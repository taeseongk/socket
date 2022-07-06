#include "chessBoard.h"

void chessBoard::castleQueen(int color) {
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