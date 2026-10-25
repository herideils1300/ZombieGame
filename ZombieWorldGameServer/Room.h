#pragma once
#include <vector>
#include <WinSock2.h>
#include <string>

class Room
{
private:
	sockaddr_in* connections;
	int maxConnections;
public:
	Room(int maxConn) : connections(new sockaddr_in[maxConn]) {}
	void loopConnectionDetection();
	void establishFullDuplexConnection();
	void loopMulticast(std::string message);

};

