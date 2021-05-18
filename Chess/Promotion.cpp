#include "Promotion.h"

void checkPromotion(Board* chessBoard, Piece* piece) {
	// White
	for (int i = 0; i < 8; i++) {
		if (chessBoard->board[0][i].piece.type == 6 && chessBoard->board[0][i].piece.isWhiteSide) {
			cout << "Please choose what type to promotion!\n";
			cout << "2) Queen   3) Rook   4) Bishop   5) Knight\nEnter the type: ";

			int typeToPromote = 2;
			cin >> typeToPromote;
			if (typeToPromote == 2) {
				chessBoard->board[0][i].piece = Piece(2, true);
			}
			else if (typeToPromote == 3) {
				chessBoard->board[0][i].piece = Piece(3, true);
			}
			else if (typeToPromote == 4) {
				chessBoard->board[0][i].piece = Piece(4, true);
			}
			else if (typeToPromote == 5) {
				chessBoard->board[0][i].piece = Piece(5, true);
			}
			else {
				cout << "type error! Promoting to Queen.\n";
				chessBoard->board[0][i].piece = Piece(2, true);
			}

			system("pause");
		}
	}
	// Black
	for (int i = 0; i < 8; i++) {
		if (chessBoard->board[7][i].piece.type == 6 && !chessBoard->board[0][i].piece.isWhiteSide) {
			cout << "Please choose what type to promotion!\n";
			cout << "2) Queen   3) Rook   4) Bishop   5) Knight\nEnter the type: ";

			int typeToPromote = 2;
			cin >> typeToPromote;
			if (typeToPromote == 2) {
				chessBoard->board[7][i].piece = Piece(2, false);
			}
			else if (typeToPromote == 3) {
				chessBoard->board[7][i].piece = Piece(3, false);
			}
			else if (typeToPromote == 4) {
				chessBoard->board[7][i].piece = Piece(4, false);
			}
			else if (typeToPromote == 5) {
				chessBoard->board[7][i].piece = Piece(5, false);
			}
			else {
				cout << "type error! Promoting to Queen.\n";
				chessBoard->board[7][i].piece = Piece(2, false);
			}
			system("pause");
		}
	}
}