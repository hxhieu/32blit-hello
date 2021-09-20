#include "logic_system.h"

namespace mitmeo
{
    extern entt::dispatcher dispatcher;
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

            auto colliding = world.view<components::Collider, components::Position>();
            std::vector<blit::Rect> colliders = std::vector<blit::Rect>{};
            std::vector<entt::entity> entities = std::vector<entt::entity>{};
            for (auto e : colliding)
            {
                auto &c = colliding.get<components::Collider>(e);
                auto &p = colliding.get<components::Position>(e);
                auto r = blit::Rect{
                    p.x + c.x,
                    p.y + c.y,
                    c.w,
                    c.h};
                colliders.emplace_back(r);
                entities.emplace_back(e);

                // if (master == nullptr)
                // {
                //     master = &r;
                //     continue;
                // }

                // if (master->contains(blit::Point{r.x, r.y}))
                // {
                //     printf("hit!!\n");
                // }
            }

            // std::pair<const entt::entity, blit::Rect> *master;
            // for (auto c : colliders)
            // {
            //     if (master == nullptr)
            //     {
            //         master = &c;
            //     }
            //     else
            //     {
            //         if (master->second.intersects(c.second))
            //         {
            //             printf("hit!!%d\n", (uint32_t)master->first);
            //         }
            //     }
            // }

            for (uint32_t i = 1; i < colliders.size(); i++)
            {
                auto master = colliders[0];
                auto slave = colliders[i];
                if (master.intersects(slave))
                {
                    dispatcher.enqueue<events::CollisionEvent>(entities[0], entities[i]);
                }
            }
        }
    }
}