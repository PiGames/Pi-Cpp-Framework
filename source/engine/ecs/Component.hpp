#pragma once

#include <string>
#include <typeindex>
#include <typeinfo>
#include <SFML/Graphics/Drawable.hpp>

namespace pi
{
	class GameObject;

	using UniqueType = std::type_index;

	// Base Component class
	class BaseComponent
	{
		friend class GameObject;

	public:
		// gameObject - pointer to Game Object that owns this component
		// child - poitner to component that inherits from Base Component
		template<class T>
		BaseComponent(GameObject* gameObject, T* child);
		virtual ~BaseComponent() = default;
		// Sets Component's name
		// name - name
		void setName(const std::string& name);

		// Returns Component's name
		std::string getName();
		// Returns pointer to Component's owning Game Object
		GameObject* getGameObject();

		operator bool() const;

	protected:
		std::string name;
		UniqueType type;
		GameObject* gameObject;
	};
	
	// Drawable Component class - draws sf::Drawables on screen
	// Don't forget to overwrite:
	// (private)
	// void draw(sf::RenderTarget&, sf::RenderStates) const
	class DrawableComponent :
		public BaseComponent,
		public sf::Drawable
	{
	public:
		// gameObject - pointer to Game Object that owns this component
		// child - poitner to component that inherits from Drawable Component
		template<class T>
		DrawableComponent(GameObject* gameObject, T* child);
	};

	// Updatable Component class - updates component in game loop
	// Don't forget to overwrite:
	// void update(float)
	class UpdatableComponent :
		public BaseComponent
	{
	public:
		// gameObject - pointer to Game Object that owns this component
		// child - poitner to component that inherits from Updatable Component
		template<class T>
		UpdatableComponent(GameObject* gameObject, T* child);

		// Updates Component's logic
		// deltaTime - frame time in seconds
		virtual void update(float deltaTime) = 0;
	};


	template<class T>
	inline BaseComponent::BaseComponent(GameObject* gameObject, T* child) :
		type(typeid(T))
	{
		this->name = "<unnamed component>";
		// Game Object cannot be nullptr! In future here will be assert
		this->gameObject = gameObject;
	}

	template<class T>
	inline DrawableComponent::DrawableComponent(GameObject * gameObject, T * child) :BaseComponent(gameObject, child)
	{
	}

	template<class T>
	inline UpdatableComponent::UpdatableComponent(GameObject * gameObject, T * child) :BaseComponent(gameObject, child)
	{
	}
}