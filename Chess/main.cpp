#include <iostream>
#include "Board.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";
    Board chessBoard;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << chessBoard.board[i][j].piece.icon << " ";
        cout << endl;
    }
}
