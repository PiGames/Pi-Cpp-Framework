#include "Renderer.hpp"

namespace pg
{
	void Renderer::GenerateMapTexture( pi::MapManager& mapManager )
	{
		auto& mapCells = mapManager.GetCells();

		this->finalMapTexture.clear();
		this->finalMapTexture.create
		(
			mapManager.GetUnitWorldSize().x * constants::cell::CELL_DIMENSIONS.x,
			mapManager.GetUnitWorldSize().y * constants::cell::CELL_DIMENSIONS.y
		);
		for ( auto& cell : mapCells )
		{
			auto& cellSprite = cell.GetSprite();
			cellSprite.setTexture( *this->mapTextureSheet.lock() );
			cellSprite.setTextureRect( sf::IntRect( constants::cell::CELL_DIMENSIONS.x * cell.GetID(), 0, constants::cell::CELL_DIMENSIONS.x, constants::cell::CELL_DIMENSIONS.y ) );

			this->finalMapTexture.draw( cellSprite );
		}

		this->finalMapTexture.display();
		this->mapSprite.setTexture( this->finalMapTexture.getTexture() );
	}

	void Renderer::Render()
	{
		std::vector<std::shared_ptr<DrawableComponent>> drawables;

		for ( ecs::internal::componentBlock_t& block : this->drawableBlocks )
			for ( auto& wrapper : block.data )
				if ( wrapper.ownerEntityID != ecs::UNASSIGNED_ENTITY_ID )
					drawables.push_back( std::static_pointer_cast<DrawableComponent>( wrapper.data ) );

		this->window.draw( this->mapSprite );

		auto drawLayersInterval = this->getDrawLayersInterval( drawables );
		size_t entitiesAlreadyDrawn = 0;
		for (
			int8_t currentLayer = drawLayersInterval.first;
			( currentLayer < drawLayersInterval.second + 1 && entitiesAlreadyDrawn < drawables.size() );
			currentLayer++
			)
		{
			for ( auto drawable : drawables )
				if ( drawable->drawLayer == currentLayer )
				{
					for ( auto& sprite : drawable->sprites )
						this->window.draw( sprite );
					entitiesAlreadyDrawn++;
				}
		}
	}

	std::pair<int8_t, int8_t> Renderer::getDrawLayersInterval( const std::vector<std::shared_ptr<DrawableComponent>>& drawables )
	{
		int8_t min = INT8_MAX, max = INT8_MIN;
		int8_t currentLayer = 0;

		for ( auto drawable : drawables )
		{
			currentLayer = drawable->drawLayer;

			if ( currentLayer > max ) max = currentLayer;
			if ( currentLayer < min ) min = currentLayer;
		}

		return std::pair<int8_t, int8_t>( min, max );
	}
}