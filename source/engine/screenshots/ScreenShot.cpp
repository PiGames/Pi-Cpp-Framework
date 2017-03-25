#include "engine/screenshots/ScreenShot.hpp"

namespace pi 
{
	void ScreenShot::checkKey(const sf::RenderWindow& window)
	{
		if ( sf::Keyboard::isKeyPressed(constants::screenShot::SCREENSHOT_BUTTON) )
		{
			take(window);
		}
	}

	bool ScreenShot::take(const sf::RenderWindow& window)
	{
		sf::Texture texture;
		texture.create(window.getSize().x, window.getSize().y);
		texture.update(window);
		sf::Image ss = texture.copyToImage();
		
		std::stringstream filename;

		filename << "data/screenshots/screenshot_" << time(0) << ".png";
		if (ss.saveToFile(filename.str())) {
			return true;
		} else {
			return false;
		}
	}
}