#pragma once
#include "Board.h"
#include "Position.h"

class Player {
public:
	virtual void OnMove(Board& const board, Position& outFromPos, Position& outToPos) = 0; // ��ܭn�q fromPos ���� toPos
	//virtual void OnPromote(/*ex. Board& const board, Position& const pawnPos, PieceType& outType*/) = 0; // ��ܤɶ�����
	bool isWhiteSide;
	Player(bool isWhiteSide);
	Player();
};

class HumanPlayer : public Player {
public: 
	virtual void OnMove(Board& const board, Position& outFromPos, Position& outToPos) override;
	//void OnPromote(/* parameters */) override;
	HumanPlayer(bool isWhiteSide);
	HumanPlayer();
};