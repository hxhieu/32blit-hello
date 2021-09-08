#include "vulcan_projectile.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        VulcanProjectile::VulcanProjectile(uint32_t x, uint32_t y) : VulcanProjectile(x, y, 0, -1) {}
        VulcanProjectile::VulcanProjectile(uint32_t x, uint32_t y, int8_t dir_x, int8_t dir_y)
        {
            world.emplace<components::Sprite>(
                entt,
                std::vector<uint8_t>{sprites::vulcan_1, sprites::vulcan_2});
            world.emplace<components::Velocity>(entt, dir_x, dir_y, 2);
            // Center pivot
            world.emplace<components::Position>(entt, x - 4, y - 4);
            world.emplace<components::AutoDestroy>(entt);
        }
    }
}