#include "update_system.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        // struct PlayerUpdateComponent;
        // typedef void (*PlayerUpdateCallback)(Player *player, uint32_t time_ms);
        // typedef struct PlayerUpdate
        // {
        //     PlayerUpdateCallback update; // The callback to run the update logic
        // } PlayerUpdate;

        UpdateSystem::UpdateSystem() {}

        void UpdateSystem::run(entt::registry &world, uint32_t time_ms)
        {
            // Update callback
            // auto playerUpdate = world.view<PlayerUpdateComponent>();
            // for (auto e : playerUpdate)
            // {
            //     auto &u = playerUpdate.get<PlayerUpdateComponent>(e);

            // }
        }
    }
}