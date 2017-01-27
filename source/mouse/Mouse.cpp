#include "Mouse.hpp"

namespace mc
{
	Mouse::Mouse(const std::string & name, const sf::Vector2f & pos)
		:MapObject(name, pos)
	{
	}

	void Mouse::setCursor(Mouse::TYPE type)
	{
	}
}

