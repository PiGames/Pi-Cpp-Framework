#pragma once

#include "Element.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include "Slider.hpp"
#include "engine/Config.hpp"

#include <array>

namespace pi
{
	namespace ui
	{
		class UI final
		{
		public:
			UI();
			~UI() = default;
			
			// Buttons section start
			void addButton(pi::ui::Button&);
			void useButtons(sf::Event&);
			void updateButtons(sf::RenderWindow&);
			// Buttons section end

			// Chechbox section start
			void addCheckbox(pi::ui::Checkbox&);
			void useCheckboxs(sf::Event&);
			void updateCheckboxs(sf::RenderWindow&);
			// Chechbox section end

			// Slider section start
			void addSlider(pi::ui::Slider&);
			void useSliders(sf::Event&);
			void updateSliders(sf::RenderWindow&);
			void selectedSliders(sf::Event&);
			void releasedSliders();
			// Slider section end

		private:
			std::array <pi::ui::Button*, constants::ui::MAX_UIELEMENTS> buttons;
			std::array <pi::ui::Checkbox*, constants::ui::MAX_UIELEMENTS> checkboxs;
			std::array <pi::ui::Slider*, constants::ui::MAX_UIELEMENTS> sliders;
		};
	}
}