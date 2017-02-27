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
			this->listLength = 0;
			this->descriptionLength = 0;
			this->type = elementType_t::LIST;
		}

		void List::SetTexture( const sf::Texture& texture )
		{
			this->texture = texture;
			this->sprite.setTexture( this->texture );
		}

		void List::SetPosition( const sf::Vector2f& position )
		{
			this->position = position;
			this->sprite.setPosition( this->position );
		}

		void List::SetSize( const sf::Vector2f& size )
		{
			this->size = size;
			this->sprite.setScale( { this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y } );
		}

		void List::SetRect( const sf::Vector2f& position, const sf::Vector2f& size )
		{
			this->position = position;
			this->size = size;
			this->sprite.setPosition( this->position );
			this->sprite.setScale( { this->size.x / this->texture.getSize().x, this->size.y / this->texture.getSize().y } );
		}

		void List::SetDescription( const sf::RectangleShape& shape, float time )
		{
			this->descriptionShape = shape;
			this->delayTime = time;
		}

		void List::AddElement( std::function<void()> function, sf::Texture& texture, sf::Text& text )
		{
			if ( this->listLength < this->list.size() )
			{
				if ( !this->list[this->listLength] )
				{
					this->list[this->listLength] = std::make_unique<listStruct_t>();
					this->list[this->listLength]->function = function;
					this->list[this->listLength]->texture = &texture;
					this->list[this->listLength]->text = text;
					this->list[this->listLength]->position = { this->position.x, this->position.y + this->size.y *( this->listLength + 1 ) };
					this->list[this->listLength]->sprite.setTexture( *this->list[this->listLength]->texture );
					this->list[this->listLength]->sprite.setPosition( this->list[this->listLength]->position );
					this->list[this->listLength]->sprite.setScale( { this->size.x / this->list[this->listLength]->texture->getSize().x, this->size.y / this->list[this->listLength]->texture->getSize().y } );
					this->listLength++;
				}
			}
		}

		// Virtual methods

		void List::use( const sf::Event& event )
		{
			if ( event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left )
			{
				if ( this->isOpen )
				{
					if ( this->sprite.getGlobalBounds().contains( static_cast<float>( event.mouseButton.x ), static_cast<float>( event.mouseButton.y ) ) )
					{
						this->isOpen = false;
					}
					for ( auto &i : this->list )
					{
						if ( i )
						{
							if ( i->sprite.getGlobalBounds().contains( static_cast<float>( event.mouseButton.x ), static_cast<float>( event.mouseButton.y ) ) )
							{
								i->function();
							}
						}
					}
				} else
				{
					if ( this->sprite.getGlobalBounds().contains( static_cast<float>( event.mouseButton.x ), static_cast<float>( event.mouseButton.y ) ) )
					{
						this->isOpen = true;
					}
				}
			} else if ( event.type == sf::Event::MouseMoved )
			{
				this->cursorOnList = false;
				if ( this->isOpen )
				{
					if ( this->drawDescription ) // if description is enable
					{
						this->drawDescription = false;
					} else if ( !this->drawDescription ) // if description is disable
					{
						for ( size_t i = 0; i < list.size() - 1; ++i )
						{
							if ( this->list[i] )
							{
								if ( this->list[i]->sprite.getGlobalBounds().contains( static_cast<float>( event.mouseMove.x ), static_cast<float>( event.mouseMove.y ) ) )
								{
									this->descriptionLength = i;
									this->cursorOnList = true;
									this->descriptionShape.setPosition( { static_cast<float>( event.mouseMove.x ) + 2.f, static_cast<float>( event.mouseMove.y ) - this->descriptionShape.getSize().y } );
									this->list[descriptionLength]->text.setPosition( { static_cast<float>( event.mouseMove.x ) + 10.f, static_cast<float>( event.mouseMove.y ) - this->descriptionShape.getSize().y + 10.f } );
								}
							}
						}
					}
				}
			}
		}

		void List::update( sf::RenderWindow& window )
		{
			window.draw( this->sprite );

			if ( this->isOpen )
			{
				for ( auto &i : this->list )
				{
					if ( i )
					{
						window.draw( i->sprite );
					}
				}
				// Description
				if ( this->drawDescription )
				{
					window.draw( this->descriptionShape );
					window.draw( this->list[descriptionLength]->text );
				} else if ( !this->drawDescription )
				{
					if ( this->cursorOnList )
					{
						if ( this->realTime >= this->delayTime )
						{
							this->drawDescription = true;
							this->realTime = 0;
						} else
						{
							this->realTime++;
						}
					}
				}
			}
		}
	}
}