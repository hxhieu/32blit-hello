#pragma once

#include "libs/entt.hpp"
#include "components.hpp"

namespace mitmeo
{
    using namespace components;

    namespace LogicSystem
    {
        void run(entt::registry &world, uint32_t time_ms)
        {
            auto system = world.view<Update>();
            // use an extended callback
            // use forward iterators and get only the components of interest
            for (auto e : system)
            {
                auto &u = system.get<Update>(e);
                u.update(time_ms);
            }
        }
    }
}