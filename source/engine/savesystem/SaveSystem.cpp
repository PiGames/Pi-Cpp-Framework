#include "SaveSystem.hpp"


namespace pi
{
	SaveSystem::SaveSystem()
	{
	}

	void SaveSystem::addVariable(std::string name, std::string value)
	{
		Var toAdd;
		toAdd.name = name;
		toAdd.value = value;
		this->vars.push_back(toAdd);
	}

	Var SaveSystem::getVariable(int index)
	{
		return this->vars[index];
	}

	bool SaveSystem::updateVariable(unsigned int index, std::string value)
	{
		if (this->vars.size() < index)
			return false;

		this->vars[index].value = value;
		return true;
	}

	bool SaveSystem::updateVariable(std::string index, std::string value)
	{
		for (auto& toupdate : this->vars)
		{
			if (toupdate.name == index)
			{
				toupdate.value = value;
				return true;
			}
		}
		return false;
	}

	std::vector<Var> SaveSystem::getVariables()
	{
		return this->vars;
	}

	bool SaveSystem::saveToFile(std::string path)
	{
		std::fstream file;

		file.open(path, std::ios::out);
		if (file.good() == false)
			return false;
		else
		{
			for (auto tosave : this->vars)
			{
				file << tosave.name << " = " << tosave.value << ";" << std::endl;
			}

			file.close();
		}

		return true;
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

				//Delete tabs and spaces
				unsigned int j = 0;
				for (unsigned int i = 0; i < line.size(); i++)
				{
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
				for (unsigned int i = 0; i < line.size(); i++)
				{
					
					if (line[i] == ';')
						continue;
					else if (line[i] == '#') //Comment
						break;

					if (line[i] == '=')
					{
						name = line.substr(0, i);
						value = line.substr(i + 1, line.size() - i - 2);

						//std::cout << value << std::endl;

						Var toAdd;
						toAdd.name = name;
						toAdd.value = value;

						this->vars.push_back(toAdd);
					}
				}
			}

			file.close();
		}
		return true;
	}

	void SaveSystem::clear()
	{
		this->vars.clear();
	}
}

