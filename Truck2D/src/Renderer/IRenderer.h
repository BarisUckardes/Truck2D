#pragma once
#include <Core/Core.h>
template<typename TElement>
class Array;
class RenderableComponent;
class ObserverComponent;
class Window;

/// <summary>
/// Renderer interface for all custom renderers to implement
/// </summary>
class EXPORT IRenderer
{
public:
	IRenderer();
	~IRenderer() = default;

	/// <summary>
	/// Renders the wolrd via calling the derived class implementation
	/// </summary>
	/// <param name="renderables"></param>
	/// <param name="observers"></param>
	virtual void Render(Array<RenderableComponent*>& renderables, Array<ObserverComponent*>& observers, const Window* window) = 0;

	/// <summary>
	/// Returns the draw mode of this renderer
	/// </summary>
	/// <returns></returns>
	FORCEINLINE GPU_PARAMETER GetDrawMode() const;

	/// <summary>
	/// Sets the draw mode for this renderer
	/// </summary>
	/// <param name="drawMode"></param>
	void SetDrawMode(GPU_PARAMETER drawMode) ;
private:
	GPU_PARAMETER m_DrawMode;
};