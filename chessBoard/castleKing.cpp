#include "chessBoard.h"

void chessBoard::castleKing(int color) {
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
