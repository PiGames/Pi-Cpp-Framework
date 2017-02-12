#include "Player.hpp"

namespace mc
{
	Player::Player(const sf::Texture& texture, const std::string& name, const sf::Vector2f& position, float speed)
	{
		this->name = name;
		this->position = position;
		this->speed = speed;
		this->texture = texture;

		this->sprite.setTexture(this->texture);
		this->sprite.setPosition(this->position);
	}


	void Player::move(Direction direction)
	{
		switch (direction)
		{
		case Direction::UP:
			this->position.y += this->speed;
			break;
		case Direction::LEFT:
			this->position.x -= this->speed;
			break;
		case Direction::RIGHT:
			this->position.x += this->speed;
			break;
		case Direction::DOWN:
			this->position.y -= this->speed;
			break;
		}
		this->sprite.setPosition(this->position);
	}
}