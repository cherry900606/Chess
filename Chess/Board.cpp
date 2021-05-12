#include "Board.h"
Board::Board()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j].x = i; board[i][j].y = j;
			board[i][j].piece = Piece(-1, false);
		}
	}
	// set black side
	board[0][0].piece = Piece("Rook", false);
	board[0][1].piece = Piece("Knight", false);
	board[0][2].piece = Piece("Bishop", false);
	board[0][3].piece = Piece("Queen", false);
	board[0][4].piece = Piece("King", false);
	board[0][5].piece = Piece("Bishop", false);
	board[0][6].piece = Piece("Knight", false);
	board[0][7].piece = Piece("Rook", false);

	board[1][0].piece = Piece("Pawn", false);
	board[1][1].piece = Piece("Pawn", false);
	board[1][2].piece = Piece("Pawn", false);
	board[1][3].piece = Piece("Pawn", false);
	board[1][4].piece = Piece("Pawn", false);
	board[1][5].piece = Piece("Pawn", false);
	board[1][6].piece = Piece("Pawn", false);
	board[1][7].piece = Piece("Pawn", false);

	// set white side
	board[6][0].piece = Piece("Pawn", true);
	board[6][1].piece = Piece("Pawn", true);
	board[6][2].piece = Piece("Pawn", true);
	board[6][3].piece = Piece("Pawn", true);
	board[6][4].piece = Piece("Pawn", true);
	board[6][5].piece = Piece("Pawn", true);
	board[6][6].piece = Piece("Pawn", true);
	board[6][7].piece = Piece("Pawn", true);

	board[7][0].piece = Piece("Rook", true);
	board[7][1].piece = Piece("Knight", true);
	board[7][2].piece = Piece("Bishop", true);
	board[7][3].piece = Piece("Queen", true);
	board[7][4].piece = Piece("King", true);
	board[7][5].piece = Piece("Bishop", true);
	board[7][6].piece = Piece("Knight", true);
	board[7][7].piece = Piece("Rook", true);
}
void Board::emptyBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j].x = i; board[i][j].y = j;
			board[i][j].piece = Piece(-1, false);
		}
	}
}
void Board::resetBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j].x = i; board[i][j].y = j;
			board[i][j].piece = Piece(-1, false);
		}
	}
	// set black side
	board[0][0].piece = Piece("Rook", false);
	board[0][1].piece = Piece("Knight", false);
	board[0][2].piece = Piece("Bishop", false);
	board[0][3].piece = Piece("Queen", false);
	board[0][4].piece = Piece("King", false);
	board[0][5].piece = Piece("Bishop", false);
	board[0][6].piece = Piece("Knight", false);
	board[0][7].piece = Piece("Rook", false);

	board[1][0].piece = Piece("Pawn", false);
	board[1][1].piece = Piece("Pawn", false);
	board[1][2].piece = Piece("Pawn", false);
	board[1][3].piece = Piece("Pawn", false);
	board[1][4].piece = Piece("Pawn", false);
	board[1][5].piece = Piece("Pawn", false);
	board[1][6].piece = Piece("Pawn", false);
	board[1][7].piece = Piece("Pawn", false);

	// set white side
	board[6][0].piece = Piece("Pawn", true);
	board[6][1].piece = Piece("Pawn", true);
	board[6][2].piece = Piece("Pawn", true);
	board[6][3].piece = Piece("Pawn", true);
	board[6][4].piece = Piece("Pawn", true);
	board[6][5].piece = Piece("Pawn", true);
	board[6][6].piece = Piece("Pawn", true);
	board[6][7].piece = Piece("Pawn", true);

	board[7][0].piece = Piece("Rook", true);
	board[7][1].piece = Piece("Knight", true);
	board[7][2].piece = Piece("Bishop", true);
	board[7][3].piece = Piece("Queen", true);
	board[7][4].piece = Piece("King", true);
	board[7][5].piece = Piece("Bishop", true);
	board[7][6].piece = Piece("Knight", true);
	board[7][7].piece = Piece("Rook", true);
}