#pragma once

#include <functional>
#include <unordered_map>
#include <memory>

#include "engine/Logger.hpp"
#include "engine/Types.hpp"

namespace pi
{
	template<class Resource, class Enum>
	class ResourceCache final
	{
	public:
		ResourceCache()
		{}

		void SetLoadingMethod( std::function<bool( Resource&, cstring_t )> method )
		{
			if ( !method )
				Logger::Log( "Loading method set for ResourceCache is empty", pi::Logger::MessageType::Warning );

			this->loadingMethod = method;
		}
		void AddResourcePath( Enum name, cstring_t path )
		{
			pathes[name] = path;
		}

		std::shared_ptr<Resource> Get( Enum name )
		{
			if ( resources.find( name ) == resources.end() || !this->resources.find( name )->second )
			{
				if ( !load( name ) )
				{
					Logger::Log( "Cannot load resource of ID: " + std::to_string( static_cast<int32_t>( name ) ), pi::Logger::MessageType::Error );
					return nullptr;
				}
			}

			return resources[name];
		}
		bool Release( Enum name, bool forceRelease )
		{
			if ( resources.find( name ) == resources.end() || !this->resources.find( name )->second )
				return false;

			if ( !resources[name].use_count() || forceRelease )
			{
				resources.erase( resources.find( name ) );

				return true;
			}

			return false;
		}
		bool ReleaseAll( bool forceRelease )
		{
			bool allReleased = true;

			for ( auto it = resources.begin(); it != resources.end(); )
			{
				if ( !it->second.use_count() || forceRelease )
					it = resources.erase( it );
				else
				{
					it++;
					allReleased = false;
				}
			}

			return allReleased;
		}

	private:
		std::unordered_map<Enum, std::shared_ptr<Resource>> resources;
		std::unordered_map<Enum, cstring_t> pathes;
		std::function<bool( Resource&, cstring_t )> loadingMethod;

		bool load( Enum name )
		{
			if ( pathes.find( name ) == pathes.end() )
			{
				Logger::Log( "Cannot load resource - cannot find path for ID: " + std::to_string( static_cast<int32_t>( name ) ), Logger::MessageType::Error );
				return false;
			} else 
			{
				resources[name] = std::make_shared<Resource>();
				if ( !loadingMethod( *resources[name], pathes[name] ) )
				{
					Logger::Log( "Cannot load resource - cannot load from path: " + std::string(pathes.at(name)) + " for ID: " + std::to_string( static_cast<int32_t>( name ) ), Logger::MessageType::Error );
					return false;
				}
			}

			return true;
		}
	};

}