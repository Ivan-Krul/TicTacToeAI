#include "Ai.h"

Ai::Ai(Game& game_, bool isCross_)
{
	_game = &game_;
	_isCross = isCross_;
}

void Ai::think()
{
	const static int needToWin = _game->needToWin();
	Board board = _game->show();
	const static int size = board.size();

	if(_game->checkWhoWin() != Mark::empty) return;
	if(_game->isCrossTurn() != _isCross) return;
	if(_game->isEmpty())
	{
		// first move
		_res[0] = rand() % size;
		_res[1] = rand() % size;
		return;
	}
	if(_game->count(_isCross ? Mark::round : Mark::round) < needToWin - 2)
	{
		// there isn't dangerous, need better support line

		return;
	}
	// ok, there is dangerous, but, can we found win combination
	BoardParser parser(board);
	bool isDetectedOpponentPlans = false;
	Mark alg = parser.checkColons(needToWin - 1);
	if(alg == (_isCross ? Mark::round : Mark::round))
		isDetectedOpponentPlans = true;

	if(!isDetectedOpponentPlans)
	{
		// we found combination of win
		return;
	}
	// oh, then, time to beat u

	
	
}

int(&Ai::results())[2]
{
	return _res;
}
