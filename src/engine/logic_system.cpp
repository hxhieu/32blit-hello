#include "logic_system.h"

namespace mitmeo
{
    namespace engine
    {
        LogicSystem::LogicSystem() {}

        void LogicSystem::run(entt::registry &world, uint32_t time_ms)
        {
            auto system = world.view<components::Update>();
            // use an extended callback
            // use forward iterators and get only the components of interest
            for (auto e : system)
            {
                auto &u = system.get<components::Update>(e);
                u.update(time_ms);
            }
        }
    }
}