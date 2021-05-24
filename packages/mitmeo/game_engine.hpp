#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "32blit.hpp"
#include "entity.hpp"

namespace mitmeo
{
    class GameEngine
    {
    private:
        uint8_t _sprite_size;
        uint32_t _current_entity_id = 0;
        std::vector<Entity *> _entities;

    public:
        GameEngine(uint8_t spriteSize = 8)
        {
            _sprite_size = spriteSize;
        }

        void init();
        void update(uint32_t time);
        void render(uint32_t time_ms);

        void add_entity(Entity *entity);
    };
}

#endif // GAME_ENGINE_H