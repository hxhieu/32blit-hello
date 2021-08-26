#include "game.hpp"
#include "assets.hpp"
#include "packages/mitmeo/components.hpp"
#include "src/const.hpp"

using namespace mitmeo;

/* setup */
void init()
{
    blit::set_screen_mode(blit::ScreenMode::lores);
    blit::screen.sprites = blit::SpriteSheet::load(png_invaders);
    // GameEngine::add_entity(new blit_invaders::Fighter());
    GameEngine::add_entity("Player")
        .set<components::Sprite>({std::vector<uint8_t>{blit_invaders::sprites::player_idle}});
}

void render(uint32_t time_ms)
{
    // Black screen
    blit::screen.pen = blit::Pen(0, 0, 0);
    blit::screen.clear();

    GameEngine::render(time_ms);
}

void update(uint32_t time_ms)
{
    GameEngine::update(time_ms);
}