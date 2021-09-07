#pragma once

#include "entt.hpp"
#include "game_engine.h"

namespace mitmeo
{
    namespace engine
    {
        class Entity
        {
        protected:
            entt::entity entt;

        public:
            Entity();

            blit::Point get_position();
        };
    }
}