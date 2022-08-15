#include "Board.h"

Board::Board(uint8_t size_)
{
	_size = size_;
	_board = new Mark[_size * _size];
}

void Board::set(int8_t x_, int8_t y_, Mark mark_)
{
	assert((x_ < _size));
	assert((y_ < _size));
	assert((x_ >= 0));
	assert((y_ >= 0));
	_board[x_ + y_ * _size] = mark_;
}

uint8_t Board::size()
{
	return _size;
}

const Mark Board::show(int8_t x_, int8_t y_)
{
	assert((x_ < _size));
	assert((y_ < _size));
	assert((x_ >= 0));
	assert((y_ >= 0));
	return _board[x_ + y_ * _size];
}

bool Board::isInBoard(int8_t x_, int8_t y_)
{
	return (0 <= x_) && (x_ < _size) && (0 <= y_) && (y_ < _size);
}

Board::~Board()
{
	delete[] _board;
}
