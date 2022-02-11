#include "Component.h"
#include <World/Entity.h>
#include <World/World.h>
void Component::OnInitialize()
{
	if(ShouldTick())
		GetOwnerEntity()->GetOwnerWorld()->RegisterLogicComponent(this);
}

Entity* Component::GetOwnerEntity() const
{
	return m_OwnerEntity;
}

Spatial* Component::GetSpatial() const
{
	return m_OwnerEntity->GetSpatial();
}

void Component::SetOwnerEntityInternal(Entity* ownerEntity)
{
	m_OwnerEntity = ownerEntity;
}
