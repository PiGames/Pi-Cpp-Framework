#pragma once

#include <array>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>
#include "Component.hpp"

namespace pi
{
	// Component Cache
	// Use it if you want to add component to your Game Object
	class ComponentCache
	{
	public:
		ComponentCache();

		// Returns Component from cache
		// Added component must inherit from Updatable or Drawable Component
		template<class T, class ...Args>
		T* getComponent(Args&& ...args);

		// Refreshes cache - resets unused Components 
		// Call it when you delete Entities to free cache
		void refresh();
		// Updates Updatable Components
		// deltaTime - frame time in seconds
		void update(float deltaTime);
		// Draws Drawable Components
		void draw(sf::RenderTarget& target, sf::RenderStates states);

	private:
		static const std::uint16_t MAX_COMPONENT_COUNT = 1024;

		std::array<std::unique_ptr<UpdatableComponent>, MAX_COMPONENT_COUNT> updatableComponents;
		std::array<std::unique_ptr<DrawableComponent>, MAX_COMPONENT_COUNT> drawableComponents;
	};

	template<class T, class ...Args>
	inline T * ComponentCache::getComponent(Args&& ...args)
	{
		if(!std::is_base_of<BaseComponent, T>::value || !std::is_base_of<UpdatableComponent, T>::value || !std::is_base_of<DrawableComponent, T>::value)
			return nullptr;
		if (std::is_same<BaseComponent, T> || std::is_same<DrawableComponent, T> || std::is_same<DrawableComponent, T>)
			return nullptr;

		if(std::is_base_of<UpdatableComponent, T>::value)
			for(auto& ptr : this->updatableComponents)
				if (!ptr)
				{
					ptr.reset(new T(args));

					return dynamic_cast<T*>(ptr.get());
				}

		else if(std::is_base_of<DrawableComponent, T>::value)
			for(auto& ptr : this->drawableComponents)
				if (!ptr)
				{
					ptr.reset(new T(args));

					return dynamic_cast<T*>(ptr.get());
				}
	}
}