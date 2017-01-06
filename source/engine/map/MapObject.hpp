#pragma once

#include "SFML/System/Vector2.hpp"
#include "engine/entity/Entity.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "CollidableObject.hpp"
#include <vector>

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

	protected:

		//position (in px)
		sf::Vector2f position; 

		sf::Sprite object;
	};
}
