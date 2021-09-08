#include "entity.h"

namespace mitmeo
{
    namespace engine
    {
        Entity::Entity()
        {
            entt = world.create();
        }

        blit::Point Entity::get_position()
        {
            auto pos = world.get<components::Position>(entt);
            return blit::Point(pos.x, pos.y);
        }
    }
}