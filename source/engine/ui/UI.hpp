#pragma once

#include "Element.hpp"
#include "Button.hpp"
#include "Checkbox.hpp"
#include "Slider.hpp"
#include "List.hpp"
#include "engine/Config.hpp"

namespace pi
{
	namespace ui
	{
		class UI final
		{
		public:
			UI();
			UI(sf::RenderWindow&);
			~UI() = default;

			void setWindow(sf::RenderWindow&);
			
			const float getPercent(float procent, float number) const { return number * procent / 100; }
			const sf::Vector2u getWindowSize() const { return this->window->getSize(); }

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
			void callbackSliders();
			void releasedSliders();
			// Slider section end

			// List section start
			void addList(pi::ui::List&);
			void useLists(sf::Event&);
			void updateLists(sf::RenderWindow&);
			void descripitonLists(sf::Event&);
			// List section end

		private:
			static const std::uint8_t MAX_NUMBER_OF_THE_ELEMENTS = 32;

			sf::RenderWindow* window;
			std::array <pi::ui::Button*, constants::ui::MAX_UIELEMENTS> buttons;
			std::array <pi::ui::Checkbox*, constants::ui::MAX_UIELEMENTS> checkboxs;
			std::array <pi::ui::Slider*, constants::ui::MAX_UIELEMENTS> sliders;
			std::array <pi::ui::List*, constants::ui::MAX_UIELEMENTS> lists;
		};
	}
}