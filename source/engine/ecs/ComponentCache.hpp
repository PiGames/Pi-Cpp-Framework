#pragma once
#include "Component.hpp"
#include "engine/Config.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <array>

namespace pi
{
	template<typename CONDITION>
	using enable_if = typename std::enable_if<CONDITION::value>::type;

	// Component Cache class
	class ComponentCache final :
		public sf::Drawable
	{
	private:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	public:
		ComponentCache();

		ComponentCache(ComponentCache&&) = delete;
		ComponentCache& operator=(ComponentCache&&) = delete;

		// Returns pointer to added Component
		// Also returns nullptr if there is more than 1024 Components of ComponentType
		template <typename T, enable_if<std::is_base_of<Component, T>>..., class ...Args>
		T* get(Args&& ...args)
		{
			if (!std::is_base_of<Component, T>::value)
				return nullptr;

			T component(args...);

			if (component.getComponentType() == ComponentType::Dry)
			{
				for(auto& dry : this->dry)
					if (!dry)
					{
						dry.reset(new T(args...));

						return dynamic_cast<T*>(dry.get());
					}
			}

			if (component.getComponentType() == ComponentType::Updatable)
			{
				for (auto& updatable : this->updatable)
					if (!updatable)
					{
						updatable.reset(new T(args...));

						return dynamic_cast<T*>(updatable.get());
					}
			}

			if (component.getComponentType() == ComponentType::Drawable)
			{
				for (auto& drawable : this->drawable)
					if (!drawable)
					{
						drawable.reset(new T(args...));

						return dynamic_cast<T*>(drawable.get());
					}
			}

			if (component.getComponentType() == ComponentType::Both)
			{
				for (auto& both : this->both)
					if (!both)
					{
						both.reset(new T(args...));

						return dynamic_cast<T*>(both.get());
					}
			}

			return nullptr;
		}

		void update(float deltaTime);

	private:
		std::array<std::unique_ptr<Component>, constants::componentCache::MAX_COMPONENT_COUNT> dry;
		std::array<std::unique_ptr<Component>, constants::componentCache::MAX_COMPONENT_COUNT> updatable;
		std::array<std::unique_ptr<Component>, constants::componentCache::MAX_COMPONENT_COUNT> drawable;
		std::array<std::unique_ptr<Component>, constants::componentCache::MAX_COMPONENT_COUNT> both;
	};
}