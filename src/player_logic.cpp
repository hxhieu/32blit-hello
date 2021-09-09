#include "player_logic.h"

namespace mitmeo
{
    extern entt::registry world;
    namespace blit_invaders
    {
        PlayerLogic::PlayerLogic() {}

        void PlayerLogic::run(uint32_t time_ms)
        {
            // Firing
            auto firingSystem = world.view<PlayerComponent, components::Position, components::Sprite>();
            for (auto e : firingSystem)
            {
                auto &p = firingSystem.get<components::Position>(e);
                auto &s = firingSystem.get<components::Sprite>(e);
                bool button_a = blit::buttons & blit::Button::A;
                if (button_a)
                {
                    if (time_ms - _last_fire_time >= fire_interval)
                    {
                        VulcanProjectile(p.x + (s.actual_w()) / 2, p.y - (s.actual_h()) / 2);
                        _last_fire_time = time_ms;
                    }
                }
            }
        }
    }
}