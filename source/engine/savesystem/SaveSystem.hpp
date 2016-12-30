#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace pi
{
	struct Var
	{
		std::string name;
		std::string value;
	};

	class SaveSystem
	{
	private:
		std::vector<Var> vars;
		
		bool isValid(std::string);
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
		Var getVariable(int);
		/*
		/ Get var from vector by name
		/ @param unsigned int varName
		/ @return Var
		*/
		Var getVariable(std::string);
		/*
		/ Get vector with vars
		/ @return std::vector<Var>
		*/
		std::vector<Var> getVariables();
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
