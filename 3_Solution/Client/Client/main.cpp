#include "NetworkHandler.h"
#include <iostream>
#include "Level.h"
#include "Resources.h"
#include "ServerMessages.h"
#include <algorithm>
#include <assert.h>
#include "Utilities.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(336, 336), "SFML_WINDOW", sf::Style::Default);

	if (!NetworkHandler::getInstance().connectToServer())
	{
		std::cerr << "Couldn't connect to server\n";
		return -1;
	}

	if (!Textures::getInstance().loadAllTextures())
	{
		std::cerr << "Couldn't load all textures\n";
		return -1;
	}

	std::unique_ptr<Level> level;
	sf::Clock gameClock;
	float deltaTime = 0.0f;
	int localClientID = INVALID_PLAYER_ID;
	while (window.isOpen())
	{
		//Handle Server Messages
		if (NetworkHandler::getInstance().isReceivedPackets())
		{
			sf::Packet receivedMessage = NetworkHandler::getInstance().getLatestPacket();

			eServerMessageType messageType;
			receivedMessage >> messageType;
			switch (messageType)
			{
			case eServerMessageType::eInitializeClientID:
				receivedMessage >> localClientID;
				break;
			case eServerMessageType::eInitialGameData:
			{
				ServerMessageInitialGameData initialGameData;
				receivedMessage >> initialGameData;
				assert(!level);
				if (!level)
				{
					level = Level::create(localClientID, initialGameData);
				}
			}
			break;
			default:
				assert(level);
				if (level)
				{
					level->onReceivedServerMessage(messageType, receivedMessage, window);
				}
				break;
			}
		}

		//Input Handling
		sf::Event sfmlEvent;
		while (window.pollEvent(sfmlEvent))
		{
			if (sfmlEvent.type == sf::Event::Closed)
			{
				sf::Packet packetToSend;
				packetToSend << eServerMessageType::eRequestDisconnection;
				NetworkHandler::getInstance().sendMessageToServer(packetToSend);
			}
			else if (sfmlEvent.type == sf::Event::KeyPressed)
			{
				level->handleInput(sfmlEvent);
			}
		}

		//Update
		if (level)
		{
			level->update(deltaTime);
		}

		//Render
		window.clear(sf::Color::Black);
		if (level)
		{
			level->render(window);
		}
		window.display();

		deltaTime = gameClock.restart().asSeconds();
	}

	NetworkHandler::getInstance().disconnectFromServer();
}