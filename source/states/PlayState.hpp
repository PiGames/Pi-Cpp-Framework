#pragma once

#include "States.hpp"
#include "engine/game/State.hpp"
#include "engine/ResourceCache.hpp"
#include "entities/Player.hpp"
#include "engine/renderer/Renderer.hpp"
#include "worldGenerator/WorldConstructor.hpp"

namespace mc
{
	class PlayState final : public pi::State
	{
	public:
		PlayState();

		short Run() override;

	private:
		pi::FontCache fonts;
		pi::TextureCache textures;

		void onActivation() override;
	};
}