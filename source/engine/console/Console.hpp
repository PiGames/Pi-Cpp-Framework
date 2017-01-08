#pragma once

#include <memory>
#include <array>
#include <vector>
#include <string>
#include <functional>

#include <SFML/Graphics.hpp>

#include "engine/Config.hpp"

namespace pi
{
	class Console;
	struct Command;

	struct Command
	{
		std::function<void(Console*, Command*)> function;
		std::string induction;
		std::vector<std::string> args;
	};

	class Console final :
		public sf::Drawable
	{
	private:
		void draw(sf::RenderTarget&, sf::RenderStates) const;

	public:
		Console();
		Console(const sf::Vector2u&);
		~Console() = default;

		Console& operator =(const Console&) = delete;
		Console(const Console&) = delete;

		// CONSOLE VIEV FUNCTIONS START
		// Set window handle
		// YOU MUST USE IT IF YOU DIDN'T USE THIS CONSTRUCTOR -> Console(sf::RenderWindow&);
		void setWindowSize(const sf::Vector2u&);
		// Set console fill color
		void setFillColor(const sf::Color&);
		// Set console outline color
		void setOutlineColor(const sf::Color&);
		// CONSOLE VIEV FUNCTIONS END

		// TEXT SECTION START
		// Set text color in all lines
		void setTextColor(const sf::Color&);
		// Set text font in all lines
		void setTextFont(sf::Font&);
		// Set text size in all lines
		void setTextSize(const unsigned);
		// Set max number of characters in all lines
		void setTextSizeInLine(const unsigned);
		// TEXT SECTION END

		// CONSOLE FUNCTIONS START
		// Add command to commands vector
		void addCommand(Command&);
		// On-Off console
		void toggle();
		// Shows console
		void show();
		// Hides console
		void hide();
		// Checks whether user click baskskape or enter
		void key(sf::Event&);
		// Checks what user write on keyboard
		void write(sf::Event&);
		// Write logs in console
		void log(const std::string&);
		// CONSOLE FUNCTIONS END

	private:
		sf::RectangleShape shape;
		sf::Vector2u windowSize;
		sf::Text text, input;
		std::array <std::string, constants::console::DEAFULT_NUMBER_OF_LINES> line;
		std::vector <Command> commands;
		unsigned numberOfLines, textSizeInLine;
		bool isOpen;

		inline void commandInduction(std::string);
	};
}