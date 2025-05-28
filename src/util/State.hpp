#pragma once

#include <rk_types.h>

namespace Util {

    template<typename T>
    class StateSequencer;
    
    template<typename T>
    class StateBase {
        public:
            virtual ~StateBase() {}
            virtual void enter() = 0;
            virtual void calc() = 0;
            virtual void leave() = 0;
    };
    
    template<typename T>
    class State: public StateBase<T> {
        public:
            typedef void (T::*StateFunction)(void);
            
            inline State() : mpStateSequencer(nullptr), mInit(nullptr), mUpdate(nullptr), mExit(nullptr) {}
            
            virtual ~State() {}
            
            void enter() {
                if (mInit) {
                    (mpStateSequencer->*mInit)();
                }
            }
            
            void calc() {
                (mpStateSequencer->*mUpdate)();
            }
            
            void leave() {
                if (mExit) {
                    (mpStateSequencer->*mExit)();
                }
            }
        
            inline void setFunctions(T* stateSequencer, StateFunction init, StateFunction update, StateFunction exit) {
                mpStateSequencer = stateSequencer;
                mInit = init;
                mUpdate = update;
                mExit = exit;
            }

        private:
            T* mpStateSequencer;
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
            virtual void calc();
            void reset();
            bool isState(State<T>*);
            void setNextState(State<T>*);
            virtual void vf_0x10();
            virtual void vf_0x14();
    };

}
