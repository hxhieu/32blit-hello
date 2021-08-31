#pragma once

#include "32blit.hpp"
#include "libs/flecs.h"
#include "entity.hpp"
#include "render_system.hpp"

namespace mitmeo
{
    namespace GameEngine
    {
        namespace
        {
            flecs::world _world;
            flecs::system<components::Sprite, components::Position> _render_system;
        }

        void init()
        {
            _render_system = RenderSystem::create(_world);
        }

        void update(uint32_t time)
        {
            _world.progress();
        }

        void render(uint32_t time_ms)
        {
            _render_system.run();
        }

        flecs::entity add_entity(const char *name)
        {
            return _world.entity(name);
        }
    };
}