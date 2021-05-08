#pragma once
class Player {
public:
	virtual void OnMove(/*ex. Board& const board, Position& outFromPos, Position& outToPos*/) = 0; // ��ܭn�q fromPos ���� toPos
	virtual void OnPromote(/*ex. Board& const board, Position& const pawnPos, PieceType& outType*/) = 0; // ��ܤɶ�����
	bool isWhiteSide;
};

class HumanPLayer : public Player {
public: 
	virtual void OnMove(/* parameters */) override;
	void OnPromote(/* parameters */) override;
};