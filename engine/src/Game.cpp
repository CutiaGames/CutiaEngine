#include "Game.hpp"
#include "Resources.hpp"
#include "InputManager.hpp"
#include "GameData.hpp"

Game* Game::instance = nullptr;
bool GameData::playerVictory = false;

Game& Game::GetInstance()
{
    if(instance == nullptr)
    {
        instance = new Game; 
    }

    return *instance;
}

void Game::Init(string title, int width, int height)
{
    this->height = height;
    this->width = width;

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

    int mixFlags = MIX_INIT_OGG | MIX_INIT_MP3;
    if(Mix_Init(mixFlags) != mixFlags)
    {
      printf("[ERROR] Mix_Init: %s\n", Mix_GetError());
      return;
    }

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
    {
        printf("[ERROR] Mix_OpenAudio: %s\n", Mix_GetError());
        return;
    }

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
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

    if(TTF_Init() != 0)
    {
        printf("[ERROR] TTF_Init: %s\n", SDL_GetError());
        return;   
    }

    storedScene = nullptr;
    dt = 0.f;
    frameStart = SDL_GetTicks();
}

Game::~Game()
{    
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();

    if(storedScene != nullptr)
    {
        delete storedScene;
    }

    while(not sceneStack.empty())
    {
        sceneStack.pop();
    }

    Resources::ClearSounds();
    Resources::ClearMusics();
    Resources::ClearImages(); 
}

Scene& Game::GetCurrentScene()
{
    return *sceneStack.top();
}

SDL_Renderer* Game::GetRenderer()
{
    return renderer;
}

void Game::Push(Scene* scene)
{
    storedScene = scene;
}

void Game::Run()
{
    if(storedScene == nullptr)
    {
        return;
    }
    
    sceneStack.push((std::unique_ptr<Scene>)storedScene);

    while(not sceneStack.empty() && not sceneStack.top()->QuitRequested())
    {
        if(sceneStack.top()->PopRequested())
        {
            sceneStack.pop();
            if(not sceneStack.empty())
            {
                sceneStack.top()->Resume();
            }
        }

        if(sceneStack.empty())
            break;

        if(storedScene != nullptr)
        {
            if(not sceneStack.empty())
            {
                sceneStack.top()->Pause();
            }
            sceneStack.push((std::unique_ptr<Scene>)storedScene);
            sceneStack.top()->Start();
            storedScene = nullptr;
        }
        
        CalculateDeltaTime();
        sceneStack.top()->Render();
        InputManager::GetInstance().Update();
        sceneStack.top()->Update(dt);
        
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

        SDL_Delay(33);
    }

    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
}

void Game::CalculateDeltaTime()
{
    int elapsedTime = SDL_GetTicks();
    dt = (elapsedTime - frameStart)/100.f;
    frameStart = elapsedTime;
}

float Game::GetDeltaTime()
{
    return dt;
}

int Game::GetHeight()
{
    return height;
}

int Game::GetWidth()
{
    return width;
}