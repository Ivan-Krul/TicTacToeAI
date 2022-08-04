#pragma once
#include "Board.h"
#include <iostream>
class Game
{
	Board _board;
	uint8_t _needCheck;
	bool _isCrossTurn;

	void _checkColons(uint8_t& crosses_,uint8_t& rounds_);
	void _checkRows(uint8_t& crosses_, uint8_t& rounds_);
	void _checkDiagonals(uint8_t& crosses_, uint8_t& rounds_);
public:
	Game(uint8_t sizeBoard_,uint8_t needCheck_);
	bool isCrossTurn();
	const Board show();
	void turn(uint8_t x_, uint8_t y);
	std::string output();
	Mark checkWhoWin();
};

