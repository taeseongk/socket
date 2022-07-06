#include "chessBoard.h"

bool chessBoard::checkArray(int color, int prevX, int prevY, int x, int y, chessPiece &piece) { 
    std::vector<chessPiece>* pieces = !color ? &blackPieces : &whitePieces;
    std::deque<chessPiece>* q1 = !color ? &whiteCheck : &blackCheck;
    std::deque<chessPiece> q2 = !color ? whiteCheck : blackCheck;
    bool check = movePiece(color, prevX, prevY, x, y, piece, true, false, true);
    for (std::vector<chessPiece>::iterator i = pieces->begin(); i != pieces->end(); ++i) { 
        if (isCheck(*i)) { 
            if (check) {
                movePiece(color, x, y, prevX, prevY, piece, false, true, true);
                q1 = &q2;
            }
            else {
                movePiece(color, x, y, prevX, prevY, piece, false, false, true);
            }
            return false;
        }
    }
    if (check) {
        movePiece(color, x, y, prevX, prevY, piece, false, true, true);
        q1 = &q2;
    }
    else {
        movePiece(color, x, y, prevX, prevY, piece, false, false, true);
    }
    return true;
}