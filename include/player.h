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
            inline static uint32_t _last_fire_time;
            inline static uint16_t _fire_interval = 500;

            static void update(uint32_t time_ms);
            static void do_fire();

        public:
            void set_fire_interval(uint8_t ms);
            Player();
        };
    }
}