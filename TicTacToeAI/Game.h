#pragma once
#include "Board.h"
class Game
{
	Board _board;
	bool _isCrossTurn;
public:
	Game(uint8_t sizeBoard_);
	bool isCrossTurn();
	const Board show();
	void turn(uint8_t x_, uint8_t y);

};

