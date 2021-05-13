#pragma once
#include "Board.h"
#include "Player.h"
#include "Viewer.h"
#include <vector>
#include <fstream>


class GameManager {
public:
	Player* players[2]; // human player or ai player
	int current_player; // 現在可以移動旗子的玩家
	Board board; // now board status
	Viewer viewer; // show the board
	vector<string> saveFile;

	GameManager(); // initialsize
	void game(Board board); // game loop
	void showMenu();
	bool invalidMove(Position moveFromPos, Position moveToPos, int type, Board board);
	bool isCheckmate(Board board, bool kingIsWhite);
	bool isCheck(Board board, bool kingIsWhite);
};