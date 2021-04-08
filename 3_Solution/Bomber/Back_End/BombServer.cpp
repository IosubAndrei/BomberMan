#include "BombServer.h"
#include "Utilities.h"

BombServer::BombServer(sf::Vector2f startingPosition, int explosionSize):
	GameObject(startingPosition, BOMB_LIFETIME, eGameObjectType::eBomb, eTimer::eTrue),
	m_explosionSize(explosionSize)
{}

int BombServer::getExplosionSize() const
{
	return m_explosionSize;
}