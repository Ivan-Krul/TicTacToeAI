#include "Board.h"

Board::Board(uint8_t size_)
{
	_size = size_;
	_board = new Mark[_size * _size];
}

void Board::set(uint8_t x_, uint8_t y_, Mark mark_)
{
	assert(x_ < _size);
	assert(y_ < _size);
	_board[x_ + y_ * _size] = mark_;
}

uint8_t Board::size()
{
	return _size;
}

const Mark Board::show(uint8_t x_, uint8_t y_)
{
	assert(x_ < _size);
	assert(y_ < _size);
	return _board[x_ + y_ * _size];
}

Board::~Board()
{
	delete[] _board;
}
