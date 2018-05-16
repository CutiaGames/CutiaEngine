#include "SceneGuitar.hpp"
#include "Image.hpp"
#include "Game.hpp"
#include "CutiaSDL.hpp"
#include <math.h>

void SceneGuitar::createNewNoteAtTop(){
    
    // printf("Scene:setup\n");
    GameObject* note = new GameObject();

    //Component
    Component* image = new Image("circle.png");
    note->x = 100;
    note->y = 0;

    note->addComponent(image);

    objs.push_back(note);
}

void SceneGuitar::setup(){
    // printf("SceneGuitar:setup\n");
}

void SceneGuitar::update(){
    Scene::update();
    // printf("SceneGuitar:update\n");
    
    if(ticks > 30){
        createNewNoteAtTop();
        ticks = 0;
    }

    SDL_Event event;
    SDL_PollEvent(&event);

    int didClicked = 0;
    if (event.type == SDL_KEYDOWN) {
        didClicked = 1;
        printf("Click received.\n");
    }

    for (auto e_obj : objs) {

        if(didClicked == 1){

            if ( abs(e_obj->y - 600) < 20 ){
                e_obj->x += 100;
                e_obj->y = 400;
            }
        }

        if (e_obj->y > 700){
            //remove obj from vector
        }
    }

    ticks++;
}