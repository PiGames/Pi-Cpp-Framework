#pragma once

#include "Component.hpp"
#include <vector>

namespace pi
{
	class GameObject 
	{
	public:    
		template<typename CONDITION>
		using enable_if = typename std::enable_if<CONDITION::value>::type;
		
		GameObject();
		GameObject(GameObject&&) = delete;
		virtual ~GameObject() = default;
		GameObject& operator=(GameObject&&) = delete;

		std::string& getName();
		sf::Vector2f& getPosition();

		void setName(std::string&& name);
		void setPosition(sf::Vector2f&& position);

		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		T* addComponent(T& component)
		{
			this->components.push_back(&component);
			return &component;
		}
		
		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		T* getComponent()
		{
			for (auto& comp : this->components)
				if (comp != nullptr && comp->uniqueType == std::type_index(typeid(T)))
					return dynamic_cast<T*>(comp);

			return nullptr;
		}

		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		T* getComponent(std::string&& name)
		{
			for (auto& comp : this->components)
				if (comp != nullptr && comp->uniqueType == std::type_index(typeid(T)) && comp->name == name)
					return dynamic_cast<T*>(comp);

			return nullptr;
		}

		template <typename T, enable_if<std::is_base_of<Component, T>>...>
		bool hasComponent()
		{
			auto val = this->getComponent<T>();

			if (val != nullptr)
				return true;

			return false;
		}
	
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