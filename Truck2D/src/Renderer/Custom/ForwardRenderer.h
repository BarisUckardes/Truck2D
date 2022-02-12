#pragma once
#include <Renderer/IRenderer.h>

/// <summary>
/// Simple forward rendering pipeline implementation
/// Iterates renderable objects and draws them by their order (Painting rule)
/// </summary>
class ForwardRenderer : public IRenderer
{
public:
	ForwardRenderer() = default;
	~ForwardRenderer() = default;

	virtual void Render(Array<RenderableComponent*>& renderables, Array<ObserverComponent*>& observers, const Window* window) override;
};

