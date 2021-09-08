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
            VulcanProjectile(uint32_t x, uint32_t y);
            VulcanProjectile(uint32_t x, uint32_t y, int8_t dir_x, int8_t dir_y);
        };
    }
}