#pragma once

#include <SFML/Graphics.hpp>
#include "engine/entity/Entity.hpp"

namespace mc
{
	class Player final : public pi::Entity
	{
	public:
		enum Direction
		{
			UP,
			LEFT,
			RIGHT,
			DOWN
		};

		Player(const sf::Texture& texture, const std::string& name = "<unnamed Player>", const sf::Vector2f& position = { 0,0 }, float speed = 1.f);
		~Player() = default;

		void move(Direction);
		void update(sf::RenderWindow&);

	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2f position;
		float speed;
	};
}