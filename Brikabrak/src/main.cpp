#include "Application.h"

int main(int argc, char** argv) {
  Application* app = new Application();

  app->Run();

  app->Clean();

  return 0;

}
