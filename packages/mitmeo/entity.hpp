#pragma once

#include "libs/entt.hpp"
#include "game_engine.hpp"

namespace mitmeo
{
    class Entity
    {
    protected:
        entt::entity entt;

    public:
        Entity()
        {
            entt = GameEngine::create_entity();
        }
    };
}