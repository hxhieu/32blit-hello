#pragma once

#include "player.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        class PlayerLogic
        {
        private:
            uint32_t _last_fire_time = 0;

        public:
            PlayerLogic();

            uint32_t fire_interval = 500;

            void run(uint32_t time_ms);
        };
    }
}