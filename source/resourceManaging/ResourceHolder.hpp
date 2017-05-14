/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Logger/Logger.hpp"
#include "ResourceWrapper.hpp"

namespace pi
{
	using textureResource_t = ResourceWrapper<sf::Texture>;
	using fontResource_t = ResourceWrapper<sf::Font>;
	using uiTextResource_t = ResourceWrapper<sf::Text>;

	/*
	===============================================================================
	Created by: Condzi
		Resource Holder struct is created for resource managing. To add resources
		use public vectors. For deleting use specified DeleteAll... methods. To get
		resource, use Get... methods.

	===============================================================================
	*/
	struct ResourceHolder final
	{
		ResourceHolder()
		{}

		std::vector<std::shared_ptr<textureResource_t>> textures;
		std::vector<std::shared_ptr<uiTextResource_t>> uiTexts;
		std::vector<std::shared_ptr<fontResource_t>> fonts;

		std::weak_ptr<textureResource_t> GetTexture( uint8_t id );
		std::weak_ptr<uiTextResource_t> GetText( uint8_t id );
		std::weak_ptr<fontResource_t> GetFont( uint8_t id );

		void DeleteAllResources();
		void DeleteAllResourcesByPriority( uint8_t priority );
		void DeleteAllResourcesByID( uint8_t id );
	};
}