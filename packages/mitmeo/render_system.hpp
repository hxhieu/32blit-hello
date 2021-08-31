#pragma once

#include "32blit.hpp"
#include "libs/flecs.h"
#include "components.hpp"
#include "animated_sprite.hpp"

namespace mitmeo
{
    using namespace components;

    namespace RenderSystem
    {
        flecs::system<Sprite, Position> create(flecs::world &world)
        {
            auto system =
                world.system<Sprite, Position>("Render")
                    .kind(flecs::OnUpdate)
                    .each([](flecs::entity e, Sprite &s, Position &p)
                          {
                              // Sprite animations
                              auto sprite_count = s.sprites.size();
                              auto frame_rate = (float)1 / s.fps;
                              if (sprite_count > 0)
                              {
                                  s.delta_time += e.delta_time();

                                  if (s.delta_time >= frame_rate)
                                  {
                                      s.sprite_index++;
                                      // Loop => back to 1st sprite
                                      if (s.sprite_index >= sprite_count)
                                      {
                                          s.sprite_index = 0;
                                      }
                                      s.delta_time = 0;
                                  }
                              }

                              blit::screen.sprite(s.sprites[s.sprite_index], blit::Point(p.x, p.y));
                          });
            return system;
        }
    }
}