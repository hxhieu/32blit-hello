#pragma once

#include "32blit.hpp"
#include "render_system.hpp"
#include "libs/entt.hpp"

namespace mitmeo
{
    namespace GameEngine
    {
        namespace
        {
            entt::registry _world;
        }

        void init()
        {
        }

        entt::registry *get_world()
        {
            return &_world;
        }

        void update(uint32_t time)
        {
        }

        void render(uint32_t time_ms)
        {
            RenderSystem::run(_world, time_ms);
        }
    };
}