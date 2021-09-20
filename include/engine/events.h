#pragma once

#include "entt.hpp"

namespace mitmeo
{
    namespace events
    {
        struct CollisionEvent
        {
            entt::entity actor1, actor2;
        };
    }
}