#include "chessBoard.h"

bool chessBoard::movePiece(int color, int prevX, int prevY, int x, int y, chessPiece &piece, bool temp1, bool temp2, bool temp3) {
    chessPiece emptyPiece = chessPiece();
    int prevX1 = abs(prevX - 11);
    int prevY1 = abs(prevY - 11);
    int x1 = abs(x - 11);
    int y1 = abs(y - 11);
    bool check = false;

   if (!color) {
        whiteBoard[prevX][prevY] = emptyPiece;
        blackBoard[prevX1][prevY1] = emptyPiece;
        for (std::vector<chessPiece>::iterator i = whitePieces.begin(); i != whitePieces.end(); ++i) {
            if (piece.getPosition().first == i->getPosition().first && 
            piece.getPosition().second == i->getPosition().second) { 
                piece.setPosition(x, y);
                *i = piece;
                break;
            }
        }
        if (whiteBoard[x][y].getColor() == 1) {
            for (std::vector<chessPiece>::iterator i = blackPieces.begin(); i != blackPieces.end(); ++i) {
                if (x1 == i->getPosition().first && y1 == i->getPosition().second) {
                    if (temp1) {
                        reservePiece = *i;
                        reservePos.first = x1;
                        reservePos.second = y1;
                        check = true;
                    }
                    blackPieces.erase(i);
                    break;
                }
            }
            for (std::deque<chessPiece>::iterator j = whiteCheck.begin(); j != whiteCheck.end(); ++j) {
                if (x1 == j->getPosition().first && y1 == j->getPosition().second) {
                    whiteCheck.erase(j);
                    break;
                }
            }
        }
        whiteBoard[x][y] = piece;
        blackBoard[x1][y1] = piece;
        blackBoard[x1][y1].setPosition(x1, y1);
        if (isCheck(piece) && !temp3) {
            blackCheck.push_back(piece);
        }
        if (temp2) {
            blackBoard[reservePos.first][reservePos.second] = reservePiece;
            whiteBoard[abs(reservePos.first-11)][abs(reservePos.second-11)] = reservePiece;
            blackPieces.push_back(reservePiece);
        }
   }
   else {
        blackBoard[prevX][prevY] = emptyPiece; 
        whiteBoard[prevX1][prevY1] = emptyPiece;
        for (std::vector<chessPiece>::iterator i = blackPieces.begin(); i != blackPieces.end(); ++i) {
            if (piece.getPosition().first == i->getPosition().first &&
            piece.getPosition().second == i->getPosition().second) {
                piece.setPosition(x, y);
                *i = piece;
                break;
            }
        }
        if (blackBoard[x][y].getColor() == 0) {
            for (std::vector<chessPiece>::iterator i = whitePieces.begin(); i != whitePieces.end(); ++i) {
                if (x1 == i->getPosition().first && y1 == i->getPosition().second) {
                if (temp1) {
                    reservePiece = *i;
                    reservePos.first = x1;
                    reservePos.second = y1;
                    check = true;
                }
                whitePieces.erase(i);
                break;
                }
            }
            for (std::deque<chessPiece>::iterator j = blackCheck.begin(); j != blackCheck.end(); ++j) {
                if (x1 == j->getPosition().first && y1 == j->getPosition().second) {
                    blackCheck.erase(j);
                    break;
                }
            }
        }
        blackBoard[x][y] = piece; 
        whiteBoard[x1][y1] = piece;
        whiteBoard[x1][y1].setPosition(x1, y1);
        if (isCheck(piece) && !temp3) {
            whiteCheck.push_back(piece);
        }
        if (temp2) {
            whiteBoard[reservePos.first][reservePos.second] = reservePiece;
            blackBoard[abs(reservePos.first-11)][abs(reservePos.second-11)] = reservePiece;
            whitePieces.push_back(reservePiece);
        }
    }
    return check;
}
