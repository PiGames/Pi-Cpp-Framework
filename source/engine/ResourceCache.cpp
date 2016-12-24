#include "ResourceCache.hpp"


namespace pi
{
	std::unique_ptr<sf::Texture> TextureCache::handleError()
	{
		auto texture = std::make_unique<sf::Texture>();
		sf::Image image;

		image.create(32u, 32u, this->fallbackColor);
		texture->loadFromImage(image);

		return std::move(texture);
	}

	TextureCache::TextureCache()
	{
		this->fallbackColor = sf::Color::Magenta;
	}

	sf::Color TextureCache::getFallbackColor()
	{
		return this->fallbackColor;
	}

	void TextureCache::setFallbackColor(sf::Color color)
	{
		this->fallbackColor = color;
	}

	sf::Texture& TextureCache::get(const std::string & path)
	{
		if (path.empty())
			return *handleError();

		// Try to find texture in cache
		{
			auto result = this->resources.find(path);

			if (result != this->resources.end())
				return *result->second;
		}

		// If cannot find it - trying to load it
		{
			auto texture = std::make_unique<sf::Texture>();

			if (!texture->loadFromFile(path))
				return *handleError();

			this->resources[path] = std::move(texture);

			return *this->resources[path];
		}
	}
}
