#include "chessBoard.h"

bool chessBoard::makeMove(int color) {
    std::string array = !color ? "ABCDEFGH" : "HGFEDCBA";
    std::string piece;
    std::pair<int, int> pieceP;
    chessPiece p;
    bool check1 = false;
    bool check2 = false;
    std::string position;
    int x, y;
    std::string prom;
    std::string answer;
    bool check3 = false;
    bool check5 = false;
    std::deque<chessPiece> q = !color ? whiteCheck : blackCheck;

    if (!q.empty()) {
        if (isCheckmate(color)) {
            if (!color) {
            std::cout << "Checkmate: Player 2 wins!" << std::endl;
            return true;
            }
            else {
            std::cout << "Checkmate: Player 1 wins!" << std::endl;
            return true;
            }
        }
    }
    else {
        if (isStalemate(color)) {
            std::cout << "Game Over: Tie!" << std::endl;
            return true;
        }
    }
    do {
        std::cout << "Which piece: ";
        std::cin >> piece;
        if (piece == "Castle") {
            if (canCastleQueen(color) || canCastleKing(color)) goto HERE4;
            continue;
        }
        if (piece == "Draw") {
            do {
            std::cout << "Does other player agree: ";
            std::cin >> answer;
            if (answer != "Y" && answer != "N") {
                continue;
            }
            if (answer == "Y") {
                std::cout << "Game Over: Tie!" << std::endl;
                return true;
            }
            check5 = true;
            } while (!check5);
        }
        if (piece == "Resign") {
            if (!color) {
            std::cout << "Game Over: Player 2 Wins!" << std::endl;
            return true;
            }
            else {
            std::cout << "Game Over: Player 1 Wins!" << std::endl;
            return true;
            }
        }
        std::stringstream n1;
        int n_1;
        n1 << piece[1];
        n1 >> n_1;
        pieceP.first = !color ? 10 - n_1 : n_1+1;
        for (int i = 0; i < 8; i++) {
            if (array[i] == piece[0]) {
            pieceP.second = i+2;
            }
        }
        if (pieceP.first < 2 || pieceP.first > 9 || pieceP.second < 2 || pieceP.second > 9) continue;
        p = !color ? whiteBoard[pieceP.first][pieceP.second] : blackBoard[pieceP.first][pieceP.second];
        if (!checkSurr(p)) continue;
        if (p.getColor() != color) continue;
        if (!checkPiece1(p)) continue;
        if (!checkPiece2(p)) continue;
        check1 = true;
    } while (!check1);
    do {
        std::cout << "Move to: ";
        std::cin >> position;
        std::stringstream n2;
        int n_2;
        n2 << position[1];
        n2 >> n_2;
        x = !color ? 10 - n_2 : n_2+1;
        for (int i = 0; i < 8; i++) {
            if (array[i] == position[0]) {
            y = i+2;
            }
        }
        if (x < 2 || x > 9 || y < 2 || y > 9) continue; 
        if (!checkMove(p, x, y)) continue; 
        if (!checkQueue(color, pieceP.first, pieceP.second, x, y, p)) continue;
        if (!checkArray(color, pieceP.first, pieceP.second, x, y, p)) continue;
        if (p.getPiece() == 0 && x == 2) {
            do {
            std::cout << "Which piece: ";
            std::cin >> prom;
            if (prom != "Q" && prom != "R" && prom != "N" && prom != "B") continue;
            check3 = true;
            } while (!check3);
        }
        check2 = true;
    } while (!check2);
    movePiece(color, pieceP.first, pieceP.second, x, y, p, true, false, false);
    if (check3) {
        promotion(color, prom[0], x, y);
    }
    if (false) { 
        HERE4:
        std::string side;
        bool check4 = false;
        do {
            std::cout << "Which side: ";
            std::cin >> side;
            if (side != "K" && side != "Q") continue;
            if (canCastleQueen(color)) {
            if (side != "Q") continue;
            castleQueen(color);
            }
            else if (canCastleKing(color)) {
            if (side != "K") continue;
            castleKing(color);
            }
            else if (canCastleQueen(color) && canCastleKing(color)) {
            if (side == "Q") {
                castleQueen(color);
            }
            else if (side == "K") {
                castleKing(color);
            }
            }
            check4 = true;
        } while (!check4);
    }
    return false;
}