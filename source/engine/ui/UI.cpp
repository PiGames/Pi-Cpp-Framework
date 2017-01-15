#include "UI.hpp"

namespace pi
{
	namespace ui
	{
		// Public

		UI::UI()
		{
			this->elementArrayLenght = 0;
		}

		UI::UI(sf::RenderWindow& window)
		{
			this->window = &window;
			this->elementArrayLenght = 0;
		}

		void UI::setWindow(sf::RenderWindow& window)
		{
			this->window = &window;
		}

		// Button methods

		void UI::useButtons(sf::Event& event)
		{
			for (auto &i : this->elements)
				if (i)
					if (i->type == ElementType::button)
						i->use(event);
		}

		void UI::updateButtons(sf::RenderWindow& window)
		{
			for (auto &i : this->elements)
				if (i)
					if (i->type == ElementType::button)
						i->update(window);
		}

		// Checkbox methods

		void UI::useCheckboxs(sf::Event& event)
		{
			for (auto &i : this->elements)
				if (i)
					if (i->type == ElementType::checkbox)
						i->use(event);
		}

		void UI::updateCheckboxs(sf::RenderWindow& window)
		{
			for (auto &i : this->elements)
				if (i)
					if (i->type == ElementType::checkbox)
						i->update(window);
		}

		// Slider methods

		void UI::useSliders(sf::Event& event)
		{
			for (auto &i : this->elements)
				if (i)
					if (i->type == ElementType::slider)
						i->use(event);
		}

		void UI::updateSliders(sf::RenderWindow& window)
		{
			for (auto &i : this->elements)
				if (i)
					if (i->type == ElementType::slider)
						i->update(window);
		}

		// List methods

		void UI::useLists(sf::Event& event)
		{
			for (auto &i : this->elements)
				if (i)
					if (i->type == ElementType::list)
						i->use(event);
		}

		void UI::updateLists(sf::RenderWindow& window)
		{
			for (auto &i : this->elements)
				if (i)
					if (i->type == ElementType::list)
						i->update(window);
		}

	}
}