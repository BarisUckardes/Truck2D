#include "IRenderer.h"
#include <GLAD/glad.h>
IRenderer::IRenderer()
{
	m_DrawMode = GL_LINE;
}

GPU_PARAMETER IRenderer::GetDrawMode() const
{
	return m_DrawMode;
}

void IRenderer::SetDrawMode(GPU_PARAMETER drawMode)
{
	m_DrawMode = drawMode;
}
