#include "game_engine.hpp"

namespace mitmeo
{
    void GameEngine::render(uint32_t time_ms)
    {
        for (auto i : _entities)
        {
            i->render(time_ms);
        }
    }

    void GameEngine::update(uint32_t time_ms)
    {
        for (auto i : _entities)
        {
            i->update(time_ms);
        }
    }

    void GameEngine::add_entity(Entity *entity)
    {
        entity->set_id(++_current_entity_id);
        _entities.push_back(entity);
    }
}