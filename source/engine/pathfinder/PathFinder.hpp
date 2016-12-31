#pragma once

#include <SFML/System/Vector2.hpp>
#include <queue>
#include "engine/cell/Cell.hpp"
#include "engine/Config.hpp"

namespace pi
{
	class PathFinder final
	{
		//Clearing targets queue
		static void clearTargets(std::queue<sf::Vector2f>* targets);

		//Converting real coordinates of point to i|j system
		static sf::Vector2i convertPositionToUnitSystem(const sf::Vector2f& data);

		//Checking that point (represented by i|j system) is in map
		static bool isInMap(const sf::Vector2i& position);

		//Reversing queue to the final form of targets
		static void reverse(std::queue<sf::Vector2f> *targets);

		//Set neighbor as currently considered cell (when neighbor has got lower weight than currently considered cell)
		static void transitionToNeighbor(sf::Vector2i *neighbor, sf::Vector2i *currentlyConsidered, std::queue<sf::Vector2f> *targets);

		//Rating cells by weights system and optional adding it to queue
		static void categorizeCells(sf::Vector2i *w, sf::Vector2i *v, std::queue<Cell*> *Q, short direction);

		//basic treatments to start a pathfinding process
		static void initialTreatments(std::queue<Cell*> *Q, sf::Vector2i *fromPos);

		//Reset value of map <=> set all weights at "NOT_VISITED"
		static void setWeightsVectorAsNotVisited();

		//Init first element in queue to start pathfinding process
		static void enterFirstElementToQueue(std::queue<Cell*> *Q, sf::Vector2i *fromPos);

		//Process of combing the area to find a way to "to" point
		static void tourTheMap(std::queue<Cell*> *Q, sf::Vector2i *toPos);

		//Returns true if cell with lower weight has been found
		static bool foundLowerWeight(sf::Vector2i *currentlyConsidered, sf::Vector2i *neighbor, std::queue<sf::Vector2f> *targets);

		//Finding a way to back to start point
		static void establishingRoad(std::queue<Cell*> *Q, std::queue<sf::Vector2f> *targets, sf::Vector2i *toPos, sf::Vector2i *fromPos);

		//Searching a cell which has got lower weight than currently considered cell
		static void searchLowerWeight(sf::Vector2i *currentlyConsidered, sf::Vector2i *fromPos, bool *sthChangedFlag, std::queue<sf::Vector2f> *targets);

		//Increasing weight of cell and calling addToQueueSearch() method
		static void increaseWeight(sf::Vector2i *neighbor, sf::Vector2i *currentlyConsidered, std::queue<Cell*> *Q);

		//Add cordinates fo cell to queue search
		static void	addToQueueSearch(std::queue<Cell*> *Q, sf::Vector2i *neighbor);

		//Checking that a cell is an obstacle or not
		static bool isCellBlocking(sf::Vector2i * currentlyConsidered, sf::Vector2i *singleAlternate);

	public:

		//Initialization (on the begining of game process)
		static void Init(std::vector<Cell> *cells, sf::Vector2f *cellDim, sf::Vector2i *worldSize);

		//Filling targets queue by points which represents way to "to" point
		static void FillTargetsQueue(const sf::Vector2f& from, const sf::Vector2f& to, std::queue<sf::Vector2f> *targets);
	
		static struct mapImitation
		{
		public:
			static std::vector<Cell>* cells;
			static std::vector<int> weights;
		};

		static enum CellState
		{
			NOT_VISITED = -1,
			START_POSITION = 0
		};

		static enum	Direction
		{
			NORTH = 0,
			NORTH_EAST = 1,
			EAST = 2,
			SOUTH_EAST = 3,
			SOUTH = 4,
			SOUTH_WEST = 5,
			WEST = 6,
			NORTH_WEST = 7
		};

		//Real value of single cell
		static sf::Vector2f *cellDimensions;

		//Map size represented by i|j system
		static sf::Vector2i *mapSize;

	};
}
