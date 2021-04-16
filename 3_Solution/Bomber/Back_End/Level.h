#pragma once
#include "NonCopyable.h"
#include "TileLayer.h"
#include "Box.h"
#include "GameObjectClient.h"
#include "PlayerClient.h"
#include "ColidableTile.h"
#include "Direction.h"
#include <vector>
#include <string>
#include <memory>
#include <SFML/Network.hpp>

struct ServerMessageInitialGameData;
class Level :
    private NonCopyable
{
private:
    Level(std::string&& levelName);

    std::string m_levelName;
    sf::Vector2i m_levelSize;
    std::vector<TileLayer> m_tileLayer;
    std::vector<sf::Vector2f> m_spawnPositions;
    std::vector<std::vector<eCollidableTile>> m_collisionLayer;
    std::vector<MovementPoint> m_localPlayersPreviousPositions;
    PlayerClient* m_localPlayer;
    std::vector<std::unique_ptr<PlayerClient>> m_players;
    std::vector<GameObjectClient> m_gameObjects;

    void onBombExplosion(sf::Vector2f position, int explosionSize);

    eCollidableTile getCollidableTile(sf::Vector2i position) const;
    void changeCollidableTile(sf::Vector2i position, eCollidableTile collidableTile);
    void addExplosionObject(sf::Vector2f position);
    PlayerClient* getPlayer(int ID);

public:
    static std::unique_ptr<Level> create(int localCLientID, ServerMessageInitialGameData& initialGameData);

    void render(sf::RenderWindow& window) const;
    void update(float deltaTime);

    void handleInput(const sf::Event& sfmlEvent);
    void onReceivedServerMessage(eServerMessageType receivedMessageType, sf::Packet& receivedMessage, sf::RenderWindow& window);

    //
};

