#include "GameManager.h"
GameManager::GameManager()
{
	// 先假定都是人類玩家
	this->current_player = 0; // 先假定player1先手
	this->players[0] = new HumanPlayer(true);
	this->players[1] = new HumanPlayer(false);
}
void GameManager::game()
{
	Board chessBoard;
	Viewer viewer;
    showMenu();
	viewer.showBoard(chessBoard);

	// loop:
	// 先手下旗
	// 判斷
	// 後手下旗
	// 判斷

	// 遊戲結束
	// 要不要再來一局?
}
void GameManager::showMenu()
{
    // 隨便從網路上抓的示意圖，之後可以改掉
    cout << "********************************************************************************\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*        ******     **                                                         *\n";
    cout << "*      **********   **                                                         *\n";
    cout << "*    ***            **                                                         *\n";
    cout << "*   ***             **            ****       ****        ****                  *\n";
    cout << "*   ***             **          ********   ***  ***    ***  ***                *\n";
    cout << "*   ***             ** ****    ***    *** ***         ***                      *\n";
    cout << "*   ***             ****  **   **********   ******      ******                 *\n";
    cout << "*    ***            ***    **  ***             *****       *****               *\n";
    cout << "*      **********   **     **   ****       ***   **    ***   **                *\n";
    cout << "*       *******     **     **     ****       *****       *****                 *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                        ' welcome to chess game '                             *\n";
    cout << "*                                                                              *\n";
    cout << "*                         press enter to continue.                             *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                              *\n";
    cout << "*                                                                          v1.0*\n";
    cout << "********************************************************************************\n";
    system("pause");
    system("cls");
	// show menu
	//  -美化或發揮創意的介面
	//  -可以放個分組名單?
	// 依據使用者輸入，選擇:
	// l) play new game
	// 2) load game
	// 3) 我不知道
}