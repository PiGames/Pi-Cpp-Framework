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
			this->listLenght = 0;
		}

		void List::setTexture(sf::Texture& texture)
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

		void List::setDescription(sf::RectangleShape& cloud, float time)
		{
			this->cloud = cloud;
			this->time = time;
		}

		void List::addElement(std::function<void()> function, sf::Texture& texture, sf::Text& text)
		{
			if (this->listLenght < constants::ui::MAX_UIELEMENTS)
				if (!this->list[listLenght])
				{
					this->list[listLenght].reset(new ListStruct);
					this->list[listLenght]->function = function;
					this->list[listLenght]->texture = &texture;
					this->list[listLenght]->text = text;
					this->list[listLenght]->position = { this->position.x,  this->position.y + this->size.y * (this->listLenght + 1) };
					this->list[listLenght]->sprite.setTexture(*this->list[listLenght]->texture);
					this->list[listLenght]->sprite.setPosition(this->list[listLenght]->position);
					this->list[listLenght]->sprite.setScale({ this->size.x / this->list[listLenght]->texture->getSize().x, this->size.y / this->list[listLenght]->texture->getSize().y });
					this->listLenght++;
				}
		}

		void List::description(sf::Event& event)
		{
			if (this->isOpen)
			{	
				
				if (this->drawDescription) // if description is enable
				{
					this->drawDescription = false;
					for (unsigned i = 0; i < list.size(); ++i)
					{
						if (this->list[i])
							if (this->list[i]->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)))
							{
								this->descriptionLenght = i;
								this->drawDescription = true;
								this->cloud.setPosition({ static_cast<float>(event.mouseMove.x) + 2.f, static_cast<float>(event.mouseMove.y) - this->cloud.getSize().y });
								this->list[descriptionLenght]->text.setPosition({ static_cast<float>(event.mouseMove.x) + 10.f, static_cast<float>(event.mouseMove.y) - this->cloud.getSize().y + 10.f });
							}
					}
				}
				else // if description is disable
				{
					for (float t = 0; t < time; ++t)
					{
						for (unsigned i = 0; i < list.size(); ++i)
						{
							if (this->list[i])
								if (this->list[i]->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y)))
								{
									this->descriptionLenght = i;
									this->drawDescription = true;
									this->cloud.setPosition({ static_cast<float>(event.mouseMove.x) + 2.f, static_cast<float>(event.mouseMove.y) - this->cloud.getSize().y });
									this->list[descriptionLenght]->text.setPosition({ static_cast<float>(event.mouseMove.x) + 10.f, static_cast<float>(event.mouseMove.y) - this->cloud.getSize().y + 10.f });
								}
						}
					}
				}
			}
		}

		// Virtual methods

		void List::use(sf::Event& event)
		{
			if (this->isOpen)
			{
				if (this->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
					this->isOpen = false;

				for (unsigned i = 0; i < list.size(); ++i)
				{
					if (this->list[i])
						if (this->list[i]->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
							this->list[i]->function();
				}

			}
			else if (!this->isOpen)
			{
				if (this->sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
					this->isOpen = true;
			}
		}

		void List::update(sf::RenderWindow& window)
		{
			window.draw(this->sprite);

			if (this->isOpen)
				for (unsigned i = 0; i < listLenght; ++i)
					if (this->list[i])
						window.draw(this->list[i]->sprite);

			// Description
			if (this->drawDescription)
			{
				window.draw(this->cloud);
				window.draw(list[descriptionLenght]->text);
			}
		}

	}
}