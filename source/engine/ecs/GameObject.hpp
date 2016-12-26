#pragma once

#include <array>
#include <functional>
#include <SFML/System/Vector2.hpp>
#include <vector>

#include "Component.hpp"


namespace pi
{
	// Game Object class
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		// Returns Game Object's name (default <unnamed GameObject>)
		std::string getName();
		// Returns Game Object's posiion (default(0,0))
		std::vector<sf::Vector2i> *getPosition();
		
		// Sets Game Object's name (default <unnamed GameObject>)
		void setName(const std::string& name);
		// Sets Game Object's position (default (0,0))
		void setPosition(std::vector<sf::Vector2i> position)

		// Adds Component to Game Object
		// Use SceneClass->ComponentCache->getComponent<YourComponent>(args)
		// returns pointer to Component
		template<class T>
		T* addComponent(T* component);
		// returns pointer to Component (first occure)
		template<class T>
		T* getComponent();
		// returns pointer to Component that has given name
		// name - component name
		template<class T>
		T* getComponent(const std::string& name);
		// returns true if has Component
		template<class T>
		bool hasComponent();
		// returns true if has Component that has given name
		// name - component name
		template<class T>
		bool hasComponent(const std::string& name);

	private:
		static const std::uint8_t MAX_COMPONENT_COUNT = 64;

		std::string name;
		std::array<UpdatableComponent*, MAX_COMPONENT_COUNT> updatableComponents;
		std::array<DrawableComponent*, MAX_COMPONENT_COUNT> drawableComponents;	

		std::vector<sf::Vector2i> unitPosition;
	};

	template<class T>
	inline T * GameObject::addComponent(T * component)
	{
		if (std::is_base_of<UpdatableComponent, T>::value)
			for (auto* updatable : this->updatableComponents)
				if (updatable == nullptr)
				{
					updatable = component;

					return component;
				}

		else if (std::is_base_of<DrawableComponent, T>::value)
			for (auto* drawable : this->drawableComponents)
				if (drawable == nullptr)
				{
					drawable = component;

					return component;
				}

		// not enough space in component array / it is not Drawable / Updatable Component 

		return nullptr;
	}

	template<class T>
	inline T * GameObject::getComponent()
	{
		std::type_index componentID(typeid(T));

		if (std::is_base_of<UpdatableComponent, T>::value)
			for (auto* updatable : this->updatableComponents)
				if (updatable != nullptr && updatable->type == componentID)
					return dynamic_cast<T*>(updatable);

		else if (std::is_base_of<DrawableComponent, T>::value)
			for (auto* drawable : this->drawableComponents)
				if (drawable != nullptr && drawable->type == componentID)
					return dynamic_cast<T*>(drawable);

		return nullptr;
	}

	template<class T>
	inline T * GameObject::getComponent(const std::string & name)
	{
		std::type_index componentID(typeid(T));

		if (std::is_base_of<UpdatableComponent, T>::value)
			for (auto* updatable : this->updatableComponents)
				if (updatable != nullptr && updatable->type == componentID && updatable->name == name)
					return dynamic_cast<T*>(updatable);

		else if (std::is_base_of<DrawableComponent, T>::value)
			for (auto* drawable : this->drawableComponents)
				if (drawable != nullptr && drawable->type == componentID && updatable->name == name)
					return dynamic_cast<T*>(drawable);

		return nullptr;
	}

	template<class T>
	inline bool GameObject::hasComponent()
	{
		std::type_index componentID(typeid(T));

		if (std::is_base_of<UpdatableComponent, T>::value)
			for (auto* updatable : this->updatableComponents)
				if (updatable != nullptr && updatable->type == componentID)
					return true;

		else if (std::is_base_of<DrawableComponent, T>::value)
			for (auto* drawable : this->drawableComponents)
				if (drawable != nullptr && drawable->type == componentID)
					return true;

		return false;
	}

	template<class T>
	inline bool GameObject::hasComponent(const std::string & name)
	{
		std::type_index componentID(typeid(T));

		if (std::is_base_of<UpdatableComponent, T>::value)
			for (auto* updatable : this->updatableComponents)
				if (updatable != nullptr && updatable->type == componentID && updatable->name == name)
					return true;

		else if (std::is_base_of<DrawableComponent, T>::value)
			for (auto* drawable : this->drawableComponents)
				if (drawable != nullptr && drawable->type == componentID && drawable->name == name)
					return true;

		return false;
	}
}