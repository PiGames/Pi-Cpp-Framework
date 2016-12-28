#include "Logger.hpp"

namespace pi
{
	std::ofstream Logger::file;

	void Logger::init(const std::string& outputFileName)
	{
		if (file.is_open())
			return;

		file.open(outputFileName);
		file << "";
		file.close();

		file.open(outputFileName, std::ios::app);
	}

	void Logger::logToFile(const std::string & message)
	{
		file << message << "\n";
	}

	void Logger::logToConsole(const std::string & message)
	{
		std::cout << message << "\n";
	}

	void Logger::log(const std::string& message, MessageType messageType, OutputType outputType)
	{
		std::string typeText = "";
		std::string output = "";

		switch (messageType)
		{
		case MessageType::Separator:
			break;

		case MessageType::Info:
			typeText = "[INFO] ";
			break;

		case MessageType::Warning:
			typeText = "[WARNING] ";
			break;

		case MessageType::Error:
			typeText = "[ERROR] ";
			break;

		case MessageType::Assert:
			typeText = "[ASSERT] ";
			break;
		}

		output = typeText + message;

		switch (outputType)
		{
			case OutputType::Console:
				logToConsole(output);
				break;

			case OutputType::File:
				logToFile(output);
				break;

			case OutputType::Both:
				logToConsole(output);
				logToFile(output);
				break;
		}
	}
}
