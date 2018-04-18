#include "Game.hpp"

int main()
{
    Game::GetInstance().Init("CutiaGames Engine 2018", 1024, 600);
    Game::GetInstance().Run();
    Game::GetInstance().~Game();

    return 0;
}