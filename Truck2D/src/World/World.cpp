#include "World.h"
#include <LogicSolver/ILogicSolver.h>
#include <Renderer/IRenderer.h>
#include <World/Entity.h>
World::World()
{
}
World::~World()
{
}
Entity* World::CreateEntity()
{
	/*
	* Create entity
	*/
	Entity* entity = new Entity();

	/*
	* Set entity owner world
	*/
	entity->SetOwnerWorldInternal(this);

	/*
	* Register entity
	*/
	m_Entities.Add(entity);

	return entity;
}
void World::TickWorld(const Window* window,float delta)
{
	/*
	* Run logic solver
	*/
	m_LogicSolver->Solve(m_LogicComponents, delta);

	/*
	* Run renderer
	*/
	m_Renderer->Render(m_RenderableComponents, m_ObserverComponents,window);
}

void World::RegisterRenderable(RenderableComponent* component)
{
	m_RenderableComponents.Add(component);
}

void World::RegisterObserver(ObserverComponent* component)
{
	m_ObserverComponents.Add(component);
}

void World::RegisterLogicComponent(Component* component)
{
	m_LogicComponents.Add(component);
}
