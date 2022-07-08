#include "chessBoard.h"

std::string chessBoard::updateBoard(int color, std::string move) {
    if (move == "Draw") {
        std::string answer;
        do {
            std::cout << "Agree to Draw?: ";
            std::cin >> answer;
            if (answer == "Y") {
                std::cout << "Game Over: Draw!" << std::endl;
                return "Y";
            }
            else if (answer == "N") {
                std::cout << "Game Continues!" << std::endl;
                return "N";
            }
        } while (true);
    } 
    else if (move == "Resign") {
        if (!color) {
            std::cout << "Game Over: Player 1 Wins!" << std::endl;
            return "Over";
        }
        else {
            std::cout << "Game Over: Player 2 Wins!" << std::endl;
            return "Over";
        }
    }
    else if (move == "CastleK" || move == "CastleQ") {
        if (move == "CastleK") {
            chessPiece rook = !color ? whiteBoard[9][9] : blackBoard[9][2];
            chessPiece king = !color ? whiteBoard[9][6] : blackBoard[9][5];

            if (!color) {
                movePiece(color, 9, 9, 9, 7, rook, true, false, false);
                movePiece(color, 9, 6, 9, 8, king, true, false, false);
            }
            else {
                movePiece(color, 9, 2, 9, 4, rook, true, false, false);
                movePiece(color, 9, 5, 9, 3, king, true, false, false);
            }
        }
        else {
            chessPiece rook = !color ? whiteBoard[9][2] : blackBoard[9][9];
            chessPiece king = !color ? whiteBoard[9][6] : blackBoard[9][5];
 
            if (!color) {
                movePiece(color, 9, 2, 9, 5, rook, true, false, false);
                movePiece(color, 9, 6, 9, 4, king, true, false, false);
            }
            else {
                movePiece(color, 9, 9, 9, 6, rook, true, false, false);
                movePiece(color, 9, 5, 9, 7, king, true, false, false);
            }
        }
    }
    else {
        chessPiece p;
        std::string array = !color ? "ABCDEFGH" : "HGFEDCBA";
        int prevX = !color ? 10 - (move[1]-'0') : (move[1]-'0')+1;
        int x = !color ? 10 - (move[3]-'0') : (move[3]-'0')+1;
        int prevY, y;
        for (int i = 0; i < 8; i++) {
            if (array[i] == move[0]) {
                prevY = i+2;
            }
            if (array[i] == move[2]) {
                y = i+2;
            }
        }
        p = !color ? whiteBoard[prevX][prevY] : blackBoard[prevX][prevY];
        movePiece(color, prevX, prevY, x, y, p, true, false, false); 
        if (move.length() == 5) {
            promotion(!color, move[4], x, y);
        }
    }
    return "";
}






