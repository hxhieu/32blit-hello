#pragma once

namespace mitmeo
{
    namespace components
    {
        struct Sprite
        {
            std::vector<uint8_t> sprites;
            uint8_t fps = 12;
            uint8_t sprite_index = 0;
            uint32_t time_ms = 0;
        };

        struct Position
        {
            uint8_t x, y;
        };

        struct Velocity
        {
            uint8_t x, y;
        };
    }
}