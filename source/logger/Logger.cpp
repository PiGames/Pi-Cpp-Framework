#include "Logger.hpp"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

namespace pi
{
	void Logger::Log( const std::string& message, const Logger::stream_t stream, const Logger::type_t type )
	{
		std::string prefix;
		setPrefix( type, prefix );
		sendMessage( message, stream, prefix );
	}

	void Logger::sendMessage( const std::string& message, Logger::stream_t stream, std::string &prefix )
	{
		std::chrono::time_point<std::chrono::system_clock> date = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t( date );

		switch ( stream )
		{
		case Logger::stream_t::FILE:
		{
			fileMessage( message, prefix, time );
			break;
		}

		case Logger::stream_t::CONSOLE:
		{
			consoleMessage( message, prefix, time );
			break;
		}

		case Logger::stream_t::BOTH:
		{
			consoleMessage( message, prefix, time );
			fileMessage( message, prefix, time );
			break;
		}
		}
	}

	void Logger::consoleMessage( const std::string& message, std::string &prefix, std::time_t& time )
	{
		std::cout << std::ctime( &time );
		std::cout << prefix << ' ';
		std::cout << message << "\n\n";
	}

	void Logger::fileMessage( const std::string& message, std::string &prefix, std::time_t& time )
	{
		std::ofstream file( "data/log/log.txt", std::ios::app );

		file << std::ctime( &time );
		file << prefix << ' ';
		file << message << "\n\n";
	}

	void Logger::setPrefix( Logger::type_t type, std::string &prefix )
	{
		switch ( type )
		{

		case Logger::type_t::ERROR:
		{
			prefix = constants::logger::PREFIX_ERROR;
			break;
		}


		case Logger::type_t::INFO:
		{
			prefix = constants::logger::PREFIX_INFO;
			break;
		}

		case Logger::type_t::SUGGESTION:
		{
			prefix = constants::logger::PREFIX_SUGGESTION;
			break;
		}

		case Logger::type_t::WARNING:
		{
			prefix = constants::logger::PREFIX_WARNING;
			break;
		}
		}
	}
}

