#pragma once

#include <atomic>
#include "32blit.hpp"

namespace mitmeo
{
    // Unique ID generator
    static std::atomic<uint32_t> uid{0};

    class Entity
    {
    private:
        uint32_t _id;

    public:
        Entity()
        {
            _id = ++uid;
        }

        uint32_t get_id()
        {
            return _id;
        }

        uint32_t x;
        uint32_t y;

        virtual void update(uint32_t time) = 0;
        virtual void render(uint32_t time_ms) = 0;
    };
}