#include "server.h"

void server::startServer() {
    int obj_server, sock, reader;
    struct sockaddr_in address;
    int opted = 1;
    int address_length = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Server: Received the message !";

    if ((obj_server = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Opening of Socket Failed !");
        exit(EXIT_FAILURE);
    }
    
    if (setsockopt(obj_server, SOL_SOCKET, SO_REUSEADDR,
                     &opted, sizeof(opted))) {
        perror("Can't set the socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(obj_server, (struct sockaddr *)&address,
             sizeof(address)) < 0) {
        perror("Binding of socket failed !");
        exit(EXIT_FAILURE);
    }

    if (listen(obj_server, 3) < 0) {
        perror("Can't listen from the server !");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for player to join ...\n");
    if ((sock = accept(obj_server, (struct sockaddr *)&address, (socklen_t *)&address_length)) < 0) {
        perror("Accept");
        exit(EXIT_FAILURE);
    }
    printf("Player joined!\n");

    while (true) {      
        reader = read(sock, buffer, 1024);
        printf("%s\n", buffer);
        memset(buffer, 0, 1024);
        send(sock, message, strlen(message), 0);
    }
}

int main() {
    server server;
    server.startServer();
}