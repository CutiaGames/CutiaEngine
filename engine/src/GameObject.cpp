#include "GameObject.hpp"

extern class Component;

void GameObject::addComponent(Component* comp){
    comp->obj = this;
    components.push_back(comp);
}

void GameObject::render(){
    for (auto e_comp : components) {
        e_comp->render();
    }
}

void GameObject::update(){
    for (auto e_comp : components) {
        e_comp->update();
    }
}