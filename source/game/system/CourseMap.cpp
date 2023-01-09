#include "CourseMap.hpp"

#include "game/system/RaceConfig.hpp"
#include "game/system/ResourceManager.hpp"

// --- EXTERN DECLARATIONS BEGIN ---

extern "C" {

// Extern function references.
// PAL: 0x80020ff4
extern UNKNOWN_FUNCTION(__construct_array);
// PAL: 0x80085110
extern UNKNOWN_FUNCTION(SinFIdx__Q24nw4r4mathFf);
// PAL: 0x80085180
extern UNKNOWN_FUNCTION(CosFIdx__Q24nw4r4mathFf);
// PAL: 0x80229dcc
extern UNKNOWN_FUNCTION(__nw__FUl);
// PAL: 0x80229df0
extern UNKNOWN_FUNCTION(__nwa__FUl);
// PAL: 0x80229ee0
extern UNKNOWN_FUNCTION(__dla__FPv);
// PAL: 0x80239f58
extern UNKNOWN_FUNCTION(setRPY__Q23EGG5QuatfFfff);
// PAL: 0x8023a2d0
extern UNKNOWN_FUNCTION(rotateVector__Q23EGG5QuatfFRCQ23EGG8Vector3f);
// PAL: 0x80243a00
extern UNKNOWN_FUNCTION(normalise__Q23EGG8Vector2fFv);
// PAL: 0x80511e00
extern UNKNOWN_FUNCTION(unk_80511e00);
// PAL: 0x8051201c
extern UNKNOWN_FUNCTION(VEC2_sub);
// PAL: 0x80512370
extern UNKNOWN_FUNCTION(CheckpointHolder_computeMeanTotalDistance);
// PAL: 0x80512c10
extern UNKNOWN_FUNCTION(loadFile__Q26System9CourseMapFlPCc);
// PAL: 0x80512c2c
extern UNKNOWN_FUNCTION(
    __ct__Q26System19MapdataFileAccessorFPCQ36System19MapdataFileAccessor5SData);
// PAL: 0x80512c6c
extern UNKNOWN_FUNCTION(getCameraType__Q26System13MapdataCameraCFv);
// PAL: 0x80512c78
extern UNKNOWN_FUNCTION(getCameraCount__Q26System9CourseMapCFv);
// PAL: 0x80512c94
extern UNKNOWN_FUNCTION(getVersion__Q26System19MapdataFileAccessorCFv);
// PAL: 0x80512c9c
extern UNKNOWN_FUNCTION(getExtraValue__Q26System21MapdataCameraAccessorCFv);
// PAL: 0x80512cac
extern UNKNOWN_FUNCTION(setIndex__Q26System15MapdataAreaBaseFUs);
// PAL: 0x80512cb4
extern UNKNOWN_FUNCTION(getAreaCount__Q26System9CourseMapCFv);
// PAL: 0x80512cd0
extern UNKNOWN_FUNCTION(getEnemyPointCount__Q26System9CourseMapCFv);
// PAL: 0x80512cec
extern UNKNOWN_FUNCTION(getItemPointCount__Q26System9CourseMapCFv);
// PAL: 0x80512d08
extern UNKNOWN_FUNCTION(getJugemPointCount__Q26System9CourseMapCFv);
// PAL: 0x80512d24
extern UNKNOWN_FUNCTION(getStartPointCount__Q26System9CourseMapCFv);
// PAL: 0x80512d40
extern UNKNOWN_FUNCTION(getStartConfig__Q26System12MapdataStageCFv);
// PAL: 0x80512d4c
extern UNKNOWN_FUNCTION(getFlareColor__Q26System12MapdataStageCFv);
// PAL: 0x80512d58
extern UNKNOWN_FUNCTION(flareToggleEnabled__Q26System12MapdataStageCFv);
// PAL: 0x80512d64
extern UNKNOWN_FUNCTION(parseStage__Q26System9CourseMapFUl);
// PAL: 0x80512e84
extern UNKNOWN_FUNCTION(parseMissionPoints__Q26System9CourseMapFUl);
// PAL: 0x80512fa4
extern UNKNOWN_FUNCTION(parseCannonPoints__Q26System9CourseMapFUl);
// PAL: 0x805130c4
extern UNKNOWN_FUNCTION(parseJugemPoints__Q26System9CourseMapFUl);
// PAL: 0x805131e4
extern UNKNOWN_FUNCTION(parseCameras__Q26System9CourseMapFUl);
// PAL: 0x80513304
extern UNKNOWN_FUNCTION(parseAreas__Q26System9CourseMapFUl);
// PAL: 0x80513398
extern UNKNOWN_FUNCTION(parsePointInfo__Q26System9CourseMapFUl);
// PAL: 0x805134c8
extern UNKNOWN_FUNCTION(parseGeoObjs__Q26System9CourseMapFUl);
// PAL: 0x80513640
extern UNKNOWN_FUNCTION(KmpHolder_parseCheckpoints);
// PAL: 0x8051377c
extern UNKNOWN_FUNCTION(KmpHolder_parseCheckpaths);
// PAL: 0x80513adc
extern UNKNOWN_FUNCTION(parseItemPoints__Q26System9CourseMapFUl);
// PAL: 0x80513bfc
extern UNKNOWN_FUNCTION(parseItemPaths__Q26System9CourseMapFUl);
// PAL: 0x80513d18
extern UNKNOWN_FUNCTION(parseEnemyPoints__Q26System9CourseMapFUl);
// PAL: 0x80513e40
extern UNKNOWN_FUNCTION(parseEnemyPaths__Q26System9CourseMapFUl);
// PAL: 0x80513f5c
extern UNKNOWN_FUNCTION(parseKartpoints__Q26System9CourseMapFUl);
// PAL: 0x805140dc
extern UNKNOWN_FUNCTION(get__Q26System19MapdataAreaAccessorCFUs);
// PAL: 0x80514100
extern UNKNOWN_FUNCTION(get__Q26System25MapdataJugemPointAccessorCFUs);
// PAL: 0x80514124
extern UNKNOWN_FUNCTION(get__Q26System25MapdataStartPointAccessorCFUs);
// PAL: 0x80514368
extern UNKNOWN_FUNCTION(unk_80514368);
// PAL: 0x805147d4
extern UNKNOWN_FUNCTION(VEC3_fromNeg);
// PAL: 0x805147fc
extern UNKNOWN_FUNCTION(
    VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f);
// PAL: 0x80514810
extern UNKNOWN_FUNCTION(Vec3_scale);
// PAL: 0x80514838
extern UNKNOWN_FUNCTION(Vec3_add);
// PAL: 0x8051486c
extern UNKNOWN_FUNCTION(VEC3_sub);
// PAL: 0x805148a0
extern UNKNOWN_FUNCTION(unk_805148a0);
// PAL: 0x80514b7c
extern UNKNOWN_FUNCTION(getEnemyPoint__Q26System9CourseMapCFUs);
// PAL: 0x80514d3c
extern UNKNOWN_FUNCTION(getItemPoint__Q26System9CourseMapCFUs);
// PAL: 0x805150e0
extern UNKNOWN_FUNCTION(unk_805150e0);
// PAL: 0x80515244
extern UNKNOWN_FUNCTION(CheckpointHolder_init);
// PAL: 0x805154e4
extern UNKNOWN_FUNCTION(Checkpoint_parse);
// PAL: 0x805155e0
extern UNKNOWN_FUNCTION(unk_805155e0);
// PAL: 0x805155e4
extern UNKNOWN_FUNCTION(unk_805155e4);
// PAL: 0x80515624
extern UNKNOWN_FUNCTION(unk_80515624);
// PAL: 0x80515a6c
extern UNKNOWN_FUNCTION(unk_80515a6c);
// PAL: 0x80515e50
extern UNKNOWN_FUNCTION(
    __ct__Q26System19MapdataAreaAccessorFPCQ26System16KmpSectionHeader);
// PAL: 0x80515f8c
extern UNKNOWN_FUNCTION(unk_80515f8c);
// PAL: 0x80516220
extern UNKNOWN_FUNCTION(AreaBox_construct);
// PAL: 0x805164fc
extern UNKNOWN_FUNCTION(AreaCylinder_construct);
// PAL: 0x80516bb0
extern UNKNOWN_FUNCTION(getCamera__Q26System9CourseMapCFUs);
// PAL: 0x80516d74
extern UNKNOWN_FUNCTION(unk_80516d74);
// PAL: 0x80517858
extern UNKNOWN_FUNCTION(unk_80517858);
// PAL: 0x80517d8c
extern UNKNOWN_FUNCTION(unk_80517d8c);
// PAL: 0x80517e88
extern UNKNOWN_FUNCTION(unk_80517e88);
// PAL: 0x805183a8
extern UNKNOWN_FUNCTION(
    __ct__Q26System17MapdataJugemPointFPCQ36System17MapdataJugemPoint5SData);
// PAL: 0x805184fc
extern UNKNOWN_FUNCTION(unk_805184fc);
// PAL: 0x80518ab8
extern UNKNOWN_FUNCTION(Vec3_fromScale);
// PAL: 0x80518b78
extern UNKNOWN_FUNCTION(getStage__Q26System9CourseMapCFv);
// PAL: 0x80518bb0
extern UNKNOWN_FUNCTION(getFlareAlpha__Q26System12MapdataStageCFv);
// PAL: 0x805411fc
extern UNKNOWN_FUNCTION(getFile__Q26System15ResourceManagerFlPCcPUl);
// PAL: 0x8054d114
extern UNKNOWN_FUNCTION(unk_8054d114);
// Extern data references.
// PAL: 0x802a4118
extern UNKNOWN_DATA(lbl_802a4118);
// PAL: 0x802a4130
extern UNKNOWN_DATA(lbl_802a4130);
// PAL: 0x802a4148
extern UNKNOWN_DATA(lbl_802a4148);
// PAL: 0x8088f8e8
extern UNKNOWN_DATA(lbl_8088f8e8);
// PAL: 0x8088fa38
extern UNKNOWN_DATA(TWENTY_FIVE__6System);
extern UNKNOWN_DATA(ZERO_FLOAT2__6System);
// PAL: 0x8088fa44
extern UNKNOWN_DATA(lbl_8088fa44);
// PAL: 0x8088fa48
extern UNKNOWN_DATA(lbl_8088fa48);
// PAL: 0x8088fa50
extern UNKNOWN_DATA(lbl_8088fa50);
// PAL: 0x8088fa58
extern UNKNOWN_DATA(lbl_8088fa58);
// PAL: 0x8088fa6c
extern UNKNOWN_DATA(lbl_8088fa6c);
// PAL: 0x8088fa70
extern UNKNOWN_DATA(lbl_8088fa70);
// PAL: 0x8088fa78
extern UNKNOWN_DATA(lbl_8088fa78);
// PAL: 0x8088fa90
extern UNKNOWN_DATA(lbl_8088fa90);
// PAL: 0x808b2c20
extern UNKNOWN_DATA(lbl_808b2c20);
// PAL: 0x808b2c30
extern UNKNOWN_DATA(__vt__Q26System9CourseMap);
// PAL: 0x808b2c3c
extern UNKNOWN_DATA(__vt__Q26System19MapdataAreaAccessor);
// PAL: 0x808b2c48
extern UNKNOWN_DATA(__vt__Q26System19MapdataAreaCylinder);
// PAL: 0x808b2c54
extern UNKNOWN_DATA(__vt__Q26System14MapdataAreaBox);
// PAL: 0x808b2c60
extern UNKNOWN_DATA(__vt__Q26System15MapdataAreaBase);
// PAL: 0x808b2c6c
extern UNKNOWN_DATA(__vt__Q26System17MapdataEnemyPoint);
// PAL: 0x809bd6e8
extern UNKNOWN_DATA(spInstance__Q26System9CourseMap);
// PAL: 0x809bd6ec
extern UNKNOWN_DATA(lbl_809bd6ec);
// PAL: 0x809bd728
extern UNKNOWN_DATA(spInstance__Q26System10RaceConfig);
// PAL: 0x809bd738
extern UNKNOWN_DATA(spInstance__Q26System15ResourceManager);
}

// --- EXTERN DECLARATIONS END ---

namespace System {

// .rodata
extern const f32 TWENTY_FIVE;
const f32 TWENTY_FIVE = 25.0f;

#ifndef SHIFTABLE
extern f32 ZERO_FLOAT2;
REL_SYMBOL_AT(ZERO_FLOAT2, 0x8088fa3c)
#else
static const f32 ZERO_FLOAT2 = 0.0f;
#endif

// .bss
CourseMap* CourseMap::spInstance;

CourseMap* CourseMap::createInstance() {
  if (spInstance == nullptr) {
    spInstance = new CourseMap();
  }

  return spInstance;
}

void CourseMap::destroyInstance() {
  if (spInstance != nullptr) {
    delete spInstance;
    spInstance = nullptr;
  }
}

CourseMap::CourseMap()
    : mpStartPoint(nullptr), mpEnemyPath(nullptr), mpCheckPath(nullptr),
      mpCheckPoint(nullptr), mpGeoObj(nullptr), mpPointInfo(nullptr),
      mpArea(nullptr), mpCamera(nullptr), mpGoalCamera(nullptr),
      mpOpeningPanCamera(nullptr), _50(0) {}

CourseMap::~CourseMap() {}

} // namespace System

// Symbol: CourseMap_init
// PAL: 0x805127ec..0x80512c10
MARK_BINARY_BLOB(CourseMap_init, 0x805127ec, 0x80512c10);
asm UNKNOWN_FUNCTION(CourseMap_init) {
  // clang-format off
  nofralloc
  /* 805127EC 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805127F0 7C0802A6 */ mflr        r0
  /* 805127F4 90010024 */ stw         r0, 0x24(r1)
  /* 805127F8 39610020 */ addi        r11, r1, 0x20
  /* 805127FC 4BB0EDA5 */ bl          _savegpr_27
  /* 80512800 3FC08089 */ lis         r30, lbl_8088f8e8@ha
  /* 80512804 3FE0808B */ lis         r31, lbl_808b2c20@ha
  /* 80512808 3C808089 */ lis         r4, lbl_8088fa90@ha
  /* 8051280C 7C7D1B78 */ mr          r29, r3
  /* 80512810 3BDEF8E8 */ addi        r30, r30, lbl_8088f8e8@l
  /* 80512814 3BFF2C20 */ addi        r31, r31, lbl_808b2c20@l
  /* 80512818 3884FA90 */ addi        r4, r4, lbl_8088fa90@l
  /* 8051281C 38600001 */ li          r3, 0x1
  /* 80512820 480003F1 */ bl          loadFile__Q26System9CourseMapFlPCc
  /* 80512824 7C7C1B78 */ mr          r28, r3
  /* 80512828 38600010 */ li          r3, 0x10
  /* 8051282C 4BD175A1 */ bl          __nw__FUl
  /* 80512830 2C030000 */ cmpwi       r3, 0x0
  /* 80512834 4182000C */ beq-        lbl_80512840
  /* 80512838 7F84E378 */ mr          r4, r28
  /* 8051283C 480003F1 */ bl          __ct__Q26System19MapdataFileAccessorFPCQ36System19MapdataFileAccessor5SData
  lbl_80512840:
  /* 80512840 3C804B54 */ lis         r4, 0x4b54
  /* 80512844 907D0004 */ stw         r3, 4(r29)
  /* 80512848 7FA3EB78 */ mr          r3, r29
  /* 8051284C 38845054 */ addi        r4, r4, 0x5054
  /* 80512850 4800170D */ bl          parseKartpoints__Q26System9CourseMapFUl
  /* 80512854 907D0008 */ stw         r3, 8(r29)
  /* 80512858 3F80454E */ lis         r28, 0x454e
  /* 8051285C 7FA3EB78 */ mr          r3, r29
  /* 80512860 389C5048 */ addi        r4, r28, 0x5048
  /* 80512864 480015DD */ bl          parseEnemyPaths__Q26System9CourseMapFUl
  /* 80512868 907D000C */ stw         r3, 0xc(r29)
  /* 8051286C 7FA3EB78 */ mr          r3, r29
  /* 80512870 389C5054 */ addi        r4, r28, 0x5054
  /* 80512874 480014A5 */ bl          parseEnemyPoints__Q26System9CourseMapFUl
  /* 80512878 907D0010 */ stw         r3, 0x10(r29)
  /* 8051287C 3F804954 */ lis         r28, 0x4954
  /* 80512880 7FA3EB78 */ mr          r3, r29
  /* 80512884 389C5048 */ addi        r4, r28, 0x5048
  /* 80512888 48001375 */ bl          parseItemPaths__Q26System9CourseMapFUl
  /* 8051288C 907D0014 */ stw         r3, 0x14(r29)
  /* 80512890 7FA3EB78 */ mr          r3, r29
  /* 80512894 389C5054 */ addi        r4, r28, 0x5054
  /* 80512898 48001245 */ bl          parseItemPoints__Q26System9CourseMapFUl
  /* 8051289C 907D0018 */ stw         r3, 0x18(r29)
  /* 805128A0 3F80434B */ lis         r28, 0x434b
  /* 805128A4 7FA3EB78 */ mr          r3, r29
  /* 805128A8 389C5048 */ addi        r4, r28, 0x5048
  /* 805128AC 48000ED1 */ bl          KmpHolder_parseCheckpaths
  /* 805128B0 907D001C */ stw         r3, 0x1c(r29)
  /* 805128B4 7FA3EB78 */ mr          r3, r29
  /* 805128B8 389C5054 */ addi        r4, r28, 0x5054
  /* 805128BC 48000D85 */ bl          KmpHolder_parseCheckpoints
  /* 805128C0 907D0020 */ stw         r3, 0x20(r29)
  /* 805128C4 3C80474F */ lis         r4, 0x474f
  /* 805128C8 7FA3EB78 */ mr          r3, r29
  /* 805128CC 3884424A */ addi        r4, r4, 0x424a
  /* 805128D0 48000BF9 */ bl          parseGeoObjs__Q26System9CourseMapFUl
  /* 805128D4 907D0028 */ stw         r3, 0x28(r29)
  /* 805128D8 3C80504F */ lis         r4, 0x504f
  /* 805128DC 7FA3EB78 */ mr          r3, r29
  /* 805128E0 38845449 */ addi        r4, r4, 0x5449
  /* 805128E4 48000AB5 */ bl          parsePointInfo__Q26System9CourseMapFUl
  /* 805128E8 907D0024 */ stw         r3, 0x24(r29)
  /* 805128EC 3C804152 */ lis         r4, 0x4152
  /* 805128F0 7FA3EB78 */ mr          r3, r29
  /* 805128F4 38844541 */ addi        r4, r4, 0x4541
  /* 805128F8 48000A0D */ bl          parseAreas__Q26System9CourseMapFUl
  /* 805128FC 907D002C */ stw         r3, 0x2c(r29)
  /* 80512900 3C804341 */ lis         r4, 0x4341
  /* 80512904 7FA3EB78 */ mr          r3, r29
  /* 80512908 38844D45 */ addi        r4, r4, 0x4d45
  /* 8051290C 480008D9 */ bl          parseCameras__Q26System9CourseMapFUl
  /* 80512910 907D0030 */ stw         r3, 0x30(r29)
  /* 80512914 3C804A47 */ lis         r4, 0x4a47
  /* 80512918 7FA3EB78 */ mr          r3, r29
  /* 8051291C 38845054 */ addi        r4, r4, 0x5054
  /* 80512920 480007A5 */ bl          parseJugemPoints__Q26System9CourseMapFUl
  /* 80512924 907D0034 */ stw         r3, 0x34(r29)
  /* 80512928 3C80434E */ lis         r4, 0x434e
  /* 8051292C 7FA3EB78 */ mr          r3, r29
  /* 80512930 38845054 */ addi        r4, r4, 0x5054
  /* 80512934 48000671 */ bl          parseCannonPoints__Q26System9CourseMapFUl
  /* 80512938 907D0038 */ stw         r3, 0x38(r29)
  /* 8051293C 3C804D53 */ lis         r4, 0x4d53
  /* 80512940 7FA3EB78 */ mr          r3, r29
  /* 80512944 38845054 */ addi        r4, r4, 0x5054
  /* 80512948 4800053D */ bl          parseMissionPoints__Q26System9CourseMapFUl
  /* 8051294C 907D0040 */ stw         r3, 0x40(r29)
  /* 80512950 3C805354 */ lis         r4, 0x5354
  /* 80512954 7FA3EB78 */ mr          r3, r29
  /* 80512958 38844749 */ addi        r4, r4, 0x4749
  /* 8051295C 48000409 */ bl          parseStage__Q26System9CourseMapFUl
  /* 80512960 907D003C */ stw         r3, 0x3c(r29)
  /* 80512964 3B800000 */ li          r28, 0x0
  /* 80512968 4800002C */ b           lbl_80512994
  lbl_8051296c:
  /* 8051296C 7FA3EB78 */ mr          r3, r29
  /* 80512970 5784063E */ clrlwi      r4, r28, 0x18
  /* 80512974 4800423D */ bl          getCamera__Q26System9CourseMapCFUs
  /* 80512978 7C7B1B78 */ mr          r27, r3
  /* 8051297C 480002F1 */ bl          getCameraType__Q26System13MapdataCameraCFv
  /* 80512980 2C030000 */ cmpwi       r3, 0x0
  /* 80512984 4082000C */ bne-        lbl_80512990
  /* 80512988 937D0044 */ stw         r27, 0x44(r29)
  /* 8051298C 48000020 */ b           lbl_805129ac
  lbl_80512990:
  /* 80512990 3B9C0001 */ addi        r28, r28, 0x1
  lbl_80512994:
  /* 80512994 7FA3EB78 */ mr          r3, r29
  /* 80512998 480002E1 */ bl          getCameraCount__Q26System9CourseMapCFv
  /* 8051299C 5463043E */ clrlwi      r3, r3, 0x10
  /* 805129A0 5780063E */ clrlwi      r0, r28, 0x18
  /* 805129A4 7C001800 */ cmpw        r0, r3
  /* 805129A8 4180FFC4 */ blt+        lbl_8051296c
  lbl_805129ac:
  /* 805129AC 3B600000 */ li          r27, 0x0
  /* 805129B0 4800002C */ b           lbl_805129dc
  lbl_805129b4:
  /* 805129B4 7FA3EB78 */ mr          r3, r29
  /* 805129B8 5764063E */ clrlwi      r4, r27, 0x18
  /* 805129BC 480041F5 */ bl          getCamera__Q26System9CourseMapCFUs
  /* 805129C0 7C7C1B78 */ mr          r28, r3
  /* 805129C4 480002A9 */ bl          getCameraType__Q26System13MapdataCameraCFv
  /* 805129C8 2C030009 */ cmpwi       r3, 0x9
  /* 805129CC 4082000C */ bne-        lbl_805129d8
  /* 805129D0 939D0048 */ stw         r28, 0x48(r29)
  /* 805129D4 48000020 */ b           lbl_805129f4
  lbl_805129d8:
  /* 805129D8 3B7B0001 */ addi        r27, r27, 0x1
  lbl_805129dc:
  /* 805129DC 7FA3EB78 */ mr          r3, r29
  /* 805129E0 48000299 */ bl          getCameraCount__Q26System9CourseMapCFv
  /* 805129E4 5463043E */ clrlwi      r3, r3, 0x10
  /* 805129E8 5760063E */ clrlwi      r0, r27, 0x18
  /* 805129EC 7C001800 */ cmpw        r0, r3
  /* 805129F0 4180FFC4 */ blt+        lbl_805129b4
  lbl_805129f4:
  /* 805129F4 807D0004 */ lwz         r3, 4(r29)
  /* 805129F8 4800029D */ bl          getVersion__Q26System19MapdataFileAccessorCFv
  /* 805129FC 28030780 */ cmplwi      r3, 0x780
  /* 80512A00 41800030 */ blt-        lbl_80512a30
  /* 80512A04 807D0030 */ lwz         r3, 0x30(r29)
  /* 80512A08 48000295 */ bl          getExtraValue__Q26System21MapdataCameraAccessorCFv
  /* 80512A0C 7C600775 */ extsb.      r0, r3
  /* 80512A10 41800020 */ blt-        lbl_80512a30
  /* 80512A14 807D0030 */ lwz         r3, 0x30(r29)
  /* 80512A18 48000285 */ bl          getExtraValue__Q26System21MapdataCameraAccessorCFv
  /* 80512A1C 7C601B78 */ mr          r0, r3
  /* 80512A20 7FA3EB78 */ mr          r3, r29
  /* 80512A24 5404063E */ clrlwi      r4, r0, 0x18
  /* 80512A28 48004189 */ bl          getCamera__Q26System9CourseMapCFUs
  /* 80512A2C 907D004C */ stw         r3, 0x4c(r29)
  lbl_80512a30:
  /* 80512A30 3B600000 */ li          r27, 0x0
  /* 80512A34 4800001C */ b           lbl_80512a50
  lbl_80512a38:
  /* 80512A38 807D002C */ lwz         r3, 0x2c(r29)
  /* 80512A3C 5764063E */ clrlwi      r4, r27, 0x18
  /* 80512A40 4800169D */ bl          get__Q26System19MapdataAreaAccessorCFUs
  /* 80512A44 5764063E */ clrlwi      r4, r27, 0x18
  /* 80512A48 48000265 */ bl          setIndex__Q26System15MapdataAreaBaseFUs
  /* 80512A4C 3B7B0001 */ addi        r27, r27, 0x1
  lbl_80512a50:
  /* 80512A50 7FA3EB78 */ mr          r3, r29
  /* 80512A54 48000261 */ bl          getAreaCount__Q26System9CourseMapCFv
  /* 80512A58 5463043E */ clrlwi      r3, r3, 0x10
  /* 80512A5C 5760063E */ clrlwi      r0, r27, 0x18
  /* 80512A60 7C001800 */ cmpw        r0, r3
  /* 80512A64 4180FFD4 */ blt+        lbl_80512a38
  /* 80512A68 807D002C */ lwz         r3, 0x2c(r29)
  /* 80512A6C 48003521 */ bl          unk_80515f8c
  /* 80512A70 3B600000 */ li          r27, 0x0
  /* 80512A74 4800001C */ b           lbl_80512a90
  lbl_80512a78:
  /* 80512A78 7FA3EB78 */ mr          r3, r29
  /* 80512A7C 5764063E */ clrlwi      r4, r27, 0x18
  /* 80512A80 480020FD */ bl          getEnemyPoint__Q26System9CourseMapCFUs
  /* 80512A84 5764063E */ clrlwi      r4, r27, 0x18
  /* 80512A88 480042ED */ bl          unk_80516d74
  /* 80512A8C 3B7B0001 */ addi        r27, r27, 0x1
  lbl_80512a90:
  /* 80512A90 7FA3EB78 */ mr          r3, r29
  /* 80512A94 4800023D */ bl          getEnemyPointCount__Q26System9CourseMapCFv
  /* 80512A98 5463043E */ clrlwi      r3, r3, 0x10
  /* 80512A9C 5760063E */ clrlwi      r0, r27, 0x18
  /* 80512AA0 7C001800 */ cmpw        r0, r3
  /* 80512AA4 4180FFD4 */ blt+        lbl_80512a78
  /* 80512AA8 3B600000 */ li          r27, 0x0
  /* 80512AAC 4800001C */ b           lbl_80512ac8
  lbl_80512ab0:
  /* 80512AB0 7FA3EB78 */ mr          r3, r29
  /* 80512AB4 5764063E */ clrlwi      r4, r27, 0x18
  /* 80512AB8 48002285 */ bl          getItemPoint__Q26System9CourseMapCFUs
  /* 80512ABC 5764063E */ clrlwi      r4, r27, 0x18
  /* 80512AC0 480053C9 */ bl          unk_80517e88
  /* 80512AC4 3B7B0001 */ addi        r27, r27, 0x1
  lbl_80512ac8:
  /* 80512AC8 7FA3EB78 */ mr          r3, r29
  /* 80512ACC 48000221 */ bl          getItemPointCount__Q26System9CourseMapCFv
  /* 80512AD0 5463043E */ clrlwi      r3, r3, 0x10
  /* 80512AD4 5760063E */ clrlwi      r0, r27, 0x18
  /* 80512AD8 7C001800 */ cmpw        r0, r3
  /* 80512ADC 4180FFD4 */ blt+        lbl_80512ab0
  /* 80512AE0 3B600000 */ li          r27, 0x0
  /* 80512AE4 48000018 */ b           lbl_80512afc
  lbl_80512ae8:
  /* 80512AE8 807D0034 */ lwz         r3, 0x34(r29)
  /* 80512AEC 5764063E */ clrlwi      r4, r27, 0x18
  /* 80512AF0 48001611 */ bl          get__Q26System25MapdataJugemPointAccessorCFUs
  /* 80512AF4 48005A09 */ bl          unk_805184fc
  /* 80512AF8 3B7B0001 */ addi        r27, r27, 0x1
  lbl_80512afc:
  /* 80512AFC 7FA3EB78 */ mr          r3, r29
  /* 80512B00 48000209 */ bl          getJugemPointCount__Q26System9CourseMapCFv
  /* 80512B04 5463043E */ clrlwi      r3, r3, 0x10
  /* 80512B08 5760063E */ clrlwi      r0, r27, 0x18
  /* 80512B0C 7C001800 */ cmpw        r0, r3
  /* 80512B10 4180FFD8 */ blt+        lbl_80512ae8
  /* 80512B14 3B600000 */ li          r27, 0x0
  /* 80512B18 48000018 */ b           lbl_80512b30
  lbl_80512b1c:
  /* 80512B1C 807D0008 */ lwz         r3, 8(r29)
  /* 80512B20 5764063E */ clrlwi      r4, r27, 0x18
  /* 80512B24 48001601 */ bl          get__Q26System25MapdataStartPointAccessorCFUs
  /* 80512B28 48001D79 */ bl          unk_805148a0
  /* 80512B2C 3B7B0001 */ addi        r27, r27, 0x1
  lbl_80512b30:
  /* 80512B30 7FA3EB78 */ mr          r3, r29
  /* 80512B34 480001F1 */ bl          getStartPointCount__Q26System9CourseMapCFv
  /* 80512B38 5463043E */ clrlwi      r3, r3, 0x10
  /* 80512B3C 5760063E */ clrlwi      r0, r27, 0x18
  /* 80512B40 7C001800 */ cmpw        r0, r3
  /* 80512B44 4180FFD8 */ blt+        lbl_80512b1c
  /* 80512B48 C09E013C */ lfs         f4, 0x13c(r30)
  /* 80512B4C 3F80809C */ lis         r28, lbl_809bd6ec@ha
  /* 80512B50 C07E0140 */ lfs         f3, 0x140(r30)
  /* 80512B54 7FA3EB78 */ mr          r3, r29
  /* 80512B58 C05E0144 */ lfs         f2, 0x144(r30)
  /* 80512B5C C03E0148 */ lfs         f1, 0x148(r30)
  /* 80512B60 C01E014C */ lfs         f0, 0x14c(r30)
  /* 80512B64 D09F0000 */ stfs        f4, 0(r31)
  /* 80512B68 D07F0004 */ stfs        f3, 4(r31)
  /* 80512B6C D05F0008 */ stfs        f2, 8(r31)
  /* 80512B70 D03CD6EC */ stfs        f1, lbl_809bd6ec@l(r28)
  /* 80512B74 D01F000C */ stfs        f0, 0xc(r31)
  /* 80512B78 48006001 */ bl          getStage__Q26System9CourseMapCFv
  /* 80512B7C 2C030000 */ cmpwi       r3, 0x0
  /* 80512B80 41820078 */ beq-        lbl_80512bf8
  /* 80512B84 7FA3EB78 */ mr          r3, r29
  /* 80512B88 48005FF1 */ bl          getStage__Q26System9CourseMapCFv
  /* 80512B8C 480001B5 */ bl          getStartConfig__Q26System12MapdataStageCFv
  /* 80512B90 2C030001 */ cmpwi       r3, 0x1
  /* 80512B94 4082002C */ bne-        lbl_80512bc0
  /* 80512B98 C09E013C */ lfs         f4, 0x13c(r30)
  /* 80512B9C C07E0140 */ lfs         f3, 0x140(r30)
  /* 80512BA0 C05E0150 */ lfs         f2, 0x150(r30)
  /* 80512BA4 C03E0154 */ lfs         f1, 0x154(r30)
  /* 80512BA8 C01E0158 */ lfs         f0, 0x158(r30)
  /* 80512BAC D09F0000 */ stfs        f4, 0(r31)
  /* 80512BB0 D07F0004 */ stfs        f3, 4(r31)
  /* 80512BB4 D05F0008 */ stfs        f2, 8(r31)
  /* 80512BB8 D03CD6EC */ stfs        f1, lbl_809bd6ec@l(r28)
  /* 80512BBC D01F000C */ stfs        f0, 0xc(r31)
  lbl_80512bc0:
  /* 80512BC0 7FA3EB78 */ mr          r3, r29
  /* 80512BC4 48005FB5 */ bl          getStage__Q26System9CourseMapCFv
  /* 80512BC8 48005FE9 */ bl          getFlareAlpha__Q26System12MapdataStageCFv
  /* 80512BCC 7C7F1B78 */ mr          r31, r3
  /* 80512BD0 7FA3EB78 */ mr          r3, r29
  /* 80512BD4 48005FA5 */ bl          getStage__Q26System9CourseMapCFv
  /* 80512BD8 48000181 */ bl          flareToggleEnabled__Q26System12MapdataStageCFv
  /* 80512BDC 7C7E1B78 */ mr          r30, r3
  /* 80512BE0 7FA3EB78 */ mr          r3, r29
  /* 80512BE4 48005F95 */ bl          getStage__Q26System9CourseMapCFv
  /* 80512BE8 48000165 */ bl          getFlareColor__Q26System12MapdataStageCFv
  /* 80512BEC 57C4063E */ clrlwi      r4, r30, 0x18
  /* 80512BF0 57E5063E */ clrlwi      r5, r31, 0x18
  /* 80512BF4 4803A521 */ bl          unk_8054d114
  lbl_80512bf8:
  /* 80512BF8 39610020 */ addi        r11, r1, 0x20
  /* 80512BFC 4BB0E9F1 */ bl          _restgpr_27
  /* 80512C00 80010024 */ lwz         r0, 0x24(r1)
  /* 80512C04 7C0803A6 */ mtlr        r0
  /* 80512C08 38210020 */ addi        r1, r1, 0x20
  /* 80512C0C 4E800020 */ blr
  // clang-format on
}

namespace System {

void* CourseMap::loadFile(s32 archiveIdx, const char* filename) {
  return ResourceManager::spInstance.nonvol->getFile(archiveIdx, filename,
                                                     nullptr);
}

MapdataFileAccessor::MapdataFileAccessor(const MapdataFileAccessor::SData* data)
    : mpData(data) {
  u32 offset = data->headerSize - data->numSections * 4;
  mSectionDefOffset = offset;
  mpSectionDef = (u32*)((u8*)mpData + offset);
  if (offset > 12) {
    mVersion = *((u32*)mpSectionDef - 1);
  } else {
    mVersion = 0;
  }
}

u8 MapdataCamera::getCameraType() const { return mpData->cameraType; }

u16 CourseMap::getCameraCount() const {
  return mpCamera != nullptr ? mpCamera->size() : 0;
}

u32 MapdataFileAccessor::getVersion() const { return mVersion; }

s8 MapdataCameraAccessor::getExtraValue() const {
  return sectionHeader->extraValue;
}

void MapdataAreaBase::setIndex(u16 idx) { mIndex = idx; }

u16 CourseMap::getAreaCount() const {
  return mpArea != nullptr ? mpArea->size() : 0;
}

u16 CourseMap::getEnemyPointCount() const {
  return mpEnemyPoint != nullptr ? mpEnemyPoint->size() : 0;
}

u16 CourseMap::getItemPointCount() const {
  return mpItemPoint != nullptr ? mpItemPoint->size() : 0;
}

u16 CourseMap::getJugemPointCount() const {
  return mpJugemPoint != nullptr ? mpJugemPoint->size() : 0;
}

u16 CourseMap::getStartPointCount() const {
  return mpStartPoint != nullptr ? mpStartPoint->size() : 0;
}

u8 MapdataStage::getStartConfig() const { return mpData->mStartConfig; }

u32 MapdataStage::getFlareColor() const { return mpData->mFlareColor; }

bool MapdataStage::flareToggleEnabled() const { return mpData->mFlareToggle; }

MapdataStageAccessor* CourseMap::parseStage(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataStageAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataStageAccessor(sectionPtr);
  }

  return accessor;
}

MapdataMissionPointAccessor* CourseMap::parseMissionPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataMissionPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataMissionPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataCannonPointAccessor* CourseMap::parseCannonPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataCannonPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataCannonPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataJugemPointAccessor* CourseMap::parseJugemPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataJugemPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataJugemPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataCameraAccessor* CourseMap::parseCameras(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataCameraAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataCameraAccessor(sectionPtr);
  }

  return accessor;
}

MapdataAreaAccessor* CourseMap::parseAreas(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataAreaAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataAreaAccessor(sectionPtr);
  }

  return accessor;
}

MapdataPointInfoAccessor* CourseMap::parsePointInfo(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataPointInfoAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataPointInfoAccessor(sectionPtr);
  }

  return accessor;
}

MapdataGeoObjAccessor* CourseMap::parseGeoObjs(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataGeoObjAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataGeoObjAccessor(sectionPtr);
  }

  return accessor;
}

} // namespace System

// Symbol: unk_80513600
// PAL: 0x80513600..0x80513640
MARK_BINARY_BLOB(unk_80513600, 0x80513600, 0x80513640);
asm UNKNOWN_FUNCTION(unk_80513600){
  // clang-format off
  nofralloc
  /* 80513600 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80513604 7C0802A6 */ mflr        r0
  /* 80513608 2C030000 */ cmpwi       r3, 0x0
  /* 8051360C 90010014 */ stw         r0, 0x14(r1)
  /* 80513610 93E1000C */ stw         r31, 0xc(r1)
  /* 80513614 7C7F1B78 */ mr          r31, r3
  /* 80513618 41820010 */ beq-        lbl_80513628
  /* 8051361C 2C040000 */ cmpwi       r4, 0x0
  /* 80513620 40810008 */ ble-        lbl_80513628
  /* 80513624 4BD167F1 */ bl          __dl__FPv
  lbl_80513628:
  /* 80513628 7FE3FB78 */ mr          r3, r31
  /* 8051362C 83E1000C */ lwz         r31, 0xc(r1)
  /* 80513630 80010014 */ lwz         r0, 0x14(r1)
  /* 80513634 7C0803A6 */ mtlr        r0
  /* 80513638 38210010 */ addi        r1, r1, 0x10
  /* 8051363C 4E800020 */ blr
  // clang-format on
}

// Symbol: KmpHolder_parseCheckpoints
// PAL: 0x80513640..0x8051377c
MARK_BINARY_BLOB(KmpHolder_parseCheckpoints, 0x80513640, 0x8051377c);
asm UNKNOWN_FUNCTION(KmpHolder_parseCheckpoints){
  // clang-format off
  nofralloc
  /* 80513640 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80513644 7C0802A6 */ mflr        r0
  /* 80513648 38C00000 */ li          r6, 0x0
  /* 8051364C 90010024 */ stw         r0, 0x24(r1)
  /* 80513650 93E1001C */ stw         r31, 0x1c(r1)
  /* 80513654 3BE00000 */ li          r31, 0x0
  /* 80513658 93C10018 */ stw         r30, 0x18(r1)
  /* 8051365C 93A10014 */ stw         r29, 0x14(r1)
  /* 80513660 93810010 */ stw         r28, 0x10(r1)
  /* 80513664 80A30004 */ lwz         r5, 4(r3)
  /* 80513668 80E50000 */ lwz         r7, 0(r5)
  /* 8051366C A0070008 */ lhz         r0, 8(r7)
  /* 80513670 7C0903A6 */ mtctr       r0
  /* 80513674 28000000 */ cmplwi      r0, 0
  /* 80513678 40810030 */ ble-        lbl_805136a8
  lbl_8051367c:
  /* 8051367C A007000A */ lhz         r0, 0xa(r7)
  /* 80513680 80650004 */ lwz         r3, 4(r5)
  /* 80513684 7C070214 */ add         r0, r7, r0
  /* 80513688 7C63302E */ lwzx        r3, r3, r6
  /* 8051368C 7C03006E */ lwzux       r0, r3, r0
  /* 80513690 7C002040 */ cmplw       r0, r4
  /* 80513694 4082000C */ bne-        lbl_805136a0
  /* 80513698 7C7F1B78 */ mr          r31, r3
  /* 8051369C 4800000C */ b           lbl_805136a8
  lbl_805136a0:
  /* 805136A0 38C60004 */ addi        r6, r6, 0x4
  /* 805136A4 4200FFD8 */ bdnz        lbl_8051367c
  lbl_805136a8:
  /* 805136A8 2C1F0000 */ cmpwi       r31, 0x0
  /* 805136AC 3B800000 */ li          r28, 0x0
  /* 805136B0 418200A8 */ beq-        lbl_80513758
  /* 805136B4 38600014 */ li          r3, 0x14
  /* 805136B8 4BD16715 */ bl          __nw__FUl
  /* 805136BC 2C030000 */ cmpwi       r3, 0x0
  /* 805136C0 7C7C1B78 */ mr          r28, r3
  /* 805136C4 41820094 */ beq-        lbl_80513758
  /* 805136C8 38800000 */ li          r4, 0x0
  /* 805136CC 90830000 */ stw         r4, 0(r3)
  /* 805136D0 3800FFFF */ li          r0, -0x1
  /* 805136D4 3BBF0008 */ addi        r29, r31, 0x8
  /* 805136D8 B0830004 */ sth         r4, 4(r3)
  /* 805136DC 93E30008 */ stw         r31, 8(r3)
  /* 805136E0 9803000C */ stb         r0, 0xc(r3)
  /* 805136E4 A3DF0004 */ lhz         r30, 4(r31)
  /* 805136E8 2C1E0000 */ cmpwi       r30, 0x0
  /* 805136EC 41820014 */ beq-        lbl_80513700
  /* 805136F0 B3C30004 */ sth         r30, 4(r3)
  /* 805136F4 57C313BA */ rlwinm      r3, r30, 2, 0xe, 0x1d
  /* 805136F8 4BD166F9 */ bl          __nwa__FUl
  /* 805136FC 907C0000 */ stw         r3, 0(r28)
  lbl_80513700:
  /* 80513700 3BE00000 */ li          r31, 0x0
  /* 80513704 48000034 */ b           lbl_80513738
  lbl_80513708:
  /* 80513708 386000C8 */ li          r3, 0xc8
  /* 8051370C 4BD166C1 */ bl          __nw__FUl
  /* 80513710 2C030000 */ cmpwi       r3, 0x0
  /* 80513714 41820014 */ beq-        lbl_80513728
  /* 80513718 57E0043E */ clrlwi      r0, r31, 0x10
  /* 8051371C 1C000014 */ mulli       r0, r0, 0x14
  /* 80513720 7C9D0214 */ add         r4, r29, r0
  /* 80513724 48001DC1 */ bl          Checkpoint_parse
  lbl_80513728:
  /* 80513728 809C0000 */ lwz         r4, 0(r28)
  /* 8051372C 57E013BA */ rlwinm      r0, r31, 2, 0xe, 0x1d
  /* 80513730 3BFF0001 */ addi        r31, r31, 0x1
  /* 80513734 7C64012E */ stwx        r3, r4, r0
  lbl_80513738:
  /* 80513738 57E0043E */ clrlwi      r0, r31, 0x10
  /* 8051373C 7C00F040 */ cmplw       r0, r30
  /* 80513740 4180FFC8 */ blt+        lbl_80513708
  /* 80513744 A01C0004 */ lhz         r0, 4(r28)
  /* 80513748 2C000000 */ cmpwi       r0, 0x0
  /* 8051374C 4182000C */ beq-        lbl_80513758
  /* 80513750 7F83E378 */ mr          r3, r28
  /* 80513754 48001AF1 */ bl          CheckpointHolder_init
  lbl_80513758:
  /* 80513758 83E1001C */ lwz         r31, 0x1c(r1)
  /* 8051375C 7F83E378 */ mr          r3, r28
  /* 80513760 83C10018 */ lwz         r30, 0x18(r1)
  /* 80513764 83A10014 */ lwz         r29, 0x14(r1)
  /* 80513768 83810010 */ lwz         r28, 0x10(r1)
  /* 8051376C 80010024 */ lwz         r0, 0x24(r1)
  /* 80513770 7C0803A6 */ mtlr        r0
  /* 80513774 38210020 */ addi        r1, r1, 0x20
  /* 80513778 4E800020 */ blr
  // clang-format on
}

// Symbol: KmpHolder_parseCheckpaths
// PAL: 0x8051377c..0x80513adc
MARK_BINARY_BLOB(KmpHolder_parseCheckpaths, 0x8051377c, 0x80513adc);
asm UNKNOWN_FUNCTION(KmpHolder_parseCheckpaths) {
  // clang-format off
  nofralloc
  /* 8051377C 9421FFA0 */ stwu        r1, -0x60(r1)
  /* 80513780 7C0802A6 */ mflr        r0
  /* 80513784 90010064 */ stw         r0, 0x64(r1)
  /* 80513788 DBE10050 */ stfd        f31, 0x50(r1)
  /* 8051378C F3E10058 */ opword      0xf3e10058
  /* 80513790 DBC10040 */ stfd        f30, 0x40(r1)
  /* 80513794 F3C10048 */ opword      0xf3c10048
  /* 80513798 39610040 */ addi        r11, r1, 0x40
  /* 8051379C 4BB0DDF1 */ bl          _savegpr_22
  /* 805137A0 80A30004 */ lwz         r5, 4(r3)
  /* 805137A4 3AE00000 */ li          r23, 0x0
  /* 805137A8 38C00000 */ li          r6, 0x0
  /* 805137AC 80E50000 */ lwz         r7, 0(r5)
  /* 805137B0 A0070008 */ lhz         r0, 8(r7)
  /* 805137B4 7C0903A6 */ mtctr       r0
  /* 805137B8 28000000 */ cmplwi      r0, 0
  /* 805137BC 40810030 */ ble-        lbl_805137ec
  lbl_805137c0:
  /* 805137C0 A007000A */ lhz         r0, 0xa(r7)
  /* 805137C4 80650004 */ lwz         r3, 4(r5)
  /* 805137C8 7C070214 */ add         r0, r7, r0
  /* 805137CC 7C63302E */ lwzx        r3, r3, r6
  /* 805137D0 7C03006E */ lwzux       r0, r3, r0
  /* 805137D4 7C002040 */ cmplw       r0, r4
  /* 805137D8 4082000C */ bne-        lbl_805137e4
  /* 805137DC 7C771B78 */ mr          r23, r3
  /* 805137E0 4800000C */ b           lbl_805137ec
  lbl_805137e4:
  /* 805137E4 38C60004 */ addi        r6, r6, 0x4
  /* 805137E8 4200FFD8 */ bdnz        lbl_805137c0
  lbl_805137ec:
  /* 805137EC 2C170000 */ cmpwi       r23, 0x0
  /* 805137F0 3B000000 */ li          r24, 0x0
  /* 805137F4 418202BC */ beq-        lbl_80513ab0
  /* 805137F8 38600010 */ li          r3, 0x10
  /* 805137FC 4BD165D1 */ bl          __nw__FUl
  /* 80513800 2C030000 */ cmpwi       r3, 0x0
  /* 80513804 7C781B78 */ mr          r24, r3
  /* 80513808 418202A8 */ beq-        lbl_80513ab0
  /* 8051380C 38000000 */ li          r0, 0x0
  /* 80513810 90030000 */ stw         r0, 0(r3)
  /* 80513814 3B770008 */ addi        r27, r23, 0x8
  /* 80513818 B0030004 */ sth         r0, 4(r3)
  /* 8051381C 92E30008 */ stw         r23, 8(r3)
  /* 80513820 A3570004 */ lhz         r26, 4(r23)
  /* 80513824 2C1A0000 */ cmpwi       r26, 0x0
  /* 80513828 41820014 */ beq-        lbl_8051383c
  /* 8051382C B3430004 */ sth         r26, 4(r3)
  /* 80513830 574313BA */ rlwinm      r3, r26, 2, 0xe, 0x1d
  /* 80513834 4BD165BD */ bl          __nwa__FUl
  /* 80513838 90780000 */ stw         r3, 0(r24)
  lbl_8051383c:
  /* 8051383C 3C808089 */ lis         r4, lbl_8088fa44@ha
  /* 80513840 3C608089 */ lis         r3, lbl_8088fa48@ha
  /* 80513844 C3C4FA44 */ lfs         f30, lbl_8088fa44@l(r4)
  /* 80513848 3AC00000 */ li          r22, 0x0
  /* 8051384C CBE3FA48 */ lfd         f31, lbl_8088fa48@l(r3)
  /* 80513850 3B20FFFF */ li          r25, -0x1
  /* 80513854 3EE04330 */ lis         r23, 0x4330
  /* 80513858 48000054 */ b           lbl_805138ac
  lbl_8051385c:
  /* 8051385C 3860000C */ li          r3, 0xc
  /* 80513860 4BD1656D */ bl          __nw__FUl
  /* 80513864 2C030000 */ cmpwi       r3, 0x0
  /* 80513868 41820034 */ beq-        lbl_8051389c
  /* 8051386C 56C02336 */ rlwinm      r0, r22, 4, 0xc, 0x1b
  /* 80513870 92E10008 */ stw         r23, 8(r1)
  /* 80513874 7C9B0214 */ add         r4, r27, r0
  /* 80513878 90830000 */ stw         r4, 0(r3)
  /* 8051387C 9B230004 */ stb         r25, 4(r3)
  /* 80513880 D3C30008 */ stfs        f30, 8(r3)
  /* 80513884 88040001 */ lbz         r0, 1(r4)
  /* 80513888 9001000C */ stw         r0, 0xc(r1)
  /* 8051388C C8010008 */ lfd         f0, 8(r1)
  /* 80513890 EC00F828 */ fsubs       f0, f0, f31
  /* 80513894 EC1E0024 */ fdivs       f0, f30, f0
  /* 80513898 D0030008 */ stfs        f0, 8(r3)
  lbl_8051389c:
  /* 8051389C 80980000 */ lwz         r4, 0(r24)
  /* 805138A0 56C013BA */ rlwinm      r0, r22, 2, 0xe, 0x1d
  /* 805138A4 3AD60001 */ addi        r22, r22, 0x1
  /* 805138A8 7C64012E */ stwx        r3, r4, r0
  lbl_805138ac:
  /* 805138AC 56C0043E */ clrlwi      r0, r22, 0x10
  /* 805138B0 7C00D040 */ cmplw       r0, r26
  /* 805138B4 4180FFA8 */ blt+        lbl_8051385c
  /* 805138B8 A0180004 */ lhz         r0, 4(r24)
  /* 805138BC 2C000000 */ cmpwi       r0, 0x0
  /* 805138C0 418201F0 */ beq-        lbl_80513ab0
  /* 805138C4 3BC0FFFF */ li          r30, -0x1
  /* 805138C8 41820010 */ beq-        lbl_805138d8
  /* 805138CC 80780000 */ lwz         r3, 0(r24)
  /* 805138D0 83A30000 */ lwz         r29, 0(r3)
  /* 805138D4 48000008 */ b           lbl_805138dc
  lbl_805138d8:
  /* 805138D8 3BA00000 */ li          r29, 0x0
  lbl_805138dc:
  /* 805138DC 881D0004 */ lbz         r0, 4(r29)
  /* 805138E0 7C000774 */ extsb       r0, r0
  /* 805138E4 2C00FFFF */ cmpwi       r0, -0x1
  /* 805138E8 40820120 */ bne-        lbl_80513a08
  /* 805138EC 38000000 */ li          r0, 0x0
  /* 805138F0 981D0004 */ stb         r0, 4(r29)
  /* 805138F4 3B200000 */ li          r25, 0x0
  /* 805138F8 3AE00002 */ li          r23, 0x2
  /* 805138FC 3BE00001 */ li          r31, 0x1
  lbl_80513900:
  /* 80513900 807D0000 */ lwz         r3, 0(r29)
  /* 80513904 5720043E */ clrlwi      r0, r25, 0x10
  /* 80513908 7C630214 */ add         r3, r3, r0
  /* 8051390C 88830008 */ lbz         r4, 8(r3)
  /* 80513910 280400FF */ cmplwi      r4, 0xff
  /* 80513914 418200E8 */ beq-        lbl_805139fc
  /* 80513918 A0180004 */ lhz         r0, 4(r24)
  /* 8051391C 7C040040 */ cmplw       r4, r0
  /* 80513920 40800014 */ bge-        lbl_80513934
  /* 80513924 80780000 */ lwz         r3, 0(r24)
  /* 80513928 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 8051392C 7F43002E */ lwzx        r26, r3, r0
  /* 80513930 48000008 */ b           lbl_80513938
  lbl_80513934:
  /* 80513934 3B400000 */ li          r26, 0x0
  lbl_80513938:
  /* 80513938 881A0004 */ lbz         r0, 4(r26)
  /* 8051393C 7C000774 */ extsb       r0, r0
  /* 80513940 2C00FFFF */ cmpwi       r0, -0x1
  /* 80513944 408200B8 */ bne-        lbl_805139fc
  /* 80513948 9BFA0004 */ stb         r31, 4(r26)
  /* 8051394C 3B600000 */ li          r27, 0x0
  lbl_80513950:
  /* 80513950 807A0000 */ lwz         r3, 0(r26)
  /* 80513954 5760043E */ clrlwi      r0, r27, 0x10
  /* 80513958 7C630214 */ add         r3, r3, r0
  /* 8051395C 88830008 */ lbz         r4, 8(r3)
  /* 80513960 280400FF */ cmplwi      r4, 0xff
  /* 80513964 4182008C */ beq-        lbl_805139f0
  /* 80513968 A0180004 */ lhz         r0, 4(r24)
  /* 8051396C 7C040040 */ cmplw       r4, r0
  /* 80513970 40800014 */ bge-        lbl_80513984
  /* 80513974 80780000 */ lwz         r3, 0(r24)
  /* 80513978 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 8051397C 7F83002E */ lwzx        r28, r3, r0
  /* 80513980 48000008 */ b           lbl_80513988
  lbl_80513984:
  /* 80513984 3B800000 */ li          r28, 0x0
  lbl_80513988:
  /* 80513988 881C0004 */ lbz         r0, 4(r28)
  /* 8051398C 7C000774 */ extsb       r0, r0
  /* 80513990 2C00FFFF */ cmpwi       r0, -0x1
  /* 80513994 4082005C */ bne-        lbl_805139f0
  /* 80513998 9AFC0004 */ stb         r23, 4(r28)
  /* 8051399C 3AC00000 */ li          r22, 0x0
  lbl_805139a0:
  /* 805139A0 807C0000 */ lwz         r3, 0(r28)
  /* 805139A4 56C0043E */ clrlwi      r0, r22, 0x10
  /* 805139A8 7C630214 */ add         r3, r3, r0
  /* 805139AC 88830008 */ lbz         r4, 8(r3)
  /* 805139B0 280400FF */ cmplwi      r4, 0xff
  /* 805139B4 41820030 */ beq-        lbl_805139e4
  /* 805139B8 A0180004 */ lhz         r0, 4(r24)
  /* 805139BC 7C040040 */ cmplw       r4, r0
  /* 805139C0 40800014 */ bge-        lbl_805139d4
  /* 805139C4 80780000 */ lwz         r3, 0(r24)
  /* 805139C8 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 805139CC 7C63002E */ lwzx        r3, r3, r0
  /* 805139D0 48000008 */ b           lbl_805139d8
  lbl_805139d4:
  /* 805139D4 38600000 */ li          r3, 0x0
  lbl_805139d8:
  /* 805139D8 7F05C378 */ mr          r5, r24
  /* 805139DC 38800003 */ li          r4, 0x3
  /* 805139E0 48001701 */ bl          unk_805150e0
  lbl_805139e4:
  /* 805139E4 3AD60001 */ addi        r22, r22, 0x1
  /* 805139E8 28160006 */ cmplwi      r22, 6
  /* 805139EC 4180FFB4 */ blt+        lbl_805139a0
  lbl_805139f0:
  /* 805139F0 3B7B0001 */ addi        r27, r27, 0x1
  /* 805139F4 281B0006 */ cmplwi      r27, 6
  /* 805139F8 4180FF58 */ blt+        lbl_80513950
  lbl_805139fc:
  /* 805139FC 3B390001 */ addi        r25, r25, 0x1
  /* 80513A00 28190006 */ cmplwi      r25, 6
  /* 80513A04 4180FEFC */ blt+        lbl_80513900
  lbl_80513a08:
  /* 80513A08 A0B80004 */ lhz         r5, 4(r24)
  /* 80513A0C 38800000 */ li          r4, 0x0
  /* 80513A10 48000060 */ b           lbl_80513a70
  lbl_80513a14:
  /* 80513A14 5480043E */ clrlwi      r0, r4, 0x10
  /* 80513A18 7C002840 */ cmplw       r0, r5
  /* 80513A1C 40800014 */ bge-        lbl_80513a30
  /* 80513A20 80780000 */ lwz         r3, 0(r24)
  /* 80513A24 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80513A28 7C63002E */ lwzx        r3, r3, r0
  /* 80513A2C 48000008 */ b           lbl_80513a34
  lbl_80513a30:
  /* 80513A30 38600000 */ li          r3, 0x0
  lbl_80513a34:
  /* 80513A34 88030004 */ lbz         r0, 4(r3)
  /* 80513A38 7C000774 */ extsb       r0, r0
  /* 80513A3C 7C00F000 */ cmpw        r0, r30
  /* 80513A40 4081002C */ ble-        lbl_80513a6c
  /* 80513A44 5480043E */ clrlwi      r0, r4, 0x10
  /* 80513A48 7C002840 */ cmplw       r0, r5
  /* 80513A4C 40800014 */ bge-        lbl_80513a60
  /* 80513A50 80780000 */ lwz         r3, 0(r24)
  /* 80513A54 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80513A58 7C63002E */ lwzx        r3, r3, r0
  /* 80513A5C 48000008 */ b           lbl_80513a64
  lbl_80513a60:
  /* 80513A60 38600000 */ li          r3, 0x0
  lbl_80513a64:
  /* 80513A64 88030004 */ lbz         r0, 4(r3)
  /* 80513A68 7C1E0774 */ extsb       r30, r0
  lbl_80513a6c:
  /* 80513A6C 38840001 */ addi        r4, r4, 0x1
  lbl_80513a70:
  /* 80513A70 5480043E */ clrlwi      r0, r4, 0x10
  /* 80513A74 7C002840 */ cmplw       r0, r5
  /* 80513A78 4180FF9C */ blt+        lbl_80513a14
  /* 80513A7C 6FC38000 */ xoris       r3, r30, 0x8000
  /* 80513A80 3C004330 */ lis         r0, 0x4330
  /* 80513A84 9061000C */ stw         r3, 0xc(r1)
  /* 80513A88 3C808089 */ lis         r4, lbl_8088fa50@ha
  /* 80513A8C C844FA50 */ lfd         f2, lbl_8088fa50@l(r4)
  /* 80513A90 3C608089 */ lis         r3, lbl_8088fa44@ha
  /* 80513A94 90010008 */ stw         r0, 8(r1)
  /* 80513A98 C023FA44 */ lfs         f1, lbl_8088fa44@l(r3)
  /* 80513A9C C8010008 */ lfd         f0, 8(r1)
  /* 80513AA0 EC001028 */ fsubs       f0, f0, f2
  /* 80513AA4 EC01002A */ fadds       f0, f1, f0
  /* 80513AA8 EC010024 */ fdivs       f0, f1, f0
  /* 80513AAC D018000C */ stfs        f0, 0xc(r24)
  lbl_80513ab0:
  /* 80513AB0 7F03C378 */ mr          r3, r24
  /* 80513AB4 E3E10058 */ opword      0xe3e10058
  /* 80513AB8 CBE10050 */ lfd         f31, 0x50(r1)
  /* 80513ABC E3C10048 */ opword      0xe3c10048
  /* 80513AC0 CBC10040 */ lfd         f30, 0x40(r1)
  /* 80513AC4 39610040 */ addi        r11, r1, 0x40
  /* 80513AC8 4BB0DB11 */ bl          _restgpr_22
  /* 80513ACC 80010064 */ lwz         r0, 0x64(r1)
  /* 80513AD0 7C0803A6 */ mtlr        r0
  /* 80513AD4 38210060 */ addi        r1, r1, 0x60
  /* 80513AD8 4E800020 */ blr
  // clang-format on
}

namespace System {

MapdataItemPointAccessor* CourseMap::parseItemPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataItemPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataItemPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataItemPathAccessor* CourseMap::parseItemPaths(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataItemPathAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataItemPathAccessor(sectionPtr);
  }

  return accessor;
}

MapdataEnemyPointAccessor* CourseMap::parseEnemyPoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataEnemyPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataEnemyPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataEnemyPathAccessor* CourseMap::parseEnemyPaths(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataEnemyPathAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataEnemyPathAccessor(sectionPtr);
  }

  return accessor;
}

MapdataStartPointAccessor* CourseMap::parseKartpoints(u32 sectionName) {
  const KmpSectionHeader* sectionPtr = mpCourse->findSection(sectionName);

  MapdataStartPointAccessor* accessor = nullptr;
  if (sectionPtr) {
    accessor = new MapdataStartPointAccessor(sectionPtr);
  }

  return accessor;
}

MapdataAreaBase* MapdataAreaAccessor::get(u16 i) const {
  return i < this->size() ? this->entries[i] : nullptr;
}

MapdataJugemPoint* MapdataJugemPointAccessor::get(u16 i) const {
  return i < this->size() ? this->entries[i] : nullptr;
}

MapdataStartPoint* MapdataStartPointAccessor::get(u16 i) const {
  return i < this->size() ? this->entries[i] : nullptr;
}

MapdataGeoObj* CourseMap::getGeoObj(u16 i) const {
  u16 count = mpGeoObj ? mpGeoObj->size() : 0;
  return i < count ? mpGeoObj->get(i) : nullptr;
}

MapdataPointInfo* MapdataGeoObj::getPointInfo() const {
  return mpData->pathId == -1
             ? nullptr
             : CourseMap::instance()->getPointInfo(mpData->pathId);
}

const KmpSectionHeader*
MapdataFileAccessor::findSection(u32 sectionName) const {
  const KmpSectionHeader* sectionPtr = nullptr;

  for (u32 i = 0; i < mpData->numSections; i++) {
    const KmpSectionHeader* header =
        (const KmpSectionHeader*)((u8*)mpData + mpData->headerSize +
                                  mpSectionDef[i]);
    if (header->sectionMagic == sectionName) {
      sectionPtr = header;
      break;
    }
  }

  return sectionPtr;
}

MapdataStartPointAccessor::MapdataStartPointAccessor(
    const KmpSectionHeader* header)
    : MapdataAccessorBase<MapdataStartPoint, MapdataStartPoint::SData>(header) {
  if (CourseMap::instance()->getVersion() > 1830) {
    init((const MapdataStartPoint::SData*)(sectionHeader + 1),
         sectionHeader->entryCount);
  } else {
    init((const MapdataStartPoint::SData*)((u8*)sectionHeader + 4), 1);
  }
}

} // namespace System

// Symbol: unk_80514368
// PAL: 0x80514368..0x80514794
MARK_BINARY_BLOB(unk_80514368, 0x80514368, 0x80514794);
asm UNKNOWN_FUNCTION(unk_80514368) {
  // clang-format off
  nofralloc
  /* 80514368 9421FEA0 */ stwu        r1, -0x160(r1)
  /* 8051436C 7C0802A6 */ mflr        r0
  /* 80514370 90010164 */ stw         r0, 0x164(r1)
  /* 80514374 DBE10150 */ stfd        f31, 0x150(r1)
  /* 80514378 F3E10158 */ opword      0xf3e10158
  /* 8051437C DBC10140 */ stfd        f30, 0x140(r1)
  /* 80514380 F3C10148 */ opword      0xf3c10148
  /* 80514384 39610140 */ addi        r11, r1, 0x140
  /* 80514388 4BB0D209 */ bl          _savegpr_23
  /* 8051438C 2C040000 */ cmpwi       r4, 0x0
  /* 80514390 3C004330 */ lis         r0, 0x4330
  /* 80514394 3FA08089 */ lis         r29, lbl_8088f8e8@ha
  /* 80514398 3FC0808B */ lis         r30, lbl_808b2c20@ha
  /* 8051439C 90010108 */ stw         r0, 0x108(r1)
  /* 805143A0 7C771B78 */ mr          r23, r3
  /* 805143A4 7C982378 */ mr          r24, r4
  /* 805143A8 7CB92B78 */ mr          r25, r5
  /* 805143AC 90010110 */ stw         r0, 0x110(r1)
  /* 805143B0 7CDA3378 */ mr          r26, r6
  /* 805143B4 7CFC3B78 */ mr          r28, r7
  /* 805143B8 3BBDF8E8 */ addi        r29, r29, lbl_8088f8e8@l
  /* 805143BC 3BDE2C20 */ addi        r30, r30, lbl_808b2c20@l
  /* 805143C0 41820388 */ beq-        lbl_80514748
  /* 805143C4 80830000 */ lwz         r4, 0(r3)
  /* 805143C8 386100F8 */ addi        r3, r1, 0xf8
  /* 805143CC C07D0170 */ lfs         f3, 0x170(r29)
  /* 805143D0 C024000C */ lfs         f1, 0xc(r4)
  /* 805143D4 C0440010 */ lfs         f2, 0x10(r4)
  /* 805143D8 C0040014 */ lfs         f0, 0x14(r4)
  /* 805143DC EC230072 */ fmuls       f1, f3, f1
  /* 805143E0 EC4300B2 */ fmuls       f2, f3, f2
  /* 805143E4 EC630032 */ fmuls       f3, f3, f0
  /* 805143E8 4BD25B71 */ bl          setRPY__Q23EGG5QuatfFfff
  /* 805143EC 3C80802A */ lis         r4, lbl_802a4148@ha
  /* 805143F0 386100B0 */ addi        r3, r1, 0xb0
  /* 805143F4 38844148 */ addi        r4, r4, lbl_802a4148@l
  /* 805143F8 480003DD */ bl          VEC3_fromNeg
  /* 805143FC 386100A4 */ addi        r3, r1, 0xa4
  /* 80514400 388100F8 */ addi        r4, r1, 0xf8
  /* 80514404 38A100B0 */ addi        r5, r1, 0xb0
  /* 80514408 480003F5 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 8051440C C04100A4 */ lfs         f2, 0xa4(r1)
  /* 80514410 3C80802A */ lis         r4, lbl_802a4118@ha
  /* 80514414 C02100A8 */ lfs         f1, 0xa8(r1)
  /* 80514418 38610098 */ addi        r3, r1, 0x98
  /* 8051441C C00100AC */ lfs         f0, 0xac(r1)
  /* 80514420 38844118 */ addi        r4, r4, lbl_802a4118@l
  /* 80514424 D04100EC */ stfs        f2, 0xec(r1)
  /* 80514428 D02100F0 */ stfs        f1, 0xf0(r1)
  /* 8051442C D00100F4 */ stfs        f0, 0xf4(r1)
  /* 80514430 480003A5 */ bl          VEC3_fromNeg
  /* 80514434 3861008C */ addi        r3, r1, 0x8c
  /* 80514438 388100F8 */ addi        r4, r1, 0xf8
  /* 8051443C 38A10098 */ addi        r5, r1, 0x98
  /* 80514440 480003BD */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80514444 C041008C */ lfs         f2, 0x8c(r1)
  /* 80514448 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 8051444C C0210090 */ lfs         f1, 0x90(r1)
  /* 80514450 3B600001 */ li          r27, 0x1
  /* 80514454 C0010094 */ lfs         f0, 0x94(r1)
  /* 80514458 D04100E0 */ stfs        f2, 0xe0(r1)
  /* 8051445C 80A3D6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r3)
  /* 80514460 D02100E4 */ stfs        f1, 0xe4(r1)
  /* 80514464 D00100E8 */ stfs        f0, 0xe8(r1)
  /* 80514468 8085003C */ lwz         r4, 0x3c(r5)
  /* 8051446C 2C040000 */ cmpwi       r4, 0x0
  /* 80514470 41820028 */ beq-        lbl_80514498
  /* 80514474 A0040004 */ lhz         r0, 4(r4)
  /* 80514478 2C000000 */ cmpwi       r0, 0x0
  /* 8051447C 4182001C */ beq-        lbl_80514498
  /* 80514480 41820010 */ beq-        lbl_80514490
  /* 80514484 80640000 */ lwz         r3, 0(r4)
  /* 80514488 80030000 */ lwz         r0, 0(r3)
  /* 8051448C 48000010 */ b           lbl_8051449c
  lbl_80514490:
  /* 80514490 38000000 */ li          r0, 0x0
  /* 80514494 48000008 */ b           lbl_8051449c
  lbl_80514498:
  /* 80514498 38000000 */ li          r0, 0x0
  lbl_8051449c:
  /* 8051449C 2C000000 */ cmpwi       r0, 0x0
  /* 805144A0 4182004C */ beq-        lbl_805144ec
  /* 805144A4 2C040000 */ cmpwi       r4, 0x0
  /* 805144A8 4182002C */ beq-        lbl_805144d4
  /* 805144AC 8065003C */ lwz         r3, 0x3c(r5)
  /* 805144B0 A0030004 */ lhz         r0, 4(r3)
  /* 805144B4 2C000000 */ cmpwi       r0, 0x0
  /* 805144B8 4182001C */ beq-        lbl_805144d4
  /* 805144BC 41820010 */ beq-        lbl_805144cc
  /* 805144C0 80630000 */ lwz         r3, 0(r3)
  /* 805144C4 80630000 */ lwz         r3, 0(r3)
  /* 805144C8 48000010 */ b           lbl_805144d8
  lbl_805144cc:
  /* 805144CC 38600000 */ li          r3, 0x0
  /* 805144D0 48000008 */ b           lbl_805144d8
  lbl_805144d4:
  /* 805144D4 38600000 */ li          r3, 0x0
  lbl_805144d8:
  /* 805144D8 80630000 */ lwz         r3, 0(r3)
  /* 805144DC 88030001 */ lbz         r0, 1(r3)
  /* 805144E0 2C000001 */ cmpwi       r0, 0x1
  /* 805144E4 40820008 */ bne-        lbl_805144ec
  /* 805144E8 3B60FFFF */ li          r27, -0x1
  lbl_805144ec:
  /* 805144EC C03E0008 */ lfs         f1, 8(r30)
  /* 805144F0 C01D0174 */ lfs         f0, 0x174(r29)
  /* 805144F4 EC200072 */ fmuls       f1, f0, f1
  /* 805144F8 4BB70C89 */ bl          CosFIdx__Q24nw4r4mathFf
  /* 805144FC FFE00890 */ fmr         f31, f1
  /* 80514500 C03E0008 */ lfs         f1, 8(r30)
  /* 80514504 C01D0174 */ lfs         f0, 0x174(r29)
  /* 80514508 EC200072 */ fmuls       f1, f0, f1
  /* 8051450C 4BB70C05 */ bl          SinFIdx__Q24nw4r4mathFf
  /* 80514510 6F608000 */ xoris       r0, r27, 0x8000
  /* 80514514 9001010C */ stw         r0, 0x10c(r1)
  /* 80514518 C85D0168 */ lfd         f2, 0x168(r29)
  /* 8051451C 38610080 */ addi        r3, r1, 0x80
  /* 80514520 C8010108 */ lfd         f0, 0x108(r1)
  /* 80514524 388100EC */ addi        r4, r1, 0xec
  /* 80514528 EC001028 */ fsubs       f0, f0, f2
  /* 8051452C EFC00072 */ fmuls       f30, f0, f1
  /* 80514530 480002A5 */ bl          VEC3_fromNeg
  /* 80514534 381CFFFF */ addi        r0, r28, -0x1
  /* 80514538 3BFD0000 */ addi        r31, r29, 0x0
  /* 8051453C 1F80000C */ mulli       r28, r0, 0xc
  /* 80514540 C87D0168 */ lfd         f3, 0x168(r29)
  /* 80514544 C05D0178 */ lfs         f2, 0x178(r29)
  /* 80514548 38610074 */ addi        r3, r1, 0x74
  /* 8051454C C01E0000 */ lfs         f0, 0(r30)
  /* 80514550 38810080 */ addi        r4, r1, 0x80
  /* 80514554 7C1FE0AE */ lbzx        r0, r31, r28
  /* 80514558 7C000774 */ extsb       r0, r0
  /* 8051455C 7C1B01D6 */ mullw       r0, r27, r0
  /* 80514560 6C008000 */ xoris       r0, r0, 0x8000
  /* 80514564 90010114 */ stw         r0, 0x114(r1)
  /* 80514568 C8210110 */ lfd         f1, 0x110(r1)
  /* 8051456C EC211828 */ fsubs       f1, f1, f3
  /* 80514570 EC22082A */ fadds       f1, f2, f1
  /* 80514574 EC000072 */ fmuls       f0, f0, f1
  /* 80514578 EC001024 */ fdivs       f0, f0, f2
  /* 8051457C EC1E0032 */ fmuls       f0, f30, f0
  /* 80514580 EC20F824 */ fdivs       f1, f0, f31
  /* 80514584 4800028D */ bl          Vec3_scale
  /* 80514588 381D0090 */ addi        r0, r29, 0x90
  /* 8051458C C1210074 */ lfs         f9, 0x74(r1)
  /* 80514590 7C00E214 */ add         r0, r0, r28
  /* 80514594 C1010078 */ lfs         f8, 0x78(r1)
  /* 80514598 7C1A00AE */ lbzx        r0, r26, r0
  /* 8051459C 3CA0809C */ lis         r5, lbl_809bd6ec@ha
  /* 805145A0 C0E1007C */ lfs         f7, 0x7c(r1)
  /* 805145A4 38610068 */ addi        r3, r1, 0x68
  /* 805145A8 7C060774 */ extsb       r6, r0
  /* 805145AC C8DD0168 */ lfd         f6, 0x168(r29)
  /* 805145B0 7CC00E70 */ srawi       r0, r6, 1
  /* 805145B4 C05E0004 */ lfs         f2, 4(r30)
  /* 805145B8 6C008000 */ xoris       r0, r0, 0x8000
  /* 805145BC 9001010C */ stw         r0, 0x10c(r1)
  /* 805145C0 38060001 */ addi        r0, r6, 0x1
  /* 805145C4 6CC68000 */ xoris       r6, r6, 0x8000
  /* 805145C8 C8010108 */ lfd         f0, 0x108(r1)
  /* 805145CC 7C000E70 */ srawi       r0, r0, 1
  /* 805145D0 90C10114 */ stw         r6, 0x114(r1)
  /* 805145D4 6C008000 */ xoris       r0, r0, 0x8000
  /* 805145D8 ECA03028 */ fsubs       f5, f0, f6
  /* 805145DC C09E000C */ lfs         f4, 0xc(r30)
  /* 805145E0 9001010C */ stw         r0, 0x10c(r1)
  /* 805145E4 388100EC */ addi        r4, r1, 0xec
  /* 805145E8 C8210110 */ lfd         f1, 0x110(r1)
  /* 805145EC C8010108 */ lfd         f0, 0x108(r1)
  /* 805145F0 EC613028 */ fsubs       f3, f1, f6
  /* 805145F4 D12100D4 */ stfs        f9, 0xd4(r1)
  /* 805145F8 EC203028 */ fsubs       f1, f0, f6
  /* 805145FC C005D6EC */ lfs         f0, lbl_809bd6ec@l(r5)
  /* 80514600 EC840172 */ fmuls       f4, f4, f5
  /* 80514604 D10100D8 */ stfs        f8, 0xd8(r1)
  /* 80514608 EC4200F2 */ fmuls       f2, f2, f3
  /* 8051460C D0E100DC */ stfs        f7, 0xdc(r1)
  /* 80514610 EC000072 */ fmuls       f0, f0, f1
  /* 80514614 EC02002A */ fadds       f0, f2, f0
  /* 80514618 EC24002A */ fadds       f1, f4, f0
  /* 8051461C 480001F5 */ bl          Vec3_scale
  /* 80514620 3861005C */ addi        r3, r1, 0x5c
  /* 80514624 388100D4 */ addi        r4, r1, 0xd4
  /* 80514628 38A10068 */ addi        r5, r1, 0x68
  /* 8051462C 4800020D */ bl          Vec3_add
  /* 80514630 C03E0000 */ lfs         f1, 0(r30)
  /* 80514634 38610050 */ addi        r3, r1, 0x50
  /* 80514638 388100E0 */ addi        r4, r1, 0xe0
  /* 8051463C 480001D5 */ bl          Vec3_scale
  /* 80514640 38610044 */ addi        r3, r1, 0x44
  /* 80514644 3881005C */ addi        r4, r1, 0x5c
  /* 80514648 38A10050 */ addi        r5, r1, 0x50
  /* 8051464C 48000221 */ bl          VEC3_sub
  /* 80514650 C0810044 */ lfs         f4, 0x44(r1)
  /* 80514654 FC20F890 */ fmr         f1, f31
  /* 80514658 C0610048 */ lfs         f3, 0x48(r1)
  /* 8051465C 38610038 */ addi        r3, r1, 0x38
  /* 80514660 C041004C */ lfs         f2, 0x4c(r1)
  /* 80514664 388100E0 */ addi        r4, r1, 0xe0
  /* 80514668 D08100C8 */ stfs        f4, 0xc8(r1)
  /* 8051466C 80B70000 */ lwz         r5, 0(r23)
  /* 80514670 D06100CC */ stfs        f3, 0xcc(r1)
  /* 80514674 D04100D0 */ stfs        f2, 0xd0(r1)
  /* 80514678 C0050000 */ lfs         f0, 0(r5)
  /* 8051467C EC04002A */ fadds       f0, f4, f0
  /* 80514680 D00100C8 */ stfs        f0, 0xc8(r1)
  /* 80514684 C0050004 */ lfs         f0, 4(r5)
  /* 80514688 EC03002A */ fadds       f0, f3, f0
  /* 8051468C D00100CC */ stfs        f0, 0xcc(r1)
  /* 80514690 C0050008 */ lfs         f0, 8(r5)
  /* 80514694 EC02002A */ fadds       f0, f2, f0
  /* 80514698 D00100D0 */ stfs        f0, 0xd0(r1)
  /* 8051469C 48000175 */ bl          Vec3_scale
  /* 805146A0 FC20F090 */ fmr         f1, f30
  /* 805146A4 3861002C */ addi        r3, r1, 0x2c
  /* 805146A8 388100EC */ addi        r4, r1, 0xec
  /* 805146AC 48000165 */ bl          Vec3_scale
  /* 805146B0 38610020 */ addi        r3, r1, 0x20
  /* 805146B4 38810038 */ addi        r4, r1, 0x38
  /* 805146B8 38A1002C */ addi        r5, r1, 0x2c
  /* 805146BC 4800017D */ bl          Vec3_add
  /* 805146C0 7C1FE214 */ add         r0, r31, r28
  /* 805146C4 C0610020 */ lfs         f3, 0x20(r1)
  /* 805146C8 7C1A00AE */ lbzx        r0, r26, r0
  /* 805146CC 38610014 */ addi        r3, r1, 0x14
  /* 805146D0 C05D0178 */ lfs         f2, 0x178(r29)
  /* 805146D4 388100BC */ addi        r4, r1, 0xbc
  /* 805146D8 7C000774 */ extsb       r0, r0
  /* 805146DC C0C10024 */ lfs         f6, 0x24(r1)
  /* 805146E0 7C1B01D6 */ mullw       r0, r27, r0
  /* 805146E4 C0A10028 */ lfs         f5, 0x28(r1)
  /* 805146E8 C89D0168 */ lfd         f4, 0x168(r29)
  /* 805146EC EC0207F2 */ fmuls       f0, f2, f31
  /* 805146F0 D06100BC */ stfs        f3, 0xbc(r1)
  /* 805146F4 C03E0000 */ lfs         f1, 0(r30)
  /* 805146F8 6C008000 */ xoris       r0, r0, 0x8000
  /* 805146FC 90010114 */ stw         r0, 0x114(r1)
  /* 80514700 C8610110 */ lfd         f3, 0x110(r1)
  /* 80514704 D0C100C0 */ stfs        f6, 0xc0(r1)
  /* 80514708 EC632028 */ fsubs       f3, f3, f4
  /* 8051470C D0A100C4 */ stfs        f5, 0xc4(r1)
  /* 80514710 EC42182A */ fadds       f2, f2, f3
  /* 80514714 EC2100B2 */ fmuls       f1, f1, f2
  /* 80514718 EC210024 */ fdivs       f1, f1, f0
  /* 8051471C 480000F5 */ bl          Vec3_scale
  /* 80514720 38610008 */ addi        r3, r1, 0x8
  /* 80514724 388100C8 */ addi        r4, r1, 0xc8
  /* 80514728 38A10014 */ addi        r5, r1, 0x14
  /* 8051472C 4800010D */ bl          Vec3_add
  /* 80514730 C0010008 */ lfs         f0, 8(r1)
  /* 80514734 D0180000 */ stfs        f0, 0(r24)
  /* 80514738 C001000C */ lfs         f0, 0xc(r1)
  /* 8051473C D0180004 */ stfs        f0, 4(r24)
  /* 80514740 C0010010 */ lfs         f0, 0x10(r1)
  /* 80514744 D0180008 */ stfs        f0, 8(r24)
  lbl_80514748:
  /* 80514748 2C190000 */ cmpwi       r25, 0x0
  /* 8051474C 41820020 */ beq-        lbl_8051476c
  /* 80514750 80770000 */ lwz         r3, 0(r23)
  /* 80514754 C0430014 */ lfs         f2, 0x14(r3)
  /* 80514758 C0230010 */ lfs         f1, 0x10(r3)
  /* 8051475C C003000C */ lfs         f0, 0xc(r3)
  /* 80514760 D0190000 */ stfs        f0, 0(r25)
  /* 80514764 D0390004 */ stfs        f1, 4(r25)
  /* 80514768 D0590008 */ stfs        f2, 8(r25)
  lbl_8051476c:
  /* 8051476C E3E10158 */ opword      0xe3e10158
  /* 80514770 CBE10150 */ lfd         f31, 0x150(r1)
  /* 80514774 E3C10148 */ opword      0xe3c10148
  /* 80514778 39610140 */ addi        r11, r1, 0x140
  /* 8051477C CBC10140 */ lfd         f30, 0x140(r1)
  /* 80514780 4BB0CE5D */ bl          _restgpr_23
  /* 80514784 80010164 */ lwz         r0, 0x164(r1)
  /* 80514788 7C0803A6 */ mtlr        r0
  /* 8051478C 38210160 */ addi        r1, r1, 0x160
  /* 80514790 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80514794
// PAL: 0x80514794..0x805147d4
MARK_BINARY_BLOB(unk_80514794, 0x80514794, 0x805147d4);
asm UNKNOWN_FUNCTION(unk_80514794){
  // clang-format off
  nofralloc
  /* 80514794 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 80514798 7C0802A6 */ mflr        r0
  /* 8051479C 2C030000 */ cmpwi       r3, 0x0
  /* 805147A0 90010014 */ stw         r0, 0x14(r1)
  /* 805147A4 93E1000C */ stw         r31, 0xc(r1)
  /* 805147A8 7C7F1B78 */ mr          r31, r3
  /* 805147AC 41820010 */ beq-        lbl_805147bc
  /* 805147B0 2C040000 */ cmpwi       r4, 0x0
  /* 805147B4 40810008 */ ble-        lbl_805147bc
  /* 805147B8 4BD1565D */ bl          __dl__FPv
  lbl_805147bc:
  /* 805147BC 7FE3FB78 */ mr          r3, r31
  /* 805147C0 83E1000C */ lwz         r31, 0xc(r1)
  /* 805147C4 80010014 */ lwz         r0, 0x14(r1)
  /* 805147C8 7C0803A6 */ mtlr        r0
  /* 805147CC 38210010 */ addi        r1, r1, 0x10
  /* 805147D0 4E800020 */ blr
  // clang-format on
}

// Symbol: VEC3_fromNeg
// PAL: 0x805147d4..0x805147fc
MARK_BINARY_BLOB(VEC3_fromNeg, 0x805147d4, 0x805147fc);
asm UNKNOWN_FUNCTION(VEC3_fromNeg){
    // clang-format off
  nofralloc
  /* 805147D4 C0440008 */ lfs         f2, 8(r4)
  /* 805147D8 C0240004 */ lfs         f1, 4(r4)
  /* 805147DC C0040000 */ lfs         f0, 0(r4)
  /* 805147E0 FC401050 */ fneg        f2, f2
  /* 805147E4 FC200850 */ fneg        f1, f1
  /* 805147E8 FC000050 */ fneg        f0, f0
  /* 805147EC D0430008 */ stfs        f2, 8(r3)
  /* 805147F0 D0030000 */ stfs        f0, 0(r3)
  /* 805147F4 D0230004 */ stfs        f1, 4(r3)
  /* 805147F8 4E800020 */ blr
    // clang-format on
}

// TODO: inlined from eggVector.hpp
// Symbol: VEC3_fromQuaternionRotated
// PAL: 0x805147fc..0x80514810
MARK_BINARY_BLOB(
    VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f,
    0x805147fc, 0x80514810);
asm void VEC3_fromQuaternionRotated(EGG::Vector3f& dst, const EGG::Quatf& q,
                                    const EGG::Vector3f& src){
    // clang-format off
  nofralloc
  /* 805147FC 7C601B78 */ mr          r0, r3
  /* 80514800 7C832378 */ mr          r3, r4
  /* 80514804 7CA42B78 */ mr          r4, r5
  /* 80514808 7C050378 */ mr          r5, r0
  /* 8051480C 4BD25AC4 */ b           rotateVector__Q23EGG5QuatfFRCQ23EGG8Vector3f
    // clang-format on
}

// Symbol: Vec3_scale
// PAL: 0x80514810..0x80514838
MARK_BINARY_BLOB(Vec3_scale, 0x80514810, 0x80514838);
asm UNKNOWN_FUNCTION(Vec3_scale){
    // clang-format off
  nofralloc
  /* 80514810 C0640008 */ lfs         f3, 8(r4)
  /* 80514814 C0440004 */ lfs         f2, 4(r4)
  /* 80514818 C0040000 */ lfs         f0, 0(r4)
  /* 8051481C EC630072 */ fmuls       f3, f3, f1
  /* 80514820 EC420072 */ fmuls       f2, f2, f1
  /* 80514824 EC000072 */ fmuls       f0, f0, f1
  /* 80514828 D0630008 */ stfs        f3, 8(r3)
  /* 8051482C D0030000 */ stfs        f0, 0(r3)
  /* 80514830 D0430004 */ stfs        f2, 4(r3)
  /* 80514834 4E800020 */ blr
    // clang-format on
}

// Symbol: Vec3_add
// PAL: 0x80514838..0x8051486c
MARK_BINARY_BLOB(Vec3_add, 0x80514838, 0x8051486c);
asm UNKNOWN_FUNCTION(Vec3_add){
    // clang-format off
  nofralloc
  /* 80514838 C0240008 */ lfs         f1, 8(r4)
  /* 8051483C C0050008 */ lfs         f0, 8(r5)
  /* 80514840 C0640004 */ lfs         f3, 4(r4)
  /* 80514844 EC81002A */ fadds       f4, f1, f0
  /* 80514848 C0450004 */ lfs         f2, 4(r5)
  /* 8051484C C0240000 */ lfs         f1, 0(r4)
  /* 80514850 C0050000 */ lfs         f0, 0(r5)
  /* 80514854 EC43102A */ fadds       f2, f3, f2
  /* 80514858 D0830008 */ stfs        f4, 8(r3)
  /* 8051485C EC01002A */ fadds       f0, f1, f0
  /* 80514860 D0430004 */ stfs        f2, 4(r3)
  /* 80514864 D0030000 */ stfs        f0, 0(r3)
  /* 80514868 4E800020 */ blr
    // clang-format on
}

// Symbol: VEC3_sub
// PAL: 0x8051486c..0x805148a0
MARK_BINARY_BLOB(VEC3_sub, 0x8051486c, 0x805148a0);
asm UNKNOWN_FUNCTION(VEC3_sub){
    // clang-format off
  nofralloc
  /* 8051486C C0240008 */ lfs         f1, 8(r4)
  /* 80514870 C0050008 */ lfs         f0, 8(r5)
  /* 80514874 C0640004 */ lfs         f3, 4(r4)
  /* 80514878 EC810028 */ fsubs       f4, f1, f0
  /* 8051487C C0450004 */ lfs         f2, 4(r5)
  /* 80514880 C0240000 */ lfs         f1, 0(r4)
  /* 80514884 C0050000 */ lfs         f0, 0(r5)
  /* 80514888 EC431028 */ fsubs       f2, f3, f2
  /* 8051488C D0830008 */ stfs        f4, 8(r3)
  /* 80514890 EC010028 */ fsubs       f0, f1, f0
  /* 80514894 D0430004 */ stfs        f2, 4(r3)
  /* 80514898 D0030000 */ stfs        f0, 0(r3)
  /* 8051489C 4E800020 */ blr
    // clang-format on
}

// Symbol: unk_805148a0
// PAL: 0x805148a0..0x80514b24
MARK_BINARY_BLOB(unk_805148a0, 0x805148a0, 0x80514b24);
asm UNKNOWN_FUNCTION(unk_805148a0) {
  // clang-format off
  nofralloc
  /* 805148A0 9421FF70 */ stwu        r1, -0x90(r1)
  /* 805148A4 7C0802A6 */ mflr        r0
  /* 805148A8 90010094 */ stw         r0, 0x94(r1)
  /* 805148AC DBE10080 */ stfd        f31, 0x80(r1)
  /* 805148B0 F3E10088 */ opword      0xf3e10088
  /* 805148B4 DBC10070 */ stfd        f30, 0x70(r1)
  /* 805148B8 F3C10078 */ opword      0xf3c10078
  /* 805148BC DBA10060 */ stfd        f29, 0x60(r1)
  /* 805148C0 F3A10068 */ opword      0xf3a10068
  /* 805148C4 93E1005C */ stw         r31, 0x5c(r1)
  /* 805148C8 7C7F1B78 */ mr          r31, r3
  /* 805148CC 93C10058 */ stw         r30, 0x58(r1)
  /* 805148D0 3FC08089 */ lis         r30, lbl_8088f8e8@ha
  /* 805148D4 3BDEF8E8 */ addi        r30, r30, lbl_8088f8e8@l
  /* 805148D8 80830000 */ lwz         r4, 0(r3)
  /* 805148DC 38610048 */ addi        r3, r1, 0x48
  /* 805148E0 C07E0170 */ lfs         f3, 0x170(r30)
  /* 805148E4 C024000C */ lfs         f1, 0xc(r4)
  /* 805148E8 C0440010 */ lfs         f2, 0x10(r4)
  /* 805148EC C0040014 */ lfs         f0, 0x14(r4)
  /* 805148F0 EC230072 */ fmuls       f1, f3, f1
  /* 805148F4 EC4300B2 */ fmuls       f2, f3, f2
  /* 805148F8 EC630032 */ fmuls       f3, f3, f0
  /* 805148FC 4BD2565D */ bl          setRPY__Q23EGG5QuatfFfff
  /* 80514900 3CA0802A */ lis         r5, lbl_802a4148@ha
  /* 80514904 38610038 */ addi        r3, r1, 0x38
  /* 80514908 38810048 */ addi        r4, r1, 0x48
  /* 8051490C 38A54148 */ addi        r5, r5, lbl_802a4148@l
  /* 80514910 4BFFFEED */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80514914 3CA0802A */ lis         r5, lbl_802a4118@ha
  /* 80514918 3861002C */ addi        r3, r1, 0x2c
  /* 8051491C 38810048 */ addi        r4, r1, 0x48
  /* 80514920 38A54118 */ addi        r5, r5, lbl_802a4118@l
  /* 80514924 4BFFFED9 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80514928 3CA0802A */ lis         r5, lbl_802a4130@ha
  /* 8051492C 38610020 */ addi        r3, r1, 0x20
  /* 80514930 38810048 */ addi        r4, r1, 0x48
  /* 80514934 38A54130 */ addi        r5, r5, lbl_802a4130@l
  /* 80514938 4BFFFEC5 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 8051493C C03E017C */ lfs         f1, 0x17c(r30)
  /* 80514940 4BB70841 */ bl          CosFIdx__Q24nw4r4mathFf
  /* 80514944 FFE00890 */ fmr         f31, f1
  /* 80514948 C03E017C */ lfs         f1, 0x17c(r30)
  /* 8051494C 4BB707C5 */ bl          SinFIdx__Q24nw4r4mathFf
  /* 80514950 EC01F824 */ fdivs       f0, f1, f31
  /* 80514954 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80514958 80E3D6E8 */ lwz         r7, spInstance__Q26System9CourseMap@l(r3)
  /* 8051495C 390000FF */ li          r8, 0xff
  /* 80514960 C03E0180 */ lfs         f1, 0x180(r30)
  /* 80514964 39200000 */ li          r9, 0x0
  /* 80514968 80C70010 */ lwz         r6, 0x10(r7)
  /* 8051496C C1810040 */ lfs         f12, 0x40(r1)
  /* 80514970 7CC00034 */ cntlzw      r0, r6
  /* 80514974 C1610038 */ lfs         f11, 0x38(r1)
  /* 80514978 C141003C */ lfs         f10, 0x3c(r1)
  /* 8051497C 5405D97E */ srwi        r5, r0, 5
  /* 80514980 C13E0154 */ lfs         f9, 0x154(r30)
  /* 80514984 48000138 */ b           lbl_80514abc
  lbl_80514988:
  /* 80514988 2C060000 */ cmpwi       r6, 0x0
  /* 8051498C 5524063E */ clrlwi      r4, r9, 0x18
  /* 80514990 41820010 */ beq-        lbl_805149a0
  /* 80514994 80670010 */ lwz         r3, 0x10(r7)
  /* 80514998 A0030004 */ lhz         r0, 4(r3)
  /* 8051499C 48000008 */ b           lbl_805149a4
  lbl_805149a0:
  /* 805149A0 38000000 */ li          r0, 0x0
  lbl_805149a4:
  /* 805149A4 7C040040 */ cmplw       r4, r0
  /* 805149A8 40800030 */ bge-        lbl_805149d8
  /* 805149AC 80870010 */ lwz         r4, 0x10(r7)
  /* 805149B0 5523063E */ clrlwi      r3, r9, 0x18
  /* 805149B4 A0040004 */ lhz         r0, 4(r4)
  /* 805149B8 7C030040 */ cmplw       r3, r0
  /* 805149BC 40800014 */ bge-        lbl_805149d0
  /* 805149C0 80640000 */ lwz         r3, 0(r4)
  /* 805149C4 552015BA */ rlwinm      r0, r9, 2, 0x16, 0x1d
  /* 805149C8 7C63002E */ lwzx        r3, r3, r0
  /* 805149CC 48000010 */ b           lbl_805149dc
  lbl_805149d0:
  /* 805149D0 38600000 */ li          r3, 0x0
  /* 805149D4 48000008 */ b           lbl_805149dc
  lbl_805149d8:
  /* 805149D8 38600000 */ li          r3, 0x0
  lbl_805149dc:
  /* 805149DC 80630004 */ lwz         r3, 4(r3)
  /* 805149E0 809F0000 */ lwz         r4, 0(r31)
  /* 805149E4 C0830004 */ lfs         f4, 4(r3)
  /* 805149E8 C0C30000 */ lfs         f6, 0(r3)
  /* 805149EC C0640004 */ lfs         f3, 4(r4)
  /* 805149F0 C0440000 */ lfs         f2, 0(r4)
  /* 805149F4 EFE41828 */ fsubs       f31, f4, f3
  /* 805149F8 C0A30008 */ lfs         f5, 8(r3)
  /* 805149FC EDA61028 */ fsubs       f13, f6, f2
  /* 80514A00 C0440008 */ lfs         f2, 8(r4)
  /* 80514A04 D0810018 */ stfs        f4, 0x18(r1)
  /* 80514A08 EFC51028 */ fsubs       f30, f5, f2
  /* 80514A0C EC6B0372 */ fmuls       f3, f11, f13
  /* 80514A10 D0C10014 */ stfs        f6, 0x14(r1)
  /* 80514A14 EC4A07F2 */ fmuls       f2, f10, f31
  /* 80514A18 EC8C07B2 */ fmuls       f4, f12, f30
  /* 80514A1C D0A1001C */ stfs        f5, 0x1c(r1)
  /* 80514A20 EC43102A */ fadds       f2, f3, f2
  /* 80514A24 D1A10008 */ stfs        f13, 8(r1)
  /* 80514A28 D3E1000C */ stfs        f31, 0xc(r1)
  /* 80514A2C EFA4102A */ fadds       f29, f4, f2
  /* 80514A30 D3C10010 */ stfs        f30, 0x10(r1)
  /* 80514A34 FC1D4840 */ opword      0xfc1d4840
  /* 80514A38 4C411382 */ cror        2, 1, 2
  /* 80514A3C 4082007C */ bne-        lbl_80514ab8
  /* 80514A40 C041002C */ lfs         f2, 0x2c(r1)
  /* 80514A44 ED1D0032 */ fmuls       f8, f29, f0
  /* 80514A48 C0810030 */ lfs         f4, 0x30(r1)
  /* 80514A4C C0610020 */ lfs         f3, 0x20(r1)
  /* 80514A50 ECC20372 */ fmuls       f6, f2, f13
  /* 80514A54 C0410024 */ lfs         f2, 0x24(r1)
  /* 80514A58 ECA407F2 */ fmuls       f5, f4, f31
  /* 80514A5C EC630372 */ fmuls       f3, f3, f13
  /* 80514A60 C0E10034 */ lfs         f7, 0x34(r1)
  /* 80514A64 EC4207F2 */ fmuls       f2, f2, f31
  /* 80514A68 C0810028 */ lfs         f4, 0x28(r1)
  /* 80514A6C ECE707B2 */ fmuls       f7, f7, f30
  /* 80514A70 ECA6282A */ fadds       f5, f6, f5
  /* 80514A74 EC43102A */ fadds       f2, f3, f2
  /* 80514A78 EC8407B2 */ fmuls       f4, f4, f30
  /* 80514A7C EC67282A */ fadds       f3, f7, f5
  /* 80514A80 ECA80232 */ fmuls       f5, f8, f8
  /* 80514A84 EC44102A */ fadds       f2, f4, f2
  /* 80514A88 EC6300F2 */ fmuls       f3, f3, f3
  /* 80514A8C EC4200B2 */ fmuls       f2, f2, f2
  /* 80514A90 EC43102A */ fadds       f2, f3, f2
  /* 80514A94 FC022840 */ opword      0xfc022840
  /* 80514A98 40800020 */ bge-        lbl_80514ab8
  /* 80514A9C 5500063E */ clrlwi      r0, r8, 0x18
  /* 80514AA0 280000FF */ cmplwi      r0, 0xff
  /* 80514AA4 4182000C */ beq-        lbl_80514ab0
  /* 80514AA8 FC1D0840 */ opword      0xfc1d0840
  /* 80514AAC 4080000C */ bge-        lbl_80514ab8
  lbl_80514ab0:
  /* 80514AB0 FC20E890 */ fmr         f1, f29
  /* 80514AB4 7D284B78 */ mr          r8, r9
  lbl_80514ab8:
  /* 80514AB8 39290001 */ addi        r9, r9, 0x1
  lbl_80514abc:
  /* 80514ABC 2C050000 */ cmpwi       r5, 0x0
  /* 80514AC0 5524063E */ clrlwi      r4, r9, 0x18
  /* 80514AC4 4182000C */ beq-        lbl_80514ad0
  /* 80514AC8 38000000 */ li          r0, 0x0
  /* 80514ACC 4800000C */ b           lbl_80514ad8
  lbl_80514ad0:
  /* 80514AD0 80670010 */ lwz         r3, 0x10(r7)
  /* 80514AD4 A0030004 */ lhz         r0, 4(r3)
  lbl_80514ad8:
  /* 80514AD8 7C040000 */ cmpw        r4, r0
  /* 80514ADC 4180FEAC */ blt+        lbl_80514988
  /* 80514AE0 5500063E */ clrlwi      r0, r8, 0x18
  /* 80514AE4 280000FF */ cmplwi      r0, 0xff
  /* 80514AE8 40820008 */ bne-        lbl_80514af0
  /* 80514AEC 39000000 */ li          r8, 0x0
  lbl_80514af0:
  /* 80514AF0 991F0004 */ stb         r8, 4(r31)
  /* 80514AF4 E3E10088 */ opword      0xe3e10088
  /* 80514AF8 CBE10080 */ lfd         f31, 0x80(r1)
  /* 80514AFC E3C10078 */ opword      0xe3c10078
  /* 80514B00 CBC10070 */ lfd         f30, 0x70(r1)
  /* 80514B04 E3A10068 */ opword      0xe3a10068
  /* 80514B08 CBA10060 */ lfd         f29, 0x60(r1)
  /* 80514B0C 83E1005C */ lwz         r31, 0x5c(r1)
  /* 80514B10 83C10058 */ lwz         r30, 0x58(r1)
  /* 80514B14 80010094 */ lwz         r0, 0x94(r1)
  /* 80514B18 7C0803A6 */ mtlr        r0
  /* 80514B1C 38210090 */ addi        r1, r1, 0x90
  /* 80514B20 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80514b24
// PAL: 0x80514b24..0x80514b30
MARK_BINARY_BLOB(unk_80514b24, 0x80514b24, 0x80514b30);
asm UNKNOWN_FUNCTION(unk_80514b24) {
  // clang-format off
  nofralloc
  /* 80514B24 3806FFFF */ addi        r0, r6, -0x1
  /* 80514B28 5406063E */ clrlwi      r6, r0, 0x18
  /* 80514B2C 4BFFF83C */ b           unk_80514368
  // clang-format on
}

namespace System {

MapdataStartPoint* CourseMap::getStartPoint(u16 i) const {
  u16 count = mpStartPoint ? mpStartPoint->size() : 0;
  return i < count ? mpStartPoint->get(i) : nullptr;
}

MapdataEnemyPoint* CourseMap::getEnemyPoint(u16 i) const {
  u16 count = mpEnemyPoint ? mpEnemyPoint->size() : 0;
  return i < count ? mpEnemyPoint->get(i) : nullptr;
}

MapdataEnemyPath* CourseMap::getEnemyPath(u16 i) const {
  u16 count =
      (mpEnemyPath && mpEnemyPath->size() != 0) ? mpEnemyPath->size() : 0;
  return i < count ? mpEnemyPath->get(i) : nullptr;
}

} // namespace System

// Symbol: unk_80514c30
// PAL: 0x80514c30..0x80514d3c
MARK_BINARY_BLOB(unk_80514c30, 0x80514c30, 0x80514d3c);
asm UNKNOWN_FUNCTION(unk_80514c30) {
  // clang-format off
  nofralloc
  /* 80514C30 3CA08089 */ lis         r5, lbl_8088fa6c@ha
  /* 80514C34 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80514C38 C005FA6C */ lfs         f0, lbl_8088fa6c@l(r5)
  /* 80514C3C 3C808089 */ lis         r4, ZERO_FLOAT2__6System@ha
  /* 80514C40 D0030004 */ stfs        f0, 4(r3)
  /* 80514C44 3CC0809C */ lis         r6, spInstance__Q26System9CourseMap@ha
  /* 80514C48 80A30000 */ lwz         r5, 0(r3)
  /* 80514C4C D0030008 */ stfs        f0, 8(r3)
  /* 80514C50 C044FA3C */ lfs         f2, ZERO_FLOAT2__6System@l(r4)
  /* 80514C54 89050000 */ lbz         r8, 0(r5)
  /* 80514C58 480000B8 */ b           lbl_80514d10
  lbl_80514c5c:
  /* 80514C5C 80E6D6E8 */ lwz         r7, spInstance__Q26System9CourseMap@l(r6)
  /* 80514C60 5505043E */ clrlwi      r5, r8, 0x10
  /* 80514C64 80870010 */ lwz         r4, 0x10(r7)
  /* 80514C68 2C040000 */ cmpwi       r4, 0x0
  /* 80514C6C 4182000C */ beq-        lbl_80514c78
  /* 80514C70 A0040004 */ lhz         r0, 4(r4)
  /* 80514C74 48000008 */ b           lbl_80514c7c
  lbl_80514c78:
  /* 80514C78 38000000 */ li          r0, 0x0
  lbl_80514c7c:
  /* 80514C7C 7C050040 */ cmplw       r5, r0
  /* 80514C80 40800030 */ bge-        lbl_80514cb0
  /* 80514C84 80A70010 */ lwz         r5, 0x10(r7)
  /* 80514C88 5504043E */ clrlwi      r4, r8, 0x10
  /* 80514C8C A0050004 */ lhz         r0, 4(r5)
  /* 80514C90 7C040040 */ cmplw       r4, r0
  /* 80514C94 40800014 */ bge-        lbl_80514ca8
  /* 80514C98 80850000 */ lwz         r4, 0(r5)
  /* 80514C9C 550013BA */ rlwinm      r0, r8, 2, 0xe, 0x1d
  /* 80514CA0 7C84002E */ lwzx        r4, r4, r0
  /* 80514CA4 48000010 */ b           lbl_80514cb4
  lbl_80514ca8:
  /* 80514CA8 38800000 */ li          r4, 0x0
  /* 80514CAC 48000008 */ b           lbl_80514cb4
  lbl_80514cb0:
  /* 80514CB0 38800000 */ li          r4, 0x0
  lbl_80514cb4:
  /* 80514CB4 80840004 */ lwz         r4, 4(r4)
  /* 80514CB8 C0030004 */ lfs         f0, 4(r3)
  /* 80514CBC C0240008 */ lfs         f1, 8(r4)
  /* 80514CC0 C0640004 */ lfs         f3, 4(r4)
  /* 80514CC4 FC001040 */ opword      0xfc001040
  /* 80514CC8 C0840000 */ lfs         f4, 0(r4)
  /* 80514CCC D0810008 */ stfs        f4, 8(r1)
  /* 80514CD0 D061000C */ stfs        f3, 0xc(r1)
  /* 80514CD4 D0210010 */ stfs        f1, 0x10(r1)
  /* 80514CD8 4180000C */ blt-        lbl_80514ce4
  /* 80514CDC FC001840 */ opword      0xfc001840
  /* 80514CE0 4080000C */ bge-        lbl_80514cec
  lbl_80514ce4:
  /* 80514CE4 C001000C */ lfs         f0, 0xc(r1)
  /* 80514CE8 D0030004 */ stfs        f0, 4(r3)
  lbl_80514cec:
  /* 80514CEC C0230008 */ lfs         f1, 8(r3)
  /* 80514CF0 FC011040 */ opword      0xfc011040
  /* 80514CF4 41800010 */ blt-        lbl_80514d04
  /* 80514CF8 C001000C */ lfs         f0, 0xc(r1)
  /* 80514CFC FC010040 */ opword      0xfc010040
  /* 80514D00 4081000C */ ble-        lbl_80514d0c
  lbl_80514d04:
  /* 80514D04 C001000C */ lfs         f0, 0xc(r1)
  /* 80514D08 D0030008 */ stfs        f0, 8(r3)
  lbl_80514d0c:
  /* 80514D0C 39080001 */ addi        r8, r8, 0x1
  lbl_80514d10:
  /* 80514D10 80E30000 */ lwz         r7, 0(r3)
  /* 80514D14 5505043E */ clrlwi      r5, r8, 0x10
  /* 80514D18 88870001 */ lbz         r4, 1(r7)
  /* 80514D1C 88070000 */ lbz         r0, 0(r7)
  /* 80514D20 7C802214 */ add         r4, r0, r4
  /* 80514D24 3804FFFF */ addi        r0, r4, -0x1
  /* 80514D28 5400063E */ clrlwi      r0, r0, 0x18
  /* 80514D2C 7C050000 */ cmpw        r5, r0
  /* 80514D30 4180FF2C */ blt+        lbl_80514c5c
  /* 80514D34 38210020 */ addi        r1, r1, 0x20
  /* 80514D38 4E800020 */ blr
  // clang-format on
}

namespace System {

MapdataItemPoint* CourseMap::getItemPoint(u16 i) const {
  u16 count = mpItemPoint ? mpItemPoint->size() : 0;
  return i < count ? mpItemPoint->get(i) : nullptr;
}

MapdataItemPath* CourseMap::getItemPath(u16 i) const {
  u16 count = (mpItemPath && mpItemPath->size() != 0) ? mpItemPath->size() : 0;
  return i < count ? mpItemPath->get(i) : nullptr;
}

} // namespace System

// Symbol: unk_80514df0
// PAL: 0x80514df0..0x80515014
MARK_BINARY_BLOB(unk_80514df0, 0x80514df0, 0x80515014);
asm UNKNOWN_FUNCTION(unk_80514df0) {
  // clang-format off
  nofralloc
  /* 80514DF0 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 80514DF4 7C0802A6 */ mflr        r0
  /* 80514DF8 90010044 */ stw         r0, 0x44(r1)
  /* 80514DFC 39610040 */ addi        r11, r1, 0x40
  /* 80514E00 4BB0C78D */ bl          _savegpr_22
  /* 80514E04 A0030004 */ lhz         r0, 4(r3)
  /* 80514E08 7C781B78 */ mr          r24, r3
  /* 80514E0C 3B20FFFF */ li          r25, -0x1
  /* 80514E10 2C000000 */ cmpwi       r0, 0x0
  /* 80514E14 41820010 */ beq-        lbl_80514e24
  /* 80514E18 80630000 */ lwz         r3, 0(r3)
  /* 80514E1C 83C30000 */ lwz         r30, 0(r3)
  /* 80514E20 48000008 */ b           lbl_80514e28
  lbl_80514e24:
  /* 80514E24 3BC00000 */ li          r30, 0x0
  lbl_80514e28:
  /* 80514E28 881E0004 */ lbz         r0, 4(r30)
  /* 80514E2C 7C000774 */ extsb       r0, r0
  /* 80514E30 2C00FFFF */ cmpwi       r0, -0x1
  /* 80514E34 40820120 */ bne-        lbl_80514f54
  /* 80514E38 38000000 */ li          r0, 0x0
  /* 80514E3C 981E0004 */ stb         r0, 4(r30)
  /* 80514E40 3B400000 */ li          r26, 0x0
  /* 80514E44 3AE00002 */ li          r23, 0x2
  /* 80514E48 3BE00001 */ li          r31, 0x1
  lbl_80514e4c:
  /* 80514E4C 807E0000 */ lwz         r3, 0(r30)
  /* 80514E50 5740043E */ clrlwi      r0, r26, 0x10
  /* 80514E54 7C630214 */ add         r3, r3, r0
  /* 80514E58 88830008 */ lbz         r4, 8(r3)
  /* 80514E5C 280400FF */ cmplwi      r4, 0xff
  /* 80514E60 418200E8 */ beq-        lbl_80514f48
  /* 80514E64 A0180004 */ lhz         r0, 4(r24)
  /* 80514E68 7C040040 */ cmplw       r4, r0
  /* 80514E6C 40800014 */ bge-        lbl_80514e80
  /* 80514E70 80780000 */ lwz         r3, 0(r24)
  /* 80514E74 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80514E78 7F63002E */ lwzx        r27, r3, r0
  /* 80514E7C 48000008 */ b           lbl_80514e84
  lbl_80514e80:
  /* 80514E80 3B600000 */ li          r27, 0x0
  lbl_80514e84:
  /* 80514E84 881B0004 */ lbz         r0, 4(r27)
  /* 80514E88 7C000774 */ extsb       r0, r0
  /* 80514E8C 2C00FFFF */ cmpwi       r0, -0x1
  /* 80514E90 408200B8 */ bne-        lbl_80514f48
  /* 80514E94 9BFB0004 */ stb         r31, 4(r27)
  /* 80514E98 3B800000 */ li          r28, 0x0
  lbl_80514e9c:
  /* 80514E9C 807B0000 */ lwz         r3, 0(r27)
  /* 80514EA0 5780043E */ clrlwi      r0, r28, 0x10
  /* 80514EA4 7C630214 */ add         r3, r3, r0
  /* 80514EA8 88830008 */ lbz         r4, 8(r3)
  /* 80514EAC 280400FF */ cmplwi      r4, 0xff
  /* 80514EB0 4182008C */ beq-        lbl_80514f3c
  /* 80514EB4 A0180004 */ lhz         r0, 4(r24)
  /* 80514EB8 7C040040 */ cmplw       r4, r0
  /* 80514EBC 40800014 */ bge-        lbl_80514ed0
  /* 80514EC0 80780000 */ lwz         r3, 0(r24)
  /* 80514EC4 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80514EC8 7FA3002E */ lwzx        r29, r3, r0
  /* 80514ECC 48000008 */ b           lbl_80514ed4
  lbl_80514ed0:
  /* 80514ED0 3BA00000 */ li          r29, 0x0
  lbl_80514ed4:
  /* 80514ED4 881D0004 */ lbz         r0, 4(r29)
  /* 80514ED8 7C000774 */ extsb       r0, r0
  /* 80514EDC 2C00FFFF */ cmpwi       r0, -0x1
  /* 80514EE0 4082005C */ bne-        lbl_80514f3c
  /* 80514EE4 9AFD0004 */ stb         r23, 4(r29)
  /* 80514EE8 3AC00000 */ li          r22, 0x0
  lbl_80514eec:
  /* 80514EEC 807D0000 */ lwz         r3, 0(r29)
  /* 80514EF0 56C0043E */ clrlwi      r0, r22, 0x10
  /* 80514EF4 7C630214 */ add         r3, r3, r0
  /* 80514EF8 88830008 */ lbz         r4, 8(r3)
  /* 80514EFC 280400FF */ cmplwi      r4, 0xff
  /* 80514F00 41820030 */ beq-        lbl_80514f30
  /* 80514F04 A0180004 */ lhz         r0, 4(r24)
  /* 80514F08 7C040040 */ cmplw       r4, r0
  /* 80514F0C 40800014 */ bge-        lbl_80514f20
  /* 80514F10 80780000 */ lwz         r3, 0(r24)
  /* 80514F14 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80514F18 7C63002E */ lwzx        r3, r3, r0
  /* 80514F1C 48000008 */ b           lbl_80514f24
  lbl_80514f20:
  /* 80514F20 38600000 */ li          r3, 0x0
  lbl_80514f24:
  /* 80514F24 7F05C378 */ mr          r5, r24
  /* 80514F28 38800003 */ li          r4, 0x3
  /* 80514F2C 480001B5 */ bl          unk_805150e0
  lbl_80514f30:
  /* 80514F30 3AD60001 */ addi        r22, r22, 0x1
  /* 80514F34 28160006 */ cmplwi      r22, 6
  /* 80514F38 4180FFB4 */ blt+        lbl_80514eec
  lbl_80514f3c:
  /* 80514F3C 3B9C0001 */ addi        r28, r28, 0x1
  /* 80514F40 281C0006 */ cmplwi      r28, 6
  /* 80514F44 4180FF58 */ blt+        lbl_80514e9c
  lbl_80514f48:
  /* 80514F48 3B5A0001 */ addi        r26, r26, 0x1
  /* 80514F4C 281A0006 */ cmplwi      r26, 6
  /* 80514F50 4180FEFC */ blt+        lbl_80514e4c
  lbl_80514f54:
  /* 80514F54 A0980004 */ lhz         r4, 4(r24)
  /* 80514F58 38A00000 */ li          r5, 0x0
  /* 80514F5C 48000060 */ b           lbl_80514fbc
  lbl_80514f60:
  /* 80514F60 54A0043E */ clrlwi      r0, r5, 0x10
  /* 80514F64 7C002040 */ cmplw       r0, r4
  /* 80514F68 40800014 */ bge-        lbl_80514f7c
  /* 80514F6C 80780000 */ lwz         r3, 0(r24)
  /* 80514F70 54A013BA */ rlwinm      r0, r5, 2, 0xe, 0x1d
  /* 80514F74 7C63002E */ lwzx        r3, r3, r0
  /* 80514F78 48000008 */ b           lbl_80514f80
  lbl_80514f7c:
  /* 80514F7C 38600000 */ li          r3, 0x0
  lbl_80514f80:
  /* 80514F80 88030004 */ lbz         r0, 4(r3)
  /* 80514F84 7C000774 */ extsb       r0, r0
  /* 80514F88 7C00C800 */ cmpw        r0, r25
  /* 80514F8C 4081002C */ ble-        lbl_80514fb8
  /* 80514F90 54A0043E */ clrlwi      r0, r5, 0x10
  /* 80514F94 7C002040 */ cmplw       r0, r4
  /* 80514F98 40800014 */ bge-        lbl_80514fac
  /* 80514F9C 80780000 */ lwz         r3, 0(r24)
  /* 80514FA0 54A013BA */ rlwinm      r0, r5, 2, 0xe, 0x1d
  /* 80514FA4 7C63002E */ lwzx        r3, r3, r0
  /* 80514FA8 48000008 */ b           lbl_80514fb0
  lbl_80514fac:
  /* 80514FAC 38600000 */ li          r3, 0x0
  lbl_80514fb0:
  /* 80514FB0 88030004 */ lbz         r0, 4(r3)
  /* 80514FB4 7C190774 */ extsb       r25, r0
  lbl_80514fb8:
  /* 80514FB8 38A50001 */ addi        r5, r5, 0x1
  lbl_80514fbc:
  /* 80514FBC 54A0043E */ clrlwi      r0, r5, 0x10
  /* 80514FC0 7C002040 */ cmplw       r0, r4
  /* 80514FC4 4180FF9C */ blt+        lbl_80514f60
  /* 80514FC8 6F238000 */ xoris       r3, r25, 0x8000
  /* 80514FCC 3C004330 */ lis         r0, 0x4330
  /* 80514FD0 9061000C */ stw         r3, 0xc(r1)
  /* 80514FD4 3C808089 */ lis         r4, lbl_8088fa50@ha
  /* 80514FD8 C844FA50 */ lfd         f2, lbl_8088fa50@l(r4)
  /* 80514FDC 3C608089 */ lis         r3, lbl_8088fa44@ha
  /* 80514FE0 90010008 */ stw         r0, 8(r1)
  /* 80514FE4 39610040 */ addi        r11, r1, 0x40
  /* 80514FE8 C023FA44 */ lfs         f1, lbl_8088fa44@l(r3)
  /* 80514FEC C8010008 */ lfd         f0, 8(r1)
  /* 80514FF0 EC001028 */ fsubs       f0, f0, f2
  /* 80514FF4 EC01002A */ fadds       f0, f1, f0
  /* 80514FF8 EC010024 */ fdivs       f0, f1, f0
  /* 80514FFC D018000C */ stfs        f0, 0xc(r24)
  /* 80515000 4BB0C5D9 */ bl          _restgpr_22
  /* 80515004 80010044 */ lwz         r0, 0x44(r1)
  /* 80515008 7C0803A6 */ mtlr        r0
  /* 8051500C 38210040 */ addi        r1, r1, 0x40
  /* 80515010 4E800020 */ blr
  // clang-format on
}

// Symbol: CheckpathHolder_findCheckpathForCheckpoint
// PAL: 0x80515014..0x80515098
MARK_BINARY_BLOB(CheckpathHolder_findCheckpathForCheckpoint, 0x80515014,
                 0x80515098);
asm UNKNOWN_FUNCTION(CheckpathHolder_findCheckpathForCheckpoint){
  // clang-format off
  nofralloc
  /* 80515014 A1030004 */ lhz         r8, 4(r3)
  /* 80515018 39400000 */ li          r10, 0x0
  /* 8051501C 48000068 */ b           lbl_80515084
  lbl_80515020:
  /* 80515020 5540043E */ clrlwi      r0, r10, 0x10
  /* 80515024 7C004040 */ cmplw       r0, r8
  /* 80515028 40800014 */ bge-        lbl_8051503c
  /* 8051502C 80A30000 */ lwz         r5, 0(r3)
  /* 80515030 554013BA */ rlwinm      r0, r10, 2, 0xe, 0x1d
  /* 80515034 7CC5002E */ lwzx        r6, r5, r0
  /* 80515038 48000008 */ b           lbl_80515040
  lbl_8051503c:
  /* 8051503C 38C00000 */ li          r6, 0x0
  lbl_80515040:
  /* 80515040 81260000 */ lwz         r9, 0(r6)
  /* 80515044 38E00000 */ li          r7, 0x0
  /* 80515048 88A90000 */ lbz         r5, 0(r9)
  /* 8051504C 7C052000 */ cmpw        r5, r4
  /* 80515050 41810020 */ bgt-        lbl_80515070
  /* 80515054 88090001 */ lbz         r0, 1(r9)
  /* 80515058 7CA50214 */ add         r5, r5, r0
  /* 8051505C 3805FFFF */ addi        r0, r5, -0x1
  /* 80515060 5400063E */ clrlwi      r0, r0, 0x18
  /* 80515064 7C040000 */ cmpw        r4, r0
  /* 80515068 41810008 */ bgt-        lbl_80515070
  /* 8051506C 38E00001 */ li          r7, 0x1
  lbl_80515070:
  /* 80515070 2C070000 */ cmpwi       r7, 0x0
  /* 80515074 4182000C */ beq-        lbl_80515080
  /* 80515078 7CC33378 */ mr          r3, r6
  /* 8051507C 4E800020 */ blr
  lbl_80515080:
  /* 80515080 394A0001 */ addi        r10, r10, 0x1
  lbl_80515084:
  /* 80515084 5540043E */ clrlwi      r0, r10, 0x10
  /* 80515088 7C004040 */ cmplw       r0, r8
  /* 8051508C 4180FF94 */ blt+        lbl_80515020
  /* 80515090 38600000 */ li          r3, 0x0
  /* 80515094 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80515098
// PAL: 0x80515098..0x805150e0
MARK_BINARY_BLOB(unk_80515098, 0x80515098, 0x805150e0);
asm UNKNOWN_FUNCTION(unk_80515098) {
  // clang-format off
  nofralloc
  /* 80515098 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 8051509C 3C004330 */ lis         r0, 0x4330
  /* 805150A0 88A40001 */ lbz         r5, 1(r4)
  /* 805150A4 3CC08089 */ lis         r6, lbl_8088fa44@ha
  /* 805150A8 90A1000C */ stw         r5, 0xc(r1)
  /* 805150AC 3CA08089 */ lis         r5, lbl_8088fa48@ha
  /* 805150B0 38E0FFFF */ li          r7, -0x1
  /* 805150B4 C825FA48 */ lfd         f1, lbl_8088fa48@l(r5)
  /* 805150B8 90010008 */ stw         r0, 8(r1)
  /* 805150BC C046FA44 */ lfs         f2, lbl_8088fa44@l(r6)
  /* 805150C0 C8010008 */ lfd         f0, 8(r1)
  /* 805150C4 90830000 */ stw         r4, 0(r3)
  /* 805150C8 EC000828 */ fsubs       f0, f0, f1
  /* 805150CC 98E30004 */ stb         r7, 4(r3)
  /* 805150D0 EC020024 */ fdivs       f0, f2, f0
  /* 805150D4 D0030008 */ stfs        f0, 8(r3)
  /* 805150D8 38210010 */ addi        r1, r1, 0x10
  /* 805150DC 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_805150e0
// PAL: 0x805150e0..0x80515244
MARK_BINARY_BLOB(unk_805150e0, 0x805150e0, 0x80515244);
asm UNKNOWN_FUNCTION(unk_805150e0){
  // clang-format off
  nofralloc
  /* 805150E0 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 805150E4 7C0802A6 */ mflr        r0
  /* 805150E8 90010034 */ stw         r0, 0x34(r1)
  /* 805150EC BEC10008 */ stmw        r22, 8(r1)
  /* 805150F0 7C781B78 */ mr          r24, r3
  /* 805150F4 7CB92B78 */ mr          r25, r5
  /* 805150F8 88030004 */ lbz         r0, 4(r3)
  /* 805150FC 7C000774 */ extsb       r0, r0
  /* 80515100 2C00FFFF */ cmpwi       r0, -0x1
  /* 80515104 4082012C */ bne-        lbl_80515230
  /* 80515108 7C850774 */ extsb       r5, r4
  /* 8051510C 98830004 */ stb         r4, 4(r3)
  /* 80515110 3BA50001 */ addi        r29, r5, 0x1
  /* 80515114 3B400000 */ li          r26, 0x0
  /* 80515118 7FA30774 */ extsb       r3, r29
  /* 8051511C 3B830001 */ addi        r28, r3, 0x1
  /* 80515120 7F830774 */ extsb       r3, r28
  /* 80515124 3B630001 */ addi        r27, r3, 0x1
  lbl_80515128:
  /* 80515128 80780000 */ lwz         r3, 0(r24)
  /* 8051512C 5740043E */ clrlwi      r0, r26, 0x10
  /* 80515130 7C630214 */ add         r3, r3, r0
  /* 80515134 88830008 */ lbz         r4, 8(r3)
  /* 80515138 280400FF */ cmplwi      r4, 0xff
  /* 8051513C 418200E8 */ beq-        lbl_80515224
  /* 80515140 A0190004 */ lhz         r0, 4(r25)
  /* 80515144 7C040040 */ cmplw       r4, r0
  /* 80515148 40800014 */ bge-        lbl_8051515c
  /* 8051514C 80790000 */ lwz         r3, 0(r25)
  /* 80515150 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80515154 7FE3002E */ lwzx        r31, r3, r0
  /* 80515158 48000008 */ b           lbl_80515160
  lbl_8051515c:
  /* 8051515C 3BE00000 */ li          r31, 0x0
  lbl_80515160:
  /* 80515160 881F0004 */ lbz         r0, 4(r31)
  /* 80515164 7C000774 */ extsb       r0, r0
  /* 80515168 2C00FFFF */ cmpwi       r0, -0x1
  /* 8051516C 408200B8 */ bne-        lbl_80515224
  /* 80515170 9BBF0004 */ stb         r29, 4(r31)
  /* 80515174 3BC00000 */ li          r30, 0x0
  lbl_80515178:
  /* 80515178 807F0000 */ lwz         r3, 0(r31)
  /* 8051517C 57C0043E */ clrlwi      r0, r30, 0x10
  /* 80515180 7C630214 */ add         r3, r3, r0
  /* 80515184 88830008 */ lbz         r4, 8(r3)
  /* 80515188 280400FF */ cmplwi      r4, 0xff
  /* 8051518C 4182008C */ beq-        lbl_80515218
  /* 80515190 A0190004 */ lhz         r0, 4(r25)
  /* 80515194 7C040040 */ cmplw       r4, r0
  /* 80515198 40800014 */ bge-        lbl_805151ac
  /* 8051519C 80790000 */ lwz         r3, 0(r25)
  /* 805151A0 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 805151A4 7EE3002E */ lwzx        r23, r3, r0
  /* 805151A8 48000008 */ b           lbl_805151b0
  lbl_805151ac:
  /* 805151AC 3AE00000 */ li          r23, 0x0
  lbl_805151b0:
  /* 805151B0 88170004 */ lbz         r0, 4(r23)
  /* 805151B4 7C000774 */ extsb       r0, r0
  /* 805151B8 2C00FFFF */ cmpwi       r0, -0x1
  /* 805151BC 4082005C */ bne-        lbl_80515218
  /* 805151C0 9B970004 */ stb         r28, 4(r23)
  /* 805151C4 3AC00000 */ li          r22, 0x0
  lbl_805151c8:
  /* 805151C8 80770000 */ lwz         r3, 0(r23)
  /* 805151CC 56C0043E */ clrlwi      r0, r22, 0x10
  /* 805151D0 7C630214 */ add         r3, r3, r0
  /* 805151D4 88830008 */ lbz         r4, 8(r3)
  /* 805151D8 280400FF */ cmplwi      r4, 0xff
  /* 805151DC 41820030 */ beq-        lbl_8051520c
  /* 805151E0 A0190004 */ lhz         r0, 4(r25)
  /* 805151E4 7C040040 */ cmplw       r4, r0
  /* 805151E8 40800014 */ bge-        lbl_805151fc
  /* 805151EC 80790000 */ lwz         r3, 0(r25)
  /* 805151F0 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 805151F4 7C63002E */ lwzx        r3, r3, r0
  /* 805151F8 48000008 */ b           lbl_80515200
  lbl_805151fc:
  /* 805151FC 38600000 */ li          r3, 0x0
  lbl_80515200:
  /* 80515200 7F25CB78 */ mr          r5, r25
  /* 80515204 7F640774 */ extsb       r4, r27
  /* 80515208 4BFFFED9 */ bl          unk_805150e0
  lbl_8051520c:
  /* 8051520C 3AD60001 */ addi        r22, r22, 0x1
  /* 80515210 28160006 */ cmplwi      r22, 6
  /* 80515214 4180FFB4 */ blt+        lbl_805151c8
  lbl_80515218:
  /* 80515218 3BDE0001 */ addi        r30, r30, 0x1
  /* 8051521C 281E0006 */ cmplwi      r30, 6
  /* 80515220 4180FF58 */ blt+        lbl_80515178
  lbl_80515224:
  /* 80515224 3B5A0001 */ addi        r26, r26, 0x1
  /* 80515228 281A0006 */ cmplwi      r26, 6
  /* 8051522C 4180FEFC */ blt+        lbl_80515128
  lbl_80515230:
  /* 80515230 BAC10008 */ lmw         r22, 8(r1)
  /* 80515234 80010034 */ lwz         r0, 0x34(r1)
  /* 80515238 7C0803A6 */ mtlr        r0
  /* 8051523C 38210030 */ addi        r1, r1, 0x30
  /* 80515240 4E800020 */ blr
  // clang-format on
}

// Symbol: CheckpointHolder_init
// PAL: 0x80515244..0x805154e4
MARK_BINARY_BLOB(CheckpointHolder_init, 0x80515244, 0x805154e4);
asm UNKNOWN_FUNCTION(CheckpointHolder_init) {
  // clang-format off
  nofralloc
  /* 80515244 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 80515248 7C0802A6 */ mflr        r0
  /* 8051524C 90010034 */ stw         r0, 0x34(r1)
  /* 80515250 BEC10008 */ stmw        r22, 8(r1)
  /* 80515254 7C791B78 */ mr          r25, r3
  /* 80515258 A0030004 */ lhz         r0, 4(r3)
  /* 8051525C 2C000000 */ cmpwi       r0, 0x0
  /* 80515260 41820270 */ beq-        lbl_805154d0
  /* 80515264 3B40FFFF */ li          r26, -0x1
  /* 80515268 3B60FFFF */ li          r27, -0x1
  /* 8051526C 3B800000 */ li          r28, 0x0
  /* 80515270 4800007C */ b           lbl_805152ec
  lbl_80515274:
  /* 80515274 5780043E */ clrlwi      r0, r28, 0x10
  /* 80515278 7C001840 */ cmplw       r0, r3
  /* 8051527C 40800014 */ bge-        lbl_80515290
  /* 80515280 80790000 */ lwz         r3, 0(r25)
  /* 80515284 578013BA */ rlwinm      r0, r28, 2, 0xe, 0x1d
  /* 80515288 7C63002E */ lwzx        r3, r3, r0
  /* 8051528C 48000008 */ b           lbl_80515294
  lbl_80515290:
  /* 80515290 38600000 */ li          r3, 0x0
  lbl_80515294:
  /* 80515294 7F24CB78 */ mr          r4, r25
  /* 80515298 5785043E */ clrlwi      r5, r28, 0x10
  /* 8051529C 48000389 */ bl          unk_80515624
  /* 805152A0 A0190004 */ lhz         r0, 4(r25)
  /* 805152A4 5783043E */ clrlwi      r3, r28, 0x10
  /* 805152A8 7C030040 */ cmplw       r3, r0
  /* 805152AC 40800014 */ bge-        lbl_805152c0
  /* 805152B0 80790000 */ lwz         r3, 0(r25)
  /* 805152B4 578013BA */ rlwinm      r0, r28, 2, 0xe, 0x1d
  /* 805152B8 7C63002E */ lwzx        r3, r3, r0
  /* 805152BC 48000008 */ b           lbl_805152c4
  lbl_805152c0:
  /* 805152C0 38600000 */ li          r3, 0x0
  lbl_805152c4:
  /* 805152C4 80630000 */ lwz         r3, 0(r3)
  /* 805152C8 88030011 */ lbz         r0, 0x11(r3)
  /* 805152CC 7C030775 */ extsb.      r3, r0
  /* 805152D0 40820008 */ bne-        lbl_805152d8
  /* 805152D4 7F9B0734 */ extsh       r27, r28
  lbl_805152d8:
  /* 805152D8 7F400774 */ extsb       r0, r26
  /* 805152DC 7C030000 */ cmpw        r3, r0
  /* 805152E0 40810008 */ ble-        lbl_805152e8
  /* 805152E4 7C7A1B78 */ mr          r26, r3
  lbl_805152e8:
  /* 805152E8 3B9C0001 */ addi        r28, r28, 0x1
  lbl_805152ec:
  /* 805152EC A0790004 */ lhz         r3, 4(r25)
  /* 805152F0 5780043E */ clrlwi      r0, r28, 0x10
  /* 805152F4 7C001840 */ cmplw       r0, r3
  /* 805152F8 4180FF7C */ blt+        lbl_80515274
  /* 805152FC 5760043E */ clrlwi      r0, r27, 0x10
  /* 80515300 9B59000C */ stb         r26, 0xc(r25)
  /* 80515304 7C001840 */ cmplw       r0, r3
  /* 80515308 B379000E */ sth         r27, 0xe(r25)
  /* 8051530C 40800014 */ bge-        lbl_80515320
  /* 80515310 80790000 */ lwz         r3, 0(r25)
  /* 80515314 540013BA */ rlwinm      r0, r0, 2, 0xe, 0x1d
  /* 80515318 7FE3002E */ lwzx        r31, r3, r0
  /* 8051531C 48000008 */ b           lbl_80515324
  lbl_80515320:
  /* 80515320 3BE00000 */ li          r31, 0x0
  lbl_80515324:
  /* 80515324 807F0000 */ lwz         r3, 0(r31)
  /* 80515328 88630011 */ lbz         r3, 0x11(r3)
  /* 8051532C 7C600774 */ extsb       r0, r3
  /* 80515330 2C00FFFF */ cmpwi       r0, -0x1
  /* 80515334 40820010 */ bne-        lbl_80515344
  /* 80515338 38000000 */ li          r0, 0x0
  /* 8051533C 981F001C */ stb         r0, 0x1c(r31)
  /* 80515340 48000008 */ b           lbl_80515348
  lbl_80515344:
  /* 80515344 987F001C */ stb         r3, 0x1c(r31)
  lbl_80515348:
  /* 80515348 A01F0018 */ lhz         r0, 0x18(r31)
  /* 8051534C 7FFBFB78 */ mr          r27, r31
  /* 80515350 3B800000 */ li          r28, 0x0
  /* 80515354 60000001 */ ori         r0, r0, 1
  /* 80515358 B01F0018 */ sth         r0, 0x18(r31)
  /* 8051535C 48000150 */ b           lbl_805154ac
  lbl_80515360:
  /* 80515360 7C1C2000 */ cmpw        r28, r4
  /* 80515364 4080000C */ bge-        lbl_80515370
  /* 80515368 807B0038 */ lwz         r3, 0x38(r27)
  /* 8051536C 48000008 */ b           lbl_80515374
  lbl_80515370:
  /* 80515370 38600000 */ li          r3, 0x0
  lbl_80515374:
  /* 80515374 A0030018 */ lhz         r0, 0x18(r3)
  /* 80515378 540007FF */ clrlwi.     r0, r0, 0x1f
  /* 8051537C 40820128 */ bne-        lbl_805154a4
  /* 80515380 7C1C2000 */ cmpw        r28, r4
  /* 80515384 4080000C */ bge-        lbl_80515390
  /* 80515388 83BB0038 */ lwz         r29, 0x38(r27)
  /* 8051538C 48000008 */ b           lbl_80515394
  lbl_80515390:
  /* 80515390 3BA00000 */ li          r29, 0x0
  lbl_80515394:
  /* 80515394 807D0000 */ lwz         r3, 0(r29)
  /* 80515398 889F001C */ lbz         r4, 0x1c(r31)
  /* 8051539C 88630011 */ lbz         r3, 0x11(r3)
  /* 805153A0 7C600774 */ extsb       r0, r3
  /* 805153A4 2C00FFFF */ cmpwi       r0, -0x1
  /* 805153A8 4082000C */ bne-        lbl_805153b4
  /* 805153AC 989D001C */ stb         r4, 0x1c(r29)
  /* 805153B0 48000008 */ b           lbl_805153b8
  lbl_805153b4:
  /* 805153B4 987D001C */ stb         r3, 0x1c(r29)
  lbl_805153b8:
  /* 805153B8 A01D0018 */ lhz         r0, 0x18(r29)
  /* 805153BC 7FBAEB78 */ mr          r26, r29
  /* 805153C0 3BC00000 */ li          r30, 0x0
  /* 805153C4 60000001 */ ori         r0, r0, 1
  /* 805153C8 B01D0018 */ sth         r0, 0x18(r29)
  /* 805153CC 480000CC */ b           lbl_80515498
  lbl_805153d0:
  /* 805153D0 7C1E2000 */ cmpw        r30, r4
  /* 805153D4 4080000C */ bge-        lbl_805153e0
  /* 805153D8 807A0038 */ lwz         r3, 0x38(r26)
  /* 805153DC 48000008 */ b           lbl_805153e4
  lbl_805153e0:
  /* 805153E0 38600000 */ li          r3, 0x0
  lbl_805153e4:
  /* 805153E4 A0030018 */ lhz         r0, 0x18(r3)
  /* 805153E8 540007FF */ clrlwi.     r0, r0, 0x1f
  /* 805153EC 408200A4 */ bne-        lbl_80515490
  /* 805153F0 7C1E2000 */ cmpw        r30, r4
  /* 805153F4 4080000C */ bge-        lbl_80515400
  /* 805153F8 82FA0038 */ lwz         r23, 0x38(r26)
  /* 805153FC 48000008 */ b           lbl_80515404
  lbl_80515400:
  /* 80515400 3AE00000 */ li          r23, 0x0
  lbl_80515404:
  /* 80515404 80770000 */ lwz         r3, 0(r23)
  /* 80515408 889D001C */ lbz         r4, 0x1c(r29)
  /* 8051540C 88630011 */ lbz         r3, 0x11(r3)
  /* 80515410 7C600774 */ extsb       r0, r3
  /* 80515414 2C00FFFF */ cmpwi       r0, -0x1
  /* 80515418 4082000C */ bne-        lbl_80515424
  /* 8051541C 9897001C */ stb         r4, 0x1c(r23)
  /* 80515420 48000008 */ b           lbl_80515428
  lbl_80515424:
  /* 80515424 9877001C */ stb         r3, 0x1c(r23)
  lbl_80515428:
  /* 80515428 A0170018 */ lhz         r0, 0x18(r23)
  /* 8051542C 7EF6BB78 */ mr          r22, r23
  /* 80515430 3B000000 */ li          r24, 0x0
  /* 80515434 60000001 */ ori         r0, r0, 1
  /* 80515438 B0170018 */ sth         r0, 0x18(r23)
  /* 8051543C 48000048 */ b           lbl_80515484
  lbl_80515440:
  /* 80515440 7C182000 */ cmpw        r24, r4
  /* 80515444 4080000C */ bge-        lbl_80515450
  /* 80515448 80760038 */ lwz         r3, 0x38(r22)
  /* 8051544C 48000008 */ b           lbl_80515454
  lbl_80515450:
  /* 80515450 38600000 */ li          r3, 0x0
  lbl_80515454:
  /* 80515454 A0030018 */ lhz         r0, 0x18(r3)
  /* 80515458 540007FF */ clrlwi.     r0, r0, 0x1f
  /* 8051545C 40820020 */ bne-        lbl_8051547c
  /* 80515460 7C182000 */ cmpw        r24, r4
  /* 80515464 4080000C */ bge-        lbl_80515470
  /* 80515468 80760038 */ lwz         r3, 0x38(r22)
  /* 8051546C 48000008 */ b           lbl_80515474
  lbl_80515470:
  /* 80515470 38600000 */ li          r3, 0x0
  lbl_80515474:
  /* 80515474 8897001C */ lbz         r4, 0x1c(r23)
  /* 80515478 480005F5 */ bl          unk_80515a6c
  lbl_8051547c:
  /* 8051547C 3AD60018 */ addi        r22, r22, 0x18
  /* 80515480 3B180001 */ addi        r24, r24, 0x1
  lbl_80515484:
  /* 80515484 A0970004 */ lhz         r4, 4(r23)
  /* 80515488 7C182000 */ cmpw        r24, r4
  /* 8051548C 4180FFB4 */ blt+        lbl_80515440
  lbl_80515490:
  /* 80515490 3B5A0018 */ addi        r26, r26, 0x18
  /* 80515494 3BDE0001 */ addi        r30, r30, 0x1
  lbl_80515498:
  /* 80515498 A09D0004 */ lhz         r4, 4(r29)
  /* 8051549C 7C1E2000 */ cmpw        r30, r4
  /* 805154A0 4180FF30 */ blt+        lbl_805153d0
  lbl_805154a4:
  /* 805154A4 3B7B0018 */ addi        r27, r27, 0x18
  /* 805154A8 3B9C0001 */ addi        r28, r28, 0x1
  lbl_805154ac:
  /* 805154AC A09F0004 */ lhz         r4, 4(r31)
  /* 805154B0 7C1C2000 */ cmpw        r28, r4
  /* 805154B4 4180FEAC */ blt+        lbl_80515360
  /* 805154B8 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 805154BC 8063D6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r3)
  /* 805154C0 4BFFC941 */ bl          unk_80511e00
  /* 805154C4 7F23CB78 */ mr          r3, r25
  /* 805154C8 4BFFCEA9 */ bl          CheckpointHolder_computeMeanTotalDistance
  /* 805154CC D0390010 */ stfs        f1, 0x10(r25)
  lbl_805154d0:
  /* 805154D0 BAC10008 */ lmw         r22, 8(r1)
  /* 805154D4 80010034 */ lwz         r0, 0x34(r1)
  /* 805154D8 7C0803A6 */ mtlr        r0
  /* 805154DC 38210030 */ addi        r1, r1, 0x30
  /* 805154E0 4E800020 */ blr
  // clang-format on
}

// Symbol: Checkpoint_parse
// PAL: 0x805154e4..0x805155e0
MARK_BINARY_BLOB(Checkpoint_parse, 0x805154e4, 0x805155e0);
asm UNKNOWN_FUNCTION(Checkpoint_parse) {
  // clang-format off
  nofralloc
  /* 805154E4 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805154E8 7C0802A6 */ mflr        r0
  /* 805154EC 3CA08051 */ lis         r5, unk_805155e4@ha
  /* 805154F0 38C00018 */ li          r6, 0x18
  /* 805154F4 90010014 */ stw         r0, 0x14(r1)
  /* 805154F8 38A555E4 */ addi        r5, r5, unk_805155e4@l
  /* 805154FC 38E00006 */ li          r7, 0x6
  /* 80515500 93E1000C */ stw         r31, 0xc(r1)
  /* 80515504 3BE00000 */ li          r31, 0x0
  /* 80515508 93C10008 */ stw         r30, 8(r1)
  /* 8051550C 7C7E1B78 */ mr          r30, r3
  /* 80515510 90830000 */ stw         r4, 0(r3)
  /* 80515514 3C808051 */ lis         r4, unk_805155e0@ha
  /* 80515518 388455E0 */ addi        r4, r4, unk_805155e0@l
  /* 8051551C B3E30004 */ sth         r31, 4(r3)
  /* 80515520 B3E30006 */ sth         r31, 6(r3)
  /* 80515524 B3E30018 */ sth         r31, 0x18(r3)
  /* 80515528 B3E3001A */ sth         r31, 0x1a(r3)
  /* 8051552C 38630038 */ addi        r3, r3, 0x38
  /* 80515530 4BB0BAC5 */ bl          __construct_array
  /* 80515534 93FE0020 */ stw         r31, 0x20(r30)
  /* 80515538 3C808089 */ lis         r4, lbl_8088fa70@ha
  /* 8051553C 80BE0000 */ lwz         r5, 0(r30)
  /* 80515540 387E0010 */ addi        r3, r30, 0x10
  /* 80515544 93FE0024 */ stw         r31, 0x24(r30)
  /* 80515548 C044FA70 */ lfs         f2, lbl_8088fa70@l(r4)
  /* 8051554C 93FE0028 */ stw         r31, 0x28(r30)
  /* 80515550 809E0000 */ lwz         r4, 0(r30)
  /* 80515554 93FE002C */ stw         r31, 0x2c(r30)
  /* 80515558 93FE0030 */ stw         r31, 0x30(r30)
  /* 8051555C 93FE0034 */ stw         r31, 0x34(r30)
  /* 80515560 93FE0038 */ stw         r31, 0x38(r30)
  /* 80515564 93FE0050 */ stw         r31, 0x50(r30)
  /* 80515568 93FE0068 */ stw         r31, 0x68(r30)
  /* 8051556C 93FE0080 */ stw         r31, 0x80(r30)
  /* 80515570 93FE0098 */ stw         r31, 0x98(r30)
  /* 80515574 93FE00B0 */ stw         r31, 0xb0(r30)
  /* 80515578 C0250000 */ lfs         f1, 0(r5)
  /* 8051557C C0050008 */ lfs         f0, 8(r5)
  /* 80515580 EC01002A */ fadds       f0, f1, f0
  /* 80515584 EC020032 */ fmuls       f0, f2, f0
  /* 80515588 D01E0008 */ stfs        f0, 8(r30)
  /* 8051558C C0250004 */ lfs         f1, 4(r5)
  /* 80515590 C005000C */ lfs         f0, 0xc(r5)
  /* 80515594 EC01002A */ fadds       f0, f1, f0
  /* 80515598 EC020032 */ fmuls       f0, f2, f0
  /* 8051559C D01E000C */ stfs        f0, 0xc(r30)
  /* 805155A0 C0040008 */ lfs         f0, 8(r4)
  /* 805155A4 C0240000 */ lfs         f1, 0(r4)
  /* 805155A8 C0440004 */ lfs         f2, 4(r4)
  /* 805155AC C064000C */ lfs         f3, 0xc(r4)
  /* 805155B0 EC210028 */ fsubs       f1, f1, f0
  /* 805155B4 EC031028 */ fsubs       f0, f3, f2
  /* 805155B8 D03E0014 */ stfs        f1, 0x14(r30)
  /* 805155BC D01E0010 */ stfs        f0, 0x10(r30)
  /* 805155C0 4BD2E441 */ bl          normalise__Q23EGG8Vector2fFv
  /* 805155C4 7FC3F378 */ mr          r3, r30
  /* 805155C8 83E1000C */ lwz         r31, 0xc(r1)
  /* 805155CC 83C10008 */ lwz         r30, 8(r1)
  /* 805155D0 80010014 */ lwz         r0, 0x14(r1)
  /* 805155D4 7C0803A6 */ mtlr        r0
  /* 805155D8 38210010 */ addi        r1, r1, 0x10
  /* 805155DC 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_805155e0
// PAL: 0x805155e0..0x805155e4
MARK_BINARY_BLOB(unk_805155e0, 0x805155e0, 0x805155e4);
asm UNKNOWN_FUNCTION(unk_805155e0){
    // clang-format off
  nofralloc
  /* 805155E0 4E800020 */ blr
    // clang-format on
}

// Symbol: unk_805155e4
// PAL: 0x805155e4..0x80515624
MARK_BINARY_BLOB(unk_805155e4, 0x805155e4, 0x80515624);
asm UNKNOWN_FUNCTION(unk_805155e4){
  // clang-format off
  nofralloc
  /* 805155E4 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805155E8 7C0802A6 */ mflr        r0
  /* 805155EC 2C030000 */ cmpwi       r3, 0x0
  /* 805155F0 90010014 */ stw         r0, 0x14(r1)
  /* 805155F4 93E1000C */ stw         r31, 0xc(r1)
  /* 805155F8 7C7F1B78 */ mr          r31, r3
  /* 805155FC 41820010 */ beq-        lbl_8051560c
  /* 80515600 2C040000 */ cmpwi       r4, 0x0
  /* 80515604 40810008 */ ble-        lbl_8051560c
  /* 80515608 4BD1480D */ bl          __dl__FPv
  lbl_8051560c:
  /* 8051560C 7FE3FB78 */ mr          r3, r31
  /* 80515610 83E1000C */ lwz         r31, 0xc(r1)
  /* 80515614 80010014 */ lwz         r0, 0x14(r1)
  /* 80515618 7C0803A6 */ mtlr        r0
  /* 8051561C 38210010 */ addi        r1, r1, 0x10
  /* 80515620 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80515624
// PAL: 0x80515624..0x80515a6c
MARK_BINARY_BLOB(unk_80515624, 0x80515624, 0x80515a6c);
asm UNKNOWN_FUNCTION(unk_80515624) {
  // clang-format off
  nofralloc
  /* 80515624 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 80515628 7C0802A6 */ mflr        r0
  /* 8051562C 90010034 */ stw         r0, 0x34(r1)
  /* 80515630 DBE10020 */ stfd        f31, 0x20(r1)
  /* 80515634 F3E10028 */ opword      0xf3e10028
  /* 80515638 93E1001C */ stw         r31, 0x1c(r1)
  /* 8051563C 7C7F1B78 */ mr          r31, r3
  /* 80515640 93C10018 */ stw         r30, 0x18(r1)
  /* 80515644 93A10014 */ stw         r29, 0x14(r1)
  /* 80515648 93810010 */ stw         r28, 0x10(r1)
  /* 8051564C B0A3001A */ sth         r5, 0x1a(r3)
  /* 80515650 80C30000 */ lwz         r6, 0(r3)
  /* 80515654 88E60012 */ lbz         r7, 0x12(r6)
  /* 80515658 280700FF */ cmplwi      r7, 0xff
  /* 8051565C 40820170 */ bne-        lbl_805157cc
  /* 80515660 3CC0809C */ lis         r6, spInstance__Q26System9CourseMap@ha
  /* 80515664 39000000 */ li          r8, 0x0
  /* 80515668 80C6D6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r6)
  /* 8051566C 8126001C */ lwz         r9, 0x1c(r6)
  /* 80515670 A1690004 */ lhz         r11, 4(r9)
  /* 80515674 48000064 */ b           lbl_805156d8
  lbl_80515678:
  /* 80515678 5500043E */ clrlwi      r0, r8, 0x10
  /* 8051567C 7C005840 */ cmplw       r0, r11
  /* 80515680 40800014 */ bge-        lbl_80515694
  /* 80515684 80C90000 */ lwz         r6, 0(r9)
  /* 80515688 550013BA */ rlwinm      r0, r8, 2, 0xe, 0x1d
  /* 8051568C 7CC6002E */ lwzx        r6, r6, r0
  /* 80515690 48000008 */ b           lbl_80515698
  lbl_80515694:
  /* 80515694 38C00000 */ li          r6, 0x0
  lbl_80515698:
  /* 80515698 81860000 */ lwz         r12, 0(r6)
  /* 8051569C 39400000 */ li          r10, 0x0
  /* 805156A0 88EC0000 */ lbz         r7, 0(r12)
  /* 805156A4 7C072800 */ cmpw        r7, r5
  /* 805156A8 41810020 */ bgt-        lbl_805156c8
  /* 805156AC 880C0001 */ lbz         r0, 1(r12)
  /* 805156B0 7CE70214 */ add         r7, r7, r0
  /* 805156B4 3807FFFF */ addi        r0, r7, -0x1
  /* 805156B8 5400063E */ clrlwi      r0, r0, 0x18
  /* 805156BC 7C050000 */ cmpw        r5, r0
  /* 805156C0 41810008 */ bgt-        lbl_805156c8
  /* 805156C4 39400001 */ li          r10, 0x1
  lbl_805156c8:
  /* 805156C8 2C0A0000 */ cmpwi       r10, 0x0
  /* 805156CC 41820008 */ beq-        lbl_805156d4
  /* 805156D0 48000018 */ b           lbl_805156e8
  lbl_805156d4:
  /* 805156D4 39080001 */ addi        r8, r8, 0x1
  lbl_805156d8:
  /* 805156D8 5500043E */ clrlwi      r0, r8, 0x10
  /* 805156DC 7C005840 */ cmplw       r0, r11
  /* 805156E0 4180FF98 */ blt+        lbl_80515678
  /* 805156E4 38C00000 */ li          r6, 0x0
  lbl_805156e8:
  /* 805156E8 2C060000 */ cmpwi       r6, 0x0
  /* 805156EC 4182010C */ beq-        lbl_805157f8
  /* 805156F0 38000006 */ li          r0, 0x6
  /* 805156F4 38E00000 */ li          r7, 0x0
  /* 805156F8 B0E30006 */ sth         r7, 6(r3)
  /* 805156FC 38E00000 */ li          r7, 0x0
  /* 80515700 3D40809C */ lis         r10, spInstance__Q26System9CourseMap@ha
  /* 80515704 7C0903A6 */ mtctr       r0
  lbl_80515708:
  /* 80515708 80060000 */ lwz         r0, 0(r6)
  /* 8051570C 7D003A14 */ add         r8, r0, r7
  /* 80515710 89280002 */ lbz         r9, 2(r8)
  /* 80515714 280900FF */ cmplwi      r9, 0xff
  /* 80515718 418200A8 */ beq-        lbl_805157c0
  /* 8051571C 816AD6E8 */ lwz         r11, spInstance__Q26System9CourseMap@l(r10)
  /* 80515720 810B001C */ lwz         r8, 0x1c(r11)
  /* 80515724 2C080000 */ cmpwi       r8, 0x0
  /* 80515728 4182000C */ beq-        lbl_80515734
  /* 8051572C A0080004 */ lhz         r0, 4(r8)
  /* 80515730 48000008 */ b           lbl_80515738
  lbl_80515734:
  /* 80515734 38000000 */ li          r0, 0x0
  lbl_80515738:
  /* 80515738 7C090040 */ cmplw       r9, r0
  /* 8051573C 4080002C */ bge-        lbl_80515768
  /* 80515740 810B001C */ lwz         r8, 0x1c(r11)
  /* 80515744 A0080004 */ lhz         r0, 4(r8)
  /* 80515748 7C090040 */ cmplw       r9, r0
  /* 8051574C 40800014 */ bge-        lbl_80515760
  /* 80515750 81080000 */ lwz         r8, 0(r8)
  /* 80515754 552013BA */ rlwinm      r0, r9, 2, 0xe, 0x1d
  /* 80515758 7D08002E */ lwzx        r8, r8, r0
  /* 8051575C 48000010 */ b           lbl_8051576c
  lbl_80515760:
  /* 80515760 39000000 */ li          r8, 0x0
  /* 80515764 48000008 */ b           lbl_8051576c
  lbl_80515768:
  /* 80515768 39000000 */ li          r8, 0x0
  lbl_8051576c:
  /* 8051576C 81080000 */ lwz         r8, 0(r8)
  /* 80515770 A0040004 */ lhz         r0, 4(r4)
  /* 80515774 89280001 */ lbz         r9, 1(r8)
  /* 80515778 89080000 */ lbz         r8, 0(r8)
  /* 8051577C 7D084A14 */ add         r8, r8, r9
  /* 80515780 3908FFFF */ addi        r8, r8, -0x1
  /* 80515784 5509063E */ clrlwi      r9, r8, 0x18
  /* 80515788 7C090040 */ cmplw       r9, r0
  /* 8051578C 40800014 */ bge-        lbl_805157a0
  /* 80515790 81040000 */ lwz         r8, 0(r4)
  /* 80515794 552013BA */ rlwinm      r0, r9, 2, 0xe, 0x1d
  /* 80515798 7D28002E */ lwzx        r9, r8, r0
  /* 8051579C 48000008 */ b           lbl_805157a4
  lbl_805157a0:
  /* 805157A0 39200000 */ li          r9, 0x0
  lbl_805157a4:
  /* 805157A4 A0030006 */ lhz         r0, 6(r3)
  /* 805157A8 5400103A */ slwi        r0, r0, 2
  /* 805157AC 7D030214 */ add         r8, r3, r0
  /* 805157B0 91280020 */ stw         r9, 0x20(r8)
  /* 805157B4 A1030006 */ lhz         r8, 6(r3)
  /* 805157B8 38080001 */ addi        r0, r8, 0x1
  /* 805157BC B0030006 */ sth         r0, 6(r3)
  lbl_805157c0:
  /* 805157C0 38E70001 */ addi        r7, r7, 0x1
  /* 805157C4 4200FF44 */ bdnz        lbl_80515708
  /* 805157C8 48000030 */ b           lbl_805157f8
  lbl_805157cc:
  /* 805157CC A0040004 */ lhz         r0, 4(r4)
  /* 805157D0 7C070040 */ cmplw       r7, r0
  /* 805157D4 40800014 */ bge-        lbl_805157e8
  /* 805157D8 80C40000 */ lwz         r6, 0(r4)
  /* 805157DC 54E013BA */ rlwinm      r0, r7, 2, 0xe, 0x1d
  /* 805157E0 7CC6002E */ lwzx        r6, r6, r0
  /* 805157E4 48000008 */ b           lbl_805157ec
  lbl_805157e8:
  /* 805157E8 38C00000 */ li          r6, 0x0
  lbl_805157ec:
  /* 805157EC 38000001 */ li          r0, 0x1
  /* 805157F0 90C30020 */ stw         r6, 0x20(r3)
  /* 805157F4 B0030006 */ sth         r0, 6(r3)
  lbl_805157f8:
  /* 805157F8 80C30000 */ lwz         r6, 0(r3)
  /* 805157FC 88C60013 */ lbz         r6, 0x13(r6)
  /* 80515800 280600FF */ cmplwi      r6, 0xff
  /* 80515804 40820160 */ bne-        lbl_80515964
  /* 80515808 3CC0809C */ lis         r6, spInstance__Q26System9CourseMap@ha
  /* 8051580C 39000000 */ li          r8, 0x0
  /* 80515810 80C6D6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r6)
  /* 80515814 8126001C */ lwz         r9, 0x1c(r6)
  /* 80515818 A1690004 */ lhz         r11, 4(r9)
  /* 8051581C 48000064 */ b           lbl_80515880
  lbl_80515820:
  /* 80515820 5500043E */ clrlwi      r0, r8, 0x10
  /* 80515824 7C005840 */ cmplw       r0, r11
  /* 80515828 40800014 */ bge-        lbl_8051583c
  /* 8051582C 80C90000 */ lwz         r6, 0(r9)
  /* 80515830 550013BA */ rlwinm      r0, r8, 2, 0xe, 0x1d
  /* 80515834 7CC6002E */ lwzx        r6, r6, r0
  /* 80515838 48000008 */ b           lbl_80515840
  lbl_8051583c:
  /* 8051583C 38C00000 */ li          r6, 0x0
  lbl_80515840:
  /* 80515840 81860000 */ lwz         r12, 0(r6)
  /* 80515844 39400000 */ li          r10, 0x0
  /* 80515848 88EC0000 */ lbz         r7, 0(r12)
  /* 8051584C 7C072800 */ cmpw        r7, r5
  /* 80515850 41810020 */ bgt-        lbl_80515870
  /* 80515854 880C0001 */ lbz         r0, 1(r12)
  /* 80515858 7CE70214 */ add         r7, r7, r0
  /* 8051585C 3807FFFF */ addi        r0, r7, -0x1
  /* 80515860 5400063E */ clrlwi      r0, r0, 0x18
  /* 80515864 7C050000 */ cmpw        r5, r0
  /* 80515868 41810008 */ bgt-        lbl_80515870
  /* 8051586C 39400001 */ li          r10, 0x1
  lbl_80515870:
  /* 80515870 2C0A0000 */ cmpwi       r10, 0x0
  /* 80515874 41820008 */ beq-        lbl_8051587c
  /* 80515878 48000018 */ b           lbl_80515890
  lbl_8051587c:
  /* 8051587C 39080001 */ addi        r8, r8, 0x1
  lbl_80515880:
  /* 80515880 5500043E */ clrlwi      r0, r8, 0x10
  /* 80515884 7C005840 */ cmplw       r0, r11
  /* 80515888 4180FF98 */ blt+        lbl_80515820
  /* 8051588C 38C00000 */ li          r6, 0x0
  lbl_80515890:
  /* 80515890 2C060000 */ cmpwi       r6, 0x0
  /* 80515894 418200FC */ beq-        lbl_80515990
  /* 80515898 38000006 */ li          r0, 0x6
  /* 8051589C 38A00000 */ li          r5, 0x0
  /* 805158A0 B0A30004 */ sth         r5, 4(r3)
  /* 805158A4 38A00000 */ li          r5, 0x0
  /* 805158A8 3D20809C */ lis         r9, spInstance__Q26System9CourseMap@ha
  /* 805158AC 7C0903A6 */ mtctr       r0
  lbl_805158b0:
  /* 805158B0 80060000 */ lwz         r0, 0(r6)
  /* 805158B4 7CE02A14 */ add         r7, r0, r5
  /* 805158B8 89070008 */ lbz         r8, 8(r7)
  /* 805158BC 280800FF */ cmplwi      r8, 0xff
  /* 805158C0 41820098 */ beq-        lbl_80515958
  /* 805158C4 8149D6E8 */ lwz         r10, spInstance__Q26System9CourseMap@l(r9)
  /* 805158C8 80EA001C */ lwz         r7, 0x1c(r10)
  /* 805158CC 2C070000 */ cmpwi       r7, 0x0
  /* 805158D0 4182000C */ beq-        lbl_805158dc
  /* 805158D4 A0070004 */ lhz         r0, 4(r7)
  /* 805158D8 48000008 */ b           lbl_805158e0
  lbl_805158dc:
  /* 805158DC 38000000 */ li          r0, 0x0
  lbl_805158e0:
  /* 805158E0 7C080040 */ cmplw       r8, r0
  /* 805158E4 4080002C */ bge-        lbl_80515910
  /* 805158E8 80EA001C */ lwz         r7, 0x1c(r10)
  /* 805158EC A0070004 */ lhz         r0, 4(r7)
  /* 805158F0 7C080040 */ cmplw       r8, r0
  /* 805158F4 40800014 */ bge-        lbl_80515908
  /* 805158F8 80E70000 */ lwz         r7, 0(r7)
  /* 805158FC 550013BA */ rlwinm      r0, r8, 2, 0xe, 0x1d
  /* 80515900 7CE7002E */ lwzx        r7, r7, r0
  /* 80515904 48000010 */ b           lbl_80515914
  lbl_80515908:
  /* 80515908 38E00000 */ li          r7, 0x0
  /* 8051590C 48000008 */ b           lbl_80515914
  lbl_80515910:
  /* 80515910 38E00000 */ li          r7, 0x0
  lbl_80515914:
  /* 80515914 80E70000 */ lwz         r7, 0(r7)
  /* 80515918 A0040004 */ lhz         r0, 4(r4)
  /* 8051591C 89070000 */ lbz         r8, 0(r7)
  /* 80515920 7C080040 */ cmplw       r8, r0
  /* 80515924 40800014 */ bge-        lbl_80515938
  /* 80515928 80E40000 */ lwz         r7, 0(r4)
  /* 8051592C 550013BA */ rlwinm      r0, r8, 2, 0xe, 0x1d
  /* 80515930 7D07002E */ lwzx        r8, r7, r0
  /* 80515934 48000008 */ b           lbl_8051593c
  lbl_80515938:
  /* 80515938 39000000 */ li          r8, 0x0
  lbl_8051593c:
  /* 8051593C A0030004 */ lhz         r0, 4(r3)
  /* 80515940 1C000018 */ mulli       r0, r0, 0x18
  /* 80515944 7CE30214 */ add         r7, r3, r0
  /* 80515948 91070038 */ stw         r8, 0x38(r7)
  /* 8051594C A0E30004 */ lhz         r7, 4(r3)
  /* 80515950 38070001 */ addi        r0, r7, 0x1
  /* 80515954 B0030004 */ sth         r0, 4(r3)
  lbl_80515958:
  /* 80515958 38A50001 */ addi        r5, r5, 0x1
  /* 8051595C 4200FF54 */ bdnz        lbl_805158b0
  /* 80515960 48000030 */ b           lbl_80515990
  lbl_80515964:
  /* 80515964 A0040004 */ lhz         r0, 4(r4)
  /* 80515968 7C060040 */ cmplw       r6, r0
  /* 8051596C 40800014 */ bge-        lbl_80515980
  /* 80515970 80840000 */ lwz         r4, 0(r4)
  /* 80515974 54C013BA */ rlwinm      r0, r6, 2, 0xe, 0x1d
  /* 80515978 7C84002E */ lwzx        r4, r4, r0
  /* 8051597C 48000008 */ b           lbl_80515984
  lbl_80515980:
  /* 80515980 38800000 */ li          r4, 0x0
  lbl_80515984:
  /* 80515984 38000001 */ li          r0, 0x1
  /* 80515988 90830038 */ stw         r4, 0x38(r3)
  /* 8051598C B0030004 */ sth         r0, 4(r3)
  lbl_80515990:
  /* 80515990 3C608089 */ lis         r3, ZERO_FLOAT2__6System@ha
  /* 80515994 7FFEFB78 */ mr          r30, r31
  /* 80515998 C3E3FA3C */ lfs         f31, ZERO_FLOAT2__6System@l(r3)
  /* 8051599C 3BA00000 */ li          r29, 0x0
  lbl_805159a0:
  /* 805159A0 A01F0004 */ lhz         r0, 4(r31)
  /* 805159A4 7C1D0000 */ cmpw        r29, r0
  /* 805159A8 40800078 */ bge-        lbl_80515a20
  /* 805159AC 839E0038 */ lwz         r28, 0x38(r30)
  /* 805159B0 38610008 */ addi        r3, r1, 0x8
  /* 805159B4 38BF0008 */ addi        r5, r31, 0x8
  /* 805159B8 389C0008 */ addi        r4, r28, 0x8
  /* 805159BC 4BFFC661 */ bl          VEC2_sub
  /* 805159C0 38610008 */ addi        r3, r1, 0x8
  /* 805159C4 4BD2E03D */ bl          normalise__Q23EGG8Vector2fFv
  /* 805159C8 D03E004C */ stfs        f1, 0x4c(r30)
  /* 805159CC 807F0000 */ lwz         r3, 0(r31)
  /* 805159D0 809C0000 */ lwz         r4, 0(r28)
  /* 805159D4 C0030000 */ lfs         f0, 0(r3)
  /* 805159D8 C0640000 */ lfs         f3, 0(r4)
  /* 805159DC C0230004 */ lfs         f1, 4(r3)
  /* 805159E0 C0440004 */ lfs         f2, 4(r4)
  /* 805159E4 EC030028 */ fsubs       f0, f3, f0
  /* 805159E8 D01E003C */ stfs        f0, 0x3c(r30)
  /* 805159EC EC020828 */ fsubs       f0, f2, f1
  /* 805159F0 D01E0040 */ stfs        f0, 0x40(r30)
  /* 805159F4 807F0000 */ lwz         r3, 0(r31)
  /* 805159F8 809C0000 */ lwz         r4, 0(r28)
  /* 805159FC C0030008 */ lfs         f0, 8(r3)
  /* 80515A00 C0640008 */ lfs         f3, 8(r4)
  /* 80515A04 C023000C */ lfs         f1, 0xc(r3)
  /* 80515A08 C044000C */ lfs         f2, 0xc(r4)
  /* 80515A0C EC030028 */ fsubs       f0, f3, f0
  /* 80515A10 D01E0044 */ stfs        f0, 0x44(r30)
  /* 80515A14 EC020828 */ fsubs       f0, f2, f1
  /* 80515A18 D01E0048 */ stfs        f0, 0x48(r30)
  /* 80515A1C 48000018 */ b           lbl_80515a34
  lbl_80515a20:
  /* 80515A20 D3FE004C */ stfs        f31, 0x4c(r30)
  /* 80515A24 D3FE0040 */ stfs        f31, 0x40(r30)
  /* 80515A28 D3FE003C */ stfs        f31, 0x3c(r30)
  /* 80515A2C D3FE0048 */ stfs        f31, 0x48(r30)
  /* 80515A30 D3FE0044 */ stfs        f31, 0x44(r30)
  lbl_80515a34:
  /* 80515A34 3BBD0001 */ addi        r29, r29, 0x1
  /* 80515A38 3BDE0018 */ addi        r30, r30, 0x18
  /* 80515A3C 2C1D0006 */ cmpwi       r29, 0x6
  /* 80515A40 4180FF60 */ blt+        lbl_805159a0
  /* 80515A44 E3E10028 */ opword      0xe3e10028
  /* 80515A48 80010034 */ lwz         r0, 0x34(r1)
  /* 80515A4C CBE10020 */ lfd         f31, 0x20(r1)
  /* 80515A50 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80515A54 83C10018 */ lwz         r30, 0x18(r1)
  /* 80515A58 83A10014 */ lwz         r29, 0x14(r1)
  /* 80515A5C 83810010 */ lwz         r28, 0x10(r1)
  /* 80515A60 7C0803A6 */ mtlr        r0
  /* 80515A64 38210030 */ addi        r1, r1, 0x30
  /* 80515A68 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80515a6c
// PAL: 0x80515a6c..0x80515c24
MARK_BINARY_BLOB(unk_80515a6c, 0x80515a6c, 0x80515c24);
asm UNKNOWN_FUNCTION(unk_80515a6c) {
  // clang-format off
  nofralloc
  /* 80515A6C 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 80515A70 7C0802A6 */ mflr        r0
  /* 80515A74 90010034 */ stw         r0, 0x34(r1)
  /* 80515A78 BEE1000C */ stmw        r23, 0xc(r1)
  /* 80515A7C 7C7A1B78 */ mr          r26, r3
  /* 80515A80 80A30000 */ lwz         r5, 0(r3)
  /* 80515A84 88A50011 */ lbz         r5, 0x11(r5)
  /* 80515A88 7CA00774 */ extsb       r0, r5
  /* 80515A8C 2C00FFFF */ cmpwi       r0, -0x1
  /* 80515A90 4082000C */ bne-        lbl_80515a9c
  /* 80515A94 9883001C */ stb         r4, 0x1c(r3)
  /* 80515A98 48000008 */ b           lbl_80515aa0
  lbl_80515a9c:
  /* 80515A9C 98A3001C */ stb         r5, 0x1c(r3)
  lbl_80515aa0:
  /* 80515AA0 A0030018 */ lhz         r0, 0x18(r3)
  /* 80515AA4 7F5DD378 */ mr          r29, r26
  /* 80515AA8 3B600000 */ li          r27, 0x0
  /* 80515AAC 60000001 */ ori         r0, r0, 1
  /* 80515AB0 B0030018 */ sth         r0, 0x18(r3)
  /* 80515AB4 48000150 */ b           lbl_80515c04
  lbl_80515ab8:
  /* 80515AB8 7C1B2000 */ cmpw        r27, r4
  /* 80515ABC 4080000C */ bge-        lbl_80515ac8
  /* 80515AC0 807D0038 */ lwz         r3, 0x38(r29)
  /* 80515AC4 48000008 */ b           lbl_80515acc
  lbl_80515ac8:
  /* 80515AC8 38600000 */ li          r3, 0x0
  lbl_80515acc:
  /* 80515ACC A0030018 */ lhz         r0, 0x18(r3)
  /* 80515AD0 540007FF */ clrlwi.     r0, r0, 0x1f
  /* 80515AD4 40820128 */ bne-        lbl_80515bfc
  /* 80515AD8 7C1B2000 */ cmpw        r27, r4
  /* 80515ADC 4080000C */ bge-        lbl_80515ae8
  /* 80515AE0 83FD0038 */ lwz         r31, 0x38(r29)
  /* 80515AE4 48000008 */ b           lbl_80515aec
  lbl_80515ae8:
  /* 80515AE8 3BE00000 */ li          r31, 0x0
  lbl_80515aec:
  /* 80515AEC 807F0000 */ lwz         r3, 0(r31)
  /* 80515AF0 889A001C */ lbz         r4, 0x1c(r26)
  /* 80515AF4 88630011 */ lbz         r3, 0x11(r3)
  /* 80515AF8 7C600774 */ extsb       r0, r3
  /* 80515AFC 2C00FFFF */ cmpwi       r0, -0x1
  /* 80515B00 4082000C */ bne-        lbl_80515b0c
  /* 80515B04 989F001C */ stb         r4, 0x1c(r31)
  /* 80515B08 48000008 */ b           lbl_80515b10
  lbl_80515b0c:
  /* 80515B0C 987F001C */ stb         r3, 0x1c(r31)
  lbl_80515b10:
  /* 80515B10 A01F0018 */ lhz         r0, 0x18(r31)
  /* 80515B14 7FFCFB78 */ mr          r28, r31
  /* 80515B18 3BC00000 */ li          r30, 0x0
  /* 80515B1C 60000001 */ ori         r0, r0, 1
  /* 80515B20 B01F0018 */ sth         r0, 0x18(r31)
  /* 80515B24 480000CC */ b           lbl_80515bf0
  lbl_80515b28:
  /* 80515B28 7C1E2000 */ cmpw        r30, r4
  /* 80515B2C 4080000C */ bge-        lbl_80515b38
  /* 80515B30 807C0038 */ lwz         r3, 0x38(r28)
  /* 80515B34 48000008 */ b           lbl_80515b3c
  lbl_80515b38:
  /* 80515B38 38600000 */ li          r3, 0x0
  lbl_80515b3c:
  /* 80515B3C A0030018 */ lhz         r0, 0x18(r3)
  /* 80515B40 540007FF */ clrlwi.     r0, r0, 0x1f
  /* 80515B44 408200A4 */ bne-        lbl_80515be8
  /* 80515B48 7C1E2000 */ cmpw        r30, r4
  /* 80515B4C 4080000C */ bge-        lbl_80515b58
  /* 80515B50 833C0038 */ lwz         r25, 0x38(r28)
  /* 80515B54 48000008 */ b           lbl_80515b5c
  lbl_80515b58:
  /* 80515B58 3B200000 */ li          r25, 0x0
  lbl_80515b5c:
  /* 80515B5C 80790000 */ lwz         r3, 0(r25)
  /* 80515B60 889F001C */ lbz         r4, 0x1c(r31)
  /* 80515B64 88630011 */ lbz         r3, 0x11(r3)
  /* 80515B68 7C600774 */ extsb       r0, r3
  /* 80515B6C 2C00FFFF */ cmpwi       r0, -0x1
  /* 80515B70 4082000C */ bne-        lbl_80515b7c
  /* 80515B74 9899001C */ stb         r4, 0x1c(r25)
  /* 80515B78 48000008 */ b           lbl_80515b80
  lbl_80515b7c:
  /* 80515B7C 9879001C */ stb         r3, 0x1c(r25)
  lbl_80515b80:
  /* 80515B80 A0190018 */ lhz         r0, 0x18(r25)
  /* 80515B84 7F37CB78 */ mr          r23, r25
  /* 80515B88 3B000000 */ li          r24, 0x0
  /* 80515B8C 60000001 */ ori         r0, r0, 1
  /* 80515B90 B0190018 */ sth         r0, 0x18(r25)
  /* 80515B94 48000048 */ b           lbl_80515bdc
  lbl_80515b98:
  /* 80515B98 7C182000 */ cmpw        r24, r4
  /* 80515B9C 4080000C */ bge-        lbl_80515ba8
  /* 80515BA0 80770038 */ lwz         r3, 0x38(r23)
  /* 80515BA4 48000008 */ b           lbl_80515bac
  lbl_80515ba8:
  /* 80515BA8 38600000 */ li          r3, 0x0
  lbl_80515bac:
  /* 80515BAC A0030018 */ lhz         r0, 0x18(r3)
  /* 80515BB0 540007FF */ clrlwi.     r0, r0, 0x1f
  /* 80515BB4 40820020 */ bne-        lbl_80515bd4
  /* 80515BB8 7C182000 */ cmpw        r24, r4
  /* 80515BBC 4080000C */ bge-        lbl_80515bc8
  /* 80515BC0 80770038 */ lwz         r3, 0x38(r23)
  /* 80515BC4 48000008 */ b           lbl_80515bcc
  lbl_80515bc8:
  /* 80515BC8 38600000 */ li          r3, 0x0
  lbl_80515bcc:
  /* 80515BCC 8899001C */ lbz         r4, 0x1c(r25)
  /* 80515BD0 4BFFFE9D */ bl          unk_80515a6c
  lbl_80515bd4:
  /* 80515BD4 3AF70018 */ addi        r23, r23, 0x18
  /* 80515BD8 3B180001 */ addi        r24, r24, 0x1
  lbl_80515bdc:
  /* 80515BDC A0990004 */ lhz         r4, 4(r25)
  /* 80515BE0 7C182000 */ cmpw        r24, r4
  /* 80515BE4 4180FFB4 */ blt+        lbl_80515b98
  lbl_80515be8:
  /* 80515BE8 3B9C0018 */ addi        r28, r28, 0x18
  /* 80515BEC 3BDE0001 */ addi        r30, r30, 0x1
  lbl_80515bf0:
  /* 80515BF0 A09F0004 */ lhz         r4, 4(r31)
  /* 80515BF4 7C1E2000 */ cmpw        r30, r4
  /* 80515BF8 4180FF30 */ blt+        lbl_80515b28
  lbl_80515bfc:
  /* 80515BFC 3BBD0018 */ addi        r29, r29, 0x18
  /* 80515C00 3B7B0001 */ addi        r27, r27, 0x1
  lbl_80515c04:
  /* 80515C04 A09A0004 */ lhz         r4, 4(r26)
  /* 80515C08 7C1B2000 */ cmpw        r27, r4
  /* 80515C0C 4180FEAC */ blt+        lbl_80515ab8
  /* 80515C10 BAE1000C */ lmw         r23, 0xc(r1)
  /* 80515C14 80010034 */ lwz         r0, 0x34(r1)
  /* 80515C18 7C0803A6 */ mtlr        r0
  /* 80515C1C 38210030 */ addi        r1, r1, 0x30
  /* 80515C20 4E800020 */ blr
  // clang-format on
}

namespace System {

MapdataCheckPoint* CourseMap::getCheckPoint(u16 i) const {
  u16 count = mpCheckPoint ? mpCheckPoint->size() : 0;
  return i < count ? mpCheckPoint->get(i) : 0;
}

MapdataCheckPath* CourseMap::getCheckPath(u16 i) const {
  u16 count = mpCheckPath ? mpCheckPath->size() : 0;
  return i < count ? mpCheckPath->get(i) : 0;
}

} // namespace System

// Symbol: unk_80515cbc
// PAL: 0x80515cbc..0x80515d3c
MARK_BINARY_BLOB(unk_80515cbc, 0x80515cbc, 0x80515d3c);
asm UNKNOWN_FUNCTION(unk_80515cbc){
  // clang-format off
  nofralloc
  /* 80515CBC 80C3001C */ lwz         r6, 0x1c(r3)
  /* 80515CC0 38E00000 */ li          r7, 0x0
  /* 80515CC4 A1260004 */ lhz         r9, 4(r6)
  /* 80515CC8 48000060 */ b           lbl_80515d28
  lbl_80515ccc:
  /* 80515CCC 54E0043E */ clrlwi      r0, r7, 0x10
  /* 80515CD0 7C004840 */ cmplw       r0, r9
  /* 80515CD4 40800014 */ bge-        lbl_80515ce8
  /* 80515CD8 80660000 */ lwz         r3, 0(r6)
  /* 80515CDC 54E013BA */ rlwinm      r0, r7, 2, 0xe, 0x1d
  /* 80515CE0 7C63002E */ lwzx        r3, r3, r0
  /* 80515CE4 48000008 */ b           lbl_80515cec
  lbl_80515ce8:
  /* 80515CE8 38600000 */ li          r3, 0x0
  lbl_80515cec:
  /* 80515CEC 81430000 */ lwz         r10, 0(r3)
  /* 80515CF0 39000000 */ li          r8, 0x0
  /* 80515CF4 88AA0000 */ lbz         r5, 0(r10)
  /* 80515CF8 7C052000 */ cmpw        r5, r4
  /* 80515CFC 41810020 */ bgt-        lbl_80515d1c
  /* 80515D00 880A0001 */ lbz         r0, 1(r10)
  /* 80515D04 7CA50214 */ add         r5, r5, r0
  /* 80515D08 3805FFFF */ addi        r0, r5, -0x1
  /* 80515D0C 5400063E */ clrlwi      r0, r0, 0x18
  /* 80515D10 7C040000 */ cmpw        r4, r0
  /* 80515D14 41810008 */ bgt-        lbl_80515d1c
  /* 80515D18 39000001 */ li          r8, 0x1
  lbl_80515d1c:
  /* 80515D1C 2C080000 */ cmpwi       r8, 0x0
  /* 80515D20 4C820020 */ bnelr-
  /* 80515D24 38E70001 */ addi        r7, r7, 0x1
  lbl_80515d28:
  /* 80515D28 54E0043E */ clrlwi      r0, r7, 0x10
  /* 80515D2C 7C004840 */ cmplw       r0, r9
  /* 80515D30 4180FF9C */ blt+        lbl_80515ccc
  /* 80515D34 38600000 */ li          r3, 0x0
  /* 80515D38 4E800020 */ blr
  // clang-format on
}

// Scheduling - https://decomp.me/scratch/hDqoW
#ifdef NON_MATCHING
MapdataPointInfoAccessor::MapdataPointInfoAccessor(
    const KmpSectionHeader* header)
    : MapdataAccessorBase<MapdataPointInfo, MapdataPointInfo::SData>(header) {
  init(sectionHeader->entryCount);
}
#else
// Symbol: unk_80515d3c
// PAL: 0x80515d3c..0x80515e04
MARK_BINARY_BLOB(unk_80515d3c, 0x80515d3c, 0x80515e04);
asm UNKNOWN_FUNCTION(unk_80515d3c) {
  // clang-format off
  nofralloc
  /* 80515D3C 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80515D40 7C0802A6 */ mflr        r0
  /* 80515D44 90010024 */ stw         r0, 0x24(r1)
  /* 80515D48 38000000 */ li          r0, 0x0
  /* 80515D4C 93E1001C */ stw         r31, 0x1c(r1)
  /* 80515D50 93C10018 */ stw         r30, 0x18(r1)
  /* 80515D54 93A10014 */ stw         r29, 0x14(r1)
  /* 80515D58 7C7D1B78 */ mr          r29, r3
  /* 80515D5C 90030000 */ stw         r0, 0(r3)
  /* 80515D60 B0030004 */ sth         r0, 4(r3)
  /* 80515D64 90830008 */ stw         r4, 8(r3)
  /* 80515D68 A0040004 */ lhz         r0, 4(r4)
  /* 80515D6C 2C000000 */ cmpwi       r0, 0x0
  /* 80515D70 41820014 */ beq-        lbl_80515d84
  /* 80515D74 B0030004 */ sth         r0, 4(r3)
  /* 80515D78 540313BA */ rlwinm      r3, r0, 2, 0xe, 0x1d
  /* 80515D7C 4BD14075 */ bl          __nwa__FUl
  /* 80515D80 907D0000 */ stw         r3, 0(r29)
  lbl_80515d84:
  /* 80515D84 A01D0004 */ lhz         r0, 4(r29)
  /* 80515D88 2C000000 */ cmpwi       r0, 0x0
  /* 80515D8C 41820058 */ beq-        lbl_80515de4
  /* 80515D90 807D0008 */ lwz         r3, 8(r29)
  /* 80515D94 3BC00000 */ li          r30, 0x0
  /* 80515D98 3BE30008 */ addi        r31, r3, 0x8
  /* 80515D9C 48000038 */ b           lbl_80515dd4
  lbl_80515da0:
  /* 80515DA0 38600004 */ li          r3, 0x4
  /* 80515DA4 4BD14029 */ bl          __nw__FUl
  /* 80515DA8 2C030000 */ cmpwi       r3, 0x0
  /* 80515DAC 41820008 */ beq-        lbl_80515db4
  /* 80515DB0 93E30000 */ stw         r31, 0(r3)
  lbl_80515db4:
  /* 80515DB4 809D0000 */ lwz         r4, 0(r29)
  /* 80515DB8 57C013BA */ rlwinm      r0, r30, 2, 0xe, 0x1d
  /* 80515DBC 3BDE0001 */ addi        r30, r30, 0x1
  /* 80515DC0 7C64012E */ stwx        r3, r4, r0
  /* 80515DC4 A01F0000 */ lhz         r0, 0(r31)
  /* 80515DC8 54002036 */ slwi        r0, r0, 4
  /* 80515DCC 7C7F0214 */ add         r3, r31, r0
  /* 80515DD0 3BE30004 */ addi        r31, r3, 0x4
  lbl_80515dd4:
  /* 80515DD4 A01D0004 */ lhz         r0, 4(r29)
  /* 80515DD8 57C3043E */ clrlwi      r3, r30, 0x10
  /* 80515DDC 7C030040 */ cmplw       r3, r0
  /* 80515DE0 4180FFC0 */ blt+        lbl_80515da0
  lbl_80515de4:
  /* 80515DE4 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80515DE8 7FA3EB78 */ mr          r3, r29
  /* 80515DEC 83C10018 */ lwz         r30, 0x18(r1)
  /* 80515DF0 83A10014 */ lwz         r29, 0x14(r1)
  /* 80515DF4 80010024 */ lwz         r0, 0x24(r1)
  /* 80515DF8 7C0803A6 */ mtlr        r0
  /* 80515DFC 38210020 */ addi        r1, r1, 0x20
  /* 80515E00 4E800020 */ blr
  // clang-format on
}
#endif

namespace System {

MapdataPointInfo* CourseMap::getPointInfo(u16 i) const {
  u16 count = mpPointInfo ? mpPointInfo->size() : 0;
  return i < count ? mpPointInfo->get(i) : 0;
}

} // namespace System

// Symbol: __ct__Q26System19MapdataAreaAccessorFPCQ26System16KmpSectionHeader
// PAL: 0x80515e50..0x80515f8c
MARK_BINARY_BLOB(
    __ct__Q26System19MapdataAreaAccessorFPCQ26System16KmpSectionHeader,
    0x80515e50, 0x80515f8c);
asm UNKNOWN_FUNCTION(
    __ct__Q26System19MapdataAreaAccessorFPCQ26System16KmpSectionHeader) {
  // clang-format off
  nofralloc
  /* 80515E50 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80515E54 7C0802A6 */ mflr        r0
  /* 80515E58 3CA0808B */ lis         r5, __vt__Q26System19MapdataAreaAccessor@ha
  /* 80515E5C 90010024 */ stw         r0, 0x24(r1)
  /* 80515E60 38000000 */ li          r0, 0x0
  /* 80515E64 38A52C3C */ addi        r5, r5, __vt__Q26System19MapdataAreaAccessor@l
  /* 80515E68 BF61000C */ stmw        r27, 0xc(r1)
  /* 80515E6C 7C7C1B78 */ mr          r28, r3
  /* 80515E70 90030000 */ stw         r0, 0(r3)
  /* 80515E74 B0030004 */ sth         r0, 4(r3)
  /* 80515E78 90A30008 */ stw         r5, 8(r3)
  /* 80515E7C 90030010 */ stw         r0, 0x10(r3)
  /* 80515E80 9083000C */ stw         r4, 0xc(r3)
  /* 80515E84 A3C40004 */ lhz         r30, 4(r4)
  /* 80515E88 2C1E0000 */ cmpwi       r30, 0x0
  /* 80515E8C 41820014 */ beq-        lbl_80515ea0
  /* 80515E90 B3C30004 */ sth         r30, 4(r3)
  /* 80515E94 57C313BA */ rlwinm      r3, r30, 2, 0xe, 0x1d
  /* 80515E98 4BD13F59 */ bl          __nwa__FUl
  /* 80515E9C 907C0000 */ stw         r3, 0(r28)
  lbl_80515ea0:
  /* 80515EA0 3BA00000 */ li          r29, 0x0
  /* 80515EA4 3FE0809C */ lis         r31, spInstance__Q26System9CourseMap@ha
  /* 80515EA8 480000B4 */ b           lbl_80515f5c
  lbl_80515eac:
  /* 80515EAC 807FD6E8 */ lwz         r3, spInstance__Q26System9CourseMap@l(r31)
  /* 80515EB0 80630004 */ lwz         r3, 4(r3)
  /* 80515EB4 80030008 */ lwz         r0, 8(r3)
  /* 80515EB8 28000898 */ cmplwi      r0, 0x898
  /* 80515EBC 4180001C */ blt-        lbl_80515ed8
  /* 80515EC0 57A0043E */ clrlwi      r0, r29, 0x10
  /* 80515EC4 807C000C */ lwz         r3, 0xc(r28)
  /* 80515EC8 1C000030 */ mulli       r0, r0, 0x30
  /* 80515ECC 7C630214 */ add         r3, r3, r0
  /* 80515ED0 3B630008 */ addi        r27, r3, 0x8
  /* 80515ED4 48000020 */ b           lbl_80515ef4
  lbl_80515ed8:
  /* 80515ED8 57A0043E */ clrlwi      r0, r29, 0x10
  /* 80515EDC 809C000C */ lwz         r4, 0xc(r28)
  /* 80515EE0 1C600030 */ mulli       r3, r0, 0x30
  /* 80515EE4 57A013BA */ rlwinm      r0, r29, 2, 0xe, 0x1d
  /* 80515EE8 7C641A14 */ add         r3, r4, r3
  /* 80515EEC 38630008 */ addi        r3, r3, 0x8
  /* 80515EF0 7F601850 */ subf        r27, r0, r3
  lbl_80515ef4:
  /* 80515EF4 881B0000 */ lbz         r0, 0(r27)
  /* 80515EF8 2C000000 */ cmpwi       r0, 0x0
  /* 80515EFC 41820010 */ beq-        lbl_80515f0c
  /* 80515F00 2C000001 */ cmpwi       r0, 0x1
  /* 80515F04 41820030 */ beq-        lbl_80515f34
  /* 80515F08 48000050 */ b           lbl_80515f58
  lbl_80515f0c:
  /* 80515F0C 38600048 */ li          r3, 0x48
  /* 80515F10 4BD13EBD */ bl          __nw__FUl
  /* 80515F14 2C030000 */ cmpwi       r3, 0x0
  /* 80515F18 4182000C */ beq-        lbl_80515f24
  /* 80515F1C 7F64DB78 */ mr          r4, r27
  /* 80515F20 48000301 */ bl          AreaBox_construct
  lbl_80515f24:
  /* 80515F24 809C0000 */ lwz         r4, 0(r28)
  /* 80515F28 57A013BA */ rlwinm      r0, r29, 2, 0xe, 0x1d
  /* 80515F2C 7C64012E */ stwx        r3, r4, r0
  /* 80515F30 48000028 */ b           lbl_80515f58
  lbl_80515f34:
  /* 80515F34 38600048 */ li          r3, 0x48
  /* 80515F38 4BD13E95 */ bl          __nw__FUl
  /* 80515F3C 2C030000 */ cmpwi       r3, 0x0
  /* 80515F40 4182000C */ beq-        lbl_80515f4c
  /* 80515F44 7F64DB78 */ mr          r4, r27
  /* 80515F48 480005B5 */ bl          AreaCylinder_construct
  lbl_80515f4c:
  /* 80515F4C 809C0000 */ lwz         r4, 0(r28)
  /* 80515F50 57A013BA */ rlwinm      r0, r29, 2, 0xe, 0x1d
  /* 80515F54 7C64012E */ stwx        r3, r4, r0
  lbl_80515f58:
  /* 80515F58 3BBD0001 */ addi        r29, r29, 0x1
  lbl_80515f5c:
  /* 80515F5C 57A0043E */ clrlwi      r0, r29, 0x10
  /* 80515F60 7C00F040 */ cmplw       r0, r30
  /* 80515F64 4180FF48 */ blt+        lbl_80515eac
  /* 80515F68 57C313BA */ rlwinm      r3, r30, 2, 0xe, 0x1d
  /* 80515F6C 4BD13E85 */ bl          __nwa__FUl
  /* 80515F70 907C0010 */ stw         r3, 0x10(r28)
  /* 80515F74 7F83E378 */ mr          r3, r28
  /* 80515F78 BB61000C */ lmw         r27, 0xc(r1)
  /* 80515F7C 80010024 */ lwz         r0, 0x24(r1)
  /* 80515F80 7C0803A6 */ mtlr        r0
  /* 80515F84 38210020 */ addi        r1, r1, 0x20
  /* 80515F88 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80515f8c
// PAL: 0x80515f8c..0x80516050
MARK_BINARY_BLOB(unk_80515f8c, 0x80515f8c, 0x80516050);
asm UNKNOWN_FUNCTION(unk_80515f8c) {
  // clang-format off
  nofralloc
  /* 80515F8C 38C00000 */ li          r6, 0x0
  /* 80515F90 48000034 */ b           lbl_80515fc4
  lbl_80515f94:
  /* 80515F94 54C0043E */ clrlwi      r0, r6, 0x10
  /* 80515F98 7C002040 */ cmplw       r0, r4
  /* 80515F9C 40800014 */ bge-        lbl_80515fb0
  /* 80515FA0 80830000 */ lwz         r4, 0(r3)
  /* 80515FA4 54C013BA */ rlwinm      r0, r6, 2, 0xe, 0x1d
  /* 80515FA8 7CA4002E */ lwzx        r5, r4, r0
  /* 80515FAC 48000008 */ b           lbl_80515fb4
  lbl_80515fb0:
  /* 80515FB0 38A00000 */ li          r5, 0x0
  lbl_80515fb4:
  /* 80515FB4 80830010 */ lwz         r4, 0x10(r3)
  /* 80515FB8 54C013BA */ rlwinm      r0, r6, 2, 0xe, 0x1d
  /* 80515FBC 38C60001 */ addi        r6, r6, 0x1
  /* 80515FC0 7CA4012E */ stwx        r5, r4, r0
  lbl_80515fc4:
  /* 80515FC4 A0830004 */ lhz         r4, 4(r3)
  /* 80515FC8 54C0043E */ clrlwi      r0, r6, 0x10
  /* 80515FCC 7C002040 */ cmplw       r0, r4
  /* 80515FD0 4180FFC4 */ blt+        lbl_80515f94
  /* 80515FD4 39200001 */ li          r9, 0x1
  /* 80515FD8 38A00004 */ li          r5, 0x4
  /* 80515FDC 48000064 */ b           lbl_80516040
  lbl_80515fe0:
  /* 80515FE0 80830010 */ lwz         r4, 0x10(r3)
  /* 80515FE4 7D2A4B78 */ mr          r10, r9
  /* 80515FE8 5526103A */ slwi        r6, r9, 2
  /* 80515FEC 7D64282E */ lwzx        r11, r4, r5
  /* 80515FF0 48000010 */ b           lbl_80516000
  lbl_80515ff4:
  /* 80515FF4 90E80000 */ stw         r7, 0(r8)
  /* 80515FF8 38C6FFFC */ addi        r6, r6, -0x4
  /* 80515FFC 394AFFFF */ addi        r10, r10, -0x1
  lbl_80516000:
  /* 80516000 2C0A0000 */ cmpwi       r10, 0x0
  /* 80516004 40810028 */ ble-        lbl_8051602c
  /* 80516008 80030010 */ lwz         r0, 0x10(r3)
  /* 8051600C 808B0004 */ lwz         r4, 4(r11)
  /* 80516010 7D003214 */ add         r8, r0, r6
  /* 80516014 80E8FFFC */ lwz         r7, -4(r8)
  /* 80516018 88040003 */ lbz         r0, 3(r4)
  /* 8051601C 80870004 */ lwz         r4, 4(r7)
  /* 80516020 88840003 */ lbz         r4, 3(r4)
  /* 80516024 7C040040 */ cmplw       r4, r0
  /* 80516028 4180FFCC */ blt+        lbl_80515ff4
  lbl_8051602c:
  /* 8051602C 80830010 */ lwz         r4, 0x10(r3)
  /* 80516030 5540103A */ slwi        r0, r10, 2
  /* 80516034 38A50004 */ addi        r5, r5, 0x4
  /* 80516038 39290001 */ addi        r9, r9, 0x1
  /* 8051603C 7D64012E */ stwx        r11, r4, r0
  lbl_80516040:
  /* 80516040 A0030004 */ lhz         r0, 4(r3)
  /* 80516044 7C090000 */ cmpw        r9, r0
  /* 80516048 4180FF98 */ blt+        lbl_80515fe0
  /* 8051604C 4E800020 */ blr
  // clang-format on
}

namespace System {

MapdataAreaBase::MapdataAreaBase(const SData* data) : mIndex(-1) {
  mpData = data;
  mBoundingSphereRadiusSq = 0.0f;
  mEllipseAspectRatio = 0.0f;
  mEllipseXRadiusSq = 0.0f;
  mDims.z = 0.0f;
  mDims.y = 0.0f;
  mDims.x = 0.0f;
  mXAxis.z = 0.0f;
  mXAxis.y = 0.0f;
  mXAxis.x = 0.0f;
  mYAxis.z = 0.0f;
  mYAxis.y = 0.0f;
  mYAxis.x = 0.0f;
  mZAxis.z = 0.0f;
  mZAxis.y = 0.0f;
  mZAxis.x = 0.0f;
}

} // namespace System

// Regswap - https://decomp.me/scratch/1tQoj
#ifdef NON_MATCHING
namespace System {

bool MapdataAreaBase::isInside(const EGG::Vector3f& pos) const {
  f32 x = mpData->position.x - pos.x;
  f32 y = mpData->position.y - pos.y;
  f32 z = mpData->position.z - pos.z;

  EGG::Vector3f pos_(x, y, z);
  return pos_.dot() > mBoundingSphereRadiusSq ? false : isInsideShape(pos);
}

} // namespace System
#else
// Symbol: isInside__Q26System15MapdataAreaBaseCFRCQ23EGG8Vector3f
// PAL: 0x805160b0..0x80516138
MARK_BINARY_BLOB(isInside__Q26System15MapdataAreaBaseCFRCQ23EGG8Vector3f,
                 0x805160b0, 0x80516138);
asm UNKNOWN_FUNCTION(isInside__Q26System15MapdataAreaBaseCFRCQ23EGG8Vector3f) {
  // clang-format off
  nofralloc
  /* 805160B0 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805160B4 7C0802A6 */ mflr        r0
  /* 805160B8 90010024 */ stw         r0, 0x24(r1)
  /* 805160BC 80A30004 */ lwz         r5, 4(r3)
  /* 805160C0 C0240000 */ lfs         f1, 0(r4)
  /* 805160C4 C0650004 */ lfs         f3, 4(r5)
  /* 805160C8 C0850008 */ lfs         f4, 8(r5)
  /* 805160CC EC430828 */ fsubs       f2, f3, f1
  /* 805160D0 C0040004 */ lfs         f0, 4(r4)
  /* 805160D4 C0A5000C */ lfs         f5, 0xc(r5)
  /* 805160D8 ECE40028 */ fsubs       f7, f4, f0
  /* 805160DC C0240008 */ lfs         f1, 8(r4)
  /* 805160E0 EC4200B2 */ fmuls       f2, f2, f2
  /* 805160E4 ECC50828 */ fsubs       f6, f5, f1
  /* 805160E8 D0610008 */ stfs        f3, 8(r1)
  /* 805160EC EC2701F2 */ fmuls       f1, f7, f7
  /* 805160F0 C0030040 */ lfs         f0, 0x40(r3)
  /* 805160F4 EC6601B2 */ fmuls       f3, f6, f6
  /* 805160F8 D081000C */ stfs        f4, 0xc(r1)
  /* 805160FC EC22082A */ fadds       f1, f2, f1
  /* 80516100 D0A10010 */ stfs        f5, 0x10(r1)
  /* 80516104 EC23082A */ fadds       f1, f3, f1
  /* 80516108 FC010040 */ opword      0xfc010040
  /* 8051610C 4081000C */ ble-        lbl_80516118
  /* 80516110 38600000 */ li          r3, 0x0
  /* 80516114 48000014 */ b           lbl_80516128
  lbl_80516118:
  /* 80516118 81830000 */ lwz         r12, 0(r3)
  /* 8051611C 818C0008 */ lwz         r12, 8(r12)
  /* 80516120 7D8903A6 */ mtctr       r12
  /* 80516124 4E800421 */ bctrl
  lbl_80516128:
  /* 80516128 80010024 */ lwz         r0, 0x24(r1)
  /* 8051612C 7C0803A6 */ mtlr        r0
  /* 80516130 38210020 */ addi        r1, r1, 0x20
  /* 80516134 4E800020 */ blr
  // clang-format on
}
#endif

namespace System {

s32 MapdataAreaBase::getRouteId() const {
  // Of course it uses r0
  return CourseMap::instance()->getVersion() >= 2200 ? (s8)mpData->railID : -1;
}

} // namespace System

// Function is too optimized - https://decomp.me/scratch/aErgS
#ifdef NON_MATCHING
namespace System {

MapdataPointInfo* MapdataAreaBase::getPointInfo() const {
  return getRouteId() == -1 ? nullptr
                            : CourseMap::instance()->getPointInfo(getRouteId());
}

} // namespace System
#else
// Symbol: unk_80516168
// PAL: 0x80516168..0x80516220
MARK_BINARY_BLOB(unk_80516168, 0x80516168, 0x80516220);
asm UNKNOWN_FUNCTION(unk_80516168) {
  // clang-format off
  nofralloc
  /* 80516168 3C80809C */ lis         r4, spInstance__Q26System9CourseMap@ha
  /* 8051616C 8084D6E8 */ lwz         r4, spInstance__Q26System9CourseMap@l(r4)
  /* 80516170 80840004 */ lwz         r4, 4(r4)
  /* 80516174 80A40008 */ lwz         r5, 8(r4)
  /* 80516178 28050898 */ cmplwi      r5, 0x898
  /* 8051617C 41800014 */ blt-        lbl_80516190
  /* 80516180 80830004 */ lwz         r4, 4(r3)
  /* 80516184 8804002C */ lbz         r0, 0x2c(r4)
  /* 80516188 7C000774 */ extsb       r0, r0
  /* 8051618C 48000008 */ b           lbl_80516194
  lbl_80516190:
  /* 80516190 3800FFFF */ li          r0, -0x1
  lbl_80516194:
  /* 80516194 2C00FFFF */ cmpwi       r0, -0x1
  /* 80516198 4082000C */ bne-        lbl_805161a4
  /* 8051619C 38600000 */ li          r3, 0x0
  /* 805161A0 4E800020 */ blr
  lbl_805161a4:
  /* 805161A4 28050898 */ cmplwi      r5, 0x898
  /* 805161A8 41800014 */ blt-        lbl_805161bc
  /* 805161AC 80630004 */ lwz         r3, 4(r3)
  /* 805161B0 8803002C */ lbz         r0, 0x2c(r3)
  /* 805161B4 7C050774 */ extsb       r5, r0
  /* 805161B8 48000008 */ b           lbl_805161c0
  lbl_805161bc:
  /* 805161BC 38A0FFFF */ li          r5, -0x1
  lbl_805161c0:
  /* 805161C0 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 805161C4 54A4043E */ clrlwi      r4, r5, 0x10
  /* 805161C8 80C3D6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r3)
  /* 805161CC 80660024 */ lwz         r3, 0x24(r6)
  /* 805161D0 2C030000 */ cmpwi       r3, 0x0
  /* 805161D4 4182000C */ beq-        lbl_805161e0
  /* 805161D8 A0030004 */ lhz         r0, 4(r3)
  /* 805161DC 48000008 */ b           lbl_805161e4
  lbl_805161e0:
  /* 805161E0 38000000 */ li          r0, 0x0
  lbl_805161e4:
  /* 805161E4 7C040040 */ cmplw       r4, r0
  /* 805161E8 40800030 */ bge-        lbl_80516218
  /* 805161EC 80860024 */ lwz         r4, 0x24(r6)
  /* 805161F0 54A3043E */ clrlwi      r3, r5, 0x10
  /* 805161F4 A0040004 */ lhz         r0, 4(r4)
  /* 805161F8 7C030040 */ cmplw       r3, r0
  /* 805161FC 40800014 */ bge-        lbl_80516210
  /* 80516200 80640000 */ lwz         r3, 0(r4)
  /* 80516204 54A013BA */ rlwinm      r0, r5, 2, 0xe, 0x1d
  /* 80516208 7C63002E */ lwzx        r3, r3, r0
  /* 8051620C 4E800020 */ blr
  lbl_80516210:
  /* 80516210 38600000 */ li          r3, 0x0
  /* 80516214 4E800020 */ blr
  lbl_80516218:
  /* 80516218 38600000 */ li          r3, 0x0
  /* 8051621C 4E800020 */ blr
  // clang-format on
}
#endif

#if 0
namespace System {
MapdataAreaBox::MapdataAreaBox(const SData* data) : MapdataAreaBase(data) {
  mDims.x = 0.5f * 10000.0f * data->scale.x;
  mDims.y = 0.5f * 10000.0f * data->scale.y;
  mDims.z = 0.5f * 10000.0f * data->scale.z;

  mEllipseAspectRatio = 0.0f;
  mEllipseXRadiusSq = 0.0f;
  mBoundingSphereRadiusSq = data->scale.x * data->scale.x +
                            data->scale.y * data->scale.y +
                            data->scale.z * data->scale.z;

  EGG::Quatf areaRot;
  areaRot.setRPY(DEG2RAD(data->rotation.x), DEG2RAD(data->rotation.y),
                 DEG2RAD(data->rotation.z));

  EGG::Vector3f areaX, areaY, areaZ;
  VEC3_fromQuaternionRotated(areaX, areaRot, EGG::Vector3f::ex);
  mXAxis = areaX;
  VEC3_fromQuaternionRotated(areaY, areaRot, EGG::Vector3f::ey);
  mYAxis = areaY;
  VEC3_fromQuaternionRotated(areaZ, areaRot, EGG::Vector3f::ez);
  mZAxis = areaZ;
}
} // namespace System
#else
// Symbol: AreaBox_construct
// PAL: 0x80516220..0x805163b4
MARK_BINARY_BLOB(AreaBox_construct, 0x80516220, 0x805163b4);
asm UNKNOWN_FUNCTION(AreaBox_construct) {
  // clang-format off
  nofralloc
  /* 80516220 9421FFB0 */ stwu        r1, -0x50(r1)
  /* 80516224 7C0802A6 */ mflr        r0
  /* 80516228 3CE08089 */ lis         r7, lbl_8088f8e8@ha
  /* 8051622C 3CC0808B */ lis         r6, __vt__Q26System15MapdataAreaBase@ha
  /* 80516230 90010054 */ stw         r0, 0x54(r1)
  /* 80516234 38E7F8E8 */ addi        r7, r7, lbl_8088f8e8@l
  /* 80516238 3CA0808B */ lis         r5, __vt__Q26System14MapdataAreaBox@ha
  /* 8051623C 38C62C60 */ addi        r6, r6, __vt__Q26System15MapdataAreaBase@l
  /* 80516240 93E1004C */ stw         r31, 0x4c(r1)
  /* 80516244 3800FFFF */ li          r0, -0x1
  /* 80516248 C0C70154 */ lfs         f6, 0x154(r7)
  /* 8051624C 38A52C54 */ addi        r5, r5, __vt__Q26System14MapdataAreaBox@l
  /* 80516250 90C30000 */ stw         r6, 0(r3)
  /* 80516254 7C7F1B78 */ mr          r31, r3
  /* 80516258 C0A7018C */ lfs         f5, 0x18c(r7)
  /* 8051625C B0030044 */ sth         r0, 0x44(r3)
  /* 80516260 C0870188 */ lfs         f4, 0x188(r7)
  /* 80516264 90830004 */ stw         r4, 4(r3)
  /* 80516268 C0670170 */ lfs         f3, 0x170(r7)
  /* 8051626C D0C30040 */ stfs        f6, 0x40(r3)
  /* 80516270 D0C3003C */ stfs        f6, 0x3c(r3)
  /* 80516274 D0C30038 */ stfs        f6, 0x38(r3)
  /* 80516278 D0C30034 */ stfs        f6, 0x34(r3)
  /* 8051627C D0C30030 */ stfs        f6, 0x30(r3)
  /* 80516280 D0C3002C */ stfs        f6, 0x2c(r3)
  /* 80516284 D0C30010 */ stfs        f6, 0x10(r3)
  /* 80516288 D0C3000C */ stfs        f6, 0xc(r3)
  /* 8051628C D0C30008 */ stfs        f6, 8(r3)
  /* 80516290 D0C3001C */ stfs        f6, 0x1c(r3)
  /* 80516294 D0C30018 */ stfs        f6, 0x18(r3)
  /* 80516298 D0C30014 */ stfs        f6, 0x14(r3)
  /* 8051629C D0C30028 */ stfs        f6, 0x28(r3)
  /* 805162A0 D0C30024 */ stfs        f6, 0x24(r3)
  /* 805162A4 D0C30020 */ stfs        f6, 0x20(r3)
  /* 805162A8 90A30000 */ stw         r5, 0(r3)
  /* 805162AC C004001C */ lfs         f0, 0x1c(r4)
  /* 805162B0 EC050032 */ fmuls       f0, f5, f0
  /* 805162B4 EC040032 */ fmuls       f0, f4, f0
  /* 805162B8 D003002C */ stfs        f0, 0x2c(r3)
  /* 805162BC EC200032 */ fmuls       f1, f0, f0
  /* 805162C0 C0040020 */ lfs         f0, 0x20(r4)
  /* 805162C4 EC050032 */ fmuls       f0, f5, f0
  /* 805162C8 D0030030 */ stfs        f0, 0x30(r3)
  /* 805162CC EC400032 */ fmuls       f2, f0, f0
  /* 805162D0 C0040024 */ lfs         f0, 0x24(r4)
  /* 805162D4 EC050032 */ fmuls       f0, f5, f0
  /* 805162D8 D0C3003C */ stfs        f6, 0x3c(r3)
  /* 805162DC D0C30038 */ stfs        f6, 0x38(r3)
  /* 805162E0 EC040032 */ fmuls       f0, f4, f0
  /* 805162E4 D0030034 */ stfs        f0, 0x34(r3)
  /* 805162E8 EC000032 */ fmuls       f0, f0, f0
  /* 805162EC EC01002A */ fadds       f0, f1, f0
  /* 805162F0 EC02002A */ fadds       f0, f2, f0
  /* 805162F4 D0030040 */ stfs        f0, 0x40(r3)
  /* 805162F8 38610030 */ addi        r3, r1, 0x30
  /* 805162FC C0240010 */ lfs         f1, 0x10(r4)
  /* 80516300 C0440014 */ lfs         f2, 0x14(r4)
  /* 80516304 C0040018 */ lfs         f0, 0x18(r4)
  /* 80516308 EC230072 */ fmuls       f1, f3, f1
  /* 8051630C EC4300B2 */ fmuls       f2, f3, f2
  /* 80516310 EC630032 */ fmuls       f3, f3, f0
  /* 80516314 4BD23C45 */ bl          setRPY__Q23EGG5QuatfFfff
  /* 80516318 3CA0802A */ lis         r5, lbl_802a4118@ha
  /* 8051631C 38610020 */ addi        r3, r1, 0x20
  /* 80516320 38810030 */ addi        r4, r1, 0x30
  /* 80516324 38A54118 */ addi        r5, r5, lbl_802a4118@l
  /* 80516328 4BFFE4D5 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 8051632C C0010020 */ lfs         f0, 0x20(r1)
  /* 80516330 3CA0802A */ lis         r5, lbl_802a4130@ha
  /* 80516334 D01F0008 */ stfs        f0, 8(r31)
  /* 80516338 38610014 */ addi        r3, r1, 0x14
  /* 8051633C 38810030 */ addi        r4, r1, 0x30
  /* 80516340 38A54130 */ addi        r5, r5, lbl_802a4130@l
  /* 80516344 C0010024 */ lfs         f0, 0x24(r1)
  /* 80516348 D01F000C */ stfs        f0, 0xc(r31)
  /* 8051634C C0010028 */ lfs         f0, 0x28(r1)
  /* 80516350 D01F0010 */ stfs        f0, 0x10(r31)
  /* 80516354 4BFFE4A9 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80516358 C0010014 */ lfs         f0, 0x14(r1)
  /* 8051635C 3CA0802A */ lis         r5, lbl_802a4148@ha
  /* 80516360 D01F0014 */ stfs        f0, 0x14(r31)
  /* 80516364 38610008 */ addi        r3, r1, 0x8
  /* 80516368 38810030 */ addi        r4, r1, 0x30
  /* 8051636C 38A54148 */ addi        r5, r5, lbl_802a4148@l
  /* 80516370 C0010018 */ lfs         f0, 0x18(r1)
  /* 80516374 D01F0018 */ stfs        f0, 0x18(r31)
  /* 80516378 C001001C */ lfs         f0, 0x1c(r1)
  /* 8051637C D01F001C */ stfs        f0, 0x1c(r31)
  /* 80516380 4BFFE47D */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80516384 C0010008 */ lfs         f0, 8(r1)
  /* 80516388 7FE3FB78 */ mr          r3, r31
  /* 8051638C D01F0020 */ stfs        f0, 0x20(r31)
  /* 80516390 C001000C */ lfs         f0, 0xc(r1)
  /* 80516394 D01F0024 */ stfs        f0, 0x24(r31)
  /* 80516398 C0010010 */ lfs         f0, 0x10(r1)
  /* 8051639C D01F0028 */ stfs        f0, 0x28(r31)
  /* 805163A0 83E1004C */ lwz         r31, 0x4c(r1)
  /* 805163A4 80010054 */ lwz         r0, 0x54(r1)
  /* 805163A8 7C0803A6 */ mtlr        r0
  /* 805163AC 38210050 */ addi        r1, r1, 0x50
  /* 805163B0 4E800020 */ blr
  // clang-format on
}
#endif

// Symbol: unk_805163b4
// PAL: 0x805163b4..0x805163f4
MARK_BINARY_BLOB(unk_805163b4, 0x805163b4, 0x805163f4);
asm UNKNOWN_FUNCTION(unk_805163b4){
  // clang-format off
  nofralloc
  /* 805163B4 9421FFF0 */ stwu        r1, -0x10(r1)
  /* 805163B8 7C0802A6 */ mflr        r0
  /* 805163BC 2C030000 */ cmpwi       r3, 0x0
  /* 805163C0 90010014 */ stw         r0, 0x14(r1)
  /* 805163C4 93E1000C */ stw         r31, 0xc(r1)
  /* 805163C8 7C7F1B78 */ mr          r31, r3
  /* 805163CC 41820010 */ beq-        lbl_805163dc
  /* 805163D0 2C040000 */ cmpwi       r4, 0x0
  /* 805163D4 40810008 */ ble-        lbl_805163dc
  /* 805163D8 4BD13A3D */ bl          __dl__FPv
  lbl_805163dc:
  /* 805163DC 7FE3FB78 */ mr          r3, r31
  /* 805163E0 83E1000C */ lwz         r31, 0xc(r1)
  /* 805163E4 80010014 */ lwz         r0, 0x14(r1)
  /* 805163E8 7C0803A6 */ mtlr        r0
  /* 805163EC 38210010 */ addi        r1, r1, 0x10
  /* 805163F0 4E800020 */ blr
  // clang-format on
}

// Symbol: isInsideShape__Q26System14MapdataAreaBoxCFRCQ23EGG8Vector3f
// PAL: 0x805163f4..0x805164fc
MARK_BINARY_BLOB(isInsideShape__Q26System14MapdataAreaBoxCFRCQ23EGG8Vector3f, 0x805163f4, 0x805164fc);
asm bool System::MapdataAreaBox::isInsideShape(const EGG::Vector3f& pos) const {
  // clang-format off
  nofralloc
  /* 805163F4 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 805163F8 80A30004 */ lwz         r5, 4(r3)
  /* 805163FC C0640004 */ lfs         f3, 4(r4)
  /* 80516400 C0050008 */ lfs         f0, 8(r5)
  /* 80516404 C0440000 */ lfs         f2, 0(r4)
  /* 80516408 ECA30028 */ fsubs       f5, f3, f0
  /* 8051640C C0250004 */ lfs         f1, 4(r5)
  /* 80516410 C0030018 */ lfs         f0, 0x18(r3)
  /* 80516414 EC820828 */ fsubs       f4, f2, f1
  /* 80516418 C0430014 */ lfs         f2, 0x14(r3)
  /* 8051641C EC250032 */ fmuls       f1, f5, f0
  /* 80516420 C0640008 */ lfs         f3, 8(r4)
  /* 80516424 C005000C */ lfs         f0, 0xc(r5)
  /* 80516428 EC4400B2 */ fmuls       f2, f4, f2
  /* 8051642C D0810008 */ stfs        f4, 8(r1)
  /* 80516430 ECC30028 */ fsubs       f6, f3, f0
  /* 80516434 C063001C */ lfs         f3, 0x1c(r3)
  /* 80516438 EC22082A */ fadds       f1, f2, f1
  /* 8051643C C0030030 */ lfs         f0, 0x30(r3)
  /* 80516440 D0A1000C */ stfs        f5, 0xc(r1)
  /* 80516444 EC4600F2 */ fmuls       f2, f6, f3
  /* 80516448 D0C10010 */ stfs        f6, 0x10(r1)
  /* 8051644C EC22082A */ fadds       f1, f2, f1
  /* 80516450 FC010040 */ opword      0xfc010040
  /* 80516454 41810014 */ bgt-        lbl_80516468
  /* 80516458 3C808089 */ lis         r4, ZERO_FLOAT2__6System@ha
  /* 8051645C C004FA3C */ lfs         f0, ZERO_FLOAT2__6System@l(r4)
  /* 80516460 FC010040 */ opword      0xfc010040
  /* 80516464 4080000C */ bge-        lbl_80516470
  lbl_80516468:
  /* 80516468 38600000 */ li          r3, 0x0
  /* 8051646C 48000088 */ b           lbl_805164f4
  lbl_80516470:
  /* 80516470 C0230008 */ lfs         f1, 8(r3)
  /* 80516474 C003000C */ lfs         f0, 0xc(r3)
  /* 80516478 EC440072 */ fmuls       f2, f4, f1
  /* 8051647C C0630010 */ lfs         f3, 0x10(r3)
  /* 80516480 EC250032 */ fmuls       f1, f5, f0
  /* 80516484 C003002C */ lfs         f0, 0x2c(r3)
  /* 80516488 EC6600F2 */ fmuls       f3, f6, f3
  /* 8051648C EC22082A */ fadds       f1, f2, f1
  /* 80516490 EC23082A */ fadds       f1, f3, f1
  /* 80516494 FC010040 */ opword      0xfc010040
  /* 80516498 41810010 */ bgt-        lbl_805164a8
  /* 8051649C FC000050 */ fneg        f0, f0
  /* 805164A0 FC010040 */ opword      0xfc010040
  /* 805164A4 4080000C */ bge-        lbl_805164b0
  lbl_805164a8:
  /* 805164A8 38600000 */ li          r3, 0x0
  /* 805164AC 48000048 */ b           lbl_805164f4
  lbl_805164b0:
  /* 805164B0 C0230020 */ lfs         f1, 0x20(r3)
  /* 805164B4 C0030024 */ lfs         f0, 0x24(r3)
  /* 805164B8 EC440072 */ fmuls       f2, f4, f1
  /* 805164BC C0630028 */ lfs         f3, 0x28(r3)
  /* 805164C0 EC250032 */ fmuls       f1, f5, f0
  /* 805164C4 C0030034 */ lfs         f0, 0x34(r3)
  /* 805164C8 EC6600F2 */ fmuls       f3, f6, f3
  /* 805164CC EC22082A */ fadds       f1, f2, f1
  /* 805164D0 EC23082A */ fadds       f1, f3, f1
  /* 805164D4 FC010040 */ opword      0xfc010040
  /* 805164D8 41810010 */ bgt-        lbl_805164e8
  /* 805164DC FC000050 */ fneg        f0, f0
  /* 805164E0 FC010040 */ opword      0xfc010040
  /* 805164E4 4080000C */ bge-        lbl_805164f0
  lbl_805164e8:
  /* 805164E8 38600000 */ li          r3, 0x0
  /* 805164EC 48000008 */ b           lbl_805164f4
  lbl_805164f0:
  /* 805164F0 38600001 */ li          r3, 0x1
  lbl_805164f4:
  /* 805164F4 38210020 */ addi        r1, r1, 0x20
  /* 805164F8 4E800020 */ blr
  // clang-format on
}

// Symbol: AreaCylinder_construct
// PAL: 0x805164fc..0x80516688
MARK_BINARY_BLOB(AreaCylinder_construct, 0x805164fc, 0x80516688);
asm UNKNOWN_FUNCTION(AreaCylinder_construct) {
  // clang-format off
  nofralloc
  /* 805164FC 9421FFB0 */ stwu        r1, -0x50(r1)
  /* 80516500 7C0802A6 */ mflr        r0
  /* 80516504 3CE08089 */ lis         r7, lbl_8088f8e8@ha
  /* 80516508 3CC0808B */ lis         r6, __vt__Q26System15MapdataAreaBase@ha
  /* 8051650C 90010054 */ stw         r0, 0x54(r1)
  /* 80516510 38E7F8E8 */ addi        r7, r7, lbl_8088f8e8@l
  /* 80516514 3CA0808B */ lis         r5, __vt__Q26System19MapdataAreaCylinder@ha
  /* 80516518 38C62C60 */ addi        r6, r6, __vt__Q26System15MapdataAreaBase@l
  /* 8051651C 93E1004C */ stw         r31, 0x4c(r1)
  /* 80516520 3800FFFF */ li          r0, -0x1
  /* 80516524 C0070154 */ lfs         f0, 0x154(r7)
  /* 80516528 38A52C48 */ addi        r5, r5, __vt__Q26System19MapdataAreaCylinder@l
  /* 8051652C 90C30000 */ stw         r6, 0(r3)
  /* 80516530 7C7F1B78 */ mr          r31, r3
  /* 80516534 C0470190 */ lfs         f2, 0x190(r7)
  /* 80516538 B0030044 */ sth         r0, 0x44(r3)
  /* 8051653C C0670170 */ lfs         f3, 0x170(r7)
  /* 80516540 90830004 */ stw         r4, 4(r3)
  /* 80516544 D0030040 */ stfs        f0, 0x40(r3)
  /* 80516548 D003003C */ stfs        f0, 0x3c(r3)
  /* 8051654C D0030038 */ stfs        f0, 0x38(r3)
  /* 80516550 D0030034 */ stfs        f0, 0x34(r3)
  /* 80516554 D0030030 */ stfs        f0, 0x30(r3)
  /* 80516558 D003002C */ stfs        f0, 0x2c(r3)
  /* 8051655C D0030010 */ stfs        f0, 0x10(r3)
  /* 80516560 D003000C */ stfs        f0, 0xc(r3)
  /* 80516564 D0030008 */ stfs        f0, 8(r3)
  /* 80516568 D003001C */ stfs        f0, 0x1c(r3)
  /* 8051656C D0030018 */ stfs        f0, 0x18(r3)
  /* 80516570 D0030014 */ stfs        f0, 0x14(r3)
  /* 80516574 D0030028 */ stfs        f0, 0x28(r3)
  /* 80516578 D0030024 */ stfs        f0, 0x24(r3)
  /* 8051657C D0030020 */ stfs        f0, 0x20(r3)
  /* 80516580 90A30000 */ stw         r5, 0(r3)
  /* 80516584 C004001C */ lfs         f0, 0x1c(r4)
  /* 80516588 EC020032 */ fmuls       f0, f2, f0
  /* 8051658C D003002C */ stfs        f0, 0x2c(r3)
  /* 80516590 EC200032 */ fmuls       f1, f0, f0
  /* 80516594 C0040020 */ lfs         f0, 0x20(r4)
  /* 80516598 EC020032 */ fmuls       f0, f2, f0
  /* 8051659C D0030030 */ stfs        f0, 0x30(r3)
  /* 805165A0 C0040024 */ lfs         f0, 0x24(r4)
  /* 805165A4 EC020032 */ fmuls       f0, f2, f0
  /* 805165A8 D0230038 */ stfs        f1, 0x38(r3)
  /* 805165AC D0030034 */ stfs        f0, 0x34(r3)
  /* 805165B0 EC000032 */ fmuls       f0, f0, f0
  /* 805165B4 EC01002A */ fadds       f0, f1, f0
  /* 805165B8 D0030040 */ stfs        f0, 0x40(r3)
  /* 805165BC C024001C */ lfs         f1, 0x1c(r4)
  /* 805165C0 C0040024 */ lfs         f0, 0x24(r4)
  /* 805165C4 EC010024 */ fdivs       f0, f1, f0
  /* 805165C8 D003003C */ stfs        f0, 0x3c(r3)
  /* 805165CC 38610030 */ addi        r3, r1, 0x30
  /* 805165D0 C0240010 */ lfs         f1, 0x10(r4)
  /* 805165D4 C0440014 */ lfs         f2, 0x14(r4)
  /* 805165D8 C0040018 */ lfs         f0, 0x18(r4)
  /* 805165DC EC230072 */ fmuls       f1, f3, f1
  /* 805165E0 EC4300B2 */ fmuls       f2, f3, f2
  /* 805165E4 EC630032 */ fmuls       f3, f3, f0
  /* 805165E8 4BD23971 */ bl          setRPY__Q23EGG5QuatfFfff
  /* 805165EC 3CA0802A */ lis         r5, lbl_802a4118@ha
  /* 805165F0 38610020 */ addi        r3, r1, 0x20
  /* 805165F4 38810030 */ addi        r4, r1, 0x30
  /* 805165F8 38A54118 */ addi        r5, r5, lbl_802a4118@l
  /* 805165FC 4BFFE201 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80516600 C0010020 */ lfs         f0, 0x20(r1)
  /* 80516604 3CA0802A */ lis         r5, lbl_802a4130@ha
  /* 80516608 D01F0008 */ stfs        f0, 8(r31)
  /* 8051660C 38610014 */ addi        r3, r1, 0x14
  /* 80516610 38810030 */ addi        r4, r1, 0x30
  /* 80516614 38A54130 */ addi        r5, r5, lbl_802a4130@l
  /* 80516618 C0010024 */ lfs         f0, 0x24(r1)
  /* 8051661C D01F000C */ stfs        f0, 0xc(r31)
  /* 80516620 C0010028 */ lfs         f0, 0x28(r1)
  /* 80516624 D01F0010 */ stfs        f0, 0x10(r31)
  /* 80516628 4BFFE1D5 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 8051662C C0010014 */ lfs         f0, 0x14(r1)
  /* 80516630 3CA0802A */ lis         r5, lbl_802a4148@ha
  /* 80516634 D01F0014 */ stfs        f0, 0x14(r31)
  /* 80516638 38610008 */ addi        r3, r1, 0x8
  /* 8051663C 38810030 */ addi        r4, r1, 0x30
  /* 80516640 38A54148 */ addi        r5, r5, lbl_802a4148@l
  /* 80516644 C0010018 */ lfs         f0, 0x18(r1)
  /* 80516648 D01F0018 */ stfs        f0, 0x18(r31)
  /* 8051664C C001001C */ lfs         f0, 0x1c(r1)
  /* 80516650 D01F001C */ stfs        f0, 0x1c(r31)
  /* 80516654 4BFFE1A9 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80516658 C0010008 */ lfs         f0, 8(r1)
  /* 8051665C 7FE3FB78 */ mr          r3, r31
  /* 80516660 D01F0020 */ stfs        f0, 0x20(r31)
  /* 80516664 C001000C */ lfs         f0, 0xc(r1)
  /* 80516668 D01F0024 */ stfs        f0, 0x24(r31)
  /* 8051666C C0010010 */ lfs         f0, 0x10(r1)
  /* 80516670 D01F0028 */ stfs        f0, 0x28(r31)
  /* 80516674 83E1004C */ lwz         r31, 0x4c(r1)
  /* 80516678 80010054 */ lwz         r0, 0x54(r1)
  /* 8051667C 7C0803A6 */ mtlr        r0
  /* 80516680 38210050 */ addi        r1, r1, 0x50
  /* 80516684 4E800020 */ blr
  // clang-format on
}

// Symbol: isInsideShape__Q26System19MapdataAreaCylinderCFRCQ23EGG8Vector3f
// PAL: 0x80516688..0x80516768
MARK_BINARY_BLOB(isInsideShape__Q26System19MapdataAreaCylinderCFRCQ23EGG8Vector3f, 0x80516688, 0x80516768);
asm bool
System::MapdataAreaCylinder::isInsideShape(const EGG::Vector3f& pos) const {
  // clang-format off
  nofralloc
  /* 80516688 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 8051668C 80A30004 */ lwz         r5, 4(r3)
  /* 80516690 C0640004 */ lfs         f3, 4(r4)
  /* 80516694 C0050008 */ lfs         f0, 8(r5)
  /* 80516698 C0440000 */ lfs         f2, 0(r4)
  /* 8051669C ECC30028 */ fsubs       f6, f3, f0
  /* 805166A0 C0250004 */ lfs         f1, 4(r5)
  /* 805166A4 C0030018 */ lfs         f0, 0x18(r3)
  /* 805166A8 ECA20828 */ fsubs       f5, f2, f1
  /* 805166AC C0430014 */ lfs         f2, 0x14(r3)
  /* 805166B0 EC260032 */ fmuls       f1, f6, f0
  /* 805166B4 C0640008 */ lfs         f3, 8(r4)
  /* 805166B8 C005000C */ lfs         f0, 0xc(r5)
  /* 805166BC EC4500B2 */ fmuls       f2, f5, f2
  /* 805166C0 D0A10008 */ stfs        f5, 8(r1)
  /* 805166C4 ECE30028 */ fsubs       f7, f3, f0
  /* 805166C8 C063001C */ lfs         f3, 0x1c(r3)
  /* 805166CC EC22082A */ fadds       f1, f2, f1
  /* 805166D0 C0030030 */ lfs         f0, 0x30(r3)
  /* 805166D4 D0C1000C */ stfs        f6, 0xc(r1)
  /* 805166D8 EC4700F2 */ fmuls       f2, f7, f3
  /* 805166DC D0E10010 */ stfs        f7, 0x10(r1)
  /* 805166E0 EC22082A */ fadds       f1, f2, f1
  /* 805166E4 FC010040 */ opword      0xfc010040
  /* 805166E8 4081000C */ ble-        lbl_805166f4
  /* 805166EC 38600000 */ li          r3, 0x0
  /* 805166F0 48000070 */ b           lbl_80516760
  lbl_805166f4:
  /* 805166F4 C0230020 */ lfs         f1, 0x20(r3)
  /* 805166F8 C0030024 */ lfs         f0, 0x24(r3)
  /* 805166FC EC450072 */ fmuls       f2, f5, f1
  /* 80516700 C0830008 */ lfs         f4, 8(r3)
  /* 80516704 EC260032 */ fmuls       f1, f6, f0
  /* 80516708 C063000C */ lfs         f3, 0xc(r3)
  /* 8051670C C0030028 */ lfs         f0, 0x28(r3)
  /* 80516710 ECA50132 */ fmuls       f5, f5, f4
  /* 80516714 EC8600F2 */ fmuls       f4, f6, f3
  /* 80516718 C0C30010 */ lfs         f6, 0x10(r3)
  /* 8051671C EC670032 */ fmuls       f3, f7, f0
  /* 80516720 C003003C */ lfs         f0, 0x3c(r3)
  /* 80516724 EC22082A */ fadds       f1, f2, f1
  /* 80516728 C0430038 */ lfs         f2, 0x38(r3)
  /* 8051672C ECC701B2 */ fmuls       f6, f7, f6
  /* 80516730 EC63082A */ fadds       f3, f3, f1
  /* 80516734 EC85202A */ fadds       f4, f5, f4
  /* 80516738 EC0000F2 */ fmuls       f0, f0, f3
  /* 8051673C EC26202A */ fadds       f1, f6, f4
  /* 80516740 EC000032 */ fmuls       f0, f0, f0
  /* 80516744 EC210072 */ fmuls       f1, f1, f1
  /* 80516748 EC01002A */ fadds       f0, f1, f0
  /* 8051674C FC020040 */ opword      0xfc020040
  /* 80516750 4080000C */ bge-        lbl_8051675c
  /* 80516754 38600000 */ li          r3, 0x0
  /* 80516758 48000008 */ b           lbl_80516760
  lbl_8051675c:
  /* 8051675C 38600001 */ li          r3, 0x1
  lbl_80516760:
  /* 80516760 38210020 */ addi        r1, r1, 0x20
  /* 80516764 4E800020 */ blr
  // clang-format on
}

namespace System {

MapdataAreaBase* CourseMap::getArea(u16 i) const {
  u16 count = mpArea ? mpArea->size() : 0;
  return i < count ? mpArea->get(i) : 0;
}

MapdataAreaBase* CourseMap::getAreaByPriority(u16 i) const {
  u16 count = mpArea ? mpArea->size() : 0;
  return i < count ? mpArea->getByPriority(i) : 0;
}

} // namespace System

// Symbol: unk_80516808
// PAL: 0x80516808..0x80516a60
MARK_BINARY_BLOB(unk_80516808, 0x80516808, 0x80516a60);
asm UNKNOWN_FUNCTION(unk_80516808){
  // clang-format off
  nofralloc
  /* 80516808 9421FFC0 */ stwu        r1, -0x40(r1)
  /* 8051680C 7C0802A6 */ mflr        r0
  /* 80516810 90010044 */ stw         r0, 0x44(r1)
  /* 80516814 39610040 */ addi        r11, r1, 0x40
  /* 80516818 4BB0AD85 */ bl          _savegpr_26
  /* 8051681C 2C050000 */ cmpwi       r5, 0x0
  /* 80516820 7C7C1B78 */ mr          r28, r3
  /* 80516824 7C9D2378 */ mr          r29, r4
  /* 80516828 7CBA2B78 */ mr          r26, r5
  /* 8051682C 7CDE3378 */ mr          r30, r6
  /* 80516830 3BE00000 */ li          r31, 0x0
  /* 80516834 418000EC */ blt-        lbl_80516920
  /* 80516838 80E3002C */ lwz         r7, 0x2c(r3)
  /* 8051683C 54A3043E */ clrlwi      r3, r5, 0x10
  /* 80516840 2C070000 */ cmpwi       r7, 0x0
  /* 80516844 4182000C */ beq-        lbl_80516850
  /* 80516848 A0070004 */ lhz         r0, 4(r7)
  /* 8051684C 48000008 */ b           lbl_80516854
  lbl_80516850:
  /* 80516850 38000000 */ li          r0, 0x0
  lbl_80516854:
  /* 80516854 7C030040 */ cmplw       r3, r0
  /* 80516858 4080002C */ bge-        lbl_80516884
  /* 8051685C A0070004 */ lhz         r0, 4(r7)
  /* 80516860 54A3043E */ clrlwi      r3, r5, 0x10
  /* 80516864 7C030040 */ cmplw       r3, r0
  /* 80516868 40800014 */ bge-        lbl_8051687c
  /* 8051686C 80670000 */ lwz         r3, 0(r7)
  /* 80516870 54A013BA */ rlwinm      r0, r5, 2, 0xe, 0x1d
  /* 80516874 7FE3002E */ lwzx        r31, r3, r0
  /* 80516878 48000010 */ b           lbl_80516888
  lbl_8051687c:
  /* 8051687C 3BE00000 */ li          r31, 0x0
  /* 80516880 48000008 */ b           lbl_80516888
  lbl_80516884:
  /* 80516884 3BE00000 */ li          r31, 0x0
  lbl_80516888:
  /* 80516888 2C1F0000 */ cmpwi       r31, 0x0
  /* 8051688C 41820094 */ beq-        lbl_80516920
  /* 80516890 807F0004 */ lwz         r3, 4(r31)
  /* 80516894 88030001 */ lbz         r0, 1(r3)
  /* 80516898 7C060000 */ cmpw        r6, r0
  /* 8051689C 40820084 */ bne-        lbl_80516920
  /* 805168A0 C0C30008 */ lfs         f6, 8(r3)
  /* 805168A4 C0E30004 */ lfs         f7, 4(r3)
  /* 805168A8 C0240000 */ lfs         f1, 0(r4)
  /* 805168AC C0040004 */ lfs         f0, 4(r4)
  /* 805168B0 EC470828 */ fsubs       f2, f7, f1
  /* 805168B4 C0A3000C */ lfs         f5, 0xc(r3)
  /* 805168B8 EC660028 */ fsubs       f3, f6, f0
  /* 805168BC C0240008 */ lfs         f1, 8(r4)
  /* 805168C0 C01F0040 */ lfs         f0, 0x40(r31)
  /* 805168C4 EC850828 */ fsubs       f4, f5, f1
  /* 805168C8 EC2300F2 */ fmuls       f1, f3, f3
  /* 805168CC D0E10014 */ stfs        f7, 0x14(r1)
  /* 805168D0 EC4200B2 */ fmuls       f2, f2, f2
  /* 805168D4 EC640132 */ fmuls       f3, f4, f4
  /* 805168D8 D0C10018 */ stfs        f6, 0x18(r1)
  /* 805168DC EC22082A */ fadds       f1, f2, f1
  /* 805168E0 D0A1001C */ stfs        f5, 0x1c(r1)
  /* 805168E4 EC23082A */ fadds       f1, f3, f1
  /* 805168E8 FC010040 */ opword      0xfc010040
  /* 805168EC 4081000C */ ble-        lbl_805168f8
  /* 805168F0 38600000 */ li          r3, 0x0
  /* 805168F4 4800001C */ b           lbl_80516910
  lbl_805168f8:
  /* 805168F8 819F0000 */ lwz         r12, 0(r31)
  /* 805168FC 7FE3FB78 */ mr          r3, r31
  /* 80516900 7FA4EB78 */ mr          r4, r29
  /* 80516904 818C0008 */ lwz         r12, 8(r12)
  /* 80516908 7D8903A6 */ mtctr       r12
  /* 8051690C 4E800421 */ bctrl
  lbl_80516910:
  /* 80516910 2C030000 */ cmpwi       r3, 0x0
  /* 80516914 4182000C */ beq-        lbl_80516920
  /* 80516918 7F43D378 */ mr          r3, r26
  /* 8051691C 4800012C */ b           lbl_80516a48
  lbl_80516920:
  /* 80516920 3B400000 */ li          r26, 0x0
  /* 80516924 480000FC */ b           lbl_80516a20
  lbl_80516928:
  /* 80516928 2C040000 */ cmpwi       r4, 0x0
  /* 8051692C 5743043E */ clrlwi      r3, r26, 0x10
  /* 80516930 4182000C */ beq-        lbl_8051693c
  /* 80516934 A0040004 */ lhz         r0, 4(r4)
  /* 80516938 48000008 */ b           lbl_80516940
  lbl_8051693c:
  /* 8051693C 38000000 */ li          r0, 0x0
  lbl_80516940:
  /* 80516940 7C030040 */ cmplw       r3, r0
  /* 80516944 40800034 */ bge-        lbl_80516978
  /* 80516948 A0040004 */ lhz         r0, 4(r4)
  /* 8051694C 5743043E */ clrlwi      r3, r26, 0x10
  /* 80516950 7C030040 */ cmplw       r3, r0
  /* 80516954 4080001C */ bge-        lbl_80516970
  /* 80516958 80640010 */ lwz         r3, 0x10(r4)
  /* 8051695C 2C030000 */ cmpwi       r3, 0x0
  /* 80516960 41820010 */ beq-        lbl_80516970
  /* 80516964 574013BA */ rlwinm      r0, r26, 2, 0xe, 0x1d
  /* 80516968 7F63002E */ lwzx        r27, r3, r0
  /* 8051696C 48000010 */ b           lbl_8051697c
  lbl_80516970:
  /* 80516970 3B600000 */ li          r27, 0x0
  /* 80516974 48000008 */ b           lbl_8051697c
  lbl_80516978:
  /* 80516978 3B600000 */ li          r27, 0x0
  lbl_8051697c:
  /* 8051697C 2C1B0000 */ cmpwi       r27, 0x0
  /* 80516980 4182009C */ beq-        lbl_80516a1c
  /* 80516984 7C1BF840 */ cmplw       r27, r31
  /* 80516988 41820094 */ beq-        lbl_80516a1c
  /* 8051698C 807B0004 */ lwz         r3, 4(r27)
  /* 80516990 88030001 */ lbz         r0, 1(r3)
  /* 80516994 7C1E0000 */ cmpw        r30, r0
  /* 80516998 40820084 */ bne-        lbl_80516a1c
  /* 8051699C C0C30008 */ lfs         f6, 8(r3)
  /* 805169A0 C0E30004 */ lfs         f7, 4(r3)
  /* 805169A4 C03D0000 */ lfs         f1, 0(r29)
  /* 805169A8 C01D0004 */ lfs         f0, 4(r29)
  /* 805169AC EC470828 */ fsubs       f2, f7, f1
  /* 805169B0 C0A3000C */ lfs         f5, 0xc(r3)
  /* 805169B4 EC660028 */ fsubs       f3, f6, f0
  /* 805169B8 C03D0008 */ lfs         f1, 8(r29)
  /* 805169BC C01B0040 */ lfs         f0, 0x40(r27)
  /* 805169C0 EC850828 */ fsubs       f4, f5, f1
  /* 805169C4 EC2300F2 */ fmuls       f1, f3, f3
  /* 805169C8 D0E10008 */ stfs        f7, 8(r1)
  /* 805169CC EC4200B2 */ fmuls       f2, f2, f2
  /* 805169D0 EC640132 */ fmuls       f3, f4, f4
  /* 805169D4 D0C1000C */ stfs        f6, 0xc(r1)
  /* 805169D8 EC22082A */ fadds       f1, f2, f1
  /* 805169DC D0A10010 */ stfs        f5, 0x10(r1)
  /* 805169E0 EC23082A */ fadds       f1, f3, f1
  /* 805169E4 FC010040 */ opword      0xfc010040
  /* 805169E8 4081000C */ ble-        lbl_805169f4
  /* 805169EC 38600000 */ li          r3, 0x0
  /* 805169F0 4800001C */ b           lbl_80516a0c
  lbl_805169f4:
  /* 805169F4 819B0000 */ lwz         r12, 0(r27)
  /* 805169F8 7F63DB78 */ mr          r3, r27
  /* 805169FC 7FA4EB78 */ mr          r4, r29
  /* 80516A00 818C0008 */ lwz         r12, 8(r12)
  /* 80516A04 7D8903A6 */ mtctr       r12
  /* 80516A08 4E800421 */ bctrl
  lbl_80516a0c:
  /* 80516A0C 2C030000 */ cmpwi       r3, 0x0
  /* 80516A10 4182000C */ beq-        lbl_80516a1c
  /* 80516A14 A87B0044 */ lha         r3, 0x44(r27)
  /* 80516A18 48000030 */ b           lbl_80516a48
  lbl_80516a1c:
  /* 80516A1C 3B5A0001 */ addi        r26, r26, 0x1
  lbl_80516a20:
  /* 80516A20 809C002C */ lwz         r4, 0x2c(r28)
  /* 80516A24 5743043E */ clrlwi      r3, r26, 0x10
  /* 80516A28 2C040000 */ cmpwi       r4, 0x0
  /* 80516A2C 4082000C */ bne-        lbl_80516a38
  /* 80516A30 38000000 */ li          r0, 0x0
  /* 80516A34 48000008 */ b           lbl_80516a3c
  lbl_80516a38:
  /* 80516A38 A0040004 */ lhz         r0, 4(r4)
  lbl_80516a3c:
  /* 80516A3C 7C030040 */ cmplw       r3, r0
  /* 80516A40 4180FEE8 */ blt+        lbl_80516928
  /* 80516A44 3860FFFF */ li          r3, -0x1
  lbl_80516a48:
  /* 80516A48 39610040 */ addi        r11, r1, 0x40
  /* 80516A4C 4BB0AB9D */ bl          _restgpr_26
  /* 80516A50 80010044 */ lwz         r0, 0x44(r1)
  /* 80516A54 7C0803A6 */ mtlr        r0
  /* 80516A58 38210040 */ addi        r1, r1, 0x40
  /* 80516A5C 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80516a60
// PAL: 0x80516a60..0x80516bb0
MARK_BINARY_BLOB(unk_80516a60, 0x80516a60, 0x80516bb0);
asm UNKNOWN_FUNCTION(unk_80516a60) {
  // clang-format off
  nofralloc
  /* 80516A60 9421FFB0 */ stwu        r1, -0x50(r1)
  /* 80516A64 39200000 */ li          r9, 0x0
  /* 80516A68 80E3002C */ lwz         r7, 0x2c(r3)
  /* 80516A6C 7CE00034 */ cntlzw      r0, r7
  /* 80516A70 5406D97E */ srwi        r6, r0, 5
  /* 80516A74 48000110 */ b           lbl_80516b84
  lbl_80516a78:
  /* 80516A78 2C070000 */ cmpwi       r7, 0x0
  /* 80516A7C 5523043E */ clrlwi      r3, r9, 0x10
  /* 80516A80 4182000C */ beq-        lbl_80516a8c
  /* 80516A84 A0070004 */ lhz         r0, 4(r7)
  /* 80516A88 48000008 */ b           lbl_80516a90
  lbl_80516a8c:
  /* 80516A8C 38000000 */ li          r0, 0x0
  lbl_80516a90:
  /* 80516A90 7C030040 */ cmplw       r3, r0
  /* 80516A94 40800034 */ bge-        lbl_80516ac8
  /* 80516A98 A0070004 */ lhz         r0, 4(r7)
  /* 80516A9C 5523043E */ clrlwi      r3, r9, 0x10
  /* 80516AA0 7C030040 */ cmplw       r3, r0
  /* 80516AA4 4080001C */ bge-        lbl_80516ac0
  /* 80516AA8 80670010 */ lwz         r3, 0x10(r7)
  /* 80516AAC 2C030000 */ cmpwi       r3, 0x0
  /* 80516AB0 41820010 */ beq-        lbl_80516ac0
  /* 80516AB4 552013BA */ rlwinm      r0, r9, 2, 0xe, 0x1d
  /* 80516AB8 7C63002E */ lwzx        r3, r3, r0
  /* 80516ABC 48000010 */ b           lbl_80516acc
  lbl_80516ac0:
  /* 80516AC0 38600000 */ li          r3, 0x0
  /* 80516AC4 48000008 */ b           lbl_80516acc
  lbl_80516ac8:
  /* 80516AC8 38600000 */ li          r3, 0x0
  lbl_80516acc:
  /* 80516ACC 81030004 */ lwz         r8, 4(r3)
  /* 80516AD0 2C030000 */ cmpwi       r3, 0x0
  /* 80516AD4 A8680028 */ lha         r3, 0x28(r8)
  /* 80516AD8 418200A8 */ beq-        lbl_80516b80
  /* 80516ADC 88080001 */ lbz         r0, 1(r8)
  /* 80516AE0 2C000005 */ cmpwi       r0, 0x5
  /* 80516AE4 4082009C */ bne-        lbl_80516b80
  /* 80516AE8 2C030000 */ cmpwi       r3, 0x0
  /* 80516AEC 40820094 */ bne-        lbl_80516b80
  /* 80516AF0 3CC08089 */ lis         r6, lbl_8088fa78@ha
  /* 80516AF4 C1680024 */ lfs         f11, 0x24(r8)
  /* 80516AF8 C1880020 */ lfs         f12, 0x20(r8)
  /* 80516AFC 38600001 */ li          r3, 0x1
  /* 80516B00 C006FA78 */ lfs         f0, lbl_8088fa78@l(r6)
  /* 80516B04 C1A8001C */ lfs         f13, 0x1c(r8)
  /* 80516B08 C1280008 */ lfs         f9, 8(r8)
  /* 80516B0C EC200332 */ fmuls       f1, f0, f12
  /* 80516B10 EC800372 */ fmuls       f4, f0, f13
  /* 80516B14 C1480004 */ lfs         f10, 4(r8)
  /* 80516B18 C108000C */ lfs         f8, 0xc(r8)
  /* 80516B1C EC0002F2 */ fmuls       f0, f0, f11
  /* 80516B20 EC69082A */ fadds       f3, f9, f1
  /* 80516B24 C0A80018 */ lfs         f5, 0x18(r8)
  /* 80516B28 C0C80014 */ lfs         f6, 0x14(r8)
  /* 80516B2C EC48002A */ fadds       f2, f8, f0
  /* 80516B30 C0E80010 */ lfs         f7, 0x10(r8)
  /* 80516B34 EC2A2028 */ fsubs       f1, f10, f4
  /* 80516B38 EC080028 */ fsubs       f0, f8, f0
  /* 80516B3C D0E10038 */ stfs        f7, 0x38(r1)
  /* 80516B40 D0240000 */ stfs        f1, 0(r4)
  /* 80516B44 EC2A202A */ fadds       f1, f10, f4
  /* 80516B48 D0640004 */ stfs        f3, 4(r4)
  /* 80516B4C D0440008 */ stfs        f2, 8(r4)
  /* 80516B50 D0C1000C */ stfs        f6, 0xc(r1)
  /* 80516B54 D0A1001C */ stfs        f5, 0x1c(r1)
  /* 80516B58 D141002C */ stfs        f10, 0x2c(r1)
  /* 80516B5C D1210030 */ stfs        f9, 0x30(r1)
  /* 80516B60 D1010034 */ stfs        f8, 0x34(r1)
  /* 80516B64 D1A10020 */ stfs        f13, 0x20(r1)
  /* 80516B68 D1810024 */ stfs        f12, 0x24(r1)
  /* 80516B6C D1610028 */ stfs        f11, 0x28(r1)
  /* 80516B70 D0250000 */ stfs        f1, 0(r5)
  /* 80516B74 D0650004 */ stfs        f3, 4(r5)
  /* 80516B78 D0050008 */ stfs        f0, 8(r5)
  /* 80516B7C 4800002C */ b           lbl_80516ba8
  lbl_80516b80:
  /* 80516B80 39290001 */ addi        r9, r9, 0x1
  lbl_80516b84:
  /* 80516B84 2C060000 */ cmpwi       r6, 0x0
  /* 80516B88 5523043E */ clrlwi      r3, r9, 0x10
  /* 80516B8C 4182000C */ beq-        lbl_80516b98
  /* 80516B90 38000000 */ li          r0, 0x0
  /* 80516B94 48000008 */ b           lbl_80516b9c
  lbl_80516b98:
  /* 80516B98 A0070004 */ lhz         r0, 4(r7)
  lbl_80516b9c:
  /* 80516B9C 7C030040 */ cmplw       r3, r0
  /* 80516BA0 4180FED8 */ blt+        lbl_80516a78
  /* 80516BA4 38600000 */ li          r3, 0x0
  lbl_80516ba8:
  /* 80516BA8 38210050 */ addi        r1, r1, 0x50
  /* 80516BAC 4E800020 */ blr
  // clang-format on
}

namespace System {

MapdataCamera* CourseMap::getCamera(u16 i) const {
  u16 count = mpCamera ? mpCamera->size() : 0;
  return i < count ? mpCamera->get(i) : 0;
}

} // namespace System

// Symbol: unk_80516bfc
// PAL: 0x80516bfc..0x80516cd4
MARK_BINARY_BLOB(unk_80516bfc, 0x80516bfc, 0x80516cd4);
asm UNKNOWN_FUNCTION(unk_80516bfc){
  // clang-format off
  nofralloc
  /* 80516BFC 80A3002C */ lwz         r5, 0x2c(r3)
  /* 80516C00 2C050000 */ cmpwi       r5, 0x0
  /* 80516C04 4182000C */ beq-        lbl_80516c10
  /* 80516C08 A0050004 */ lhz         r0, 4(r5)
  /* 80516C0C 48000008 */ b           lbl_80516c14
  lbl_80516c10:
  /* 80516C10 38000000 */ li          r0, 0x0
  lbl_80516c14:
  /* 80516C14 7C040040 */ cmplw       r4, r0
  /* 80516C18 408000B4 */ bge-        lbl_80516ccc
  /* 80516C1C 2C050000 */ cmpwi       r5, 0x0
  /* 80516C20 4182000C */ beq-        lbl_80516c2c
  /* 80516C24 A0050004 */ lhz         r0, 4(r5)
  /* 80516C28 48000008 */ b           lbl_80516c30
  lbl_80516c2c:
  /* 80516C2C 38000000 */ li          r0, 0x0
  lbl_80516c30:
  /* 80516C30 7C040040 */ cmplw       r4, r0
  /* 80516C34 40800028 */ bge-        lbl_80516c5c
  /* 80516C38 A0050004 */ lhz         r0, 4(r5)
  /* 80516C3C 7C040040 */ cmplw       r4, r0
  /* 80516C40 40800014 */ bge-        lbl_80516c54
  /* 80516C44 80A50000 */ lwz         r5, 0(r5)
  /* 80516C48 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80516C4C 7C85002E */ lwzx        r4, r5, r0
  /* 80516C50 48000010 */ b           lbl_80516c60
  lbl_80516c54:
  /* 80516C54 38800000 */ li          r4, 0x0
  /* 80516C58 48000008 */ b           lbl_80516c60
  lbl_80516c5c:
  /* 80516C5C 38800000 */ li          r4, 0x0
  lbl_80516c60:
  /* 80516C60 2C040000 */ cmpwi       r4, 0x0
  /* 80516C64 41820068 */ beq-        lbl_80516ccc
  /* 80516C68 80840004 */ lwz         r4, 4(r4)
  /* 80516C6C 88040002 */ lbz         r0, 2(r4)
  /* 80516C70 7C040775 */ extsb.      r4, r0
  /* 80516C74 41800058 */ blt-        lbl_80516ccc
  /* 80516C78 80A30030 */ lwz         r5, 0x30(r3)
  /* 80516C7C 5483043E */ clrlwi      r3, r4, 0x10
  /* 80516C80 2C050000 */ cmpwi       r5, 0x0
  /* 80516C84 4182000C */ beq-        lbl_80516c90
  /* 80516C88 A0050004 */ lhz         r0, 4(r5)
  /* 80516C8C 48000008 */ b           lbl_80516c94
  lbl_80516c90:
  /* 80516C90 38000000 */ li          r0, 0x0
  lbl_80516c94:
  /* 80516C94 7C030040 */ cmplw       r3, r0
  /* 80516C98 4080002C */ bge-        lbl_80516cc4
  /* 80516C9C A0050004 */ lhz         r0, 4(r5)
  /* 80516CA0 5483043E */ clrlwi      r3, r4, 0x10
  /* 80516CA4 7C030040 */ cmplw       r3, r0
  /* 80516CA8 40800014 */ bge-        lbl_80516cbc
  /* 80516CAC 80650000 */ lwz         r3, 0(r5)
  /* 80516CB0 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80516CB4 7C63002E */ lwzx        r3, r3, r0
  /* 80516CB8 4E800020 */ blr
  lbl_80516cbc:
  /* 80516CBC 38600000 */ li          r3, 0x0
  /* 80516CC0 4E800020 */ blr
  lbl_80516cc4:
  /* 80516CC4 38600000 */ li          r3, 0x0
  /* 80516CC8 4E800020 */ blr
  lbl_80516ccc:
  /* 80516CCC 38600000 */ li          r3, 0x0
  /* 80516CD0 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80516cd4
// PAL: 0x80516cd4..0x80516d4c
MARK_BINARY_BLOB(unk_80516cd4, 0x80516cd4, 0x80516d4c);
asm UNKNOWN_FUNCTION(unk_80516cd4) {
  // clang-format off
  nofralloc
  /* 80516CD4 80630000 */ lwz         r3, 0(r3)
  /* 80516CD8 88030001 */ lbz         r0, 1(r3)
  /* 80516CDC 7C050775 */ extsb.      r5, r0
  /* 80516CE0 4080000C */ bge-        lbl_80516cec
  /* 80516CE4 38600000 */ li          r3, 0x0
  /* 80516CE8 4E800020 */ blr
  lbl_80516cec:
  /* 80516CEC 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80516CF0 54A4043E */ clrlwi      r4, r5, 0x10
  /* 80516CF4 80C3D6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r3)
  /* 80516CF8 80660030 */ lwz         r3, 0x30(r6)
  /* 80516CFC 2C030000 */ cmpwi       r3, 0x0
  /* 80516D00 4182000C */ beq-        lbl_80516d0c
  /* 80516D04 A0030004 */ lhz         r0, 4(r3)
  /* 80516D08 48000008 */ b           lbl_80516d10
  lbl_80516d0c:
  /* 80516D0C 38000000 */ li          r0, 0x0
  lbl_80516d10:
  /* 80516D10 7C040040 */ cmplw       r4, r0
  /* 80516D14 40800030 */ bge-        lbl_80516d44
  /* 80516D18 80860030 */ lwz         r4, 0x30(r6)
  /* 80516D1C 54A3043E */ clrlwi      r3, r5, 0x10
  /* 80516D20 A0040004 */ lhz         r0, 4(r4)
  /* 80516D24 7C030040 */ cmplw       r3, r0
  /* 80516D28 40800014 */ bge-        lbl_80516d3c
  /* 80516D2C 80640000 */ lwz         r3, 0(r4)
  /* 80516D30 54A013BA */ rlwinm      r0, r5, 2, 0xe, 0x1d
  /* 80516D34 7C63002E */ lwzx        r3, r3, r0
  /* 80516D38 4E800020 */ blr
  lbl_80516d3c:
  /* 80516D3C 38600000 */ li          r3, 0x0
  /* 80516D40 4E800020 */ blr
  lbl_80516d44:
  /* 80516D44 38600000 */ li          r3, 0x0
  /* 80516D48 4E800020 */ blr
  // clang-format on
}

namespace System {

bool MapdataEnemyPoint::isNonPrivateBattle() {
  return (RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode ==
              RaceConfig::Settings::GAMEMODE_BATTLE ||
          RaceConfig::spInstance->mRaceScenario.mSettings.mGameMode ==
              RaceConfig::Settings::GAMEMODE_PUBLIC_BATTLE);
}

} // namespace System

// Symbol: unk_80516d74
// PAL: 0x80516d74..0x80517590
MARK_BINARY_BLOB(unk_80516d74, 0x80516d74, 0x80517590);
asm UNKNOWN_FUNCTION(unk_80516d74) {
  // clang-format off
  nofralloc
  /* 80516D74 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 80516D78 7C0802A6 */ mflr        r0
  /* 80516D7C 3CA0809C */ lis         r5, spInstance__Q26System10RaceConfig@ha
  /* 80516D80 90010034 */ stw         r0, 0x34(r1)
  /* 80516D84 38000000 */ li          r0, 0x0
  /* 80516D88 BEE1000C */ stmw        r23, 0xc(r1)
  /* 80516D8C 7C7E1B78 */ mr          r30, r3
  /* 80516D90 7C9F2378 */ mr          r31, r4
  /* 80516D94 3BA00001 */ li          r29, 0x1
  /* 80516D98 98830014 */ stb         r4, 0x14(r3)
  /* 80516D9C 98030011 */ stb         r0, 0x11(r3)
  /* 80516DA0 98030010 */ stb         r0, 0x10(r3)
  /* 80516DA4 80A5D728 */ lwz         r5, spInstance__Q26System10RaceConfig@l(r5)
  /* 80516DA8 80050B70 */ lwz         r0, 0xb70(r5)
  /* 80516DAC 2C000003 */ cmpwi       r0, 0x3
  /* 80516DB0 41820010 */ beq-        lbl_80516dc0
  /* 80516DB4 2C000009 */ cmpwi       r0, 0x9
  /* 80516DB8 41820008 */ beq-        lbl_80516dc0
  /* 80516DBC 3BA00000 */ li          r29, 0x0
  lbl_80516dc0:
  /* 80516DC0 38C00000 */ li          r6, 0x0
  /* 80516DC4 3D00809C */ lis         r8, spInstance__Q26System9CourseMap@ha
  /* 80516DC8 38000002 */ li          r0, 0x2
  /* 80516DCC 4800025C */ b           lbl_80517028
  lbl_80516dd0:
  /* 80516DD0 2C090000 */ cmpwi       r9, 0x0
  /* 80516DD4 54C9043E */ clrlwi      r9, r6, 0x10
  /* 80516DD8 38E00000 */ li          r7, 0x0
  /* 80516DDC 41820018 */ beq-        lbl_80516df4
  /* 80516DE0 80AA000C */ lwz         r5, 0xc(r10)
  /* 80516DE4 A0A50004 */ lhz         r5, 4(r5)
  /* 80516DE8 2C050000 */ cmpwi       r5, 0x0
  /* 80516DEC 41820008 */ beq-        lbl_80516df4
  /* 80516DF0 38E00001 */ li          r7, 0x1
  lbl_80516df4:
  /* 80516DF4 2C070000 */ cmpwi       r7, 0x0
  /* 80516DF8 41820010 */ beq-        lbl_80516e08
  /* 80516DFC 80AA000C */ lwz         r5, 0xc(r10)
  /* 80516E00 A0A50004 */ lhz         r5, 4(r5)
  /* 80516E04 48000008 */ b           lbl_80516e0c
  lbl_80516e08:
  /* 80516E08 38A00000 */ li          r5, 0x0
  lbl_80516e0c:
  /* 80516E0C 7C092840 */ cmplw       r9, r5
  /* 80516E10 40800030 */ bge-        lbl_80516e40
  /* 80516E14 812A000C */ lwz         r9, 0xc(r10)
  /* 80516E18 54C7043E */ clrlwi      r7, r6, 0x10
  /* 80516E1C A0A90004 */ lhz         r5, 4(r9)
  /* 80516E20 7C072840 */ cmplw       r7, r5
  /* 80516E24 40800014 */ bge-        lbl_80516e38
  /* 80516E28 80E90000 */ lwz         r7, 0(r9)
  /* 80516E2C 54C513BA */ rlwinm      r5, r6, 2, 0xe, 0x1d
  /* 80516E30 7CA7282E */ lwzx        r5, r7, r5
  /* 80516E34 48000010 */ b           lbl_80516e44
  lbl_80516e38:
  /* 80516E38 38A00000 */ li          r5, 0x0
  /* 80516E3C 48000008 */ b           lbl_80516e44
  lbl_80516e40:
  /* 80516E40 38A00000 */ li          r5, 0x0
  lbl_80516e44:
  /* 80516E44 80E50000 */ lwz         r7, 0(r5)
  /* 80516E48 89270000 */ lbz         r9, 0(r7)
  /* 80516E4C 7C044840 */ cmplw       r4, r9
  /* 80516E50 41800024 */ blt-        lbl_80516e74
  /* 80516E54 88E70001 */ lbz         r7, 1(r7)
  /* 80516E58 7CE93A14 */ add         r7, r9, r7
  /* 80516E5C 38E7FFFF */ addi        r7, r7, -0x1
  /* 80516E60 54E7063E */ clrlwi      r7, r7, 0x18
  /* 80516E64 7C043840 */ cmplw       r4, r7
  /* 80516E68 4181000C */ bgt-        lbl_80516e74
  /* 80516E6C 38E00001 */ li          r7, 0x1
  /* 80516E70 48000008 */ b           lbl_80516e78
  lbl_80516e74:
  /* 80516E74 38E00000 */ li          r7, 0x0
  lbl_80516e78:
  /* 80516E78 2C070000 */ cmpwi       r7, 0x0
  /* 80516E7C 418201A8 */ beq-        lbl_80517024
  /* 80516E80 7C044840 */ cmplw       r4, r9
  /* 80516E84 408200B0 */ bne-        lbl_80516f34
  /* 80516E88 39600000 */ li          r11, 0x0
  /* 80516E8C 7C0903A6 */ mtctr       r0
  lbl_80516e90:
  /* 80516E90 81450000 */ lwz         r10, 0(r5)
  /* 80516E94 5567043E */ clrlwi      r7, r11, 0x10
  /* 80516E98 892A0001 */ lbz         r9, 1(r10)
  /* 80516E9C 7CEA3A14 */ add         r7, r10, r7
  /* 80516EA0 88E70002 */ lbz         r7, 2(r7)
  /* 80516EA4 28090001 */ cmplwi      r9, 1
  /* 80516EA8 40810018 */ ble-        lbl_80516ec0
  /* 80516EAC 280700FF */ cmplwi      r7, 0xff
  /* 80516EB0 41820010 */ beq-        lbl_80516ec0
  /* 80516EB4 88E30010 */ lbz         r7, 0x10(r3)
  /* 80516EB8 38E70001 */ addi        r7, r7, 0x1
  /* 80516EBC 98E30010 */ stb         r7, 0x10(r3)
  lbl_80516ec0:
  /* 80516EC0 81450000 */ lwz         r10, 0(r5)
  /* 80516EC4 396B0001 */ addi        r11, r11, 0x1
  /* 80516EC8 5567043E */ clrlwi      r7, r11, 0x10
  /* 80516ECC 892A0001 */ lbz         r9, 1(r10)
  /* 80516ED0 7CEA3A14 */ add         r7, r10, r7
  /* 80516ED4 88E70002 */ lbz         r7, 2(r7)
  /* 80516ED8 28090001 */ cmplwi      r9, 1
  /* 80516EDC 40810018 */ ble-        lbl_80516ef4
  /* 80516EE0 280700FF */ cmplwi      r7, 0xff
  /* 80516EE4 41820010 */ beq-        lbl_80516ef4
  /* 80516EE8 88E30010 */ lbz         r7, 0x10(r3)
  /* 80516EEC 38E70001 */ addi        r7, r7, 0x1
  /* 80516EF0 98E30010 */ stb         r7, 0x10(r3)
  lbl_80516ef4:
  /* 80516EF4 81450000 */ lwz         r10, 0(r5)
  /* 80516EF8 396B0001 */ addi        r11, r11, 0x1
  /* 80516EFC 5567043E */ clrlwi      r7, r11, 0x10
  /* 80516F00 892A0001 */ lbz         r9, 1(r10)
  /* 80516F04 7CEA3A14 */ add         r7, r10, r7
  /* 80516F08 88E70002 */ lbz         r7, 2(r7)
  /* 80516F0C 28090001 */ cmplwi      r9, 1
  /* 80516F10 40810018 */ ble-        lbl_80516f28
  /* 80516F14 280700FF */ cmplwi      r7, 0xff
  /* 80516F18 41820010 */ beq-        lbl_80516f28
  /* 80516F1C 88E30010 */ lbz         r7, 0x10(r3)
  /* 80516F20 38E70001 */ addi        r7, r7, 0x1
  /* 80516F24 98E30010 */ stb         r7, 0x10(r3)
  lbl_80516f28:
  /* 80516F28 396B0001 */ addi        r11, r11, 0x1
  /* 80516F2C 4200FF64 */ bdnz        lbl_80516e90
  /* 80516F30 48000018 */ b           lbl_80516f48
  lbl_80516f34:
  /* 80516F34 88E30010 */ lbz         r7, 0x10(r3)
  /* 80516F38 2C070000 */ cmpwi       r7, 0x0
  /* 80516F3C 4082000C */ bne-        lbl_80516f48
  /* 80516F40 38E70001 */ addi        r7, r7, 0x1
  /* 80516F44 98E30010 */ stb         r7, 0x10(r3)
  lbl_80516f48:
  /* 80516F48 81450000 */ lwz         r10, 0(r5)
  /* 80516F4C 892A0001 */ lbz         r9, 1(r10)
  /* 80516F50 88EA0000 */ lbz         r7, 0(r10)
  /* 80516F54 7CE74A14 */ add         r7, r7, r9
  /* 80516F58 38E7FFFF */ addi        r7, r7, -0x1
  /* 80516F5C 54E7063E */ clrlwi      r7, r7, 0x18
  /* 80516F60 7C043840 */ cmplw       r4, r7
  /* 80516F64 408200AC */ bne-        lbl_80517010
  /* 80516F68 88EA0008 */ lbz         r7, 8(r10)
  /* 80516F6C 280700FF */ cmplwi      r7, 0xff
  /* 80516F70 41820010 */ beq-        lbl_80516f80
  /* 80516F74 88E30011 */ lbz         r7, 0x11(r3)
  /* 80516F78 38E70001 */ addi        r7, r7, 0x1
  /* 80516F7C 98E30011 */ stb         r7, 0x11(r3)
  lbl_80516f80:
  /* 80516F80 80E50000 */ lwz         r7, 0(r5)
  /* 80516F84 88E70009 */ lbz         r7, 9(r7)
  /* 80516F88 280700FF */ cmplwi      r7, 0xff
  /* 80516F8C 41820010 */ beq-        lbl_80516f9c
  /* 80516F90 88E30011 */ lbz         r7, 0x11(r3)
  /* 80516F94 38E70001 */ addi        r7, r7, 0x1
  /* 80516F98 98E30011 */ stb         r7, 0x11(r3)
  lbl_80516f9c:
  /* 80516F9C 80E50000 */ lwz         r7, 0(r5)
  /* 80516FA0 88E7000A */ lbz         r7, 0xa(r7)
  /* 80516FA4 280700FF */ cmplwi      r7, 0xff
  /* 80516FA8 41820010 */ beq-        lbl_80516fb8
  /* 80516FAC 88E30011 */ lbz         r7, 0x11(r3)
  /* 80516FB0 38E70001 */ addi        r7, r7, 0x1
  /* 80516FB4 98E30011 */ stb         r7, 0x11(r3)
  lbl_80516fb8:
  /* 80516FB8 80E50000 */ lwz         r7, 0(r5)
  /* 80516FBC 88E7000B */ lbz         r7, 0xb(r7)
  /* 80516FC0 280700FF */ cmplwi      r7, 0xff
  /* 80516FC4 41820010 */ beq-        lbl_80516fd4
  /* 80516FC8 88E30011 */ lbz         r7, 0x11(r3)
  /* 80516FCC 38E70001 */ addi        r7, r7, 0x1
  /* 80516FD0 98E30011 */ stb         r7, 0x11(r3)
  lbl_80516fd4:
  /* 80516FD4 80E50000 */ lwz         r7, 0(r5)
  /* 80516FD8 88E7000C */ lbz         r7, 0xc(r7)
  /* 80516FDC 280700FF */ cmplwi      r7, 0xff
  /* 80516FE0 41820010 */ beq-        lbl_80516ff0
  /* 80516FE4 88E30011 */ lbz         r7, 0x11(r3)
  /* 80516FE8 38E70001 */ addi        r7, r7, 0x1
  /* 80516FEC 98E30011 */ stb         r7, 0x11(r3)
  lbl_80516ff0:
  /* 80516FF0 80E50000 */ lwz         r7, 0(r5)
  /* 80516FF4 88E7000D */ lbz         r7, 0xd(r7)
  /* 80516FF8 280700FF */ cmplwi      r7, 0xff
  /* 80516FFC 41820028 */ beq-        lbl_80517024
  /* 80517000 88E30011 */ lbz         r7, 0x11(r3)
  /* 80517004 38E70001 */ addi        r7, r7, 0x1
  /* 80517008 98E30011 */ stb         r7, 0x11(r3)
  /* 8051700C 48000018 */ b           lbl_80517024
  lbl_80517010:
  /* 80517010 88A30011 */ lbz         r5, 0x11(r3)
  /* 80517014 2C050000 */ cmpwi       r5, 0x0
  /* 80517018 4082000C */ bne-        lbl_80517024
  /* 8051701C 38A50001 */ addi        r5, r5, 0x1
  /* 80517020 98A30011 */ stb         r5, 0x11(r3)
  lbl_80517024:
  /* 80517024 38C60001 */ addi        r6, r6, 0x1
  lbl_80517028:
  /* 80517028 8148D6E8 */ lwz         r10, spInstance__Q26System9CourseMap@l(r8)
  /* 8051702C 38E00000 */ li          r7, 0x0
  /* 80517030 812A000C */ lwz         r9, 0xc(r10)
  /* 80517034 2C090000 */ cmpwi       r9, 0x0
  /* 80517038 41820014 */ beq-        lbl_8051704c
  /* 8051703C A0A90004 */ lhz         r5, 4(r9)
  /* 80517040 2C050000 */ cmpwi       r5, 0x0
  /* 80517044 41820008 */ beq-        lbl_8051704c
  /* 80517048 38E00001 */ li          r7, 0x1
  lbl_8051704c:
  /* 8051704C 2C070000 */ cmpwi       r7, 0x0
  /* 80517050 54C7043E */ clrlwi      r7, r6, 0x10
  /* 80517054 41820010 */ beq-        lbl_80517064
  /* 80517058 80AA000C */ lwz         r5, 0xc(r10)
  /* 8051705C A0A50004 */ lhz         r5, 4(r5)
  /* 80517060 48000008 */ b           lbl_80517068
  lbl_80517064:
  /* 80517064 38A00000 */ li          r5, 0x0
  lbl_80517068:
  /* 80517068 7C072840 */ cmplw       r7, r5
  /* 8051706C 4180FD64 */ blt+        lbl_80516dd0
  /* 80517070 2C1D0000 */ cmpwi       r29, 0x0
  /* 80517074 8B830010 */ lbz         r28, 0x10(r3)
  /* 80517078 8B630011 */ lbz         r27, 0x11(r3)
  /* 8051707C 41820014 */ beq-        lbl_80517090
  /* 80517080 7C9BE214 */ add         r4, r27, r28
  /* 80517084 38000000 */ li          r0, 0x0
  /* 80517088 98830011 */ stb         r4, 0x11(r3)
  /* 8051708C 98030010 */ stb         r0, 0x10(r3)
  lbl_80517090:
  /* 80517090 88830010 */ lbz         r4, 0x10(r3)
  /* 80517094 88030011 */ lbz         r0, 0x11(r3)
  /* 80517098 2C040000 */ cmpwi       r4, 0x0
  /* 8051709C 98830012 */ stb         r4, 0x12(r3)
  /* 805170A0 98030013 */ stb         r0, 0x13(r3)
  /* 805170A4 41820010 */ beq-        lbl_805170b4
  /* 805170A8 7C832378 */ mr          r3, r4
  /* 805170AC 4BD12D45 */ bl          __nwa__FUl
  /* 805170B0 907E0008 */ stw         r3, 8(r30)
  lbl_805170b4:
  /* 805170B4 887E0013 */ lbz         r3, 0x13(r30)
  /* 805170B8 4BD12D39 */ bl          __nwa__FUl
  /* 805170BC 907E000C */ stw         r3, 0xc(r30)
  /* 805170C0 38A00000 */ li          r5, 0x0
  /* 805170C4 388000FF */ li          r4, 0xff
  /* 805170C8 48000010 */ b           lbl_805170d8
  lbl_805170cc:
  /* 805170CC 807E0008 */ lwz         r3, 8(r30)
  /* 805170D0 7C8329AE */ stbx        r4, r3, r5
  /* 805170D4 38A50001 */ addi        r5, r5, 0x1
  lbl_805170d8:
  /* 805170D8 881E0010 */ lbz         r0, 0x10(r30)
  /* 805170DC 7C050000 */ cmpw        r5, r0
  /* 805170E0 4180FFEC */ blt+        lbl_805170cc
  /* 805170E4 38A00000 */ li          r5, 0x0
  /* 805170E8 388000FF */ li          r4, 0xff
  /* 805170EC 48000010 */ b           lbl_805170fc
  lbl_805170f0:
  /* 805170F0 807E000C */ lwz         r3, 0xc(r30)
  /* 805170F4 7C8329AE */ stbx        r4, r3, r5
  /* 805170F8 38A50001 */ addi        r5, r5, 0x1
  lbl_805170fc:
  /* 805170FC 881E0011 */ lbz         r0, 0x11(r30)
  /* 80517100 7C050000 */ cmpw        r5, r0
  /* 80517104 4180FFEC */ blt+        lbl_805170f0
  /* 80517108 38BFFFFF */ addi        r5, r31, -0x1
  /* 8051710C 38DF0001 */ addi        r6, r31, 0x1
  /* 80517110 39000000 */ li          r8, 0x0
  /* 80517114 39200000 */ li          r9, 0x0
  /* 80517118 39400000 */ li          r10, 0x0
  /* 8051711C 39600000 */ li          r11, 0x0
  /* 80517120 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80517124 38000001 */ li          r0, 0x1
  /* 80517128 4800040C */ b           lbl_80517534
  lbl_8051712c:
  /* 8051712C 2C0C0000 */ cmpwi       r12, 0x0
  /* 80517130 556C043E */ clrlwi      r12, r11, 0x10
  /* 80517134 38E00000 */ li          r7, 0x0
  /* 80517138 41820018 */ beq-        lbl_80517150
  /* 8051713C 8098000C */ lwz         r4, 0xc(r24)
  /* 80517140 A0840004 */ lhz         r4, 4(r4)
  /* 80517144 2C040000 */ cmpwi       r4, 0x0
  /* 80517148 41820008 */ beq-        lbl_80517150
  /* 8051714C 38E00001 */ li          r7, 0x1
  lbl_80517150:
  /* 80517150 2C070000 */ cmpwi       r7, 0x0
  /* 80517154 41820010 */ beq-        lbl_80517164
  /* 80517158 8098000C */ lwz         r4, 0xc(r24)
  /* 8051715C A0840004 */ lhz         r4, 4(r4)
  /* 80517160 48000008 */ b           lbl_80517168
  lbl_80517164:
  /* 80517164 38800000 */ li          r4, 0x0
  lbl_80517168:
  /* 80517168 7C0C2040 */ cmplw       r12, r4
  /* 8051716C 40800030 */ bge-        lbl_8051719c
  /* 80517170 8198000C */ lwz         r12, 0xc(r24)
  /* 80517174 5567043E */ clrlwi      r7, r11, 0x10
  /* 80517178 A08C0004 */ lhz         r4, 4(r12)
  /* 8051717C 7C072040 */ cmplw       r7, r4
  /* 80517180 40800014 */ bge-        lbl_80517194
  /* 80517184 80EC0000 */ lwz         r7, 0(r12)
  /* 80517188 556413BA */ rlwinm      r4, r11, 2, 0xe, 0x1d
  /* 8051718C 7C87202E */ lwzx        r4, r7, r4
  /* 80517190 48000010 */ b           lbl_805171a0
  lbl_80517194:
  /* 80517194 38800000 */ li          r4, 0x0
  /* 80517198 48000008 */ b           lbl_805171a0
  lbl_8051719c:
  /* 8051719C 38800000 */ li          r4, 0x0
  lbl_805171a0:
  /* 805171A0 80E40000 */ lwz         r7, 0(r4)
  /* 805171A4 89870000 */ lbz         r12, 0(r7)
  /* 805171A8 7C1F6040 */ cmplw       r31, r12
  /* 805171AC 41800024 */ blt-        lbl_805171d0
  /* 805171B0 88E70001 */ lbz         r7, 1(r7)
  /* 805171B4 7CEC3A14 */ add         r7, r12, r7
  /* 805171B8 38E7FFFF */ addi        r7, r7, -0x1
  /* 805171BC 54E7063E */ clrlwi      r7, r7, 0x18
  /* 805171C0 7C1F3840 */ cmplw       r31, r7
  /* 805171C4 4181000C */ bgt-        lbl_805171d0
  /* 805171C8 38E00001 */ li          r7, 0x1
  /* 805171CC 48000008 */ b           lbl_805171d4
  lbl_805171d0:
  /* 805171D0 38E00000 */ li          r7, 0x0
  lbl_805171d4:
  /* 805171D4 2C070000 */ cmpwi       r7, 0x0
  /* 805171D8 41820358 */ beq-        lbl_80517530
  /* 805171DC 2C1D0000 */ cmpwi       r29, 0x0
  /* 805171E0 41820130 */ beq-        lbl_80517310
  /* 805171E4 7C1F6040 */ cmplw       r31, r12
  /* 805171E8 40820108 */ bne-        lbl_805172f0
  /* 805171EC 39800000 */ li          r12, 0x0
  /* 805171F0 480000F0 */ b           lbl_805172e0
  lbl_805171f4:
  /* 805171F4 80E40000 */ lwz         r7, 0(r4)
  /* 805171F8 5599043E */ clrlwi      r25, r12, 0x10
  /* 805171FC 8B070001 */ lbz         r24, 1(r7)
  /* 80517200 7F27CA14 */ add         r25, r7, r25
  /* 80517204 8B590002 */ lbz         r26, 2(r25)
  /* 80517208 28180001 */ cmplwi      r24, 1
  /* 8051720C 408100D0 */ ble-        lbl_805172dc
  /* 80517210 281A00FF */ cmplwi      r26, 0xff
  /* 80517214 418200C8 */ beq-        lbl_805172dc
  /* 80517218 82E3D6E8 */ lwz         r23, spInstance__Q26System9CourseMap@l(r3)
  /* 8051721C 3B200000 */ li          r25, 0x0
  /* 80517220 8317000C */ lwz         r24, 0xc(r23)
  /* 80517224 2C180000 */ cmpwi       r24, 0x0
  /* 80517228 41820014 */ beq-        lbl_8051723c
  /* 8051722C A3180004 */ lhz         r24, 4(r24)
  /* 80517230 2C180000 */ cmpwi       r24, 0x0
  /* 80517234 41820008 */ beq-        lbl_8051723c
  /* 80517238 3B200001 */ li          r25, 0x1
  lbl_8051723c:
  /* 8051723C 2C190000 */ cmpwi       r25, 0x0
  /* 80517240 41820010 */ beq-        lbl_80517250
  /* 80517244 8317000C */ lwz         r24, 0xc(r23)
  /* 80517248 A3180004 */ lhz         r24, 4(r24)
  /* 8051724C 48000008 */ b           lbl_80517254
  lbl_80517250:
  /* 80517250 3B000000 */ li          r24, 0x0
  lbl_80517254:
  /* 80517254 7C1AC040 */ cmplw       r26, r24
  /* 80517258 4080002C */ bge-        lbl_80517284
  /* 8051725C 8337000C */ lwz         r25, 0xc(r23)
  /* 80517260 A3190004 */ lhz         r24, 4(r25)
  /* 80517264 7C1AC040 */ cmplw       r26, r24
  /* 80517268 40800014 */ bge-        lbl_8051727c
  /* 8051726C 83390000 */ lwz         r25, 0(r25)
  /* 80517270 575815BA */ rlwinm      r24, r26, 2, 0x16, 0x1d
  /* 80517274 7F59C02E */ lwzx        r26, r25, r24
  /* 80517278 48000010 */ b           lbl_80517288
  lbl_8051727c:
  /* 8051727C 3B400000 */ li          r26, 0x0
  /* 80517280 48000008 */ b           lbl_80517288
  lbl_80517284:
  /* 80517284 3B400000 */ li          r26, 0x0
  lbl_80517288:
  /* 80517288 5518063E */ clrlwi      r24, r8, 0x18
  /* 8051728C A327000E */ lhz         r25, 0xe(r7)
  /* 80517290 7C07C030 */ slw         r7, r0, r24
  /* 80517294 7F273839 */ and.        r7, r25, r7
  /* 80517298 4182001C */ beq-        lbl_805172b4
  /* 8051729C 833A0000 */ lwz         r25, 0(r26)
  /* 805172A0 5547063E */ clrlwi      r7, r10, 0x18
  /* 805172A4 831E000C */ lwz         r24, 0xc(r30)
  /* 805172A8 8B390000 */ lbz         r25, 0(r25)
  /* 805172AC 7F3839AE */ stbx        r25, r24, r7
  /* 805172B0 48000024 */ b           lbl_805172d4
  lbl_805172b4:
  /* 805172B4 833A0000 */ lwz         r25, 0(r26)
  /* 805172B8 5547063E */ clrlwi      r7, r10, 0x18
  /* 805172BC 831E000C */ lwz         r24, 0xc(r30)
  /* 805172C0 8B590001 */ lbz         r26, 1(r25)
  /* 805172C4 8B390000 */ lbz         r25, 0(r25)
  /* 805172C8 7F39D214 */ add         r25, r25, r26
  /* 805172CC 3B39FFFF */ addi        r25, r25, -0x1
  /* 805172D0 7F3839AE */ stbx        r25, r24, r7
  lbl_805172d4:
  /* 805172D4 39080001 */ addi        r8, r8, 0x1
  /* 805172D8 394A0001 */ addi        r10, r10, 0x1
  lbl_805172dc:
  /* 805172DC 398C0001 */ addi        r12, r12, 0x1
  lbl_805172e0:
  /* 805172E0 5587043E */ clrlwi      r7, r12, 0x10
  /* 805172E4 7C07E000 */ cmpw        r7, r28
  /* 805172E8 4180FF0C */ blt+        lbl_805171f4
  /* 805172EC 4800010C */ b           lbl_805173f8
  lbl_805172f0:
  /* 805172F0 5507063F */ clrlwi.     r7, r8, 0x18
  /* 805172F4 40820104 */ bne-        lbl_805173f8
  /* 805172F8 819E000C */ lwz         r12, 0xc(r30)
  /* 805172FC 5547063E */ clrlwi      r7, r10, 0x18
  /* 80517300 39080001 */ addi        r8, r8, 0x1
  /* 80517304 394A0001 */ addi        r10, r10, 0x1
  /* 80517308 7CAC39AE */ stbx        r5, r12, r7
  /* 8051730C 480000EC */ b           lbl_805173f8
  lbl_80517310:
  /* 80517310 7C1F6040 */ cmplw       r31, r12
  /* 80517314 408200D0 */ bne-        lbl_805173e4
  /* 80517318 38E00000 */ li          r7, 0x0
  /* 8051731C 480000B4 */ b           lbl_805173d0
  lbl_80517320:
  /* 80517320 83040000 */ lwz         r24, 0(r4)
  /* 80517324 54EC043E */ clrlwi      r12, r7, 0x10
  /* 80517328 7D986214 */ add         r12, r24, r12
  /* 8051732C 8B2C0002 */ lbz         r25, 2(r12)
  /* 80517330 281900FF */ cmplwi      r25, 0xff
  /* 80517334 41820098 */ beq-        lbl_805173cc
  /* 80517338 82E3D6E8 */ lwz         r23, spInstance__Q26System9CourseMap@l(r3)
  /* 8051733C 3B000000 */ li          r24, 0x0
  /* 80517340 8197000C */ lwz         r12, 0xc(r23)
  /* 80517344 2C0C0000 */ cmpwi       r12, 0x0
  /* 80517348 41820014 */ beq-        lbl_8051735c
  /* 8051734C A18C0004 */ lhz         r12, 4(r12)
  /* 80517350 2C0C0000 */ cmpwi       r12, 0x0
  /* 80517354 41820008 */ beq-        lbl_8051735c
  /* 80517358 3B000001 */ li          r24, 0x1
  lbl_8051735c:
  /* 8051735C 2C180000 */ cmpwi       r24, 0x0
  /* 80517360 41820010 */ beq-        lbl_80517370
  /* 80517364 8197000C */ lwz         r12, 0xc(r23)
  /* 80517368 A18C0004 */ lhz         r12, 4(r12)
  /* 8051736C 48000008 */ b           lbl_80517374
  lbl_80517370:
  /* 80517370 39800000 */ li          r12, 0x0
  lbl_80517374:
  /* 80517374 7C196040 */ cmplw       r25, r12
  /* 80517378 4080002C */ bge-        lbl_805173a4
  /* 8051737C 8317000C */ lwz         r24, 0xc(r23)
  /* 80517380 A1980004 */ lhz         r12, 4(r24)
  /* 80517384 7C196040 */ cmplw       r25, r12
  /* 80517388 40800014 */ bge-        lbl_8051739c
  /* 8051738C 83180000 */ lwz         r24, 0(r24)
  /* 80517390 572C15BA */ rlwinm      r12, r25, 2, 0x16, 0x1d
  /* 80517394 7D98602E */ lwzx        r12, r24, r12
  /* 80517398 48000010 */ b           lbl_805173a8
  lbl_8051739c:
  /* 8051739C 39800000 */ li          r12, 0x0
  /* 805173A0 48000008 */ b           lbl_805173a8
  lbl_805173a4:
  /* 805173A4 39800000 */ li          r12, 0x0
  lbl_805173a8:
  /* 805173A8 832C0000 */ lwz         r25, 0(r12)
  /* 805173AC 550C063E */ clrlwi      r12, r8, 0x18
  /* 805173B0 831E0008 */ lwz         r24, 8(r30)
  /* 805173B4 39080001 */ addi        r8, r8, 0x1
  /* 805173B8 8B590001 */ lbz         r26, 1(r25)
  /* 805173BC 8B390000 */ lbz         r25, 0(r25)
  /* 805173C0 7F39D214 */ add         r25, r25, r26
  /* 805173C4 3B39FFFF */ addi        r25, r25, -0x1
  /* 805173C8 7F3861AE */ stbx        r25, r24, r12
  lbl_805173cc:
  /* 805173CC 38E70001 */ addi        r7, r7, 0x1
  lbl_805173d0:
  /* 805173D0 899E0012 */ lbz         r12, 0x12(r30)
  /* 805173D4 54F8043E */ clrlwi      r24, r7, 0x10
  /* 805173D8 7C186000 */ cmpw        r24, r12
  /* 805173DC 4180FF44 */ blt+        lbl_80517320
  /* 805173E0 48000018 */ b           lbl_805173f8
  lbl_805173e4:
  /* 805173E4 550C063F */ clrlwi.     r12, r8, 0x18
  /* 805173E8 40820010 */ bne-        lbl_805173f8
  /* 805173EC 80FE0008 */ lwz         r7, 8(r30)
  /* 805173F0 39080001 */ addi        r8, r8, 0x1
  /* 805173F4 7CA761AE */ stbx        r5, r7, r12
  lbl_805173f8:
  /* 805173F8 80E40000 */ lwz         r7, 0(r4)
  /* 805173FC 89870001 */ lbz         r12, 1(r7)
  /* 80517400 88E70000 */ lbz         r7, 0(r7)
  /* 80517404 7CE76214 */ add         r7, r7, r12
  /* 80517408 38E7FFFF */ addi        r7, r7, -0x1
  /* 8051740C 54E7063E */ clrlwi      r7, r7, 0x18
  /* 80517410 7C1F3840 */ cmplw       r31, r7
  /* 80517414 40820100 */ bne-        lbl_80517514
  /* 80517418 39800000 */ li          r12, 0x0
  /* 8051741C 480000E8 */ b           lbl_80517504
  lbl_80517420:
  /* 80517420 80E40000 */ lwz         r7, 0(r4)
  /* 80517424 5598043E */ clrlwi      r24, r12, 0x10
  /* 80517428 7F07C214 */ add         r24, r7, r24
  /* 8051742C 8B580008 */ lbz         r26, 8(r24)
  /* 80517430 281A00FF */ cmplwi      r26, 0xff
  /* 80517434 418200CC */ beq-        lbl_80517500
  /* 80517438 82E3D6E8 */ lwz         r23, spInstance__Q26System9CourseMap@l(r3)
  /* 8051743C 3B200000 */ li          r25, 0x0
  /* 80517440 8317000C */ lwz         r24, 0xc(r23)
  /* 80517444 2C180000 */ cmpwi       r24, 0x0
  /* 80517448 41820014 */ beq-        lbl_8051745c
  /* 8051744C A3180004 */ lhz         r24, 4(r24)
  /* 80517450 2C180000 */ cmpwi       r24, 0x0
  /* 80517454 41820008 */ beq-        lbl_8051745c
  /* 80517458 3B200001 */ li          r25, 0x1
  lbl_8051745c:
  /* 8051745C 2C190000 */ cmpwi       r25, 0x0
  /* 80517460 41820010 */ beq-        lbl_80517470
  /* 80517464 8317000C */ lwz         r24, 0xc(r23)
  /* 80517468 A3180004 */ lhz         r24, 4(r24)
  /* 8051746C 48000008 */ b           lbl_80517474
  lbl_80517470:
  /* 80517470 3B000000 */ li          r24, 0x0
  lbl_80517474:
  /* 80517474 7C1AC040 */ cmplw       r26, r24
  /* 80517478 4080002C */ bge-        lbl_805174a4
  /* 8051747C 8337000C */ lwz         r25, 0xc(r23)
  /* 80517480 A3190004 */ lhz         r24, 4(r25)
  /* 80517484 7C1AC040 */ cmplw       r26, r24
  /* 80517488 40800014 */ bge-        lbl_8051749c
  /* 8051748C 83390000 */ lwz         r25, 0(r25)
  /* 80517490 575815BA */ rlwinm      r24, r26, 2, 0x16, 0x1d
  /* 80517494 7F59C02E */ lwzx        r26, r25, r24
  /* 80517498 48000010 */ b           lbl_805174a8
  lbl_8051749c:
  /* 8051749C 3B400000 */ li          r26, 0x0
  /* 805174A0 48000008 */ b           lbl_805174a8
  lbl_805174a4:
  /* 805174A4 3B400000 */ li          r26, 0x0
  lbl_805174a8:
  /* 805174A8 5538063E */ clrlwi      r24, r9, 0x18
  /* 805174AC A327000E */ lhz         r25, 0xe(r7)
  /* 805174B0 38F80006 */ addi        r7, r24, 0x6
  /* 805174B4 7C073830 */ slw         r7, r0, r7
  /* 805174B8 7F273839 */ and.        r7, r25, r7
  /* 805174BC 41820028 */ beq-        lbl_805174e4
  /* 805174C0 835A0000 */ lwz         r26, 0(r26)
  /* 805174C4 5547063E */ clrlwi      r7, r10, 0x18
  /* 805174C8 833E000C */ lwz         r25, 0xc(r30)
  /* 805174CC 8B1A0001 */ lbz         r24, 1(r26)
  /* 805174D0 8B5A0000 */ lbz         r26, 0(r26)
  /* 805174D4 7F5AC214 */ add         r26, r26, r24
  /* 805174D8 3B5AFFFF */ addi        r26, r26, -0x1
  /* 805174DC 7F5939AE */ stbx        r26, r25, r7
  /* 805174E0 48000018 */ b           lbl_805174f8
  lbl_805174e4:
  /* 805174E4 833A0000 */ lwz         r25, 0(r26)
  /* 805174E8 5547063E */ clrlwi      r7, r10, 0x18
  /* 805174EC 835E000C */ lwz         r26, 0xc(r30)
  /* 805174F0 8B390000 */ lbz         r25, 0(r25)
  /* 805174F4 7F3A39AE */ stbx        r25, r26, r7
  lbl_805174f8:
  /* 805174F8 39290001 */ addi        r9, r9, 0x1
  /* 805174FC 394A0001 */ addi        r10, r10, 0x1
  lbl_80517500:
  /* 80517500 398C0001 */ addi        r12, r12, 0x1
  lbl_80517504:
  /* 80517504 5587043E */ clrlwi      r7, r12, 0x10
  /* 80517508 7C07D800 */ cmpw        r7, r27
  /* 8051750C 4180FF14 */ blt+        lbl_80517420
  /* 80517510 48000020 */ b           lbl_80517530
  lbl_80517514:
  /* 80517514 5524063F */ clrlwi.     r4, r9, 0x18
  /* 80517518 40820018 */ bne-        lbl_80517530
  /* 8051751C 80FE000C */ lwz         r7, 0xc(r30)
  /* 80517520 5544063E */ clrlwi      r4, r10, 0x18
  /* 80517524 39290001 */ addi        r9, r9, 0x1
  /* 80517528 394A0001 */ addi        r10, r10, 0x1
  /* 8051752C 7CC721AE */ stbx        r6, r7, r4
  lbl_80517530:
  /* 80517530 396B0001 */ addi        r11, r11, 0x1
  lbl_80517534:
  /* 80517534 8303D6E8 */ lwz         r24, spInstance__Q26System9CourseMap@l(r3)
  /* 80517538 38E00000 */ li          r7, 0x0
  /* 8051753C 8198000C */ lwz         r12, 0xc(r24)
  /* 80517540 2C0C0000 */ cmpwi       r12, 0x0
  /* 80517544 41820014 */ beq-        lbl_80517558
  /* 80517548 A08C0004 */ lhz         r4, 4(r12)
  /* 8051754C 2C040000 */ cmpwi       r4, 0x0
  /* 80517550 41820008 */ beq-        lbl_80517558
  /* 80517554 38E00001 */ li          r7, 0x1
  lbl_80517558:
  /* 80517558 2C070000 */ cmpwi       r7, 0x0
  /* 8051755C 5567043E */ clrlwi      r7, r11, 0x10
  /* 80517560 41820010 */ beq-        lbl_80517570
  /* 80517564 8098000C */ lwz         r4, 0xc(r24)
  /* 80517568 A0840004 */ lhz         r4, 4(r4)
  /* 8051756C 48000008 */ b           lbl_80517574
  lbl_80517570:
  /* 80517570 38800000 */ li          r4, 0x0
  lbl_80517574:
  /* 80517574 7C072040 */ cmplw       r7, r4
  /* 80517578 4180FBB4 */ blt+        lbl_8051712c
  /* 8051757C BAE1000C */ lmw         r23, 0xc(r1)
  /* 80517580 80010034 */ lwz         r0, 0x34(r1)
  /* 80517584 7C0803A6 */ mtlr        r0
  /* 80517588 38210030 */ addi        r1, r1, 0x30
  /* 8051758C 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80517590
// PAL: 0x80517590..0x8051760c
MARK_BINARY_BLOB(unk_80517590, 0x80517590, 0x8051760c);
asm UNKNOWN_FUNCTION(unk_80517590){
  // clang-format off
  nofralloc
  /* 80517590 80630010 */ lwz         r3, 0x10(r3)
  /* 80517594 88840000 */ lbz         r4, 0(r4)
  /* 80517598 2C030000 */ cmpwi       r3, 0x0
  /* 8051759C 4182000C */ beq-        lbl_805175a8
  /* 805175A0 A0030004 */ lhz         r0, 4(r3)
  /* 805175A4 48000008 */ b           lbl_805175ac
  lbl_805175a8:
  /* 805175A8 38000000 */ li          r0, 0x0
  lbl_805175ac:
  /* 805175AC 7C040040 */ cmplw       r4, r0
  /* 805175B0 40800028 */ bge-        lbl_805175d8
  /* 805175B4 A0030004 */ lhz         r0, 4(r3)
  /* 805175B8 7C040040 */ cmplw       r4, r0
  /* 805175BC 40800014 */ bge-        lbl_805175d0
  /* 805175C0 80630000 */ lwz         r3, 0(r3)
  /* 805175C4 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 805175C8 7C63002E */ lwzx        r3, r3, r0
  /* 805175CC 48000010 */ b           lbl_805175dc
  lbl_805175d0:
  /* 805175D0 38600000 */ li          r3, 0x0
  /* 805175D4 48000008 */ b           lbl_805175dc
  lbl_805175d8:
  /* 805175D8 38600000 */ li          r3, 0x0
  lbl_805175dc:
  /* 805175DC 2C030000 */ cmpwi       r3, 0x0
  /* 805175E0 4082000C */ bne-        lbl_805175ec
  /* 805175E4 386000FF */ li          r3, 0xff
  /* 805175E8 4E800020 */ blr
  lbl_805175ec:
  /* 805175EC 88030011 */ lbz         r0, 0x11(r3)
  /* 805175F0 7C050040 */ cmplw       r5, r0
  /* 805175F4 4180000C */ blt-        lbl_80517600
  /* 805175F8 386000FF */ li          r3, 0xff
  /* 805175FC 4E800020 */ blr
  lbl_80517600:
  /* 80517600 8063000C */ lwz         r3, 0xc(r3)
  /* 80517604 7C6328AE */ lbzx        r3, r3, r5
  /* 80517608 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_8051760c
// PAL: 0x8051760c..0x80517670
MARK_BINARY_BLOB(unk_8051760c, 0x8051760c, 0x80517670);
asm UNKNOWN_FUNCTION(unk_8051760c){
  // clang-format off
  nofralloc
  /* 8051760C 80630010 */ lwz         r3, 0x10(r3)
  /* 80517610 88840000 */ lbz         r4, 0(r4)
  /* 80517614 2C030000 */ cmpwi       r3, 0x0
  /* 80517618 4182000C */ beq-        lbl_80517624
  /* 8051761C A0030004 */ lhz         r0, 4(r3)
  /* 80517620 48000008 */ b           lbl_80517628
  lbl_80517624:
  /* 80517624 38000000 */ li          r0, 0x0
  lbl_80517628:
  /* 80517628 7C040040 */ cmplw       r4, r0
  /* 8051762C 40800028 */ bge-        lbl_80517654
  /* 80517630 A0030004 */ lhz         r0, 4(r3)
  /* 80517634 7C040040 */ cmplw       r4, r0
  /* 80517638 40800014 */ bge-        lbl_8051764c
  /* 8051763C 80630000 */ lwz         r3, 0(r3)
  /* 80517640 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80517644 7C63002E */ lwzx        r3, r3, r0
  /* 80517648 48000010 */ b           lbl_80517658
  lbl_8051764c:
  /* 8051764C 38600000 */ li          r3, 0x0
  /* 80517650 48000008 */ b           lbl_80517658
  lbl_80517654:
  /* 80517654 38600000 */ li          r3, 0x0
  lbl_80517658:
  /* 80517658 2C030000 */ cmpwi       r3, 0x0
  /* 8051765C 4082000C */ bne-        lbl_80517668
  /* 80517660 38600000 */ li          r3, 0x0
  /* 80517664 4E800020 */ blr
  lbl_80517668:
  /* 80517668 88630011 */ lbz         r3, 0x11(r3)
  /* 8051766C 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80517670
// PAL: 0x80517670..0x805176ec
MARK_BINARY_BLOB(unk_80517670, 0x80517670, 0x805176ec);
asm UNKNOWN_FUNCTION(unk_80517670){
  // clang-format off
  nofralloc
  /* 80517670 80630010 */ lwz         r3, 0x10(r3)
  /* 80517674 88840000 */ lbz         r4, 0(r4)
  /* 80517678 2C030000 */ cmpwi       r3, 0x0
  /* 8051767C 4182000C */ beq-        lbl_80517688
  /* 80517680 A0030004 */ lhz         r0, 4(r3)
  /* 80517684 48000008 */ b           lbl_8051768c
  lbl_80517688:
  /* 80517688 38000000 */ li          r0, 0x0
  lbl_8051768c:
  /* 8051768C 7C040040 */ cmplw       r4, r0
  /* 80517690 40800028 */ bge-        lbl_805176b8
  /* 80517694 A0030004 */ lhz         r0, 4(r3)
  /* 80517698 7C040040 */ cmplw       r4, r0
  /* 8051769C 40800014 */ bge-        lbl_805176b0
  /* 805176A0 80630000 */ lwz         r3, 0(r3)
  /* 805176A4 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 805176A8 7C63002E */ lwzx        r3, r3, r0
  /* 805176AC 48000010 */ b           lbl_805176bc
  lbl_805176b0:
  /* 805176B0 38600000 */ li          r3, 0x0
  /* 805176B4 48000008 */ b           lbl_805176bc
  lbl_805176b8:
  /* 805176B8 38600000 */ li          r3, 0x0
  lbl_805176bc:
  /* 805176BC 2C030000 */ cmpwi       r3, 0x0
  /* 805176C0 4082000C */ bne-        lbl_805176cc
  /* 805176C4 386000FF */ li          r3, 0xff
  /* 805176C8 4E800020 */ blr
  lbl_805176cc:
  /* 805176CC 88030010 */ lbz         r0, 0x10(r3)
  /* 805176D0 7C050040 */ cmplw       r5, r0
  /* 805176D4 4180000C */ blt-        lbl_805176e0
  /* 805176D8 386000FF */ li          r3, 0xff
  /* 805176DC 4E800020 */ blr
  lbl_805176e0:
  /* 805176E0 80630008 */ lwz         r3, 8(r3)
  /* 805176E4 7C6328AE */ lbzx        r3, r3, r5
  /* 805176E8 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_805176ec
// PAL: 0x805176ec..0x80517750
MARK_BINARY_BLOB(unk_805176ec, 0x805176ec, 0x80517750);
asm UNKNOWN_FUNCTION(unk_805176ec){
  // clang-format off
  nofralloc
  /* 805176EC 80630010 */ lwz         r3, 0x10(r3)
  /* 805176F0 88840000 */ lbz         r4, 0(r4)
  /* 805176F4 2C030000 */ cmpwi       r3, 0x0
  /* 805176F8 4182000C */ beq-        lbl_80517704
  /* 805176FC A0030004 */ lhz         r0, 4(r3)
  /* 80517700 48000008 */ b           lbl_80517708
  lbl_80517704:
  /* 80517704 38000000 */ li          r0, 0x0
  lbl_80517708:
  /* 80517708 7C040040 */ cmplw       r4, r0
  /* 8051770C 40800028 */ bge-        lbl_80517734
  /* 80517710 A0030004 */ lhz         r0, 4(r3)
  /* 80517714 7C040040 */ cmplw       r4, r0
  /* 80517718 40800014 */ bge-        lbl_8051772c
  /* 8051771C 80630000 */ lwz         r3, 0(r3)
  /* 80517720 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80517724 7C63002E */ lwzx        r3, r3, r0
  /* 80517728 48000010 */ b           lbl_80517738
  lbl_8051772c:
  /* 8051772C 38600000 */ li          r3, 0x0
  /* 80517730 48000008 */ b           lbl_80517738
  lbl_80517734:
  /* 80517734 38600000 */ li          r3, 0x0
  lbl_80517738:
  /* 80517738 2C030000 */ cmpwi       r3, 0x0
  /* 8051773C 4082000C */ bne-        lbl_80517748
  /* 80517740 38600000 */ li          r3, 0x0
  /* 80517744 4E800020 */ blr
  lbl_80517748:
  /* 80517748 88630010 */ lbz         r3, 0x10(r3)
  /* 8051774C 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80517750
// PAL: 0x80517750..0x80517858
MARK_BINARY_BLOB(unk_80517750, 0x80517750, 0x80517858);
asm UNKNOWN_FUNCTION(unk_80517750){
  // clang-format off
  nofralloc
  /* 80517750 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80517754 7C0802A6 */ mflr        r0
  /* 80517758 90010024 */ stw         r0, 0x24(r1)
  /* 8051775C 93E1001C */ stw         r31, 0x1c(r1)
  /* 80517760 3BE00000 */ li          r31, 0x0
  /* 80517764 93C10018 */ stw         r30, 0x18(r1)
  /* 80517768 7CBE2B78 */ mr          r30, r5
  /* 8051776C 93A10014 */ stw         r29, 0x14(r1)
  /* 80517770 7C9D2378 */ mr          r29, r4
  /* 80517774 93810010 */ stw         r28, 0x10(r1)
  /* 80517778 7C7C1B78 */ mr          r28, r3
  /* 8051777C 4800007C */ b           lbl_805177f8
  lbl_80517780:
  /* 80517780 2C050000 */ cmpwi       r5, 0x0
  /* 80517784 57E4043E */ clrlwi      r4, r31, 0x10
  /* 80517788 38600000 */ li          r3, 0x0
  /* 8051778C 41820014 */ beq-        lbl_805177a0
  /* 80517790 A0050004 */ lhz         r0, 4(r5)
  /* 80517794 2C000000 */ cmpwi       r0, 0x0
  /* 80517798 41820008 */ beq-        lbl_805177a0
  /* 8051779C 38600001 */ li          r3, 0x1
  lbl_805177a0:
  /* 805177A0 2C030000 */ cmpwi       r3, 0x0
  /* 805177A4 4182000C */ beq-        lbl_805177b0
  /* 805177A8 A0050004 */ lhz         r0, 4(r5)
  /* 805177AC 48000008 */ b           lbl_805177b4
  lbl_805177b0:
  /* 805177B0 38000000 */ li          r0, 0x0
  lbl_805177b4:
  /* 805177B4 7C040040 */ cmplw       r4, r0
  /* 805177B8 4080002C */ bge-        lbl_805177e4
  /* 805177BC A0050004 */ lhz         r0, 4(r5)
  /* 805177C0 57E3043E */ clrlwi      r3, r31, 0x10
  /* 805177C4 7C030040 */ cmplw       r3, r0
  /* 805177C8 40800014 */ bge-        lbl_805177dc
  /* 805177CC 80650000 */ lwz         r3, 0(r5)
  /* 805177D0 57E013BA */ rlwinm      r0, r31, 2, 0xe, 0x1d
  /* 805177D4 7C63002E */ lwzx        r3, r3, r0
  /* 805177D8 48000010 */ b           lbl_805177e8
  lbl_805177dc:
  /* 805177DC 38600000 */ li          r3, 0x0
  /* 805177E0 48000008 */ b           lbl_805177e8
  lbl_805177e4:
  /* 805177E4 38600000 */ li          r3, 0x0
  lbl_805177e8:
  /* 805177E8 7FA4EB78 */ mr          r4, r29
  /* 805177EC 7FC5F378 */ mr          r5, r30
  /* 805177F0 48000069 */ bl          unk_80517858
  /* 805177F4 3BFF0001 */ addi        r31, r31, 0x1
  lbl_805177f8:
  /* 805177F8 80BC000C */ lwz         r5, 0xc(r28)
  /* 805177FC 38600000 */ li          r3, 0x0
  /* 80517800 2C050000 */ cmpwi       r5, 0x0
  /* 80517804 41820014 */ beq-        lbl_80517818
  /* 80517808 A0050004 */ lhz         r0, 4(r5)
  /* 8051780C 2C000000 */ cmpwi       r0, 0x0
  /* 80517810 41820008 */ beq-        lbl_80517818
  /* 80517814 38600001 */ li          r3, 0x1
  lbl_80517818:
  /* 80517818 2C030000 */ cmpwi       r3, 0x0
  /* 8051781C 57E3043E */ clrlwi      r3, r31, 0x10
  /* 80517820 4182000C */ beq-        lbl_8051782c
  /* 80517824 A0050004 */ lhz         r0, 4(r5)
  /* 80517828 48000008 */ b           lbl_80517830
  lbl_8051782c:
  /* 8051782C 38000000 */ li          r0, 0x0
  lbl_80517830:
  /* 80517830 7C030040 */ cmplw       r3, r0
  /* 80517834 4180FF4C */ blt+        lbl_80517780
  /* 80517838 80010024 */ lwz         r0, 0x24(r1)
  /* 8051783C 83E1001C */ lwz         r31, 0x1c(r1)
  /* 80517840 83C10018 */ lwz         r30, 0x18(r1)
  /* 80517844 83A10014 */ lwz         r29, 0x14(r1)
  /* 80517848 83810010 */ lwz         r28, 0x10(r1)
  /* 8051784C 7C0803A6 */ mtlr        r0
  /* 80517850 38210020 */ addi        r1, r1, 0x20
  /* 80517854 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80517858
// PAL: 0x80517858..0x80517ce4
MARK_BINARY_BLOB(unk_80517858, 0x80517858, 0x80517ce4);
asm UNKNOWN_FUNCTION(unk_80517858) {
  // clang-format off
  nofralloc
  /* 80517858 9421FFD0 */ stwu        r1, -0x30(r1)
  /* 8051785C 7C0802A6 */ mflr        r0
  /* 80517860 3CC0809C */ lis         r6, spInstance__Q26System9CourseMap@ha
  /* 80517864 90010034 */ stw         r0, 0x34(r1)
  /* 80517868 BF010010 */ stmw        r24, 0x10(r1)
  /* 8051786C 7C781B78 */ mr          r24, r3
  /* 80517870 7CBA2B78 */ mr          r26, r5
  /* 80517874 7C992378 */ mr          r25, r4
  /* 80517878 38600000 */ li          r3, 0x0
  /* 8051787C 80C6D6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r6)
  /* 80517880 80A6000C */ lwz         r5, 0xc(r6)
  /* 80517884 2C050000 */ cmpwi       r5, 0x0
  /* 80517888 41820014 */ beq-        lbl_8051789c
  /* 8051788C A0050004 */ lhz         r0, 4(r5)
  /* 80517890 2C000000 */ cmpwi       r0, 0x0
  /* 80517894 41820008 */ beq-        lbl_8051789c
  /* 80517898 38600001 */ li          r3, 0x1
  lbl_8051789c:
  /* 8051789C 2C030000 */ cmpwi       r3, 0x0
  /* 805178A0 41820010 */ beq-        lbl_805178b0
  /* 805178A4 8066000C */ lwz         r3, 0xc(r6)
  /* 805178A8 A0030004 */ lhz         r0, 4(r3)
  /* 805178AC 48000008 */ b           lbl_805178b4
  lbl_805178b0:
  /* 805178B0 38000000 */ li          r0, 0x0
  lbl_805178b4:
  /* 805178B4 7C040040 */ cmplw       r4, r0
  /* 805178B8 4080002C */ bge-        lbl_805178e4
  /* 805178BC 8066000C */ lwz         r3, 0xc(r6)
  /* 805178C0 A0030004 */ lhz         r0, 4(r3)
  /* 805178C4 7C040040 */ cmplw       r4, r0
  /* 805178C8 40800014 */ bge-        lbl_805178dc
  /* 805178CC 80630000 */ lwz         r3, 0(r3)
  /* 805178D0 548015BA */ rlwinm      r0, r4, 2, 0x16, 0x1d
  /* 805178D4 7C63002E */ lwzx        r3, r3, r0
  /* 805178D8 48000010 */ b           lbl_805178e8
  lbl_805178dc:
  /* 805178DC 38600000 */ li          r3, 0x0
  /* 805178E0 48000008 */ b           lbl_805178e8
  lbl_805178e4:
  /* 805178E4 38600000 */ li          r3, 0x0
  lbl_805178e8:
  /* 805178E8 80630000 */ lwz         r3, 0(r3)
  /* 805178EC 2C050000 */ cmpwi       r5, 0x0
  /* 805178F0 38A00000 */ li          r5, 0x0
  /* 805178F4 8BA30000 */ lbz         r29, 0(r3)
  /* 805178F8 41820018 */ beq-        lbl_80517910
  /* 805178FC 8066000C */ lwz         r3, 0xc(r6)
  /* 80517900 A0030004 */ lhz         r0, 4(r3)
  /* 80517904 2C000000 */ cmpwi       r0, 0x0
  /* 80517908 41820008 */ beq-        lbl_80517910
  /* 8051790C 38A00001 */ li          r5, 0x1
  lbl_80517910:
  /* 80517910 2C050000 */ cmpwi       r5, 0x0
  /* 80517914 41820010 */ beq-        lbl_80517924
  /* 80517918 8066000C */ lwz         r3, 0xc(r6)
  /* 8051791C A0030004 */ lhz         r0, 4(r3)
  /* 80517920 48000008 */ b           lbl_80517928
  lbl_80517924:
  /* 80517924 38000000 */ li          r0, 0x0
  lbl_80517928:
  /* 80517928 7C040040 */ cmplw       r4, r0
  /* 8051792C 4080002C */ bge-        lbl_80517958
  /* 80517930 8066000C */ lwz         r3, 0xc(r6)
  /* 80517934 A0030004 */ lhz         r0, 4(r3)
  /* 80517938 7C040040 */ cmplw       r4, r0
  /* 8051793C 40800014 */ bge-        lbl_80517950
  /* 80517940 80630000 */ lwz         r3, 0(r3)
  /* 80517944 548015BA */ rlwinm      r0, r4, 2, 0x16, 0x1d
  /* 80517948 7C63002E */ lwzx        r3, r3, r0
  /* 8051794C 48000010 */ b           lbl_8051795c
  lbl_80517950:
  /* 80517950 38600000 */ li          r3, 0x0
  /* 80517954 48000008 */ b           lbl_8051795c
  lbl_80517958:
  /* 80517958 38600000 */ li          r3, 0x0
  lbl_8051795c:
  /* 8051795C 80830000 */ lwz         r4, 0(r3)
  /* 80517960 3B600000 */ li          r27, 0x0
  /* 80517964 3FE0809C */ lis         r31, spInstance__Q26System9CourseMap@ha
  /* 80517968 3FC0809C */ lis         r30, spInstance__Q26System10RaceConfig@ha
  /* 8051796C 88640001 */ lbz         r3, 1(r4)
  /* 80517970 88040000 */ lbz         r0, 0(r4)
  /* 80517974 7C601A14 */ add         r3, r0, r3
  /* 80517978 3803FFFF */ addi        r0, r3, -0x1
  /* 8051797C 541C063E */ clrlwi      r28, r0, 0x18
  lbl_80517980:
  /* 80517980 80980000 */ lwz         r4, 0(r24)
  /* 80517984 7C64DA14 */ add         r3, r4, r27
  /* 80517988 88030002 */ lbz         r0, 2(r3)
  /* 8051798C 7C190040 */ cmplw       r25, r0
  /* 80517990 408201E0 */ bne-        lbl_80517b70
  /* 80517994 2C1A0000 */ cmpwi       r26, 0x0
  /* 80517998 4182017C */ beq-        lbl_80517b14
  /* 8051799C 807ED728 */ lwz         r3, spInstance__Q26System10RaceConfig@l(r30)
  /* 805179A0 38000001 */ li          r0, 0x1
  /* 805179A4 80630B70 */ lwz         r3, 0xb70(r3)
  /* 805179A8 2C030003 */ cmpwi       r3, 0x3
  /* 805179AC 41820010 */ beq-        lbl_805179bc
  /* 805179B0 2C030009 */ cmpwi       r3, 0x9
  /* 805179B4 41820008 */ beq-        lbl_805179bc
  /* 805179B8 38000000 */ li          r0, 0x0
  lbl_805179bc:
  /* 805179BC 2C000000 */ cmpwi       r0, 0x0
  /* 805179C0 418200AC */ beq-        lbl_80517a6c
  /* 805179C4 80BFD6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r31)
  /* 805179C8 88840000 */ lbz         r4, 0(r4)
  /* 805179CC 80650010 */ lwz         r3, 0x10(r5)
  /* 805179D0 2C030000 */ cmpwi       r3, 0x0
  /* 805179D4 4182000C */ beq-        lbl_805179e0
  /* 805179D8 A0030004 */ lhz         r0, 4(r3)
  /* 805179DC 48000008 */ b           lbl_805179e4
  lbl_805179e0:
  /* 805179E0 38000000 */ li          r0, 0x0
  lbl_805179e4:
  /* 805179E4 7C040040 */ cmplw       r4, r0
  /* 805179E8 4080002C */ bge-        lbl_80517a14
  /* 805179EC 80650010 */ lwz         r3, 0x10(r5)
  /* 805179F0 A0030004 */ lhz         r0, 4(r3)
  /* 805179F4 7C040040 */ cmplw       r4, r0
  /* 805179F8 40800014 */ bge-        lbl_80517a0c
  /* 805179FC 80630000 */ lwz         r3, 0(r3)
  /* 80517A00 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80517A04 7C83002E */ lwzx        r4, r3, r0
  /* 80517A08 48000010 */ b           lbl_80517a18
  lbl_80517a0c:
  /* 80517A0C 38800000 */ li          r4, 0x0
  /* 80517A10 48000008 */ b           lbl_80517a18
  lbl_80517a14:
  /* 80517A14 38800000 */ li          r4, 0x0
  lbl_80517a18:
  /* 80517A18 88C40011 */ lbz         r6, 0x11(r4)
  /* 80517A1C 38A00000 */ li          r5, 0x0
  /* 80517A20 4800001C */ b           lbl_80517a3c
  lbl_80517a24:
  /* 80517A24 8064000C */ lwz         r3, 0xc(r4)
  /* 80517A28 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80517A2C 7C0300AE */ lbzx        r0, r3, r0
  /* 80517A30 7C1C0040 */ cmplw       r28, r0
  /* 80517A34 4182013C */ beq-        lbl_80517b70
  /* 80517A38 38A50001 */ addi        r5, r5, 0x1
  lbl_80517a3c:
  /* 80517A3C 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80517A40 7C003040 */ cmplw       r0, r6
  /* 80517A44 4180FFE0 */ blt+        lbl_80517a24
  /* 80517A48 88040013 */ lbz         r0, 0x13(r4)
  /* 80517A4C 7C060040 */ cmplw       r6, r0
  /* 80517A50 40800120 */ bge-        lbl_80517b70
  /* 80517A54 8064000C */ lwz         r3, 0xc(r4)
  /* 80517A58 7F8331AE */ stbx        r28, r3, r6
  /* 80517A5C 88640011 */ lbz         r3, 0x11(r4)
  /* 80517A60 38030001 */ addi        r0, r3, 0x1
  /* 80517A64 98040011 */ stb         r0, 0x11(r4)
  /* 80517A68 48000108 */ b           lbl_80517b70
  lbl_80517a6c:
  /* 80517A6C 80BFD6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r31)
  /* 80517A70 88840000 */ lbz         r4, 0(r4)
  /* 80517A74 80650010 */ lwz         r3, 0x10(r5)
  /* 80517A78 2C030000 */ cmpwi       r3, 0x0
  /* 80517A7C 4182000C */ beq-        lbl_80517a88
  /* 80517A80 A0030004 */ lhz         r0, 4(r3)
  /* 80517A84 48000008 */ b           lbl_80517a8c
  lbl_80517a88:
  /* 80517A88 38000000 */ li          r0, 0x0
  lbl_80517a8c:
  /* 80517A8C 7C040040 */ cmplw       r4, r0
  /* 80517A90 4080002C */ bge-        lbl_80517abc
  /* 80517A94 80650010 */ lwz         r3, 0x10(r5)
  /* 80517A98 A0030004 */ lhz         r0, 4(r3)
  /* 80517A9C 7C040040 */ cmplw       r4, r0
  /* 80517AA0 40800014 */ bge-        lbl_80517ab4
  /* 80517AA4 80630000 */ lwz         r3, 0(r3)
  /* 80517AA8 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80517AAC 7C83002E */ lwzx        r4, r3, r0
  /* 80517AB0 48000010 */ b           lbl_80517ac0
  lbl_80517ab4:
  /* 80517AB4 38800000 */ li          r4, 0x0
  /* 80517AB8 48000008 */ b           lbl_80517ac0
  lbl_80517abc:
  /* 80517ABC 38800000 */ li          r4, 0x0
  lbl_80517ac0:
  /* 80517AC0 88C40010 */ lbz         r6, 0x10(r4)
  /* 80517AC4 38A00000 */ li          r5, 0x0
  /* 80517AC8 4800001C */ b           lbl_80517ae4
  lbl_80517acc:
  /* 80517ACC 80640008 */ lwz         r3, 8(r4)
  /* 80517AD0 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80517AD4 7C0300AE */ lbzx        r0, r3, r0
  /* 80517AD8 7C1C0040 */ cmplw       r28, r0
  /* 80517ADC 41820094 */ beq-        lbl_80517b70
  /* 80517AE0 38A50001 */ addi        r5, r5, 0x1
  lbl_80517ae4:
  /* 80517AE4 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80517AE8 7C003040 */ cmplw       r0, r6
  /* 80517AEC 4180FFE0 */ blt+        lbl_80517acc
  /* 80517AF0 88040012 */ lbz         r0, 0x12(r4)
  /* 80517AF4 7C060040 */ cmplw       r6, r0
  /* 80517AF8 40800078 */ bge-        lbl_80517b70
  /* 80517AFC 80640008 */ lwz         r3, 8(r4)
  /* 80517B00 7F8331AE */ stbx        r28, r3, r6
  /* 80517B04 88640010 */ lbz         r3, 0x10(r4)
  /* 80517B08 38030001 */ addi        r0, r3, 0x1
  /* 80517B0C 98040010 */ stb         r0, 0x10(r4)
  /* 80517B10 48000060 */ b           lbl_80517b70
  lbl_80517b14:
  /* 80517B14 80BFD6E8 */ lwz         r5, spInstance__Q26System9CourseMap@l(r31)
  /* 80517B18 88840000 */ lbz         r4, 0(r4)
  /* 80517B1C 80650010 */ lwz         r3, 0x10(r5)
  /* 80517B20 2C030000 */ cmpwi       r3, 0x0
  /* 80517B24 4182000C */ beq-        lbl_80517b30
  /* 80517B28 A0030004 */ lhz         r0, 4(r3)
  /* 80517B2C 48000008 */ b           lbl_80517b34
  lbl_80517b30:
  /* 80517B30 38000000 */ li          r0, 0x0
  lbl_80517b34:
  /* 80517B34 7C040040 */ cmplw       r4, r0
  /* 80517B38 4080002C */ bge-        lbl_80517b64
  /* 80517B3C 80650010 */ lwz         r3, 0x10(r5)
  /* 80517B40 A0030004 */ lhz         r0, 4(r3)
  /* 80517B44 7C040040 */ cmplw       r4, r0
  /* 80517B48 40800014 */ bge-        lbl_80517b5c
  /* 80517B4C 80630000 */ lwz         r3, 0(r3)
  /* 80517B50 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80517B54 7C63002E */ lwzx        r3, r3, r0
  /* 80517B58 48000010 */ b           lbl_80517b68
  lbl_80517b5c:
  /* 80517B5C 38600000 */ li          r3, 0x0
  /* 80517B60 48000008 */ b           lbl_80517b68
  lbl_80517b64:
  /* 80517B64 38600000 */ li          r3, 0x0
  lbl_80517b68:
  /* 80517B68 7F84E378 */ mr          r4, r28
  /* 80517B6C 48000221 */ bl          unk_80517d8c
  lbl_80517b70:
  /* 80517B70 3B7B0001 */ addi        r27, r27, 0x1
  /* 80517B74 2C1B0006 */ cmpwi       r27, 0x6
  /* 80517B78 4180FE08 */ blt+        lbl_80517980
  /* 80517B7C 3B600000 */ li          r27, 0x0
  /* 80517B80 3FE0809C */ lis         r31, spInstance__Q26System9CourseMap@ha
  lbl_80517b84:
  /* 80517B84 80B80000 */ lwz         r5, 0(r24)
  /* 80517B88 7C65DA14 */ add         r3, r5, r27
  /* 80517B8C 88030008 */ lbz         r0, 8(r3)
  /* 80517B90 7C190040 */ cmplw       r25, r0
  /* 80517B94 40820130 */ bne-        lbl_80517cc4
  /* 80517B98 2C1A0000 */ cmpwi       r26, 0x0
  /* 80517B9C 418200BC */ beq-        lbl_80517c58
  /* 80517BA0 80DFD6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r31)
  /* 80517BA4 88850001 */ lbz         r4, 1(r5)
  /* 80517BA8 88050000 */ lbz         r0, 0(r5)
  /* 80517BAC 80660010 */ lwz         r3, 0x10(r6)
  /* 80517BB0 7C802214 */ add         r4, r0, r4
  /* 80517BB4 3804FFFF */ addi        r0, r4, -0x1
  /* 80517BB8 2C030000 */ cmpwi       r3, 0x0
  /* 80517BBC 5404063E */ clrlwi      r4, r0, 0x18
  /* 80517BC0 4182000C */ beq-        lbl_80517bcc
  /* 80517BC4 A0030004 */ lhz         r0, 4(r3)
  /* 80517BC8 48000008 */ b           lbl_80517bd0
  lbl_80517bcc:
  /* 80517BCC 38000000 */ li          r0, 0x0
  lbl_80517bd0:
  /* 80517BD0 7C040040 */ cmplw       r4, r0
  /* 80517BD4 4080002C */ bge-        lbl_80517c00
  /* 80517BD8 80660010 */ lwz         r3, 0x10(r6)
  /* 80517BDC A0030004 */ lhz         r0, 4(r3)
  /* 80517BE0 7C040040 */ cmplw       r4, r0
  /* 80517BE4 40800014 */ bge-        lbl_80517bf8
  /* 80517BE8 80630000 */ lwz         r3, 0(r3)
  /* 80517BEC 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80517BF0 7C83002E */ lwzx        r4, r3, r0
  /* 80517BF4 48000010 */ b           lbl_80517c04
  lbl_80517bf8:
  /* 80517BF8 38800000 */ li          r4, 0x0
  /* 80517BFC 48000008 */ b           lbl_80517c04
  lbl_80517c00:
  /* 80517C00 38800000 */ li          r4, 0x0
  lbl_80517c04:
  /* 80517C04 88C40011 */ lbz         r6, 0x11(r4)
  /* 80517C08 38A00000 */ li          r5, 0x0
  /* 80517C0C 4800001C */ b           lbl_80517c28
  lbl_80517c10:
  /* 80517C10 8064000C */ lwz         r3, 0xc(r4)
  /* 80517C14 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80517C18 7C0300AE */ lbzx        r0, r3, r0
  /* 80517C1C 7C1D0040 */ cmplw       r29, r0
  /* 80517C20 418200A4 */ beq-        lbl_80517cc4
  /* 80517C24 38A50001 */ addi        r5, r5, 0x1
  lbl_80517c28:
  /* 80517C28 54A0063E */ clrlwi      r0, r5, 0x18
  /* 80517C2C 7C003040 */ cmplw       r0, r6
  /* 80517C30 4180FFE0 */ blt+        lbl_80517c10
  /* 80517C34 88040013 */ lbz         r0, 0x13(r4)
  /* 80517C38 7C060040 */ cmplw       r6, r0
  /* 80517C3C 40800088 */ bge-        lbl_80517cc4
  /* 80517C40 8064000C */ lwz         r3, 0xc(r4)
  /* 80517C44 7FA331AE */ stbx        r29, r3, r6
  /* 80517C48 88640011 */ lbz         r3, 0x11(r4)
  /* 80517C4C 38030001 */ addi        r0, r3, 0x1
  /* 80517C50 98040011 */ stb         r0, 0x11(r4)
  /* 80517C54 48000070 */ b           lbl_80517cc4
  lbl_80517c58:
  /* 80517C58 80DFD6E8 */ lwz         r6, spInstance__Q26System9CourseMap@l(r31)
  /* 80517C5C 88850001 */ lbz         r4, 1(r5)
  /* 80517C60 88050000 */ lbz         r0, 0(r5)
  /* 80517C64 80660010 */ lwz         r3, 0x10(r6)
  /* 80517C68 7C802214 */ add         r4, r0, r4
  /* 80517C6C 3804FFFF */ addi        r0, r4, -0x1
  /* 80517C70 2C030000 */ cmpwi       r3, 0x0
  /* 80517C74 5404063E */ clrlwi      r4, r0, 0x18
  /* 80517C78 4182000C */ beq-        lbl_80517c84
  /* 80517C7C A0030004 */ lhz         r0, 4(r3)
  /* 80517C80 48000008 */ b           lbl_80517c88
  lbl_80517c84:
  /* 80517C84 38000000 */ li          r0, 0x0
  lbl_80517c88:
  /* 80517C88 7C040040 */ cmplw       r4, r0
  /* 80517C8C 4080002C */ bge-        lbl_80517cb8
  /* 80517C90 80660010 */ lwz         r3, 0x10(r6)
  /* 80517C94 A0030004 */ lhz         r0, 4(r3)
  /* 80517C98 7C040040 */ cmplw       r4, r0
  /* 80517C9C 40800014 */ bge-        lbl_80517cb0
  /* 80517CA0 80630000 */ lwz         r3, 0(r3)
  /* 80517CA4 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80517CA8 7C63002E */ lwzx        r3, r3, r0
  /* 80517CAC 48000010 */ b           lbl_80517cbc
  lbl_80517cb0:
  /* 80517CB0 38600000 */ li          r3, 0x0
  /* 80517CB4 48000008 */ b           lbl_80517cbc
  lbl_80517cb8:
  /* 80517CB8 38600000 */ li          r3, 0x0
  lbl_80517cbc:
  /* 80517CBC 7FA4EB78 */ mr          r4, r29
  /* 80517CC0 480000CD */ bl          unk_80517d8c
  lbl_80517cc4:
  /* 80517CC4 3B7B0001 */ addi        r27, r27, 0x1
  /* 80517CC8 2C1B0006 */ cmpwi       r27, 0x6
  /* 80517CCC 4180FEB8 */ blt+        lbl_80517b84
  /* 80517CD0 BB010010 */ lmw         r24, 0x10(r1)
  /* 80517CD4 80010034 */ lwz         r0, 0x34(r1)
  /* 80517CD8 7C0803A6 */ mtlr        r0
  /* 80517CDC 38210030 */ addi        r1, r1, 0x30
  /* 80517CE0 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80517ce4
// PAL: 0x80517ce4..0x80517d38
MARK_BINARY_BLOB(unk_80517ce4, 0x80517ce4, 0x80517d38);
asm UNKNOWN_FUNCTION(unk_80517ce4){
  // clang-format off
  nofralloc
  /* 80517CE4 88C30010 */ lbz         r6, 0x10(r3)
  /* 80517CE8 38E00000 */ li          r7, 0x0
  /* 80517CEC 4800001C */ b           lbl_80517d08
  lbl_80517cf0:
  /* 80517CF0 80A30008 */ lwz         r5, 8(r3)
  /* 80517CF4 54E0063E */ clrlwi      r0, r7, 0x18
  /* 80517CF8 7C0500AE */ lbzx        r0, r5, r0
  /* 80517CFC 7C040040 */ cmplw       r4, r0
  /* 80517D00 4D820020 */ beqlr-
  /* 80517D04 38E70001 */ addi        r7, r7, 0x1
  lbl_80517d08:
  /* 80517D08 54E0063E */ clrlwi      r0, r7, 0x18
  /* 80517D0C 7C003040 */ cmplw       r0, r6
  /* 80517D10 4180FFE0 */ blt+        lbl_80517cf0
  /* 80517D14 88030012 */ lbz         r0, 0x12(r3)
  /* 80517D18 7C060040 */ cmplw       r6, r0
  /* 80517D1C 4C800020 */ bgelr-
  /* 80517D20 80A30008 */ lwz         r5, 8(r3)
  /* 80517D24 7C8531AE */ stbx        r4, r5, r6
  /* 80517D28 88830010 */ lbz         r4, 0x10(r3)
  /* 80517D2C 38040001 */ addi        r0, r4, 0x1
  /* 80517D30 98030010 */ stb         r0, 0x10(r3)
  /* 80517D34 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80517d38
// PAL: 0x80517d38..0x80517d8c
MARK_BINARY_BLOB(unk_80517d38, 0x80517d38, 0x80517d8c);
asm UNKNOWN_FUNCTION(unk_80517d38){
  // clang-format off
  nofralloc
  /* 80517D38 88C30011 */ lbz         r6, 0x11(r3)
  /* 80517D3C 38E00000 */ li          r7, 0x0
  /* 80517D40 4800001C */ b           lbl_80517d5c
  lbl_80517d44:
  /* 80517D44 80A3000C */ lwz         r5, 0xc(r3)
  /* 80517D48 54E0063E */ clrlwi      r0, r7, 0x18
  /* 80517D4C 7C0500AE */ lbzx        r0, r5, r0
  /* 80517D50 7C040040 */ cmplw       r4, r0
  /* 80517D54 4D820020 */ beqlr-
  /* 80517D58 38E70001 */ addi        r7, r7, 0x1
  lbl_80517d5c:
  /* 80517D5C 54E0063E */ clrlwi      r0, r7, 0x18
  /* 80517D60 7C003040 */ cmplw       r0, r6
  /* 80517D64 4180FFE0 */ blt+        lbl_80517d44
  /* 80517D68 88030013 */ lbz         r0, 0x13(r3)
  /* 80517D6C 7C060040 */ cmplw       r6, r0
  /* 80517D70 4C800020 */ bgelr-
  /* 80517D74 80A3000C */ lwz         r5, 0xc(r3)
  /* 80517D78 7C8531AE */ stbx        r4, r5, r6
  /* 80517D7C 88830011 */ lbz         r4, 0x11(r3)
  /* 80517D80 38040001 */ addi        r0, r4, 0x1
  /* 80517D84 98030011 */ stb         r0, 0x11(r3)
  /* 80517D88 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80517d8c
// PAL: 0x80517d8c..0x80517e88
MARK_BINARY_BLOB(unk_80517d8c, 0x80517d8c, 0x80517e88);
asm UNKNOWN_FUNCTION(unk_80517d8c){
  // clang-format off
  nofralloc
  /* 80517D8C 39000000 */ li          r8, 0x0
  /* 80517D90 38C000FF */ li          r6, 0xff
  /* 80517D94 48000064 */ b           lbl_80517df8
  lbl_80517d98:
  /* 80517D98 80A30008 */ lwz         r5, 8(r3)
  /* 80517D9C 5500063E */ clrlwi      r0, r8, 0x18
  /* 80517DA0 7C0500AE */ lbzx        r0, r5, r0
  /* 80517DA4 7C040040 */ cmplw       r4, r0
  /* 80517DA8 4082004C */ bne-        lbl_80517df4
  /* 80517DAC 7D094378 */ mr          r9, r8
  /* 80517DB0 4800001C */ b           lbl_80517dcc
  lbl_80517db4:
  /* 80517DB4 80A30008 */ lwz         r5, 8(r3)
  /* 80517DB8 5520063E */ clrlwi      r0, r9, 0x18
  /* 80517DBC 39290001 */ addi        r9, r9, 0x1
  /* 80517DC0 7CA50214 */ add         r5, r5, r0
  /* 80517DC4 88050001 */ lbz         r0, 1(r5)
  /* 80517DC8 98050000 */ stb         r0, 0(r5)
  lbl_80517dcc:
  /* 80517DCC 88A30010 */ lbz         r5, 0x10(r3)
  /* 80517DD0 5527063E */ clrlwi      r7, r9, 0x18
  /* 80517DD4 3805FFFF */ addi        r0, r5, -0x1
  /* 80517DD8 7C070000 */ cmpw        r7, r0
  /* 80517DDC 4180FFD8 */ blt+        lbl_80517db4
  /* 80517DE0 80A30008 */ lwz         r5, 8(r3)
  /* 80517DE4 7CC539AE */ stbx        r6, r5, r7
  /* 80517DE8 88A30010 */ lbz         r5, 0x10(r3)
  /* 80517DEC 3805FFFF */ addi        r0, r5, -0x1
  /* 80517DF0 98030010 */ stb         r0, 0x10(r3)
  lbl_80517df4:
  /* 80517DF4 39080001 */ addi        r8, r8, 0x1
  lbl_80517df8:
  /* 80517DF8 88030010 */ lbz         r0, 0x10(r3)
  /* 80517DFC 5505063E */ clrlwi      r5, r8, 0x18
  /* 80517E00 7C050040 */ cmplw       r5, r0
  /* 80517E04 4180FF94 */ blt+        lbl_80517d98
  /* 80517E08 39000000 */ li          r8, 0x0
  /* 80517E0C 38C000FF */ li          r6, 0xff
  /* 80517E10 48000064 */ b           lbl_80517e74
  lbl_80517e14:
  /* 80517E14 80A3000C */ lwz         r5, 0xc(r3)
  /* 80517E18 5500063E */ clrlwi      r0, r8, 0x18
  /* 80517E1C 7C0500AE */ lbzx        r0, r5, r0
  /* 80517E20 7C040040 */ cmplw       r4, r0
  /* 80517E24 4082004C */ bne-        lbl_80517e70
  /* 80517E28 7D094378 */ mr          r9, r8
  /* 80517E2C 4800001C */ b           lbl_80517e48
  lbl_80517e30:
  /* 80517E30 80A3000C */ lwz         r5, 0xc(r3)
  /* 80517E34 5520063E */ clrlwi      r0, r9, 0x18
  /* 80517E38 39290001 */ addi        r9, r9, 0x1
  /* 80517E3C 7CA50214 */ add         r5, r5, r0
  /* 80517E40 88050001 */ lbz         r0, 1(r5)
  /* 80517E44 98050000 */ stb         r0, 0(r5)
  lbl_80517e48:
  /* 80517E48 88A30011 */ lbz         r5, 0x11(r3)
  /* 80517E4C 5527063E */ clrlwi      r7, r9, 0x18
  /* 80517E50 3805FFFF */ addi        r0, r5, -0x1
  /* 80517E54 7C070000 */ cmpw        r7, r0
  /* 80517E58 4180FFD8 */ blt+        lbl_80517e30
  /* 80517E5C 80A3000C */ lwz         r5, 0xc(r3)
  /* 80517E60 7CC539AE */ stbx        r6, r5, r7
  /* 80517E64 88A30011 */ lbz         r5, 0x11(r3)
  /* 80517E68 3805FFFF */ addi        r0, r5, -0x1
  /* 80517E6C 98030011 */ stb         r0, 0x11(r3)
  lbl_80517e70:
  /* 80517E70 39080001 */ addi        r8, r8, 0x1
  lbl_80517e74:
  /* 80517E74 88030011 */ lbz         r0, 0x11(r3)
  /* 80517E78 5505063E */ clrlwi      r5, r8, 0x18
  /* 80517E7C 7C050040 */ cmplw       r5, r0
  /* 80517E80 4180FF94 */ blt+        lbl_80517e14
  /* 80517E84 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80517e88
// PAL: 0x80517e88..0x805181f0
MARK_BINARY_BLOB(unk_80517e88, 0x80517e88, 0x805181f0);
asm UNKNOWN_FUNCTION(unk_80517e88) {
  // clang-format off
  nofralloc
  /* 80517E88 9421FFE0 */ stwu        r1, -0x20(r1)
  /* 80517E8C 38C000FF */ li          r6, 0xff
  /* 80517E90 38A00000 */ li          r5, 0x0
  /* 80517E94 3804FFFF */ addi        r0, r4, -0x1
  /* 80517E98 93E1001C */ stw         r31, 0x1c(r1)
  /* 80517E9C 38E40001 */ addi        r7, r4, 0x1
  /* 80517EA0 39000000 */ li          r8, 0x0
  /* 80517EA4 39400006 */ li          r10, 0x6
  /* 80517EA8 93C10018 */ stw         r30, 0x18(r1)
  /* 80517EAC 39600006 */ li          r11, 0x6
  /* 80517EB0 93A10014 */ stw         r29, 0x14(r1)
  /* 80517EB4 98A30011 */ stb         r5, 0x11(r3)
  /* 80517EB8 98A30010 */ stb         r5, 0x10(r3)
  /* 80517EBC 3CA0809C */ lis         r5, spInstance__Q26System9CourseMap@ha
  /* 80517EC0 98C30004 */ stb         r6, 4(r3)
  /* 80517EC4 98C30005 */ stb         r6, 5(r3)
  /* 80517EC8 98C30006 */ stb         r6, 6(r3)
  /* 80517ECC 98C30007 */ stb         r6, 7(r3)
  /* 80517ED0 98C30008 */ stb         r6, 8(r3)
  /* 80517ED4 98C30009 */ stb         r6, 9(r3)
  /* 80517ED8 98C3000A */ stb         r6, 0xa(r3)
  /* 80517EDC 98C3000B */ stb         r6, 0xb(r3)
  /* 80517EE0 98C3000C */ stb         r6, 0xc(r3)
  /* 80517EE4 98C3000D */ stb         r6, 0xd(r3)
  /* 80517EE8 98C3000E */ stb         r6, 0xe(r3)
  /* 80517EEC 98C3000F */ stb         r6, 0xf(r3)
  /* 80517EF0 480002A4 */ b           lbl_80518194
  lbl_80517ef4:
  /* 80517EF4 2C0C0000 */ cmpwi       r12, 0x0
  /* 80517EF8 550C043E */ clrlwi      r12, r8, 0x10
  /* 80517EFC 39200000 */ li          r9, 0x0
  /* 80517F00 41820018 */ beq-        lbl_80517f18
  /* 80517F04 80DE0014 */ lwz         r6, 0x14(r30)
  /* 80517F08 A0C60004 */ lhz         r6, 4(r6)
  /* 80517F0C 2C060000 */ cmpwi       r6, 0x0
  /* 80517F10 41820008 */ beq-        lbl_80517f18
  /* 80517F14 39200001 */ li          r9, 0x1
  lbl_80517f18:
  /* 80517F18 2C090000 */ cmpwi       r9, 0x0
  /* 80517F1C 41820010 */ beq-        lbl_80517f2c
  /* 80517F20 80DE0014 */ lwz         r6, 0x14(r30)
  /* 80517F24 A0C60004 */ lhz         r6, 4(r6)
  /* 80517F28 48000008 */ b           lbl_80517f30
  lbl_80517f2c:
  /* 80517F2C 38C00000 */ li          r6, 0x0
  lbl_80517f30:
  /* 80517F30 7C0C3040 */ cmplw       r12, r6
  /* 80517F34 40800030 */ bge-        lbl_80517f64
  /* 80517F38 819E0014 */ lwz         r12, 0x14(r30)
  /* 80517F3C 5509043E */ clrlwi      r9, r8, 0x10
  /* 80517F40 A0CC0004 */ lhz         r6, 4(r12)
  /* 80517F44 7C093040 */ cmplw       r9, r6
  /* 80517F48 40800014 */ bge-        lbl_80517f5c
  /* 80517F4C 812C0000 */ lwz         r9, 0(r12)
  /* 80517F50 550613BA */ rlwinm      r6, r8, 2, 0xe, 0x1d
  /* 80517F54 7CC9302E */ lwzx        r6, r9, r6
  /* 80517F58 48000010 */ b           lbl_80517f68
  lbl_80517f5c:
  /* 80517F5C 38C00000 */ li          r6, 0x0
  /* 80517F60 48000008 */ b           lbl_80517f68
  lbl_80517f64:
  /* 80517F64 38C00000 */ li          r6, 0x0
  lbl_80517f68:
  /* 80517F68 81260000 */ lwz         r9, 0(r6)
  /* 80517F6C 89890000 */ lbz         r12, 0(r9)
  /* 80517F70 7C046040 */ cmplw       r4, r12
  /* 80517F74 41800024 */ blt-        lbl_80517f98
  /* 80517F78 89290001 */ lbz         r9, 1(r9)
  /* 80517F7C 7D2C4A14 */ add         r9, r12, r9
  /* 80517F80 3929FFFF */ addi        r9, r9, -0x1
  /* 80517F84 5529063E */ clrlwi      r9, r9, 0x18
  /* 80517F88 7C044840 */ cmplw       r4, r9
  /* 80517F8C 4181000C */ bgt-        lbl_80517f98
  /* 80517F90 39200001 */ li          r9, 0x1
  /* 80517F94 48000008 */ b           lbl_80517f9c
  lbl_80517f98:
  /* 80517F98 39200000 */ li          r9, 0x0
  lbl_80517f9c:
  /* 80517F9C 2C090000 */ cmpwi       r9, 0x0
  /* 80517FA0 418201F0 */ beq-        lbl_80518190
  /* 80517FA4 7C046040 */ cmplw       r4, r12
  /* 80517FA8 408200CC */ bne-        lbl_80518074
  /* 80517FAC 39200000 */ li          r9, 0x0
  /* 80517FB0 7D6903A6 */ mtctr       r11
  lbl_80517fb4:
  /* 80517FB4 83C60000 */ lwz         r30, 0(r6)
  /* 80517FB8 552C043E */ clrlwi      r12, r9, 0x10
  /* 80517FBC 7D9E6214 */ add         r12, r30, r12
  /* 80517FC0 8BEC0002 */ lbz         r31, 2(r12)
  /* 80517FC4 281F00FF */ cmplwi      r31, 0xff
  /* 80517FC8 418200A0 */ beq-        lbl_80518068
  /* 80517FCC 83A5D6E8 */ lwz         r29, spInstance__Q26System9CourseMap@l(r5)
  /* 80517FD0 3BC00000 */ li          r30, 0x0
  /* 80517FD4 819D0014 */ lwz         r12, 0x14(r29)
  /* 80517FD8 2C0C0000 */ cmpwi       r12, 0x0
  /* 80517FDC 41820014 */ beq-        lbl_80517ff0
  /* 80517FE0 A18C0004 */ lhz         r12, 4(r12)
  /* 80517FE4 2C0C0000 */ cmpwi       r12, 0x0
  /* 80517FE8 41820008 */ beq-        lbl_80517ff0
  /* 80517FEC 3BC00001 */ li          r30, 0x1
  lbl_80517ff0:
  /* 80517FF0 2C1E0000 */ cmpwi       r30, 0x0
  /* 80517FF4 41820010 */ beq-        lbl_80518004
  /* 80517FF8 819D0014 */ lwz         r12, 0x14(r29)
  /* 80517FFC A18C0004 */ lhz         r12, 4(r12)
  /* 80518000 48000008 */ b           lbl_80518008
  lbl_80518004:
  /* 80518004 39800000 */ li          r12, 0x0
  lbl_80518008:
  /* 80518008 7C1F6040 */ cmplw       r31, r12
  /* 8051800C 4080002C */ bge-        lbl_80518038
  /* 80518010 83DD0014 */ lwz         r30, 0x14(r29)
  /* 80518014 A19E0004 */ lhz         r12, 4(r30)
  /* 80518018 7C1F6040 */ cmplw       r31, r12
  /* 8051801C 40800014 */ bge-        lbl_80518030
  /* 80518020 83DE0000 */ lwz         r30, 0(r30)
  /* 80518024 57EC15BA */ rlwinm      r12, r31, 2, 0x16, 0x1d
  /* 80518028 7D9E602E */ lwzx        r12, r30, r12
  /* 8051802C 48000010 */ b           lbl_8051803c
  lbl_80518030:
  /* 80518030 39800000 */ li          r12, 0x0
  /* 80518034 48000008 */ b           lbl_8051803c
  lbl_80518038:
  /* 80518038 39800000 */ li          r12, 0x0
  lbl_8051803c:
  /* 8051803C 83CC0000 */ lwz         r30, 0(r12)
  /* 80518040 89830010 */ lbz         r12, 0x10(r3)
  /* 80518044 8BFE0001 */ lbz         r31, 1(r30)
  /* 80518048 8BDE0000 */ lbz         r30, 0(r30)
  /* 8051804C 7D836214 */ add         r12, r3, r12
  /* 80518050 7FDEFA14 */ add         r30, r30, r31
  /* 80518054 3BDEFFFF */ addi        r30, r30, -0x1
  /* 80518058 9BCC0004 */ stb         r30, 4(r12)
  /* 8051805C 89830010 */ lbz         r12, 0x10(r3)
  /* 80518060 398C0001 */ addi        r12, r12, 0x1
  /* 80518064 99830010 */ stb         r12, 0x10(r3)
  lbl_80518068:
  /* 80518068 39290001 */ addi        r9, r9, 0x1
  /* 8051806C 4200FF48 */ bdnz        lbl_80517fb4
  /* 80518070 48000024 */ b           lbl_80518094
  lbl_80518074:
  /* 80518074 89230010 */ lbz         r9, 0x10(r3)
  /* 80518078 2C090000 */ cmpwi       r9, 0x0
  /* 8051807C 40820018 */ bne-        lbl_80518094
  /* 80518080 7D234A14 */ add         r9, r3, r9
  /* 80518084 98090004 */ stb         r0, 4(r9)
  /* 80518088 89230010 */ lbz         r9, 0x10(r3)
  /* 8051808C 39290001 */ addi        r9, r9, 0x1
  /* 80518090 99230010 */ stb         r9, 0x10(r3)
  lbl_80518094:
  /* 80518094 81260000 */ lwz         r9, 0(r6)
  /* 80518098 89890001 */ lbz         r12, 1(r9)
  /* 8051809C 89290000 */ lbz         r9, 0(r9)
  /* 805180A0 7D296214 */ add         r9, r9, r12
  /* 805180A4 3929FFFF */ addi        r9, r9, -0x1
  /* 805180A8 5529063E */ clrlwi      r9, r9, 0x18
  /* 805180AC 7C044840 */ cmplw       r4, r9
  /* 805180B0 408200C0 */ bne-        lbl_80518170
  /* 805180B4 39200000 */ li          r9, 0x0
  /* 805180B8 7D4903A6 */ mtctr       r10
  lbl_805180bc:
  /* 805180BC 83C60000 */ lwz         r30, 0(r6)
  /* 805180C0 552C043E */ clrlwi      r12, r9, 0x10
  /* 805180C4 7D9E6214 */ add         r12, r30, r12
  /* 805180C8 8BCC0008 */ lbz         r30, 8(r12)
  /* 805180CC 281E00FF */ cmplwi      r30, 0xff
  /* 805180D0 41820094 */ beq-        lbl_80518164
  /* 805180D4 83A5D6E8 */ lwz         r29, spInstance__Q26System9CourseMap@l(r5)
  /* 805180D8 3BE00000 */ li          r31, 0x0
  /* 805180DC 819D0014 */ lwz         r12, 0x14(r29)
  /* 805180E0 2C0C0000 */ cmpwi       r12, 0x0
  /* 805180E4 41820014 */ beq-        lbl_805180f8
  /* 805180E8 A18C0004 */ lhz         r12, 4(r12)
  /* 805180EC 2C0C0000 */ cmpwi       r12, 0x0
  /* 805180F0 41820008 */ beq-        lbl_805180f8
  /* 805180F4 3BE00001 */ li          r31, 0x1
  lbl_805180f8:
  /* 805180F8 2C1F0000 */ cmpwi       r31, 0x0
  /* 805180FC 41820010 */ beq-        lbl_8051810c
  /* 80518100 819D0014 */ lwz         r12, 0x14(r29)
  /* 80518104 A18C0004 */ lhz         r12, 4(r12)
  /* 80518108 48000008 */ b           lbl_80518110
  lbl_8051810c:
  /* 8051810C 39800000 */ li          r12, 0x0
  lbl_80518110:
  /* 80518110 7C1E6040 */ cmplw       r30, r12
  /* 80518114 4080002C */ bge-        lbl_80518140
  /* 80518118 83FD0014 */ lwz         r31, 0x14(r29)
  /* 8051811C A19F0004 */ lhz         r12, 4(r31)
  /* 80518120 7C1E6040 */ cmplw       r30, r12
  /* 80518124 40800014 */ bge-        lbl_80518138
  /* 80518128 83FF0000 */ lwz         r31, 0(r31)
  /* 8051812C 57CC15BA */ rlwinm      r12, r30, 2, 0x16, 0x1d
  /* 80518130 7D9F602E */ lwzx        r12, r31, r12
  /* 80518134 48000010 */ b           lbl_80518144
  lbl_80518138:
  /* 80518138 39800000 */ li          r12, 0x0
  /* 8051813C 48000008 */ b           lbl_80518144
  lbl_80518140:
  /* 80518140 39800000 */ li          r12, 0x0
  lbl_80518144:
  /* 80518144 83EC0000 */ lwz         r31, 0(r12)
  /* 80518148 89830011 */ lbz         r12, 0x11(r3)
  /* 8051814C 8BFF0000 */ lbz         r31, 0(r31)
  /* 80518150 7D836214 */ add         r12, r3, r12
  /* 80518154 9BEC000A */ stb         r31, 0xa(r12)
  /* 80518158 89830011 */ lbz         r12, 0x11(r3)
  /* 8051815C 398C0001 */ addi        r12, r12, 0x1
  /* 80518160 99830011 */ stb         r12, 0x11(r3)
  lbl_80518164:
  /* 80518164 39290001 */ addi        r9, r9, 0x1
  /* 80518168 4200FF54 */ bdnz        lbl_805180bc
  /* 8051816C 48000024 */ b           lbl_80518190
  lbl_80518170:
  /* 80518170 88C30011 */ lbz         r6, 0x11(r3)
  /* 80518174 2C060000 */ cmpwi       r6, 0x0
  /* 80518178 40820018 */ bne-        lbl_80518190
  /* 8051817C 7CC33214 */ add         r6, r3, r6
  /* 80518180 98E6000A */ stb         r7, 0xa(r6)
  /* 80518184 88C30011 */ lbz         r6, 0x11(r3)
  /* 80518188 38C60001 */ addi        r6, r6, 0x1
  /* 8051818C 98C30011 */ stb         r6, 0x11(r3)
  lbl_80518190:
  /* 80518190 39080001 */ addi        r8, r8, 0x1
  lbl_80518194:
  /* 80518194 83C5D6E8 */ lwz         r30, spInstance__Q26System9CourseMap@l(r5)
  /* 80518198 39200000 */ li          r9, 0x0
  /* 8051819C 819E0014 */ lwz         r12, 0x14(r30)
  /* 805181A0 2C0C0000 */ cmpwi       r12, 0x0
  /* 805181A4 41820014 */ beq-        lbl_805181b8
  /* 805181A8 A0CC0004 */ lhz         r6, 4(r12)
  /* 805181AC 2C060000 */ cmpwi       r6, 0x0
  /* 805181B0 41820008 */ beq-        lbl_805181b8
  /* 805181B4 39200001 */ li          r9, 0x1
  lbl_805181b8:
  /* 805181B8 2C090000 */ cmpwi       r9, 0x0
  /* 805181BC 5509043E */ clrlwi      r9, r8, 0x10
  /* 805181C0 41820010 */ beq-        lbl_805181d0
  /* 805181C4 80DE0014 */ lwz         r6, 0x14(r30)
  /* 805181C8 A0C60004 */ lhz         r6, 4(r6)
  /* 805181CC 48000008 */ b           lbl_805181d4
  lbl_805181d0:
  /* 805181D0 38C00000 */ li          r6, 0x0
  lbl_805181d4:
  /* 805181D4 7C093040 */ cmplw       r9, r6
  /* 805181D8 4180FD1C */ blt+        lbl_80517ef4
  /* 805181DC 83E1001C */ lwz         r31, 0x1c(r1)
  /* 805181E0 83C10018 */ lwz         r30, 0x18(r1)
  /* 805181E4 83A10014 */ lwz         r29, 0x14(r1)
  /* 805181E8 38210020 */ addi        r1, r1, 0x20
  /* 805181EC 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_805181f0
// PAL: 0x805181f0..0x80518268
MARK_BINARY_BLOB(unk_805181f0, 0x805181f0, 0x80518268);
asm UNKNOWN_FUNCTION(unk_805181f0){
  // clang-format off
  nofralloc
  /* 805181F0 80630018 */ lwz         r3, 0x18(r3)
  /* 805181F4 88840000 */ lbz         r4, 0(r4)
  /* 805181F8 2C030000 */ cmpwi       r3, 0x0
  /* 805181FC 4182000C */ beq-        lbl_80518208
  /* 80518200 A0030004 */ lhz         r0, 4(r3)
  /* 80518204 48000008 */ b           lbl_8051820c
  lbl_80518208:
  /* 80518208 38000000 */ li          r0, 0x0
  lbl_8051820c:
  /* 8051820C 7C040040 */ cmplw       r4, r0
  /* 80518210 40800028 */ bge-        lbl_80518238
  /* 80518214 A0030004 */ lhz         r0, 4(r3)
  /* 80518218 7C040040 */ cmplw       r4, r0
  /* 8051821C 40800014 */ bge-        lbl_80518230
  /* 80518220 80630000 */ lwz         r3, 0(r3)
  /* 80518224 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80518228 7C03002E */ lwzx        r0, r3, r0
  /* 8051822C 48000010 */ b           lbl_8051823c
  lbl_80518230:
  /* 80518230 38000000 */ li          r0, 0x0
  /* 80518234 48000008 */ b           lbl_8051823c
  lbl_80518238:
  /* 80518238 38000000 */ li          r0, 0x0
  lbl_8051823c:
  /* 8051823C 2C000000 */ cmpwi       r0, 0x0
  /* 80518240 4082000C */ bne-        lbl_8051824c
  /* 80518244 386000FF */ li          r3, 0xff
  /* 80518248 4E800020 */ blr
  lbl_8051824c:
  /* 8051824C 28050006 */ cmplwi      r5, 6
  /* 80518250 4180000C */ blt-        lbl_8051825c
  /* 80518254 386000FF */ li          r3, 0xff
  /* 80518258 4E800020 */ blr
  lbl_8051825c:
  /* 8051825C 7C602A14 */ add         r3, r0, r5
  /* 80518260 8863000A */ lbz         r3, 0xa(r3)
  /* 80518264 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80518268
// PAL: 0x80518268..0x805182cc
MARK_BINARY_BLOB(unk_80518268, 0x80518268, 0x805182cc);
asm UNKNOWN_FUNCTION(unk_80518268){
  // clang-format off
  nofralloc
  /* 80518268 80630018 */ lwz         r3, 0x18(r3)
  /* 8051826C 88840000 */ lbz         r4, 0(r4)
  /* 80518270 2C030000 */ cmpwi       r3, 0x0
  /* 80518274 4182000C */ beq-        lbl_80518280
  /* 80518278 A0030004 */ lhz         r0, 4(r3)
  /* 8051827C 48000008 */ b           lbl_80518284
  lbl_80518280:
  /* 80518280 38000000 */ li          r0, 0x0
  lbl_80518284:
  /* 80518284 7C040040 */ cmplw       r4, r0
  /* 80518288 40800028 */ bge-        lbl_805182b0
  /* 8051828C A0030004 */ lhz         r0, 4(r3)
  /* 80518290 7C040040 */ cmplw       r4, r0
  /* 80518294 40800014 */ bge-        lbl_805182a8
  /* 80518298 80630000 */ lwz         r3, 0(r3)
  /* 8051829C 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 805182A0 7C63002E */ lwzx        r3, r3, r0
  /* 805182A4 48000010 */ b           lbl_805182b4
  lbl_805182a8:
  /* 805182A8 38600000 */ li          r3, 0x0
  /* 805182AC 48000008 */ b           lbl_805182b4
  lbl_805182b0:
  /* 805182B0 38600000 */ li          r3, 0x0
  lbl_805182b4:
  /* 805182B4 2C030000 */ cmpwi       r3, 0x0
  /* 805182B8 4082000C */ bne-        lbl_805182c4
  /* 805182BC 38600000 */ li          r3, 0x0
  /* 805182C0 4E800020 */ blr
  lbl_805182c4:
  /* 805182C4 88630011 */ lbz         r3, 0x11(r3)
  /* 805182C8 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_805182cc
// PAL: 0x805182cc..0x80518344
MARK_BINARY_BLOB(unk_805182cc, 0x805182cc, 0x80518344);
asm UNKNOWN_FUNCTION(unk_805182cc){
  // clang-format off
  nofralloc
  /* 805182CC 80630018 */ lwz         r3, 0x18(r3)
  /* 805182D0 88840000 */ lbz         r4, 0(r4)
  /* 805182D4 2C030000 */ cmpwi       r3, 0x0
  /* 805182D8 4182000C */ beq-        lbl_805182e4
  /* 805182DC A0030004 */ lhz         r0, 4(r3)
  /* 805182E0 48000008 */ b           lbl_805182e8
  lbl_805182e4:
  /* 805182E4 38000000 */ li          r0, 0x0
  lbl_805182e8:
  /* 805182E8 7C040040 */ cmplw       r4, r0
  /* 805182EC 40800028 */ bge-        lbl_80518314
  /* 805182F0 A0030004 */ lhz         r0, 4(r3)
  /* 805182F4 7C040040 */ cmplw       r4, r0
  /* 805182F8 40800014 */ bge-        lbl_8051830c
  /* 805182FC 80630000 */ lwz         r3, 0(r3)
  /* 80518300 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 80518304 7C03002E */ lwzx        r0, r3, r0
  /* 80518308 48000010 */ b           lbl_80518318
  lbl_8051830c:
  /* 8051830C 38000000 */ li          r0, 0x0
  /* 80518310 48000008 */ b           lbl_80518318
  lbl_80518314:
  /* 80518314 38000000 */ li          r0, 0x0
  lbl_80518318:
  /* 80518318 2C000000 */ cmpwi       r0, 0x0
  /* 8051831C 4082000C */ bne-        lbl_80518328
  /* 80518320 386000FF */ li          r3, 0xff
  /* 80518324 4E800020 */ blr
  lbl_80518328:
  /* 80518328 28050006 */ cmplwi      r5, 6
  /* 8051832C 4180000C */ blt-        lbl_80518338
  /* 80518330 386000FF */ li          r3, 0xff
  /* 80518334 4E800020 */ blr
  lbl_80518338:
  /* 80518338 7C602A14 */ add         r3, r0, r5
  /* 8051833C 88630004 */ lbz         r3, 4(r3)
  /* 80518340 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_80518344
// PAL: 0x80518344..0x805183a8
MARK_BINARY_BLOB(unk_80518344, 0x80518344, 0x805183a8);
asm UNKNOWN_FUNCTION(unk_80518344){
  // clang-format off
  nofralloc
  /* 80518344 80630018 */ lwz         r3, 0x18(r3)
  /* 80518348 88840000 */ lbz         r4, 0(r4)
  /* 8051834C 2C030000 */ cmpwi       r3, 0x0
  /* 80518350 4182000C */ beq-        lbl_8051835c
  /* 80518354 A0030004 */ lhz         r0, 4(r3)
  /* 80518358 48000008 */ b           lbl_80518360
  lbl_8051835c:
  /* 8051835C 38000000 */ li          r0, 0x0
  lbl_80518360:
  /* 80518360 7C040040 */ cmplw       r4, r0
  /* 80518364 40800028 */ bge-        lbl_8051838c
  /* 80518368 A0030004 */ lhz         r0, 4(r3)
  /* 8051836C 7C040040 */ cmplw       r4, r0
  /* 80518370 40800014 */ bge-        lbl_80518384
  /* 80518374 80630000 */ lwz         r3, 0(r3)
  /* 80518378 548013BA */ rlwinm      r0, r4, 2, 0xe, 0x1d
  /* 8051837C 7C63002E */ lwzx        r3, r3, r0
  /* 80518380 48000010 */ b           lbl_80518390
  lbl_80518384:
  /* 80518384 38600000 */ li          r3, 0x0
  /* 80518388 48000008 */ b           lbl_80518390
  lbl_8051838c:
  /* 8051838C 38600000 */ li          r3, 0x0
  lbl_80518390:
  /* 80518390 2C030000 */ cmpwi       r3, 0x0
  /* 80518394 4082000C */ bne-        lbl_805183a0
  /* 80518398 38600000 */ li          r3, 0x0
  /* 8051839C 4E800020 */ blr
  lbl_805183a0:
  /* 805183A0 88630010 */ lbz         r3, 0x10(r3)
  /* 805183A4 4E800020 */ blr
  // clang-format on
}

// Symbol:
// __ct__Q26System17MapdataJugemPointFPCQ36System17MapdataJugemPoint5SData
// PAL: 0x805183a8..0x805184fc
MARK_BINARY_BLOB(
    __ct__Q26System17MapdataJugemPointFPCQ36System17MapdataJugemPoint5SData,
    0x805183a8, 0x805184fc);
asm UNKNOWN_FUNCTION(
    __ct__Q26System17MapdataJugemPointFPCQ36System17MapdataJugemPoint5SData) {
  // clang-format off
  nofralloc
  /* 805183A8 9421FFB0 */ stwu        r1, -0x50(r1)
  /* 805183AC 7C0802A6 */ mflr        r0
  /* 805183B0 3CA08089 */ lis         r5, lbl_8088fa58@ha
  /* 805183B4 90010054 */ stw         r0, 0x54(r1)
  /* 805183B8 C085FA58 */ lfs         f4, lbl_8088fa58@l(r5)
  /* 805183BC 93E1004C */ stw         r31, 0x4c(r1)
  /* 805183C0 7C7F1B78 */ mr          r31, r3
  /* 805183C4 90830000 */ stw         r4, 0(r3)
  /* 805183C8 C0440014 */ lfs         f2, 0x14(r4)
  /* 805183CC C0240010 */ lfs         f1, 0x10(r4)
  /* 805183D0 EC6400B2 */ fmuls       f3, f4, f2
  /* 805183D4 C004000C */ lfs         f0, 0xc(r4)
  /* 805183D8 EC440072 */ fmuls       f2, f4, f1
  /* 805183DC EC240032 */ fmuls       f1, f4, f0
  /* 805183E0 D063000C */ stfs        f3, 0xc(r3)
  /* 805183E4 D0230004 */ stfs        f1, 4(r3)
  /* 805183E8 D0430008 */ stfs        f2, 8(r3)
  /* 805183EC 38610038 */ addi        r3, r1, 0x38
  /* 805183F0 4BD21B69 */ bl          setRPY__Q23EGG5QuatfFfff
  /* 805183F4 3C80802A */ lis         r4, lbl_802a4148@ha
  /* 805183F8 3861002C */ addi        r3, r1, 0x2c
  /* 805183FC 38844148 */ addi        r4, r4, lbl_802a4148@l
  /* 80518400 4BFFC3D5 */ bl          VEC3_fromNeg
  /* 80518404 38610020 */ addi        r3, r1, 0x20
  /* 80518408 38810038 */ addi        r4, r1, 0x38
  /* 8051840C 38A1002C */ addi        r5, r1, 0x2c
  /* 80518410 4BFFC3ED */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80518414 C0010020 */ lfs         f0, 0x20(r1)
  /* 80518418 3C80802A */ lis         r4, lbl_802a4118@ha
  /* 8051841C D01F0010 */ stfs        f0, 0x10(r31)
  /* 80518420 38610014 */ addi        r3, r1, 0x14
  /* 80518424 38844118 */ addi        r4, r4, lbl_802a4118@l
  /* 80518428 C0010024 */ lfs         f0, 0x24(r1)
  /* 8051842C D01F0014 */ stfs        f0, 0x14(r31)
  /* 80518430 C0010028 */ lfs         f0, 0x28(r1)
  /* 80518434 D01F0018 */ stfs        f0, 0x18(r31)
  /* 80518438 4BFFC39D */ bl          VEC3_fromNeg
  /* 8051843C 38610008 */ addi        r3, r1, 0x8
  /* 80518440 38810038 */ addi        r4, r1, 0x38
  /* 80518444 38A10014 */ addi        r5, r1, 0x14
  /* 80518448 4BFFC3B5 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 8051844C C0010008 */ lfs         f0, 8(r1)
  /* 80518450 D01F001C */ stfs        f0, 0x1c(r31)
  /* 80518454 807F0000 */ lwz         r3, 0(r31)
  /* 80518458 C001000C */ lfs         f0, 0xc(r1)
  /* 8051845C D01F0020 */ stfs        f0, 0x20(r31)
  /* 80518460 C0010010 */ lfs         f0, 0x10(r1)
  /* 80518464 D01F0024 */ stfs        f0, 0x24(r31)
  /* 80518468 A883001A */ lha         r4, 0x1a(r3)
  /* 8051846C 2C040000 */ cmpwi       r4, 0x0
  /* 80518470 40800018 */ bge-        lbl_80518488
  /* 80518474 3860FFFF */ li          r3, -0x1
  /* 80518478 38000000 */ li          r0, 0x0
  /* 8051847C B07F002A */ sth         r3, 0x2a(r31)
  /* 80518480 B01F002C */ sth         r0, 0x2c(r31)
  /* 80518484 48000060 */ b           lbl_805184e4
  lbl_80518488:
  /* 80518488 3C6051EC */ lis         r3, 0x51ec
  /* 8051848C 3803851F */ addi        r0, r3, -0x7ae1
  /* 80518490 7C002096 */ mulhw       r0, r0, r4
  /* 80518494 7C002E70 */ srawi       r0, r0, 5
  /* 80518498 54030FFE */ srwi        r3, r0, 0x1f
  /* 8051849C 7C001A14 */ add         r0, r0, r3
  /* 805184A0 1C000064 */ mulli       r0, r0, 0x64
  /* 805184A4 7C002050 */ subf        r0, r0, r4
  /* 805184A8 B01F002A */ sth         r0, 0x2a(r31)
  /* 805184AC 7C000734 */ extsh       r0, r0
  /* 805184B0 2C000063 */ cmpwi       r0, 0x63
  /* 805184B4 4082000C */ bne-        lbl_805184c0
  /* 805184B8 3800FFFF */ li          r0, -0x1
  /* 805184BC B01F002A */ sth         r0, 0x2a(r31)
  lbl_805184c0:
  /* 805184C0 809F0000 */ lwz         r4, 0(r31)
  /* 805184C4 3C6051EC */ lis         r3, 0x51ec
  /* 805184C8 3863851F */ addi        r3, r3, -0x7ae1
  /* 805184CC A804001A */ lha         r0, 0x1a(r4)
  /* 805184D0 7C030096 */ mulhw       r0, r3, r0
  /* 805184D4 7C002E70 */ srawi       r0, r0, 5
  /* 805184D8 54030FFE */ srwi        r3, r0, 0x1f
  /* 805184DC 7C001A14 */ add         r0, r0, r3
  /* 805184E0 B01F002C */ sth         r0, 0x2c(r31)
  lbl_805184e4:
  /* 805184E4 7FE3FB78 */ mr          r3, r31
  /* 805184E8 83E1004C */ lwz         r31, 0x4c(r1)
  /* 805184EC 80010054 */ lwz         r0, 0x54(r1)
  /* 805184F0 7C0803A6 */ mtlr        r0
  /* 805184F4 38210050 */ addi        r1, r1, 0x50
  /* 805184F8 4E800020 */ blr
  // clang-format on
}

// Symbol: unk_805184fc
// PAL: 0x805184fc..0x80518920
MARK_BINARY_BLOB(unk_805184fc, 0x805184fc, 0x80518920);
asm UNKNOWN_FUNCTION(unk_805184fc) {
  // clang-format off
  nofralloc
  /* 805184FC 9421FF50 */ stwu        r1, -0xb0(r1)
  /* 80518500 7C0802A6 */ mflr        r0
  /* 80518504 900100B4 */ stw         r0, 0xb4(r1)
  /* 80518508 DBE100A0 */ stfd        f31, 0xa0(r1)
  /* 8051850C F3E100A8 */ opword      0xf3e100a8
  /* 80518510 DBC10090 */ stfd        f30, 0x90(r1)
  /* 80518514 F3C10098 */ opword      0xf3c10098
  /* 80518518 DBA10080 */ stfd        f29, 0x80(r1)
  /* 8051851C F3A10088 */ opword      0xf3a10088
  /* 80518520 93E1007C */ stw         r31, 0x7c(r1)
  /* 80518524 3FE08089 */ lis         r31, lbl_8088f8e8@ha
  /* 80518528 3BFFF8E8 */ addi        r31, r31, lbl_8088f8e8@l
  /* 8051852C 93C10078 */ stw         r30, 0x78(r1)
  /* 80518530 7C7E1B78 */ mr          r30, r3
  /* 80518534 C07F0170 */ lfs         f3, 0x170(r31)
  /* 80518538 80830000 */ lwz         r4, 0(r3)
  /* 8051853C 38610060 */ addi        r3, r1, 0x60
  /* 80518540 C024000C */ lfs         f1, 0xc(r4)
  /* 80518544 C0440010 */ lfs         f2, 0x10(r4)
  /* 80518548 C0040014 */ lfs         f0, 0x14(r4)
  /* 8051854C EC230072 */ fmuls       f1, f3, f1
  /* 80518550 EC4300B2 */ fmuls       f2, f3, f2
  /* 80518554 EC630032 */ fmuls       f3, f3, f0
  /* 80518558 4BD21A01 */ bl          setRPY__Q23EGG5QuatfFfff
  /* 8051855C 3CA0802A */ lis         r5, lbl_802a4148@ha
  /* 80518560 38610050 */ addi        r3, r1, 0x50
  /* 80518564 38810060 */ addi        r4, r1, 0x60
  /* 80518568 38A54148 */ addi        r5, r5, lbl_802a4148@l
  /* 8051856C 4BFFC291 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80518570 3CA0802A */ lis         r5, lbl_802a4118@ha
  /* 80518574 38610044 */ addi        r3, r1, 0x44
  /* 80518578 38810060 */ addi        r4, r1, 0x60
  /* 8051857C 38A54118 */ addi        r5, r5, lbl_802a4118@l
  /* 80518580 4BFFC27D */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80518584 3CA0802A */ lis         r5, lbl_802a4130@ha
  /* 80518588 38610038 */ addi        r3, r1, 0x38
  /* 8051858C 38810060 */ addi        r4, r1, 0x60
  /* 80518590 38A54130 */ addi        r5, r5, lbl_802a4130@l
  /* 80518594 4BFFC269 */ bl          VEC3_fromQuaternionRotated__FRQ23EGG8Vector3fRCQ23EGG5QuatfRCQ23EGG8Vector3f
  /* 80518598 C03F0194 */ lfs         f1, 0x194(r31)
  /* 8051859C 4BB6CBE5 */ bl          CosFIdx__Q24nw4r4mathFf
  /* 805185A0 FFE00890 */ fmr         f31, f1
  /* 805185A4 C03F0194 */ lfs         f1, 0x194(r31)
  /* 805185A8 4BB6CB69 */ bl          SinFIdx__Q24nw4r4mathFf
  /* 805185AC EC21F824 */ fdivs       f1, f1, f31
  /* 805185B0 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 805185B4 80E3D6E8 */ lwz         r7, spInstance__Q26System9CourseMap@l(r3)
  /* 805185B8 390000FF */ li          r8, 0xff
  /* 805185BC C01F0198 */ lfs         f0, 0x198(r31)
  /* 805185C0 39200000 */ li          r9, 0x0
  /* 805185C4 80C70010 */ lwz         r6, 0x10(r7)
  /* 805185C8 C1810058 */ lfs         f12, 0x58(r1)
  /* 805185CC 7CC00034 */ cntlzw      r0, r6
  /* 805185D0 C1610050 */ lfs         f11, 0x50(r1)
  /* 805185D4 C1410054 */ lfs         f10, 0x54(r1)
  /* 805185D8 5405D97E */ srwi        r5, r0, 5
  /* 805185DC C13F0154 */ lfs         f9, 0x154(r31)
  /* 805185E0 48000138 */ b           lbl_80518718
  lbl_805185e4:
  /* 805185E4 2C060000 */ cmpwi       r6, 0x0
  /* 805185E8 5524063E */ clrlwi      r4, r9, 0x18
  /* 805185EC 41820010 */ beq-        lbl_805185fc
  /* 805185F0 80670010 */ lwz         r3, 0x10(r7)
  /* 805185F4 A0030004 */ lhz         r0, 4(r3)
  /* 805185F8 48000008 */ b           lbl_80518600
  lbl_805185fc:
  /* 805185FC 38000000 */ li          r0, 0x0
  lbl_80518600:
  /* 80518600 7C040040 */ cmplw       r4, r0
  /* 80518604 40800030 */ bge-        lbl_80518634
  /* 80518608 80870010 */ lwz         r4, 0x10(r7)
  /* 8051860C 5523063E */ clrlwi      r3, r9, 0x18
  /* 80518610 A0040004 */ lhz         r0, 4(r4)
  /* 80518614 7C030040 */ cmplw       r3, r0
  /* 80518618 40800014 */ bge-        lbl_8051862c
  /* 8051861C 80640000 */ lwz         r3, 0(r4)
  /* 80518620 552015BA */ rlwinm      r0, r9, 2, 0x16, 0x1d
  /* 80518624 7C63002E */ lwzx        r3, r3, r0
  /* 80518628 48000010 */ b           lbl_80518638
  lbl_8051862c:
  /* 8051862C 38600000 */ li          r3, 0x0
  /* 80518630 48000008 */ b           lbl_80518638
  lbl_80518634:
  /* 80518634 38600000 */ li          r3, 0x0
  lbl_80518638:
  /* 80518638 80630004 */ lwz         r3, 4(r3)
  /* 8051863C 809E0000 */ lwz         r4, 0(r30)
  /* 80518640 C0830004 */ lfs         f4, 4(r3)
  /* 80518644 C0C30000 */ lfs         f6, 0(r3)
  /* 80518648 C0640004 */ lfs         f3, 4(r4)
  /* 8051864C C0440000 */ lfs         f2, 0(r4)
  /* 80518650 EFE41828 */ fsubs       f31, f4, f3
  /* 80518654 C0A30008 */ lfs         f5, 8(r3)
  /* 80518658 EDA61028 */ fsubs       f13, f6, f2
  /* 8051865C C0440008 */ lfs         f2, 8(r4)
  /* 80518660 D0810030 */ stfs        f4, 0x30(r1)
  /* 80518664 EFC51028 */ fsubs       f30, f5, f2
  /* 80518668 EC6B0372 */ fmuls       f3, f11, f13
  /* 8051866C D0C1002C */ stfs        f6, 0x2c(r1)
  /* 80518670 EC4A07F2 */ fmuls       f2, f10, f31
  /* 80518674 EC8C07B2 */ fmuls       f4, f12, f30
  /* 80518678 D0A10034 */ stfs        f5, 0x34(r1)
  /* 8051867C EC43102A */ fadds       f2, f3, f2
  /* 80518680 D1A10020 */ stfs        f13, 0x20(r1)
  /* 80518684 D3E10024 */ stfs        f31, 0x24(r1)
  /* 80518688 EFA4102A */ fadds       f29, f4, f2
  /* 8051868C D3C10028 */ stfs        f30, 0x28(r1)
  /* 80518690 FC1D4840 */ opword      0xfc1d4840
  /* 80518694 4C411382 */ cror        2, 1, 2
  /* 80518698 4082007C */ bne-        lbl_80518714
  /* 8051869C C0410044 */ lfs         f2, 0x44(r1)
  /* 805186A0 ED1D0072 */ fmuls       f8, f29, f1
  /* 805186A4 C0810048 */ lfs         f4, 0x48(r1)
  /* 805186A8 C0610038 */ lfs         f3, 0x38(r1)
  /* 805186AC ECC20372 */ fmuls       f6, f2, f13
  /* 805186B0 C041003C */ lfs         f2, 0x3c(r1)
  /* 805186B4 ECA407F2 */ fmuls       f5, f4, f31
  /* 805186B8 EC630372 */ fmuls       f3, f3, f13
  /* 805186BC C0E1004C */ lfs         f7, 0x4c(r1)
  /* 805186C0 EC4207F2 */ fmuls       f2, f2, f31
  /* 805186C4 C0810040 */ lfs         f4, 0x40(r1)
  /* 805186C8 ECE707B2 */ fmuls       f7, f7, f30
  /* 805186CC ECA6282A */ fadds       f5, f6, f5
  /* 805186D0 EC43102A */ fadds       f2, f3, f2
  /* 805186D4 EC8407B2 */ fmuls       f4, f4, f30
  /* 805186D8 EC67282A */ fadds       f3, f7, f5
  /* 805186DC ECA80232 */ fmuls       f5, f8, f8
  /* 805186E0 EC44102A */ fadds       f2, f4, f2
  /* 805186E4 EC6300F2 */ fmuls       f3, f3, f3
  /* 805186E8 EC4200B2 */ fmuls       f2, f2, f2
  /* 805186EC EC43102A */ fadds       f2, f3, f2
  /* 805186F0 FC022840 */ opword      0xfc022840
  /* 805186F4 40800020 */ bge-        lbl_80518714
  /* 805186F8 5500063E */ clrlwi      r0, r8, 0x18
  /* 805186FC 280000FF */ cmplwi      r0, 0xff
  /* 80518700 4182000C */ beq-        lbl_8051870c
  /* 80518704 FC1D0040 */ opword      0xfc1d0040
  /* 80518708 4080000C */ bge-        lbl_80518714
  lbl_8051870c:
  /* 8051870C FC00E890 */ fmr         f0, f29
  /* 80518710 7D284B78 */ mr          r8, r9
  lbl_80518714:
  /* 80518714 39290001 */ addi        r9, r9, 0x1
  lbl_80518718:
  /* 80518718 2C050000 */ cmpwi       r5, 0x0
  /* 8051871C 5524063E */ clrlwi      r4, r9, 0x18
  /* 80518720 4182000C */ beq-        lbl_8051872c
  /* 80518724 38000000 */ li          r0, 0x0
  /* 80518728 4800000C */ b           lbl_80518734
  lbl_8051872c:
  /* 8051872C 80670010 */ lwz         r3, 0x10(r7)
  /* 80518730 A0030004 */ lhz         r0, 4(r3)
  lbl_80518734:
  /* 80518734 7C040000 */ cmpw        r4, r0
  /* 80518738 4180FEAC */ blt+        lbl_805185e4
  /* 8051873C 5500063E */ clrlwi      r0, r8, 0x18
  /* 80518740 280000FF */ cmplwi      r0, 0xff
  /* 80518744 40820008 */ bne-        lbl_8051874c
  /* 80518748 39000000 */ li          r8, 0x0
  lbl_8051874c:
  /* 8051874C 991E0028 */ stb         r8, 0x28(r30)
  /* 80518750 3C60809C */ lis         r3, spInstance__Q26System9CourseMap@ha
  /* 80518754 C01F0198 */ lfs         f0, 0x198(r31)
  /* 80518758 390000FF */ li          r8, 0xff
  /* 8051875C 80E3D6E8 */ lwz         r7, spInstance__Q26System9CourseMap@l(r3)
  /* 80518760 39200000 */ li          r9, 0x0
  /* 80518764 C1810058 */ lfs         f12, 0x58(r1)
  /* 80518768 80C70018 */ lwz         r6, 0x18(r7)
  /* 8051876C C1610050 */ lfs         f11, 0x50(r1)
  /* 80518770 7CC00034 */ cntlzw      r0, r6
  /* 80518774 C1410054 */ lfs         f10, 0x54(r1)
  /* 80518778 C13F0154 */ lfs         f9, 0x154(r31)
  /* 8051877C 5405D97E */ srwi        r5, r0, 5
  /* 80518780 48000138 */ b           lbl_805188b8
  lbl_80518784:
  /* 80518784 2C060000 */ cmpwi       r6, 0x0
  /* 80518788 5524063E */ clrlwi      r4, r9, 0x18
  /* 8051878C 41820010 */ beq-        lbl_8051879c
  /* 80518790 80670018 */ lwz         r3, 0x18(r7)
  /* 80518794 A0030004 */ lhz         r0, 4(r3)
  /* 80518798 48000008 */ b           lbl_805187a0
  lbl_8051879c:
  /* 8051879C 38000000 */ li          r0, 0x0
  lbl_805187a0:
  /* 805187A0 7C040040 */ cmplw       r4, r0
  /* 805187A4 40800030 */ bge-        lbl_805187d4
  /* 805187A8 80870018 */ lwz         r4, 0x18(r7)
  /* 805187AC 5523063E */ clrlwi      r3, r9, 0x18
  /* 805187B0 A0040004 */ lhz         r0, 4(r4)
  /* 805187B4 7C030040 */ cmplw       r3, r0
  /* 805187B8 40800014 */ bge-        lbl_805187cc
  /* 805187BC 80640000 */ lwz         r3, 0(r4)
  /* 805187C0 552015BA */ rlwinm      r0, r9, 2, 0x16, 0x1d
  /* 805187C4 7C63002E */ lwzx        r3, r3, r0
  /* 805187C8 48000010 */ b           lbl_805187d8
  lbl_805187cc:
  /* 805187CC 38600000 */ li          r3, 0x0
  /* 805187D0 48000008 */ b           lbl_805187d8
  lbl_805187d4:
  /* 805187D4 38600000 */ li          r3, 0x0
  lbl_805187d8:
  /* 805187D8 80630000 */ lwz         r3, 0(r3)
  /* 805187DC 809E0000 */ lwz         r4, 0(r30)
  /* 805187E0 C0830004 */ lfs         f4, 4(r3)
  /* 805187E4 C0C30000 */ lfs         f6, 0(r3)
  /* 805187E8 C0640004 */ lfs         f3, 4(r4)
  /* 805187EC C0440000 */ lfs         f2, 0(r4)
  /* 805187F0 EFC41828 */ fsubs       f30, f4, f3
  /* 805187F4 C0A30008 */ lfs         f5, 8(r3)
  /* 805187F8 EDA61028 */ fsubs       f13, f6, f2
  /* 805187FC C0440008 */ lfs         f2, 8(r4)
  /* 80518800 D0810018 */ stfs        f4, 0x18(r1)
  /* 80518804 EFE51028 */ fsubs       f31, f5, f2
  /* 80518808 EC6B0372 */ fmuls       f3, f11, f13
  /* 8051880C D0C10014 */ stfs        f6, 0x14(r1)
  /* 80518810 EC4A07B2 */ fmuls       f2, f10, f30
  /* 80518814 EC8C07F2 */ fmuls       f4, f12, f31
  /* 80518818 D0A1001C */ stfs        f5, 0x1c(r1)
  /* 8051881C EC43102A */ fadds       f2, f3, f2
  /* 80518820 D1A10008 */ stfs        f13, 8(r1)
  /* 80518824 D3C1000C */ stfs        f30, 0xc(r1)
  /* 80518828 EFA4102A */ fadds       f29, f4, f2
  /* 8051882C D3E10010 */ stfs        f31, 0x10(r1)
  /* 80518830 FC1D4840 */ opword      0xfc1d4840
  /* 80518834 4C411382 */ cror        2, 1, 2
  /* 80518838 4082007C */ bne-        lbl_805188b4
  /* 8051883C C0410044 */ lfs         f2, 0x44(r1)
  /* 80518840 ED1D0072 */ fmuls       f8, f29, f1
  /* 80518844 C0810048 */ lfs         f4, 0x48(r1)
  /* 80518848 C0610038 */ lfs         f3, 0x38(r1)
  /* 8051884C ECC20372 */ fmuls       f6, f2, f13
  /* 80518850 C041003C */ lfs         f2, 0x3c(r1)
  /* 80518854 ECA407B2 */ fmuls       f5, f4, f30
  /* 80518858 EC630372 */ fmuls       f3, f3, f13
  /* 8051885C C0E1004C */ lfs         f7, 0x4c(r1)
  /* 80518860 EC4207B2 */ fmuls       f2, f2, f30
  /* 80518864 C0810040 */ lfs         f4, 0x40(r1)
  /* 80518868 ECE707F2 */ fmuls       f7, f7, f31
  /* 8051886C ECA6282A */ fadds       f5, f6, f5
  /* 80518870 EC43102A */ fadds       f2, f3, f2
  /* 80518874 EC8407F2 */ fmuls       f4, f4, f31
  /* 80518878 EC67282A */ fadds       f3, f7, f5
  /* 8051887C ECA80232 */ fmuls       f5, f8, f8
  /* 80518880 EC44102A */ fadds       f2, f4, f2
  /* 80518884 EC6300F2 */ fmuls       f3, f3, f3
  /* 80518888 EC4200B2 */ fmuls       f2, f2, f2
  /* 8051888C EC43102A */ fadds       f2, f3, f2
  /* 80518890 FC022840 */ opword      0xfc022840
  /* 80518894 40800020 */ bge-        lbl_805188b4
  /* 80518898 5500063E */ clrlwi      r0, r8, 0x18
  /* 8051889C 280000FF */ cmplwi      r0, 0xff
  /* 805188A0 4182000C */ beq-        lbl_805188ac
  /* 805188A4 FC1D0040 */ opword      0xfc1d0040
  /* 805188A8 4080000C */ bge-        lbl_805188b4
  lbl_805188ac:
  /* 805188AC FC00E890 */ fmr         f0, f29
  /* 805188B0 7D284B78 */ mr          r8, r9
  lbl_805188b4:
  /* 805188B4 39290001 */ addi        r9, r9, 0x1
  lbl_805188b8:
  /* 805188B8 2C050000 */ cmpwi       r5, 0x0
  /* 805188BC 5524063E */ clrlwi      r4, r9, 0x18
  /* 805188C0 4182000C */ beq-        lbl_805188cc
  /* 805188C4 38000000 */ li          r0, 0x0
  /* 805188C8 4800000C */ b           lbl_805188d4
  lbl_805188cc:
  /* 805188CC 80670018 */ lwz         r3, 0x18(r7)
  /* 805188D0 A0030004 */ lhz         r0, 4(r3)
  lbl_805188d4:
  /* 805188D4 7C040000 */ cmpw        r4, r0
  /* 805188D8 4180FEAC */ blt+        lbl_80518784
  /* 805188DC 5500063E */ clrlwi      r0, r8, 0x18
  /* 805188E0 280000FF */ cmplwi      r0, 0xff
  /* 805188E4 40820008 */ bne-        lbl_805188ec
  /* 805188E8 39000000 */ li          r8, 0x0
  lbl_805188ec:
  /* 805188EC 991E0029 */ stb         r8, 0x29(r30)
  /* 805188F0 E3E100A8 */ opword      0xe3e100a8
  /* 805188F4 CBE100A0 */ lfd         f31, 0xa0(r1)
  /* 805188F8 E3C10098 */ opword      0xe3c10098
  /* 805188FC CBC10090 */ lfd         f30, 0x90(r1)
  /* 80518900 E3A10088 */ opword      0xe3a10088
  /* 80518904 CBA10080 */ lfd         f29, 0x80(r1)
  /* 80518908 83E1007C */ lwz         r31, 0x7c(r1)
  /* 8051890C 83C10078 */ lwz         r30, 0x78(r1)
  /* 80518910 800100B4 */ lwz         r0, 0xb4(r1)
  /* 80518914 7C0803A6 */ mtlr        r0
  /* 80518918 382100B0 */ addi        r1, r1, 0xb0
  /* 8051891C 4E800020 */ blr
  // clang-format on
}

namespace System {

MapdataJugemPoint* CourseMap::getJugemPoint(u16 i) const {
  u16 count = mpJugemPoint ? mpJugemPoint->size() : 0;
  return i < count ? mpJugemPoint->get(i) : 0;
}

} // namespace System

// Symbol: unk_8051896c
// PAL: 0x8051896c..0x80518ab8
MARK_BINARY_BLOB(unk_8051896c, 0x8051896c, 0x80518ab8);
asm UNKNOWN_FUNCTION(unk_8051896c) {
  // clang-format off
  nofralloc
  /* 8051896C 9421FFA0 */ stwu        r1, -0x60(r1)
  /* 80518970 7C0802A6 */ mflr        r0
  /* 80518974 90010064 */ stw         r0, 0x64(r1)
  /* 80518978 39610060 */ addi        r11, r1, 0x60
  /* 8051897C 4BB08C21 */ bl          _savegpr_26
  /* 80518980 3CC0809C */ lis         r6, spInstance__Q26System10RaceConfig@ha
  /* 80518984 3FA08089 */ lis         r29, lbl_8088f8e8@ha
  /* 80518988 80C6D728 */ lwz         r6, spInstance__Q26System10RaceConfig@l(r6)
  /* 8051898C 7C7A1B78 */ mr          r26, r3
  /* 80518990 7C9B2378 */ mr          r27, r4
  /* 80518994 3BBDF8E8 */ addi        r29, r29, lbl_8088f8e8@l
  /* 80518998 80060B70 */ lwz         r0, 0xb70(r6)
  /* 8051899C 2C000002 */ cmpwi       r0, 0x2
  /* 805189A0 4182000C */ beq-        lbl_805189ac
  /* 805189A4 2C000005 */ cmpwi       r0, 0x5
  /* 805189A8 40820008 */ bne-        lbl_805189b0
  lbl_805189ac:
  /* 805189AC 38A000FF */ li          r5, 0xff
  lbl_805189b0:
  /* 805189B0 280500FF */ cmplwi      r5, 0xff
  /* 805189B4 418200D0 */ beq-        lbl_80518a84
  /* 805189B8 54BC0DFC */ rlwinm      r28, r5, 1, 0x17, 0x1e
  /* 805189BC 3BDD0120 */ addi        r30, r29, 0x120
  /* 805189C0 7C1EE0AE */ lbzx        r0, r30, r28
  /* 805189C4 3FE04330 */ lis         r31, 0x4330
  /* 805189C8 93E10038 */ stw         r31, 0x38(r1)
  /* 805189CC 38610020 */ addi        r3, r1, 0x20
  /* 805189D0 7C000774 */ extsb       r0, r0
  /* 805189D4 C85D0168 */ lfd         f2, 0x168(r29)
  /* 805189D8 6C008000 */ xoris       r0, r0, 0x8000
  /* 805189DC 9001003C */ stw         r0, 0x3c(r1)
  /* 805189E0 C01D019C */ lfs         f0, 0x19c(r29)
  /* 805189E4 389A001C */ addi        r4, r26, 0x1c
  /* 805189E8 C8210038 */ lfd         f1, 0x38(r1)
  /* 805189EC EC211028 */ fsubs       f1, f1, f2
  /* 805189F0 EC200072 */ fmuls       f1, f0, f1
  /* 805189F4 480000C5 */ bl          Vec3_fromScale
  /* 805189F8 7C7EE214 */ add         r3, r30, r28
  /* 805189FC 93E10040 */ stw         r31, 0x40(r1)
  /* 80518A00 88030001 */ lbz         r0, 1(r3)
  /* 80518A04 38610014 */ addi        r3, r1, 0x14
  /* 80518A08 C85D0168 */ lfd         f2, 0x168(r29)
  /* 80518A0C 389A0010 */ addi        r4, r26, 0x10
  /* 80518A10 7C000774 */ extsb       r0, r0
  /* 80518A14 C01D01A0 */ lfs         f0, 0x1a0(r29)
  /* 80518A18 6C008000 */ xoris       r0, r0, 0x8000
  /* 80518A1C 90010044 */ stw         r0, 0x44(r1)
  /* 80518A20 C8210040 */ lfd         f1, 0x40(r1)
  /* 80518A24 EC211028 */ fsubs       f1, f1, f2
  /* 80518A28 EC200072 */ fmuls       f1, f0, f1
  /* 80518A2C 4800008D */ bl          Vec3_fromScale
  /* 80518A30 38610008 */ addi        r3, r1, 0x8
  /* 80518A34 38810020 */ addi        r4, r1, 0x20
  /* 80518A38 38A10014 */ addi        r5, r1, 0x14
  /* 80518A3C 4BFFBDFD */ bl          Vec3_add
  /* 80518A40 807A0000 */ lwz         r3, 0(r26)
  /* 80518A44 C0A10008 */ lfs         f5, 8(r1)
  /* 80518A48 C081000C */ lfs         f4, 0xc(r1)
  /* 80518A4C C0610010 */ lfs         f3, 0x10(r1)
  /* 80518A50 C0430008 */ lfs         f2, 8(r3)
  /* 80518A54 C0230004 */ lfs         f1, 4(r3)
  /* 80518A58 C0030000 */ lfs         f0, 0(r3)
  /* 80518A5C EC42182A */ fadds       f2, f2, f3
  /* 80518A60 EC21202A */ fadds       f1, f1, f4
  /* 80518A64 D0A1002C */ stfs        f5, 0x2c(r1)
  /* 80518A68 EC00282A */ fadds       f0, f0, f5
  /* 80518A6C D0810030 */ stfs        f4, 0x30(r1)
  /* 80518A70 D0610034 */ stfs        f3, 0x34(r1)
  /* 80518A74 D01B0000 */ stfs        f0, 0(r27)
  /* 80518A78 D03B0004 */ stfs        f1, 4(r27)
  /* 80518A7C D05B0008 */ stfs        f2, 8(r27)
  /* 80518A80 48000020 */ b           lbl_80518aa0
  lbl_80518a84:
  /* 80518A84 80630000 */ lwz         r3, 0(r3)
  /* 80518A88 C0430008 */ lfs         f2, 8(r3)
  /* 80518A8C C0230004 */ lfs         f1, 4(r3)
  /* 80518A90 C0030000 */ lfs         f0, 0(r3)
  /* 80518A94 D0040000 */ stfs        f0, 0(r4)
  /* 80518A98 D0240004 */ stfs        f1, 4(r4)
  /* 80518A9C D0440008 */ stfs        f2, 8(r4)
  lbl_80518aa0:
  /* 80518AA0 39610060 */ addi        r11, r1, 0x60
  /* 80518AA4 4BB08B45 */ bl          _restgpr_26
  /* 80518AA8 80010064 */ lwz         r0, 0x64(r1)
  /* 80518AAC 7C0803A6 */ mtlr        r0
  /* 80518AB0 38210060 */ addi        r1, r1, 0x60
  /* 80518AB4 4E800020 */ blr
  // clang-format on
}

// Symbol: Vec3_fromScale
// PAL: 0x80518ab8..0x80518ae0
MARK_BINARY_BLOB(Vec3_fromScale, 0x80518ab8, 0x80518ae0);
asm UNKNOWN_FUNCTION(Vec3_fromScale) {
  // clang-format off
  nofralloc
  /* 80518AB8 C0640008 */ lfs         f3, 8(r4)
  /* 80518ABC C0440004 */ lfs         f2, 4(r4)
  /* 80518AC0 C0040000 */ lfs         f0, 0(r4)
  /* 80518AC4 EC630072 */ fmuls       f3, f3, f1
  /* 80518AC8 EC420072 */ fmuls       f2, f2, f1
  /* 80518ACC EC000072 */ fmuls       f0, f0, f1
  /* 80518AD0 D0630008 */ stfs        f3, 8(r3)
  /* 80518AD4 D0030000 */ stfs        f0, 0(r3)
  /* 80518AD8 D0430004 */ stfs        f2, 4(r3)
  /* 80518ADC 4E800020 */ blr
  // clang-format on
}

namespace System {

MapdataCannonPoint* CourseMap::getCannonPoint(u16 i) const {
  u16 count = mpCannonPoint ? mpCannonPoint->size() : 0;
  return i < count ? mpCannonPoint->get(i) : 0;
}

MapdataMissionPoint* CourseMap::getMissionPoint(u16 i) const {
  u16 count = mpMissionPoint ? mpMissionPoint->size() : 0;
  return i < count ? mpMissionPoint->get(i) : 0;
}

MapdataStage* CourseMap::getStage() const {
  if (mpStageInfo && mpStageInfo->size() != 0) {
    return mpStageInfo->get(0);
  }

  return nullptr;
}

u8 MapdataStage::getFlareAlpha() const {
  return CourseMap::instance()->getVersion() > 2320 ? mpData->mFlareAlpha : 75;
}

MapdataAreaAccessor::~MapdataAreaAccessor() { delete[] byPriority; }

MapdataEnemyPoint::~MapdataEnemyPoint() {
  if (_08)
    delete[] _08;

  if (_0c)
    delete[] _0c;
}

} // namespace System
