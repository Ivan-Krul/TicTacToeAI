#include "Board.h"

Board::Board(uint8_t size_)
{
	_size = size_;
	_board = new Mark[_size * _size];
}

void Board::set(uint16_t pos_, Mark mark_)
{
	assert(pos_ < _size);
	_board[pos_] = mark_;
}

uint8_t Board::size()
{
	return _size;
}

const Mark Board::show(uint16_t pos_)
{
	assert(pos_ < _size);
	return _board[pos_];
}

Board::~Board()
{
	delete[] _board;
}
