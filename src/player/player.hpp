#pragma once

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
                world->emplace<Position>(entt, 40, 40);
                world->emplace<Sprite>(entt, std::vector<uint8_t>{sprites::player_idle, 6}, 30);
                world->emplace<Velocity>(entt, 1, 1);
                world->emplace<DirectionalControl>(entt, false, false, true, true);
            }
        };
    }
}