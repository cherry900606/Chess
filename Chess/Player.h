#pragma once
#include "Board.h"
#include "Position.h"

class Player {
public:
	virtual void OnMove(Board& const board, Position& outFromPos, Position& outToPos) = 0; // 選擇要從 fromPos 走到 toPos
	//virtual void OnPromote(/*ex. Board& const board, Position& const pawnPos, PieceType& outType*/) = 0; // 選擇升階類型
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