#include "Entity.h"

World* Entity::GetOwnerWorld() const
{
	return m_OwnerWorld;
}

Spatial* Entity::GetSpatial() const
{
	return m_Spatial;
}

String Entity::GetName() const
{
	return m_Name;
}

void Entity::SetName(const String& name)
{
	m_Name = name;
}

Entity::Entity(const String name)
{
	/*
	* Set name
	*/
	m_Name = name;

	/*
	* Create spatial component
	*/
	Spatial* spatial = new Spatial();

	/*
	* Register spatial owner entity
	*/
	((Component*)spatial)->SetOwnerEntityInternal(this);

	/*
	* Set spatial
	*/
	m_Spatial = spatial;
}

Entity::~Entity()
{

}

void Entity::SetOwnerWorldInternal(World* world)
{
	m_OwnerWorld = world;
}
