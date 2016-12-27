#include "PathFinder.hpp"

struct PathFinder::mapImitation;
std::vector<Cell>* PathFinder::mapImitation::cells;
std::vector<int> PathFinder::mapImitation::weights;

sf::Vector2f PathFinder::cellDimensions;
sf::Vector2i PathFinder::mapSize;


void PathFinder::clearTargets(std::queue<sf::Vector2f>* targets)
{
	while (!targets->empty()) targets->pop();
}

sf::Vector2i PathFinder::convertCordsToPos(sf::Vector2f data)
{
	return sf::Vector2i(data.x / cellDimensions.x, data.y / cellDimensions.y);
}

bool PathFinder::isInMap(const sf::Vector2i& position)
{
	return !(position.x<0 || position.x > mapSize.x - 1 || position.y<0 || position.y > mapSize.y - 1);
}

void PathFinder::transitionToNeighbor(sf::Vector2i *neighbor, sf::Vector2i *currentlyConsidered, std::queue<sf::Vector2f> *targets)
{
	*currentlyConsidered = *neighbor;
	targets->push(sf::Vector2f(currentlyConsidered->x*cellDimensions.x, currentlyConsidered->y*cellDimensions.y));
}

void PathFinder::categorizeCells(sf::Vector2i * neighbor, sf::Vector2i * currentlyConsidered, std::queue<Cell*> *Q, short direction)
{
	std::pair<sf::Vector2i,sf::Vector2i> alternate;

	if (isInMap(*neighbor) && !(&(*(mapImitation::cells))[mapSize.x*neighbor->y + neighbor->x])->IsCollideable() && mapImitation::weights[mapSize.x*neighbor->y + neighbor->x] == PathFinder::NOT_VISITED)
	{
		switch (direction)
		{
			case PathFinder::Direction::NORTH:
			case PathFinder::Direction::EAST:
			case PathFinder::Direction::SOUTH:
			case PathFinder::Direction::WEST: increaseWeight(neighbor, currentlyConsidered, Q); break;

			case PathFinder::Direction::NORTH_EAST:
			{
				alternate.first.x = 1; alternate.first.y = 0;
				alternate.second.x = 0; alternate.second.y = -1;
				break;
			}

			case PathFinder::Direction::SOUTH_EAST:
			{
				alternate.first.x = 1; alternate.first.y = 0;
				alternate.second.x = 0; alternate.second.y = 1;
				break;
			}

			case PathFinder::Direction::SOUTH_WEST:
			{
				alternate.first.x = -1; alternate.first.y = 0;
				alternate.second.x = 0; alternate.second.y = 1;
				break;
			}

			case PathFinder::Direction::NORTH_WEST:
			{
				alternate.first.x = -1; alternate.first.y = 0;
				alternate.second.x = 0; alternate.second.y = -1;
				break;
			}
		}
		
		if (!isCellBlocking(currentlyConsidered,&alternate.first) && !isCellBlocking(currentlyConsidered,&alternate.second))
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
		targets->push(sf::Vector2f(var.x + cellDimensions.x / 2, var.y + cellDimensions.y / 2));
	}

}

void PathFinder::initialTreatments(std::queue<Cell*>* Q, sf::Vector2i * fromPos)
{
	setWeightsVectorAsNotVisited();
enterFirstElementToQueue(Q, fromPos);
}

void PathFinder::setWeightsVectorAsNotVisited()
{
	for (size_t i = 0; i < mapImitation::cells->size(); i++)
		mapImitation::weights.emplace_back(PathFinder::CellState::NOT_VISITED);
}

void PathFinder::enterFirstElementToQueue(std::queue<Cell*> *Q, sf::Vector2i *fromPos)
{
	Q->push(&((*(mapImitation::cells))[fromPos->y*mapSize.x + fromPos->x]));
	mapImitation::weights[fromPos->y*mapSize.x + mapSize.x] = PathFinder::CellState::START_POSITION;
}

void PathFinder::tourTheMap(std::queue<Cell*> *Q, sf::Vector2i *toPos)
{
	sf::Vector2i currentlyConsidered;

	const std::vector<std::pair<int, int>> neighbours = { std::pair<int,int>(0,-1),std::pair<int,int>(1,-1), std::pair<int,int>(1,0),std::pair<int,int>(1,1),std::pair<int,int>(0,1),std::pair<int,int>(-1, 1),std::pair<int,int>(-1, 0),std::pair<int,int>(-1, -1) };
	sf::Vector2i neighbor;

	while (!Q->empty())
	{
		currentlyConsidered = sf::Vector2i(convertCordsToPos(Q->front()->getPosition());
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
	if (isInMap(*neighbor) && mapImitation::weights[neighbor->y*mapSize.x + neighbor->x] == mapImitation::weights[currentlyConsidered->y*mapSize.x + currentlyConsidered->x] - 1) //TOP LEFT
	{
		transitionToNeighbor(neighbor, currentlyConsidered, targets);
		return true;
	}
	return false;
}

void PathFinder::establishingRoad(std::queue<Cell*> *Q, std::queue<sf::Vector2f> *targets, sf::Vector2i *toPos, sf::Vector2i *fromPos)
{
	if (!Q->empty())//isn't empty <=> way has been found
	{
		sf::Vector2i currentlyConsidered = *toPos;

		targets->push(sf::Vector2f(currentlyConsidered.x*cellDimensions.x, currentlyConsidered.y*cellDimensions.y));

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

void PathFinder::increaseWeight(sf::Vector2i *neighbor, sf::Vector2i *currentlyConsidered, std::queue<Cell*> *Q)
{
	mapImitation::weights[mapSize.x*neighbor->y + neighbor->x] = mapImitation::weights[mapSize.x*currentlyConsidered->y + currentlyConsidered->x] + 1;
	addToQueueSearch(Q, neighbor);
}

void PathFinder::addToQueueSearch(std::queue<Cell*>* Q, sf::Vector2i * neighbor)
{
	Q->push(&((*(mapImitation::cells))[mapSize.x*neighbor->y + neighbor->x]));
}

bool PathFinder::isCellBlocking(sf::Vector2i * currentlyConsidered, sf::Vector2i * singleAlternate)
{
	if (!isInMap(sf::Vector2i(currentlyConsidered->x + singleAlternate->x, currentlyConsidered->y + singleAlternate->y)))
		return false;
	else if (!(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y + singleAlternate->y) + currentlyConsidered->x + singleAlternate->x].IsCollideable())
		return false;
	return true;
}

void PathFinder::Init(std::vector<Cell> *cells, sf::Vector2f cellDim, sf::Vector2i worldSize)
{
	mapImitation::cells = cells;
	cellDimensions = cellDim;
	mapSize = worldSize;
}

void PathFinder::FillTargetsQueue(sf::Vector2f from, sf::Vector2f to, std::queue<sf::Vector2f> *targets)
{
	clearTargets(targets);

	//Converting real coordinates of points to i | j system
	sf::Vector2i toPos = sf::Vector2i(to.x / cellDimensions.x, to.y / cellDimensions.y);
	sf::Vector2i fromPos = sf::Vector2i(from.x / cellDimensions.x, from.y / cellDimensions.y);

	std::queue<Cell*> Q;

	initialTreatments(&Q, &fromPos);

	tourTheMap(&Q, &toPos);

	establishingRoad(&Q, targets, &toPos, &fromPos);
}
