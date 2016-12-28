#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <string>
#include <typeinfo>
#include <typeindex>

namespace pi
{
	class GameObject;

	// Component types:
	// Dry - not 'real' component, only added - nothing updates or draws, probably only a flag
	// Updatable - only updates, not draws
	// Drawable - only draws, not updates
	// Both - updates and draws
	enum class ComponentType
	{
		Dry = -1,
		Updatable = 0,
		Drawable,
		Both
	};

	// Component class 
	// You can add it to Game Object
	// Component Type should not be changed in other places than Component's constructor!
	// Private methods to override:
	// void update(float)
	// virtual void draw(sf::RenderTarget&, sf::RenderStates) const
	// Public:
	// ComponentType getComponentType()
	class Component : 
		public sf::Drawable
	{
		friend class ComponentCache;
		friend class GameObject;

	private:
		virtual void update(float);
		virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	public:
		// Component class constructor
		// gameObject - reference to owning Game Object
		// component - component
		template<class T>
		Component(GameObject& gameObject, T* component) noexcept;
		virtual ~Component();

		Component(Component&&) = delete;
		Component& operator=(Component&&) = delete;

		// Returns reference to owning Game Object
		auto& getGameObject();
		// Returns Component type
		virtual ComponentType getComponentType() = 0;
		// Returns reference to Component's name
		auto& getName();
		// Returns Component's unique type id
		std::type_index getUniqueType();

		// Sets Component name
		void setName(std::string&& name);

	protected:
		GameObject& gameObject;
		std::string name;
	
	private:
		std::type_index uniqueType;
	};

	template<class T>
	inline Component::Component(GameObject & gameObject, T * component) noexcept :
		gameObject(gameObject),
		uniqueType(typeid(T))
	{
		this->name = "<unnamed Component>";
	}
}