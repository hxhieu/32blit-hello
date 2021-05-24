#include "game.hpp"
#include "assets.hpp"

using namespace blit;
using namespace constants;
using namespace mitmeo;

// TileMap *environment;

GameEngine *_engine;

/* setup */
void init()
{
    blit::set_screen_mode(ScreenMode::hires);
    screen.sprites = SpriteSheet::load(png_invaders);
    _engine = new GameEngine(&screen);
}

void render(uint32_t time_ms)
{
    // screen.alpha = 255;
    // screen.pen = Pen(39, 39, 54);
    // screen.clear();

    // screen.alpha = 255;
    // screen.mask = nullptr;

    // environment->draw(&screen, Rect(0, 0, 320, 240));

    // screen.alpha = 255;
    // screen.pen = Pen(255, 255, 255);
    // screen.rectangle(Rect(0, 0, 320, 14));

    // screen.pen = Pen(0, 0, 0);
    // screen.text("Tilemap demo", minimal_font, Point(5, 4));
    // screen.watermark();
    // Size screen_size = screen.bounds;
    // screen.sprite(0, Point((screen_size.w - SPRITE_SIZE) / 2, (screen_size.h - SPRITE_SIZE) / 2));

    _engine->render(time_ms);
}

void update(uint32_t time_ms)
{
    _engine->render(time_ms);
}