#pragma once
#include "NonCopyable.h"
#include <SFML/Network.hpp>
#include"ServerMessageType.h"
#include <vector>
#include <queue>
#include <mutex>
#include<memory>

class NetworkHandler :
    private NonCopyable
{
private:
    NetworkHandler();
    std::queue<sf::Packet> m_receivedPacket;
    std::unique_ptr<sf::TcpSocket> m_tcpSocket;

    void listen();

public:
    static NetworkHandler& getInstance()
    {
        static NetworkHandler instance;
        return instance;
    }

    bool isReceivedPacket() const;
    sf::Packet getLatestPacket();

    bool connectToServer();
    void disconnectFromServer();
    void sendMessageToServer(sf::Packet& packetToSend);
};

