#include "invader_sm_lgreen.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        InvaderSmallLightGreen::InvaderSmallLightGreen(int32_t x, int32_t y) : Invader(x, y)
        {
            world.emplace<components::Sprite>(
                entt,
                std::vector<uint8_t>{sprites::invader_lgreen_1, sprites::invader_lgreen_2},
                std::vector<uint8_t>{sprites::invader_lgreen_1, sprites::invader_lgreen_2},
                std::vector<uint8_t>{sprites::invader_lgreen_1, sprites::invader_lgreen_2},
                12);
            world.emplace<InvaderSmallComponent>(entt);
        }
    }
}
