#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "Component.hpp"
#include "Constants.hpp"

#include <string>

using std::string;

class Image: public Component{

    private:
        SDL_Texture* loadImage(string path);
        SDL_Texture* image;
        float width, height;

    public:
        Image(string path){ image = loadImage(path); }
        int x, y;
        void render();
        void update();
};


#endif