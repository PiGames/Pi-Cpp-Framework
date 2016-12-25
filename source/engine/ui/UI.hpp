#pragma once

#include "Button.hpp"
#include "Checkbox.hpp"

#include <vector>

namespace pi
{
	namespace ui
	{
		class UI
		{
		public:
			UI() = default;
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

		private:
			std::vector <pi::ui::Button*> m_Buttons;
			std::vector <pi::ui::Checkbox*> m_Checkboxs;
		};
	}
}