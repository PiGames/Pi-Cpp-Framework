#include "Player.hpp"

namespace pg
{
	void Player::SetUpComponents()
	{
		auto playerController = this->AddComponent<PlayerControllerComponent>();
		auto position = this->AddComponent<PositionComponent>();
		auto velocity = this->AddComponent<VelocityComponent>();
		auto tag = this->AddComponent<TagComponent>();

		playerController->left = movementKey_t( sf::Keyboard::A, { -100.0f, 0.0f } );
		playerController->right = movementKey_t( sf::Keyboard::D, { 100.0f, 0.0f } );
		playerController->jump = movementKey_t( sf::Keyboard::Space, { 0.0f, -250.0f } );

		*position = sf::Vector2f( 0.0f, 0.0f );
		*velocity = sf::Vector2f( 0.0f, 0.0f );

		*tag = entityID_t::PLAYER;
	}

	void Player::Update()
	{
		auto playerController = this->GetComponent<PlayerControllerComponent>();
		auto position = this->GetComponent<PositionComponent>();
		auto velocity = this->GetComponent<VelocityComponent>();
		auto drawable = this->GetComponent<DrawableComponent>();

		if ( sf::Keyboard::isKeyPressed( playerController->left.key ) )
			playerController->pendingForce += playerController->left.force;
		if ( sf::Keyboard::isKeyPressed( playerController->right.key ) )
			playerController->pendingForce += playerController->right.force;
		if ( sf::Keyboard::isKeyPressed( playerController->jump.key ) && !playerController->lockJump )
		{
			playerController->pendingForce += playerController->jump.force;
			playerController->lockJump = true;
		}

		velocity->pendingForce += playerController->pendingForce;
		playerController->pendingForce = sf::Vector2f();

		if ( drawable )
			drawable->sprites[0].setPosition( *position );
	}
}