#include "entity.h"

namespace mitmeo
{
    namespace engine
    {
        Entity::Entity()
        {
            entt = GameEngine::GetInstance()->create_entity();
        }
    }
}