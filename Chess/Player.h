#pragma once
class Player {
public:
	virtual void OnMove(/*ex. Board& const board, Position& outFromPos, Position& outToPos*/) = 0; // 選擇要從 fromPos 走到 toPos
	virtual void OnPromote(/*ex. Board& const board, Position& const pawnPos, PieceType& outType*/) = 0; // 選擇升階類型
	bool isWhiteSide;
};

class HumanPLayer : public Player {
public: 
	virtual void OnMove(/* parameters */) override;
	void OnPromote(/* parameters */) override;
};