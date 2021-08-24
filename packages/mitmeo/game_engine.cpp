#include "game_engine.hpp"

namespace mitmeo
{
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

    GameEngine::GameEngine()
    {
    }

    GameEngine::~GameEngine()
    {
        delete _instance;
        _instance = nullptr;
    }

    void GameEngine::internal_render(uint32_t time_ms)
    {
        for (auto i : _entities)
        {
            i->render(time_ms);
        }
    }

    void GameEngine::internal_update(uint32_t time_ms)
    {
        for (auto i : _entities)
        {
            i->update(time_ms);
        }
    }

    void GameEngine::internal_add_entity(Entity *entity)
    {
        _entities.push_back(entity);
    }
}