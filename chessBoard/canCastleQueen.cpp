#include "chessBoard.h"

bool chessBoard::canCastleQueen(int color) {
    chessPiece rook = !color ? whiteBoard[9][2] : blackBoard[9][9];
    chessPiece king = !color ? whiteBoard[9][6] : blackBoard[9][5];
    bool check = false;

    if (!color) {
        if (rook.getPiece() == 1 && king.getPiece() == 5) { 
            if (!rook.getCastle() && !king.getCastle() && whiteCheck.empty()) { 
                if (whiteBoard[9][3].getPiece() == -1 && whiteBoard[9][4].getPiece() == -1 && whiteBoard[9][5].getPiece() == -1) {
                    movePiece(color, 9, 6, 9, 4, king, true, false, true); 
                    check = true;
                }
            }
        }
        for (std::vector<chessPiece>::iterator i = whitePieces.begin(); i != whitePieces.end(); ++i) {
            if (i->getPiece() != -1) { 
                if (isCheck(*i)) return false; 
            }
        }
        if (check) {
            movePiece(color, 9, 4, 9, 6, king, false, false, true);
            return true;
        }
    }
    else {
        if (rook.getPiece() == 1 && king.getPiece() == 6) { 
            if (!rook.getCastle() && !king.getCastle() && blackCheck.empty()) { 
                if (blackBoard[9][6].getPiece() == -1 && blackBoard[9][7].getPiece() == -1 && blackBoard[9][8].getPiece() == -1) {
                    movePiece(color, 9, 5, 9, 7, king, true, false, true);
                    check = true;
                }
            }
        }
        for (std::vector<chessPiece>::iterator i = blackPieces.begin(); i != blackPieces.end(); ++i) { 
            if (i->getPiece() != -1) {
                if (isCheck(*i)) return false; 
            }
        }
        if (check) {
            movePiece(color, 9, 7, 9, 5, king, false, false, true);
            return true;
        }
    }
   return false;
}