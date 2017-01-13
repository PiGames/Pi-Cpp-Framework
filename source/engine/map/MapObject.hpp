#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "CollidableObject.hpp"
#include "engine/entity/Entity.hpp"

namespace pi
{
	class MapObject : public Entity
	{
	protected:

		//Draws object
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		MapObject(const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0,0 });
		
		//Returns real position (in px)
		sf::Vector2f& getPosition();	

		//Returns width of object (in px)
		const float getWidth();

		//Returns height of object (in px)
		const float getHeight();

	protected:

		//position (in px)
		sf::Vector2f position; 

		sf::Sprite object;
	};
}
