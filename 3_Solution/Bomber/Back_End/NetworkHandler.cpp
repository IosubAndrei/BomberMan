#include "NetworkHandler.h"
#include <assert.h>
#include <iostream>

NetworkHandler::NetworkHandler() :m_receivedPacket(), m_tcpSocket()
{

}

bool NetworkHandler::isReceivedPacket() const
{
	return !m_receivedPacket.empty();
}

sf::Packet NetworkHandler::getLatestPacket()
{
	sf::Packet packetReceived;
	assert(!m_receivedPacket.empty());
	if (!m_receivedPacket.empty())
	{
		packetReceived = m_receivedPacket.front();
		m_receivedPacket.pop();
	}

	return packetReceived;
}

bool NetworkHandler::connectToServer()
{

}

void NetworkHandler::disconnectFromServer()
{


}


void NetworkHandler::sendMessageToServer(sf::Packet& packetToSend)
{


}

void NetworkHandler::listen()
{

}