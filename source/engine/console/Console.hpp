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

		void setWindow(sf::RenderWindow&);
		void setTexture(const sf::Texture&);
		void setFillColor(const sf::Color&);
		void setOutlineColor(const sf::Color& outline);

		void setTextColor(const sf::Color&);
		void setTextFont(sf::Font&);
		void setTextSize(unsigned);
		void setTextSizeInLine(unsigned);

		void addCommand(Command&);

		void run();
		void key(sf::Event&);
		void write(sf::Event&);
		void log(const std::string&);
		
		void update();

	private:
		sf::RectangleShape shape;
		sf::RenderWindow* window;
		bool isOpen;

		sf::Text text, input;
		unsigned numberOfLines, textSizeInLine;
		std::array <std::string, constants::console::DEAFULT_NUMBER_OF_LINES> line;
		std::vector <Command> commands;

		inline void commandInduction(std::string);
	};
}