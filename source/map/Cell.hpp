#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Config.hpp"

namespace pi
{
	class Cell
	{
	public:
		Cell( int identifier, const sf::Vector2i& unitPosition );

		int GetID() const
		{
			return this->id;
		}

		sf::Sprite& GetSprite()
		{
			return this->object;
		}

	private:
		const int id;

		sf::Sprite object;
	};
}