#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <Windows.h>

#pragma comment(lib, "ws2_32.lib")

int __cdecl main()
{
	try
	{
		WSAData wsad;

		int wsaRes = WSAStartup(MAKEWORD(2, 2), &wsad);
		if (wsaRes != 0) {
			std::cout << "Error at dll startup." << std::endl;
		}

		//Initalizing the socket
		SOCKET serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
		if (serverSocket == INVALID_SOCKET) {
			std::cout << "Socket failed to initalize" << std::endl;
			return 0;
		}

		std::cout << "Socket initialized" << std::endl;

		//Setting the address structure socket to data binding
		sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_port = htons(80);
		int result = inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

		std::cout << "Socket address set to: " << addr.sin_addr.S_un.S_addr << std::endl;

		//Binding the data to the socket
		if (int bindResult = bind(serverSocket, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
			std::cout << "Socket failed at binding. Error code: " << bindResult << ", " << WSAGetLastError() << std::endl;
			closesocket(serverSocket);
			WSACleanup();
		}

		//Help variables for the listening process
		int maxNumOfConnections = 1;
		bool over = false;
		std::string str = std::string();
		char buffer[1024];

		//LISTEN 
		do {
			memset(buffer, '\0', 1024);

			int numOfBytes = recv(serverSocket, buffer, 1024, 0);

			send(serverSocket, "Socket connected", sizeof("Socket connected"), 0);
			char recieveBuffer[1024];

			str = std::move(recieveBuffer);
			std::cout << str << std::endl;
			str.clear();
		} while (maxNumOfConnections < 1 && !over);

		WSACleanup();

		return 0;

	}
	catch (std::exception e)
	{
		std::cout << "Compile time error occured: " << e.what() << std::endl;
		return 1;
	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
