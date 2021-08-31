#pragma once

namespace mitmeo
{
    namespace components
    {
        struct Sprite
        {
            std::vector<uint8_t> sprites;
            uint8_t fps = 12;
            uint8_t current_sprite = 0;
        };

        struct Position
        {
            uint8_t x, y;
        };
    }
}