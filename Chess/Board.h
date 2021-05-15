#pragma once
#include "Position.h"
class Board
{
public:
	Position board[8][8];
	Board();
	void resetBoard(); // 恢復成初始棋盤
	void emptyBoard(); // 無棋的空棋盤
};