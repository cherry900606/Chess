#include "Position.h"

Position::Position(int x, int y, Piece piece)
{
	this->x = x;
	this->y = y;
	this->piece = piece;
}
Position::Position()
{
	this->x = this->y = 0;
}