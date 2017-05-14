#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>

#include "Config.hpp"

namespace pi
{
	class Logger
	{
	public:
		enum stream_t
		{
			CONSOLE,
			FILE,
			BOTH
		};

		enum type_t
		{
			INFO = 0,
			SUGGESTION = 1,
			WARNING = 2,
			ERROR = 3
		};

		static void Log( const std::string&, const Logger::stream_t = Logger::stream_t::CONSOLE, const Logger::type_t = Logger::type_t::ERROR );

	private:

		static void sendMessage( const std::string& message, Logger::stream_t stream, std::string &prefix );

		static void consoleMessage( const std::string&message, std::string &prefix, std::time_t& time );

		static void fileMessage( const std::string&, std::string &prefix, std::time_t& time );

		static void setPrefix( Logger::type_t type, std::string &prefix );
	};

#if defined _DEBUG
#define DEBUG_LOG( message, output, prefix ) Logger::Log( message, output, prefix ); 
#else
#define DEBUG_LOG( message, prefix, output ) 
#endif

}
