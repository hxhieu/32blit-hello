#pragma once

#include "32blit.hpp"
#include "libs/flecs.h"
#include "components.hpp"
#include "animated_sprite.hpp"

namespace mitmeo
{
    using namespace components;

    namespace RenderSystem
    {
        flecs::system<Sprite, Position> create(flecs::world &world)
        {
            auto system =
                world.system<Sprite, Position>("Render")
                    .kind(flecs::OnUpdate)
                    .each([](flecs::entity e, Sprite &s, Position &p)
                          { blit::screen.sprite(s.sprites[s.current_sprite], blit::Point(p.x, p.y)); });
            return system;
        }
    }
}