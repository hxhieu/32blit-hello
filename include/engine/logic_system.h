#pragma once

#include "entt.hpp"
#include "components.h"

namespace mitmeo
{
    namespace engine
    {
        class LogicSystem
        {
        public:
            LogicSystem();
            void run(entt::registry &world, uint32_t time_ms);
        };
    }
}