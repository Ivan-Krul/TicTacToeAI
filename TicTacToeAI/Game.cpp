#include "Game.h"
#include "BoardParser.h"
#include <sstream>

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
	_needCheck = needCheck_;
}

bool Game::isCrossTurn()
{
	return _isCrossTurn;
}

Board Game::show()
{
	return _board;
}

void Game::turn(uint8_t x_, uint8_t y_)
{
	if(_board.show(x_, y_) == Mark::empty)
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
}

std::string Game::output()
{
	const static char bordVertical = '|';
	const static bool needSpace = true;
	std::stringstream str;
	str << "turn: " << (_isCrossTurn ? "cross" : "round") << '\n';

	str << _outputBorders();

	//game field
	for(uint8_t iy = 0; iy < _board.size(); iy++)
	{
		str << bordVertical;
		for(uint8_t ix = 0; ix < _board.size(); ix++)
		{
			str << (needSpace ? " " : "") << (char)_board.show(ix, iy);
		}
		str << (needSpace ? " " : "") << bordVertical << "\n";
	}

	str << _outputBorders();

	return str.str();
}

bool Game::isFilled()
{
	for(size_t ix = 0; ix < _board.size(); ix++)
	{
		for(size_t iy = 0; iy < _board.size(); iy++)
		{
			if(_board.show(ix, iy) == Mark::empty)
				return false;
		}
	}
	return true;
}

bool Game::isEmpty()
{
	for(size_t ix = 0; ix < _board.size(); ix++)
	{
		for(size_t iy = 0; iy < _board.size(); iy++)
		{
			if(_board.show(ix, iy) != Mark::empty)
				return false;
		}
	}
	return true;
}

int Game::count(Mark mark_)
{
	int cnt = 0;
	for(size_t ix = 0; ix < _board.size(); ix++)
	{
		for(size_t iy = 0; iy < _board.size(); iy++)
		{
			if(_board.show(ix, iy) == mark_)
				cnt++;
		}
	}
	return cnt;
}

const int Game::needToWin()
{
	return _needCheck;
}

Mark Game::checkWhoWin()
{
	static uint8_t size = _board.size();
	Mark prev;
	uint8_t crosses = 0;
	uint8_t rounds = 0;
	BoardParser parser(_board);
	Mark resAlg = parser.checkColons(_needCheck);
	if(resAlg != Mark::empty)
		return resAlg;
	resAlg = parser.checkRows(_needCheck);
	if(resAlg != Mark::empty)
		return resAlg;
	resAlg = parser.checkDiagonalsUL(_needCheck);
	if(resAlg != Mark::empty)
		return resAlg;
	resAlg = parser.checkDiagonalsDL(_needCheck);
	if(resAlg != Mark::empty)
		return resAlg;
	resAlg = parser.checkDiagonalsUR(_needCheck);
	if(resAlg != Mark::empty)
		return resAlg;
	resAlg = parser.checkDiagonalsDR(_needCheck);
	if(resAlg != Mark::empty)
		return resAlg;
	return Mark::empty;
}
