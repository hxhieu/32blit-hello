#ifndef PLAYER_FIGHTER_H
#define PLAYER_FIGHTER_H

#include "32blit.hpp"
#include "../../packages/mitmeo/entity.hpp"

namespace mitmeo
{
    class Fighter : public Entity
    {
    private:
        uint32_t _sprite_size = 8;

    public:
        void init();
        void update(uint32_t time);
        void render(uint32_t time_ms);
    };
}

#endif // PLAYER_FIGHTER_H