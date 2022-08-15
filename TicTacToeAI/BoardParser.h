#pragma once
#include "Board.h"
class BoardParser
{
private:
	Board* _board;
	uint8_t _size;
	Mark _prev = Mark::empty;
	uint8_t _crosses = 0, _rounds = 0;
	int _abortedPos[2] = { -1,-1 };

	void _switch(int ix, int iy, Mark& prev_, uint8_t& crosses_, uint8_t& rounds_);
public:
	BoardParser(Board& board_);
	Mark checkColons(uint8_t needCheck_);
	Mark checkRows(uint8_t needCheck_);
	Mark checkDiagonalsUL(uint8_t needCheck_);
	Mark checkDiagonalsDL(uint8_t needCheck_);
	Mark checkDiagonalsUR(uint8_t needCheck_);
	Mark checkDiagonalsDR(uint8_t needCheck_);
};

