#pragma once
#include <stdint.h>
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
	void set(uint16_t pos_, Mark mark_);
	uint8_t size();
	const Mark* show();
	~Board();
};