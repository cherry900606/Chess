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
			gameManager.game();
		}
		else if (cmd == 2)
		{
			endGame = true;
		}
		else if (cmd == 3)
		{
			cout << "此功能尚未實作" << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
}
