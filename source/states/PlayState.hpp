#pragma once

#include "States.hpp"
#include "engine/game/State.hpp"
#include "engine/ResourceCache.hpp"
#include "entities/Player.hpp"
#include "engine/renderer/Renderer.hpp"
#include "worldGenerator/WorldConstructor.hpp"

namespace mc
{
	class PlayState final :
		public pi::State
	{
	private:
		void onActivation() override;

	public:
		PlayState();

		short run();

	private:
		pi::FontCache fonts;
		pi::TextureCache textures;
	};
}