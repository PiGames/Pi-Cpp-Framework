// Created by: Condzi
#pragma once

#include <fstream>
#include <string>
#include <unordered_map>

#include "engine/Logger.hpp"

namespace pi
{
	// Class for managing save files
	// In future probably changed to https://github.com/PiGames/SimpleINI
	class SaveSystem final
	{
	private:
		bool checkComment( const std::string& );
		bool load( const std::string&, std::vector<std::string>& );
		void parse( std::vector<std::string>& );
		void removeSpaces( std::string& );
		void split( const std::string& );

	public:
		SaveSystem();

		/*
		/ Add new var to vector, also overwrites old one
		/ @param string varName
		/ @param string varValue
		*/
		void addVariable( const std::string&, const std::string& );
		/*
		/ Get var from vector by name
		/ @param string varName
		/ @return variable data or "@error"
		*/
		std::string getVariable( const std::string& );
		/*
		/ Get vector with vars
		/ @return std::vector<Var>
		*/
		std::unordered_map<std::string, std::string> getVariables();
		/*
		/ Update var in vector by name
		/ @param string varName
		/ @param string newValue
		/ @return bool ('true' if updated properly)
		*/
		bool updateVariable( const std::string&, const std::string& );
		/*
		/ Save to file
		/ @param string PathFile
		/ @return bool ('true' if saved properly)
		*/
		bool saveToFile( const std::string& );
		/*
		/ Parse from file
		/ @param string PathFile
		/ @return bool ('true' if parse properly)
		*/
		bool loadFromFile( const std::string& );
		/*
		/ Clear vars vector
		*/
		void clear();

	private:
		std::unordered_map<std::string, std::string> variables;
	};
}
