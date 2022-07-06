#include "chessBoard.h"

void chessBoard::printBoard(int color) const{
    system("clear");
    std::string array = !color ? "ABCDEFGH" : "HGFEDCBA";
    
    int counter = 0;
    if (!color) {
        std::cout << "Player 1:" << std::endl;
    }
    else {
        std::cout << "Player 2:" << std::endl;
    }
    std::cout << "  ";
    for (int i = 0; i <= 48; i++) {
        if ((i-3) % 6 == 0) {
            std::cout << array[counter];
            counter++;
        }
        else if (i == 48) {
            std::cout << std::endl;
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << "  ";
    for (int i = 0; i < 25; i++) {
        std::cout << "# ";
    }
    std::cout << std::endl;
    for (int i = 8; i > 0; i--) {
        int k = 10 - i;
        if (!color) {
            std::cout << i << " ";
        }
        else {
            std::cout << 9-i << " ";
        }
        for (int j = 0; j <= 48; j++) {
            if (j == 0) {
                std::cout << "#";
            }
            else if (j == 48) {
                std::cout << "#" << std::endl;
            }
            else if (j % 6 == 0) {
                std::cout << "|";
            }
            else if((j-3) % 6 == 0) {
                if (!color) {
                whiteBoard[k][((j-3)/6)+2].printPiece();
                } 
                else {
                blackBoard[k][((j-3)/6)+2].printPiece();
                }
            }
            else {
                std::cout << " ";
            }
        }
        if (i != 1) {
            std::cout << "  ";
            for (int j = 0; j <= 48; j++) {
                if (j == 0) {
                std::cout << "#";
                }
                else if (j == 48) {
                std::cout << "#" << std::endl;
                }
                else if (j % 6 != 0) {
                std::cout << "-"; 
                }
                else {
                std::cout << " ";
                }
            }
        }
    }
    std::cout << "  ";
    for (int i = 0; i < 25; i++) {
        std::cout << "# ";
    }
    std::cout << std::endl;
}