#include "GameManager.h"
#include <sstream>

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
    string command, type;

    showMenu();
	
    bool endGame = false;
    while (1)
    {
        // white turn
        bool validInput = false;
        do
        {
            cout << "Now is WHITE turn!\n" << endl;
            viewer.showBoard(chessBoard);
            getline(cin, command);

            stringstream ss(command); // ���Φr���
            ss >> type;
            if (type == "move" || type == "Move") // ���� (ex: move 0 0 0 2)
            {
                Position moveToPos, moveFromPos;
                ss >> moveFromPos.x >> moveFromPos.y >> moveToPos.x >> moveToPos.y;

                if (chessBoard.board[moveFromPos.y][moveFromPos.x].piece.type == -1) // �q�Ū���l����
                {
                    cout << "�п�ܥ��T����m�I" << endl;
                    system("pause");
                }
                else if (chessBoard.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != players[current_player]->isWhiteSide) // ���ʤ��ݩ�ۤv���Ѥl
                {
                    cout << "�п�ܥ��T���Ѥl!" << endl;
                    system("pause");
                }
                else if (invalidMove(moveFromPos, moveToPos, chessBoard.board[moveFromPos.y][moveToPos.x].piece.type)) // ���ʼҦ����ŦX�Ѻ�
                {

                }
                else // ���`���p
                {
                    players[current_player]->OnMove(chessBoard, moveFromPos, moveToPos); // ����
                    system("pause");
                    validInput = true;
                }
            }
            else if (type == "exit" || type == "Exit") // �뭰
            {
                endGame = true;
                break;
            }
            system("cls"); // �M�ŵe��
        } while (!validInput); // ���T��J�A�~���}�j��


        if (endGame) break; // �P�_�n���n���}�C��
        current_player = (current_player == 0) ? 1 : 0; // �������a

        // black turn
        validInput = false;
        do
        {
            cout << "Now is BLACK turn!\n" << endl;
            viewer.showBoard(chessBoard);
            getline(cin, command);

            stringstream ss;
            ss << command;
            ss >> type;
            if (type == "move" || type == "Move") // ����
            {
                Position moveToPos, moveFromPos;
                ss >> moveFromPos.x >> moveFromPos.y >> moveToPos.x >> moveToPos.y;

                if (chessBoard.board[moveFromPos.y][moveFromPos.x].piece.type == -1) // �q�Ū���l����
                {
                    cout << "�п�ܥ��T����m�I" << endl;
                    system("pause");
                }
                else if (chessBoard.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != players[current_player]->isWhiteSide)
                {
                    cout << "�п�ܥ��T���Ѥl!" << endl;
                    system("pause");
                }
                else
                {
                    players[current_player]->OnMove(chessBoard, moveFromPos, moveToPos);
                    validInput = true;
                }

            }
            else if (type == "exit" || type == "Exit") // �뭰
            {
                endGame = true;
                break;
            }
            else
            {

            }
            system("cls");
        } while (!validInput);


        if (endGame) break;
        current_player = (current_player == 0) ? 1 : 0;

    }
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
bool GameManager::invalidMove(Position moveFromPos, Position moveToPos, int type)
{
    if (type == 1) // king
    {

    }
    else if (type == 2) // queen
    {

    }
    else if (type == 3) // rook
    {

    }
    else if (type == 4) // bishop
    {

    }
    else if (type == 5) // knight
    {

    }
    else if (type == 6) // pawn
    {

    }
    return false;
}