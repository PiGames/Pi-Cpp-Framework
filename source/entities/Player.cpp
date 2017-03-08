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


	void Player::Move( Player::direction_t direction, sf::View* view )
	{
		sf::Vector2f move;
		switch ( direction )
		{
		case Player::direction_t::UP:
			move.y -= this->speed;
			break;
		case Player::direction_t::LEFT:
			move.x -= this->speed;
			break;
		case Player::direction_t::RIGHT:
			move.x += this->speed;
			break;
		case Player::direction_t::DOWN:
			move.y += this->speed;
			break;
		}
		this->sprite.move( move );
		view->move( move );
	}

	void Player::Update( sf::RenderWindow& window )
	{
		window.draw( this->sprite );
	}
}