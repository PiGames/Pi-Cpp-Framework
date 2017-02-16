#include "SaveSystem.hpp"

namespace pi
{
	SaveSystem::SaveSystem()
	{
	}

	void SaveSystem::addVariable(const std::string& name, const std::string& value)
	{
		this->variables[name] = value;
	}

	std::string SaveSystem::getVariable(const std::string& name)
	{
		auto find = this->variables.find(name);

		if (find == this->variables.end())
			return "@error";

		return this->variables[name];
	}

	bool SaveSystem::updateVariable(const std::string& name, const std::string& value)
	{
		auto find = this->variables.find(name);

		if (find == this->variables.end())
		{
			Logger::Log(constants::error::saveSystem::CANNOT_UPDATE_CANNOT_FOUND + name, Logger::MessageType::Error);

			return false;
		}

		this->variables[name] = value;

		return true;
	}

	std::unordered_map<std::string, std::string> SaveSystem::getVariables()
	{
		return this->variables;
	}

	bool SaveSystem::saveToFile(const std::string& path)
	{
		std::ofstream file;

		file.open(path, std::ios::out);
		if (!file.good())
		{
			Logger::Log(constants::error::saveSystem::CANNOT_SAVE + path, Logger::MessageType::Error);

			file.close();

			return false;
		}


		for (auto& var : this->variables)
		{
			file << var.first << " = " << var.second << "\n";
		}

		file.close();

		return true;
	}

	bool SaveSystem::checkComment(const std::string& buffer)
	{
		if (buffer[0] == constants::saveSystem::COMMENT)
			return true;

		return false;
	}

	bool SaveSystem::load(const std::string & path, std::vector<std::string>& raw)
	{
		std::ifstream file;
		std::string temp;

		file.open(path);
		if (!file.is_open())
		{
			Logger::Log(constants::error::saveSystem::CANNOT_OPEN + path, Logger::MessageType::Error);

			return false;
		}

		while (!file.eof())
		{
			std::getline(file, temp);

			raw.push_back(temp);
		}

		file.close();

		return true;
	}

	void SaveSystem::parse(std::vector<std::string>& raw)
	{
		for (auto& line : raw)
		{
			if (checkComment(line))
				continue;

			removeSpaces(line);
			split(line);
		}
	}

	void SaveSystem::removeSpaces(std::string& line)
	{
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	}

	void SaveSystem::split(const std::string& line)
	{
		auto equalPosition = line.find('=');
		std::string name;
		std::string value;

		if (equalPosition == line.npos)
			return;

		name = line.substr(0, equalPosition);
		value = line.substr(equalPosition + 1, line.size());

		this->variables[name] = value;
	}

	bool SaveSystem::loadFromFile(const std::string& file)
	{
		std::vector<std::string> raw;

		clear();

		if (!load(file, raw))
			return false;

		parse(raw);

		return true;
	}

	void SaveSystem::clear()
	{
		this->variables.clear();
	}
}

