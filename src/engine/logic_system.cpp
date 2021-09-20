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

            // auto colliding = world.view<components::Collider, components::Position>();
            // std::vector<blit::Rect> colliders = std::vector<blit::Rect>{};
            // for (auto e : colliding)
            // {
            //     auto &c = colliding.get<components::Collider>(e);
            //     auto &p = colliding.get<components::Position>(e);
            //     colliders.emplace_back(blit::Rect{
            //         p.x + c.x,
            //         p.y + c.y,
            //         c.w,
            //         c.h});
            // }

            // blit::screen.pen = Pen(255);
            // for (auto c : colliders)
            // {
            //     blit::screen.line(blit::Point(c.y, c.y), blit::Point)
            // }
        }
    }
}