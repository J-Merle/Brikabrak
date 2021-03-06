#pragma once
#include <SDL2/SDL.h>

class Application {
public:
  Application();
  ~Application();
  void Run();
  void Clean();

private:
  void InitSDL();
  SDL_Window* window;
  SDL_Renderer* renderer;

};
