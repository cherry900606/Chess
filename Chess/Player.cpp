#include "Player.h"
Player::Player(bool isWhiteSide)
{
	this->isWhiteSide = isWhiteSide;
}
Player::Player()
{
	this->isWhiteSide = true;
}
HumanPlayer::HumanPlayer()
{
	this->isWhiteSide = true;
}
HumanPlayer::HumanPlayer(bool isWhiteSide)
{
	this->isWhiteSide = isWhiteSide;
}
void HumanPlayer::OnMove(Board& const board, Position& outFromPos, Position& outToPos)
{
	board.board[outToPos.y][outToPos.x].piece = board.board[outFromPos.y][outFromPos.x].piece; // 移過去
	board.board[outFromPos.y][outFromPos.x].piece = Piece(-1, true); // 淨空原本的
}