#include "Game.hpp"
#include "Scene.hpp"

Game* Game::instance = nullptr;

Game& Game::getInstance(){

    if(instance == nullptr){
        instance = new Game;
        instance->inputManager = new InputManager();
    }

    return *instance;
}

void Game::Init(int width, int height, Scene* initialScene){

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

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if(renderer == nullptr){
        printf("[ERROR] SDL_CreateRenderer: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) < 0 ){
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
        exit(EXIT_FAILURE);
    }

    currentScene = initialScene;
    currentScene->setup();

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

bool Game::buttonDown(const std::string& buttonName){
    return inputManager->is_button_down(buttonName);
}

void Game::run(){

    bool loop = true;

    while(loop){

        SDL_Event evt;
        while(SDL_PollEvent(&evt) != 0) {
            switch(evt.type) {
                case SDL_QUIT:
                    loop = false;
                    break;
                default:
                    inputManager->gather_input(evt);
                    break;
            }
        }

        //Update
        currentScene->update();

        //Clear screen
        SDL_RenderClear(renderer);

        //Render
        currentScene->render();
        SDL_RenderPresent(renderer);

        //Clear input
        inputManager->clear_input();

        SDL_Delay(13);
    }
}
