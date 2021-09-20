#include "movement_system.h"

namespace mitmeo
{
    namespace engine
    {
        MovementSystem::MovementSystem() {}

        void MovementSystem::run(entt::registry &world, uint32_t time_ms)
        {
            // Directional control
            auto directional = world.view<components::Velocity, components::DirectionalControl>();
            for (auto e : directional)
            {
                auto &v = directional.get<components::Velocity>(e);
                auto &d = directional.get<components::DirectionalControl>(e);

                bool dpad_l = blit::buttons & blit::Button::DPAD_LEFT;
                bool dpad_r = blit::buttons & blit::Button::DPAD_RIGHT;
                bool dpad_u = blit::buttons & blit::Button::DPAD_UP;
                bool dpad_d = blit::buttons & blit::Button::DPAD_DOWN;

                v.x = v.y = 0;

                if (dpad_l && d.can_left)
                {
                    v.x = d.upward ? -1 : 1;
                }

                if (dpad_r && d.can_right)
                {
                    v.x = d.upward ? 1 : -1;
                }

                if (dpad_u && d.can_up)
                {
                    v.y = d.upward ? -1 : 1;
                }

                if (dpad_d && d.can_down)
                {
                    v.y = d.upward ? 1 : -1;
                }
            }

            // Final translation
            auto translation = world.view<components::Position, components::Velocity, components::Sprite>();
            for (auto e : translation)
            {
                auto &p = translation.get<components::Position>(e);
                auto &v = translation.get<components::Velocity>(e);
                auto &s = translation.get<components::Sprite>(e);

                // Reset velocity, should always be 1
                if (v.x != 0)
                {
                    v.x = v.x > 0 ? 1 : -1;
                }
                if (v.y != 0)
                {
                    v.y = v.y > 0 ? 1 : -1;
                }

                // Just translate
                p.x = std::clamp((int32_t)(p.x + v.x * v.speed), (int32_t)0, blit::screen.bounds.w);
                p.y = std::clamp((int32_t)(p.y + v.y * v.speed), (int32_t)0, blit::screen.bounds.h);
            }
        }
    }
}