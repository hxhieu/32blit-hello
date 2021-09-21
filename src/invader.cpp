#include "invader.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        Invader::Invader(int32_t x, int32_t y)
        {
            world.emplace<components::Position>(entt, x, y);
            world.emplace<components::Velocity>(entt, 0, 0, 1);
            world.emplace<components::Collider>(entt, 16, 16);
            world.emplace<InvaderComponent>(entt);
        }
    }
}
