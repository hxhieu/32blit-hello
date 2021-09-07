#pragma once

#include "32blit.hpp"
#include "entt.hpp"
#include "render_system.h"
#include "movement_system.h"
#include "logic_system.h"

namespace mitmeo
{
    namespace engine
    {
        /**
         * The Singleton class defines the `GetInstance` method that serves as an
         * alternative to constructor and lets clients access the same instance of this
         * class over and over.
         */
        class GameEngine
        {

            /**
             * The Singleton's constructor/destructor should always be private to
             * prevent direct construction/desctruction calls with the `new`/`delete`
             * operator.
             */
        private:
            static GameEngine *_instance;
            entt::registry _world;
            MovementSystem _movement_system;
            RenderSystem _render_system;
            LogicSystem _logic_system;

            GameEngine();
            ~GameEngine();

        public:
            /**
             * Singletons should not be cloneable.
             */
            GameEngine(GameEngine &other) = delete;
            /**
             * Singletons should not be assignable.
             */
            void operator=(const GameEngine &) = delete;
            /**
             * This is the static method that controls the access to the singleton
             * instance. On the first run, it creates a singleton object and places it
             * into the static field. On subsequent runs, it returns the client existing
             * object stored in the static field.
             */
            static GameEngine *GetInstance();
            /**
             * Finally, any singleton should define some business logic, which can be
             * executed on its instance.
             */
            void update(uint32_t time_ms);
            void render(uint32_t time_ms);
            entt::entity create_entity();
            entt::registry *get_world();
        };
    }
}