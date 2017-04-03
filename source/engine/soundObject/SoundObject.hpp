// Created by: mvxxx
#pragma once

#include <map>
#include <vector>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "engine/Config.hpp"
#include "engine/Logger.hpp"

namespace pi
{
	//SoundObject class
	//It is designed to administer short sounds
	class SoundObject
	{
	public:

		//Emplaces new sound
		//returns false if sound with given name exist 
		//or sound isn't in source folder
		//returns true if sound has been added
		bool EmplaceSound( std::string & name );

		//Returns false if sound with given name doesn't exist
		//returns true if sound with given name exist
		bool IsSoundExist( std::string & name )
		{
			return ( sounds.find( name ) != sounds.end() );
		}

		//Returns number of sound with given name
		//returns -1 value if sound doesn't exist
		int8_t GetNumberOfSound( std::string & name );

		//Erase sound with given name
		//returns false if sound doesn't exist
		//returns true if sound has been removed
		bool EraseSound( std::string & name );

		//Plays sound with given name
		//returns false if sound doesn't exist
		//returns true if sound is being played succesfully
		bool PlaySound( std::string & name );

	private:

		std::map<std::string, int8_t> sounds;

		std::vector<std::pair<sf::Sound, sf::SoundBuffer>> soundSource;
	};
}