#include "Game.hpp"

int main(){
    Game::getInstance().Init(1024, 600);
    Game::getInstance().run();
    Game::getInstance().~Game();

    return 0;
}