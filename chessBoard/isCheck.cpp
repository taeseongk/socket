#include "chessBoard.h"

bool chessBoard::isCheck(chessPiece piece) const { //return true if move caused check for opponent
   int i = piece.getPosition().first;
   int j = piece.getPosition().second;
   int color = piece.getColor();
   int king = !color ? 6 : 5;
   chessPiece** board = !color ? whiteBoard : blackBoard;
   switch (piece.getPiece()) {
      case 0:
         if (board[i-1][j-1].getPiece() == king || board[i-1][j+1].getPiece() == king) return true;
         break;
      case 1:
         for (int k = 1; k < 8; k++) { //left
            if (board[i][j-k].getPiece() == king) return true;
            else if (board[i][j-k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //right
            if (board[i][j+k].getPiece() == king) return true;
            else if (board[i][j+k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //up
            if (board[i-k][j].getPiece() == king) return true;
            else if (board[i-k][j].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //down
            if (board[i+k][j].getPiece() == king) return true;
            else if (board[i+k][j].getPiece() != -1) break;
         }
         break;
      case 2:
         if (board[i-2][j-1].getPiece() == king || board[i-2][j+1].getPiece() == king || board[i-1][j+2].getPiece() == king || 
         board[i+1][j+2].getPiece() == king || board[i+2][j+1].getPiece() == king || board[i+2][j-1].getPiece() == king || 
         board[i+1][j-2].getPiece() == king || board[i-1][j-2].getPiece() == king) return true;
         break;
      case 3:
         for (int k = 1; k < 8; k++) { //up-left
            if (board[i-k][j-k].getPiece() == king) return true;
            else if (board[i-k][j-k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //up-right
            if (board[i-k][j+k].getPiece() == king) return true;
            else if (board[i-k][j+k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //down-left
            if (board[i+k][j-k].getPiece() == king) return true;
            else if (board[i+k][j-k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //down-right
            if (board[i+k][j+k].getPiece() == king) return true;
            else if (board[i+k][j+k].getPiece() != -1) break;
         }
         break;
      case 4:
         for (int k = 1; k < 8; k++) { //left
            if (board[i][j-k].getPiece() == king) return true;
            else if (board[i][j-k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //right
            if (board[i][j+k].getPiece() == king) return true;
            else if (board[i][j+k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //up
            if (board[i-k][j].getPiece() == king) return true;
            else if (board[i-k][j].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //down
            if (board[i+k][j].getPiece() == king) return true;
            else if (board[i+k][j].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //up-left
            if (board[i-k][j-k].getPiece() == king) return true;
            else if (board[i-k][j-k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //up-right
            if (board[i-k][j+k].getPiece() == king) return true;
            else if (board[i-k][j+k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //down-left
            if (board[i+k][j-k].getPiece() == king) return true;
            else if (board[i+k][j-k].getPiece() != -1) break;
         }
         for (int k = 1; k < 8; k++) { //down-right
            if (board[i+k][j+k].getPiece() == king) return true;
            else if (board[i+k][j+k].getPiece() != -1) break;
         }
         break;
      case 5:
         if (board[i][j-1].getPiece() == king || board[i][j+1].getPiece() == king || board[i-1][j].getPiece() == king ||
         board[i+1][j].getPiece() == king || board[i-1][j-1].getPiece() == king || board[i-1][j+1].getPiece() == king ||
         board[i+1][j-1].getPiece() == king || board[i+1][j+1].getPiece() == king) return true;
         break;
      case 6:
         if (board[i][j-1].getPiece() == king || board[i][j+1].getPiece() == king || board[i-1][j].getPiece() == king ||
         board[i+1][j].getPiece() == king || board[i-1][j-1].getPiece() == king || board[i-1][j+1].getPiece() == king ||
         board[i+1][j-1].getPiece() == king || board[i+1][j+1].getPiece() == king) return true;
         break;
      default:
         break;
   }
   return false;
}