#include "Ai.h"

Ai::Ai(Game& game_, bool isCross_)
{
	_game = &game_;
	_isCross = isCross_;
}

void Ai::think()
{
	if(_game->checkWhoWin() != Mark::empty) return;
	if(_game->isCrossTurn() != _isCross) return;
	Board board = _game->show();
	
	for(int iy = 0; iy < board.size(); iy++)
	{
		for(int ix = 0; ix < board.size(); ix++)
		{
			
		}
	}
}

int(&Ai::results())[2]
{
	return _res;
}
