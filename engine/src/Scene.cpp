#include "Scene.hpp"
#include "Image.hpp"
#include <iostream>

Image* image = NULL;


void Scene::setup(){
    image = new Image("donut.png");
}

void Scene::render(){
    image->render();
}

void Scene::update(){
    image->update();
}