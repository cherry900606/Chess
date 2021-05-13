#include "GameManager.h"
#include <sstream>

GameManager::GameManager()
{
    // 先假定都是人類玩家
    this->current_player = 0; // 先假定player1先手(白棋)
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

                stringstream ss(command); // 切割字串用
                ss >> type;
                if (type == "move" || type == "Move") // 移動 (ex: move 0 0 0 2)
                {
                    Position moveToPos, moveFromPos;
                    ss >> moveFromPos.x >> moveFromPos.y >> moveToPos.x >> moveToPos.y;
                    moveFromPos.piece = chessBoard.board[moveFromPos.y][moveFromPos.x].piece;

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
                    else if (invalidMove(moveFromPos, moveToPos, chessBoard.board[moveFromPos.y][moveFromPos.x].piece.type, chessBoard)) // 移動模式不符合棋種
                    {
                        cout << "錯誤的移動方式！" << endl;
                        system("pause");
                    }
                    else // 正常情況
                    {
                        players[current_player]->OnMove(chessBoard, moveFromPos, moveToPos); // 移動
                        validInput = true;
                        if (isCheckmate(chessBoard, !players[current_player]->isWhiteSide))
                        {
                            cout << "黑子將死!!" << endl;
                            endGame = true;
                            system("pause");
                        }
                    }
                }
                else if (type == "exit" || type == "Exit") // 投降
                {
                    endGame = true;
                    break;
                }
                else if (type == "save" || type == "Save")
                {
                    string fileName;
                    cout << "save as file name: ";
                    cin >> fileName;

                    // 把檔名記錄起來
                    ofstream file(fileName);
                    this->saveFile.push_back(fileName);
                    if (!file)
                        cout << "存檔失敗" << endl;
                    else
                        cout << "存檔成功" << endl;
                    system("pause");

                    // 開始存檔
                    file << this->current_player << endl; // 下次由誰開始
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
                system("cls"); // 清空畫面
            } while (!validInput); // 正確輸入，才離開迴圈

            if (endGame) break; // 判斷要不要離開遊戲
            current_player = (current_player == 0) ? 1 : 0; // 切換玩家
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
                if (type == "move" || type == "Move") // 移動
                {
                    Position moveToPos, moveFromPos;
                    ss >> moveFromPos.x >> moveFromPos.y >> moveToPos.x >> moveToPos.y;
                    moveFromPos.piece = chessBoard.board[moveFromPos.y][moveFromPos.x].piece;

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
                    else if (invalidMove(moveFromPos, moveToPos, chessBoard.board[moveFromPos.y][moveFromPos.x].piece.type, chessBoard)) // 移動模式不符合棋種
                    {
                        cout << "錯誤的移動方式！" << endl;
                        system("pause");
                    }
                    else
                    {
                        players[current_player]->OnMove(chessBoard, moveFromPos, moveToPos);
                        validInput = true;
                        if (isCheckmate(chessBoard, !players[current_player]->isWhiteSide))
                        {
                            cout << "白子將死!!" << endl;
                            system("pause");
                            endGame = true;
                        }
                    }

                }
                else if (type == "exit" || type == "Exit") // 投降
                {
                    endGame = true;
                    break;
                }
                else if (type == "save" || type == "Save")
                {
                    string fileName;
                    cout << "save as file name: ";
                    cin >> fileName;

                    // 把檔名記錄起來
                    ofstream file(fileName);
                    this->saveFile.push_back(fileName);
                    if (!file)
                        cout << "存檔失敗" << endl;
                    else
                        cout << "存檔成功" << endl;
                    system("pause");

                    // 開始存檔
                    file << this->current_player << endl; // 下次由誰開始
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

            if (endGame) break;
            current_player = (current_player == 0) ? 1 : 0;
        }
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
		cout << "*                         1) start new game                                    *\n";
		cout << "*                         2) exit                                              *\n";
		cout << "*                         3) load game                                         *\n";
		cout << "*                                                                              *\n";
		cout << "*                                                                              *\n";
		cout << "*                                                                          v1.0*\n";
		cout << "********************************************************************************\n";
	
    
    // show menu
    //  -美化或發揮創意的介面
    //  -可以放個分組名單?
    // 依據使用者輸入，選擇:
    // l) play new game
    // 2) load game
    // 3) 我不知道
}

// 判斷兩點位置是否構成斜線
bool isTilt(Position moveFromPos, Position moveToPos)
{
	return abs(moveFromPos.x - moveToPos.x) == abs(moveFromPos.y - moveToPos.y);
}

bool GameManager::invalidMove(Position moveFromPos, Position moveToPos, int type, Board& board)
{
    // 直接判斷了，如果起始點跟結束點棋色相同，一定不對！！
    if (board.board[moveToPos.y][moveToPos.x].piece.type != -1&&
        board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide == board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
        return true;

    if (type == 1) // king
    {
        if (board.board[moveToPos.y][moveToPos.x].piece.type != -1 &&
            board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide == board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide) // 終點有棋 & 與己同色
            return true;
        if (moveToPos.y == 7 || moveToPos.y == 0) {
            if (moveToPos.y == moveFromPos.y) {
                if (abs(moveToPos.x - moveFromPos.x) == 2) {
                    //檢查是否是王車易位
                    cout << "Check Castling." << endl;
                    if (Castling(moveFromPos, moveToPos, board)) {
                        cout << "Castling success." << endl;
                        system("pause");
                        if (moveFromPos.x > moveToPos.x) {
                            //move to left
                            moveFromPos.x = 0;
                            moveToPos.x = moveFromPos.x + 3;
                            players[current_player]->OnMove(board, moveFromPos, moveToPos);
                        }
                        else {
                            //move to right
                            moveFromPos.x = 7;
                            moveToPos.x = moveFromPos.x - 2;
                            players[current_player]->OnMove(board, moveFromPos, moveToPos);
                        }
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
        }
        if (abs(moveFromPos.x - moveToPos.x) + abs(moveFromPos.y - moveToPos.y) > 1) // 走不只一步
            return true;
        else
            return false;
    }
    else if (type == 2) // queen
    {
        if (moveFromPos.x == moveToPos.x && moveFromPos.y > moveToPos.y) // 上
        {
            int count = abs(moveFromPos.y - moveToPos.y);
            for (int i = 1; i <= count; i++)
            {
                // 終點有棋 && 與己異色
                if (i == count &&
                    board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide)
                    return false;
                if (board.board[moveFromPos.y - i][moveFromPos.x].piece.type != -1)
                    return true;
            }
        }
        else if (moveFromPos.x == moveToPos.x && moveFromPos.y < moveToPos.y) // 下
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
        else if (moveFromPos.y == moveToPos.y && moveFromPos.x > moveToPos.x) // 左
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
        else if (moveFromPos.y == moveToPos.y && moveFromPos.x < moveToPos.x) // 右
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
        else if (moveFromPos.x < moveToPos.x && moveFromPos.y > moveToPos.y) // 右上
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
        else if (moveFromPos.x < moveToPos.x && moveFromPos.y < moveToPos.y) // 右下
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
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y > moveToPos.y) // 左上
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
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y < moveToPos.y) // 左下
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
        if ((moveFromPos.x == moveToPos.x) && abs(moveFromPos.y - moveToPos.y) != 0) // 走直線
        {
            if (moveFromPos.y > moveToPos.y) // 往上走
            {
                for (int i = moveFromPos.y - 1; i >= moveToPos.y; i--) // 從自己上面那格走起
                {
                    // 最後一步 && 是敵方棋
                    if (i == moveToPos.y && board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide)
                        return false;
                    if (board.board[i][moveFromPos.x].piece.type != -1)
                        return true;
                }
                return false;
            }
            else // 往下走
            {
                for (int i = moveFromPos.y + 1; i <= moveToPos.y; i++) // 從自己下面那格走起
                {
                    // 最後一步 && 是敵方棋
                    if (i == moveToPos.y && board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide)
                        return false;
                    if (board.board[i][moveFromPos.x].piece.type != -1)
                        return true;
                }
                return false;
            }
        }
        else if ((moveFromPos.y == moveToPos.y) && abs(moveFromPos.x - moveToPos.x) != 0) // 走橫線
        {
            if (moveFromPos.x > moveToPos.x) // 往左走
            {
                for (int i = moveFromPos.x - 1; i >= moveToPos.x; i--) // 從左邊一格走起
                {
                    // 最終格 && 敵方棋
                    if (i == moveToPos.x && board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide)
                        return false;
                    // 不是空格
                    if (board.board[moveFromPos.y][i].piece.type != -1)
                        return true;
                }
                return false;
            }
            else // 往右走
            {
                for (int i = moveFromPos.x + 1; i <= moveToPos.x; i++) // 從右邊一格走起
                {
                    // 最終格 && 敵方棋
                    if (i == moveToPos.x && board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide != board.board[moveToPos.y][moveToPos.x].piece.isWhiteSide)
                        return false;
                    // 不是空格
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

        if (moveFromPos.x < moveToPos.x && moveFromPos.y > moveToPos.y) // 到右上
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
        else if (moveFromPos.x < moveToPos.x && moveFromPos.y < moveToPos.y) // 右下
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
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y > moveToPos.y) // 左上
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
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y < moveToPos.y) // 左下
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
        if (moveFromPos.y - 2 == moveToPos.y && abs(moveFromPos.x - moveToPos.x) == 1) // 上兩步 左右
            return false;
        if (moveFromPos.y + 2 == moveToPos.y && abs(moveFromPos.x - moveToPos.x) == 1) // 下兩步 左右
            return false;
        if (moveFromPos.x - 2 == moveToPos.x && abs(moveFromPos.y - moveToPos.y) == 1) // 左兩步 上下
            return false;
        if (moveFromPos.x + 2 == moveToPos.x && abs(moveFromPos.y - moveToPos.y) == 1) // 右兩步 上下
            return false;
        return true;
    }
    else if (type == 6) // pawn
    {
        if (moveFromPos.piece.isWhiteSide) //白子只能往上走
        {
            // 斜前方一格吃子
            if (abs(moveFromPos.x - moveToPos.x) == 1 && moveFromPos.y - 1 == moveToPos.y)
                return false;
            // 一般移動
            if (moveFromPos.piece.isFirstMove) // first step can move one or two
            {
                // 往上走 && 終點空格(不黑不白)
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
        else // 黑子只能往下走
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

//將死的判斷方法:
//國王可以走的即為包括自身在內的九宮格
//因此，只需將敵方棋子全部判斷過一次，
//若該棋子可以移動到九宮格之一，即做標記
//最後看九宮格是否都被標記，或有己方棋而無法一動
//如以一來，當達成「下一步會被敵方吃掉」且「無法逃跑」
//則將死。
bool GameManager::isCheckmate(Board board, bool kingIsWhite)  // 棋盤與敵方國王顏色
{
    int countTable[8][8] = { 0 };
    Position kingPos;

     // 找到要確認將死的王的位置
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

	Position moveFromPos, moveToPos; // 從哪格移動
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // 該格有棋 && 敵方棋
            if (board.board[i][j].piece.type != -1 && board.board[i][j].piece.isWhiteSide != kingIsWhite)
            {
                moveFromPos.x = j; moveFromPos.y = i;
                for (int y = -1; y <= 1; y++) // 以王為中心的九宮格找過一次
                {
                    for (int x = -1; x <= 1; x++)
                    {
						moveToPos.x = kingPos.x + x;
						moveToPos.y = kingPos.y + y;
                        if (kingPos.y + y < 0 || kingPos.y + y>7 || kingPos.x + x < 0 || kingPos.x + x>7) // 檢查邊界
                            continue;
                        if (!invalidMove(moveFromPos, moveToPos, board.board[i][j].piece.type, board)) //可以移動到該格
                        {
                            countTable[moveToPos.y][moveToPos.x]++;
							cout << "x= " << moveFromPos.x << ", y= " << moveFromPos.y << " move to x=" << moveToPos.x << ", y= " << moveToPos.y << endl;
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

    // 最後檢查countTable
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (kingPos.y + i < 0 || kingPos.y + i>7 || kingPos.x + j < 0 || kingPos.x + j>7) // 檢查邊界
                continue;
            if (countTable[kingPos.y + i][kingPos.x + j] == 0) // 只要有一格安全，就不會被將軍
                return false;
        }
    }
    return true;
}
/*Castling
  目前想法是使用者如果要執行王車易位，直接輸入移動王兩格即可
*/
bool GameManager::Castling(Position moveFromPos, Position moveToPos, Board board) {
    int count_attact = 0;
    //確認要移動的是王，且是第一次移動
    if (board.board[moveFromPos.y][moveFromPos.x].piece.type == 1 && board.board[moveFromPos.y][moveFromPos.x].piece.isFirstMove == true) {
        if (moveFromPos.x < moveToPos.x && moveFromPos.y == moveToPos.y) {
            //右移(短易位)，且終點的右邊一格是城堡
            if (board.board[moveToPos.y][moveToPos.x + 1].piece.type == 3 && board.board[moveToPos.y][moveToPos.x + 1].piece.isFirstMove == true) {
                //判斷國王和城堡中間都沒有棋子
                for (int i = 1;i <= 2;i++) {
                    if (board.board[moveFromPos.y][moveFromPos.x + i].piece.type != -1) {
                        return false;
                    }
                }
                //中間紅點目前都沒有被攻擊(包含王自己)
                Position attact_;
                Position moveToPos_;
                moveToPos_.x = moveFromPos.x;
                moveToPos_.y = moveFromPos.y;
                for (int j = 0;j < 8;j++) {
                    for (int i = 0;i < 8;i++) {
                        if (board.board[j][i].piece.type != -1 && board.board[j][i].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide) {
                            attact_.x = i;
                            attact_.y = j;
                            for (int a = 0;a < 3;a++) {
                                moveToPos_.x++;
                                moveToPos_.y++;
                                if (!invalidMove(attact_, moveToPos_, board.board[j][i].piece.type, board)) {
                                    count_attact++;
                                }
                            }
                        }
                    }
                }
                if (count_attact > 0) {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                return false;
            }
        }
        else if (moveFromPos.x > moveToPos.x && moveFromPos.y == moveToPos.y) {
            //左移(長易位)，且終點的左邊兩格是城堡
            if (board.board[moveToPos.y][moveToPos.x - 2].piece.type == 3 && board.board[moveToPos.y][moveToPos.x - 2].piece.isFirstMove == true) {
                //判斷國王和城堡中間都沒有棋子
                for (int i = 1;i <= 3;i++) {
                    if (board.board[moveFromPos.y][moveFromPos.x - i].piece.type != -1) {
                        return false;
                    }
                }
                //中間紅點目前都沒有被攻擊(包含王自己)
                Position attact_;
                Position moveToPos_;
                moveToPos_.x = moveFromPos.x;
                moveToPos_.y = moveFromPos.y;
                for (int j = 0;j < 8;j++) {
                    for (int i = 0;i < 8;i++) {
                        if (board.board[j][i].piece.type != -1 && board.board[j][i].piece.isWhiteSide != board.board[moveFromPos.y][moveFromPos.x].piece.isWhiteSide) {
                            attact_.x = i;
                            attact_.y = j;
                            for (int a = 0;a < 3;a++) {
                                moveToPos_.x--;
                                moveToPos_.y--;
                                if (!invalidMove(attact_, moveToPos_, board.board[j][i].piece.type, board)) {
                                    count_attact++;
                                }
                            }
                        }
                    }
                }
                if (count_attact > 0) {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                return false;
            }
        }
        else {
            //to From 同點
            return false;
        }
    }
    else {
        return false;
    }
}