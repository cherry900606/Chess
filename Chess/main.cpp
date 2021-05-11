#include <iostream>
#include "GameManager.h"
using namespace std;

int main()
{
    GameManager gameManager;
	bool endGame = false;

	while (!endGame) // menu loop
	{
		gameManager.showMenu(); // print game menu
		int cmd;
		// 除了1.開始遊戲、2.結束程式以外，也許還會新增load選項
		cout << "Command: ";
		cin >> cmd;
		if (cmd == 1)
		{
			gameManager.game(gameManager.board);
		}
		else if (cmd == 2)
		{
			endGame = true;
		}
		else if (cmd == 3)
		{
			string fileName;
			cout << "請輸入要讀取的檔案名稱: ";
			cin >> fileName;
			ifstream file(fileName);
			if (!file)
				cout << "檔案讀取失敗" << endl;
			else
				cout << "檔案存在!" << endl;
			system("pause");

			gameManager.board.emptyBoard(); // 把board先清空
			file >> gameManager.current_player;

			// 讀檔ing
			int x, y, isWhite, type;
			char icon;
			while (file >> x >> y)
			{
				file >> isWhite >> type >> icon;
				gameManager.board.board[y][x].piece.isWhiteSide = isWhite;
				gameManager.board.board[y][x].piece.type = type;
				gameManager.board.board[y][x].piece.icon = icon;
			}
			
			// 重新遊玩
			gameManager.game(gameManager.board);
		}
		else
		{
			cout << "error" << endl;
		}
	}
}
