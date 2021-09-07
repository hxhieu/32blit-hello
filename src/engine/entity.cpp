#include "entity.h"

namespace mitmeo
{
    namespace engine
    {
        Entity::Entity()
        {
            entt = GameEngine::GetInstance()->create_entity();
        }

        blit::Point Entity::get_position()
        {
            entt::registry *world = GameEngine::GetInstance()->get_world();
            auto pos = world->get<components::Position>(entt);
            return blit::Point(pos.x, pos.y);
        }
    }
}