#include "chessBoard.h"

bool chessBoard::checkMove(chessPiece &piece, int x, int y) const {
   int i = piece.getPosition().first;
   int j = piece.getPosition().second;
   int color = piece.getColor();
   chessPiece** board = !color ? whiteBoard : blackBoard;
   switch (piece.getPiece()) {
      case 0: 
         if (!piece.getPawn()) {
            if (i-1 == x && j == y && board[x][y].getPiece() == -1) { //if move is forward once and no piece in front
               piece.setPawn();
               return true;
            }  
            else if(i-2 == x && j == y && board[x+1][y].getPiece() == -1 && board[x][y].getPiece() == -1) { //if move is forward twice
               piece.setPawn();
               return true;
            }
            else if (((i-1 == x && j-1 == y) || (i-1 == x && j+1 == y)) && board[x][y].getColor() == !color) return true;
         }
         else if (piece.getPawn()) {
            if (i-1 == x && j == y && board[x][y].getPiece() == -1) return true; //if move is forward once
            else if (((i-1 == x && j-1 == y) || (i-1 == x && j+1 == y)) && board[x][y].getColor() == !color) return true;
         }
         break;
      case 1:
         if (i-x >= 1 && j == y) { //if move is forward
            for (int k = i-1; k > x; k--) {
               if (board[k][y].getPiece() != -1) return false;
            }
            goto HERE1;
         }
         else if (x-i >= 1 && j == y) { //if move is backward
            for (int k = i+1; k < x; k++) {
               if (board[k][y].getPiece() != -1) return false;
            }
            goto HERE1;
         }
         else if (i == x && j-y >= 1) { //if move is leftward
            for (int k = j-1; k > y; k--) {
               if (board[x][k].getPiece() != -1) return false;
            }
            goto HERE1;
         }
         else if (i == x && y-j >= 1) { //if move is rightward
            for (int k = j+1; k < y; k++) {
               if (board[x][k].getPiece() != -1) return false;
            }
            goto HERE1;
         }
         break;
      case 2:
         if ((i-2 == x && j-1 == y) || (i-2 == x && j+1 == y) || (i-1 == x && j+2 == y) || (i+1 == x && j+2 == y) || 
         (i+2 == x && j+1 == y) || (i+2 == x && j-1 == y) || (i+1 == x && j-2 == y) || (i-1 == x && j-2 == y)) goto HERE2;
         break;
      case 3:
         if (i-x >= 1 && j-y >= 1 && i-x == j-y) { //if move is up-left
            for (int k = 1; k < i-x; k++) {
               if (board[i-k][j-k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (x-i >= 1 && j-y >= 1 && x-i == j-y) { //if move is down-left
            for (int k = 1; k < x-i; k++) {
               if (board[i+k][j-k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (i-x >= 1 && y-j >= 1 && i-x == y-j) { //if move is up-right
            for (int k = 1; k < i-x; k++) {
               if (board[i-k][j+k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (x-i >= 1 && y-j >= 1 && x-i == y-j) { //if move is down-right
            for (int k = 1; k < x-i; k++) {
               if (board[i+k][j+k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         break;
      case 4:
         if (i-x >= 1 && j == y) { //if move is forward
            for (int k = i-1; k > x; k--) {
               if (board[k][y].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (x-i >= 1 && j == y) { //if move is backward
            for (int k = i+1; k < x; k++) {
               if (board[k][y].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (i == x && j-y >= 1) { //if move is leftward
            for (int k = j-1; k > y; k--) {
               if (board[x][k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (i == x && y-j >= 1) { //if move is rightward
            for (int k = j+1; k < y; k++) {
               if (board[x][k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (i-x >= 1 && j-y >= 1 && i-x == j-y) { //if move is up-left
            for (int k = 1; k < i-x; k++) {
               if (board[i-k][j-k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (x-i >= 1 && j-y >= 1 && x-i == j-y) { //if move is down-left
            for (int k = 1; k < x-i; k++) {
               if (board[i+k][j-k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (i-x >= 1 && y-j >= 1 && i-x == y-j) { //if move is up-right
            for (int k = 1; k < i-x; k++) {
               if (board[i-k][j+k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         else if (x-i >= 1 && y-j >= 1 && x-i == y-j) { //if move is down-right
            for (int k = 1; k < x-i; k++) {
               if (board[i+k][j+k].getPiece() != -1) return false;
            }
            goto HERE2;
         }
         break;
      case 5:
         if (i-x == 1 && j == y) { //if move is forward
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (x-i == 1 && j == y) { //if move is backward
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (i == x && j-y == 1) { //if move is leftward
            if (board[x][y].getPiece() != -1) return false; 
            goto HERE1;
         }
         else if (i == x && y-j == 1) { //if move is rightward
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (i-x == 1 && j-y == 1) { //if move is up-left
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (x-i == 1 && j-y == 1) { //if move is down-left
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (i-x == 1 && y-j == 1) { //if move is up-right
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (x-i == 1 && y-j == 1) { //if move is down-right
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         break;
      case 6:
         if (i-x == 1 && j == y) { //if move is forward
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (x-i == 1 && j == y) { //if move is backward
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (i == x && j-y == 1) { //if move is leftward
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (i == x && y-j == 1) { //if move is rightward
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (i-x == 1 && j-y == 1) { //if move is up-left
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (x-i == 1 && j-y == 1) { //if move is down-left
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (i-x == 1 && y-j == 1) { //if move is up-right
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         else if (x-i == 1 && y-j == 1) { //if move is down-right
            if (board[x][y].getPiece() != -1) return false;
            goto HERE1;
         }
         break;
      default:
         if (false) {
            HERE1:
            if (color != board[x][y].getColor()) {
               piece.setCastle(); //after move has been made
               return true;
            }
            HERE2:
            if (color != board[x][y].getColor()) return true;
         }
         break;
   }
   return false;
}