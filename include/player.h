#pragma once

#include "entity.h"
#include "vulcan_projectile.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        class Player : public engine::Entity
        {
        public:
            Player();
        };

        struct PlayerComponent
        {
        };
    }
}