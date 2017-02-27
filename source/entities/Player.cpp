#include "Player.hpp"

namespace mc
{
	Player::Player( const sf::Texture& texture, const std::string& name, const sf::Vector2f& position, float speed )
	{
		this->name = name;
		this->position = position;
		this->speed = speed;
		this->texture = texture;

		this->sprite.setTexture( this->texture );
		this->sprite.setPosition( this->position );
	}


	void Player::Move( Player::direction_t direction )
	{
		switch ( direction )
		{
		case Player::direction_t::UP:
			this->position.y -= this->speed;
			break;
		case Player::direction_t::LEFT:
			this->position.x -= this->speed;
			break;
		case Player::direction_t::RIGHT:
			this->position.x += this->speed;
			break;
		case Player::direction_t::DOWN:
			this->position.y += this->speed;
			break;
		}
		this->sprite.setPosition( this->position );
	}

	void Player::Update( sf::RenderWindow& window )
	{
		window.draw( this->sprite );
	}
}