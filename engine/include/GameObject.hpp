#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "CutiaSDL.hpp"
#include "Component.hpp"
#include <vector>

using std::vector;

class GameObject{

    private:
        vector<Component*> components;

    public:
        GameObject(){ components = vector<Component*>(); }
        float x, y;
        void addComponent(Component* comp);
        void render();
        void update();
};

#endif