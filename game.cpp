#include "game.hpp"
#include "assets.hpp"

using namespace blit;
using namespace mitmeo;

uint8_t SPRITE_SIZE = 8;

/* setup */
void init()
{
    blit::set_screen_mode(ScreenMode::hires);
    screen.sprites = SpriteSheet::load(png_invaders);

    GameEngine::add_entity(new Fighter());
}

void render(uint32_t time_ms)
{
    // Black screen
    screen.pen = Pen(0, 0, 0);
    screen.clear();

    GameEngine::render(time_ms);
}

void update(uint32_t time_ms)
{
    GameEngine::update(time_ms);
}