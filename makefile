CXX=clang++

VPATH=./chessBoard/:./server-client

chessGame: chessGame.o chessPiece.o chessBoard.o checkMove.o checkPiece1.o checkPiece2.o checkSurr.o isCheck.o isCheckmate.o isStalemate.o checkQueue.o checkArray.o canCastleQueen.o canCastleKing.o castleQueen.o castleKing.o promotion.o makeMove.o movePiece.o printBoard.o updateBoard.o client.o server.o
	${CXX} chessGame.o chessPiece.o chessBoard.o checkMove.o checkPiece1.o checkPiece2.o checkSurr.o isCheck.o isCheckmate.o isStalemate.o checkQueue.o checkArray.o canCastleQueen.o canCastleKing.o castleQueen.o castleKing.o promotion.o makeMove.o movePiece.o printBoard.o updateBoard.o client.o server.o -o chessGame

server: server.o
	${CXX} server.o -o server

client: client.o
	${CXX} client.o -o client

clean:
	/bin/rm -f *.o chessGame server client
