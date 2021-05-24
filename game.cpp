#include "game.hpp"
#include "assets.hpp"

using namespace blit;

TileMap *environment;

/* setup */
void init()
{
    blit::set_screen_mode(ScreenMode::hires);

    screen.sprites = Surface::load(asset_platformer);
    environment = new TileMap((uint8_t *)asset_tilemap, nullptr, Size(64, 64), screen.sprites);
}

void render(uint32_t time_ms)
{
    // screen.alpha = 255;
    // screen.pen = Pen(39, 39, 54);
    // screen.clear();

    // screen.alpha = 255;
    // screen.mask = nullptr;

    environment->draw(&screen, Rect(0, 0, 320, 240));

    // screen.alpha = 255;
    // screen.pen = Pen(255, 255, 255);
    // screen.rectangle(Rect(0, 0, 320, 14));

    // screen.pen = Pen(0, 0, 0);
    // screen.text("Tilemap demo", minimal_font, Point(5, 4));
    // screen.watermark();
}

void update(uint32_t time)
{
}