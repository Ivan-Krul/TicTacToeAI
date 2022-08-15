#pragma once
#include "Game.h"
class Ai
{
private:
	Game* _game;
	bool _isCross;

	int _res[2];
public:
	Ai(Game& game_, bool isCross_);
	void think();
	int(&results())[2];
};
