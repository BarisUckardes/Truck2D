#pragma once
#include <Core/Core.h>
#include <Memory/String.h>
#include <Memory/Array.h>
#include <World/Components/Spatial.h>


class World;

/// <summary>
/// Represents a simple container for the actual scripting objects(components)
/// Can register polymorhphic components to execute different behaviour
/// </summary>
class EXPORT Entity
{
	friend class World;
public:

	/// <summary>
	/// Registers an component via templated type
	/// </summary>
	/// <typeparam name="TComponent"></typeparam>
	/// <typeparam name="...TParameters"></typeparam>
	/// <param name="...parameters"></param>
	/// <returns></returns>
	template<typename TComponent,typename ...TParameters>
	TComponent* AddComponent(TParameters... parameters);

	/// <summary>
	/// Returns the owner world of this entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE World* GetOwnerWorld() const;

	/// <summary>
	/// Returns the spatial component of this entity
	/// Each entity has on spatial component.
	/// Its mandatory
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Spatial* GetSpatial() const;

	/// <summary>
	/// Returns the entity name
	/// </summary>
	/// <returns></returns>
	FORCEINLINE String GetName() const;

	/// <summary>
	/// Sets the entity name
	/// </summary>
	/// <param name="name"></param>
	void SetName(const String& name);
private:
	Entity(const String name = "Default Entity Name");
	~Entity();

	/// <summary>
	/// An internal owner world setter for initialization purpopses
	/// </summary>
	/// <param name="world"></param>
	void SetOwnerWorldInternal(World* world);

	Array<Component*> m_Components;
	World* m_OwnerWorld;
	Spatial* m_Spatial;
	String m_Name;
};

template<typename TComponent, typename ...TParameters>
inline TComponent* Entity::AddComponent(TParameters ...parameters)
{
	/*
	* Create new component
	*/
	TComponent* component = new TComponent(parameters...);

	/*
	* Set spatial
	*/
	component->SetOwnerEntityInternal(this);

	/*
	* Proc OnInitialize
	*/
	component->OnInitialize();

	/*
	* Register
	*/
	m_Components.Add(component);

	return component;
}
