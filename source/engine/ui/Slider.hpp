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
		Slider class.
		===============================================================================
		*/
		class Slider final : public Element
		{
		public:
			Slider();
			~Slider() = default;

			// VIEW FUNCTIONS START
			// Set slider and rate texture
			void SetTexture( const sf::Texture& sliderTexture, const sf::Texture& rateTexture );
			// Set scale slider and rate
			void SetScale( const sf::Vector2f& scale );
			// Set position and size
			void SetRect( const sf::Vector2f& position, const sf::Vector2f& size );
			// VIEW FUNCTIONS END

			// GET START
			// If user click rate and not relase mouse button 
			const bool GetSelected() const { return this->isSelected; }
			// GET END

			// FUNCTIONS FOR FUNCTIONS IN ARRAY START
			float ScalePositionOfRate() const { return( this->ratePosition.x - this->position.x ) / ( this->size.x - this->rateSize.x ); }
			float ScalePositionOfRateToReal( float number ) const { return( this->ratePosition.x - this->position.x ) / ( this->size.x - this->rateSize.x ) * number; }
			// FUNCTIONS FOR FUNCTIONS IN ARRAY END

			// Add calback function for slider
			void AddCallback( std::function<void( Slider* )> function );
			// Set checking whether rate is selected and use callback
			void SetCheckingInRealMode( bool isEnable );
			// Set delay time for checkingInRealMode
			void SetDelayTime( float time );

		private:
			sf::Texture sliderTexture, rateTexture;
			sf::Sprite rateSprite;
			sf::Vector2f ratePosition, rateSize, scale;
			std::array <std::function<void( Slider* )>, constants::ui::MAX_CALLBACKS> functions;
			float realTime, delayTime;
			bool isSelected, checkingInRealMode;

			// VIRTUAL FUNCTIONS START
			void use( const sf::Event& event ) override;
			void update( sf::RenderWindow& window ) override;
			// VIRTUAL FUNCTIONS START
		};
	}
}