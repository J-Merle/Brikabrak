#include "Application.h"

#define FPS 30

Application::Application() {
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

Application::~Application() {
  this->Clean();
}

void Application::Run() {
  Uint32 startTime, endTime;

  SDL_Event event;
  while(1) {
    startTime = SDL_GetTicks();
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
      break ;
    }

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
