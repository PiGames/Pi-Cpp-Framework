#include "UI.hpp"

namespace pi
{
	namespace ui
	{
		void UI::addButton(pi::ui::Button& button)
		{
			this->m_Buttons.push_back(&button);
		}

		void UI::useButtons(sf::Event& event)
		{
			for (unsigned i = 0; i < this->m_Buttons.size(); ++i)
				this->m_Buttons[i]->click(event);
		}

		void UI::updateButtons(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->m_Buttons.size(); ++i)
				this->m_Buttons[i]->update(window);
		}

		void UI::addCheckbox(pi::ui::Checkbox& checkbox)
		{
			this->m_Checkboxs.push_back(&checkbox);
		}

		void UI::useCheckboxs(sf::Event& event)
		{
			for (unsigned i = 0; i < this->m_Checkboxs.size(); ++i)
				this->m_Checkboxs[i]->use(event);
		}

		void UI::updateCheckboxs(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->m_Checkboxs.size(); ++i)
				this->m_Checkboxs[i]->update(window);
		}
	}
}