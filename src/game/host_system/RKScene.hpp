#pragma once

#include <egg/core/eggExpHeap.hpp>
#include <egg/core/eggScene.hpp>

// TODO: These likely align with the resource archives in Scene\UI

//! Unique game scene IDs
enum RKSceneID {
  SCENE_UNK3 = 3,
  SCENE_UNK6 = 6,
  SCENE_UNK7 = 7,
  SCENE_UNK8 = 8,
  SCENE_UNK9 = 9,
  SCENE_UNK10 = 10,
  SCENE_UNK11 = 11,

  // --- <SceneCreatorREL>
  RK_SCENE_ID_GAME_START = 0, //!< Called when REL first loaded; "Title" might
                              //!< be a more fitting name*
  RK_SCENE_ID_MAIN_MENU = 1,  //!< "メニューシーン" -> "Menu Scene"
  RK_SCENE_ID_RACE = 2,       //!< "レースシーン" -> "Race Scene"

  RK_SCENE_ID_MULTI = 4, //!< "地球儀シーン" -> "Globe Scene"

  // --- <SceneCreatorStatic>
  RK_SCENE_ID_BOOTSTRAP =
      5, //!< Root scene loaded immediately after initializing the system.
  // --- </SceneCreatorStatic>

  RK_SCENE_ID_FLAG_OPEN = 12 //!< "フラグオープンシーン" -> "Flag Open Scene"
  // --- </SceneCreatorREL>
};

//! Certain heap allocations are tracked to a given memory budgeting category.
enum RKHeapTag {
  RK_HEAP_TAG_DEFAULT = 0x0,
  RK_HEAP_TAG_RACE_DATA = 0x1,
  RK_HEAP_TAG_MISC_SINGLETON = 0x2, // Rendering?
  RK_HEAP_TAG_3 = 0x3,
  RK_HEAP_TAG_RACE_GEO_OBJ = 0x4,
  RK_HEAP_TAG_RACE_JMAP_AND_MDL = 0x5,
  RK_HEAP_TAG_MENU = 0x6,
  RK_HEAP_TAG_EFFECT = 0x7,
  RK_HEAP_TAG_AUDIO = 0x8,
  RK_HEAP_TAG_9 = 0x9,
  RK_HEAP_TAG_RES = 0xA,
  RK_HEAP_TAG_HBM = 0xB,
  RK_HEAP_TAG_12 = 0xC,
  RK_HEAP_TAG_NETWORKING = 0xD
};

struct HeapCollection {
  enum eHeapId { HEAP_ID_MEM1, HEAP_ID_MEM2, HEAP_ID_DEBUG, HEAP_ID_NUM };
  EGG::ExpHeap* mpHeaps[HEAP_ID_NUM];
  EGG::ExpHeap::GroupSizeRecord mRecords[HEAP_ID_NUM];

  void setGroupIdAll(s32 id); // RKHeapTag

  inline HeapCollection() {
    mpHeaps[HeapCollection::HEAP_ID_MEM1] = NULL;
    mpHeaps[HeapCollection::HEAP_ID_MEM2] = NULL;
    mpHeaps[HeapCollection::HEAP_ID_DEBUG] = NULL;
  }
};

class RKScene : public EGG::Scene {
public:
  virtual ~RKScene() override {}
  inline RKScene() { setHeaps(); }
  inline void dummy(EGG::ExpHeap*);
  inline void setHeaps() {
    EGG::ExpHeap* a[3];

    a[0] = downcast(getA());
    a[1] = downcast(getB());
    a[2] = downcast(getC());
    setm1(a[0]);
    setm2(a[1]);
    setd(a[2]);
  }
  inline EGG::Heap* getA() {
    return mHeapCollection.mpHeaps[HeapCollection::HEAP_ID_MEM1];
  }
  inline EGG::Heap* getB() {
    return mHeapCollection.mpHeaps[HeapCollection::HEAP_ID_MEM2];
  }
  inline EGG::Heap* getC() {
    return mHeapCollection.mpHeaps[HeapCollection::HEAP_ID_DEBUG];
  }
  inline EGG::ExpHeap* getDbgHeap() {
    return downcast(mHeapCollection.mpHeaps[HeapCollection::HEAP_ID_DEBUG]);
  }
  inline void setm1(EGG::ExpHeap* a) {
    mHeapCollection.mpHeaps[HeapCollection::HEAP_ID_MEM1] = a;
  }
  inline void setm2(EGG::ExpHeap* a) {
    mHeapCollection.mpHeaps[HeapCollection::HEAP_ID_MEM2] = a;
  }
  inline void setd(EGG::ExpHeap* a) {
    mHeapCollection.mpHeaps[HeapCollection::HEAP_ID_DEBUG] = a;
  }
  // Perhaps not the best spot
  inline EGG::ExpHeap* downcast(EGG::Heap* pHeap) {
    if (pHeap && pHeap->getHeapKind() == EGG::Heap::HEAP_KIND_EXPANDED)
      return reinterpret_cast<EGG::ExpHeap*>(pHeap);
    else
      return 0;
  }
  HeapCollection mHeapCollection; // 0x30
  // 0xc3c
  unk8 _c3c[0xc70 - 0xc3c];
};
