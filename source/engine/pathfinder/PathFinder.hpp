// Created by: mvxxx
#pragma once

#include <queue>

#include <SFML/System/Vector2.hpp>

#include "engine/map/MapManager.hpp"
#include "engine/Config.hpp"
#include "engine/Math.hpp"

namespace pi
{
	//PathFinder class
	//It finds the best way to target
	class PathFinder final
	{
	private:
		//Clears targets queue
		static void clearTargets(std::queue<sf::Vector2f>* targets);

		//Checksthat point (represented by i|j system) is in map
		static bool isInMap(const sf::Vector2i& position);

		//Revers queue to the final form of targets
		static void reverse(std::queue<sf::Vector2f> *targets);

		//Sets neighbor as currently considered cell (when neighbor has got lower weight than currently considered cell)
		static void transitionToNeighbor(sf::Vector2i *neighbor, sf::Vector2i *currentlyConsidered, std::queue<sf::Vector2f> *targets);

		//Ratings cells by weights system and optional adding it to queue
		static void categorizeCells(sf::Vector2i *w, sf::Vector2i *v, std::queue<sf::Vector2i> *Q, short direction);

		//basic treatments to start a pathfinding process
		static void initialTreatments(std::queue<sf::Vector2i>* Q, sf::Vector2i *fromPos);

		//Resets value of map <=> set all weights at "NOT_VISITED"
		static void setWeightsVectorAsNotVisited();

		//Init first element in queue to start pathfinding process
		static void enterFirstElementToQueue(std::queue<sf::Vector2i>* Q, sf::Vector2i *fromPos);

		//Process of combing the area to find a way to "to" point
		static void tourTheMap(std::queue<sf::Vector2i> *Q, sf::Vector2i *toPos);

		//Returns true if cell with lower weight has been found
		static bool foundLowerWeight(sf::Vector2i *currentlyConsidered, sf::Vector2i *neighbor, std::queue<sf::Vector2f> *targets);

		//Finds a way to back to start point
		static void establishingRoad(std::queue<sf::Vector2i> *Q, std::queue<sf::Vector2f> *targets, sf::Vector2i *toPos, sf::Vector2i *fromPos);

		//Searches a cell which has got lower weight than currently considered cell
		static void searchLowerWeight(sf::Vector2i *currentlyConsidered, sf::Vector2i *fromPos, bool *sthChangedFlag, std::queue<sf::Vector2f> *targets);

		//Increases weight of cell and calling addToQueueSearch() method
		static void increaseWeight(sf::Vector2i *neighbor, sf::Vector2i *currentlyConsidered, std::queue<sf::Vector2i> *Q);

		//Adds cordinates fo cell to queue search
		static void	addToQueueSearch(std::queue<sf::Vector2i> *Q, sf::Vector2i *neighbor);

		//Checks that a cell is an obstacle or not
		static bool isCellBlocking(sf::Vector2i * currentlyConsidered, sf::Vector2i *singleAlternate);

		//Checks that target is unreachable
		static bool targetIsUnreachable(const sf::Vector2f& to);

	public:
		PathFinder() = delete;

		//Initialization (on the begining of game process)
		static void Init(sf::Vector2i *worldSize);

		//Filling targets queue by points which represents way to "to" point
		static void FillTargetsQueue(const sf::Vector2f& from, const sf::Vector2f& to, std::queue<sf::Vector2f> *targets);
	
		static struct mapImitation
		{
		public:
		//	static std::vector<Cell>* cells;
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

		//Map size represented by i|j system
		static sf::Vector2i *unitMapSize;

	};
}
