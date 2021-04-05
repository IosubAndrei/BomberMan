#pragma once
#include "Timer.h"
#include <SFML/Graphics.hpp>

constexpr float BOMB_LIFETIME = 2.0f;

enum class eGameObjectType
{
	eBomb=0,
	eExplosion
};

class GameObject
{
protected:
	eGameObjectType m_type;
	float m_movementSpeed;
	sf::Vector2f m_previousPosition;
	sf::Vector2f m_position;
	sf::Vector2f m_newPosition;
	Timer m_lifeTimer;

public:
	GameObject(sf::Vector2f startingPosition, float expirationTime, eGameObjectType type, eTimer timerActive = eTimer::eTrue);

	bool isMoving() const;
	eGameObjectType getType() const;
	const Timer& getTimer() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getNewPosition() const;

	void update(float frameTime);
	void setNewPosition(sf::Vector2f newPosition);
};

