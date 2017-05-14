#pragma once

#include <cassert>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include "components/Drawable.hpp"
#include "ecs/ComponentBlock.hpp"
#include "logger/Logger.hpp"
#include "map/MapManager.hpp"

namespace pg
{
	/*
	===============================================================================
	Created by: Condzi
		Renderer uses a component blocks of DrawableCompoents. You should get them
		using Reserve method in ecs::SystemBase. Pass them directly here. Before
		rendering make sure that you passed map texture.

	===============================================================================
	*/
	class Renderer final
	{
	public:
		Renderer( sf::RenderWindow& win ) :
			window( win )
		{}

		void SetComponentBlocks( std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>>& components )
		{
			this->drawableBlocks = components;
		}
		void SetMapTextureSheet( std::weak_ptr<sf::Texture> texture )
		{
			if ( texture.expired() )
				pi::Logger::Log( "Assiging expired texture to Renderer", pi::Logger::CONSOLE, pi::Logger::ERROR );
			this->mapTextureSheet = texture;
		}

		void GenerateMapTexture( pi::MapManager& mapManager );

		void ClearWindow( sf::Color clearColor = sf::Color::Black ) const
		{
			this->window.clear( clearColor );
		}
		void Render();
		void Display() const
		{
			this->window.display();
		}
		void ClearData()
		{
			this->drawableBlocks.clear();
		}

	private:
		std::vector<std::reference_wrapper<ecs::internal::componentBlock_t>> drawableBlocks;
		std::weak_ptr<sf::Texture> mapTextureSheet;
		sf::RenderTexture finalMapTexture;
		sf::Sprite mapSprite;
		sf::RenderWindow& window;

		std::pair<int8_t, int8_t> getDrawLayersInterval( const std::vector<std::shared_ptr<DrawableComponent>>& drawables );
	};
}