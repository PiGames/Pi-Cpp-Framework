#include "UI.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		UI::UI()
		{
			for (auto &i : this->m_Buttons)
				i = nullptr;
			for (auto &i : this->m_Checkboxs)
				i = nullptr;
			for (auto &i : this->m_Sliders)
				i = nullptr;
		}

		void UI::addButton(pi::ui::Button& button)
		{
			for (unsigned i = 0; i < this->m_Buttons.size(); ++i)
				if (this->m_Buttons[i] == nullptr)
				{
					this->m_Buttons[i] = &button; break;
				}
		}

		void UI::useButtons(sf::Event& event)
		{
			for (unsigned i = 0; i < this->m_Buttons.size(); ++i)
				if (this->m_Buttons[i] != nullptr)
					this->m_Buttons[i]->use(event);
		}

		void UI::updateButtons(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->m_Buttons.size(); ++i)
				if (this->m_Buttons[i] != nullptr)
					this->m_Buttons[i]->update(window);
		}

		void UI::addCheckbox(pi::ui::Checkbox& checkbox)
		{
			for (unsigned i = 0; i < this->m_Checkboxs.size(); ++i)
				if (this->m_Checkboxs[i] == nullptr)
				{
					this->m_Checkboxs[i] = &checkbox; break;
				}
		}

		void UI::useCheckboxs(sf::Event& event)
		{
			for (unsigned i = 0; i < this->m_Checkboxs.size(); ++i)
				if (this->m_Checkboxs[i] != nullptr)
					this->m_Checkboxs[i]->use(event);
		}

		void UI::updateCheckboxs(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->m_Checkboxs.size(); ++i)
				if (this->m_Checkboxs[i] != nullptr)
					this->m_Checkboxs[i]->update(window);
		}
	}
}