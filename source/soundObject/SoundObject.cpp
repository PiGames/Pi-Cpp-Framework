#include "SoundObject.hpp"
#include <iostream>

namespace pi
{
	bool SoundObject::EmplaceSound( const std::string & name )
	{
		if ( sounds.find( name ) != sounds.end() )
		{
			Logger::Log( constants::error::soundObject::ALREADY_EXIST, Logger::CONSOLE, Logger::WARNING );
			return false;
		}

		sf::SoundBuffer soundBuffer;
		if ( !soundBuffer.loadFromFile( "data/sounds/" + name ) )
		{
			return false;
		}

		sf::Sound sound;
		soundSource.push_back( std::pair<sf::Sound, sf::SoundBuffer>( sound, soundBuffer ) );
		soundSource.back().first.setBuffer( soundSource.back().second );
		sounds.emplace( std::pair<std::string, int>( name, sounds.size() ) );
		return true;
	}

	int8_t SoundObject::GetNumberOfSound( const std::string & name )
	{
		auto itr = sounds.find( name );

		if ( itr == sounds.end() )
		{
			Logger::Log( constants::error::soundObject::DOES_NOT_EXIST_IN_SYSTEM, Logger::CONSOLE, Logger::WARNING );
			return -1;
		}
		else return itr->second;
	}

	bool SoundObject::EraseSound( const std::string & name )
	{
		auto soundIterator = sounds.find( name );

		if ( soundIterator == sounds.end() )
		{
			Logger::Log( constants::error::soundObject::DOES_NOT_EXIST_IN_SYSTEM, Logger::CONSOLE, Logger::WARNING );
			return false;
		}

		int8_t number = soundIterator->second;

		auto soundSourceIterator = soundSource.begin() + soundIterator->second;

		sounds.erase( soundIterator );

		soundSource.erase( soundSourceIterator );

		return true;
	}

	bool SoundObject::PlaySound( const std::string & name )
	{
		if ( !IsSoundExist( name ) )
		{
			Logger::Log( constants::error::soundObject::DOES_NOT_EXIST_IN_SYSTEM, Logger::CONSOLE, Logger::WARNING );
			return false;
		}

		soundSource[sounds[name]].first.play();
		return true;
	}
}

