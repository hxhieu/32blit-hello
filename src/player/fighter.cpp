#include "fighter.hpp"

namespace mitmeo
{
    void Fighter::update(uint32_t time)
    {
        bool button_a = blit::buttons & blit::Button::A;
        bool button_b = blit::buttons & blit::Button::B;
        bool button_x = blit::buttons & blit::Button::X;
        bool button_y = blit::buttons & blit::Button::Y;
        bool button_m = blit::buttons & blit::Button::MENU;
        bool button_h = blit::buttons & blit::Button::HOME;
        bool dpad_l = blit::buttons & blit::Button::DPAD_LEFT;
        bool dpad_r = blit::buttons & blit::Button::DPAD_RIGHT;
        bool dpad_u = blit::buttons & blit::Button::DPAD_UP;
        bool dpad_d = blit::buttons & blit::Button::DPAD_DOWN;

        if (dpad_l)
        {
            x -= 0.5;
        }

        if (dpad_r)
        {
            x += 1;
        }

        if (dpad_u)
        {
            y -= 1;
        }

        if (dpad_d)
        {
            y += 1;
        }
    }

    void Fighter::render(uint32_t time_ms)
    {
        blit::screen.sprite(0, blit::Point(x, y));
    }
}