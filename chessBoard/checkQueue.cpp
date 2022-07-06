#include "chessBoard.h"

bool chessBoard::checkQueue(int color, int prevX, int prevY, int x, int y, chessPiece &piece) { 
   std::deque<chessPiece>* q1 = !color ? &whiteCheck : &blackCheck;
   std::deque<chessPiece> q2 = !color ? whiteCheck : blackCheck;
   bool check = movePiece(color, prevX, prevY, x, y, piece, true, false, true);
    while (!q1->empty()) { 
        if (isCheck(q1->front())) {
            if (check) {
                movePiece(color, x, y, prevX, prevY, piece, false, true, true);
                q1 = &q2;
            }
            else {
                movePiece(color, x, y, prevX, prevY, piece, false, false, true);
            }
            return false;
        }
        q1->pop_front();
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