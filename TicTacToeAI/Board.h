#pragma once
#include <stdint.h>
#include <cassert>
enum class Mark : char
{
	empty = ' ',
	cross = 'x',
	round = 'o'
};

class Board
{
	uint8_t _size;
	Mark* _board;
public:
	Board(uint8_t size_);
	void set(uint8_t x_, uint8_t y_, Mark mark_);
	uint8_t size();
	const Mark show(uint8_t x_, uint8_t y_);
	~Board();
};