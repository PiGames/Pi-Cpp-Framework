#include "PathFinder.hpp"

std::pair<std::vector<Cell>*, std::vector<int>> PathFinder::m_cells;
sf::Vector2f PathFinder::cellDimensions;
sf::Vector2i PathFinder::mapSize; //i/j


void PathFinder::clearTargets(std::queue<sf::Vector2f>* targets)
{
	while(!targets->empty()) targets->pop();
}

sf::Vector2i PathFinder::convertCordsToPos(sf::Vector2f data)
{
	return sf::Vector2i(data.x/ cellDimensions.x, data.y / cellDimensions.y);
}

bool PathFinder::isInMap(sf::Vector2i position) //in i|j system
{
	return !(position.x<0 || position.x > mapSize.x || position.y<0 || position.y > mapSize.y);
}

void PathFinder::wayBackProcess(sf::Vector2i zp, sf::Vector2i w, std::queue<sf::Vector2f> *targets)
{
		w = zp;
		targets->push(sf::Vector2f(w.x*cellDimensions.x, w.y*cellDimensions.y));
}

void PathFinder::reverse(std::queue<sf::Vector2f>* targets)
{
	std::vector<sf::Vector2f> list;

	while (!targets->empty())
	{
		list.push_back(targets->front());
		targets->pop();
	}

	for (auto var : list)
		targets->push(var);
	
}

void PathFinder::Init(std::vector<Cell> *cells, sf::Vector2f cellDim, sf::Vector2i worldSize)
{
	m_cells.first = cells;
	cellDimensions = cellDim;
	mapSize = worldSize;
}

void PathFinder::FillTargetsQueue(sf::Vector2f from, sf::Vector2f to, std::queue<sf::Vector2f> *targets)
{
	sf::Vector2i toPos = sf::Vector2i(to.x / cellDimensions.x, to.y / cellDimensions.y); //convert from map cords to i|j system
	sf::Vector2i fromPos = sf::Vector2i(from.x / cellDimensions.x, from.y / cellDimensions.y);
	//krok 0
	std::queue<Cell*> Q;

	for (auto var : m_cells.second)
		var = -1;
	//krok 1
	Q.push((Cell*)&m_cells.first[convertCordsToPos(from).y*mapSize.x + convertCordsToPos(from).x]);
	m_cells.second[convertCordsToPos(from).y*mapSize.x + convertCordsToPos(from).x] = 0;


	//krok 2
	sf::Vector2i v;

	while (!Q.empty())
	{
		//krok 3
		v = sf::Vector2i(convertCordsToPos(Q.front()->GetPosition()));
		Q.pop();

		//krok 4-5
		sf::Vector2i w = sf::Vector2i(v.x - 1, v.y - 1);//Left-Top
		
		if(isInMap(w) && ((Cell*)&m_cells.first[mapSize.x*w.y + w.x])->IsCollideable() && m_cells.second[mapSize.x*w.y + w.x]==-1)
		{ 
			m_cells.second[mapSize.x*w.y + w.x] = m_cells.second[mapSize.x*v.y + v.x] + 1;
			Q.push((Cell*)&m_cells.first[mapSize.x*w.y + w.x]);
			if (w == toPos) break;
		}


		w = sf::Vector2i(v.x, v.y - 1);//TOP-CENTER
		
		if (isInMap(w) && ((Cell*)&m_cells.first[mapSize.x*w.y + w.x])->IsCollideable() && m_cells.second[mapSize.x*w.y + w.x] == -1)
		{
			m_cells.second[mapSize.x*w.y + w.x] = m_cells.second[mapSize.x*v.y + v.x] + 1;
			Q.push((Cell*)&m_cells.first[mapSize.x*w.y + w.x]);
			if (w == toPos) break;
		}

		w = sf::Vector2i(v.x, v.y - 1);//TOP-RIGHT

		if (isInMap(w) && ((Cell*)&m_cells.first[mapSize.x*w.y + w.x])->IsCollideable() && m_cells.second[mapSize.x*w.y + w.x] == -1)
		{
			m_cells.second[mapSize.x*w.y + w.x] = m_cells.second[mapSize.x*v.y + v.x] + 1;
			Q.push((Cell*)&m_cells.first[mapSize.x*w.y + w.x]);
			if (w == toPos) break;
		}

		w = sf::Vector2i(v.x-1, v.y );//CENTER-LEFT

		if (isInMap(w) && ((Cell*)&m_cells.first[mapSize.x*w.y + w.x])->IsCollideable() && m_cells.second[mapSize.x*w.y + w.x] == -1)
		{
			m_cells.second[mapSize.x*w.y + w.x] = m_cells.second[mapSize.x*v.y + v.x] + 1;
			Q.push((Cell*)&m_cells.first[mapSize.x*w.y + w.x]);
			if (w == toPos) break;
		}

		w = sf::Vector2i(v.x+1, v.y );//CENTER-RIGHT

		if (isInMap(w) && ((Cell*)&m_cells.first[mapSize.x*w.y + w.x])->IsCollideable() && m_cells.second[mapSize.x*w.y + w.x] == -1)
		{
			m_cells.second[mapSize.x*w.y + w.x] = m_cells.second[mapSize.x*v.y + v.x] + 1;
			Q.push((Cell*)&m_cells.first[mapSize.x*w.y + w.x]);
			if (w == toPos) break;
		}

		w = sf::Vector2i(v.x - 1, v.y + 1);//DOWN-LEFT

		if (isInMap(w) && ((Cell*)&m_cells.first[mapSize.x*w.y + w.x])->IsCollideable() && m_cells.second[mapSize.x*w.y + w.x] == -1)
		{
			m_cells.second[mapSize.x*w.y + w.x] = m_cells.second[mapSize.x*v.y + v.x] + 1;
			Q.push((Cell*)&m_cells.first[mapSize.x*w.y + w.x]);
			if (w == toPos) break;
		}


		w = sf::Vector2i(v.x, v.y + 1);//DOWN-CENTER

		if (isInMap(w) && ((Cell*)&m_cells.first[mapSize.x*w.y + w.x])->IsCollideable() && m_cells.second[mapSize.x*w.y + w.x] == -1)
		{
			m_cells.second[mapSize.x*w.y + w.x] = m_cells.second[mapSize.x*v.y + v.x] + 1;
			Q.push((Cell*)&m_cells.first[mapSize.x*w.y + w.x]);
			if (w == toPos) break;
		}

		w = sf::Vector2i(v.x, v.y + 1);//DOWN-RIGHT

		if (isInMap(w) && ((Cell*)&m_cells.first[mapSize.x*w.y + w.x])->IsCollideable() && m_cells.second[mapSize.x*w.y + w.x] == -1)
		{
			m_cells.second[mapSize.x*w.y + w.x] = m_cells.second[mapSize.x*v.y + v.x] + 1;
			Q.push((Cell*)&m_cells.first[mapSize.x*w.y + w.x]);
			if (w == toPos) break;
		}
	}	

	//krok 6
	if (!Q.empty())//isn't empty <=> way has been found
	{
		sf::Vector2i w = toPos;
		
		targets->push(sf::Vector2f(w.x*cellDimensions.x,w.y*cellDimensions.y));

		while (w != fromPos)
		{
			sf::Vector2i zp = sf::Vector2i(w.x-1, w.y-1);

			if (isInMap(zp) && m_cells.second[zp.y*mapSize.x + zp.x]== m_cells.second[w.y*mapSize.x + w.x]-1) //TOP LEFT
			{
				wayBackProcess(zp, w, targets);
				continue;
			}

			zp = sf::Vector2i(w.x, w.y - 1);//TOP-CENTER

			if (isInMap(zp) && m_cells.second[zp.y*mapSize.x + zp.x] == m_cells.second[w.y*mapSize.x + w.x] - 1) //TOP LEFT
			{
				wayBackProcess(zp, w, targets);
				continue;
			}

			
			zp = sf::Vector2i(w.x + 1, w.y - 1);//TOP-RIGHT

			if (isInMap(zp) && m_cells.second[zp.y*mapSize.x + zp.x] == m_cells.second[w.y*mapSize.x + w.x] - 1) //TOP LEFT
			{
				wayBackProcess(zp, w, targets);
				continue;
			}

			zp = sf::Vector2i(w.x - 1, w.y);//CENTER-LEFT

			if (isInMap(zp) && m_cells.second[zp.y*mapSize.x + zp.x] == m_cells.second[w.y*mapSize.x + w.x] - 1) //TOP LEFT
			{
				wayBackProcess(zp, w, targets);
				continue;
			}


			zp = sf::Vector2i(w.x + 1, w.y);//CENTER-RIGHT

			if (isInMap(zp) && m_cells.second[zp.y*mapSize.x + zp.x] == m_cells.second[w.y*mapSize.x + w.x] - 1) //TOP LEFT
			{
				wayBackProcess(zp, w, targets);
				continue;
			}


			zp = sf::Vector2i(w.x - 1, w.y + 1);//DOWN-LEFT

			
			if (isInMap(zp) && m_cells.second[zp.y*mapSize.x + zp.x] == m_cells.second[w.y*mapSize.x + w.x] - 1) //TOP LEFT
			{
				wayBackProcess(zp, w, targets);
				continue;
			}


			zp = sf::Vector2i(w.x, w.y + 1);//DOWN-CENTER

			if (isInMap(zp) && m_cells.second[zp.y*mapSize.x + zp.x] == m_cells.second[w.y*mapSize.x + w.x] - 1) //TOP LEFT
			{
				wayBackProcess(zp, w, targets);
				continue;
			}

			zp = sf::Vector2i(w.x + 1, w.y + 1);//DOWN-RIGHT

			if (isInMap(zp) && m_cells.second[zp.y*mapSize.x + zp.x] == m_cells.second[w.y*mapSize.x + w.x] - 1) //TOP LEFT
			{
				wayBackProcess(zp, w, targets);
				continue;
			}

		}
		reverse(targets);
	}

	
}
