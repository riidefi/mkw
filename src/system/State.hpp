#pragma once

#include <rk_types.h>

class StateSequencer;

namespace System {

class State;
typedef void(State::*StateFunction)(void);

class State {
    public:
        virtual ~State();
        virtual void enter();
        virtual void calc();
        virtual void leave();

    private:
        StateSequencer* mpStateSequencer;
        StateFunction mInit;
        StateFunction mUpdate;
        StateFunction mExit;
};

class StateSequencer {
    State* mpCurrentState;
    State* mpNextState;
    State mState;

    public:
        virtual ~StateSequencer();
        virtual void update();
        virtual void vf_0x10();
        virtual void vf_0x14();
};

}
