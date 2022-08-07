#pragma once
#include "Board.h"
#include <iostream>
class Game
{
	Board _board;
	uint8_t _needCheck;
	bool _isCrossTurn;

	Mark _checkColons();
	Mark _checkRows();
	Mark _checkDiagonalsUL();
	Mark _checkDiagonalsDL();
	Mark _checkDiagonalsUR();
	Mark _checkDiagonalsDR();
	std::string _outputBorders();
public:
	Game(uint8_t sizeBoard_,uint8_t needCheck_);
	bool isCrossTurn();
	const Board show();
	void turn(uint8_t x_, uint8_t y);
	std::string output();
	bool isFilled();
	Mark checkWhoWin();
};

