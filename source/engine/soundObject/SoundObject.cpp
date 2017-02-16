#include "SoundObject.hpp"

namespace pi
{
	bool SoundObject::emplaceSound(std::string name)
	{
		if (sounds.find(name) != sounds.end())
		{
			Logger::Log(constants::error::soundSystem::ALREADY_EXIST, Logger::MessageType::Warning, Logger::OutputType::Both);
			return false;
		}

		sf::SoundBuffer soundBuffer;
		if (!soundBuffer.loadFromFile(constants::soundSystem::SOUND_PATH + name + constants::soundSystem::SOUND_FORMAT))
		{
			Logger::Log(constants::error::soundSystem::DOES_NOT_EXIST_IN_FOLDER, Logger::MessageType::Warning, Logger::OutputType::Both);
			return false;
		}

		sf::Sound sound;
		sound.setBuffer(soundBuffer);

		soundSource.push_back(std::pair<sf::Sound, sf::SoundBuffer>(sound, soundBuffer));

		sounds.emplace(name, sounds.size());

		return true;
	}

	bool SoundObject::isSoundExist(std::string name)
	{
		return (sounds.find(name) != sounds.end());
	}

	int8_t SoundObject::getNumberOfSound(std::string name)
	{
		auto itr = sounds.find(name);

		if (itr == sounds.end())
		{
			Logger::Log(constants::error::soundSystem::DOES_NOT_EXIST_IN_SYSTEM, Logger::MessageType::Warning, Logger::OutputType::Both);
			return -1;
		}
		else return itr->second;
	}

	bool SoundObject::eraseSound(std::string name)
	{
		auto soundIterator = sounds.find(name);

		if (soundIterator == sounds.end())
		{
			Logger::Log(constants::error::soundSystem::DOES_NOT_EXIST_IN_SYSTEM, Logger::MessageType::Warning, Logger::OutputType::Both);
			return false;
		}

		int8_t number = soundIterator->second;

		auto soundSourceIterator = soundSource.begin() + soundIterator->second;

		sounds.erase(soundIterator);

		soundSource.erase(soundSourceIterator);

		return true;
	}

	bool SoundObject::playSound(std::string name)
	{
		if (!isSoundExist(name))
			return false;

		soundSource[sounds[name]].first.play();

		return true;
	}
}

