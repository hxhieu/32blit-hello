#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "sprites.h"
#include "entity.h"
#include "components.h"
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