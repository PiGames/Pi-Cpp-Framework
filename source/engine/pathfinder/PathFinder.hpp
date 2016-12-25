#pragma once

#include <queue>
#include <SFML/System/Vector2.hpp>
#include "Cell.h"
#include <stack>

class PathFinder final
{
	static std::pair<std::vector<Cell>*, std::vector<int>> m_cells;

	static sf::Vector2f cellDimensions; 

	static sf::Vector2i mapSize; //i/j

	static void clearTargets(std::queue<sf::Vector2f>* targets);

	static sf::Vector2i convertCordsToPos(sf::Vector2f data);

	static bool isInMap(sf::Vector2i position); //i/j

	static void wayBackProcess(sf::Vector2i zp, sf::Vector2i w, std::queue<sf::Vector2f> *targets);

	static void reverse(std::queue<sf::Vector2f> *targets);

public:
	static void Init(std::vector<Cell> *cells,sf::Vector2f cellDim,sf::Vector2i worldSize);

	static void FillTargetsQueue(sf::Vector2f from, sf::Vector2f to,std::queue<sf::Vector2f> *targets);
	
};
