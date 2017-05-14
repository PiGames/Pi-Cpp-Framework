#pragma once

#include <map>
#include <vector>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "logger/Logger.hpp"
#include "Config.hpp"

namespace pi
{
	//SoundObject class
	//It is designed to administer short sounds
	class SoundObject
	{
	public:
	protected:
	private:

		std::map<std::string, int> sounds;

		std::vector<std::pair<sf::Sound, sf::SoundBuffer>> soundSource;

		/* ===Methods=== */

	public:

		//Emplaces new sound
		//returns false if sound with given name exist 
		//or sound isn't in source folder
		//returns true if sound has been added
		bool EmplaceSound(const std::string & name );
		

		//Returns false if sound with given name doesn't exist
		//returns true if sound with given name exist
		bool IsSoundExist(const std::string & name )
		{
			return ( sounds.find( name ) != sounds.end() );
		}

		//Returns number of sound with given name
		//returns -1 value if sound doesn't exist
		int8_t GetNumberOfSound(const std::string & name );

		//Erase sound with given name
		//returns false if sound doesn't exist
		//returns true if sound has been removed
		bool EraseSound(const std::string & name );

		//Plays sound with given name
		//returns false if sound doesn't exist
		//returns true if sound is being played succesfully
		bool PlaySound(const std::string & name );

	protected:
	private:
	};
}