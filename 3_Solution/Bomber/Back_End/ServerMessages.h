#pragma once
#include "PlayerControllerType.h"
#include <SFML/Graphics.hpp>
#include "Direction.h"
#include <vector>
#include <string>

struct PlayerDetails
{
	int ID;
	sf::Vector2f spawnPosition;

	PlayerDetails(int ID, sf::Vector2f spawnPosition):ID(ID),spawnPosition(spawnPosition)
	{}
};

struct ServerMessageInitialGameData
{
	std::string levelName;
	std::vector<PlayerDetails> playerDetails;
};

struct ServerMessageInvalidMove
{
	sf::Vector2f invalidPosition;
	sf::Vector2f lastValidPosition;

	ServerMessageInvalidMove():invalidPosition(),lastValidPosition()
	{}

	ServerMessageInvalidMove(sf::Vector2f invalidPosition, sf::Vector2f lastValidPosition):
		invalidPosition(invalidPosition),lastValidPosition(lastValidPosition)
	{}
};

struct ServerMessagePlayerMove
{
	sf::Vector2f newPosition;
	float speed;

	ServerMessagePlayerMove():newPosition(),speed(0)
	{}

	ServerMessagePlayerMove(sf::Vector2f newPosition, float speed):newPosition(newPosition),
		speed(speed)
	{}
};