#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "player.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        class UpdateSystem
        {
        public:
            UpdateSystem();
            void run(entt::registry &world, uint32_t time_ms);
        };
    }
}