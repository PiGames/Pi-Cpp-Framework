#pragma once

#include <SFML/Graphics.hpp>
#include "engine/entity/Entity.hpp"

namespace mc
{
	class Player final : public pi::Entity
	{
	public:
		enum direction_t
		{
			UP,
			LEFT,
			RIGHT,
			DOWN
		};

		Player( const sf::Texture& texture, const std::string& name = "<unnamed Player>", const sf::Vector2f& position = { 0, 0 }, float speed = 1.f );
		~Player() = default;

		void Move( Player::direction_t direction, sf::View* view );
		void Update( sf::RenderWindow& window );

		sf::Vector2f GetPosition() const
		{
			return this->position;
		}
		const sf::Texture* GetTexture() const
		{
			return &texture;
		}

	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Vector2f position;
		float speed;
	};
}