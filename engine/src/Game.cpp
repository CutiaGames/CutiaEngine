#include "Game.hpp"


Game* Game::instance = nullptr;

Game& Game::getInstance(){

    if(instance == nullptr){
        instance = new Game;
    }

    return *instance;
}

void Game::Init(int width, int height){

    //TODO: Crash when fail init
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
        printf("[ERROR] SDL_Init: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
    if(IMG_Init(imageFlags) != imageFlags){
        printf("[ERROR] IMG_Init: %s\n", IMG_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("CutiaEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == nullptr){
        printf("[ERROR] SDL_CreateWindow: %s\n", Mix_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        printf("[ERROR] SDL_CreateRenderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    currentScene = Scene();
    currentScene.setup();

    instance = this;
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


SDL_Renderer* Game::getRenderer(){
    return renderer;
}

SDL_Event Game::getEvent(){
    return event;
}

void Game::run(){

    while(1){

        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) break;

        //Update
        currentScene.update();

        SDL_RenderClear(renderer);
        //Render
        currentScene.render();
        SDL_RenderPresent(renderer);

        SDL_Delay(33);
    }
}
