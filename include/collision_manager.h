#pragma once

#include <string>
#include "player.h"
#include "vulcan_projectile.h"
#include "invader_sm_lgreen.h"

namespace mitmeo
{
    namespace blit_invaders
    {
        // Manage the set of AxB collision so it won't get re-process per frame
        extern std::unordered_set<std::string> collision_map;
        struct CollisionActor
        {
            entt::entity actor;
            blit::Rect collider;
            int32_t life;
        };

        class CollisionManager
        {
        private:
            CollisionActor GetCollisionActor(
                entt::entity e,
                components::Collider *c,
                components::Position *p,
                components::Vital *v);

            bool FirstContact(CollisionActor actor1, CollisionActor actor2);
            void ResolveCollision(CollisionActor actor1, CollisionActor actor2);
            std::string GetCollisionKey(CollisionActor actor1, CollisionActor actor2);

        public:
            CollisionManager();
            void run(uint32_t time_ms);
        };
    }
}