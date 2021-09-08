#include "update_system.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        UpdateSystem::UpdateSystem() {}

        void UpdateSystem::run(entt::registry &world, uint32_t time_ms)
        {
            // Player
            auto playerRef = world.view<components::Ref<Player>>();
            for (auto e : playerRef)
            {
                auto &r = playerRef.get<components::Ref<Player>>(e);
                if (r.instance != nullptr)
                {
                    r.instance->update(time_ms);
                }
            }
        }
    }
}