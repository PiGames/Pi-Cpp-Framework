#pragma once

#include "Element.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include "Slider.hpp"

#include <array>

namespace pi
{
	namespace ui
	{
		class UI
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

			// Slider section end

		private:
			std::array <pi::ui::Button*, 32> buttons;
			std::array <pi::ui::Checkbox*, 32> checkboxs;
			std::array <pi::ui::Slider*, 32> sliders;
		};
	}
}