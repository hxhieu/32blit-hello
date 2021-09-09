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

        struct Update;
        typedef void (*UpdateCallback)(uint32_t time_ms);
        typedef struct Update
        {
            UpdateCallback update; // The callback to run the update logic
        } Update;

        struct AutoDestroy
        {
        };

        template <class T>
        struct Ref
        {
            T *instance;
        };
    }
}