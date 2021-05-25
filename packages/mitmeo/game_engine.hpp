#pragma once

#include "32blit.hpp"
#include "entity.hpp"

namespace mitmeo
{
    class GameEngine
    {
    private:
        static GameEngine *_instance;
        uint32_t _current_entity_id = 0;
        std::vector<Entity *> _entities;

        GameEngine();
        ~GameEngine();

        static GameEngine &get_instance()
        {
            if (!_instance)
            {
                _instance = new GameEngine();
            }
            return *_instance;
        }

        void internal_update(uint32_t time);
        void internal_render(uint32_t time_ms);
        void internal_add_entity(Entity *entity);

    public:
        static void update(uint32_t time);
        static void render(uint32_t time_ms);
        static void add_entity(Entity *entity);
        static void terminate();
    };
}