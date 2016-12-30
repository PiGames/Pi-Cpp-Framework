#include "Interpreter.hpp"

namespace pi
{
	float* Interpreter::heightMap;
	std::vector<int> Interpreter::id;

	void Interpreter::loadCellTypes()
	{
		std::ifstream input("id.txt");
		int tempID;

		while (input >> tempID) id.push_back(tempID);
	}

	void Interpreter::ConstructWorld(int width, int height, int seed, int accuracy)
	{
		heightMap = WorldGenerator::Generate(width,height,seed,accuracy);

		loadCellTypes();
	}

}

