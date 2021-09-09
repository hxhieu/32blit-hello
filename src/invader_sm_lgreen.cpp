#include "invader_sm_lgreen.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        InvaderSmallLightGreen::InvaderSmallLightGreen()
        {
            world.emplace<components::Sprite>(
                entt,
                std::vector<uint8_t>{sprites::invader_lgreen_1, sprites::invader_lgreen_2},
                std::vector<uint8_t>{sprites::invader_lgreen_1, sprites::invader_lgreen_2},
                std::vector<uint8_t>{sprites::invader_lgreen_1, sprites::invader_lgreen_2},
                12);
            world.emplace<components::Velocity>(entt, 0, 0, 1);
            world.emplace<components::Position>(entt, 100, 100);
            world.emplace<InvaderSmallComponent>(entt);
        }
    }
}