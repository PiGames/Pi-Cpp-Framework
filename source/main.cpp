#include <iostream>
#include "engine\savesystem\SaveSystem.hpp"

int main()
{
	std::cout << "Mars Colony \ncreated by PiGames \n";
	
	
	
	auto MyCfg = pi::SaveSystem();

	MyCfg.loadFromFile("data/save_2.txt");
	MyCfg.addVariable("Kills", "5002");
	MyCfg.saveToFile("data/save_3.txt");
	
	
	std::cin.get();
	return 0;
}