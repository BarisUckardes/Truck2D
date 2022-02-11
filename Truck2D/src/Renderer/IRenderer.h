#pragma once

template<typename TElement>
class Array;

class RenderableComponent;
class ObserverComponent;
class Window;
/// <summary>
/// Renderer interface for all custom renderers to implement
/// </summary>
class IRenderer
{
public:
	IRenderer() = default;
	~IRenderer() = default;

	/// <summary>
	/// Renders the wolrd via calling the derived class implementation
	/// </summary>
	/// <param name="renderables"></param>
	/// <param name="observers"></param>
	virtual void Render(Array<RenderableComponent*>& renderables, Array<ObserverComponent*>& observers, const Window* window) = 0;
};