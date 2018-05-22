#include "GameObject.hpp"

extern class Component;

void GameObject::addComponent(Component* comp){
    // printf("Component Added\n");
    comp->obj = this;
    components.push_back(comp);
}

void GameObject::render(){
    // printf("GameObject:render\n");
    for (auto e_comp : components) {
        e_comp->render();
    }
}

void GameObject::update(){
    // printf("GameObject:update\n");
    for (auto e_comp : components) {
        e_comp->update();
    }
}