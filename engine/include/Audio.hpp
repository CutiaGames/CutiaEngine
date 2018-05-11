#ifndef AUDIO_HPP
#define AUDIO_HPP

#include "Component.hpp"
#include "CutiaSDL.hpp"
#include <string>

using std::string;

enum AudioState {
    none = 0,
    playing = 1,
    paused = 2,
    stopped = 3
};

class Audio : Component{
    
    private:
        Mix_Music* loadMusic(string path);
        Mix_Chunk* loadSound(string path);
        Mix_Music* music;
        AudioState state;

    public:
        Audio(string path){ music = loadMusic(path); };
        void play();
        void pause();
        void stop();

};

#endif