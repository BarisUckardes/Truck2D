#pragma once
#include <Renderer/IRenderer.h>

class ForwardRenderer : public IRenderer
{
public:
	ForwardRenderer() = default;
	~ForwardRenderer() = default;

	virtual void Render(Array<RenderableComponent*>& renderables, Array<ObserverComponent*>& observers, const Window* window) override;
};

