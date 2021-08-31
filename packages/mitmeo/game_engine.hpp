#pragma once

#include "32blit.hpp"
// #include "entity.hpp"
// #include "render_system.hpp"
#include "libs/entt.hpp"

namespace mitmeo
{
    namespace GameEngine
    {
        struct position
        {
            float x;
            float y;
        };

        struct velocity
        {
            float dx;
            float dy;
        };
        namespace
        {
            // flecs::world _world;
            // flecs::system<components::Sprite, components::Position> _render_system;
        }

        void init()
        {
            entt::registry registry;

            for (auto i = 0u; i < 10u; ++i)
            {
                const auto entity = registry.create();
                registry.emplace<position>(entity, i * 1.f, i * 1.f);
                if (i % 2 == 0)
                {
                    registry.emplace<velocity>(entity, i * .1f, i * .1f);
                }
            }
            // _render_system = RenderSystem::create(_world);
            auto view = registry.view<const position, velocity>();

            // use forward iterators and get only the components of interest
            for (auto entity : view)
            {
                auto &vel = view.get<velocity>(entity);
                printf("%d\n", (int)vel.dx);
            }
        }

        void update(uint32_t time)
        {
            // _world.progress();
        }

        void render(uint32_t time_ms)
        {
            // _render_system.run();
        }

        // flecs::entity add_entity(const char *name)
        // {
        //     return _world.entity(name);
        // }
    };
}