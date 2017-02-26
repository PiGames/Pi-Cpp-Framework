// Created by: Condzi
#pragma once

#include <vector>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include "engine/RenderSettings.hpp"
#include "engine/Logger.hpp"
#include "engine/map/MapManager.hpp"

namespace pi
{
	class Renderer final
	{
	private:
		static void updateMapVerticies();
		static void drawMap();

	public:
		Renderer() = delete;

		static void Init();
		static void SetMapTexture( std::shared_ptr<sf::Texture> texture );
		static void SetWindow( sf::RenderWindow* win );

		static void Update();

		static void Render( const sf::Color& clearColor = sf::Color::Black );

	private:
		/* static std::shared_ptr<UI> ui; ? */
		static std::shared_ptr<sf::Texture> mapTexture;
		static sf::RenderWindow* window;

		static std::vector<sf::Vertex> mapVerticies;
		/* static std::shared_ptr<std::vector<Entity>> player ? */
	};
}
