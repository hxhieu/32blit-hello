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

            auto renderer = world.view<components::Sprite, components::Position, components::Velocity>();
            for (auto e : renderer)
            {
                auto &p = renderer.get<components::Position>(e);
                auto &s = renderer.get<components::Sprite>(e);
                auto &v = renderer.get<components::Velocity>(e);
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
            }
        }
    };
}