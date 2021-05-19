#include <iostream>
#include <windows.h>
#include "GameManager.h"
using namespace std;
void welcome();
int main()
{
	welcome();

    GameManager gameManager;
	bool endGame = false;

	while (!endGame) // menu loop
	{
		gameManager.showMenu(); // print game menu

		//改成string輸入可防呆，避免使用者輸入英文字導致無限迴圈
		string cmd;
		cout << "Command: ";
		cin >> cmd;
		if (cmd == "1") // 新遊戲
		{
			// 初始化設定
			int setFirstPlayer = 0;
			cout << "請決定 1)白棋 2)黑棋 先攻: ";
			cin >> setFirstPlayer;
			setFirstPlayer--;
			gameManager.current_player = setFirstPlayer;
			gameManager.board.resetBoard();
			gameManager.game(gameManager.board);
		}
		else if (cmd == "2") // 離開遊戲
		{
			endGame = true;
		}
		else if (cmd == "3") // 讀檔
		{
			string fileName;
			cout << "請輸入要讀取的檔案名稱(ex: 1.txt): ";
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
		else // 錯誤指令
		{
			cout << "error command" << endl;
			system("pause");
			cmd.clear();
		}
	}
}
//動畫
void welcome() {
	
	for (int j = 0;j < 8;j++) {
		for (int i = 0;i <= 2;i++) {
			cout << endl;
		}
		for (int i = 0;i < 10 + j;i++) {
			cout << " ";
		}
		cout << "##      ## ######## ##        ######   #######  ##     ## ########" << endl;
		for (int i = 0;i < 10 + j;i++) {
			cout << " ";
		}
		cout << "##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##" << endl;
		for (int i = 0;i < 10 + j;i++) {
			cout << " ";
		}
		cout << "##  ##  ## ##       ##       ##       ##     ## #### #### ##" << endl;
		for (int i = 0;i < 10 + j;i++) {
			cout << " ";
		}
		cout << "##  ##  ## ######   ##       ##       ##     ## ## ### ## ######" << endl;
		for (int i = 0;i < 10 + j;i++) {
			cout << " ";
		}
		cout << "##  ##  ## ##       ##       ##       ##     ## ##     ## ##" << endl;
		for (int i = 0;i < 10 + j;i++) {
			cout << " ";
		}
		cout << "##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##" << endl;
		for (int i = 0;i < 10 + j;i++) {
			cout << " ";
		}
		cout << " ###  ###  ######## ########  ######   #######  ##     ## ########" << endl;
		
		//cout << "-----Welcome to play chess-----";
		Sleep(300); //停三秒
		system("cls");
	}
}