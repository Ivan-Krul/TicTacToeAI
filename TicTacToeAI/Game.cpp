#include "Game.h"
#include <sstream>
void Game::_checkColons(uint8_t& crosses_, uint8_t& rounds_)
{
	//colons
	for(uint8_t iy = 0; iy < _board.size(); iy++)
	{
		for(uint8_t ix = 0; ix < _board.size(); ix++)
		{
			_checkSingleMark(ix, iy, crosses_, rounds_);
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
			_checkSingleMark(ix, iy, crosses_, rounds_);
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

void Game::_checkDiagonals(uint8_t& crosses_, uint8_t& rounds_)
{
	// diagonals, first stage
	for(int8_t ip = 0; ip < _board.size(); ip++)
	{
		for(int8_t id = -_board.size()/2+1; id < _board.size(); id++)
		{
			_checkSingleMark(ip + id, ip - id,crosses_,rounds_);
		}
		if(crosses_ == _needCheck || rounds_ == _needCheck)
			return;
		else
		{
			crosses_ = 0;
			rounds_ = 0;
		}
	}
	for(int8_t ip = _board.size() - 1; ip >= 0; ip--)
	{
		for(int8_t id = 0; id < _board.size(); id++)
		{
			_checkSingleMark(ip + id, ip - id, crosses_, rounds_);
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

void Game::_checkDiagonals1(uint8_t& crosses_, uint8_t& rounds_)
{
	// diagonals, second stage
	for(int8_t ip = 0; ip < _board.size(); ip++)
	{
		for(int8_t id = -_board.size() / 2 + 1; id < _board.size(); id++)
		{
			_checkSingleMark(ip + id + 1, ip - id, crosses_, rounds_);
		}
		if(crosses_ == _needCheck || rounds_ == _needCheck)
			return;
		else
		{
			crosses_ = 0;
			rounds_ = 0;
		}
	}
	for(int8_t ip = _board.size() - 1; ip >= 0; ip--)
	{
		for(int8_t id = 0; id < _board.size(); id++)
		{
			_checkSingleMark(ip + id + 1, ip - id, crosses_, rounds_);
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

void Game::_checkSingleMark(int8_t x_,int8_t y_,uint8_t& crosses_, uint8_t& rounds_)
{
	if(_board.isInBoard(x_, y_))
	{
		if(_board.show(x_, y_) == Mark::cross)
			crosses_++;
		else if(_board.show(x_, y_) == Mark::round)
			rounds_++;
	}
}

std::string Game::_outputBorders()
{
	const static char bordCorner = '+';
	const static bool needSpace = true;
	const static char bordHorizontal = '-';
	//border
	std::stringstream str;
	str << bordCorner;
	for(uint8_t ix = 0; ix < _board.size(); ix++)
	{
		str << (needSpace ? " " : "") << bordHorizontal;
	}
	str << (needSpace ? " " : "") << bordCorner << "\n";
	return str.str();
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
	const static char bordVertical = '|';
	const static bool needSpace = true;
	std::stringstream str;
	str << "turn: " << (_isCrossTurn ? "cross" : "round") << '\n';

	str << _outputBorders();

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

	str << _outputBorders();

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

	_checkDiagonals(crosses, rounds);
	if(crosses == _needCheck)
		return Mark::cross;
	else if(rounds == _needCheck)
		return Mark::round;

	_checkDiagonals1(crosses, rounds);
	if(crosses == _needCheck)
		return Mark::cross;
	else if(rounds == _needCheck)
		return Mark::round;

	return Mark::empty;
}
