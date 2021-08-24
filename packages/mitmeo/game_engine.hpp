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

        void internal_update(uint32_t time)
        {
            for (auto i : _entities)
            {
                i->update(time);
            }
        }
        void internal_render(uint32_t time_ms)
        {
            for (auto i : _entities)
            {
                i->render(time_ms);
            }
        }
        void internal_add_entity(Entity *entity)
        {
            _entities.push_back(entity);
        }

    public:
        static void update(uint32_t time_ms);
        static void render(uint32_t time_ms);
        static void add_entity(Entity *entity);
    };

    // Allocate the memory
    GameEngine *GameEngine::_instance = nullptr;

    void GameEngine::update(uint32_t time_ms)
    {
        get_instance().internal_update(time_ms);
    }

    void GameEngine::render(uint32_t time_ms)
    {
        get_instance().internal_render(time_ms);
    }

    void GameEngine::add_entity(Entity *entity)
    {
        get_instance().internal_add_entity(entity);
    }

    GameEngine::GameEngine() {}

    GameEngine::~GameEngine()
    {
        delete _instance;
        _instance = nullptr;
    }
}