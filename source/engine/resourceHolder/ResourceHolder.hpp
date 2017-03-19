#pragma once

#include <memory>
#include <vector>

#include "engine/Logger.hpp"
#include "engine/Types.hpp"

namespace pi
{
	/*
	===============================================================================
	Created by: Condzi
		Global (static) class for holding resources. You can delete them using 
		delete methods by priority and ID.
		NOTE: Add resources using public vectors, but GET THEM USING GETTERS!

	===============================================================================
	*/
	struct ResourceHolder final
	{
		ResourceHolder() = delete;
		
		static std::vector<std::shared_ptr<textureResource_t>> textures;
		static std::vector<std::shared_ptr<fontResource_t>> fonts;

		static void Initialize();
		static void Shutdown();

		static void DeleteAllResources();
		static void DeleteAllResourcesByPriority( uint8_t priority );
		static void DeleteAllResourcesByID( uint8_t id );

		static std::weak_ptr<textureResource_t> GetTexture( uint8_t id );
		static std::weak_ptr<fontResource_t> GetFont( uint8_t id );
	};
}