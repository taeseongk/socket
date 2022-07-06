#include "chessBoard.h"

bool chessBoard::isCheckmate(int color) {
   std::vector<chessPiece> pieces = !color ? whitePieces : blackPieces;
   for (std::vector<chessPiece>::iterator i = pieces.begin(); i != pieces.end(); ++i) {
      if (checkPiece1(*i) && checkPiece2(*i)) {
         return false;
      }
   }
   return true;
}