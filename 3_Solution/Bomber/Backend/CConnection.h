#pragma once

#include <Windows.h>
#include <string>
#include <cstdlib>

class CConnection
{
public:

	//state
	bool m_isOccupied;

	//Socket connection
	SOCKET m_socket;

	// Logged username
	std::string m_username;

};