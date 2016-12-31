#include "UI.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		UI::UI()
		{
			this->buttons.fill(nullptr);
			this->checkboxs.fill(nullptr);
			this->sliders.fill(nullptr);
			this->lists.fill(nullptr);
		}

		UI::UI(sf::RenderWindow& window)
		{
			this->buttons.fill(nullptr);
			this->checkboxs.fill(nullptr);
			this->sliders.fill(nullptr);
			this->lists.fill(nullptr);
			this->window = &window;
		}

		void UI::setWindow(sf::RenderWindow& window)
		{
			this->window = &window;
		}

		// Button methods

		void UI::addButton(pi::ui::Button& button)
		{
			for (unsigned i = 0; i < this->buttons.size(); ++i)
				if (!this->buttons[i])
				{
					this->buttons[i] = &button; break;
				}
		}

		void UI::useButtons(sf::Event& event)
		{
			for (unsigned i = 0; i < this->buttons.size(); ++i)
				if (this->buttons[i])
					this->buttons[i]->use(event);
		}

		void UI::updateButtons(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->buttons.size(); ++i)
				if (this->buttons[i])
					this->buttons[i]->update(window);
		}

		// Checkbox methods

		void UI::addCheckbox(pi::ui::Checkbox& checkbox)
		{
			for (unsigned i = 0; i < this->checkboxs.size(); ++i)
				if (!this->checkboxs[i])
				{
					this->checkboxs[i] = &checkbox; break;
				}
		}

		void UI::useCheckboxs(sf::Event& event)
		{
			for (unsigned i = 0; i < this->checkboxs.size(); ++i)
				if (this->checkboxs[i])
					this->checkboxs[i]->use(event);
		}

		void UI::updateCheckboxs(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->checkboxs.size(); ++i)
				if (this->checkboxs[i])
					this->checkboxs[i]->update(window);
		}

		// Slider methods

		void UI::addSlider(pi::ui::Slider& slider)
		{
			for (unsigned i = 0; i < this->sliders.size(); ++i)
				if (!this->sliders[i])
				{
					this->sliders[i] = &slider; break;
				}
		}

		void UI::useSliders(sf::Event& event)
		{
			for (unsigned i = 0; i < this->sliders.size(); ++i)
				if (this->sliders[i])
					this->sliders[i]->use(event);
		}

		void UI::updateSliders(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->sliders.size(); ++i)
				if (this->sliders[i])
					this->sliders[i]->update(window);
		}

		void UI::selectedSliders(sf::Event& event)
		{
			for (unsigned i = 0; i < this->sliders.size(); ++i)
				if (this->sliders[i])
					this->sliders[i]->selected(event);
		}

		void UI::callbackSliders()
		{
			for (unsigned i = 0; i < this->sliders.size(); ++i)
				if (this->sliders[i])
					this->sliders[i]->callback();
		}

		void UI::releasedSliders()
		{
			for (unsigned i = 0; i < this->sliders.size(); ++i)
				if (this->sliders[i])
					this->sliders[i]->released();
		}

		// List 

		void UI::addList(pi::ui::List &list)
		{
			for (unsigned i = 0; i < this->lists.size(); ++i)
				if (!this->lists[i])
				{
					this->lists[i] = &list; break;
				}
		}

		void UI::useLists(sf::Event& event)
		{
			for (unsigned i = 0; i < this->lists.size(); ++i)
				if (this->lists[i])
					this->lists[i]->use(event);
		}

		void UI::updateLists(sf::RenderWindow& window)
		{
			for (unsigned i = 0; i < this->lists.size(); ++i)
				if (this->lists[i])
					this->lists[i]->update(window);
		}

		void UI::descripitonLists(sf::Event& event)
		{
			for (unsigned i = 0; i < this->lists.size(); ++i)
				if (this->lists[i])
					this->lists[i]->description(event);
		}
		
	}
}