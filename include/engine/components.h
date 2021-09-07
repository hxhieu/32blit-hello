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
            uint8_t w, h = 8;
            uint8_t sprite_index = 0;
            uint32_t time_ms = 0;
        };

        struct Position
        {
            uint8_t x, y;
        };

        struct Velocity
        {
            int8_t x, y;
            uint8_t speed;
        };

        struct DirectionalControl
        {
            bool can_up, can_down, can_left, can_right = true;
            bool upward = true;
        };

        struct Update;
        typedef void (*UpdateCallback)(uint32_t time_ms);
        typedef struct Update
        {
            UpdateCallback update; // The callback to run the update logic
        } Update;

        struct AutoDestroy
        {
        };
    }
}