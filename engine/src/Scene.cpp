#include "Scene.hpp"
#include "Image.hpp"
#include <iostream>
#include "GameObject.hpp"



void Scene::setup(){

    GameObject* obj = new GameObject();

    //Component
    Component* image = new Image("donut.png");
    obj->x = 100;
    obj->y = 100;

    obj->addComponent(image);

    objs.push_back(obj);
}

void Scene::render(){
    
    for (auto e_obj : objs) {
        e_obj->render();
    }
}

void Scene::update(){
    
    for (auto e_obj : objs) {
        e_obj->update();
    }
}