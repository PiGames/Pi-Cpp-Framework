#pragma once

#include "Element.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace ui
	{
		class Checkbox final : public Element
		{
		public:
			Checkbox();
			~Checkbox() = default;

			// VIEW FUNCTIONS START
			// Set checkbox textures when on and off
			void setTexture(const sf::Texture&, const sf::Texture&);
			// Set checkbox position
			void setPosition(const sf::Vector2f&);
			// Set checkbox size
			void setSize(const sf::Vector2f&);
			// Set checkbox position and size
			void setRect(const sf::Vector2f&, const sf::Vector2f&);
			// Set On-Off
			void setEnable(const bool);
			// VIEV FUNCTIONS END

			// GET START
			// Get checkbox texture
			const sf::Texture getTexture() const { return *this->texture; }
			// Get checkbox when is on
			const sf::Texture getTextureOn() const { return this->textureOn; }
			// Get checkbox when is off
			const sf::Texture getTextureOff() const { return this->textureOff; }
			// Get On or Off
			const bool getEnable() const { return this->isEnable; }
			// GET END

			// Add calback function for checkbox when is on
			void addCallbackOn(std::function<void()>);
			// Add calback function for checkbox when is off
			void addCallbackOff(std::function<void()>);

		private:
			sf::Texture *texture, textureOn, textureOff;
			std::array <std::function<void()>, constants::ui::MAX_CALLBACKS> functionsOff;
			std::array <std::function<void()>, constants::ui::MAX_CALLBACKS> functionsOn;
			bool isEnable;

			void enable();
			void disable();

			// VIRTUAL FUNCTIONS START
			void use(sf::Event& event) final;
			// VIRTUAL FUNCTIONS END
		};
	}
}