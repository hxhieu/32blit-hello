#include "render_system.h"

namespace mitmeo
{
    namespace engine
    {
        RenderSystem::RenderSystem() {}

        void RenderSystem::run(entt::registry &world, uint32_t time_ms)
        {
            auto system = world.view<components::Sprite, components::Position, components::Velocity>();
            // use an extended callback
            // use forward iterators and get only the components of interest
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

                blit::screen.sprite(sprites[s.sprite_index], blit::Point(p.x, p.y), blit::Point(s.w / 2, s.h / 2), 2.0, 0);
            }

            // delta_time sprite animation
            // Sprite animations
            //           auto sprite_count = s.sprites.size();
            //           auto frame_rate = (float)1 / s.fps;
            //           if (sprite_count > 0)
            //           {
            //               s.delta_time += e.delta_time();

            //               if (s.delta_time >= frame_rate)
            //               {
            //                   s.sprite_index++;
            //                   // Loop => back to 1st sprite
            //                   if (s.sprite_index >= sprite_count)
            //                   {
            //                       s.sprite_index = 0;
            //                   }
            //                   s.delta_time = 0;
            //               }
            //           }

            //           blit::screen.sprite(s.sprites[s.sprite_index], blit::Point(p.x, p.y));
        }
    };
}