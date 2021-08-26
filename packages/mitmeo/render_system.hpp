#pragma once

#include "32blit.hpp"
#include "libs/flecs.h"
#include "components.hpp"
#include "animated_sprite.hpp"

namespace mitmeo
{
    using namespace components;

    namespace systems
    {
        struct RenderSystem
        {
            // Define types inside module scope. This is not mandatory, but ensures
            // that their fully qualified Flecs name matches the C++ type name. It also
            // ensures that type names cannot clash between modules.

            RenderSystem(flecs::world &world)
            {
                /* Register module with world */
                world.module<RenderSystem>();

                /* Register components */
                world.component<Sprite>();
                world.component<Position>();
                // world.component<AnimatedSprite>();

                /* Register system */
                world.system<Sprite, Position>("Render")
                    .each([](flecs::entity e, Sprite &s, Position &p) {});
            }
        };
    }
}