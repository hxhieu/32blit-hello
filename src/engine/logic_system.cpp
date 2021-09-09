#include "logic_system.h"

namespace mitmeo
{
    namespace engine
    {
        LogicSystem::LogicSystem() {}

        void LogicSystem::run(entt::registry &world, uint32_t time_ms)
        {
            auto autoDestroy = world.view<components::AutoDestroy, components::Position>();
            for (auto e : autoDestroy)
            {
                auto &p = autoDestroy.get<components::Position>(e);
                // Destroy off-screen
                if (p.y <= 0 || p.y >= blit::screen.bounds.h || p.x <= 0 || p.x >= blit::screen.bounds.w)
                {
                    world.destroy(e);
                }
            }
        }
    }
}