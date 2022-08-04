#include "Game.h"
#include <sstream>
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

	//board
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

	//board
	str << bordCorner;
	for(uint8_t ix = 0; ix < _board.size(); ix++)
	{
		str << (needSpace ? " " : "") << bordHorizontal;
	}
	str << (needSpace ? " " : "") << bordCorner << "\n";
	return str.str();
}
