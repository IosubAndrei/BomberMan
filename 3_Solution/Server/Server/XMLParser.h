#pragma once
#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Base64.h"
#include "tinyxml.h"
#include "TileLayer.h"
#include "CollidableTile.h"

namespace XMLParser
{
	bool parseTextureDetails(sf::Vector2i& tileSize, sf::Vector2i& textureSize, int& column, const std::string& levelFileName, const std::string& textureFileName);

	bool loadLevelAsClient(const std::string& levelName, sf::Vector2i& levelSize,
		std::vector<TileLayer>& tileLayers, std::vector<std::vector<eCollidableTile>>& collisionLayer,
		std::vector<sf::Vector2f>& spawnPosition);

	bool loadLevelAsServer(const std::string& levelName, sf::Vector2i& levelSize,
		std::vector<std::vector<eCollidableTile>>& collisionLayer, std::vector<sf::Vector2f>& spawnPositions, sf::Vector2i& tileSIze);

	std::vector<TileLayer> parseTileLayers(const TiXmlElement& rootElement, const sf::Vector2i mapSize);
	sf::Vector2i parseMapSize(const TiXmlElement& rootElement);
	sf::Vector2i parseTileSize(const TiXmlElement& rootElement);
	std::vector<sf::Vector2f> parseObjectLayer(const TiXmlElement& rootElement, sf::Vector2i tileSize, const std::string& layerName);
	void parseCollisionLayer(const TiXmlElement& rootElement, sf::Vector2i tileSize, std::vector<std::vector<eCollidableTile>>& collisionLayer);
	void parseBoxLayer(const TiXmlElement& rootElement, sf::Vector2i tileSize, std::vector<std::vector<eCollidableTile>>& collisionLayer);
	std::vector<std::vector<int>> decodeTileLayer(const TiXmlElement& tileLayerElement, sf::Vector2i mapSize);
}