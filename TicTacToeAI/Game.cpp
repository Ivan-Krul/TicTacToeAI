#include "Game.h"
#include <sstream>

Mark Game::_checkColons()
{
	static uint8_t size = _board.size();
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t ix = 0; ix < size; ix++)
	{
		prev = Mark::empty;
		for(uint8_t iy = 0; iy < size; iy++)
		{
			switch(_board.show(ix, iy))
			{
				case Mark::cross:
					if(prev != Mark::cross)
						crosses = 0,rounds = 0;
					crosses++;
					break;
				case Mark::round:
					if(prev != Mark::round)
						crosses = 0,rounds = 0;
					rounds++;
					break;
				default:
					crosses = 0,rounds = 0;
					break;
			}
			prev = _board.show(ix, iy);

			if(crosses == _needCheck) return Mark::cross;
			else if(rounds == _needCheck) return Mark::round;
		}
	}
	return Mark::empty;
}

Mark Game::_checkRows()
{
	static uint8_t size = _board.size();
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t iy = 0; iy < size; iy++)
	{
		prev = Mark::empty;
		for(uint8_t ix = 0; ix < size; ix++)
		{
			switch(_board.show(ix, iy))
			{
				case Mark::cross:
					if(prev != Mark::cross)
						crosses = 0, rounds = 0;
					crosses++;
					break;
				case Mark::round:
					if(prev != Mark::round)
						crosses = 0, rounds = 0;
					rounds++;
					break;
				default:
					crosses = 0, rounds = 0;
					break;
			}
			prev = _board.show(ix, iy);

			if(crosses == _needCheck) return Mark::cross;
			else if(rounds == _needCheck) return Mark::round;
		}
	}
	return Mark::empty;
}

Mark Game::_checkDiagonalsUL()
{
	static uint8_t size = _board.size();
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t iy = 0; iy < size; iy++)
	{
		prev = Mark::empty;
		for(uint8_t id = 0; id <= iy; id++)
		{
			switch(_board.show(id, iy-id))
			{
				case Mark::cross:
					if(prev != Mark::cross)
						crosses = 0, rounds = 0;
					crosses++;
					break;
				case Mark::round:
					if(prev != Mark::round)
						crosses = 0, rounds = 0;
					rounds++;
					break;
				default:
					crosses = 0, rounds = 0;
					break;
			}
			prev = _board.show(id, iy-id);

			if(crosses == _needCheck) return Mark::cross;
			else if(rounds == _needCheck) return Mark::round;
		}
	}
	return Mark::empty;
}

Mark Game::_checkDiagonalsDL()
{
	static uint8_t size = _board.size();
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t ix = 0; ix < size; ix++)
	{
		prev = Mark::empty;
		for(uint8_t id = 0; id <= ix; id++)
		{
			switch(_board.show(ix - id, size - 1 - id))
			{
				case Mark::cross:
					if(prev != Mark::cross)
						crosses = 0, rounds = 0;
					crosses++;
					break;
				case Mark::round:
					if(prev != Mark::round)
						crosses = 0, rounds = 0;
					rounds++;
					break;
				default:
					crosses = 0, rounds = 0;
					break;
			}
			prev = _board.show(ix - id, size - 1 - id);

			if(crosses == _needCheck) return Mark::cross;
			else if(rounds == _needCheck) return Mark::round;
		}
	}
	return Mark::empty;
}

Mark Game::_checkDiagonalsUR()
{
	static uint8_t size = _board.size();
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t iy = 0; iy < size; iy++)
	{
		prev = Mark::empty;
		for(uint8_t id = 0; id <= iy; id++)
		{
			switch(_board.show(size - 1 - id, iy - id))
			{
				case Mark::cross:
					if(prev != Mark::cross)
						crosses = 0, rounds = 0;
					crosses++;
					break;
				case Mark::round:
					if(prev != Mark::round)
						crosses = 0, rounds = 0;
					rounds++;
					break;
				default:
					crosses = 0, rounds = 0;
					break;
			}
			prev = _board.show(size - 1 - id, iy - id);

			if(crosses == _needCheck) return Mark::cross;
			else if(rounds == _needCheck) return Mark::round;
		}
	}
	return Mark::empty;
}

Mark Game::_checkDiagonalsDR()
{
	static uint8_t size = _board.size();
	Mark prev;
	uint8_t crosses = 0, rounds = 0;
	for(uint8_t ix = 0; ix < size; ix++)
	{
		prev = Mark::empty;
		for(uint8_t id = 0; id <= ix; id++)
		{
			switch(_board.show(ix-id, size - 1 - id))
			{
				case Mark::cross:
					if(prev != Mark::cross)
						crosses = 0, rounds = 0;
					crosses++;
					break;
				case Mark::round:
					if(prev != Mark::round)
						crosses = 0, rounds = 0;
					rounds++;
					break;
				default:
					crosses = 0, rounds = 0;
					break;
			}
			prev = _board.show(ix - id, size - 1 - id);

			if(crosses == _needCheck) return Mark::cross;
			else if(rounds == _needCheck) return Mark::round;
		}
	}
	return Mark::empty;
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
	_needCheck = needCheck_;
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

Mark Game::checkWhoWin()
{
	static uint8_t size = _board.size();
	Mark prev;
	uint8_t crosses = 0;
	uint8_t rounds = 0;

	Mark resAlg = _checkColons();
	if(resAlg != Mark::empty)
		return resAlg;

	resAlg = _checkRows();
	if(resAlg != Mark::empty)
		return resAlg;

	resAlg = _checkDiagonalsUL();
	if(resAlg != Mark::empty)
		return resAlg;
	resAlg = _checkDiagonalsDL();
	if(resAlg != Mark::empty)
		return resAlg;

	resAlg = _checkDiagonalsUR();
	if(resAlg != Mark::empty)
		return resAlg;
	resAlg = _checkDiagonalsDR();
	if(resAlg != Mark::empty)
		return resAlg;

	return Mark::empty;
}
