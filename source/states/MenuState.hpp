#pragma once

#include "States.hpp"
#include "engine/game/State.hpp"
#include "engine/ResourceCache.hpp"
#include "engine/ui/UI.hpp"

namespace mc
{
	class MenuState final :
		public pi::State
	{
	public:
		MenuState();
		~MenuState() = default;

		short run();
	private:
		pi::FontCache fonts;
	};
}