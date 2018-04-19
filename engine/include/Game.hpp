#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "State.hpp"

using std::string;

class Game
{
  private:
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;

  public:
    ~Game();

    void Init(int width, int height);
    static Game& GetInstance();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();

};

#endif
