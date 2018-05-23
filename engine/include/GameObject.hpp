#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "CutiaSDL.hpp"
#include "Component.hpp"
#include <vector>

using std::vector;

class GameObject{

    protected:
        vector<Component*> components;

    public:
        GameObject(){ components = vector<Component*>(); }
        bool enabled = true;
        float x, y;
        void addComponent(Component* comp);
        virtual void render();
        virtual void update();
};

#endif