#pragma once
#include "../../packages/mitmeo/entity.hpp"

namespace mitmeo
{
    namespace blit_invaders
    {
        class Projectile : public Entity
        {
        private:
            uint8_t _power;

        public:
            Projectile(uint8_t power = 1)
            {
                _power = power;
            }

            void update(uint32_t time_ms);
            void render(uint32_t time_ms);
        };
    }
}