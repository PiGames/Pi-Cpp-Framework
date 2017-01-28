#include "PathFinder.hpp"

namespace pi
{
	struct PathFinder::mapImitation;
	//std::vector<Cell>* PathFinder::mapImitation::cells;
	std::vector<int> PathFinder::mapImitation::weights;

	sf::Vector2i *PathFinder::unitMapSize;


	void PathFinder::clearTargets(std::queue<sf::Vector2f>* targets)
	{
		while (!targets->empty()) targets->pop();
	}


	bool PathFinder::isInMap(const sf::Vector2i& position)
	{
		return !(position.x<0 || position.x > unitMapSize->x - 1 || position.y<0 || position.y > unitMapSize->y - 1);
	}

	void PathFinder::transitionToNeighbor(sf::Vector2i *neighbor, sf::Vector2i *currentlyConsidered, std::queue<sf::Vector2f> *targets)
	{
		*currentlyConsidered = *neighbor;
		targets->push(sf::Vector2f(currentlyConsidered->x*constants::cell::CELL_DIMENSIONS.x, currentlyConsidered->y*constants::cell::CELL_DIMENSIONS.y));
	}

	void PathFinder::categorizeCells(sf::Vector2i * neighbor, sf::Vector2i * currentlyConsidered, std::queue<sf::Vector2i> *Q, short direction)
	{
		std::pair<sf::Vector2i, sf::Vector2i> alternate;

		if (isInMap(*neighbor) && !MapManager::isCollidableUnit(*neighbor) && mapImitation::weights[unitMapSize->x*neighbor->y + neighbor->x] == PathFinder::NOT_VISITED)
		{
			switch (direction)
			{
				case PathFinder::Direction::NORTH:
				case PathFinder::Direction::EAST:
				case PathFinder::Direction::SOUTH:
				case PathFinder::Direction::WEST: increaseWeight(neighbor, currentlyConsidered, Q); break;

				case PathFinder::Direction::NORTH_EAST:
				{
					alternate.first = constants::mapManager::unitDirections.at(constants::mapManager::nameDirections::EAST); 
					alternate.second = constants::mapManager::unitDirections.at(constants::mapManager::nameDirections::NORTH);
					break;
				}
	
				case PathFinder::Direction::SOUTH_EAST:
				{
					alternate.first = constants::mapManager::unitDirections.at(constants::mapManager::nameDirections::EAST);
					alternate.second = constants::mapManager::unitDirections.at(constants::mapManager::nameDirections::SOUTH);
					break;
				}

				case PathFinder::Direction::SOUTH_WEST:
				{
					alternate.first = constants::mapManager::unitDirections.at(constants::mapManager::nameDirections::WEST);
					alternate.second = constants::mapManager::unitDirections.at(constants::mapManager::nameDirections::SOUTH);
					break;
				}

				case PathFinder::Direction::NORTH_WEST:
				{
					alternate.first = constants::mapManager::unitDirections.at(constants::mapManager::nameDirections::WEST);
					alternate.second = constants::mapManager::unitDirections.at(constants::mapManager::nameDirections::NORTH);
					break;
				}
			}

			if (!isCellBlocking(currentlyConsidered, &alternate.first) && !isCellBlocking(currentlyConsidered, &alternate.second))
				increaseWeight(neighbor, currentlyConsidered, Q);

		}
	}

	void PathFinder::reverse(std::queue<sf::Vector2f>* targets)
	{
		std::vector<sf::Vector2f> list;

		while (!targets->empty())
		{
			list.push_back(targets->front());
			targets->pop();
		}

		std::reverse(list.begin(), list.end());

		for (auto &var : list)
		{
			targets->push(sf::Vector2f(var.x + constants::cell::CELL_DIMENSIONS.x / 2, var.y + constants::cell::CELL_DIMENSIONS.y / 2));
		}

	}

	void PathFinder::initialTreatments(std::queue<sf::Vector2i>* Q, sf::Vector2i * fromPos)
	{
		setWeightsVectorAsNotVisited();
		enterFirstElementToQueue(Q, fromPos);
	}

	void PathFinder::setWeightsVectorAsNotVisited()
	{
		for (size_t i = 0; i < unitMapSize->x*unitMapSize->y; ++i)
			mapImitation::weights.emplace_back(PathFinder::CellState::NOT_VISITED);
	}

	void PathFinder::enterFirstElementToQueue(std::queue<sf::Vector2i> *Q, sf::Vector2i *fromPos)
	{
		Q->push(sf::Vector2i(*fromPos));
		mapImitation::weights[fromPos->y*unitMapSize->x + fromPos->x] = PathFinder::CellState::START_POSITION;
	}

	void PathFinder::tourTheMap(std::queue<sf::Vector2i> *Q, sf::Vector2i *toPos)
	{
		sf::Vector2i currentlyConsidered;

		const std::vector<std::pair<int, int>> neighbours = { std::pair<int,int>(0,-1),std::pair<int,int>(1,-1), std::pair<int,int>(1,0),std::pair<int,int>(1,1),std::pair<int,int>(0,1),std::pair<int,int>(-1, 1),std::pair<int,int>(-1, 0),std::pair<int,int>(-1, -1) };
		sf::Vector2i neighbor;

		while (!Q->empty())
		{
			currentlyConsidered = Q->front();
			Q->pop();
			for (size_t direction = 0; direction < neighbours.size(); direction++)
			{
				neighbor = sf::Vector2i(currentlyConsidered.x + neighbours[direction].first, currentlyConsidered.y + neighbours[direction].second);
				categorizeCells(&neighbor, &currentlyConsidered, Q, direction);
				if (neighbor == *toPos) break;
			}
			if (neighbor == *toPos) break;
		}
	}

	bool PathFinder::foundLowerWeight(sf::Vector2i *currentlyConsidered, sf::Vector2i *neighbor, std::queue<sf::Vector2f>* targets)
	{
		if (isInMap(*neighbor) && mapImitation::weights[neighbor->y*unitMapSize->x + neighbor->x] == mapImitation::weights[currentlyConsidered->y*unitMapSize->x + currentlyConsidered->x] - 1) //TOP LEFT
		{
			transitionToNeighbor(neighbor, currentlyConsidered, targets);
			return true;
		}
		return false;
	}

	void PathFinder::establishingRoad(std::queue<sf::Vector2i> *Q, std::queue<sf::Vector2f> *targets, sf::Vector2i *toPos, sf::Vector2i *fromPos)
	{
		if (!Q->empty())//isn't empty <=> way has been found
		{
			sf::Vector2i currentlyConsidered = *toPos;

			targets->push(sf::Vector2f(currentlyConsidered.x*constants::cell::CELL_DIMENSIONS.x, currentlyConsidered.y*constants::cell::CELL_DIMENSIONS.y));

			bool sthChangedFlag = true;

			searchLowerWeight(&currentlyConsidered, fromPos, &sthChangedFlag, targets);

			reverse(targets);
		}
	}

	void PathFinder::searchLowerWeight(sf::Vector2i *currentlyConsidered, sf::Vector2i *fromPos, bool *sthChangedFlag, std::queue<sf::Vector2f> *targets)
	{
		const std::vector<std::pair<int, int>> neighbours = { std::pair<int,int>(0,-1),std::pair<int,int>(1,-1), std::pair<int,int>(1,0),std::pair<int,int>(1,1),std::pair<int,int>(0,1),std::pair<int,int>(-1, 1),std::pair<int,int>(-1, 0),std::pair<int,int>(-1, -1) };

		sf::Vector2i neighbor;

		while (*currentlyConsidered != *fromPos && *sthChangedFlag)
		{
			size_t direction;
			for (direction = 0; direction < neighbours.size(); direction++)
			{
				neighbor = sf::Vector2i(currentlyConsidered->x + neighbours[direction].first, currentlyConsidered->y + neighbours[direction].second);
				if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) break;
			}
			if (direction != neighbours.size()) continue;
			*sthChangedFlag = false;
		}
	}

	void PathFinder::increaseWeight(sf::Vector2i *neighbor, sf::Vector2i *currentlyConsidered, std::queue<sf::Vector2i> *Q)
	{
		mapImitation::weights[unitMapSize->x*neighbor->y + neighbor->x] = mapImitation::weights[unitMapSize->x*currentlyConsidered->y + currentlyConsidered->x] + 1;
		addToQueueSearch(Q, neighbor);
	}

	void PathFinder::addToQueueSearch(std::queue<sf::Vector2i>* Q, sf::Vector2i * neighbor)
	{
		Q->push(*neighbor);
	}

	bool PathFinder::isCellBlocking(sf::Vector2i * currentlyConsidered, sf::Vector2i * singleAlternate)
	{
		if (!isInMap(sf::Vector2i(currentlyConsidered->x + singleAlternate->x, currentlyConsidered->y + singleAlternate->y)))
			return false;
		else if (!MapManager::isCollidableUnit(sf::Vector2i(currentlyConsidered->y + singleAlternate->y, currentlyConsidered->x + singleAlternate->x)))
			return false;
		return true;
	}

	bool PathFinder::targetIsUnreachable(const sf::Vector2f & to)
	{
		sf::Vector2i unitTarget = Math::convertPositionToUnitSystem(to,constants::cell::CELL_DIMENSIONS);
		return !MapManager::isCollidableUnit(unitTarget);
	}

	void PathFinder::init( sf::Vector2i *worldSize)
	{
		unitMapSize = worldSize;
	}

	void PathFinder::fillTargetsQueue(const sf::Vector2f& from, const sf::Vector2f& to, std::queue<sf::Vector2f> *targets)
	{

		if (!targetIsUnreachable(to)) return;

		clearTargets(targets);

		//Converting real coordinates of points to i | j system
		sf::Vector2i toPosUnit = sf::Vector2i(to.x / constants::cell::CELL_DIMENSIONS.x, to.y / constants::cell::CELL_DIMENSIONS.y);
		sf::Vector2i fromPosUnit = sf::Vector2i(from.x / constants::cell::CELL_DIMENSIONS.x, from.y / constants::cell::CELL_DIMENSIONS.y);

		std::queue<sf::Vector2i> Q;

		initialTreatments(&Q, &fromPosUnit);

		tourTheMap(&Q, &toPosUnit);

		establishingRoad(&Q, targets, &toPosUnit, &fromPosUnit);
	}

}

