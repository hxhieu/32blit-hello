#pragma once

#include "32blit.hpp"
#include "../../packages/mitmeo/entity.hpp"
#include "../const.hpp"

namespace mitmeo
{
    namespace blit_invaders
    {
        class Fighter : public Entity
        {
        private:
            uint32_t _last_fire_time;

            void do_fire();

        public:
            Fighter()
            {
                blit::Size screen_size = blit::screen.bounds;
                x = (screen_size.w - 8) / 2;
                y = screen_size.h - 16;
                set_sprites(std::vector<uint8_t>{sprites::player_idle});
            }

            uint32_t fire_interval = 500;

            void update(uint32_t time_ms);
            void render(uint32_t time_ms);
        };
    }
}