#ifndef SCENE_GUITAR_HPP
#define SCENE_GUITAR_HPP

#include "Scene.hpp"
#include "GameObject.hpp"
#include <vector>

using std::vector;

class SceneGuitar : public Scene{

    private:
        int ticks;
        void createNewNoteAtTop();

    public:
        void setup();
        void update();

};


#endif