#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"

struct MovementPoint
{
	sf::Vector2f position;
	eDirection moveDirection;

	MovementPoint(sf::Vector2f position, eDirection moveDirection);
};

enum class eCollidableTile;
struct MovementPoint;
class PlayerClient: public Player
{
private:
	const ePlayerType m_playerType;
	AnimatedSprite m_sprite;

	std::vector<sf::RectangleShape> m_path;

public:
	PlayerClient(int ID, sf::Vector2f startingPosition, ePlayerType playerType);

	void update(float deltaTime) override;
	void render(sf::RenderWindow& window) const;

	void setNewPosition(sf::Vector2f newPosition, const std::vector<std::vector<eCollidableTile>>& collisionLayer, sf::Vector2i tileSize,
		std::vector<MovementPoint>& localPlayerPreviousPositions);
	void stopAtPosition(sf::Vector2f position);

	void setPathToRender(const std::vector<sf::Vector2f>& path);
};

