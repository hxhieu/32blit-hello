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
            VulcanProjectile(uint8_t x, uint8_t y, int8_t dir_x = 0, int8_t dir_y = -1);
        };
    }
}