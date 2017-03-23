// Created by: mvxxx
#pragma once

#include <vector>
#include <memory>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "engine/Config.hpp"
#include "CollidableObject.hpp"
#include "engine/entity/Entity.hpp"
#include "engine/Math.hpp"

namespace pi
{
	//MapObject class
	//Represents a drawable object which is on the map
	//It can be static/movable object
	//If you want to create map object, firstly you need to create static/movable (which inherits from it)
	class MapObject : public Entity
	{
	public:
		MapObject( std::weak_ptr<sf::Texture> texture, const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0, 0 } );

		//Returns real position (in px)
		sf::Vector2f& GetPosition()
		{
			return this->position;
		}

		//Returns width of object (in px)
		float GetWidth() const
		{
			return this->object.getGlobalBounds().width;
		}

		//Returns height of object (in px)
		float GetHeight() const
		{
			return this->object.getGlobalBounds().height;
		}

		//Sets position (in px)
		void SetPosition( const sf::Vector2f& position )
		{
			this->object.setPosition( position );
		}

		//Shift of object
		void Move( sf::Vector2f shift )
		{
			this->object.move( shift );
		}
	protected:
		//position (in px)
		sf::Vector2f position;

		sf::Sprite object;

	private:
		virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const
		{
			target.draw( object, states );
		}
	};
}
