#include <iostream>
#include "Application.h"
#include "Sprite.h"
#include "Tile.h"
#include "Brikabrak.h"

#define FPS 60

Application::Application() {
  this->InitSDL();
}

Application::~Application() {
  this->Clean();
}

void Application::Run() {
  Tile* tile1 = new Tile(0, 0, SDL_FLIP_NONE);
  Tile* tile2 = new Tile(1, 0, SDL_FLIP_NONE);
  Tile* tile3 = new Tile(0, 0, SDL_FLIP_HORIZONTAL);

  Sprite* sprite = new Sprite(3, 1);
  sprite->AddTile(*tile1);
  sprite->AddTile(*tile2);
  sprite->AddTile(*tile3);

  SDL_Surface *surface = nullptr;
  SDL_Texture *texture = nullptr;

  surface = SDL_LoadBMP("Brikabrak/assets/bat.bmp");
  if(surface == nullptr) {
    SDL_Log("Unable to load bmp: %s", SDL_GetError());
  }
  texture = SDL_CreateTextureFromSurface(this->renderer, surface);
  SDL_FreeSurface(surface);

  Uint32 startTime, endTime;

  SDL_Event event;
  while(1) {
    startTime = SDL_GetTicks();
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
      break ;
    }


    SDL_Rect source;
    source.x = 0;
    source.y = 0;
    source.w = TILE_SIZE;
    source.h = TILE_SIZE;

    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.w = TILE_SIZE;
    dest.h = TILE_SIZE;

    SDL_RenderClear(renderer);

    int i = 0;
    for(auto const& tile: sprite->tiles) {
      source.x = tile.tileId * TILE_SIZE;
      dest.x = i * TILE_SIZE;
      SDL_RenderCopyEx(renderer, texture, &source, &dest, tile.angle, nullptr, tile.flip);


      i++;
    }
    SDL_RenderPresent(renderer);

    endTime = SDL_GetTicks();
    Uint32 deltaTime = endTime - startTime;

    if (deltaTime > (1000 / FPS)) {
    } else {
      SDL_Delay((1000 / FPS) - deltaTime);
    }
  }

}

void Application::Clean() {
  if (this->renderer != nullptr) {
    SDL_DestroyRenderer(renderer);
    SDL_Log("Destroying renderer");
  }
  if (this->window != nullptr) {
    SDL_DestroyWindow(window);
    SDL_Log("Destroying window");
  }
  SDL_Quit();
}

void Application::InitSDL() {
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    this->Clean();
  }

  this->window = SDL_CreateWindow(
      "Brikabrak",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      640,
      480,
      SDL_WINDOW_OPENGL
  );

  if (this->window == nullptr) {
    SDL_Log("Unable to create the window: %s", SDL_GetError());
    this->Clean();
  }

  this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer == nullptr) {
    SDL_Log("Unable to create the renderer: %s", SDL_GetError());
    this->Clean();
  }

}
