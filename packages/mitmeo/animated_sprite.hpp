#pragma once

#include "32blit.hpp"

namespace mitmeo
{
    class AnimatedSprite
    {
    private:
        uint32_t _frame_time;
        uint32_t _last_time_ms;
        float _frame_rate;
        std::vector<uint8_t> *_sprites;
        uint8_t _sprite_index;
        uint8_t _sprite_count;

        ~AnimatedSprite();

    public:
        AnimatedSprite()
        {
            _frame_time = 0;
            _frame_rate = 1.0;
            _sprite_index = 0;
            _sprites = new std::vector<uint8_t>(0);
        }

        void set_sprites(std::vector<uint8_t> sprites)
        {
            _sprites->clear();
            for (auto sprite : sprites)
            {
                _sprites->push_back(sprite);
            }
            _sprite_index = 0;
            _sprite_count = sprites.size();
        }

        void set_fps(uint8_t fps)
        {
            _frame_rate = 1.0 / fps;
        }

        uint8_t next(uint32_t time_ms)
        {
            if (_sprite_count > 0)
            {
                if ((float)(time_ms - _frame_time) / 1000 > _frame_rate)
                {
                    _sprite_index++;
                    // Loop => back to 1st sprite
                    if (_sprite_index >= _sprite_count)
                    {
                        _sprite_index = 0;
                    }
                    _frame_time = time_ms;
                }
            }
            return (*_sprites)[_sprite_index];
        }
    };
}