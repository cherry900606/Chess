#include "GameManager.h"
#include <sstream>

GameManager::GameManager()
{
    // �����w���O�H�����a
    this->current_player = 0; // �����wplayer1����(�մ�)
    this->players[0] = new HumanPlayer(true);
    this->players[1] = new HumanPlayer(false);
}
void GameManager::game(Board chessBoard=Board())
{
    //Board chessBoard;
    Viewer viewer;
    string command, type;


    bool endGame = false;
    while (1)
    {
        bool validInput = false;

        // white turn
        if (players[current_player]->isWhiteSide)
        {
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
                    moveFromPos.piece = chessBoard.board[moveFromPos.y][moveFromPos.x].piece;

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
                    else if (invalidMove(moveFromPos, moveToPos, chessBoard.board[moveFromPos.y][moveFromPos.x].piece.type, chessBoard)) // ���ʼҦ����ŦX�Ѻ�
                    {
                        cout << "���~�����ʤ覡�I" << endl;
                        system("pause");
                    }
                    else // ���`���p
                    {
                        players[current_player]->OnMove(chessBoard, moveFromPos, moveToPos); // ����
                        validInput = true;
                        if (isCheck(chessBoard, !players[current_player]->isWhiteSide))
                        {
                            cout << "�¤l�Q�N�x" << endl;
                            system("pause");
                        }
                        if (isCheckmate(chessBoard, !players[current_player]->isWhiteSide))
                        {
                            cout << "�¤l�N���A�դl�ӧQ�I" << endl;
                            endGame = true;
                            system("pause");
                        }
                    }
                }
                else if (type == "exit" || type == "Exit") // �뭰
                {
                    endGame = true;
                    cout << "�դl�{��A�¤l�ӧQ�I" << endl;
                    system("pause");
                    break;
                }
                else if (type == "save" || type == "Save")
                {
                    string fileName;
                    cout << "save as file name: ";
                    cin >> fileName;

                    // ���ɦW�O���_��
                    ofstream file(fileName);
                    this->saveFile.push_back(fileName);
                    if (!file)
                        cout << "�s�ɥ���" << endl;
                    else
                        cout << "�s�ɦ��\" << endl;
                    system("pause");

                    // �}�l�s��
                    file << this->current_player << endl; // �U���ѽֶ}�l
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (chessBoard.board[i][j].piece.type != -1) // x y color type icon
                                file << j << " " << i << " " << chessBoard.board[i][j].piece.isWhiteSide << " " << chessBoard.board[i][j].piece.type <<
                                chessBoard.board[i][j].piece.icon << endl;
                        }
                    }
                    cin.ignore();
                }
                system("cls"); // �M�ŵe��
            } while (!validInput); // ���T��J�A�~���}�j��

            if (endGame) // �P�_�n���n���}�C��
            {
                system("cls");
                break;
            }
            current_player = (current_player == 0) ? 1 : 0; // �������a
        }
        
        validInput = false;

        // black turn
        if (!players[current_player]->isWhiteSide)
        {
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
                    moveFromPos.piece = chessBoard.board[moveFromPos.y][moveFromPos.x].piece;

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
                    else if (invalidMove(moveFromPos, moveToPos, chessBoard.board[moveFromPos.y][moveFromPos.x].piece.type, chessBoard)) // ���ʼҦ����ŦX�Ѻ�
                    {
                        cout << "���~�����ʤ覡�I" << endl;
                        system("pause");
                    }
                    else
                    {
                        players[current_player]->OnMove(chessBoard, moveFromPos, moveToPos);
                        validInput = true;
                        if (isCheck(chessBoard, !players[current_player]->isWhiteSide))
                        {
                            cout << "�դl�Q�N�x" << endl;
                            system("pause");
                        }
                        if (isCheckmate(chessBoard, !players[current_player]->isWhiteSide))
                        {
                            cout << "�դl�N���A�¤l�ӧQ�I" << endl;
                            system("pause");
                            endGame = true;
                        }
                    }

                }
                else if (type == "exit" || type == "Exit") // �뭰
                {
                    endGame = true;
                    cout << "�¤l�{��A�դl�ӧQ�I" << endl;
                    system("pause");
                    break;
                }
                else if (type == "save" || type == "Save")
                {
                    string fileName;
                    cout << "save as file name: ";
                    cin >> fileName;

                    // ���ɦW�O���_��
                    ofstream file(fileName);
                    this->saveFile.push_back(fileName);
                    if (!file)
                        cout << "�s�ɥ���" << endl;
                    else
                        cout << "�s�ɦ��\" << endl;
                    system("pause");

                    // �}�l�s��
                    file << this->current_player << endl; // �U���ѽֶ}�l
                    for (int i = 0; i < 8; i++)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            if (chessBoard.board[i][j].piece.type != -1) // x y color type icon
                                file << j << " " << i << " " << chessBoard.board[i][j].piece.isWhiteSide << " " << chessBoard.board[i][j].piece.type <<
                                chessBoard.board[i][j].piece.icon << endl;
                        }
                    }
                    cin.ignore();
                }
                system("cls");
            } while (!validInput);

            if (endGame) // �P�_�n���n���}�C��
            {
                system("cls");
                break;
            }
            current_player = (current_player == 0) ? 1 : 0;
        }
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
		cout << "*                         1) start new game                                    *\n";
		cout << "*                         2) exit                                              *\n";
		cout << "*                         3) load game                                         *\n";
		cout << "*                                                                              *\n";
		cout << "*                                                                              *\n";
		cout << "*                                                                          v1.0*\n";
		cout << "********************************************************************************\n";
	
    
    // show menu
    //  -���Ʃεo���зN������
    //  -�i�H��Ӥ��զW��?
    // �̾ڨϥΪ̿�J�A���:
    // l) play new game
    // 2) load game
    // 3) �ڤ����D
}

// �P�_���I��m�O�_�c���׽u
bool isTilt(Position moveFromPos, Position moveToPos)
{
	return abs(moveFromPos.x - moveToPos.x) == abs(moveFromPos.y - moveToPos.y);
}

bool GameManager::invalidMove(Position moveFromPos, Position moveToPos, int type, Board board)
{
    // �����P�_�F�A�p�G�_�l�I�򵲧��I�Ѧ�ۦP�A�@�w����I�I
    if (board.board[moveToPos.y][moveToPos.x].piece.type != -1&&
        board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide == board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
        return true;

    if (type == 1) // king
    {
        if (board.board[moveToPos.y][moveToPos.x].piece.type != -1 &&
            board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide == board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide) // ���I���� & �P�v�P��
            return true;
        if (abs(moveFromPos.x - moveToPos.x) > 1 || abs(moveFromPos.y - moveToPos.y) > 1) // �����u�@�B
            return true;
        else
            return false;
    }
    else if (type == 2) // queen
    {
        if (moveFromPos.x == moveToPos.x && moveFromPos.y > moveToPos.y) // �W
        {
            int count = abs(moveFromPos.y - moveToPos.y);
            for (int i = 1; i <= count; i++)
            {
                // ���I���� && �P�v����
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y - i][moveFromPos.x].piece.type != -1)
                    return true;
            }
        }
        else if (moveFromPos.x == moveToPos.x && moveFromPos.y < moveToPos.y) // �U
        {
            int count = abs(moveFromPos.y - moveToPos.y);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y + i][moveFromPos.x].piece.type != -1)
                    return true;
            }
        }
        else if (moveFromPos.y == moveToPos.y && moveFromPos.x > moveToPos.x) // ��
        {
            int count = abs(moveFromPos.y - moveToPos.y);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y][moveFromPos.x - i].piece.type != -1)
                    return true;
            }
        }
        else if (moveFromPos.y == moveToPos.y && moveFromPos.x < moveToPos.x) // �k
        {
            int count = abs(moveFromPos.y - moveToPos.y);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y][moveFromPos.x + i].piece.type != -1)
                    return true;
            }
        }
        else if (moveFromPos.x < moveToPos.x && moveFromPos.y > moveToPos.y) // �k�W
        {
			if (!isTilt(moveFromPos, moveToPos))
			{
				return true;
			}
            int count = abs(moveFromPos.x - moveToPos.x);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y - i][moveFromPos.x + i].piece.type != -1)
                    return true;
            }
            return false;
        }
        else if (moveFromPos.x < moveToPos.x && moveFromPos.y < moveToPos.y) // �k�U
        {
			if (!isTilt(moveFromPos, moveToPos))
			{
				return true;
			}
            int count = abs(moveFromPos.x - moveToPos.x);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y + i][moveFromPos.x + i].piece.type != -1)
                    return true;
            }
            return false;
        }
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y > moveToPos.y) // ���W
        {
			if (!isTilt(moveFromPos, moveToPos))
			{
				return true;
			}
            int count = abs(moveFromPos.x - moveToPos.x);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y - i][moveFromPos.x - i].piece.type != -1)
                    return true;
            }
            return false;
        }
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y < moveToPos.y) // ���U
        {
			if (!isTilt(moveFromPos, moveToPos))
			{
				return true;
			}
            int count = abs(moveFromPos.x - moveToPos.x);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y + i][moveFromPos.x - i].piece.type != -1)
                    return true;
            }
            return false;
        }
    }
    else if (type == 3) // rook
    {
        if ((moveFromPos.x == moveToPos.x) && abs(moveFromPos.y - moveToPos.y) != 0) // �����u
        {
            if (moveFromPos.y > moveToPos.y) // ���W��
            {
                for (int i = moveFromPos.y - 1; i >= moveToPos.y; i--) // �q�ۤv�W�����樫�_
                {
                    // �̫�@�B && �O�Ĥ��
                    if (i == moveToPos.y && board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide)
                        return false;
                    if (board.board[i][moveFromPos.x].piece.type != -1)
                        return true;
                }
                return false;
            }
            else // ���U��
            {
                for (int i = moveFromPos.y + 1; i <= moveToPos.y; i++) // �q�ۤv�U�����樫�_
                {
                    // �̫�@�B && �O�Ĥ��
                    if (i == moveToPos.y && board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide)
                        return false;
                    if (board.board[i][moveFromPos.x].piece.type != -1)
                        return true;
                }
                return false;
            }
        }
        else if ((moveFromPos.y == moveToPos.y) && abs(moveFromPos.x - moveToPos.x) != 0) // ����u
        {
            if (moveFromPos.x > moveToPos.x) // ������
            {
                for (int i = moveFromPos.x - 1; i >= moveToPos.x; i--) // �q����@�樫�_
                {
                    // �̲׮� && �Ĥ��
                    if (i == moveToPos.x && board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide)
                        return false;
                    // ���O�Ů�
                    if (board.board[moveFromPos.y][i].piece.type != -1)
                        return true;
                }
                return false;
            }
            else // ���k��
            {
                for (int i = moveFromPos.x + 1; i <= moveToPos.x; i++) // �q�k��@�樫�_
                {
                    // �̲׮� && �Ĥ��
                    if (i == moveToPos.x && board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide)
                        return false;
                    // ���O�Ů�
                    if (board.board[moveFromPos.y][i].piece.type != -1)
                        return true;
                }
                return false;
            }
        }
        return true;
    }
    else if (type == 4) // bishop
    {
        if (moveFromPos.x == moveToPos.x || moveFromPos.y == moveToPos.y)
            return true;
		if (!isTilt(moveFromPos, moveToPos))
		{
			return true;
		}

        if (moveFromPos.x < moveToPos.x && moveFromPos.y > moveToPos.y) // ��k�W
        {
            int count = abs(moveFromPos.x - moveToPos.x);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y - i][moveFromPos.x + i].piece.type != -1)
                    return true;
            }
            return false;
        }
        else if (moveFromPos.x < moveToPos.x && moveFromPos.y < moveToPos.y) // �k�U
        {
            int count = abs(moveFromPos.x - moveToPos.x);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y + i][moveFromPos.x + i].piece.type != -1)
                    return true;
            }
            return false;
        }
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y > moveToPos.y) // ���W
        {
            int count = abs(moveFromPos.x - moveToPos.x);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y - i][moveFromPos.x - i].piece.type != -1)
                    return true;
            }
            return false;
        }
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y < moveToPos.y) // ���U
        {
            int count = abs(moveFromPos.x - moveToPos.x);
            for (int i = 1; i <= count; i++)
            {
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y + i][moveFromPos.x - i].piece.type != -1)
                    return true;
            }
            return false;
        }

    }
    else if (type == 5) // knight
    {
        if (moveFromPos.y - 2 == moveToPos.y && abs(moveFromPos.x - moveToPos.x) == 1) // �W��B ���k
            return false;
        if (moveFromPos.y + 2 == moveToPos.y && abs(moveFromPos.x - moveToPos.x) == 1) // �U��B ���k
            return false;
        if (moveFromPos.x - 2 == moveToPos.x && abs(moveFromPos.y - moveToPos.y) == 1) // ����B �W�U
            return false;
        if (moveFromPos.x + 2 == moveToPos.x && abs(moveFromPos.y - moveToPos.y) == 1) // �k��B �W�U
            return false;
        return true;
    }
    else if (type == 6) // pawn
    {
        if (moveFromPos.piece.isWhiteSide) //�դl�u�੹�W��
        {
            // �׫e��@��Y�l
            if (abs(moveFromPos.x - moveToPos.x) == 1 && moveFromPos.y - 1 == moveToPos.y)
                return false;
            // �@�벾��
            if (moveFromPos.piece.isFirstMove) // first step can move one or two
            {
                // ���W�� && ���I�Ů�(���¤���)
                if ((moveFromPos.x == moveToPos.x) && (moveFromPos.y - 1 == moveToPos.y || moveFromPos.y - 2 == moveToPos.y) &&
                    board.board[moveToPos.y][moveToPos.x].piece.type == -1)
                    return false;
                return true;
            }
            if ((moveFromPos.x == moveToPos.x) && (moveFromPos.y - 1 == moveToPos.y) &&
				board.board[moveToPos.y][moveToPos.x].piece.type == -1) // other steps can only move one
                return false;
            return true;
        }
        else // �¤l�u�੹�U��
        {
            if (abs(moveFromPos.x - moveToPos.x) == 1 && moveFromPos.y + 1 == moveToPos.y)
                return false;
            if (moveFromPos.piece.isFirstMove)
            {
                if ((moveFromPos.x == moveToPos.x) && (moveFromPos.y + 1 == moveToPos.y || moveFromPos.y + 2 == moveToPos.y) &&
                    board.board[moveToPos.y][moveToPos.x].piece.type == -1)
                    return false;
                return true;
            }
            if ((moveFromPos.x == moveToPos.x) && (moveFromPos.y + 1 == moveToPos.y) &&
				board.board[moveToPos.y][moveToPos.x].piece.type == -1)
                return false;
            return true;
        }
    }
    return false;
}

//�N�����P�_��k:
//����i�H�����Y���]�A�ۨ��b�����E�c��
//�]���A�u�ݱN�Ĥ�Ѥl�����P�_�L�@���A
//�Y�ӴѤl�i�H���ʨ�E�c�椧�@�A�Y���аO
//�̫�ݤE�c��O�_���Q�аO�A�Φ��v��ѦӵL�k�@��
//�p�H�@�ӡA��F���u�U�@�B�|�Q�Ĥ�Y���v�B�u�L�k�k�]�v
//�h�N���C
bool GameManager::isCheckmate(Board board, bool kingIsWhite)  // �ѽL�P�Ĥ����C��
{
    int countTable[8][8] = { 0 };
    Position kingPos;

     // ���n�T�{�N����������m
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board.board[i][j].piece.type == 1 && board.board[i][j].piece.isWhiteSide == kingIsWhite)
            {
                kingPos.x = j;
                kingPos.y = i;
                break;
            }
        }
    }
    board.board[kingPos.y][kingPos.x].piece = Piece(-1, false);

	Position moveFromPos, moveToPos; // �q���沾��
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // �Ӯ榳�� && �Ĥ��
            if (board.board[i][j].piece.type != -1 && board.board[i][j].piece.isWhiteSide != kingIsWhite)
            {
                moveFromPos.x = j; moveFromPos.y = i;
                for (int y = -1; y <= 1; y++) // �H�������ߪ��E�c���L�@��
                {
                    for (int x = -1; x <= 1; x++)
                    {
						moveToPos.x = kingPos.x + x;
						moveToPos.y = kingPos.y + y;
                        
                        if (kingPos.y + y < 0 || kingPos.y + y>7 || kingPos.x + x < 0 || kingPos.x + x>7) // �ˬd���
                            continue;

                        Piece tempPiece;
                        bool isChange = false;
                        if (board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != kingIsWhite) // �p�G�n���ʨ쪺���椣�O����P�⪺��(�Ĥ��)
                        {
                            isChange = true;
                            tempPiece = board.board[moveToPos.y][moveToPos.x].piece;
                            board.board[moveToPos.y][moveToPos.x].piece = Piece(-1, false);
                        }
                        if (!invalidMove(moveFromPos, moveToPos, board.board[i][j].piece.type, board)) //�i�H���ʨ�Ӯ�
                        {
                            countTable[moveToPos.y][moveToPos.x]++;
							//cout << "x= " << moveFromPos.x << ", y= " << moveFromPos.y << " move to x=" << moveToPos.x << ", y= " << moveToPos.y << endl;
                        }
                        if (isChange)
                        {
                            board.board[moveToPos.y][moveToPos.x].piece = tempPiece;
                        }
                    }
                }
            }
        }
    }

    // for test
	/*cout << "king color: " << kingIsWhite << endl;
    cout << "king pos: " << kingPos.x << " " << kingPos.y << endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << countTable[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");*/

    // �̫��ˬdcountTable
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (kingPos.y + i < 0 || kingPos.y + i>7 || kingPos.x + j < 0 || kingPos.x + j>7) // �ˬd���
                continue;
            if (board.board[kingPos.y + i][kingPos.x + j].piece.isWhiteSide == kingIsWhite)
                countTable[kingPos.y + i][kingPos.x + j]++;
            if (countTable[kingPos.y + i][kingPos.x + j] == 0) // �u�n���@��w���A�N���|�Q�N�x
                return false;
        }
    }
    return true;
}
bool GameManager::isCheck(Board board, bool kingIsWhite)
{
    Position kingPos;

    // ���n�T�{�N����������m
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board.board[i][j].piece.type == 1 && board.board[i][j].piece.isWhiteSide == kingIsWhite)
            {
                kingPos.x = j;
                kingPos.y = i;
                break;
            }
        }
    }

    Position moveFromPos; // �q���沾��
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // �Ӯ榳�� && �Ĥ��
            if (board.board[i][j].piece.type != -1 && board.board[i][j].piece.isWhiteSide != kingIsWhite)
            {
                moveFromPos.x = j; moveFromPos.y = i;
                if (!invalidMove(moveFromPos, kingPos, board.board[i][j].piece.type, board))
                {
                    return true; // �u�n���@�ӴѤl�|�¯٨�A�N�c���N�x
                }
            }
        }
    }
    return false;
}