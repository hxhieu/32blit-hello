#include "logic_system.h"

namespace mitmeo
{
    namespace engine
    {
        LogicSystem::LogicSystem() {}

        void LogicSystem::run(entt::registry &world, uint32_t time_ms)
        {
            auto autoDestroy = world.view<components::AutoDestroy, components::Position, components::Sprite>();
            for (auto e : autoDestroy)
            {
                auto &p = autoDestroy.get<components::Position>(e);
                auto &s = autoDestroy.get<components::Sprite>(e);

                // Destroy off-screen
                auto sprite_w = s.actual_w();
                auto sprite_h = s.actual_h();
                if (p.y <= sprite_h || p.y >= blit::screen.bounds.h || p.x <= sprite_w || p.x >= blit::screen.bounds.w)
                {
                    world.destroy(e);
                }
            }
        }
    }
}
