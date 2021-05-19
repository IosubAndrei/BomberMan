#include <iostream>
#include "Server.h"
#include <unordered_map>
#include <vector>
#include <array>
#include <assert.h>

int main()
{
	std::unique_ptr<Server> server = Server::create(sf::IpAddress::LocalHost, 55001);
	assert(server);
	if (!server)
	{
		std::cout << "Failed to start server\n";
		return -1;
	}

	server->run();

	return 0;
}