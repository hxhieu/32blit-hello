#include "player.hpp"

namespace mitmeo
{
    namespace blit_invaders
    {
        void Player::update(uint32_t time_ms)
        {
            printf("%d\n", time_ms);
        }

        Player::Player()
        {
            entt::registry *world = GameEngine::get_world();
            world->emplace<Sprite>(
                entt,
                30,
                std::vector<uint8_t>{sprites::player_idle},
                std::vector<uint8_t>{sprites::player_left},
                std::vector<uint8_t>{sprites::player_right});
            world->emplace<Velocity>(entt, 0, 0, 1);
            world->emplace<DirectionalControl>(entt, 1, true, true, true, true);
            world->emplace<Update>(entt, Player::update);

            blit::Size screen_size = blit::screen.bounds;
            world->emplace<Position>(entt, (screen_size.w - 8) / 2, screen_size.h - 40);
        }
    }
}