#include "fighter.hpp"

namespace mitmeo
{
    namespace blit_invaders
    {
        void Fighter::update(uint32_t time_ms)
        {
            bool button_a = blit::buttons & blit::Button::A;
            // bool button_b = blit::buttons & blit::Button::B;
            // bool button_x = blit::buttons & blit::Button::X;
            // bool button_y = blit::buttons & blit::Button::Y;
            // bool button_m = blit::buttons & blit::Button::MENU;
            // bool button_h = blit::buttons & blit::Button::HOME;
            bool dpad_l = blit::buttons & blit::Button::DPAD_LEFT;
            bool dpad_r = blit::buttons & blit::Button::DPAD_RIGHT;
            // bool dpad_u = blit::buttons & blit::Button::DPAD_UP;
            // bool dpad_d = blit::buttons & blit::Button::DPAD_DOWN;

            set_sprites(std::vector<uint8_t>{sprites::player_idle});
            if (dpad_l)
            {
                x -= 1;
                set_sprites(std::vector<uint8_t>{sprites::player_left});
            }

            if (dpad_r)
            {
                x += 1;
                set_sprites(std::vector<uint8_t>{sprites::player_right});
            }

            if (button_a)
            {
                if (time_ms - _last_fire_time >= fire_interval)
                {
                    do_fire();
                    _last_fire_time = time_ms;
                }
            }
        }

        void Fighter::do_fire()
        {
            printf("fire1!!\n");
        }
        // void Fighter::render(uint32_t time_ms)
        // {
        //     blit::screen.sprite(1, blit::Point(x, y));
        //     blit::debug(std::to_string(time_ms) + ", ");
        // }
    }
}