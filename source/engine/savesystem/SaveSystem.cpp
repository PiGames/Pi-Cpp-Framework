#include "SaveSystem.hpp"


namespace pi
{
	SaveSystem::SaveSystem()
	{
	}

	void SaveSystem::addVariable(std::string name, std::string value)
	{
		this->variables.insert({ name, value });
	}

	std::string SaveSystem::getVariable(int index)
	{
		std::size_t i = 0;
		for (auto& toReturn : this->variables)
		{
			if (i == index)
				return toReturn.second;
			i++;
		}
	}
	
	std::string SaveSystem::getVariable(const std::string& index)
	{
		auto toReturn = this->variables.find(index);
		if (toReturn != this->variables.end())
		{
			return toReturn->second;
		}
	}

	bool SaveSystem::updateVariable(unsigned int index, std::string value)
	{

		return true;
	}

	bool SaveSystem::updateVariable(std::string index, std::string value)
	{

		return false;
	}

	std::unordered_map<std::string, std::string> SaveSystem::getVariables()
	{
		return this->variables;
	}

	bool SaveSystem::saveToFile(std::string path)
	{
		std::fstream file;

		file.open(path, std::ios::out);
		if (file.good() == false)
			return false;
		else
		{
			for (auto tosave : this->variables)
			{
				file << tosave.first << " = " << tosave.second << ";" << std::endl;
			}

			file.close();
		}

		return true;
	}

	bool SaveSystem::checkComment(std::string buffer)
	{
		for (unsigned int i = 0; i < buffer.size(); i++) 
			if (buffer[i] == '#') 
				return true;
			
		
		return false;
	}

	bool SaveSystem::loadFromFile(std::string path)
	{
		clear();

		std::fstream file;

		file.open(path, std::ios::in);
		if (file.good() == false)
			return false;
		else
		{
			std::string line;
			while (!file.eof())
			{
				getline(file, line);
				if(!checkComment(line))
				{
					//Delete tabs, spaces and ';'
					std::size_t j = 0;
					for (std::size_t i = 0; i < line.size(); i++)
					{
						if (line[i] == ';')
						{
							std::size_t found = line.find_first_of(';');
							while (found != i)
							{
								if (line[i] == line[found])
									continue;
								else
									line.erase(found, 1);
							}
						}
						if (line[i] == ' ' || line[i] == '\t')
						{
							j = i + 1;
							while (j < line.size() && (line[j] == ' '))
								++j;

							if (j == i)
								line.erase(i, 1);
							else
								line.erase(i, j - i);
						}
					}

					std::string name;
					std::string value;
					for (std::size_t i = 0; i < line.size(); i++)
					{
						if (line[i] == '=')
						{
							name = line.substr(0, i);
							value = line.substr(i + 1, line.size() - i - 2);

							this->variables.insert({ name, value });
						}
					}
				}
			}
			file.close();
		}
		return true;
	}

	void SaveSystem::clear()
	{
		this->variables.clear();
	}
}

