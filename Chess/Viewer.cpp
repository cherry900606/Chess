#include "Viewer.h"
void Viewer::showBoard(Board chessBoard)
{
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
}