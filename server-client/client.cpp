#include "client.h"
#include <chrono>
#include <thread>
#include "../chessBoard/chessBoard.h"

int client::startClient() {
    int obj_socket = 0, reader;
    struct sockaddr_in serv_addr;
    char message[1024];
    char buffer[1024] = {0};

    if ((obj_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error !");
        return 0;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address ! This IP Address is not supported !\n");
        return 0;
    }

    if (connect(obj_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("No servers to join!");
        return 0;
    }
    printf("Joined a server!\n");
    printf("Starting game!\n ");
    std::chrono::seconds dura(1);
    std::this_thread::sleep_for(dura);
    
    chessBoard board;
    while (true) {
        board.printBoard(1);
HERE:
        memset(buffer, 0, 1024);
        reader = read(obj_socket, buffer, 1024);
        if (!strcmp(buffer, "Over")){
            board.updateBoard(1, "Resign");
            return 0;
        }
        else if (!strcmp(buffer, "Draw")) {
            std::string answer = board.updateBoard(1, "Draw");
            if (answer == "Y") {
                send(obj_socket, "Over", 4, 0);
                return 0;
            }
            else if (answer == "N") {
                send(obj_socket, "Continue", 8, 0);
                goto HERE;
            }
        }
        else if (!strcmp(buffer, "CastleQ")) {
            board.updateBoard(1, "CastleQ");
        }
        else if (!strcmp(buffer, "CastleK")) {
            board.updateBoard(1, "CastleK");
        }
        else {
            std::string move(buffer);
            board.updateBoard(1, move);
        }
        board.printBoard(1);
    }
    return 0;
}
