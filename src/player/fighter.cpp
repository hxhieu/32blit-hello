#include "fighter.hpp"

using namespace blit;

namespace mitmeo
{
    void Fighter::init()
    {
    }

    void Fighter::update(uint32_t time)
    {
    }

    void Fighter::render(uint32_t time_ms)
    {
        Size screen_size = screen.bounds;
        screen.sprite(0, Point((screen_size.w - _sprite_size) / 2, screen_size.h - 40));
    }
}