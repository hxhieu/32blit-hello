#pragma once

#include "32blit.hpp"
#include "../../packages/mitmeo/entity.hpp"

namespace mitmeo
{
    class Fighter : public Entity
    {
    private:
    public:
        Fighter()
        {
            blit::Size screen_size = blit::screen.bounds;
            x = (screen_size.w - 8) / 2;
            y = screen_size.h - 40;
            set_sprites(std::vector<uint8_t>{3, 19});
        }
        void update(uint32_t time);
        void render(uint32_t time_ms);
    };
}