#include "EventManager.hpp"

namespace mv
{
	EventManager::EventManager( sf::RenderWindow *win )
		:window(win)
	{
	}

	void EventManager::checkEvent(sf::Event & event)
	{
		while (window-> pollEvent(event))
		{
			switch (event.type)
			{

			//Example: 

			/*case sf::Event::Closed:
			{
				window->close();
				break;
			}*/

			/*there you can add new case*/
			}
		}
	}
}