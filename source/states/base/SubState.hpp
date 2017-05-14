#pragma once

#include <cinttypes>

// Forward Declaration 
namespace sf
{
	class RenderWindow;
}

namespace pi
{
	/*
	===============================================================================
	Created by: Condzi
		Virtual Sub State class. It's a lighter version of State useful for in-State
		States (if you have Menu you probably want CreditsSubState and OptionsSubState
		for example). You must overwrite: OnStart, OnStop, Run. Run method returns
		uint8_t which is id of State or SubState that it wants to switch to.

	===============================================================================
	*/
	class SubState
	{
	public:
		explicit SubState( sf::RenderWindow& win ) :
			window( win )
		{}
		virtual ~SubState() = default;

		virtual void OnStart() = 0;
		virtual void OnStop() = 0;
		virtual uint8_t Run() = 0;

	protected:
		sf::RenderWindow& window;
	};
}