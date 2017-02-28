#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

/*
===---===
If you want to extend event control you need to modife checkControl() method:
-Add new case like this:
case sf::Event::MouseLeft:
{
do sth...
break;
}
===---===
*/

namespace mv
{
	class EventManager
	{

	public:

		EventManager( sf::RenderWindow *win );
		void checkEvent( sf::Event &event );

	private:

		sf::RenderWindow* window;
	};
}