#pragma once

#include "32blit.hpp"
#include "../../packages/mitmeo/entity.hpp"
#include "../../packages/mitmeo/game_engine.hpp"
#include "../const.hpp"

namespace mitmeo
{
    namespace blit_invaders
    {
        class Player : public Entity
        {
        private:
            static void update(uint32_t time_ms);

        public:
            Player();
        };
    }
}