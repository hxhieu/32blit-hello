#include "32blit.hpp"
#include "entt.hpp"
#include "assets.hpp"
#include "game_engine.h"
#include "player_logic.h"
#include "invader_sm_lgreen.h"

using namespace mitmeo;

blit_invaders::PlayerLogic _player_logic;

/* setup */
void init()
{
    blit::set_screen_mode(blit::ScreenMode::hires);
    blit::screen.sprites = blit::SpriteSheet::load(png_invaders);
    // Example spawn
    blit_invaders::Player();
    blit_invaders::InvaderSmallLightGreen();
}

void update(uint32_t time_ms)
{
    _player_logic.run(time_ms);
    engine::update(time_ms);
}

void render(uint32_t time_ms)
{
    // Black screen
    blit::screen.pen = blit::Pen(0, 0, 0);
    blit::screen.clear();

    engine::render(time_ms);
}