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

			// Set
			void setTexture(sf::Texture&, sf::Texture&);
			void setPosition(const sf::Vector2f&);
			void setSize(const sf::Vector2f&);
			void setRect(const sf::Vector2f&, const sf::Vector2f&);
			void setEnable(bool);
			// Get
			sf::Texture getTexture() const { return *this->texture; }
			sf::Texture getTextureOn() const { return this->textureOn; }
			sf::Texture getTextureOff() const { return this->textureOff; }
			const bool getEnable() const { return this->enable; }

			void addCallbackOn(void());
			void addCallbackOff(void());

			virtual void use(sf::Event& event) final override;
			
		private:
			sf::Texture *texture, textureOn, textureOff;
			std::array <void(*)(), constants::ui::MAX_CALLBACKS> functionsOff;
			std::array <void(*)(), constants::ui::MAX_CALLBACKS> functionsOn;
			bool enable;

			void Enable();
			void Disable();
		};
	}
}