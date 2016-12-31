#include "Console.hpp"

namespace pi
{
	Console::Console()
	{
		// Default settings
		this->isOpen = false;
		this->numberOfLines = constants::console::DEAFULT_NUMBER_OF_LINES;
		this->textSizeInLine = constants::console::DEAFULT_TEXT_SIZE_IN_LINE;
		this->commandArrayLenght = 0;
		// Text settings
		this->text.setFillColor(sf::Color::White);
		this->text.setCharacterSize(constants::console::DEAFULT_TEXT_SIZE);
		this->text.setPosition({ 0, 0 });

		this->input.setFillColor(sf::Color::White);
		this->input.setCharacterSize(constants::console::DEAFULT_TEXT_SIZE);
		this->input.setPosition({ 20.f, this->window->getSize().y / 2 - 20.f });

		this->input.setString("|");
	}
	
	Console::Console(sf::RenderWindow& window)
	{
		// Default settings
		this->window = &window;
		this->isOpen = false;
		this->numberOfLines = constants::console::DEAFULT_NUMBER_OF_LINES;;
		this->textSizeInLine = constants::console::DEAFULT_TEXT_SIZE_IN_LINE;
		this->commandArrayLenght = 0;
		// Text settings
		this->text.setFillColor(sf::Color::White);
		this->text.setCharacterSize(constants::console::DEAFULT_TEXT_SIZE);
		this->text.setPosition({ 0, 0 });

		this->input.setFillColor(sf::Color::White);
		this->input.setCharacterSize(constants::console::DEAFULT_TEXT_SIZE);
		this->input.setPosition({ 20.f, this->window->getSize().y / 2 - 20.f });

		this->input.setString("|");
	}

	void Console::setWindow(sf::RenderWindow& window)
	{
		// Default settings
		this->window = &window;
	}
	
	void Console::setTexture(sf::Texture& texture)
	{
		this->texture = texture;
		this->sprite.setTexture(this->texture);
		this->sprite.setPosition({ 0, 0 });
		this->sprite.setScale({ static_cast<float>(this->window->getSize().x) / static_cast<float>(this->texture.getSize().x), static_cast<float>(this->window->getSize().y) / static_cast<float>(this->texture.getSize().y) / 2.f });
	}

	void Console::setTextColor(const sf::Color& color)
	{
		this->text.setFillColor(color);
		this->input.setFillColor(color);
	}

	void Console::setTextFont(sf::Font& font)
	{
		this->text.setFont(font);
		this->input.setFont(font);
	}

	void Console::setTextSize(unsigned size)
	{
		this->text.setCharacterSize(size);
		this->input.setCharacterSize(size);
	}

	void Console::setTextSizeInLine(unsigned size)
	{
		this->textSizeInLine = size;
	}

	void Console::addCommand(void function())
	{
		this->command[commandArrayLenght].reset(new Command);
		this->command[commandArrayLenght]->function = function;
		commandArrayLenght++;
	}

	void Console::run()
	{
		if (!this->isOpen)
		{
			this->isOpen = true;
		}
		else if (this->isOpen)
		{
			this->isOpen = false;
		}
	}

	void Console::key(sf::Event& event)
	{
		if (event.key.code == sf::Keyboard::Return)
		{
			if (this->input.getString().getSize() < textSizeInLine) // Input text one row
			{
				// First lane
				for (unsigned i = 0; i < this->line.size() - 1; ++i)
					this->line[i] = this->line[i + 1];
				this->line[line.size() - 1] = this->input.getString().substring(0, this->input.getString().getSize() - 1);

				// Write all string array in console text
				this->input.setString("|");
				this->text.setString("");
				for (auto &i : this->line)
					this->text.setString(this->text.getString() + i + "\n");
			}
			else if (this->input.getString().getSize() < this->textSizeInLine * 2) // Input text two row
			{
				// First lane
				for (unsigned i = 0; i < this->line.size() - 1; ++i)
					this->line[i] = this->line[i + 1];
				this->line[line.size() - 1] = this->input.getString().substring(0, this->textSizeInLine - 1);

				// Second lane
				for (unsigned i = 0; i < this->line.size() - 1; ++i)
					this->line[i] = this->line[i + 1];
				this->line[line.size() - 1] = this->input.getString().substring(this->textSizeInLine + 1, this->textSizeInLine * 2 - 1);

				// Write all string array in console text
				this->input.setString("|");
				this->text.setString("");
				for (auto &i : this->line)
					this->text.setString(this->text.getString() + i + "\n");
			}
		}
		else if (event.key.code == sf::Keyboard::BackSpace)
		{
			if (this->input.getString().getSize() == 1)
				this->input.setString("|");
			else
				this->input.setString(this->input.getString().substring(0, this->input.getString().getSize() - 2) + "|");
		}
	}

	void Console::write(sf::Event& event)
	{
		if (this->input.getString().getSize() < this->textSizeInLine) // Write in first row
			this->input.setString(this->input.getString().substring(0, this->input.getString().getSize() - 1) + static_cast<char>(event.text.unicode) + "|");
		else if (this->input.getString().getSize() == this->textSizeInLine) // Jump to next row
			this->input.setString(this->input.getString().substring(0, this->input.getString().getSize() - 1) + "\n" + static_cast<char>(event.text.unicode) + "|");
		else if(this->input.getString().getSize() < this->textSizeInLine * 2) // Write in second row
			this->input.setString(this->input.getString().substring(0, this->input.getString().getSize() - 1) + static_cast<char>(event.text.unicode) + "|");
	}

	void Console::log(std::string tekst)
	{
		for (unsigned size = 0; size < this->numberOfLines; ++size)
		{

			if (tekst.size() <= this->textSizeInLine * size)
			{
				for (unsigned write = 1; write <= size; ++write)
				{
					for (unsigned i = 0; i < this->line.size() - 1; ++i)
						this->line[i] = this->line[i + 1];

					if (write < size) // Whatever else line option
					{
						this->line[line.size() - 1] = tekst.substr(0, this->textSizeInLine - 1);
						tekst = tekst.substr(this->textSizeInLine, tekst.size() - 1);
					}
					else // Last line option
					{
						this->line[line.size() - 1] = tekst.substr(0, tekst.size() - 1);

						// Write all string array in console text
						this->text.setString("");
						for (auto &i : this->line)
							this->text.setString(this->text.getString() + i + "\n");
						break;
					}
				}
				// Break for first for
				break;
			}
		}

	}

	void Console::update()
	{
		if (this->isOpen)
		{
			this->window->draw(sprite);
			this->window->draw(text);
			this->window->draw(input);
		}
	}
}