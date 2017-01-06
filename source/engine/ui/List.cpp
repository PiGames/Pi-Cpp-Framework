#include "List.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		List::List()
		{
			this->isOpen = false;
			this->drawDescription = false;
			this->cursorOnList = false;
			this->delayTime = 2000;
			this->realTime = 0;
			this->listLenght = 0;
			this->descriptionLenght = 0;
			this->type = "LIST";
		}

		void List::setTexture(const sf::Texture& texture)
		{
			this->texture = texture;
			this->sprite.setTexture(this->texture);
		}

		void List::setPosition(const sf::Vector2f& position)
		{
			this->position = position;
			this->sprite.setPosition(this->position);
		}

		void List::setSize(const sf::Vector2f& size)
		{
			this->size = size;
			this->sprite.setScale({ this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y });
		}

		void List::setRect(const sf::Vector2f& position, const sf::Vector2f& size)
		{
			this->position = position;
			this->size = size;
			this->sprite.setPosition(this->position);
			this->sprite.setScale({ this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y });
		}

		void List::setDescription(const sf::RectangleShape& shape, const float time)
		{
			this->descriptionShape = shape;
			this->delayTime = time;
		}

		void List::addElement(std::function<void()> function, sf::Texture& texture, sf::Text& text)
		{
			if (this->listLenght < this->list.size())
				if (!this->list[this->listLenght])
				{
					this->list[this->listLenght] = std::make_unique<ListStruct>();
					this->list[this->listLenght]->function = function;
					this->list[this->listLenght]->texture = &texture;
					this->list[this->listLenght]->text = text;
					this->list[this->listLenght]->position = { this->position.x,  this->position.y + this->size.y * (this->listLenght + 1) };
					this->list[this->listLenght]->sprite.setTexture(*this->list[this->listLenght]->texture);
					this->list[this->listLenght]->sprite.setPosition(this->list[this->listLenght]->position);
					this->list[this->listLenght]->sprite.setScale({ this->size.x / this->list[this->listLenght]->texture->getSize().x, this->size.y / this->list[this->listLenght]->texture->getSize().y });
					this->listLenght++;
				}
		}

		// Virtual methods

		void List::use(sf::Event& event)
		{
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				if (this->isOpen)
				{
					if (this->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
						this->isOpen = false;

					for (auto &i : this->list)
						if (i)
							if (i->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
								i->function();
				}
				else
					if (this->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
						this->isOpen = true;
			}
			else if (event.type == sf::Event::MouseMoved)
			{
				this->cursorOnList = false;
				if (this->isOpen)
				{
					if (this->drawDescription) // if description is enable
						this->drawDescription = false;
					else if (!this->drawDescription) // if description is disable
					{
						for (unsigned i = 0; i < list.size() - 1; ++i)
						{
							if (this->list[i])
								if (this->list[i]->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)))
								{
									this->descriptionLenght = i;
									this->cursorOnList = true;
									this->descriptionShape.setPosition({ static_cast<float>(event.mouseMove.x) + 2.f, static_cast<float>(event.mouseMove.y) - this->descriptionShape.getSize().y });
									this->list[descriptionLenght]->text.setPosition({ static_cast<float>(event.mouseMove.x) + 10.f, static_cast<float>(event.mouseMove.y) - this->descriptionShape.getSize().y + 10.f });
								}
						}
					}
				}
			}
		}

		void List::update(sf::RenderWindow& window)
		{
			window.draw(this->sprite);

			if (this->isOpen)
			{
				for (auto &i : this->list)
					if (i)
						window.draw(i->sprite);

				// Description
				if (this->drawDescription)
				{
					window.draw(this->descriptionShape);
					window.draw(this->list[descriptionLenght]->text);
				}
				else if (!this->drawDescription)
				{
					if (this->cursorOnList)
					{
						if (this->realTime >= this->delayTime)
						{
							this->drawDescription = true;
							this->realTime = 0;
						}
						else
							this->realTime++;
					}
				}
			}
		}
	}
}