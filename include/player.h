#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "sprites.h"
#include "entity.h"
#include "components.h"
#include "vulcan_projectile.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        class Player : public engine::Entity
        {
        private:
            uint32_t _last_fire_time;

            void do_fire();

        public:
            Player();

            uint16_t fire_interval;

            void set_fire_interval(uint8_t ms);
            void update(uint32_t time_ms);
        };
    }
}