/*
	Conrad 'Condzi' Kubacki 2017
	https://github.com/condzi
*/

#include "ResourceHolder.hpp"

namespace pi
{
	void ResourceHolder::DeleteAllResources()
	{
		Logger::Log( "Starting to delete all resources...", Logger::BOTH, Logger::INFO );
		Logger::Log( std::to_string( this->textures.size() ) + " Textures", Logger::BOTH, Logger::INFO );
		this->textures.clear();
		Logger::Log( std::to_string( this->uiTexts.size() ) + " Texts", Logger::BOTH, Logger::INFO );
		this->uiTexts.clear();
		Logger::Log( std::to_string( this->fonts.size() ) + " Fonts", Logger::BOTH, Logger::INFO );
		this->fonts.clear();
		Logger::Log( "All resources deleted!", Logger::BOTH, Logger::INFO );
	}

	void ResourceHolder::DeleteAllResourcesByPriority( uint8_t priority )
	{
		Logger::Log( "Starting to delete all resources of priority " + std::to_string( priority ), Logger::BOTH, Logger::INFO );

		uint16_t counter = 0;

		for ( auto textureIterator = this->textures.begin(); textureIterator != this->textures.end(); )
		{
			if ( ( *textureIterator )->GetResourcePriority() == priority )
			{
				textureIterator = this->textures.erase( textureIterator );
				counter++;
			} else
				textureIterator++;
		}
		for ( auto textsIterator = this->uiTexts.begin(); textsIterator != this->uiTexts.end(); )
		{
			if ( ( *textsIterator )->GetResourcePriority() == priority )
			{
				textsIterator = this->uiTexts.erase( textsIterator );
				counter++;
			} else
				textsIterator++;
		}
		for ( auto fontIterator = this->fonts.begin(); fontIterator != this->fonts.end(); )
		{
			if ( ( *fontIterator )->GetResourcePriority() == priority )
			{
				fontIterator = this->fonts.erase( fontIterator );
				counter++;
			} else
				fontIterator++;
		}

		Logger::Log( std::to_string( counter ) + " resources of priority " + std::to_string( priority ) + " deleted", Logger::BOTH, Logger::INFO );
	}

	void ResourceHolder::DeleteAllResourcesByID( uint8_t id )
	{
		Logger::Log( "Starting to delete all resources of ID " + std::to_string( id ), Logger::BOTH, Logger::INFO );

		uint16_t counter = 0;

		for ( auto textureIterator = this->textures.begin(); textureIterator != this->textures.end(); )
		{
			if ( ( *textureIterator )->GetResourceID() == id )
			{
				textureIterator = this->textures.erase( textureIterator );
				counter++;
			} else
				textureIterator++;
		}
		for ( auto textsIterator = this->uiTexts.begin(); textsIterator != this->uiTexts.end(); )
		{
			if ( ( *textsIterator )->GetResourceID() == id )
			{
				textsIterator = this->uiTexts.erase( textsIterator );
				counter++;
			} else
				textsIterator++;
		}
		for ( auto fontIterator = this->fonts.begin(); fontIterator != this->fonts.end(); )
		{
			if ( ( *fontIterator )->GetResourceID() == id )
			{
				fontIterator = this->fonts.erase( fontIterator );
				counter++;
			} else
				fontIterator++;
		}

		Logger::Log( std::to_string( counter ) + " resources of ID " + std::to_string( id ) + " deleted", Logger::BOTH, Logger::INFO );
	}

	std::weak_ptr<textureResource_t> ResourceHolder::GetTexture( uint8_t id )
	{
		for ( auto ptr : this->textures )
			if ( ptr->GetResourceID() == id )
				return ptr;

		Logger::Log( "Cannot find Texture of ID " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
		return std::weak_ptr<textureResource_t>();
	}

	std::weak_ptr<uiTextResource_t> ResourceHolder::GetText( uint8_t id )
	{
		for ( auto ptr : this->uiTexts )
			if ( ptr->GetResourceID() == id )
				return ptr;

		Logger::Log( "Cannot find Text of ID " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
		return std::weak_ptr<uiTextResource_t>();
	}

	std::weak_ptr<fontResource_t> ResourceHolder::GetFont( uint8_t id )
	{
		for ( auto ptr : this->fonts )
			if ( ptr->GetResourceID() == id )
				return ptr;

		Logger::Log( "Cannot find Font of ID " + std::to_string( id ), Logger::BOTH, Logger::ERROR );
		return std::weak_ptr<fontResource_t>();
	}
}