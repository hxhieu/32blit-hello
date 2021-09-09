#include "32blit.hpp"
#include "entt.hpp"
#include "assets.hpp"
#include "game_engine.h"
#include "player.h"
#include "update_system.h"

using namespace mitmeo;

blit_invaders::UpdateSystem _update_system;

/* setup */
void init()
{
    blit::set_screen_mode(blit::ScreenMode::hires);
    blit::screen.sprites = blit::SpriteSheet::load(png_invaders);
    // Example spawn
    blit_invaders::Player{};
}

void update(uint32_t time_ms)
{
    engine::update(time_ms);
}

void render(uint32_t time_ms)
{
    // Black screen
    blit::screen.pen = blit::Pen(0, 0, 0);
    blit::screen.clear();

    engine::render(time_ms);
}