#pragma once

#include "32blit.hpp"
#include "../../packages/mitmeo/entity.hpp"

namespace mitmeo
{
    class Fighter : public Entity
    {
    private:
        uint32_t _sprite_size = 8;

    public:
        void update(uint32_t time);
        void render(uint32_t time_ms);
    };
}