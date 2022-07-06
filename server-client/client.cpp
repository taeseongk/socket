#include "client.h"

int client::startClient() {
    int obj_socket = 0, reader;
    struct sockaddr_in serv_addr;
    char message[1024];
    char buffer[1024] = {0};

    if ((obj_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error !");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address ! This IP Address is not supported !\n");
        return -1;
    }

    if (connect(obj_socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed : Can't establish a connection over this socket !");
        return -1;
    }
    
    while (true) {
        memset(message, 0, 1024);
        printf("\nType in a message: ");
        scanf("%s", message);
        send(obj_socket, message, strlen(message), 0);
        memset(buffer, 0, 1024); 
        reader = read(obj_socket, buffer, 1024);
        printf ("%s\n", buffer);
    }
    return 0;
}

int main() {
    client client;
    client.startClient();
}
