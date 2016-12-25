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
			if ((isInMap(sf::Vector2i(currentlyConsidered->x+1, currentlyConsidered->y)) && isInMap(sf::Vector2i(currentlyConsidered->x , currentlyConsidered->y-1)) && !(*(mapImitation::cells))[mapSize.x*neighbor->y + neighbor->x + 1].IsCollideable() && !(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y-1) + currentlyConsidered->x ].IsCollideable()) ||
			(isInMap(sf::Vector2i(currentlyConsidered->x + 1, currentlyConsidered->y)) && !(*(mapImitation::cells))[mapSize.x*currentlyConsidered->y + currentlyConsidered->x + 1].IsCollideable()) ||
			(isInMap(sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y - 1)) && !(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y - 1) + currentlyConsidered->x].IsCollideable()))
			increaseWeight(neighbor, currentlyConsidered, Q);
			break;
			}

			case PathFinder::Direction::SOUTH_EAST:
			{
			if ((isInMap(sf::Vector2i(currentlyConsidered->x + 1, currentlyConsidered->y)) && isInMap(sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y + 1)) && !(*(mapImitation::cells))[mapSize.x*currentlyConsidered->y + currentlyConsidered->x + 1].IsCollideable() && !(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y + 1) + currentlyConsidered->x].IsCollideable()) ||
			(isInMap(sf::Vector2i(currentlyConsidered->x + 1, currentlyConsidered->y)) && !(*(mapImitation::cells))[mapSize.x*currentlyConsidered->y + currentlyConsidered->x + 1].IsCollideable()) ||
			(isInMap(sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y + 1)) && !(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y + 1) + currentlyConsidered->x].IsCollideable()))
			increaseWeight(neighbor, currentlyConsidered, Q);
			break;
			}

			case PathFinder::Direction::SOUTH_WEST:
			{
			if ((isInMap(sf::Vector2i(currentlyConsidered->x - 1, currentlyConsidered->y)) && isInMap(sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y + 1)) && !(*(mapImitation::cells))[mapSize.x*currentlyConsidered->y + currentlyConsidered->x - 1].IsCollideable() && !(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y + 1) + currentlyConsidered->x].IsCollideable()) ||
			(isInMap(sf::Vector2i(currentlyConsidered->x - 1, currentlyConsidered->y)) && !(*(mapImitation::cells))[mapSize.x*currentlyConsidered->y + currentlyConsidered->x - 1].IsCollideable()) ||
			(isInMap(sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y + 1)) && !(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y + 1) + currentlyConsidered->x].IsCollideable()))
			increaseWeight(neighbor, currentlyConsidered, Q);
			break;
			}

			case PathFinder::Direction::NORTH_WEST:
			{
			if ((isInMap(sf::Vector2i(currentlyConsidered->x - 1, currentlyConsidered->y)) && isInMap(sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y - 1)) && !(*(mapImitation::cells))[mapSize.x*currentlyConsidered->y + currentlyConsidered->x - 1].IsCollideable() && !(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y - 1) + currentlyConsidered->x].IsCollideable()) ||
			(isInMap(sf::Vector2i(currentlyConsidered->x - 1, currentlyConsidered->y)) && !(*(mapImitation::cells))[mapSize.x*currentlyConsidered->y + currentlyConsidered->x - 1].IsCollideable()) ||
			(isInMap(sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y - 1)) && !(*(mapImitation::cells))[mapSize.x*(currentlyConsidered->y - 1) + currentlyConsidered->x].IsCollideable()))
			increaseWeight(neighbor, currentlyConsidered, Q);
			break;
			}
		}
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

	while (!Q->empty())
	{
		currentlyConsidered = sf::Vector2i(convertCordsToPos(Q->front()->GetPosition()));
		Q->pop();

		sf::Vector2i neighbor = sf::Vector2i(currentlyConsidered.x - 1, currentlyConsidered.y - 1);//TOP-LEFT
		categorizeCells(&neighbor, &currentlyConsidered, Q, PathFinder::Direction::NORTH_WEST);
		if (neighbor == *toPos) break;

		neighbor = sf::Vector2i(currentlyConsidered.x, currentlyConsidered.y - 1);//TOP-CENTER
		categorizeCells(&neighbor, &currentlyConsidered, Q, PathFinder::Direction::NORTH);
		if (neighbor == *toPos) break;

		neighbor = sf::Vector2i(currentlyConsidered.x + 1, currentlyConsidered.y - 1);//TOP-RIGHT
		categorizeCells(&neighbor, &currentlyConsidered, Q, PathFinder::Direction::NORTH_EAST);
		if (neighbor == *toPos) break;

		neighbor = sf::Vector2i(currentlyConsidered.x - 1, currentlyConsidered.y);//CENTER-LEFT
		categorizeCells(&neighbor, &currentlyConsidered, Q, PathFinder::Direction::WEST);
		if (neighbor == *toPos) break;

		neighbor = sf::Vector2i(currentlyConsidered.x + 1, currentlyConsidered.y);//CENTER-RIGHT
		categorizeCells(&neighbor, &currentlyConsidered, Q, PathFinder::Direction::EAST);
		if (neighbor == *toPos) break;

		neighbor = sf::Vector2i(currentlyConsidered.x - 1, currentlyConsidered.y + 1);//DOWN-LEFT
		categorizeCells(&neighbor, &currentlyConsidered, Q, PathFinder::Direction::SOUTH_WEST);
		if (neighbor == *toPos) break;


		neighbor = sf::Vector2i(currentlyConsidered.x, currentlyConsidered.y + 1);//DOWN-CENTER
		categorizeCells(&neighbor, &currentlyConsidered, Q, PathFinder::Direction::SOUTH);
		if (neighbor == *toPos) break;

		neighbor = sf::Vector2i(currentlyConsidered.x + 1, currentlyConsidered.y + 1);//DOWN-RIGHT
		categorizeCells(&neighbor, &currentlyConsidered, Q, PathFinder::Direction::SOUTH_EAST);
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
	while (*currentlyConsidered != *fromPos && *sthChangedFlag)
	{
		sf::Vector2i neighbor = sf::Vector2i(currentlyConsidered->x - 1, currentlyConsidered->y - 1);
		if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) continue;

		neighbor = sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y - 1);//TOP-CENTER
		if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) continue;

		neighbor = sf::Vector2i(currentlyConsidered->x + 1, currentlyConsidered->y - 1);//TOP-RIGHT
		if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) continue;

		neighbor = sf::Vector2i(currentlyConsidered->x - 1, currentlyConsidered->y);//CENTER-LEFT
		if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) continue;

		neighbor = sf::Vector2i(currentlyConsidered->x + 1, currentlyConsidered->y);//CENTER-RIGHT
		if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) continue;

		neighbor = sf::Vector2i(currentlyConsidered->x - 1, currentlyConsidered->y + 1);//DOWN-LEFT
		if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) continue;

		neighbor = sf::Vector2i(currentlyConsidered->x, currentlyConsidered->y + 1);//DOWN-CENTER
		if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) continue;

		neighbor = sf::Vector2i(currentlyConsidered->x + 1, currentlyConsidered->y + 1);//DOWN-RIGHT
		if (foundLowerWeight(currentlyConsidered, &neighbor, targets)) continue;

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
