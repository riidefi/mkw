#pragma once

#include "../types.hpp"
#include <stdlib.h>

namespace low {

struct RelHeader {
  // Header
  //

  // Module ID: Should be unique
  u32 id = 1;

  // Filled in on runtime (linked list)
  u32 runtime_next = 0;
  u32 runtime_last = 0;
 
  // Section table descriptor
  u32 num_sections = 0;
  u32 ofs_section_table = 0;

  // Name descriptor
  u32 ofs_name = 0;
  u32 name_size = 0;

  // We only care about V3
  u32 version = 3;

  // Data
  //

  // Size of the BSS section (zero-filled)
  u32 bssSize = 0;

  // Offset of first rel table
  u32 relOffset = 0;

  // "imp" table descriptor
  u32 impOffset;
  u32 impSize;

  // `prolog` will be relative to this
  u8 prologSection;
  // `epilog` relative to this
  u8 epilogSection;
  // `unresolved` relative to this
  u8 unresolvedSection;
  // Supposedly filled at runtime?
  u8 bssSection = 0;

  // Exported functions
  // Relative to the sections above
  u32 prolog;
  u32 epilog;
  u32 unresolved;

  // Version 2
  //

  // Alignment on all sections
  u32 align;
  // Alignment of BSS section
  u32 bssAlign;

  // Version 3
  //

  // Address of relocation data to be reused for other purposes? don't quite
  // understand
  u32 fixSize;
};

static_assert(sizeof(RelHeader) == 0x4c, "Invalid header size");

struct SectionDescriptor {
  u32 offset; // lower 2 bits flags
  u32 size;
};

struct Imp {
  u32 module_id;
  u32 offset;
};

enum class R : u8 {
  R_PPC_NONE = 0,
  R_PPC_ADDR32 = 1,    /* 32bit absolute address */
  R_PPC_ADDR24 = 2,    /* 26bit address, 2 bits ignored.  */
  R_PPC_ADDR16 = 3,    /* 16bit absolute address */
  R_PPC_ADDR16_LO = 4, /* lower 16bit of absolute address */
  R_PPC_ADDR16_HI = 5, /* high 16bit of absolute address */
  R_PPC_ADDR16_HA = 6, /* adjusted high 16bit */
  R_PPC_ADDR14 = 7,    /* 16bit address, 2 bits ignored */
  R_PPC_ADDR14_BRTAKEN = 8,
  R_PPC_ADDR14_BRNTAKEN = 9,
  R_PPC_REL24 = 10, /* PC relative 26 bit */
  R_PPC_REL14 = 11, /* PC relative 16 bit */
  R_PPC_REL14_BRTAKEN = 12,
  R_PPC_REL14_BRNTAKEN = 13,

  R_RVL_NONE = 201,
  R_RVL_SECT = 202,
  R_RVL_STOP = 203
};

struct Reloc {
  // Relative to last
  u16 offset;
  u8 type;
  u8 section;
  u32 addend; // abs address for dol
};

static_assert(sizeof(Reloc) == 8);

inline void flip(u32& data) { data = _byteswap_ulong(data); }
inline void flip(u16& data) { data = ((data & 0xff00) >> 8) | (data & 0xff); }

inline void flip(Reloc& r) {
  flip(r.offset);
  flip(r.addend);
}

inline void flip(Imp& imp) {
  flip(imp.module_id);
  flip(imp.offset);
}

inline void flip(SectionDescriptor& desc) {
  flip(desc.offset);
  flip(desc.size);
}

inline void flip(RelHeader& header) {
  flip(header.id);
  flip(header.runtime_last);
  flip(header.runtime_next);
  flip(header.num_sections);
  flip(header.ofs_section_table);
  flip(header.ofs_name);
  flip(header.name_size);
  flip(header.version);
  flip(header.bssSize);
  flip(header.relOffset);
  flip(header.impOffset);
  flip(header.impSize);

  flip(header.prolog);
  flip(header.epilog);
  flip(header.unresolved);

  flip(header.align);
  flip(header.bssAlign);
  flip(header.fixSize);
}

} // namespace low
