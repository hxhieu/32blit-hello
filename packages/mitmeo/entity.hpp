#ifndef ENTITY_H
#define ENTITY_H

#include "32blit.hpp"

namespace mitmeo
{
    class Entity
    {
    private:
        uint32_t _id;

    public:
        uint32_t id() const
        {
            return _id;
        }

        void set_id(uint32_t id)
        {
            _id = id;
        }

        virtual void init() = 0;
        virtual void update(uint32_t time) = 0;
        virtual void render(uint32_t time_ms) = 0;
    };
}

#endif // ENTITY_H