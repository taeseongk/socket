#include "chessBoard.h"

void chessBoard::promotion(int color, char p, int x, int y) {
    chessPiece** board1 = !color ? whiteBoard : blackBoard;
    chessPiece piece;

    switch (p) {
        case 'R':
            piece = chessPiece(color, 1);
            break;
        case 'N':
            piece = chessPiece(color, 2);
            break;  
        case 'B':
            piece = chessPiece(color, 3);
            break;
        case 'Q':
            piece = chessPiece(color, 4);
            break;
        default:
            break;
    }
    piece.setPosition(x, y);
    if (!color) {
        whiteBoard[x][y] = piece;
        whitePieces.push_back(piece);
        piece.setPosition(abs(x-11), abs(y-11));
        blackBoard[abs(x-11)][abs(y-11)] = piece;
        blackPieces.push_back(piece);
    }
    else {
        blackBoard[x][y] = piece;
        blackPieces.push_back(piece);
        piece.setPosition(abs(x-11), abs(y-11));
        whiteBoard[abs(x-11)][abs(y-11)] = piece;
        whitePieces.push_back(piece);
    }
}
