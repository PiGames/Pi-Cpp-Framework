#pragma once

#include <SFML/Audio/Music.hpp>

#include "States.hpp"
#include "engine/game/State.hpp"
#include "engine/ResourceCache.hpp"
#include "engine/ui/UI.hpp"

namespace mc
{
	class MenuState final :
		public pi::State
	{
	public:
		MenuState();
		~MenuState() = default;

		short run();
	private:
		// MenuState class variables
		pi::ui::UI ui;
		pi::ui::Button *playButton, *exitButton;
		sf::Texture backgroundTexture, playTexture, exitTexture;
		sf::RectangleShape background;
		bool isInitialized, isPlay, isExit;

		// Initialize class
		void initialize();

		pi::FontCache fonts;
		sf::Music music;
	};
}