#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "game_engine.h"
#include "components.h"

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