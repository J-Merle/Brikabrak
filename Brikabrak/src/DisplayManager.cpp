#include <iostream>
#include "DisplayManager.h"
#include "Brikabrak.h"

DisplayManager::DisplayManager() {}
DisplayManager::~DisplayManager() {}

void DisplayManager::Init(SDL_Renderer* p_renderer) {
  this->renderer = p_renderer;
  SDL_Surface *surface = nullptr;

  surface = SDL_LoadBMP("Brikabrak/assets/bat.bmp");
  if(surface == nullptr) {
    SDL_Log("Unable to load bmp: %s", SDL_GetError());
  }
  this->texture = SDL_CreateTextureFromSurface(this->renderer, surface);
  SDL_FreeSurface(surface);
}

void DisplayManager::DisplaySprite(const Sprite& p_sprite, int x, int y) {
    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    source.w = TILE_SIZE;
    source.h = TILE_SIZE;

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = TILE_SIZE;
    dest.h = TILE_SIZE;

    int i = 0;
    for(auto const& tile: p_sprite.tiles) {
      source.x = tile.tileId * TILE_SIZE;
      dest.x = (i % p_sprite.width) * TILE_SIZE + x;
      dest.y = (i / p_sprite.width) * TILE_SIZE + y;
      SDL_RenderCopyEx(renderer, this->texture, &source, &dest, tile.angle, nullptr, tile.flip);
      i++;
    }
}
