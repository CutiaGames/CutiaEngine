#include "Audio.hpp"


using std::string;

Mix_Music* Audio::loadMusic(string path){
    
    Mix_Music* msc = NULL;
    // msc = Mix_LoadMUS(path.c_str());

    if (msc == NULL) exit(EXIT_FAILURE);

    return msc;
}



Mix_Chunk* Audio::loadSound(string path){

    Mix_Chunk* snd = NULL;
    // snd = Mix_LoadWAV(path.c_str());
    if (snd == NULL) exit(EXIT_FAILURE);

    return snd;
}

void Audio::play(){
    
    int play_forever = -1;

    if(state == stopped || state == none);
        // Mix_PlayMusic(music, play_forever);
    else if (state == paused);
        // Mix_ResumeMusic();
    
    state = playing;
}

void Audio::pause(){
    // Mix_PauseMusic();
    state = paused;
}

void Audio::stop(){
    // Mix_HaltMusic();
    state = stopped;
}