#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "CutiaSDL.hpp"
#include <stdio.h>

class GameObject;

class Component{

    public:
        virtual void render(){ printf("Component:render\n"); return; }
        virtual void update(){ printf("Component:update\n"); return; }
        GameObject* obj;
};

#endif