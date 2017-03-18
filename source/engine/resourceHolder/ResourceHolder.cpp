#include "ResourceHolder.hpp"

namespace pi
{
	std::vector<std::shared_ptr<textureResource_t>> ResourceHolder::textures;
	std::vector<std::shared_ptr<fontResource_t>> ResourceHolder::fonts;


	void ResourceHolder::Initialize()
	{
		Logger::Log( "Resource Holder initialized!" );
	}

	void ResourceHolder::Shutdown()
	{
		ResourceHolder::DeleteAllResources();
		Logger::Log( "Resource Holder shutdown!" );
	}

	void ResourceHolder::DeleteAllResources()
	{
		Logger::Log( "Starting to delete all resources..." );
		Logger::Log( std::to_string( ResourceHolder::textures.size() ) + " Textures" );
		ResourceHolder::textures.clear();
		Logger::Log( std::to_string( ResourceHolder::fonts.size() ) + " Fonts" );
		ResourceHolder::fonts.clear();
		Logger::Log( "All resources deleted!" );
	}

	void ResourceHolder::DeleteAllResourcesByPriority( uint8_t priority )
	{
		Logger::Log( "Starting to delete all resources of priority " + std::to_string( priority ) );

		for ( auto textureIterator = ResourceHolder::textures.begin(); textureIterator != ResourceHolder::textures.end(); )
		{
			if ( ( *textureIterator )->GetResourcePriority() == priority )
				textureIterator = ResourceHolder::textures.erase( textureIterator );
			else
				textureIterator++;
		}
		for ( auto fontIterator = ResourceHolder::fonts.begin(); fontIterator != ResourceHolder::fonts.end(); )
		{
			if ( ( *fontIterator )->GetResourcePriority() == priority )
				fontIterator = ResourceHolder::fonts.erase( fontIterator );
			else
				fontIterator++;
		}

		Logger::Log( "All resources of priority " + std::to_string( priority ) + " deleted" );
	}

	void ResourceHolder::DeleteAllResourcesByID( uint8_t id )
	{
		Logger::Log( "Starting to delete all resources of ID " + std::to_string( id ) );

		for ( auto textureIterator = ResourceHolder::textures.begin(); textureIterator != ResourceHolder::textures.end(); )
		{
			if ( ( *textureIterator )->GetResourceID() == id )
				textureIterator = ResourceHolder::textures.erase( textureIterator );
			else
				textureIterator++;
		}
		for ( auto fontIterator = ResourceHolder::fonts.begin(); fontIterator != ResourceHolder::fonts.end(); )
		{
			if ( ( *fontIterator )->GetResourceID() == id )
				fontIterator = ResourceHolder::fonts.erase( fontIterator );
			else
				fontIterator++;
		}

		Logger::Log( "All resources of ID " + std::to_string( id ) + " deleted" );
	}

	std::weak_ptr<textureResource_t> ResourceHolder::GetTexture( uint8_t id )
	{
		for ( auto ptr : ResourceHolder::textures )
			if ( ptr->GetResourceID() == id )
				return ptr;

		Logger::Log( "Cannot find Texture of ID " + std::to_string( id ), pi::Logger::MessageType::Error);
		return std::weak_ptr<textureResource_t>();
	}

	std::weak_ptr<fontResource_t> ResourceHolder::GetFont( uint8_t id )
	{
		for ( auto ptr : ResourceHolder::fonts )
			if ( ptr->GetResourceID() == id )
				return ptr;

		Logger::Log( "Cannot find Font of ID " + std::to_string( id ), pi::Logger::MessageType::Error );
		return std::weak_ptr<fontResource_t>();
	}
}