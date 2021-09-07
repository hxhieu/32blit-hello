#include "player.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        void Player::update(uint32_t time_ms)
        {
            bool button_a = blit::buttons & blit::Button::A;
            if (button_a)
            {
                if (time_ms - _last_fire_time >= _fire_interval)
                {
                    do_fire();
                    _last_fire_time = time_ms;
                }
            }
        }

        Player::Player()
        {
            entt::registry *world = engine::GameEngine::GetInstance()->get_world();
            world->emplace<components::Sprite>(
                entt,
                std::vector<uint8_t>{sprites::player_idle},
                std::vector<uint8_t>{sprites::player_left},
                std::vector<uint8_t>{sprites::player_right},
                30);
            world->emplace<components::Velocity>(entt, 0, 0, 1);
            world->emplace<components::DirectionalControl>(entt, 1, true, true, true, true);
            // world->emplace<components::Update>(entt, [&](uint32_t time_ms)
            //                                    { auto pos = get_position(); });

            blit::Size screen_size = blit::screen.bounds;
            world->emplace<components::Position>(entt, (screen_size.w - 8) / 2, screen_size.h - 40);
        }

        void Player::set_fire_interval(uint8_t ms)
        {
            _fire_interval = ms;
        }

        void Player::do_fire()
        {
            // auto pos = get_position();
            // auto projectile = VulcanProjectile(pos.x, pos.y);
        }

        // typedef void (*PlayerUpdateCallback)(Player *player, uint32_t time_ms);
        // typedef struct PlayerUpdate
        // {
        //     PlayerUpdateCallback update; // The callback to run the update logic
        // } PlayerUpdate;
    }
}