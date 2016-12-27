#pragma once
#include "Component.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <array>

namespace pi
{
	template<typename CONDITION>
	using enable_if = typename std::enable_if<CONDITION::value>::type;

	// Component Cache class
	class ComponentCache final:
		public sf::Drawable
	{
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		ComponentCache();

		ComponentCache(ComponentCache&&) = delete;
		ComponentCache& operator=(ComponentCache&&) = delete;
	
		// Returns pointer to added Component
		template <typename T, enable_if<std::is_base_of<Component, T>>..., class ...Args>
		T* get(Args&& ...args)
		{
			if (!std::is_base_of<Component, T>::value)
				return nullptr;

			T* component = new T(args...);

			else if (t->getComponentType() == ComponentType::Updatable)
				for (auto& updatable : this->updatable)
					if (!updatable)
					{
						updatable.reset(component);

						return component;
					}

					else if (t->getComponentType() == ComponentType::Drawable)
						for (auto& drawable : this->drawable)
							if (!drawable)
							{
								drawable.reset(component);

								return component;
							}

			delete component;

			return nullptr;
		}
	
		void update(float deltaTime);

	private:
		static const std::uint16_t MAX_COMPONENT_COUNT = 1024;

		std::array<std::unique_ptr<Component>, MAX_COMPONENT_COUNT> updatable;
		std::array<std::unique_ptr<Component>, MAX_COMPONENT_COUNT> drawable;
	};
}