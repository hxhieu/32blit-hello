#include "game_engine.h"

namespace mitmeo
{
    entt::registry world;
    entt::dispatcher dispatcher;

    namespace
    {
        engine::MovementSystem _movement_system;
        engine::LogicSystem _logic_system;
        engine::RenderSystem _render_system;

#ifdef DEBUG
        engine::RenderDebugSystem _render_debug_system;
#endif

    }

    void engine::update(uint32_t time_ms)
    {
        _logic_system.run(world, time_ms);
        _movement_system.run(world, time_ms);
        dispatcher.update();
    }

    void engine::render(uint32_t time_ms)
    {
        _render_system.run(world, time_ms);

#ifdef DEBUG
        _render_debug_system.run(world, time_ms);
#endif
    }
}