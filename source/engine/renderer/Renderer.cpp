#include "Renderer.hpp"

namespace pi
{
	/* static std::shared_ptr<UI> ui; ? */
	/* static std::shared_ptr<Player> player ? */
	std::shared_ptr<sf::Texture> Renderer::mapTexture;
	sf::RenderWindow* Renderer::window;

	std::vector<sf::Vertex> Renderer::mapVerticies;


	void Renderer::updateMapVerticies()
	{
		static bool errorMessageLogged = false;
		if (!mapTexture && !errorMessageLogged)
		{
			errorMessageLogged = true;
			Logger::Log("mapTexture is not set, Renderer cannot update map verticies", pi::Logger::MessageType::Error, pi::Logger::OutputType::Console);
		}
		if(errorMessageLogged)
			return;
		errorMessageLogged = false;

		sf::Vector2i mapSize = MapManager::GetUnitWorldSize();
		const auto& tiles = MapManager::GetSurface();

		Renderer::mapVerticies.clear();
		// * 4 because 4 verticies = quad
		Renderer::mapVerticies.resize(mapSize.x * mapSize.y * 4);

		for (int32_t x = 0; x < mapSize.x; x++)
		{
			for (int32_t y = 0; y < mapSize.y; y++)
			{
				uint32_t tileID = tiles[x + y * mapSize.x].getID(); 

				if (tileID * renderSettings::MAP_CELL_TEXTURE_SIZE.x > Renderer::mapTexture->getSize().x ||
					renderSettings::MAP_CELL_TEXTURE_SIZE.y > Renderer::mapTexture->getSize().y)
				{
					Logger::Log(
						"Invalid map texture size! Requested/max: x: " + std::to_string(tileID * renderSettings::MAP_CELL_TEXTURE_SIZE.x) + " / " + std::to_string(Renderer::mapTexture->getSize().x) + ", y: " + std::to_string(renderSettings::MAP_CELL_TEXTURE_SIZE.y) + " / " + std::to_string(Renderer::mapTexture->getSize().y), 
						Logger::MessageType::Error, Logger::OutputType::Both);
					return;
				}

				sf::IntRect cuttingArea(tileID * renderSettings::MAP_CELL_TEXTURE_SIZE.x, 0, renderSettings::MAP_CELL_TEXTURE_SIZE.x, renderSettings::MAP_CELL_TEXTURE_SIZE.y);

				sf::Vertex* quad = &mapVerticies[(x + y * mapSize.y) * 4];
				
				quad[0].position = sf::Vector2f(x * mapSize.x + renderSettings::RENDER_OFFSET.x, y * mapSize.y + renderSettings::RENDER_OFFSET.y);
				quad[1].position = sf::Vector2f((x + 1) * mapSize.x + renderSettings::RENDER_OFFSET.x, y * mapSize.y + renderSettings::RENDER_OFFSET.y);
				quad[2].position = sf::Vector2f((x + 1) * mapSize.x + renderSettings::RENDER_OFFSET.x, (y + 1) * mapSize.y + renderSettings::RENDER_OFFSET.y);
				quad[3].position = sf::Vector2f(x * mapSize.x + renderSettings::RENDER_OFFSET.x, (y + 1) * mapSize.y + renderSettings::RENDER_OFFSET.y);

				quad[0].texCoords = sf::Vector2f(cuttingArea.left, 0);
				quad[1].texCoords = sf::Vector2f(cuttingArea.left + cuttingArea.width, 0);
				quad[2].texCoords = sf::Vector2f(cuttingArea.left + cuttingArea.width, cuttingArea.top + cuttingArea.height);
				quad[3].texCoords = sf::Vector2f(cuttingArea.left, cuttingArea.top + cuttingArea.height);
			}
		}
	}

	void Renderer::drawMap()
	{
		static bool errorMessageLogged = false;
		if (!Renderer::mapTexture && !errorMessageLogged)
		{
			errorMessageLogged = true;
			Logger::Log("mapTexture is not set, Renderer cannot draw map", pi::Logger::MessageType::Error, pi::Logger::OutputType::Console);
		}
		if (!Renderer::mapVerticies.size() && !errorMessageLogged)
		{
			errorMessageLogged = true;
			Logger::Log("no mapVerticies (Map not generated?), Renderer cannot draw map", pi::Logger::MessageType::Error, pi::Logger::OutputType::Console);
		}
		if(errorMessageLogged)
			return;
		errorMessageLogged = false;


		sf::RenderStates mapRenderStates = sf::RenderStates::Default;
		sf::Transform mapTransform;

		mapTransform.scale(renderSettings::RENDER_SCALE.x, renderSettings::RENDER_SCALE.y);
		// Sad because calling .get() :(
		mapRenderStates.texture = Renderer::mapTexture.get();
		mapRenderStates.transform = mapTransform;

		Renderer::window->draw(&Renderer::mapVerticies[0], Renderer::mapVerticies.size(), sf::PrimitiveType::Quads, mapRenderStates);
	}

	void Renderer::Init()
	{
		Logger::Log("Initialiing Renderer...");
	}

	void Renderer::SetMapTexture(std::shared_ptr<sf::Texture> texture)
	{
		Renderer::mapTexture = texture;
	}

	void Renderer::SetWindow(sf::RenderWindow* win)
	{
		Renderer::window = win;
	}

	void Renderer::Update()
	{
		Renderer::updateMapVerticies();
	}

	void Renderer::Render(const sf::Color& clearColor)
	{
		Renderer::window->clear(clearColor);

		Renderer::drawMap();

		Renderer::window->display();
	}
}