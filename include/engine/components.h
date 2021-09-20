#pragma once

#include <stdint.h>

namespace mitmeo
{
    namespace components
    {
        struct Sprite
        {
            std::vector<uint8_t> idle;
            std::vector<uint8_t> left;
            std::vector<uint8_t> right;
            uint8_t fps = 12;
            float scale = 2;
            uint8_t w = 8, h = 8;
            uint8_t transform = 0;
            uint8_t sprite_index = 0;
            uint32_t time_ms = 0;

            int32_t actual_w()
            {
                return w * (uint16_t)scale;
            }
            int32_t actual_h()
            {
                return h * (uint16_t)scale;
            }
        };

        struct Position
        {
            uint16_t x, y;
        };

        struct Velocity
        {
            int8_t x, y;
            uint8_t speed;
        };

        struct DirectionalControl
        {
            bool can_up = true, can_down = true, can_left = true, can_right = true;
            bool upward = true;
        };

        struct AutoDestroy
        {
        };

        struct Collider
        {
            int w = 8, h = 8, x = 0, y = 0;
        };

    }
}