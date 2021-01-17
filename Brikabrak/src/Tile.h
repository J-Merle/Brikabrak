#pragma once
#include <SDL2/SDL.h>

class Tile {
public:
  Tile();
  Tile(unsigned short p_tileId, double p_angle, SDL_RendererFlip p_flip);
  ~Tile();
  unsigned short tileId;
  double angle;
  SDL_RendererFlip flip;
};
