#pragma once

#include "entity.h"

namespace mitmeo
{
    extern entt::dispatcher dispatcher;
    namespace blit_invaders
    {
        class VulcanProjectile : public engine::Entity
        {
        public:
            VulcanProjectile(uint32_t x, uint32_t y);
            VulcanProjectile(uint32_t x, uint32_t y, int8_t dir_x, int8_t dir_y);
            void OnCollision(const events::CollisionEvent &evt);
        };
    }
}