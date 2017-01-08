#pragma once

#include "Element.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace ui
	{
		class List final : public Element
		{
		public:
			List();
			~List() = default;

			List& operator =(const List&) = delete;
			List(const List& element) = delete;

			// VIEW FUNCTIONS START
			// Set list texture
			void setTexture(const sf::Texture&);
			// Set list position
			void setPosition(const sf::Vector2f&);
			// Set list size
			void setSize(const sf::Vector2f&);
			// Set list position and size
			void setRect(const sf::Vector2f&, const sf::Vector2f&);
			// Set description shape and her delay time
			void setDescription(const sf::RectangleShape&, const float);
			// VIEW FUNCTIONS END

			// GET START
			// Get list head texture
			const sf::Texture getTexture() const { return this->texture; }
			// Get list lenght
			const unsigned getListLenght() const { return this->listLenght; }
			// Get list open - yes or no
			const bool getOpen() const { return this->isOpen; }
			// GET END

			// Add list element, his function, texture and text for description
			void addElement(std::function<void()>, sf::Texture&, sf::Text&);

		private:
			sf::Texture texture;
			sf::RectangleShape descriptionShape;
			sf::Vector2i mousePosition;
			unsigned listLenght, descriptionLenght;
			float realTime, delayTime;
			bool isOpen, drawDescription, cursorOnList;

			struct ListStruct
			{
				std::function<void()> function;
				sf::Texture* texture;
				sf::Sprite sprite;
				sf::Text text;
				sf::Vector2f position;
			};
			std::array <std::unique_ptr<ListStruct>, constants::ui::MAX_UIELEMENTS> list;

			// VIRTUAL FUNCTIONS START
			void use(sf::Event&) final;
			void update(sf::RenderWindow&) final;
			// VIRTUAL FUNCTIONS END
		};
	}
}