#pragma once

namespace mitmeo
{
    namespace components
    {
        struct Sprite
        {
            uint8_t fps = 12;
            std::vector<uint8_t> idle;
            std::vector<uint8_t> left;
            std::vector<uint8_t> right;
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

        struct DirectionalControl
        {
            int speed;
            bool can_up, can_down, can_left, can_right = true;
            bool upward = true;
        };

    }
}