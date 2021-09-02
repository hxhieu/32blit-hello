#pragma once

#include "32blit.hpp"
#include "../../packages/mitmeo/entity.hpp"
#include "../../packages/mitmeo/game_engine.hpp"
#include "../const.hpp"

namespace mitmeo
{
    namespace blit_invaders
    {
        class Player : public Entity
        {
        public:
            Player()
            {
                entt::registry *world = GameEngine::get_world();
                world->emplace<Sprite>(
                    entt,
                    30,
                    std::vector<uint8_t>{sprites::player_idle},
                    std::vector<uint8_t>{sprites::player_left},
                    std::vector<uint8_t>{sprites::player_right});
                world->emplace<Velocity>(entt, 0, 0);
                world->emplace<DirectionalControl>(entt, 1, true, true, true, true);

                blit::Size screen_size = blit::screen.bounds;
                world->emplace<Position>(entt, (screen_size.w - 8) / 2, screen_size.h - 40);
            }
        };
    }
}