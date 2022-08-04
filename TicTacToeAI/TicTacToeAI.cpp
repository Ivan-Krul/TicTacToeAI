// TicTacToeAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

int main()
{
    Game game(3,3);
    game.turn(1, 1);
    game.turn(2, 1);
    std::cout<<game.output();
    std::cout << "Hello World!\n";
}
