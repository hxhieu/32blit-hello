#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "movement_system.h"
#include "logic_system.h"
#include "render_system.h"

namespace mitmeo
{
    extern entt::registry world;
    extern entt::dispatcher dispatcher;

    namespace engine
    {
        void update(uint32_t time_ms);
        void render(uint32_t time_ms);
    }

}