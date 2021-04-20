#pragma once

#include "low/LowRel.hpp"
#include "types.hpp"
#include <memory>
#include <string>
#include <vector>

struct Section {
  std::vector<u8> data;
  bool executable = false;
};
struct SectionTable {
  std::vector<Section> sections;
};

struct BinSymbol {
  u8 section;
  u32 offset;
};

struct RelocationTableHolder {
  std::vector<u8> rel_relocs;
  std::vector<u8> dol_relocs;
};

struct ExportedSymbols {
  BinSymbol prolog;
  BinSymbol epilog;
  BinSymbol unresolved;
};

struct RelFile {
  u32 id = 1;

  u32 name_offset;
  u32 name_size;

  SectionTable sections;
  u32 bssSize;

  // "imp"
  RelocationTableHolder relocations;

  ExportedSymbols exported;

  // V2
  u32 all_align;
  u32 bss_align;

  // V3
  u32 fix_size;
};

inline u32 writeBufRaw(std::vector<u8>& buf, u32 pos, const u8* data,
                       u32 size) {
  if (buf.size() < pos + size)
    buf.resize(pos + size);
  memcpy(buf.data() + pos, data, size);
  return pos + size;
}
inline u32 writeBufRaw(std::vector<u8>& buf, const u8* data, u32 size) {
  return (u32)writeBufRaw(buf, (u32)buf.size(), data, size);
}

template <typename T>
inline u32 writeBuf(std::vector<u8>& buf, u32 pos, const T& data) {
  return writeBufRaw(buf, pos, (const u8*)&data, sizeof(data));
}
template <typename T> inline u32 writeBuf(std::vector<u8>& buf, const T& data) {
  return writeBufRaw(buf, buf.size(), data);
}

std::vector<u8> Lower(RelFile& rel) {
  std::vector<u8> buf(sizeof(low::RelHeader));

  // Push back all data
  std::vector<low::SectionDescriptor> desc(rel.sections.sections.size());
  {
    for (int i = 0; i < rel.sections.sections.size(); ++i) {
      auto& sec = rel.sections.sections[i];

      desc[i].offset = (u32)buf.size() | sec.executable;
      desc[i].size = (u32)sec.data.size();

      writeBufRaw(buf, sec.data.data(), sec.data.size());
    }
  }

  u32 imp_table_offset = buf.size();
  u32 imp_size = 2 * sizeof(low::Imp);

  const u32 sec_table_size =
      (rel.sections.sections.size()) * sizeof(low::SectionDescriptor);

  low::RelHeader header{
      .id = rel.id,
      .runtime_next = 0,
      .runtime_last = 0,
      // First section NULL
      .num_sections = (u32)rel.sections.sections.size(),
      .ofs_section_table =
          sizeof(low::RelHeader), // Immediately following the header
      .ofs_name = 0,
      .name_size = 66,
      .version = 3,
      .bssSize = rel.bssSize,
      .relOffset = imp_table_offset + imp_size,
      .impOffset = imp_table_offset,
      .impSize = imp_size,
      .prologSection = rel.exported.prolog.section,
      .epilogSection = rel.exported.epilog.section,
      .unresolvedSection = rel.exported.unresolved.section,
      .bssSection = 0,
      .prolog = rel.exported.prolog.offset,
      .epilog = rel.exported.epilog.offset,
      .unresolved = rel.exported.unresolved.offset,
      .align = rel.all_align,
      .bssAlign = rel.bss_align,
      .fixSize = rel.fix_size //
  };
  low::flip(header);
  writeBuf(buf, 0, header);

  {
    for (auto& d : desc)
      low::flip(d);
    u32 cursor = sizeof(low::RelHeader);
    for (auto& d : desc) {
      writeBuf(buf, cursor, d);
      cursor += sizeof(low::SectionDescriptor);
    }
  }

  // Write relocs
  std::vector<low::Imp> imps(2);
  imps[0].module_id = 1;
  imps[0].offset = (u32)buf.size();

  writeBufRaw(buf, rel.relocations.rel_relocs.data(),
              rel.relocations.rel_relocs.size());

  imps[1].module_id = 0;
  imps[1].offset = (u32)buf.size();

  writeBufRaw(buf, rel.relocations.dol_relocs.data(),
              rel.relocations.dol_relocs.size());

  // write imp
  {
    u32 cursor = imp_table_offset;
    for (auto& i : imps) {
      low::flip(i);
      writeBuf(buf, cursor, i);
      cursor += sizeof(low::Imp);
    }
  }

  return buf;
}

u32 computeRelocSecSize(const u8* data_begin, const u8* data_end,
                        bool is_main_dol) {
  auto* start = data_begin;
  while (data_begin < data_end) {
    low::Reloc reloc = *(low::Reloc*)data_begin;
    data_begin += sizeof(low::Reloc);
    low::flip(reloc);

    if ((low::R)reloc.type == low::R::R_RVL_STOP) {

      return data_begin - start;
    }
  }

  throw "Failure";
  return 0;
}

inline RelFile Lift(std::vector<char> buf) {
  low::RelHeader rel_header;
  memcpy(&rel_header, buf.data(), sizeof(rel_header));
  low::flip(rel_header);

  auto& hdr = rel_header;
  RelFile rel;
  rel.id = hdr.id;
  rel.name_offset = hdr.id;
  rel.name_size = hdr.name_size;

  std::vector<low::SectionDescriptor> section_table;
  section_table.resize(hdr.num_sections);
  memcpy(section_table.data(), buf.data() + hdr.ofs_section_table,
         hdr.num_sections * sizeof(low::SectionDescriptor));
  for (auto& s : section_table)
    low::flip(s);

  rel.sections.sections.resize(hdr.num_sections);
  for (int i = 1; i < hdr.num_sections; ++i) {
    auto& sec = rel.sections.sections[i];
    sec.data.resize(section_table[i].size);
    memcpy(sec.data.data(), buf.data() + (section_table[i].offset & (~1)),
           section_table[i].size);
    sec.executable = section_table[i].offset & 1;
  }

  std::vector<low::Imp> imps(rel_header.impSize / sizeof(low::Imp));
  memcpy(imps.data(), buf.data() + rel_header.impOffset, rel_header.impSize);

  for (auto& x : imps)
    low::flip(x);

  for (int i = 0; i < imps.size(); ++i) {
    auto& imp = imps[i];

    auto sz =
        computeRelocSecSize((u8*)buf.data() + imp.offset,
                            (u8*)buf.data() + buf.size(), imp.module_id == 0);
    auto& buf =
        i == 0 ? rel.relocations.rel_relocs : rel.relocations.dol_relocs;
    buf.resize(sz);
    memcpy(buf.data(), buf.data() + imp.offset, sz);
  }

  rel.bssSize = hdr.bssSize;
  rel.exported.prolog.section = hdr.prologSection;
  rel.exported.epilog.section = hdr.epilogSection;
  rel.exported.unresolved.section = hdr.unresolvedSection;

  rel.exported.prolog.offset = hdr.prolog;
  rel.exported.epilog.offset = hdr.epilog;
  rel.exported.unresolved.offset = hdr.unresolved;

  rel.all_align = hdr.align;
  rel.bss_align = hdr.bssAlign;

  rel.fix_size = hdr.fixSize;

  return rel;
}