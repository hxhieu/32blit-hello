#include "player.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        Player::Player()
        {
            this->fire_interval = 500;
            this->_last_fire_time = 0;

            world.emplace<components::Sprite>(
                entt,
                std::vector<uint8_t>{sprites::player_idle},
                std::vector<uint8_t>{sprites::player_left},
                std::vector<uint8_t>{sprites::player_right},
                30);
            world.emplace<components::Velocity>(entt, 0, 0, 1);
            world.emplace<components::DirectionalControl>(entt, 1, true, true, true, true);
            world.emplace<components::Ref<Player>>(entt, this);

            blit::Size screen_size = blit::screen.bounds;
            world.emplace<components::Position>(entt, (screen_size.w - 8) / 2, screen_size.h - 40);
        }

        void Player::update(uint32_t time_ms)
        {
            // fire_interval = 500;
            // bool button_a = blit::buttons & blit::Button::A;
            // if (button_a)
            // {
            //     if (time_ms - _last_fire_time >= fire_interval)
            //     {
            //         do_fire();
            //         _last_fire_time = time_ms;
            //     }
            // }
            // if (time_ms - _last_fire_time >= fire_interval)
            // {
            //     do_fire();
            //     _last_fire_time = time_ms;
            // }
            do_fire();
        }

        void Player::do_fire()
        {
            // auto &pos = world.get<components::Position>(entt);
            // VulcanProjectile(100, 100);
            this->fire_interval = 500;
            printf("%d\n", this->fire_interval);
        }
    }
}