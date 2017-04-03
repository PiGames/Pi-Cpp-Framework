#pragma once
#include <string>
#include <tuple>
#include <vector>

class ISerializable
{
	//Sample data:
	//std::pair(variableName,variableValue)

public:
	//Return serialized data
	virtual std::vector<std::pair<std::string, std::string>> GetSerializedData() = 0;
	
	//Fills fields by serialized data
	//Return true if fills completed succesfully
	virtual bool SetSerializedData(std::vector<std::pair<std::string, std::string>> data) = 0;

};

