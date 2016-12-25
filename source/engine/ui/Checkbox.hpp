#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace pi
{
	namespace ui
	{
		class Checkbox
		{
		public:
			Checkbox() = default;
			~Checkbox() = default;

			// Set
			void setTexture(sf::Texture&, sf::Texture&);
			void setPosition(const sf::Vector2f&);
			void setSize(const sf::Vector2f&);
			// Get
			sf::Texture getTexture() { return *this->m_Texture; }
			sf::Texture getTextureOff() { return this->m_TextureOff; }
			sf::Texture getTextureOn() { return this->m_TextureOn; }
			const sf::Vector2f getPosition() const { return this->m_Position; }
			const sf::Vector2f getSize() const { return this->m_Size; }

			void addCallbackOff(void());
			void addCallbackOn(void());
			void use(sf::Event& event);
			void update(sf::RenderWindow&);

			
		private:
			sf::Texture *m_Texture, m_TextureOff, m_TextureOn;
			sf::Sprite m_Sprite;
			sf::Vector2f m_Position, m_Size;
			std::vector <void(*)()> m_FunctionsOff;
			std::vector <void(*)()> m_FunctionsOn;
			bool m_Enable = false;

			void enable();
			void disable();
		};
	}
}