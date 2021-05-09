#include "GameManager.h"
#include <sstream>

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

            stringstream ss(command); // 切割字串用
            ss >> type;
            if (type == "move" || type == "Move") // 移動 (ex: move 0 0 0 2)
            {
                Position moveToPos, moveFromPos;
                ss >> moveFromPos.x >> moveFromPos.y >> moveToPos.x >> moveToPos.y;

                if (chessBoard.board[moveFromPos.y][moveFromPos.x].piece.type == -1) // 從空的格子移動
                {
                    cout << "請選擇正確的位置！" << endl;
                    system("pause");
                }
                else if (chessBoard.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != players[current_player]->isWhiteSide) // 移動不屬於自己的棋子
                {
                    cout << "請選擇正確的棋子!" << endl;
                    system("pause");
                }
                else if (invalidMove(moveFromPos, moveToPos, chessBoard.board[moveFromPos.y][moveToPos.x].piece.type)) // 移動模式不符合棋種
                {

                }
                else // 正常情況
                {
                    players[current_player]->OnMove(chessBoard, moveFromPos, moveToPos); // 移動
                    system("pause");
                    validInput = true;
                }
            }
            else if (type == "exit" || type == "Exit") // 投降
            {
                endGame = true;
                break;
            }
            system("cls"); // 清空畫面
        } while (!validInput); // 正確輸入，才離開迴圈


        if (endGame) break; // 判斷要不要離開遊戲
        current_player = (current_player == 0) ? 1 : 0; // 切換玩家

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
            if (type == "move" || type == "Move") // 移動
            {
                Position moveToPos, moveFromPos;
                ss >> moveFromPos.x >> moveFromPos.y >> moveToPos.x >> moveToPos.y;

                if (chessBoard.board[moveFromPos.y][moveFromPos.x].piece.type == -1) // 從空的格子移動
                {
                    cout << "請選擇正確的位置！" << endl;
                    system("pause");
                }
                else if (chessBoard.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != players[current_player]->isWhiteSide)
                {
                    cout << "請選擇正確的棋子!" << endl;
                    system("pause");
                }
                else
                {
                    players[current_player]->OnMove(chessBoard, moveFromPos, moveToPos);
                    validInput = true;
                }

            }
            else if (type == "exit" || type == "Exit") // 投降
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