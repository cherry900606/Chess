#pragma once
#include "Position.h"
class Board
{
public:
	Position board[8][8];
	Board();
	void resetBoard(); // ��_����l�ѽL
	void emptyBoard(); // �L�Ѫ��ŴѽL
};