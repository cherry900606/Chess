#include "Piece.h"
Piece::Piece()
{
	this->isAlive = true;
	this->isFirstMove = true;
}
Piece::Piece(int type, bool isWhiteSide)
{
	this->type = type;
	this->isWhiteSide = isWhiteSide;
	this->isAlive = true;
	this->isFirstMove = true;

	if (type == 1) // king
	{
		if (isWhiteSide)
			this->icon = 'k';
		else
			this->icon = 'K';
	}
	else if (type == 2) // queen
	{
		if (isWhiteSide)
			this->icon = 'q';
		else
			this->icon = 'Q';
	}
	else if (type == 3) // rook, ¨®(«°³ù)
	{
		if (isWhiteSide)
			this->icon = 'r';
		else
			this->icon = 'R';
	}
	else if (type == 4) // bishop
	{
		if (isWhiteSide)
			this->icon = 'b';
		else
			this->icon = 'B';
	}
	else if (type == 5) // knight
	{
		if (isWhiteSide)
			this->icon = 'k';
		else
			this->icon = 'K';
	}
	else if (type == 6) // pawn
	{
		if (isWhiteSide)
			this->icon = 'p';
		else
			this->icon = 'P';
	}
	else // empty, no chess
	{
		this->icon = ' ';
		this->type = -1;
	}
}

Piece::Piece(string type, bool isWhiteSide)
{
	this->isWhiteSide = isWhiteSide;
	this->isAlive = true;
	this->isFirstMove = true;

	if (type == "King") // king
	{
		this->type = 1;
		if (isWhiteSide)
			this->icon = 'k';
		else
			this->icon = 'K';
	}
	else if (type == "Queen") // queen
	{
		this->type = 2;
		if (isWhiteSide)
			this->icon = 'q';
		else
			this->icon = 'Q';
	}
	else if (type == "Rook") // rook, ¨®(«°³ù)
	{
		this->type = 3;
		if (isWhiteSide)
			this->icon = 'r';
		else
			this->icon = 'R';
	}
	else if (type == "Bishop") // bishop
	{
		this->type = 4;
		if (isWhiteSide)
			this->icon = 'b';
		else
			this->icon = 'B';
	}
	else if (type == "Knight") // knight
	{
		this->type = 5;
		if (isWhiteSide)
			this->icon = 'n';
		else
			this->icon = 'N';
	}
	else if (type == "Pawn") // pawn
	{
		this->type = 6;
		if (isWhiteSide)
			this->icon = 'p';
		else
			this->icon = 'P';
	}
	else // empty, no chess
	{
		this->icon = ' ';
		this->type = -1;
	}
}