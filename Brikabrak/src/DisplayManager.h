#pragma once
#include <SDL2/SDL.h>
#include "Sprite.h"

class DisplayManager {
public:
  DisplayManager();
  ~DisplayManager();
  void Init(SDL_Renderer* renderer);
  void DisplaySprite(const Sprite& sprite, int x, int y);

private:
  SDL_Renderer* renderer;
  SDL_Texture* texture;
};

