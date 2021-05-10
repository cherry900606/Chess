#pragma once
#include "Board.h"
#include "Player.h"
#include "Viewer.h"

class GameManager {
public:
	Player* players[2]; // human player or ai player
	int current_player; // 現在可以移動旗子的玩家
	Board board; // now board status
	Viewer viewer; // show the board

	GameManager(); // initialsize
	void game(); // game loop
	void showMenu();
	bool invalidMove(Position moveFromPos, Position moveToPos, int type, Board board);
};