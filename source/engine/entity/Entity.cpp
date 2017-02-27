#include "Entity.hpp"

namespace pi
{
	Entity::Entity( const std::string& name ) :
		name( name )
	{
	}
	void Entity::Update( float deltaTime )
	{
	}


	void Entity::draw( sf::RenderTarget& target, sf::RenderStates states_t ) const
	{
	}
}

