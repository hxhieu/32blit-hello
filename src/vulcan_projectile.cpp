#include "vulcan_projectile.h"

namespace mitmeo
{
    extern entt::registry world;
    namespace blit_invaders
    {
        struct vulcan_projectile_listener
        {
            VulcanProjectile *instance;
            void receive(const events::CollisionEvent &evt)
            {
                // printf("%d\n", instance->entt);
            }
        };

        VulcanProjectile::VulcanProjectile(uint32_t x, uint32_t y) : VulcanProjectile(x, y, 0, -1) {}
        VulcanProjectile::VulcanProjectile(uint32_t x, uint32_t y, int8_t dir_x, int8_t dir_y)
        {
            world.emplace<components::Sprite>(
                entt,
                std::vector<uint8_t>{sprites::vulcan_1, sprites::vulcan_2});
            world.emplace<components::Velocity>(entt, dir_x, dir_y, 1);
            // Center pivot
            world.emplace<components::Position>(entt, x, y);
            world.emplace<components::AutoDestroy>(entt);
            world.emplace<components::Collider>(entt, 8, 8, 0, -4);

            vulcan_projectile_listener listener = vulcan_projectile_listener{this};
            dispatcher.sink<events::CollisionEvent>().connect<&vulcan_projectile_listener::receive>(listener);
            printf("%d\n", entt);
        }

        void VulcanProjectile::OnCollision(const events::CollisionEvent &evt)
        {
            printf("%d %d %d\n", (uint32_t)this->entt, evt.actor1, evt.actor2);
            if (evt.actor1 == entt || evt.actor2 == entt)
            {
                world.destroy(entt);
            }
        }
    }
}