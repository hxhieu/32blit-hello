#include "32blit.hpp"
#include "assets.hpp"
#include "game_engine.h"
#include "player.h"
#include "update_system.h"

using namespace mitmeo;

blit_invaders::UpdateSystem _update_system;
entt::registry *_world;

/* setup */
void init()
{
    blit::set_screen_mode(blit::ScreenMode::hires);
    blit::screen.sprites = blit::SpriteSheet::load(png_invaders);
    _world = engine::GameEngine::GetInstance()->get_world();
    // Example spawn
    blit_invaders::Player{};
}

void render(uint32_t time_ms)
{
    // Black screen
    blit::screen.pen = blit::Pen(0, 0, 0);
    blit::screen.clear();

    engine::GameEngine::GetInstance()->render(time_ms);
}

void update(uint32_t time_ms)
{
    engine::GameEngine::GetInstance()->update(time_ms);
    _update_system.run(*_world, time_ms);
}
