#pragma once

#include "entity.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        class Invader : public engine::Entity
        {
        public:
            Invader(int32_t x, int32_t y);
        };

        struct InvaderComponent : public components::Vital
        {
        };

        // Separate structs to distinguish the invader types
        struct InvaderSmallComponent
        {
        };

        struct InvaderLargeComponent
        {
        };

    }
}
