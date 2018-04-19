#include "Game.hpp"

Game* Game::instance = nullptr;

Game& Game::GetInstance()
{
    if(instance == nullptr)
    {
        instance = new Game; 
    }

    return *instance;
}

void Game::Init(int width, int height)
{
    
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        printf("[ERROR] SDL_Init: %s\n", SDL_GetError());
        return;
    }

    int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if(IMG_Init(imageFlags) != imageFlags)
    {
        printf("[ERROR] IMG_Init: %s\n", IMG_GetError());
        return;
    }

    window = SDL_CreateWindow("CutiaEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == nullptr)
    {
        printf("[ERROR] SDL_CreateWindow: %s\n", Mix_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        printf("[ERROR] SDL_CreateRenderer: %s\n", SDL_GetError());
        return;
    }

    state = new State();
    instance = this;
}

Game::~Game()
{    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    delete state;
}

State& Game::GetState()
{
    return *state;
}

SDL_Renderer* Game::GetRenderer()
{
    return renderer;
}

void Game::Run()
{
    while(not state->QuitRequested())
    {
        state->Render();
        state->Update(0.0);

        SDL_RenderPresent(renderer);

        SDL_Delay(33);
    }
}
