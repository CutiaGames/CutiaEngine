#ifndef GAME_HPP
#define GAME_HPP

#include "CutiaSDL.hpp"
#include "Scene.hpp"

class Game {
  
  private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    Scene* currentScene;

  public:
    ~Game();

    void Init(int width, int height);
    static Game& getInstance();
    void run();
    SDL_Renderer* getRenderer();
    SDL_Event getEvent();

};

#endif
