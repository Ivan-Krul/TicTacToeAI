// TicTacToeAI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

int main()
{
    Game game(3,3);
    while(game.checkWhoWin() == Mark::empty && !game.isFilled())
    {
        int posX, posY;
        std::cout << game.output();
        std::cin >> posX >> posY;
        game.turn(posX, posY);
    }
    std::cout << game.output();
    std::cout<<(char)game.checkWhoWin();
}
