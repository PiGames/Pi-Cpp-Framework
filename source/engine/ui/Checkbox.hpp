#pragma once

#include "Element.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace ui
	{
		/*
		===============================================================================
		Created by: Beniamin Gajecki ,,Uriel"
		Checkbox class.
		===============================================================================
		*/
		class Checkbox final : public Element
		{
		public:
			Checkbox();
			~Checkbox() = default;

			// VIEW FUNCTIONS START
			// Set checkbox textures when on and off
			void SetTexture( const sf::Texture& textureOff, const sf::Texture& textureOn );
			// Set checkbox position
			void SetPosition( const sf::Vector2f& position );
			// Set checkbox size
			void SetSize( const sf::Vector2f& size );
			// Set checkbox position and size
			void SetRect( const sf::Vector2f&, const sf::Vector2f& );
			// Set On-Off
			void SetEnable( const bool );
			// VIEW FUNCTIONS END

			// GET START
			// Get checkbox texture
			const sf::Texture GetTexture() const { return *this->texture; }
			// Get checkbox when is on
			const sf::Texture GetTextureOn() const { return this->textureOn; }
			// Get checkbox when is off
			const sf::Texture GetTextureOff() const { return this->textureOff; }
			// Get On or Off
			const bool GetEnable() const { return this->isEnable; }
			// GET END

			// Add calback function for checkbox when is on
			void AddCallbackOn( std::function<void()> );
			// Add calback function for checkbox when is off
			void AddCallbackOff( std::function<void()> );

		private:
			sf::Texture *texture, textureOn, textureOff;
			std::array <std::function<void()>, constants::ui::MAX_CALLBACKS> functionsOff;
			std::array <std::function<void()>, constants::ui::MAX_CALLBACKS> functionsOn;
			bool isEnable;

			void enable();
			void disable();

			// VIRTUAL FUNCTIONS START
			void use( const sf::Event& event ) final;
			// VIRTUAL FUNCTIONS END
		};
	}
}