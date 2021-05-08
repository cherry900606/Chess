#pragma once
#include <iostream>
using namespace std;

class Piece
{
public:
	Piece(int type, bool isWhiteSide);
	Piece(string type, bool isWhiteSide);
	Piece();
	int type;
	bool isAlive;
	bool isWhiteSide;
	char icon;
};