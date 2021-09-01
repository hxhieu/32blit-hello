#include "game.hpp"

using namespace mitmeo;

/* setup */
void init()
{
    blit::set_screen_mode(blit::ScreenMode::lores);
    blit::screen.sprites = blit::SpriteSheet::load(png_invaders);

    GameEngine::init();

    // Example spawn
    entt::registry *world = GameEngine::get_world();
    blit_invaders::create_player(world);
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