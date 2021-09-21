#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "movement_system.h"
#include "logic_system.h"
#include "render_system.h"

#ifdef DEBUG
#include "render_debug_system.h"
#endif

namespace mitmeo
{
    extern entt::registry world;

    namespace engine
    {
        void update(uint32_t time_ms);
        void render(uint32_t time_ms);
    }
}
