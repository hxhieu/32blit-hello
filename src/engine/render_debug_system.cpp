#include "render_debug_system.h"

namespace mitmeo
{
    namespace engine
    {
        RenderDebugSystem::RenderDebugSystem() {}

        void RenderDebugSystem::run(entt::registry &world, uint32_t time_ms)
        {
            // Debug pen
            blit::screen.pen = blit::Pen(0, 255, 0, 200);

            auto debug = world.view<components::Collider, components::Position>();
            std::vector<blit::Rect> colliders = std::vector<blit::Rect>{};
            for (auto e : debug)
            {
                auto &c = debug.get<components::Collider>(e);
                auto &p = debug.get<components::Position>(e);
                auto r = blit::Rect{
                    p.x + (int32_t)c.x,
                    p.y + (int32_t)c.y,
                    (int32_t)c.w,
                    (int32_t)c.h};

                // Draw origins
                blit::screen.line(blit::Point(p.x - 2, p.y), blit::Point(p.x + 2, p.y));
                blit::screen.line(blit::Point(p.x, p.y - 2), blit::Point(p.x, p.y + 2));

                // Draw colliders
                blit::screen.line(blit::Point(r.x - r.w / 2, r.y - r.h / 2), blit::Point(r.x + r.w / 2, r.y - r.h / 2));
                blit::screen.line(blit::Point(r.x - r.w / 2, r.y + r.h / 2), blit::Point(r.x + r.w / 2, r.y + r.h / 2));
                blit::screen.line(blit::Point(r.x - r.w / 2, r.y - r.h / 2), blit::Point(r.x - r.w / 2, r.y + r.h / 2));
                blit::screen.line(blit::Point(r.x + r.w / 2, r.y - r.h / 2), blit::Point(r.x + r.w / 2, r.y + r.h / 2));
            }
        }
    };
}
