// Created by: mvxxx
#pragma once

#include "engine/map/MapObject.hpp"
#include "engine/ResourceCache.hpp"
#include "engine/Config.hpp"

namespace mc
{
	//Mouse class
	//Represents mouse on the scene
	class Mouse : public pi::MapObject
	{
	public:
		Mouse( std::weak_ptr<sf::Texture> texture, const std::string& name = "<unnamed Entity>", const sf::Vector2f& pos = { 0, 0 } );

		enum class type_t
		{
			SIMPLE = 0
		};

		void ProcessEvent( const sf::Event& event, const sf::RenderWindow& window );

		void SetCursor( Mouse::type_t type );
	private:
	};
}