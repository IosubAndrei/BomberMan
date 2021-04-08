#pragma once
#include "AnimatedSprite.h"
#include "GameObject.h"
#include <vector>

constexpr float EXPLOSION_LIFETIME_DURATION = 0.5f;

class GameObjectClient : public GameObject
{
private:
	AnimatedSprite m_sprite;

public:
	GameObjectClient(sf::Vector2f startingPosition, float expirationTime, eAnimationName startingAnimation,
		eGameObjectType type, eTimer timerActivate = eTimer::eFalse);

	void render(sf::RenderWindow& window) const;
	void update(float deltaTime);
};

