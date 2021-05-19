#pragma once
#include "GameObject.h"

class BombServer : public GameObject
{
private:
	int m_explosionSize;

public:
	BombServer(sf::Vector2f startingPosition, int explosionSize);

	int getExplosionSize() const;
};

