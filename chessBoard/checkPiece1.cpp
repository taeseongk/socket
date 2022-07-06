#include "chessBoard.h"

bool chessBoard::checkPiece1(chessPiece piece) { 
    int i = piece.getPosition().first;
    int j = piece.getPosition().second;
    int color = piece.getColor();
    int k;
    chessPiece** board = !color ? whiteBoard : blackBoard;
   
    switch (piece.getPiece()) {
        case 0: 
            if (!piece.getPawn()) {
                if (board[i-1][j].getPiece() == -1 && checkQueue(color, i, j, i-1, j, piece)) return true; 
                else if(board[i-1][j].getPiece() == -1 && board[i-2][j].getPiece() == -1 && 
                checkQueue(color, i, j, i-2, j, piece)) return true; 
                else if (board[i-1][j-1].getColor() == !color && checkQueue(color, i, j, i-1, j-1, piece)) return true;
                else if (board[i-1][j+1].getColor() == !color && checkQueue(color, i, j, i-1, j+1, piece)) return true;
            }
            else if (piece.getPawn()) {
                if (board[i-1][j].getPiece() == -1 && checkQueue(color, i, j, i-1, j, piece)) return true; 
                else if (board[i-1][j-1].getColor() == !color && checkQueue(color, i, j, i-1, j-1, piece)) return true;
                else if (board[i-1][j+1].getColor() == !color && checkQueue(color, i, j, i-1, j+1, piece)) return true;
            }
            break;
        case 1:
            k = i - 1;
            while (board[k][j].getPiece() == -1 || board[k][j].getColor() == !color) { 
                if (checkQueue(color, i, j, k, j, piece)) return true;
                if (board[k][j].getColor() == !color) break;
                k--;
            }
            k = i + 1;
            while (board[k][j].getPiece() == -1 || board[k][j].getColor() == !color) { 
                if (checkQueue(color, i, j, k, j, piece)) return true;
                if (board[k][j].getColor() == !color) break;
                k++;
            }
            k = j - 1;
            while (board[i][k].getPiece() == -1 || board[i][k].getColor() == !color) { 
                if (checkQueue(color, i, j, i, k, piece)) return true;
                if (board[i][k].getColor() == !color) break;
                k--;
            }
            k = j + 1;
            while (board[i][k].getPiece() == -1 || board[i][k].getColor() == !color) { 
                if (checkQueue(color, i, j, i, k, piece)) return true;
                if (board[i][k].getColor() == !color) break;
                k++;
            }        
            break;
        case 2:
            if ((board[i-2][j-1].getPiece() == -1 || board[i-2][j-1].getColor() == !color) && checkQueue(color, i, j, i-2, j-1, piece)) return true;
            else if ((board[i-2][j+1].getPiece() == -1 || board[i-2][j+1].getColor() == !color) && checkQueue(color, i, j, i-2, j+1, piece)) return true;
            else if ((board[i-1][j+2].getPiece() == -1 || board[i-1][j+2].getColor() == !color) && checkQueue(color, i, j, i-1, j+2, piece)) return true;
            else if ((board[i+1][j+2].getPiece() == -1 || board[i+1][j+2].getColor() == !color) && checkQueue(color, i, j, i+1, j+2, piece)) return true;
            else if ((board[i+2][j+1].getPiece() == -1 || board[i+2][j+1].getColor() == !color) && checkQueue(color, i, j, i+2, j+1, piece)) return true;
            else if ((board[i+2][j-1].getPiece() == -1 || board[i+2][j-1].getColor() == !color) && checkQueue(color, i, j, i+2, j-1, piece)) return true;
            else if ((board[i+1][j-2].getPiece() == -1 || board[i+1][j-2].getColor() == !color) && checkQueue(color, i, j, i+1, j-2, piece)) return true;
            else if ((board[i-1][j-2].getPiece() == -1 || board[i-1][j-2].getColor() == !color) && checkQueue(color, i, j, i-1, j-2, piece)) return true;
            break;
        case 3:
            k = 1;
            while (board[i-k][j-k].getPiece() == -1 || board[i-k][j-k].getColor() == !color) { 
                if (checkQueue(color, i, j, i-k, j-k, piece)) return true;
                if (board[i-k][j-k].getColor() == !color) break;
                k++;
            }
            k = 1;
            while (board[i+k][j-k].getPiece() == -1 || board[i+k][j-k].getColor() == !color) { 
                if (checkQueue(color, i, j, i+k, j-k, piece)) return true;
                if (board[i+k][j-k].getColor() == !color) break;
                k++;
            }
            k = 1;
            while (board[i-k][j+k].getPiece() == -1 || board[i-k][j+k].getColor() == !color) {
                if (checkQueue(color, i, j, i-k, j+k, piece)) return true;
                if (board[i-k][j+k].getColor() == !color) break;
                k++;
            }
            k = 1;
            while (board[i+k][j+k].getPiece() == -1 || board[i+k][j+k].getColor() == !color) {
                if (checkQueue(color, i, j, i+k, j+k, piece)) return true;
                if (board[i+k][j+k].getColor() == !color) break;
                k++;
            }
            break;
        case 4:
            k = i - 1;
            while (board[k][j].getPiece() == -1 || board[k][j].getColor() == !color) {
                if (checkQueue(color, i, j, k, j, piece)) return true;
                if (board[k][j].getColor() == !color) break;
                k--;
            }
            k = i + 1;
            while (board[k][j].getPiece() == -1 || board[k][j].getColor() == !color) {
                if (checkQueue(color, i, j, k, j, piece)) return true;
                if (board[k][j].getColor() == !color) break;
                k++;
            }
            k = j - 1;
            while (board[i][k].getPiece() == -1 || board[i][k].getColor() == !color) { 
                if (checkQueue(color, i, j, i, k, piece)) return true;
                if (board[i][k].getColor() == !color) break;
                k--;
            }
            k = j + 1;
            while (board[i][k].getPiece() == -1 || board[i][k].getColor() == !color) { 
                if (checkQueue(color, i, j, i, k, piece)) return true;
                if (board[i][k].getColor() == !color) break;
                k++;
            }        
            k = 1;
            while (board[i-k][j-k].getPiece() == -1 || board[i-k][j-k].getColor() == !color) { 
                if (checkQueue(color, i, j, i-k, j-k, piece)) return true;
                if (board[i-k][j-k].getColor() == !color) break;
                k++;
            }
            k = 1;
            while (board[i+k][j-k].getPiece() == -1 || board[i+k][j-k].getColor() == !color) { 
                if (checkQueue(color, i, j, i+k, j-k, piece)) return true;
                if (board[i+k][j-k].getColor() == !color) break;
                k++;
            }
            k = 1;
            while (board[i-k][j+k].getPiece() == -1 || board[i-k][j+k].getColor() == !color) {
                if (checkQueue(color, i, j, i-k, j+k, piece)) return true;
                if (board[i-k][j+k].getColor() == !color) break;
                k++;
            }
            k = 1;
            while (board[i+k][j+k].getPiece() == -1 || board[i+k][j+k].getColor() == !color) {
                if (checkQueue(color, i, j, i+k, j+k, piece)) return true;
                if (board[i+k][j+k].getColor() == !color) break;
                k++;
            }
            break;
        case 5:
            if ((board[i-1][j].getPiece() == -1 || board[i-1][j].getColor() == !color) && checkQueue(color, i, j, i-1, j, piece)) return true;
            else if ((board[i+1][j].getPiece() == -1 || board[i+1][j].getColor() == !color) && checkQueue(color, i, j, i+1, j, piece)) return true;
            else if ((board[i][j-1].getPiece() == -1 || board[i][j-1].getColor() == !color) && checkQueue(color, i, j, i, j-1, piece)) return true;
            else if ((board[i][j+1].getPiece() == -1 || board[i][j+1].getColor() == !color) && checkQueue(color, i, j, i, j+1, piece)) return true;
            else if ((board[i-1][j-1].getPiece() == -1 || board[i-1][j-1].getColor() == !color) && checkQueue(color, i, j, i-1, j-1, piece)) return true;
            else if ((board[i+1][j-1].getPiece() == -1 || board[i+1][j-1].getColor() == !color) && checkQueue(color, i, j, i+1, j-1, piece)) return true;
            else if ((board[i-1][j+1].getPiece() == -1 || board[i-1][j+1].getColor() == !color) && checkQueue(color, i, j, i-1, j+1, piece)) return true;
            else if ((board[i+1][j+1].getPiece() == -1 || board[i+1][j+1].getColor() == !color) && checkQueue(color, i, j, i+1, j+1, piece)) return true;
            break;
        case 6:
            if ((board[i-1][j].getPiece() == -1 || board[i-1][j].getColor() == !color) && checkQueue(color, i, j, i-1, j, piece)) return true;
            else if ((board[i+1][j].getPiece() == -1 || board[i+1][j].getColor() == !color) && checkQueue(color, i, j, i+1, j, piece)) return true;
            else if ((board[i][j-1].getPiece() == -1 || board[i][j-1].getColor() == !color) && checkQueue(color, i, j, i, j-1, piece)) return true;
            else if ((board[i][j+1].getPiece() == -1 || board[i][j+1].getColor() == !color) && checkQueue(color, i, j, i, j+1, piece)) return true;
            else if ((board[i-1][j-1].getPiece() == -1 || board[i-1][j-1].getColor() == !color) && checkQueue(color, i, j, i-1, j-1, piece)) return true;
            else if ((board[i+1][j-1].getPiece() == -1 || board[i+1][j-1].getColor() == !color) && checkQueue(color, i, j, i+1, j-1, piece)) return true;
            else if ((board[i-1][j+1].getPiece() == -1 || board[i-1][j+1].getColor() == !color) && checkQueue(color, i, j, i-1, j+1, piece)) return true;
            else if ((board[i+1][j+1].getPiece() == -1 || board[i+1][j+1].getColor() == !color) && checkQueue(color, i, j, i+1, j+1, piece)) return true;
            break;
        default:
            break;
    }
   return false;
}
