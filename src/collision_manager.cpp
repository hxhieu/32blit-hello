#include "collision_manager.h"

namespace mitmeo
{
    extern entt::registry world;
    namespace blit_invaders
    {
        std::unordered_set<std::string> collision_map{};

        CollisionManager::CollisionManager() {}

        CollisionActor CollisionManager::GetCollisionActor(
            entt::entity e,
            components::Collider *c,
            components::Position *p,
            components::Vital *v)
        {
            // Based on current position
            auto r = blit::Rect{
                p->x + (int32_t)c->x,
                p->y + (int32_t)c->y,
                (int32_t)c->w,
                (int32_t)c->h};

            return CollisionActor{
                e,
                // Half-extents
                blit::Rect{
                    r.x - r.w / 2,
                    r.y - r.h / 2,
                    r.w,
                    r.h},
                v->hp};
        }

        std::string CollisionManager::GetCollisionKey(CollisionActor actor1, CollisionActor actor2)
        {
            return std::to_string((uint32_t)actor1.actor) + "x" + std::to_string((uint32_t)actor2.actor);
        }

        bool CollisionManager::FirstContact(CollisionActor actor1, CollisionActor actor2)
        {
            auto key = GetCollisionKey(actor1, actor2);
            if (collision_map.find(key) == collision_map.end() && actor1.collider.intersects(actor2.collider))
            {
                collision_map.emplace(key);
                return true;
            }
            return false;
        }

        void CollisionManager::ResolveCollision(CollisionActor actor1, CollisionActor actor2)
        {
            collision_map.erase(GetCollisionKey(actor1, actor2));
        }

        void CollisionManager::run(uint32_t time_ms)
        {
            // Player projectiles
            auto playerProjectiles = world.view<components::Projectile<Player>, components::Collider, components::Position>();
            auto playerProjectileActors = std::vector<CollisionActor>{};
            for (auto e : playerProjectiles)
            {
                auto &v = playerProjectiles.get<components::Projectile<Player>>(e);
                auto &p = playerProjectiles.get<components::Position>(e);
                auto &c = playerProjectiles.get<components::Collider>(e);
                playerProjectileActors.emplace_back(GetCollisionActor(e, &c, &p, &v));
            }

            // Small invaders
            auto smallInvaders = world.view<InvaderSmallComponent, components::Collider, components::Position>();
            auto smallInvaderActors = std::vector<CollisionActor>{};
            for (auto e : smallInvaders)
            {
                auto &v = smallInvaders.get<InvaderSmallComponent>(e);
                auto &p = smallInvaders.get<components::Position>(e);
                auto &c = smallInvaders.get<components::Collider>(e);
                smallInvaderActors.emplace_back(GetCollisionActor(e, &c, &p, &v));
            }

            // Check player projectiles vs small invaders collision
            for (auto i : smallInvaderActors)
            {
                for (auto p : playerProjectileActors)
                {
                    if (FirstContact(i, p))
                    {
                        printf("hit!!!\n");
                    }
                }
            }
        }
    }
}