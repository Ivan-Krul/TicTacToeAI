#include "Game.h"
#include <sstream>
void Game::_checkColons(uint8_t& crosses_, uint8_t& rounds_)
{
	//colons
	for(uint8_t iy = 0; iy < _board.size(); iy++)
	{
		for(uint8_t ix = 0; ix < _board.size(); ix++)
		{
			if(_board.show(ix, iy) == Mark::cross)
			{
				crosses_++;
			}
			else if(_board.show(ix, iy) == Mark::round)
			{
				rounds_++;
			}
		}
		if(crosses_ == _needCheck || rounds_ == _needCheck)
			return;
		else
		{
			crosses_ = 0;
			rounds_ = 0;
		}
	}
}

void Game::_checkRows(uint8_t& crosses_, uint8_t& rounds_)
{
	//rows

	for(uint8_t ix = 0; ix < _board.size(); ix++)
	{
		for(uint8_t iy = 0; iy < _board.size(); iy++)
		{
			if(_board.show(ix, iy) == Mark::cross)
			{
				crosses_++;
			}
			else if(_board.show(ix, iy) == Mark::round)
			{
				rounds_++;
			}

			if(crosses_ == _needCheck || rounds_ == _needCheck)
				return;
			else
			{
				crosses_ = 0;
				rounds_ = 0;
			}
		}
	}
}

void Game::_checkDiagonals(uint8_t& crosses_, uint8_t& rounds_)
{
	// diagonals

	for(uint8_t ip = 0; ip < _board.size(); ip++)
	{
		for(uint8_t id = 0; id < _board.size(); id++)
		{
			if(_board.show(ip+id, ip-id) == Mark::cross)
			{
				crosses_++;
			}
			else if(_board.show(ip + id, ip - id) == Mark::round)
			{
				rounds_++;
			}
		}
	}
}

Game::Game(uint8_t sizeBoard_,uint8_t needCheck_) : _board(sizeBoard_)
{
	for(uint8_t ix = 0; ix < sizeBoard_; ix++)
	{
		for(uint8_t iy = 0; iy < sizeBoard_; iy++)
		{
			_board.set(ix, iy, Mark::empty);
		}
	}
	_isCrossTurn = true;
}

bool Game::isCrossTurn()
{
	return _isCrossTurn;
}

const Board Game::show()
{
	return _board;
}

void Game::turn(uint8_t x_, uint8_t y_)
{
	if(_isCrossTurn)
	{
		_board.set(x_, y_, Mark::cross);
	}
	else
	{
		_board.set(x_, y_, Mark::round);
	}
	_isCrossTurn = !_isCrossTurn;
}

std::string Game::output()
{
	const static char bordCorner = '+';
	const static char bordVertical = '|';
	const static char bordHorizontal = '-';
	const static bool needSpace = true;
	std::stringstream str;
	str << "turn: " << (_isCrossTurn ? "cross" : "round") << '\n';

	//border
	str << bordCorner;
	for(uint8_t ix = 0; ix < _board.size(); ix++)
	{
		str << (needSpace ? " " : "") << bordHorizontal;
	}
	str << (needSpace ? " " : "") << bordCorner<<"\n";

	//game field
	for(uint8_t ix = 0; ix < _board.size(); ix++)
	{
		str << bordVertical;
		for(uint8_t iy = 0; iy < _board.size(); iy++)
		{
			str << (needSpace ? " " : "") << (char)_board.show(ix, iy);
		}
		str << (needSpace ? " " : "") << bordVertical << "\n";
	}

	//border
	str << bordCorner;
	for(uint8_t ix = 0; ix < _board.size(); ix++)
	{
		str << (needSpace ? " " : "") << bordHorizontal;
	}
	str << (needSpace ? " " : "") << bordCorner << "\n";
	return str.str();
}

Mark Game::checkWhoWin()
{
	// we have board with marks ...
	// ... and need check this, who is winning
	// we will be checking all colons, rows and diagonals on winning
	
	uint8_t crosses = 0;
	uint8_t rounds = 0;
	_checkColons(crosses, rounds);
	if(crosses == _needCheck)
		return Mark::cross;
	else if(rounds == _needCheck)
		return Mark::round;

	_checkRows(crosses, rounds);
	if(crosses == _needCheck)
		return Mark::cross;
	else if(rounds == _needCheck)
		return Mark::round;
	
	return Mark::empty;
}
