#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

namespace pi
{
	struct Var
	{

	};

	class SaveSystem
	{
	private:
		std::unordered_map<std::string, std::string> variables;
		
		bool checkComment(std::string);
	public:
		SaveSystem();

		/*
		/ Add new var to vector
		/ @param string varName
		/ @param string varValue
		*/
		void addVariable(std::string, std::string);
		/*
		/ Get var from vector by id
		/ @param unsigned int varID
		/ @return Var
		*/
		std::string getVariable(int);
		/*
		/ Get var from vector by name
		/ @param unsigned int varName
		/ @return Var
		*/
		std::string getVariable(const std::string&);
		/*
		/ Get vector with vars
		/ @return std::vector<Var>
		*/
		std::unordered_map<std::string, std::string> getVariables();
		/*
		/ Update var in vector by id
		/ @param unsigned int varID
		/ @param string newValue
		*/
		bool updateVariable(unsigned int, std::string);
		/*
		/ Update var in vector by name
		/ @param string varName
		/ @param string newValue
		*/
		bool updateVariable(std::string, std::string);
		/*
		/ Save to file
		/ @param string PathFile
		/ @return bool ('true' if save properly)
		*/
		bool saveToFile(std::string);
		/*
		/ Parse from file
		/ @param string PathFile
		/ @return bool ('true' if parse properly)
		*/
		bool loadFromFile(std::string);
		/*
		/ Clear vars vector
		*/
		void clear();
	};
}
