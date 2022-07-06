#include "chessBoard.h"

bool chessBoard::checkSurr(chessPiece piece) const {
   int i = piece.getPosition().first;
   int j = piece.getPosition().second;
   int color = piece.getColor();
   chessPiece** board = !color ? whiteBoard : blackBoard;
   switch (piece.getPiece()) {
      case 0:
         if (board[i-1][j].getPiece() == -1 || board[i-1][j-1].getColor() == !color ||
         board[i-1][j+1].getColor() == !color) return true;
         break;
      case 1:
         if (board[i-1][j].getColor() != color || board[i+1][j].getColor() != color || 
         board[i][j-1].getColor() != color || board[i][j+1].getColor() != color) return true;
         break;
      case 2:
         if (board[i-2][j-1].getColor() != color || board[i-2][j+1].getColor() != color || board[i-1][j+2].getColor() != color || 
         board[i+1][j+2].getColor() != color || board[i+2][j+1].getColor() != color || board[i+2][j-1].getColor() != color || 
         board[i+1][j-2].getColor() != color || board[i-1][j-2].getColor() != color) return true;
         break;
      case 3:
         if (board[i-1][j-1].getColor() != color || board[i-1][j+1].getColor() != color ||
         board[i+1][j-1].getColor() != color || board[i+1][j+1].getColor() != color) return true;
         break;
      case 4:
         if (board[i-1][j].getColor() != color || board[i+1][j].getColor() != color || board[i][j-1].getColor() != color || 
         board[i][j+1].getColor() != color || board[i-1][j-1].getColor() != color || board[i-1][j+1].getColor() != color || 
         board[i+1][j-1].getColor() != color || board[i+1][j+1].getColor() != color) return true;
         break;
      case 5:
         if (board[i-1][j].getColor() != color || board[i+1][j].getColor() != color || board[i][j-1].getColor() != color || 
         board[i][j+1].getColor() != color || board[i-1][j-1].getColor() != color || board[i-1][j+1].getColor() != color || 
         board[i+1][j-1].getColor() != color || board[i+1][j+1].getColor() != color) return true;
         break;
      case 6:
         if (board[i-1][j].getColor() != color || board[i+1][j].getColor() != color || board[i][j-1].getColor() != color || 
         board[i][j+1].getColor() != color || board[i-1][j-1].getColor() != color || board[i-1][j+1].getColor() != color || 
         board[i+1][j-1].getColor() != color || board[i+1][j+1].getColor() != color) return true;
         break;
      default:
         break;
   }
   return false;
}