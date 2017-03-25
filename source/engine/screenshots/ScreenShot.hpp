#pragma once
#include "engine/Config.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <sstream>
#include <ctime>

namespace pi 
{
	class ScreenShot 
	{
		private:
			ScreenShot(){}
			ScreenShot(const ScreenShot&);
			ScreenShot& operator =(const ScreenShot&);
		public:
			static ScreenShot* getInstance()
			{
				static ScreenShot instance;
				return &instance;
			}

			void checkKey(const sf::RenderWindow&);
			bool take(const sf::RenderWindow&);
	};
}