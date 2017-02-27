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
	public:
		SaveSystem();

		/*
		/ Add new var to vector, also overwrites old one
		/ @param string varName
		/ @param string varValue
		*/
		void AddVariable( const std::string& name, const std::string& value )
		{
			this->variables[name] = value;
		}
		/*
		/ Get var from vector by name
		/ @param string varName
		/ @return variable data or "@error"
		*/
		std::string GetVariable( const std::string& name ) const;
		/*
		/ Get vector with vars
		/ @return std::vector<Var>
		*/
		std::unordered_map<std::string, std::string> GetVariables() const
		{
			return this->variables;
		}
		/*
		/ Update var in vector by name
		/ @param string varName
		/ @param string newValue
		/ @return bool ('true' if updated properly)
		*/
		bool UpdateVariable( const std::string&, const std::string& );
		/*
		/ Save to file
		/ @param string PathFile
		/ @return bool ('true' if saved properly)
		*/
		bool SaveToFile( const std::string& );
		/*
		/ Parse from file
		/ @param string PathFile
		/ @return bool ('true' if parse properly)
		*/
		bool LoadFromFile( const std::string& );
		/*
		/ Clear vars vector
		*/
		void Clear()
		{
			this->variables.clear();
		}

	private:
		std::unordered_map<std::string, std::string> variables;

		bool checkComment( const std::string& );
		bool load( const std::string&, std::vector<std::string>& );
		void parse( std::vector<std::string>& );
		void removeSpaces( std::string& );
		void split( const std::string& );
	};
}
