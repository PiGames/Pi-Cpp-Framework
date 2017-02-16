#include "Logger.hpp"

namespace pi
{
	std::ofstream Logger::file;
	Console* Logger::console;

	void Logger::Init(const std::string& outputFileName, Console* console)
	{
		if (Logger::file.is_open())
			return;

		Logger::file.open(outputFileName);

		Logger::console = console;
	}

	void Logger::logToFile(const std::string & message)
	{
		file << message << "\n";
	}

	void Logger::logToConsole(const std::string & message)
	{
		std::cout << message << "\n";

		if (Logger::console != nullptr)
			Logger::console->log(message);
	}

	void Logger::Log(const std::string& message, MessageType messageType, OutputType outputType)
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
			Logger::logToConsole(output);
			break;

		case OutputType::File:
			Logger::logToFile(output);
			break;

		case OutputType::Both:
			Logger::logToConsole(output);
			Logger::logToFile(output);
			break;
		}
	}
}
