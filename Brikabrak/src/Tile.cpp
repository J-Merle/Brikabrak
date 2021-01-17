#include "Tile.h"

Tile::Tile() {}

Tile::Tile(unsigned short p_tileId, double p_angle, SDL_RendererFlip p_flip) {
  this->tileId = p_tileId;
  this->angle = p_angle;
  this->flip = p_flip;
}

Tile::~Tile() {}
