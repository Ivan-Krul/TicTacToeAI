#include "Board.h"

Board::Board(uint8_t size_)
{
	_size = size_;
	_board = new Mark[_size * _size];
}

void Board::set(uint16_t pos_, Mark mark_)
{
	if(pos_)
	_board[pos_] = mark_;
}

uint8_t Board::size()
{
	return _size;
}

const Mark* Board::show()
{
	return _board;
}

Board::~Board()
{
	delete[] _board;
}
