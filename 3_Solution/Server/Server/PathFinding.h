#pragma once
#include "NonCopyable.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <queue>

class GraphNode
{
private:
	sf::Vector2i cameFrom;
	bool visited;

public:
	GraphNode();
	GraphNode(sf::Vector2i cameFrom);

	sf::Vector2i getCameFrom() const;
	bool isVisited() const;
};

class Graph
{
private:
	std::vector<std::vector<GraphNode>> m_graph;

public:
	Graph();

	bool isEmpty() const;
	sf::Vector2i getPreviousPosition(sf::Vector2i position, sf::Vector2i levelSize) const;
	bool isPositionVisited(sf::Vector2i position, sf::Vector2i levelSize) const;

	void resetGraph(sf::Vector2i levelSize);
	void addToGraph(sf::Vector2i position, sf::Vector2i lastPosition, sf::Vector2i levelSize);
};

enum class eDirection;
class BombServer;
class Server;
class PathFinding : private NonCopyable
{
private:
	Graph m_graph;
	std::queue<sf::Vector2i> m_frontier;
	std::vector<sf::Vector2i> m_adjacentPositions;

	PathFinding() {}
	void reset(sf::Vector2i levelSize);

public:
	static PathFinding& getInstance()
	{
		static PathFinding instance;
		return instance;
	}
	
	void createGraph(sf::Vector2i levelSize);
};

