#pragma once

#include "32blit.hpp"
#include "libs/entt.hpp"
#include "components.hpp"

namespace mitmeo
{
    using namespace components;

    namespace MovementSystem
    {
        void run(entt::registry &world, uint32_t time_ms)
        {
            auto directional = world.view<Velocity, DirectionalControl>();
            for (auto e : directional)
            {
                auto &v = directional.get<Velocity>(e);
                auto &d = directional.get<DirectionalControl>(e);
                bool dpad_l = blit::buttons & blit::Button::DPAD_LEFT;
                bool dpad_r = blit::buttons & blit::Button::DPAD_RIGHT;
                bool dpad_u = blit::buttons & blit::Button::DPAD_UP;
                bool dpad_d = blit::buttons & blit::Button::DPAD_DOWN;

                v.x = v.y = 0;

                if (dpad_l && d.can_left)
                {
                    v.x = d.upward ? -d.speed : d.speed;
                }

                if (dpad_r && d.can_right)
                {
                    v.x = d.upward ? d.speed : -d.speed;
                }

                if (dpad_u && d.can_up)
                {
                    v.y = d.upward ? -d.speed : d.speed;
                }

                if (dpad_d && d.can_down)
                {
                    v.y = d.upward ? d.speed : d.speed;
                }
            }

            auto translation = world.view<Position, Velocity>();
            for (auto e : translation)
            {
                auto &p = translation.get<Position>(e);
                auto &v = translation.get<Velocity>(e);
                // Just translate
                p.x += v.x;
                p.y += v.y;
            }
        }
    }
}