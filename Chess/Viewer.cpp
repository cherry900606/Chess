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
	cout << "\n<輸入指令提示>" << endl;
	cout << "-移動: move x1 y1 x2 y2" << endl;
	cout << "-存檔: save" << endl;
	cout << "-投降: exit" << endl;
	cout << "請輸入指令: ";
}