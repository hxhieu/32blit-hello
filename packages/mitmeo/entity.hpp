#pragma once

#include <atomic>
#include "32blit.hpp"
#include "animated_sprite.hpp"

namespace mitmeo
{
    // Unique ID generator
    static std::atomic<uint32_t> uid{0};

    class Entity
    {
    private:
        uint32_t _id;
        AnimatedSprite *_anim;
        blit::SpriteTransform _sprite_transform;
        blit::Rect _collider;

    public:
        Entity()
        {
            _id = ++uid;
            _anim = new AnimatedSprite();
        }

        uint32_t get_id()
        {
            return _id;
        }

        uint32_t x;
        uint32_t y;

        void set_sprites(
            const std::vector<uint8_t> sprites,
            const uint8_t fps = 12,
            const blit::SpriteTransform transform = blit::SpriteTransform::NONE)
        {
            _anim->set_fps(fps);
            _anim->set_sprites(sprites);
            _sprite_transform = transform;
        }

        void update(uint32_t time)
        {
            // update the collider position
            _collider.x = -x / 2;
            _collider.y = -y / 2;
        }

        void render(uint32_t time_ms)
        {
            blit::screen.sprite(_anim->next(time_ms), blit::Point(x, y), _sprite_transform);
        }
    };
}