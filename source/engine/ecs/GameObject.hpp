#pragma once

#include "Component.hpp"
#include <vector>

namespace pi
{
	// Game Object class
	// You can add Components to it and intherit from it
	class GameObject 
	{
	public:    
		template<typename CONDITION>
		using enable_if = typename std::enable_if<CONDITION::value>::type;
		
		GameObject();
		GameObject(GameObject&&) = delete;
		virtual ~GameObject() = default;
		GameObject& operator=(GameObject&&) = delete;

		// Returns reference to it name
		std::string& getName();
		// Returns reference to it position
		sf::Vector2f& getPosition();

		// Sets its name
		void setName(std::string&& name);
		// Sets its position
		void setPosition(sf::Vector2f&& position);

		// Adds Component to Game Object
		// Don't forget to use Component Cache!
		// Returns pointer to added Component
		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		T* addComponent(T& component)
		{
			this->components.push_back(&component);
			return &component;
		}
		// Returns Component of given type
		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		T* getComponent()
		{
			for (auto& comp : this->components)
				if (comp != nullptr && comp->uniqueType == std::type_index(typeid(T)))
					return dynamic_cast<T*>(comp);

			return nullptr;
		}
		// Returns Component of given type and name
		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		T* getComponent(std::string&& name)
		{
			for (auto& comp : this->components)
				if (comp != nullptr && comp->uniqueType == std::type_index(typeid(T)) && comp->name == name)
					return dynamic_cast<T*>(comp);

			return nullptr;
		}
		// Returns true if Component of given type was found
		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		bool hasComponent()
		{
			auto val = this->getComponent<T>();

			if (val != nullptr)
				return true;

			return false;
		}
		// Returns true if Component of given type and name was found
		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		bool hasComponent(std::string&& name)
		{
			auto val = this->getComponent<T>(name);

			if (val != nullptr)
				return true;

			return false;
		}

	protected:
		std::string name;
		sf::Vector2f position;
		std::vector<Component*> components;
	};
}