#pragma once
#include "Board.h"
#include "Player.h"
#include "Viewer.h"

class GameManager {
public:
	Player* players[2];
	int current_player;
	Board board;
	Viewer viewer;
};