#include "game_engine.h"

namespace mitmeo
{
    namespace engine
    {

        /**
         * Static methods should be defined outside the class.
         */

        GameEngine *GameEngine::_instance{nullptr};

        /**
         * The first time we call GetInstance we will lock the storage location
         *      and then we make sure again that the variable is null and then we
         *      set the value. RU:
         */
        GameEngine *GameEngine::GetInstance()
        {
            if (_instance == nullptr)
            {
                _instance = new GameEngine();
            }
            return _instance;
        }

        GameEngine::GameEngine() {}

        entt::entity GameEngine::create_entity()
        {
            return _world.create();
        }

        entt::registry *GameEngine::get_world()
        {
            return &_world;
        }

        void GameEngine::update(uint32_t time_ms)
        {
            _logic_system.run(_world, time_ms);
            _movement_system.run(_world, time_ms);
        }

        void GameEngine::render(uint32_t time_ms)
        {
            _render_system.run(_world, time_ms);
        }
    }
}