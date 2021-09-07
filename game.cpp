#include "32blit.hpp"
#include "assets.hpp"
#include "game_engine.h"
#include "player.h"

using namespace mitmeo;

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

    engine::GameEngine::GetInstance()->render(time_ms);
}

void update(uint32_t time_ms)
{
    engine::GameEngine::GetInstance()->update(time_ms);
}