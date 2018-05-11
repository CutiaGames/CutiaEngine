#ifndef SCENE_HPP
#define SCENE_HPP

#include "CutiaSDL.hpp"

class Scene{

    public:
        virtual void render();
        virtual void update();
};


#endif