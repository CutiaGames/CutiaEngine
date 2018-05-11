#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "CutiaSDL.hpp"

class Component{

    public:
        virtual void render(){ return; }
        virtual void update(){ return; }
};

#endif