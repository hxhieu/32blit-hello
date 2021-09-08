#include "player.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        Player::Player()
        {
            _last_fire_time = 0;
            fire_interval = 500;

            entt::registry *world = engine::GameEngine::GetInstance()->get_world();
            world->emplace<components::Sprite>(
                entt,
                std::vector<uint8_t>{sprites::player_idle},
                std::vector<uint8_t>{sprites::player_left},
                std::vector<uint8_t>{sprites::player_right},
                30);
            world->emplace<components::Velocity>(entt, 0, 0, 1);
            world->emplace<components::DirectionalControl>(entt, 1, true, true, true, true);
            world->emplace<components::Ref<Player>>(entt, this);

            blit::Size screen_size = blit::screen.bounds;
            world->emplace<components::Position>(entt, (screen_size.w - 8) / 2, screen_size.h - 40);
        }

        void Player::update(uint32_t time_ms)
        {
            bool button_a = blit::buttons & blit::Button::A;
            if (button_a)
            {
                if (time_ms - _last_fire_time >= fire_interval)
                {
                    do_fire();
                    _last_fire_time = time_ms;
                }
            }
        }

        void Player::do_fire()
        {
            VulcanProjectile(100, 100);
        }
    }
}