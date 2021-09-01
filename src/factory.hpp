#pragma once

#include "../packages/mitmeo/libs/entt.hpp"
#include "../packages/mitmeo/components.hpp"
#include "const.hpp"

namespace mitmeo
{
    using namespace components;
    namespace blit_invaders
    {
        entt::entity create_player(entt::registry *world)
        {
            auto e = world->create();
            world->emplace<Position>(e, 40, 40);
            world->emplace<Sprite>(e, std::vector<uint8_t>{sprites::player_idle}, 30);
            return e;
        }
    }
}