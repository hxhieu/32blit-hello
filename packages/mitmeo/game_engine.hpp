#pragma once

#include "32blit.hpp"
#include "render_system.hpp"
#include "movement_system.hpp"
#include "libs/entt.hpp"

namespace mitmeo
{
    namespace GameEngine
    {
        uint8_t fps;

        namespace
        {
            entt::registry _world;
            uint32_t _last_update;
            bool can_update(uint32_t time_ms)
            {
                if (time_ms - _last_update >= 1000)
                {
                    _last_update = time_ms;
                    return true;
                }
                return false;
            }
        }

        void init()
        {
        }

        entt::registry *get_world()
        {
            return &_world;
        }

        void update(uint32_t time_ms)
        {
            MovementSystem::run(_world, time_ms);
        }

        void render(uint32_t time_ms)
        {
            RenderSystem::run(_world, time_ms);
        }
    };
}