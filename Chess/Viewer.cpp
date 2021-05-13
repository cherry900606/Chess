#include "Viewer.h"
void Viewer::showBoard(Board chessBoard)
{
	// print board
    cout << "  ";
    for (int i = 0; i < 8; i++)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 8; j++)
            cout << chessBoard.board[i][j].piece.icon << " ";
        cout << endl;
    }

	// print hint
	cout << "\n<��J���O����>" << endl;
	cout << "-����: move x1 y1 x2 y2" << endl;
	cout << "-�s��: save" << endl;
	cout << "-�뭰: exit" << endl;
	cout << "�п�J���O: ";
}