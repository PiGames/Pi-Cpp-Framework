#pragma once

#include "Element.hpp"

#include <array>

namespace pi
{
	namespace ui
	{
		class Checkbox : public pi::ui::Element
		{
		public:
			Checkbox();
			~Checkbox() = default;

			// Set
			void setTexture(sf::Texture&, sf::Texture&);
			void setPosition(const sf::Vector2f&);
			void setSize(const sf::Vector2f&);
			// Get
			sf::Texture getTexture() const { return *this->m_Texture; }
			sf::Texture getTextureOff() const { return this->m_TextureOff; }
			sf::Texture getTextureOn() const { return this->m_TextureOn; }

			void addCallbackOff(void());
			void addCallbackOn(void());

			virtual void use(sf::Event& event) override;
			
		private:
			sf::Texture *m_Texture, m_TextureOff, m_TextureOn;
			std::array <void(*)(), 8> m_FunctionsOff;
			std::array <void(*)(), 8> m_FunctionsOn;
			bool m_Enable;

			void enable();
			void disable();
		};
	}
}