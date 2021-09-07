#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "sprites.h"
#include "entity.h"
#include "components.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        class Player : public engine::Entity
        {
        private:
            static void update(uint32_t time_ms);

        public:
            Player();
        };
    }
}