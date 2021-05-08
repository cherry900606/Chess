#pragma once
#include "Piece.h"
class Position
{
public:
	int x, y;
	Piece piece;
	Position();
	Position(int x, int y, Piece piece);
};