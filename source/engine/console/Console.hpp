#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>
#include <vector>
#include <string>
#include <functional>


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

	class Console final
	{
	public:
		Console();
		Console(sf::RenderWindow&);
		~Console() = default;

		Console& operator =(const Console&) = delete;
		Console(const Console&) = delete;

		void setWindow(sf::RenderWindow&);
		void setTexture(const sf::Texture&);
		void setFillColor(const sf::Color&);
		void setOutlineColor(const sf::Color&);

		void setTextColor(const sf::Color&);
		void setTextFont(sf::Font&);
		void setTextSize(const unsigned&);
		void setTextSizeInLine(const unsigned&);

		void addCommand(Command&);

		void run();
		void key(sf::Event&);
		void write(sf::Event&);
		void log(const std::string&);
		
		void update();

	private:
		sf::RectangleShape shape;
		sf::RenderWindow* window;
		sf::Text text, input;
		std::array <std::string, constants::console::DEAFULT_NUMBER_OF_LINES> line;
		std::vector <Command> commands;
		unsigned numberOfLines, textSizeInLine;
		bool isOpen;

		inline void commandInduction(std::string);
	};
}