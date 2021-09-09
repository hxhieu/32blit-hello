#include "player.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        Player::Player()
        {
            world.emplace<components::Sprite>(
                entt,
                std::vector<uint8_t>{sprites::player_idle},
                std::vector<uint8_t>{sprites::player_left},
                std::vector<uint8_t>{sprites::player_right},
                30);
            world.emplace<components::Velocity>(entt, 0, 0, 1);
            world.emplace<components::DirectionalControl>(entt, 1, true, true, true, true);
            world.emplace<PlayerComponent>(entt);

            blit::Size screen_size = blit::screen.bounds;
            world.emplace<components::Position>(entt, (screen_size.w - 8) / 2, screen_size.h - 40);
        }
    }
}