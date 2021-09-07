#pragma once

#include "32blit.hpp"
#include "sprites.h"
#include "entity.h"
#include "game_engine.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        class VulcanProjectile : public engine::Entity
        {
        public:
            VulcanProjectile(uint8_t x, uint8_t y, uint8_t dir_x, uint8_t dir_y);
            // {
            //     entt::registry *world = GameEngine::get_world();
            //     world->emplace<Sprite>(
            //         entt,
            //         30,
            //         std::vector<uint8_t>{sprites::vulcan_1, sprites::vulcan_2});
            //     world->emplace<Velocity>(entt, dir_x, dir_y);
            //     // Center pivot
            //     world->emplace<Position>(entt, x - 4, y - 4);
            // }
        };
    }
}