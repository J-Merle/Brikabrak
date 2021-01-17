#pragma once
#include <vector>
#include "Tile.h"

class Sprite {
public:
  Sprite() : Sprite(1,1) {};
  Sprite(unsigned short p_width, unsigned short p_height);
  ~Sprite();
  void AddTile(Tile p_tile);
  unsigned short width;
  unsigned short height;
  std::vector<Tile> tiles;

};
