// A simple chess game

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "chessBoard/chessBoard.h"
#include "server-client/server.h"
#include "server-client/client.h"

int main() {
	system("clear");
	std::string answer;
	do {
		std::cout << "Create Game or Join Game? (C or J): ";
		std::cin >> answer;
		if (answer == "C" || answer == "J") {
			break;
		}
	} while (true);

	if (answer == "C") {
		server server;
		server.startServer();
	}
	else {
		client client;
		client.startClient();
	}

	chessBoard board;
	std::chrono::seconds dura(1);
	while (true) {
		board.printBoard(0);
		if (board.makeMove(0))
			break;
		board.printBoard(0);
		std::cout << std::endl;
		std::this_thread::sleep_for(dura);
		board.printBoard(1);
		if (board.makeMove(1))
			break;
		board.printBoard(1);
		std::cout << std::endl;
		std::this_thread::sleep_for(dura);
	}
	return 0;
}
