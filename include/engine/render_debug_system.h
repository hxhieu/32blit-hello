#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "components.h"

namespace mitmeo
{
    namespace engine
    {
        class RenderDebugSystem
        {
        public:
            RenderDebugSystem();
            void run(entt::registry &world, uint32_t time_ms);
        };
    }
}
