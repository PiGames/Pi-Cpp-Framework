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

			// Set
			void setTexture(sf::Texture&);
			void setPosition(const sf::Vector2f&);
			void setSize(const sf::Vector2f&);
			void setRect(const sf::Vector2f&, const sf::Vector2f&);
			void setDescription(sf::RectangleShape&, float);
			// Get
			sf::Texture getTexture() const { return this->texture; }
			unsigned getListLenght() const { return this->listLenght; }
			bool getEnable() const { return this->enable; }

			void addElement(void(), sf::Texture&, sf::Text&);
			void description(sf::Event&);

			virtual void use(sf::Event&) final override;
			virtual void update(sf::RenderWindow&) final override;

		private:
			sf::Texture texture;
			sf::RectangleShape cloud;
			unsigned listLenght, descriptionLenght;
			bool enable, descriptionEnable;
			float time;

			static const std::uint8_t MAX_NUMBER_OF_THE_ELEMENTS = 32;
			struct ListStruct
			{
				void(*function)();
				sf::Texture texture;
				sf::Sprite sprite;
				sf::Text text;
				sf::Vector2f position;
			};
			std::array <std::unique_ptr<ListStruct>, constants::ui::MAX_UIELEMENTS> list;
		};
	}
}