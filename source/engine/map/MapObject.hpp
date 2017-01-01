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
	class MapObject : public Entity, public CollidableObject
	{
	protected:

		//Draws object
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		MapObject(const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0,0 }, std::vector<sf::Vector2i> uPos = { sf::Vector2i(0,0) },bool collidableFlag=false);
		
		//Returns real position (in px)
		sf::Vector2f& getPosition();

		//Returns vector of unit position (in unit system)
		std::vector<sf::Vector2i>& getUnitPosition();

		

	protected:

		//position (in px)
		sf::Vector2f position; 
		
		//vector of unit position (in unit system)
		std::vector<sf::Vector2i> unitPosition;

		sf::Sprite object;
	};
}
