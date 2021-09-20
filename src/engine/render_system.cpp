#include "render_system.h"

namespace mitmeo
{
    namespace engine
    {
        RenderSystem::RenderSystem() {}

        void RenderSystem::run(entt::registry &world, uint32_t time_ms)
        {
            // Debug pen
            blit::screen.pen = blit::Pen(0, 255, 0, 200);

            auto system = world.view<components::Sprite, components::Position, components::Velocity>();
            for (auto e : system)
            {
                auto &p = system.get<components::Position>(e);
                auto &s = system.get<components::Sprite>(e);
                auto &v = system.get<components::Velocity>(e);
                // Sprite animations
                auto sprites = v.x == 0 ? s.idle : (v.x == 1 ? s.right : s.left);
                auto sprite_count = sprites.size();
                auto frame_rate = (float)1 / s.fps;
                if (sprite_count > 0)
                {

                    if ((float)(time_ms - s.time_ms) / 1000 > frame_rate)
                    {
                        s.sprite_index++;
                        // Loop => back to 1st sprite
                        if (s.sprite_index >= sprite_count)
                        {
                            s.sprite_index = 0;
                        }
                        s.time_ms = time_ms;
                    }
                }

                blit::screen.sprite(
                    sprites[s.sprite_index],
                    blit::Point(p.x, p.y),
                    blit::Point(s.w / 2, s.h / 2),
                    s.scale,
                    s.transform);
                // Origin
                blit::screen.line(blit::Point(p.x - 2, p.y), blit::Point(p.x + 2, p.y));
                blit::screen.line(blit::Point(p.x, p.y - 2), blit::Point(p.x, p.y + 2));
            }

            auto colliding = world.view<components::Collider, components::Position>();
            std::vector<blit::Rect> colliders = std::vector<blit::Rect>{};
            for (auto e : colliding)
            {
                auto &c = colliding.get<components::Collider>(e);
                auto &p = colliding.get<components::Position>(e);
                auto r = blit::Rect{
                    p.x + c.x,
                    p.y + c.y,
                    c.w,
                    c.h};

                blit::screen.line(blit::Point(r.x - r.w / 2, r.y - r.h / 2), blit::Point(r.x + r.w / 2, r.y - r.h / 2));
                blit::screen.line(blit::Point(r.x - r.w / 2, r.y + r.h / 2), blit::Point(r.x + r.w / 2, r.y + r.h / 2));
                blit::screen.line(blit::Point(r.x - r.w / 2, r.y - r.h / 2), blit::Point(r.x - r.w / 2, r.y + r.h / 2));
                blit::screen.line(blit::Point(r.x + r.w / 2, r.y - r.h / 2), blit::Point(r.x + r.w / 2, r.y + r.h / 2));
            }
        }
    };
}