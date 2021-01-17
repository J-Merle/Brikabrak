#include "Sprite.h"

Sprite::Sprite(unsigned short p_width, unsigned short p_height) {
  this->width = p_width;
  this->height = p_height;
}

Sprite::~Sprite() {}

void Sprite::AddTile(Tile p_tile) {
  if(this->tiles.size() < (this->width * this->height)) {
    this->tiles.push_back(p_tile);
  }

}
