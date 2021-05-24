#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "32blit.hpp"

namespace mitmeo
{
    class GameEngine
    {
    private:
        blit::Surface *_screen;
        uint8_t _sprite_size;

    public:
        GameEngine(blit::Surface *screen, uint8_t spriteSize = 8)
        {
            _screen = screen;
            _sprite_size = spriteSize;
        }

        void update(uint32_t time);
        void render(uint32_t time_ms);
        void init();
    };
}

#endif // GAME_ENGINE_H