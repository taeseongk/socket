#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string>
#include <iostream> 

#define PORT 8080

class server {
    public:
        void startServer();
};

#endif