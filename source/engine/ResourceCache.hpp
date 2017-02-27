// Created by: Condzi
#pragma once

#include <array>
#include <string>
#include <unordered_map>
#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Logger.hpp"

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
		virtual T& Get( const std::string& path )
		{
			if ( path.empty() )
			{
				Logger::Log( constants::error::resourceCache::CANNOT_GET_NO_PATH, Logger::MessageType::Error );

				return handleError();
			}

			// Try to find T in cache
			{
				auto result = this->resources.find( path );

				if ( result != this->resources.end() )
					return *result->second;
			}

			// If cannot find it - trying to load it
			{
				auto resource = std::make_unique<T>();

				if ( !resource->loadFromFile( path ) )
				{
					Logger::Log( constants::error::resourceCache::CANNOT_GET_CANNOT_LOAD + path, pi::Logger::MessageType::Error );

					return handleError();
				}

				this->resources[path] = std::move( resource );

				return *this->resources[path];
			}
		}
	protected:
		// Returns special resource version if error occures in get method
		virtual T& handleError()
		{
			return error_resource;
		}

		std::unordered_map<std::string, std::unique_ptr<T>> resources;
		T error_resource;
	};

	template<class T>
	inline ResourceCache<T>::ResourceCache()
	{
	}

	// Returns 32x32 texture if cannot load correctly 
	class TextureCache final : public ResourceCache<sf::Texture>
	{
	public:
		TextureCache();

		// Sets Fallback Color
		sf::Color GetFallbackColor()
		{
			return this->fallbackColor;
		}
		// Returns Fallback Color
		void SetFallbackColor( const sf::Color& color )
		{
			this->fallbackColor = color;
		}

	private:
		sf::Color fallbackColor;

		sf::Texture& handleError()
		{
			return error_resource;
		}

	};

	// Returns DejaVuSans if cannot lad correctly
	class FontCache final : public ResourceCache<sf::Font>
	{
	public:
		FontCache();
	private:
		sf::Font& handleError()
		{
			return error_resource;
		}
	};
}