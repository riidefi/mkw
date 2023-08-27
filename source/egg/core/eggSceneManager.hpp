#pragma once

#include <egg/core/eggColorFader.hpp>
#include <egg/core/eggScene.hpp>
#include <rk_types.h>

namespace EGG {

class SceneCreator {
public:
  virtual Scene*
  create(int SceneID); //!< [vt+0x08] @see SceneManager::createScene
  virtual void destroy(int SceneID); //!< [vt+0x0C]
};

class SceneManager {
public:
  // -1 -> idle?
  // 3  -> fading out (can see game -> black)
  enum eAfterFadeType {
    STATUS_IDLE = -1, // guess
    // big logic
    STATUS_CHANGE_SCENE = 0,
    // destroyScene then
    // set in changeSiblingSceneAfterFadeOut
    //! [1] Change to a sibling scene @see changeSIblingSceneAfterFadeOut,
    //! calcCurrentFader
    STATUS_CHANGE_SIBLING_SCENE = 1,
    // createScene with _18 and _10
    STATUS_OUTGOING = 2,
    //! [3] When set, in calcFader, reinitCurrentScene
    STATUS_REINITIALIZE = 3,
    STATUS_INCOMING = 4
  };

public: // .sbss
  //! @brief Option to use when creating Scene ExpHeaps
  static u16 sHeapOptionFlg;
  static Heap* sHeapMem1_ForCreateScene;
  static Heap* sHeapMem2_ForCreateScene;
  static Heap* sHeapDebug_ForCreateScene;

public:
  //! @brief [vt+0x08] Calculate the current fader and scene.
  //!
  virtual void calc();

  //! @brief [vt+0x0C] Draw the current fader and scene.
  //!
  virtual void draw();

  //! @brief [vt+0x10] Calculate the current scene.
  //!
  virtual void calcCurrentScene();

  //! @brief [vt+0x14] Calculate the current fader and post-fade operations.
  //! Overrided implementations must also implement all post-fade status
  //! handling.
  //!
  virtual void calcCurrentFader();

  //! @brief [vt+0x18] Draws the current scene.
  //!
  virtual void drawCurrentScene();

  //! @brief [vt+0x1C] Draw the current fader if it exists, otherwise do
  //! nothing.
  //!
  virtual void drawCurrentFader();

  //! @brief [vt+0x20] Create the default fader for this manager
  //!
  //! @details Default fader spans from (0,0) to (640,480), is pure black, and
  //! is configured in the OPAQUE state
  //!
  virtual void createDefaultFader();

public:
  //! @brief		Constructor
  //!
  //! @param[in]	creator Scene creator to use for this manager when
  //! creating new scenes.
  //!
  //! @remarks	Nintendo appears to never use this argument, opting instead to
  //! set it later directly. Whether this was with an inline setter or not we'll
  //! never know.
  //!
  SceneManager(SceneCreator* creator);

  //! @brief Fade into the scene
  //!
  //! @pre mCurrentFader *must* be set.
  //!
  //! @returns Whether or not the operation did anything.
  //!
  bool fadeIn();

  //! @brief Fade out of the scene
  //!
  //! @pre mCurrentFader *must* be set.
  //!
  //! @returns Whether or not the operation did anything.
  //!
  bool fadeOut();

  //! @brief Re-initialize current scene
  //!
  //! @pre mCurrentScene is not NULL.
  //!
  void reinitCurrentScene();

  //! @brief Fade out, and set the status flag to reinitialize the current scene
  //! the next frame
  //!
  //! @pre
  //!		- mTransitionStatus is STATUS_IDLE.
  //!		- mCurrentFader *must* not be null. (not checked)
  //!		- The screen is not fading or blocked. (mCurrentFader->mStatus
  //!== ESTATUS_HIDDEN
  //!
  //! @returns Whether or not the operation was successful (including fading
  //! out)
  //!
  bool reinitCurrentSceneAfterFadeOut();

  //! @brief Destroy the current scene, then manuever to a sibling of the
  //! parent.
  //!
  //! @param[in] ID Scene ID to switch to after destroying current scene
  //! completely.
  //!
  void changeScene(int ID);

  //! @brief Change to a sibling scene with the specified ID.
  //!
  //! @param[in] ID Scene ID of sibling to switch to. Must have same parent.
  //!
  void changeSiblingScene(int ID);

  //! @brief Fade out, and set the status flag to change the current scene the
  //! next frame
  //!
  //! @param[in] ID Scene ID to switch to after destroying current scene
  //! completely.
  //!
  bool changeSiblingSceneAfterFadeOut(int ID);

  //! @brief Change to a sibling scene specified by mNextSceneID.
  //!
  //! @pre
  //!		- mCurrentScene is not NULL. (checked)
  //!		- mParentScene is not NULL. (checked in createScene).
  //!
  void changeSiblingScene();

  //! @brief Create a scene with the specified ID and parent.
  //!
  //! @param[in] ID ID of scene to create.
  //! @param[in] pParentScene Pointer to scene parent (NULL if root).
  //!
  //! @pre System heaps are initialized if root, otherwise parent heaps must be
  //! initialized.
  //!
  void createScene(int ID, Scene* pParentScene);

  //! @brief Create a child scene with the specified ID and parent.
  //!
  //! @param[in] ID ID of child scene to create.
  //! @param[in] pParentScene Pointer to scene parent (NULL if root).
  //!
  //! @pre System heaps are initialized if root, otherwise parent heaps must be
  //! initialized.
  //!
  void createChildScene(int ID, Scene* pScene);

  //! @brief Destroy the current scene and optionally switch to a NULL scene.
  //!
  //! @param[in] destroyRootIfNoParent If the current scene does not have a
  //! parent, should this function still proceed. If false and the scene has no
  //! parent, nothing will be done.
  //!
  //! @pre mCurrentScene is not NULL. (checked)
  //!
  //! @returns Whether or not operations succeeed. If the current scene or
  //! current scene parent is NULL, false.
  //!
  bool destroyCurrentSceneNoIncoming(bool destroyRootIfNoParent);

  //! @brief Climb up parent links, setting the current scene to the ID matched
  //! scene.
  //!
  //! @param[in] ID of the scene to find. This must exist in the parent links as
  //! a parent, grandparent, etc.
  //!
  //! @pre findParentScene preconditions and a valid parent/grandparent/etc has
  //! the ID specified.
  //!
  bool destroyToSelectSceneID(int ID);

  //! @brief Destroy the scene pScene and all children recursively.
  //!
  //! @param[in] pScene Scene to destroy.
  //!
  //! @remarks The GP is flushed and synced after major changes.
  //!
  void destroyScene(Scene* pScene);

  //! @brief If mCurrentScene set, call the respective virtual function for an
  //! incoming child creation.
  //!
  void incomingCurrentScene();

  //! @brief Set the scene indices based on mNextSceneID for creation.
  //!
  void setupNextSceneID();

  //! @brief If mCurrentScene set, call the respective virtual function for an
  //! outgoing child creation.
  void outgoingParentScene(Scene* pScene);

  //! @brief	Search up parent links from the current scene to the root
  //!			for a parent scene that matches ID.
  //!
  //!	@param[in] ID Target ID of parent to find.
  //!
  //! @returns Pointer to found parent scene, otherwise NULL.
  //!
  Scene* findParentScene(int ID);

public:
  //! @brief Create a child scene with the specified ID.
  //!
  //! @param[in] ID ID of child scene to create.
  //!
  //! @pre Calls createChildScene with the current scene.
  //!
  inline void createChildSceneCurrent(int ID) {
    createChildScene(ID, getCurrentScene());
  }

  //! @brief Resets the transition status to idle.
  //!
  inline void resetAfterFadeType() { mTransitionStatus = STATUS_IDLE; }

  //! @brief Gets the current scene.
  //!
  inline Scene* getCurrentScene() const { return mCurrentScene; }

  inline int getCurrentSceneID() const { return mCurrentSceneID; }

  inline Scene* getParentScene() const { return pParent; }

  inline ColorFader* getCurrentFader() const { return mCurrentFader; }

  static inline EGG::Heap* getHeapForCreateScene_Mem1() {
    return sHeapMem1_ForCreateScene;
  }

  static inline EGG::Heap* getHeapForCreateScene_Mem2() {
    return sHeapMem2_ForCreateScene;
  }

  static inline EGG::Heap* getHeapForCreateScene_Debug() {
    return sHeapDebug_ForCreateScene;
  }

  inline int getNextSceneID() { return mNextSceneID; }

  inline void setAfterFadeType(eAfterFadeType type) {
    mTransitionStatus = type;
  }

  inline eAfterFadeType getAfterFadeType() { return mTransitionStatus; }

  inline void setCreator(SceneCreator* creator) { mSceneCreator = creator; }

  inline void setNextSceneID(int ID) { mNextSceneID = ID; }

private:
  SceneCreator* mSceneCreator; //!< [+0x04]
  u32 _08;                     // unseen

  Scene* mCurrentScene; //!< [+0x0C]

  // actually, pROotScene maybe?
  Scene* pParent; //!< [+0x10] name from wii sports assert. might be wrong. when
                  //!< STATE_2, create this scene with argument _18

  s32 mNextSceneID; //!< [+0x14] set in matched inline "setNextSceneID" set to
                    //!< -1 in ct. tied to  mCurrentScene->OC. child?
  s32 mCurrentSceneID;
  s32 mPreviousSceneID;

  eAfterFadeType mTransitionStatus; //!< [+0x20] -1 in ct
  ColorFader* mCurrentFader; //!< [+0x24] header fn placement proves it's a ptr
                             //!< to ColorFader not Fader
  u32 bUseMem2; //!< [+0x28] If 1, use MEM2 heap for scenes when creating.
                //!< Otherwise, use MEM1.
};

} // namespace EGG
