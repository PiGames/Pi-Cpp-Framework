#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>
#include <string>
#include <functional>


#include "engine/Config.hpp"

namespace pi
{
	struct Command
	{
		std::function <void()> function;
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
		void setTexture(sf::Texture&);

		void setTextColor(const sf::Color&);
		void setTextFont(sf::Font&);
		void setTextSize(unsigned);
		void setTextSizeInLine(unsigned);

		void addCommand(void());

		void run();
		void key(sf::Event&);
		void write(sf::Event&);
		void log(std::string);
		void update();

	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::RenderWindow* window;
		bool isOpen;

		sf::Text text, input;
		unsigned numberOfLines, textSizeInLine, commandArrayLenght;
		std::array <std::string, constants::console::DEAFULT_NUMBER_OF_LINES> line;
		std::array <std::unique_ptr<Command>, constants::console::MAX_COMMANDS> command;
	};
}