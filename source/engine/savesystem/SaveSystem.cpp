#include "SaveSystem.hpp"

namespace pi
{
	SaveSystem::SaveSystem()
	{
	}

	std::string SaveSystem::GetVariable( const std::string& name ) const
	{
		auto find = this->variables.find( name );

		if ( find == this->variables.end() )
			return "@error";

		return this->variables.at( name );
	}

	bool SaveSystem::UpdateVariable( const std::string& name, const std::string& value )
	{
		auto find = this->variables.find( name );

		if ( find == this->variables.end() )
		{
			Logger::Log( constants::error::saveSystem::CANNOT_UPDATE_CANNOT_FOUND + name, Logger::MessageType::Error );

			return false;
		}

		this->variables[name] = value;

		return true;
	}

	bool SaveSystem::SaveToFile( const std::string& path )
	{
		std::ofstream file;

		file.open( path, std::ios::out );
		if ( !file.good() )
		{
			Logger::Log( constants::error::saveSystem::CANNOT_SAVE + path, Logger::MessageType::Error );

			file.close();

			return false;
		}


		for ( auto& var : this->variables )
		{
			file << var.first << " = " << var.second << "\n";
		}

		file.close();

		return true;
	}

	bool SaveSystem::checkComment( const std::string& buffer )
	{
		if ( buffer[0] == constants::saveSystem::COMMENT )
			return true;

		return false;
	}

	bool SaveSystem::load( const std::string & path, std::vector<std::string>& raw )
	{
		std::ifstream file;
		std::string temp;

		file.open( path );
		if ( !file.is_open() )
		{
			Logger::Log( constants::error::saveSystem::CANNOT_OPEN + path, Logger::MessageType::Error );

			return false;
		}

		while ( !file.eof() )
		{
			std::getline( file, temp );

			raw.push_back( temp );
		}

		file.close();

		return true;
	}

	void SaveSystem::parse( std::vector<std::string>& raw )
	{
		for ( auto& line : raw )
		{
			if ( checkComment( line ) )
				continue;

			removeSpaces( line );
			split( line );
		}
	}

	void SaveSystem::removeSpaces( std::string& line )
	{
		line.erase( std::remove( line.begin(), line.end(), ' ' ), line.end() );
	}

	void SaveSystem::split( const std::string& line )
	{
		auto equalPosition = line.find( '=' );
		std::string name;
		std::string value;

		if ( equalPosition == line.npos )
			return;

		name = line.substr( 0, equalPosition );
		value = line.substr( equalPosition + 1, line.size() );

		this->variables[name] = value;
	}

	bool SaveSystem::LoadFromFile( const std::string& file )
	{
		std::vector<std::string> raw;

		Clear();

		if ( !load( file, raw ) )
			return false;

		parse( raw );

		return true;
	}
}

