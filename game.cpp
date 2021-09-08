#include "32blit.hpp"
#include "entt.hpp"
#include "assets.hpp"
#include "game_engine.h"
#include "player.h"
#include "update_system.h"
#include "movement_system.h"
#include "logic_system.h"
#include "render_system.h"

using namespace mitmeo;

blit_invaders::UpdateSystem _update_system;
engine::MovementSystem _movement_system;
engine::LogicSystem _logic_system;
engine::RenderSystem _render_system;

/* setup */
void init()
{
    blit::set_screen_mode(blit::ScreenMode::hires);
    blit::screen.sprites = blit::SpriteSheet::load(png_invaders);
    // Example spawn
    blit_invaders::Player{};
}

void render(uint32_t time_ms)
{
    // Black screen
    blit::screen.pen = blit::Pen(0, 0, 0);
    blit::screen.clear();

    _render_system.run(world, time_ms);
}

void update(uint32_t time_ms)
{
    _logic_system.run(world, time_ms);
    _update_system.run(world, time_ms);
    _movement_system.run(world, time_ms);
}
