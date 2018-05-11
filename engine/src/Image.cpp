#include "Image.hpp"
#include "Game.hpp"
#include "CutiaSDL.hpp"
#include <string.h>

using std::string;

void Image::render(){

    SDL_Renderer* screen = Game::getInstance().getRenderer();
    SDL_Rect renderQuad = {x, y, width, height};
    SDL_RenderCopy(screen, image, NULL, &renderQuad);

    screen = NULL;
}

void Image::update(){
    x += 1;
}


SDL_Texture* Image::loadImage(std::string path){

    SDL_Surface* surface = NULL;

    path = ASSETS_PATH + path;

    surface = IMG_Load(path.c_str());

    if (surface == NULL) {
        printf("Image surface failed loading.\n");
        std::exit(EXIT_FAILURE);
    }

    SDL_Renderer* screen = Game::getInstance().getRenderer();

    SDL_Texture* texture = SDL_CreateTextureFromSurface(screen, surface);

    if (texture == NULL){
        printf("Texture failed loading.\n");
        std::exit(EXIT_FAILURE);
    }

    width = surface->w;
    height = surface->h;

    SDL_FreeSurface(surface);
    surface = NULL;
    screen = NULL;

    return texture;
}



