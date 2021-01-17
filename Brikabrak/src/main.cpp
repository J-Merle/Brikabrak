#include <iostream>
#include <SDL2/SDL.h>

#define FPS 30



int main(int argc, char** argv) {
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return 1;
  }

  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;

  window = SDL_CreateWindow(
      "Brikabrak",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      640,
      480,
      SDL_WINDOW_OPENGL
      );

  if (window == nullptr) {
    SDL_Log("Unable to create the window: %s", SDL_GetError());
    return 1;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer == nullptr) {
    SDL_Log("Unable to create the renderer: %s", SDL_GetError());
    return 1;
  }

  // Init bmp
  SDL_Texture* bitmapTexture = nullptr;
  SDL_Surface* bitmapSurface = nullptr;

  bitmapSurface = SDL_LoadBMP("Brikabrak/assets/bat.bmp");

  if (bitmapSurface == nullptr) {
    SDL_Log("Unable to create the surface: %s", SDL_GetError());
    return 1;
  }

  bitmapTexture = SDL_CreateTextureFromSurface(renderer, bitmapSurface);

  if (bitmapTexture == nullptr) {
    SDL_Log("Unable to create the texture: %s", SDL_GetError());
    return 1;
  }

  SDL_FreeSurface(bitmapSurface);

  SDL_Rect source;
  source.x = 0;
  source.y = 0;
  source.w = 16;
  source.h = 16;

  SDL_Rect source2;
  source2.x = 16;
  source2.y = 0;
  source2.w = 16;
  source2.h = 16;

  SDL_Rect dest;
  dest.x = 0;
  dest.y = 0;
  dest.w = 16;
  dest.h = 16;

  SDL_Rect dest2;
  dest2.x = 16;
  dest2.y = 0;
  dest2.w = 16;
  dest2.h = 16;

  SDL_Rect dest3;
  dest3.x = 32;
  dest3.y = 0;
  dest3.w = 16;
  dest3.h = 16;

  Uint32 startTime, endTime;

  SDL_Event event;
  while(1) {
    startTime = SDL_GetTicks();
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
      SDL_Log("Goodbye !");
      break ;
    }
    if(event.type == SDL_KEYDOWN) {
      dest.x += 7;
      dest2.x+= 7;
      dest3.x+= 7;
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bitmapTexture, &source, &dest);
    SDL_RenderCopy(renderer, bitmapTexture, &source2, &dest2);
    SDL_RenderCopyEx(renderer, bitmapTexture, &source, &dest3, 0, nullptr, SDL_FLIP_HORIZONTAL);
    SDL_RenderPresent(renderer);

    endTime = SDL_GetTicks();
    Uint32 deltaTime = endTime - startTime;

    if (deltaTime > (1000 / FPS)) {
    } else {
      SDL_Delay((1000 / FPS) - deltaTime);
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;

}
