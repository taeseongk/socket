#include "chessBoard/chessBoard.h"

chessBoard::chessBoard() {
	chessPiece wPawn = chessPiece(0, 0);
	chessPiece wRook = chessPiece(0, 1);
	chessPiece wKnight = chessPiece(0, 2);
	chessPiece wBishop = chessPiece(0, 3);
	chessPiece wQueen = chessPiece(0, 4);
	chessPiece wKing = chessPiece(0, 5);
	chessPiece bPawn = chessPiece(1, 0);
	chessPiece bRook = chessPiece(1, 1);
	chessPiece bKnight = chessPiece(1, 2);
	chessPiece bBishop = chessPiece(1, 3);
	chessPiece bQueen = chessPiece(1, 4);
	chessPiece bKing = chessPiece(1, 5);

	chessPiece blackPiece[16] = {bRook, bKnight, bBishop, bQueen, bKing, bBishop, bKnight, bRook, 
									bPawn, bPawn, bPawn, bPawn, bPawn, bPawn, bPawn, bPawn};
	int bCounter1 = 0;
	int bCounter2 = 15;

	chessPiece whitePiece[16] = {wPawn, wPawn, wPawn, wPawn, wPawn, wPawn, wPawn, wPawn, 
									wRook, wKnight, wBishop, wQueen, wKing, wBishop, wKnight, wRook};
	int wCounter1 = 0;
	int wCounter2 = 15;

	whiteBoard = new chessPiece*[12];
	blackBoard = new chessPiece*[12];
	
	for (int i = 0; i < 12; i++) {
		whiteBoard[i] = new chessPiece[12];
		blackBoard[i] = new chessPiece[12];
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (j > 1 && j < 10) {
				if (i == 2 || i == 3) {
					whiteBoard[i][j] = blackPiece[bCounter1];
					whiteBoard[i][j].setPosition(i, j);
					bCounter1++;
					blackBoard[i][j] = whitePiece[wCounter2];
					blackBoard[i][j].setPosition(i, j);
					wCounter2--;
				}
				else if (i == 8 || i == 9) {
					whitePieces.push_back(whitePiece[wCounter1]);
					whitePieces.back().setPosition(i, j);
					whiteBoard[i][j] = whitePieces.back();
					wCounter1++;
					blackPieces.push_back(blackPiece[bCounter2]);
					blackPieces.back().setPosition(i, j);
					blackBoard[i][j] = blackPieces.back();
					bCounter2--;
				}
				else if (i > 3 && i < 8) {
					chessPiece emptyPiece = chessPiece();
					whiteBoard[i][j] = emptyPiece;
					blackBoard[i][j] = emptyPiece;
				}
				else {
					chessPiece wWall = chessPiece(0);
					chessPiece bWall = chessPiece(1);
					whiteBoard[i][j] = wWall;
					blackBoard[i][j] = bWall;
				}
			}
			else {
				chessPiece wWall = chessPiece(0);
				chessPiece bWall = chessPiece(1);
				whiteBoard[i][j] = wWall;
				blackBoard[i][j] = bWall;
			}
		}
	}
}

chessBoard::~chessBoard() {
	delete whiteBoard;
	delete blackBoard;
}