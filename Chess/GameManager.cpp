#include "GameManager.h"
GameManager::GameManager()
{
	// �����w���O�H�����a
	this->current_player = 0; // �����wplayer1����
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
	// ����U�X
	// �P�_
	// ���U�X
	// �P�_

	// �C������
	// �n���n�A�Ӥ@��?
}
void GameManager::showMenu()
{
    // �H�K�q�����W�쪺�ܷN�ϡA����i�H�ﱼ
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
	//  -���Ʃεo���зN������
	//  -�i�H��Ӥ��զW��?
	// �̾ڨϥΪ̿�J�A���:
	// l) play new game
	// 2) load game
	// 3) �ڤ����D
}