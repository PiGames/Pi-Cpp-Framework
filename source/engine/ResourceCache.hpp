#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

namespace pi
{
	template<class T>
	class ResourceCache
	{
	public:
		ResourceCache();
		virtual ~ResourceCache() = default;
	
		virtual T& get(const std::string& key) = 0;

	protected:
		virtual std::unique_ptr<T> handleError() = 0;

	protected:
		std::unordered_map<std::string, std::unique_ptr<T>> resources;
	};

	template<class T>
	inline ResourceCache<T>::ResourceCache()
	{
	}


	class TextureCache final:
		public ResourceCache<sf::Texture>
	{
	private:
		std::unique_ptr<sf::Texture> handleError();

	public:
		TextureCache();

		sf::Color getFallbackColor();
		void setFallbackColor(sf::Color color);

		sf::Texture& get(const std::string& path);
	
	private:
		sf::Color fallbackColor;
	};
}