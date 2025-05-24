
#pragma once

#include <nw4r/g3d/g3d_rescommon.hpp>
#include <nw4r/g3d/g3d_resdict.h>

namespace nw4r { namespace g3d {

struct ResFileHeaderData
{
    char signature[4];
    u16  byteOrder;
    u16  version;
    u32  fileSize;
    u16  headerSize;
    u16  dataBlocks;
};


// Folder names stored in the top level dictionary
#define NW4R_G3D_FOLDER_MODELS        "3DModels(NW4R)"
#define NW4R_G3D_FOLDER_PLTTS         "Palettes(NW4R)"
#define NW4R_G3D_FOLDER_TEXTURES      "Textures(NW4R)"
#define NW4R_G3D_FOLDER_ANM_CHR       "AnmChr(NW4R)"
#define NW4R_G3D_FOLDER_ANM_VIS       "AnmVis(NW4R)"
#define NW4R_G3D_FOLDER_ANM_CLR       "AnmClr(NW4R)"
#define NW4R_G3D_FOLDER_ANM_TEXPAT    "AnmTexPat(NW4R)"
#define NW4R_G3D_FOLDER_ANM_TEXSRT    "AnmTexSrt(NW4R)"
#define NW4R_G3D_FOLDER_ANM_SHP       "AnmShp(NW4R)"
#define NW4R_G3D_FOLDER_ANM_SCN       "AnmScn(NW4R)"
#define NW4R_G3D_FOLDER_EXTERNAL      "External"


struct ResTopLevelDictData
{
    ResBlockHeaderData header;   // "root"
    ResDicData         topLevel;
};

struct ResFileData
{
    ResFileHeaderData   fileHeader;
    ResTopLevelDictData dict;
};

class ResMdl;
class ResPltt;
class ResTex;
class ResAnmChr;
class ResAnmVis;
class ResAnmClr;
class ResAnmTexPat;
class ResAnmTexSrt;
class ResAnmShp;
class ResAnmScn;

class ResFile : public ResCommon<ResFileData>
{
public:
  explicit ResFile(void *p=nullptr) : ResCommon<ResFileData>(p) {}

  ResMdl GetResMdl(const char *) const;
  ResMdl GetResMdl(int) const;
  ResMdl GetResMdl(u32) const; //inlined

  ResPltt GetResPltt(const char *) const;
  ResPltt GetResPltt(ResName) const;
  ResPltt GetResPltt(int) const;
  ResPltt GetResPltt(u32) const; //inlined
  
  ResTex GetResTex(const char *) const;
  ResTex GetResTex(ResName) const;
  ResTex GetResTex(int) const;
  ResTex GetResTex(u32) const; //inlined
  
  ResAnmChr GetResAnmChr(const char *) const;
  ResAnmChr GetResAnmChr(int) const;
  ResAnmChr GetResAnmChr(u32) const; //inlined
  
  ResAnmVis GetResAnmVis(const char *) const;
  ResAnmVis GetResAnmVis(int) const;
  ResAnmVis GetResAnmVis(u32) const; //inlined
  
  ResAnmClr GetResAnmClr(const char *) const;
  ResAnmClr GetResAnmClr(int) const;
  ResAnmClr GetResAnmClr(u32) const; //inlined
  
  ResAnmTexPat GetResAnmTexPat(const char *) const;
  ResAnmTexPat GetResAnmTexPat(int) const;
  ResAnmTexPat GetResAnmTexPat(u32) const; //inlined
  
  ResAnmTexSrt GetResAnmTexSrt(const char *) const;
  ResAnmTexSrt GetResAnmTexSrt(int) const;
  ResAnmTexSrt GetResAnmTexSrt(u32) const; //inlined
  
  ResAnmShp GetResAnmShp(const char *) const;
  ResAnmShp GetResAnmShp(int) const;
  ResAnmShp GetResAnmShp(u32) const; //inlined
  
  ResAnmScn GetResAnmScn(const char *) const;
  ResAnmScn GetResAnmScn(int) const;
  ResAnmScn GetResAnmScn(u32) const; //inlined
  
  u32 GetResMdlNumEntries() const; //inlined
  u32 GetResPlttNumEntries() const; //inlined
  u32 GetResTexNumEntries() const; //inlined
  u32 GetResAnmChrNumEntries() const; //inlined
  u32 GetResAnmVisNumEntries() const; //inlined
  u32 GetResAnmClrNumEntries() const; //inlined
  u32 GetResAnmTexPatNumEntries() const; //inlined
  u32 GetResAnmTexSrtNumEntries() const; //inlined
  u32 GetResAnmShpNumEntries() const; //inlined
  u32 GetResAnmScnNumEntries() const;
  
  bool Bind(ResFile);
  void Release();
  void Init();
  void Terminate();
  bool CheckRevision() const;
};
}} // nw4r::g3d
