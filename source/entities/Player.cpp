#include "Player.hpp"

namespace mc
{
	Player::Player(const sf::Texture& texture, const std::string& name = "<unnamed Player>", const sf::Vector2f& position = { 0,0 }, float speed = 1.f)
	{
		this->name = name;
		this->position = position;
		this->speed = speed;
		this->texture = texture;

		this->sprite.setTexture(this->texture);
		this->sprite.setPosition(this->position);
	}


	void Player::move(Rotation rotation)
	{
		switch (rotation)
		{
		case Rotation::UP:
			this->position.y += this->speed;
			break;
		case Rotation::LEFT:
			this->position.x -= this->speed;
			break;
		case Rotation::RIGHT:
			this->position.x += this->speed;
			break;
		case Rotation::DOWN:
			this->position.y -= this->speed;
			break;
		}
		this->sprite.setPosition(this->position);
	}
}