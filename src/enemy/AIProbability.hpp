#pragma once

#include "AIInfo.hpp"

namespace Enemy {

    class AIProbabilityBase {
        public:
            inline AIProbabilityBase() {
                mGroupKind = 0;
                mStartBoostLevel = 0;
            }
            
            virtual ~AIProbabilityBase();
            virtual void determineIfCanMiniturbo();
            virtual void getStartBoost();
            virtual void setDoTrick(bool);
            virtual s32 getStartBoostLevel();
            virtual bool getDrift(bool);
            virtual bool getMiniturbo();
            virtual bool getTrick();
            virtual bool getWheelie();
            virtual bool vf_0x2C();
            virtual bool isLaunchBlockLine();

        protected:
            s32 mGroupKind;
            s32 mStartBoostLevel;
    };

    class AIProbabilityRace: public AIProbabilityBase {
        public:
            AIProbabilityRace();
            ~AIProbabilityRace();
            void determineIfCanMiniturbo();
            void getStartBoost();
            bool getDrift(bool);
            bool getMiniturbo();
            bool getTrick();
            bool getWheelie();
            bool vf_0x2C();
            bool isLaunchBlockLine();

        private:
            AIInfo* mpInfo;
            s32 field_0x10;
            bool mbCanDrift;
            bool mbCanMiniturbo;
    };

    // Unknown vtable at 0x808CA060
    class AIProbabilityBattleBase: public AIProbabilityBase {
        public:
            inline AIProbabilityBattleBase() {}
            virtual ~AIProbabilityBattleBase();
            virtual void determineIfCanMiniturbo();
            virtual bool getDrift(bool);
            virtual bool getMiniturbo();
            virtual bool getTrick();
            virtual bool getWheelie();
            virtual bool vf_0x2C();
            virtual bool isLaunchBlockLine();
    };

    class AIProbabilityBattle: public AIProbabilityBattleBase {
        public:
            inline AIProbabilityBattle() {}
            void setDoTrick(bool);
            virtual bool vf_0x2C();

        private:
            bool mbDoTrick;
    };

    class AIProbabilityDemo: public AIProbabilityBase {
        public:
            inline AIProbabilityDemo() {}
            ~AIProbabilityDemo() {}
            void determineIfCanMiniturbo() {}
            s32 getStartBoostLevel() { return 0; }
            bool getDrift(bool) { return true; }
            bool getMiniturbo() { return true; }
            bool getTrick() { return true; }
            bool getWheelie() { return true; }
            bool vf_0x2C() {return false; }
            bool isLaunchBlockLine() { return true; }
    };

}
