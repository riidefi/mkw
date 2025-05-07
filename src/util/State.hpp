#pragma once

#include <rk_types.h>

namespace Util {

    template<typename T>
    class StateSequencer;
    
    template<typename T>
    class StateBase {
        public:
            virtual ~StateBase() = 0;
            virtual void enter(T* obj) = 0;
            virtual void calc(T* obj) = 0;
            virtual void leave(T* obj) = 0;
    };
    
    template<typename T>
    class State: public StateBase<T> {
        public:
            typedef void (T::*StateFunction)(void);
            
            inline State() : mpStateSequencer(nullptr), mInit(nullptr), mUpdate(nullptr), mExit(nullptr) {}
            
            virtual ~State() {}
            
            void enter(T* obj) {
                if (mInit) {
                    (obj->*mInit)();
                }
            }
            
            void calc(T* obj) {
                (obj->*mUpdate)();
            }
            
            void leave(T* obj) {
                if (mExit) {
                    (obj->*mExit)();
                }
            }
        
            inline void setFunctions(StateFunction init, StateFunction update, StateFunction exit) {
                mInit = init;
                mUpdate = update;
                mExit = exit;
            }

        private:
            StateSequencer<T>* mpStateSequencer;
            StateFunction mInit;
            StateFunction mUpdate;
            StateFunction mExit;
    };
    
    template<typename T>
    class StateSequencer {
        protected:
            State<T>* mpCurrentState;
            State<T>* mpNextState;
            State<T> mState;

        public:
            StateSequencer();
            virtual ~StateSequencer();
            virtual void update(T* obj);
            void reset();
            bool isState(State<T>*);
            void setNextState(State<T>*);
            virtual void vf_0x10();
            virtual void vf_0x14();
    };

}
