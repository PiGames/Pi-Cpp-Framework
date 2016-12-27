#include "UI.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		UI::UI()
		{
			for (auto &i : this->buttons)
				i = nullptr;
			for (auto &i : this->checkboxs)
				i = nullptr;
			for (auto &i : this->sliders)
				i = nullptr;
		}

		void UI::addButton(pi::ui::Button& button)
		{
			for (unsigned i = 0; i < this->buttons.size(); ++i)
				if (this->buttons[i] == nullptr)
				{
					this->buttons[i] = &button; break;
				}
		}

		void UI::useButtons(sf::Event& event)
		{
			for (unsigned i = 0; i < this->buttons.size(); ++i)
				if (this->buttons[i] != nullptr)
					this->buttons[i]->use(event);
		}

		void UI::updateButtons(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->buttons.size(); ++i)
				if (this->buttons[i] != nullptr)
					this->buttons[i]->update(window);
		}

		void UI::addCheckbox(pi::ui::Checkbox& checkbox)
		{
			for (unsigned i = 0; i < this->checkboxs.size(); ++i)
				if (this->checkboxs[i] == nullptr)
				{
					this->checkboxs[i] = &checkbox; break;
				}
		}

		void UI::useCheckboxs(sf::Event& event)
		{
			for (unsigned i = 0; i < this->checkboxs.size(); ++i)
				if (this->checkboxs[i] != nullptr)
					this->checkboxs[i]->use(event);
		}

		void UI::updateCheckboxs(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->checkboxs.size(); ++i)
				if (this->checkboxs[i] != nullptr)
					this->checkboxs[i]->update(window);
		}
	}
}