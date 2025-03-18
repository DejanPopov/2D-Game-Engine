#include <iostream>
#include "Game.h"

int main(int argc,char* argv[]) 
{
    Game game; // Contructor and Destructor are called here

    game.Initialize();
    game.Run();
    game.Destroy();

    return 0;
}
