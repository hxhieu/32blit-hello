#pragma once

#include "32blit.hpp"
#include "libs/flecs.h"
#include "entity.hpp"
#include "render_system.hpp"

namespace mitmeo
{
    class GameEngine
    {
    private:
        static GameEngine *_instance;
        uint32_t _current_entity_id = 0;
        std::vector<Entity *> _entities;
        flecs::world _world;
        flecs::system<components::Sprite, components::Position> _render_system;

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
        }
        void internal_render(uint32_t time_ms)
        {
            _render_system.run(_world.delta_time());
        }
        void internal_add_entity(Entity *entity)
        {
            _entities.push_back(entity);
        }
        flecs::entity internal_add_entity(const char *name)
        {
            return _world.entity(name);
        }

    public:
        static void update(uint32_t time_ms);
        static void render(uint32_t time_ms);
        static void add_entity(Entity *entity);
        static flecs::entity add_entity(const char *name);
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

    flecs::entity GameEngine::add_entity(const char *name)
    {
        return get_instance().internal_add_entity(name);
    }

    GameEngine::GameEngine()
    {
        _world.set_target_fps(30);
        _render_system = RenderSystem::create(_world);
    }

    GameEngine::~GameEngine()
    {
        delete _instance;
        _instance = nullptr;
    }
}