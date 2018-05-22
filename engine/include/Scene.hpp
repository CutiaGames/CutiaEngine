#ifndef SCENE_HPP
#define SCENE_HPP

#include "CutiaSDL.hpp"
#include "GameObject.hpp"
#include <vector>

using std::vector;

class Scene{

    public:
        Scene(){ objs = vector<GameObject*>(); }
        void setup();
        virtual void render();
        virtual void update();
    
    protected:
        vector<GameObject*> objs;
};


#endif