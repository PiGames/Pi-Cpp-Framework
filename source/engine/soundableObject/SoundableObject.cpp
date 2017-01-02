#include "SoundableObject.hpp"

namespace pi
{
	bool pi::SoundableObject::emplace_sound(std::string name)
	{
		if (sounds.find(name) != sounds.end())
			return false;

		sf::SoundBuffer soundBuffer;
		if (!soundBuffer.loadFromFile(constants::SoundSystem::SOUND_PATH+name+constants::SoundSystem::SOUND_FORMAT))
			return false;

		sf::Sound sound;
		sound.setBuffer(soundBuffer);

		soundSource.push_back(std::pair<sf::Sound, sf::SoundBuffer>(sound, soundBuffer));

		sounds.emplace(name,sounds.size());
		
		return true;
	}

	bool SoundableObject::isSoundExist(std::string name)
	{
		return (sounds.find(name) != sounds.end());
	}

	uint8_t SoundableObject::getNumberOfSound(std::string name)
	{
		auto itr = sounds.find(name);
		
		if (itr == sounds.end()) return -1;
		else return itr->second;
	}

	bool SoundableObject::erase_sound(std::string name)
	{
		auto soundIterator = sounds.find(name);
		if (soundIterator == sounds.end()) return false;
		uint8_t number = soundIterator->second;

		auto soundSourceIterator = soundSource.begin() + soundIterator->second;

		sounds.erase(soundIterator);

		soundSource.erase(soundSourceIterator);

		return true;
	}
}

