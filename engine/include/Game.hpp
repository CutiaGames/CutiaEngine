#ifndef GAME_HPP
#define GAME_HPP

#include "CutiaSDL.hpp"
#include "Scene.hpp"
#include "InputManager.hpp"
#include <string>

class Game {
  
  private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    Scene* currentScene;
    InputManager* inputManager;

  public:
    ~Game();

    void Init(int width, int height, Scene* initialScene);
    static Game& getInstance();
    void run();

    SDL_Renderer* getRenderer();
    SDL_Event getEvent();    

    // Input Manager interface
    bool buttonDown(const std::string& buttonName);

};

#endif
