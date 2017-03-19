// Created by: Condzi
#pragma once

#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include "engine/RenderSettings.hpp"
#include "engine/Logger.hpp"
#include "engine/map/MapManager.hpp"
#include "engine/Types.hpp"


namespace pi
{
	class Renderer final
	{
	public:
		Renderer() = delete;

		static void SetMapTexture( std::weak_ptr<sf::Texture> texture )
		{
			Renderer::mapTexture = texture;
		}
		static void SetWindow( sf::RenderWindow* win )
		{
			Renderer::window = win;
		}

		static void Init()
		{
			Logger::Log( "Initialiing Renderer..." );
		}

		static void Update()
		{
			Renderer::updateMapVerticies();
		}

		static void Render( const sf::Color& clearColor = sf::Color::Black );

	private:
		/* static std::shared_ptr<UI> ui; ? */
		static std::weak_ptr<sf::Texture> mapTexture;
		static sf::RenderWindow* window;

		static std::vector<sf::Vertex> mapVerticies;
		/* static std::shared_ptr<std::vector<Entity>> player ? */

		static void updateMapVerticies();
		static void drawMap();
	};
}
