#include "Room.h"
#include <iostream>

void Room::loopConnectionDetection()
{
	int connections = 0;
	int maxConnections = std::size(this->connections)
	while(connections < maxConnections)
	{
		// Create a socket
		SOCKET serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
		if (serverSocket == INVALID_SOCKET) {
			std::cout << "Socket failed to initalize" << std::endl;
			return;
		}
		std::cout << "Socket initialized" << std::endl;
		// Setting the address structure socket to data binding
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(80);


		
	}
}

void Room::establishFullDuplexConnection()
{
}

void Room::loopMulticast(std::string message)
{
}
