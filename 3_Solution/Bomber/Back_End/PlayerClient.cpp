#include "PlayerClient.h"
#include "Utilities.h"
#include "ServerMessageType.h"
#include "ServerMessages.h"
#include "NetworkHandler.h"
#include <SFML\Network.hpp>
#include <assert.h>

MovementPoint::MovementPoint(sf::Vector2f position, eDirection moveDirection):position(position), moveDirection(moveDirection)
{

}

PlayerClient::PlayerClient(int ID, sf::Vector2f startingPosition, ePlayerType playerType)
	: Player(ID, startingPosition, ePlayerControllerType::eHuman), m_playerType(playerType), m_sprite(startingPosition, eAnimationName::ePlayerIdleDown)
{}

void PlayerClient::update(float deltaTime)
{
	Player::update(deltaTime);

	if (!isMoving())
	{
		m_sprite.setPosition(m_position);
		m_sprite.update(deltaTime);
	}
}

void PlayerClient::render(sf::RenderWindow& window) const
{
	for (const auto& i : m_path)
	{
		window.draw(i);
	}

	m_sprite.render(window);
}

void PlayerClient::setNewPosition(sf::Vector2f newPosition, const std::vector<std::vector<eCollidableTile>>& collisionLayer, sf::Vector2i tileSize,
	std::vector<MovementPoint>& localPlayerPreviousPositions)
{
	if (m_playerType == ePlayerType::eLocal)
	{
		if (!isMoving() && !Utilities::isPositionCollidable(collisionLayer, newPosition, tileSize))
		{
			m_newPosition = newPosition;
			m_previousPosition = m_position;

			if (newPosition.x > m_position.x)
			{
				m_facingDirection = eDirection::eRight;
				m_sprite.setNewAnimation(eAnimationName::ePlayerMoveRight);
			}
			else if (newPosition.x < m_position.x)
			{
				m_facingDirection = eDirection::eLeft;
				m_sprite.setNewAnimation(eAnimationName::ePlayerMoveLeft);
			}
			else if (newPosition.y < m_position.y)
			{
				m_facingDirection = eDirection::eUp;
				m_sprite.setNewAnimation(eAnimationName::ePlayerMoveUp);
			}
			else if (newPosition.y > m_position.y)
			{
				m_facingDirection = eDirection::eDown;
				m_sprite.setNewAnimation(eAnimationName::ePlayerMoveDown);
			}

			sf::Packet packetToSend;
			packetToSend << eServerMessageType::ePlayerMoveToPosition << ServerMessagePlayerMove(m_newPosition, m_movementSpeed);

		}
	}
}