#pragma once

#include <string>
#include <unordered_map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>

namespace pi
{
	// Template for Resource Cache - use it to store your resources 
	template<class T>
	class ResourceCache
	{
	public:
		ResourceCache();
		virtual ~ResourceCache() = default;
	
		// Returns reference to given resource
		virtual T& get(const std::string& key) = 0;

	protected:
		// Returns special resource version if error occures in get method
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

		// Sets Fallback Color
		sf::Color getFallbackColor();
		// Returns Fallback Color
		void setFallbackColor(sf::Color color);

		sf::Texture& get(const std::string& path);
	
	private:
		sf::Color fallbackColor;
	};
}