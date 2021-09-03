/*!
 * @file
 * @brief TODO
 */

#pragma once

#include <egg/core/eggDisposer.hpp>
#include <egg/core/eggHeap.hpp>
#include <rk_types.h>

namespace EGG {

class SceneManager;

// HACK: Only the first instance of this symbol will be kept
#ifndef EGGSCENE_INLINEBODY
#define EGGSCENE_INLINEBODY ;
#else
#undef EGGSCENE_INLINEBODY
#define EGGSCENE_INLINEBODY                                                    \
  {}
#endif

class Scene : public Disposer {
public:
  virtual ~Scene(); //! [vt+0x08] Virtual destructor.

  virtual void calc() EGGSCENE_INLINEBODY                      //! [vt+0x0C]
      virtual void draw() EGGSCENE_INLINEBODY                  //! [vt+0x10]
      virtual void enter() EGGSCENE_INLINEBODY                 //! [vt+0x14]
      virtual void exit() EGGSCENE_INLINEBODY                  //! [vt+0x18]
      virtual void reinit() EGGSCENE_INLINEBODY                //! [vt+0x1C]
      virtual void incoming_childDestroy() EGGSCENE_INLINEBODY //! [vt+0x20]
      virtual void outgoing_childCreate() EGGSCENE_INLINEBODY  //! [vt+0x24]

      //! @brief Constructor
      Scene();

private:
  // -- vt + inherited mContainHeap from Disposer --
  // int _08;    // TODO get name from SceneManager usage
  // Scene* _0C; // TODO get name from SceneManager usage

  Heap* _10; // something like mCreatorHeap? set to Heap::sCurrentHeap in ct
  Heap* mHeapMem1;  //!< [+0x14]
  Heap* mHeapMem2;  //!< [+0x18]
  Heap* mHeapDebug; //!< [+0x1C]

  Scene* pParentScene; //!< [+0x20] name from @see SceneManager::createScene
  Scene* pChildScene;  //!< [+0x24] If non null, destroyed too in destroyScene.
                      //!< childscene?. name from @see SceneManager::createScene

  int mID;                 //!< [+0x28]
  SceneManager* pSceneMgr; //!< [+0x2C] @see SceneManager::createScene

public:
  // inlines. actually above exit and below enter
  inline void setSceneMgr(SceneManager* mgr) { this->pSceneMgr = mgr; }
  inline void setParentScene(Scene* scene) { this->pParentScene = scene; }
  inline void setSceneID(int ID) { this->mID = ID; }
  inline void setChildScene(Scene* scene) { pChildScene = scene; }

  inline const Scene* getParentScene() const { return pParentScene; }
  inline Scene* getParentScene() { return pParentScene; }

  inline int getSceneID() const { return mID; }

  inline const Heap* getHeap() const { return _10; }
  inline Heap* getHeap() { return _10; }

  inline const Heap* getHeap_Mem1() const { return mHeapMem1; }
  inline Heap* getHeap_Mem1() { return mHeapMem1; }

  inline const Scene* getChildScene() const { return pChildScene; }
  inline Scene* getChildScene() { return pChildScene; }

  inline const SceneManager* getSceneMgr() const { return pSceneMgr; }
  inline SceneManager* getSceneMgr() { return pSceneMgr; }

  inline const Heap* getHeap_Mem2() const { return mHeapMem2; }
  inline Heap* getHeap_Mem2() { return mHeapMem2; }

  // not yet found in symbol maps, but needed
  inline const Heap* getHeap_Debug() const { return mHeapDebug; }
  inline Heap* getHeap_Debug() { return mHeapDebug; }
};

} // namespace EGG
