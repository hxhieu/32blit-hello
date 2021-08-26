#pragma once

namespace mitmeo
{
    namespace components
    {
        struct Sprite
        {
        private:
            uint32_t _frame_time;
            uint32_t _last_time_ms;
            uint8_t _sprite_index;

        public:
            std::vector<uint8_t> sprites;
            uint8_t fps;
            // uint8_t next(uint32_t time_ms)
            // {
            //     auto sprite_count = sprites.size();
            //     if (sprite_count > 0)
            //     {
            //         if ((double)(time_ms - _frame_time) / 1000 > 1.0 / fps)
            //         {
            //             _sprite_index++;
            //             // Loop => back to 1st sprite
            //             if (_sprite_index >= sprite_count)
            //             {
            //                 _sprite_index = 0;
            //             }
            //             _frame_time = time_ms;
            //         }
            //     }
            //     return sprites[_sprite_index];
            // }
        };

        struct Position
        {
            uint8_t x, y;
        };
    }
}