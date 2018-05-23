#include "Scene.hpp"
#include <iostream>
#include "GameObject.hpp"

void Scene::setup(){
}

void Scene::render(){
    // printf("Scene:render\n");
    for (auto e_obj : objs) {
        if(e_obj->enabled)
            e_obj->render();
    }
}

void Scene::update(){
    // printf("Scene:update\n");
    for (auto e_obj : objs) {
        if(e_obj->enabled)
            e_obj->update();
    }
}