#pragma once
#include "Player.h"
#include "GameObject.h"
#include <SFML/Network.hpp>
#include <memory>
#include <utility>
#include <vector>

class Server;
class PlayerServer :
    public Player
{
public:
    PlayerServer(int ID, sf::Vector2f startingPosition, ePlayerControllerType controllerType);

    void setNewPosition(sf::Vector2f newPosition, Server& server);
};

class PlayerServerHuman : public PlayerServer
{
private:
    std::unique_ptr<sf::TcpSocket>& getTcpScket();

public:
    PlayerServerHuman(std::unique_ptr<sf::TcpSocket> tcpSocket, int ID, sf::Vector2f startingPosition, sf::SocketSelector& socketSelector);
    ~PlayerServerHuman() override;

    std::unique_ptr<sf::TcpSocket>& getTCPSocket();
};

