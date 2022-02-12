#pragma once
#include <Core/Core.h>
#include <Memory/Array.h>

class Window;
class Entity;
class Component;
class RenderableComponent;
class ObserverComponent;
class IRenderer;
class ILogicSolver;
class ImGuiRenderer;
class IGUIPainter;
/// <summary>
/// Encapsulates large amount of scenary data.
/// Entities,components....
/// Logic solvers and renderers
/// </summary>
class EXPORT World
{
public:
	World();
	~World();

	/// <summary>
	/// Creates new entity for this world
	/// </summary>
	/// <returns></returns>
	Entity* CreateEntity();

	/// <summary>
	/// Registers a custom renderer via template type
	/// </summary>
	/// <typeparam name="TRenderer"></typeparam>
	/// <typeparam name="...TParameters"></typeparam>
	/// <param name="...parameters"></param>
	template<typename TRenderer,typename... TParameters>
	TRenderer* RegisterRenderer(TParameters... parameters);

	/// <summary>
	/// Registers a custom logic solver via template type
	/// </summary>
	/// <typeparam name="TLogicSolver"></typeparam>
	/// <typeparam name="...TParameters"></typeparam>
	/// <param name="...parameters"></param>
	template<typename TLogicSolver,typename... TParameters>
	TLogicSolver* RegisterLogicSolver(TParameters... parameters);


	/// <summary>
	/// Ticks the world
	/// Calls the logic solver
	/// Calls the renderer
	/// </summary>
	/// <param name="window"></param>
	void TickWorld(const Window* window,float delta);

	/// <summary>
	/// Called when a renderable registered
	/// </summary>
	/// <param name="component"></param>
	void RegisterRenderable(RenderableComponent* component);

	/// <summary>
	/// Called when a observer registered
	/// </summary>
	/// <param name="component"></param>
	void RegisterObserver(ObserverComponent* component);

	/// <summary>
	/// Called when a tickable component registered
	/// </summary>
	/// <param name="component"></param>
	void RegisterLogicComponent(Component* component);
private:

	Array<Entity*> m_Entities;
	Array<Component*> m_LogicComponents;
	Array<RenderableComponent*> m_RenderableComponents;
	Array<ObserverComponent*> m_ObserverComponents;
	IRenderer* m_Renderer;
	ILogicSolver* m_LogicSolver;
};

template<typename TRenderer, typename ...TParameters>
inline TRenderer* World::RegisterRenderer(TParameters ...parameters)
{
	m_Renderer = new TRenderer(parameters...);
	return (TRenderer*)m_Renderer;

}

template<typename TLogicSolver, typename ...TParameters>
inline TLogicSolver* World::RegisterLogicSolver(TParameters ...parameters)
{
	m_LogicSolver = new TLogicSolver(parameters...);
	return (TLogicSolver*)m_LogicSolver;
}
