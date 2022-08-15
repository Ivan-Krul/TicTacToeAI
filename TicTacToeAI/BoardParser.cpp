#include "BoardParser.h"

BoardParser::BoardParser(Board& board_)
{
	_board = &board_;
	_size = board_.size();
}

void BoardParser::_switch(int ix,int iy,Mark& prev_,uint8_t& crosses_, uint8_t& rounds_)
{
	switch(_board->show(ix, iy))
	{
		case Mark::cross:
			if(prev_ != Mark::cross)
				crosses_ = 0, rounds_ = 0;
			crosses_++;
			break;
		case Mark::round:
			if(prev_ != Mark::round)
				crosses_ = 0, rounds_ = 0;
			rounds_++;
			break;
		default:
			crosses_ = 0, rounds_ = 0;
			break;
	}
	prev_ = _board->show(ix, iy);
}

Mark BoardParser::checkColons(uint8_t needCheck_)
{
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t ix = 0; ix < _size; ix++)
	{
		prev = Mark::empty;
		for(uint8_t iy = 0; iy < _size; iy++)
		{
			_switch(ix, iy, _prev, crosses, rounds);

			if(crosses == needCheck_ || rounds == needCheck_) {
				(_abortedPos[0] = ix, _abortedPos[1] = iy);
				return crosses == needCheck_?Mark::cross: Mark::round;
			}
		}
	}
	return Mark::empty;
}

Mark BoardParser::checkRows(uint8_t needCheck_)
{
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t iy = 0; iy < _size; iy++)
	{
		prev = Mark::empty;
		for(uint8_t ix = 0; ix < _size; ix++)
		{
			_switch(ix, iy, _prev, crosses, rounds);

			if(crosses == needCheck_ || rounds == needCheck_)
			{
				(_abortedPos[0] = ix, _abortedPos[1] = iy);
				return crosses == needCheck_ ? Mark::cross : Mark::round;
			}
		}
	}
	return Mark::empty;
}

Mark BoardParser::checkDiagonalsUL(uint8_t needCheck_)
{
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t iy = 0; iy < _size; iy++)
	{
		prev = Mark::empty;
		for(uint8_t id = 0; id <= iy; id++)
		{
			_switch(id, iy - id, _prev, crosses, rounds);

			if(crosses == needCheck_ || rounds == needCheck_)
			{
				(_abortedPos[0] = id, _abortedPos[1] = iy - id);
				return crosses == needCheck_ ? Mark::cross : Mark::round;
			}
		}
	}
	return Mark::empty;
}

Mark BoardParser::checkDiagonalsDL(uint8_t needCheck_)
{
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t ix = 0; ix < _size; ix++)
	{
		prev = Mark::empty;
		for(uint8_t id = 0; id <= ix; id++)
		{
			_switch(ix - id, _size - 1 - id, _prev, crosses, rounds);

			if(crosses == needCheck_ || rounds == needCheck_)
			{
				(_abortedPos[0] = ix - id, _abortedPos[1] = _size - 1 - id);
				return crosses == needCheck_ ? Mark::cross : Mark::round;
			}
		}
	}
	return Mark::empty;
}

Mark BoardParser::checkDiagonalsUR(uint8_t needCheck_)
{
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t iy = 0; iy < _size; iy++)
	{
		prev = Mark::empty;
		for(uint8_t id = 0; id <= iy; id++)
		{
			_switch(_size - 1 - id, iy - id, _prev, crosses, rounds);

			if(crosses == needCheck_ || rounds == needCheck_)
			{
				(_abortedPos[0] = _size - 1 - id, _abortedPos[1] = iy - id);
				return crosses == needCheck_ ? Mark::cross : Mark::round;
			}
		}
	}
	return Mark::empty;
}

Mark BoardParser::checkDiagonalsDR(uint8_t needCheck_)
{
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t ix = 0; ix < _size; ix++)
	{
		prev = Mark::empty;
		for(uint8_t id = 0; id <= ix; id++)
		{
			_switch(ix - id, _size - 1 - id, _prev, crosses, rounds);

			if(crosses == needCheck_ || rounds == needCheck_)
			{
				(_abortedPos[0] = ix - id, _abortedPos[1] = _size - 1 - id);
				return crosses == needCheck_ ? Mark::cross : Mark::round;
			}
		}
	}
	return Mark::empty;
}
