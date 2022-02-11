#include "RenderableComponent.h"
#include <World/Components/Spatial.h>
#include <World/Entity.h>
#include <World/World.h>
RenderableComponent::RenderableComponent(Mesh* mesh, ShaderProgram* program, Texture2D* texture)
{
    m_Mesh = mesh;
    m_Program = program;
    m_Texture = texture;
}

RenderableComponent::~RenderableComponent()
{

}

Mesh* RenderableComponent::GetMesh() const
{
    return m_Mesh;
}

ShaderProgram* RenderableComponent::GetProgram() const
{
    return m_Program;
}

Texture2D* RenderableComponent::GetTexture() const
{
    return m_Texture;
}

void RenderableComponent::OnInitialize()
{
    Component::OnInitialize();

    GetOwnerEntity()->GetOwnerWorld()->RegisterRenderable(this);
}
