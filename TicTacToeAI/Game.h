#pragma once
#include "Board.h"
#include "BoardParser.h"
#include <iostream>
class Game
{
	Board _board;
	uint8_t _needCheck;
	bool _isCrossTurn;
	std::string _outputBorders();
public:
	Game(uint8_t sizeBoard_,uint8_t needCheck_);
	bool isCrossTurn();
	Board show();
	void turn(uint8_t x_, uint8_t y);
	std::string output();
	bool isFilled();
	bool isEmpty();
	int count(Mark mark_);
	const int needToWin();
	Mark checkWhoWin();
};

