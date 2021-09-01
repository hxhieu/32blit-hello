#pragma once

#include "32blit.hpp"
#include "libs/entt.hpp"
#include "components.hpp"

namespace mitmeo
{
    using namespace components;

    namespace MovementSystem
    {
        void run(entt::registry &world, uint32_t time_ms)
        {
            auto system = world.view<Position, Velocity>();
            // use an extended callback
            // use forward iterators and get only the components of interest
            for (auto e : system)
            {
                auto &p = system.get<Position>(e);
                auto &v = system.get<Velocity>(e);
                // Just translate
                p.x += v.x;
                p.y += v.y;
            }
        }
    }
}