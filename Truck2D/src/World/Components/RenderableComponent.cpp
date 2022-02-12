#include "RenderableComponent.h"
#include <World/Components/Spatial.h>
#include <World/Entity.h>
#include <World/World.h>
RenderableComponent::RenderableComponent(Mesh* mesh, ShaderProgram* program, Texture2D* texture,const glm::vec2& tiling)
{
    m_Mesh = mesh;
    m_Program = program;
    m_Texture = texture;
    m_Tiling = tiling;
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

glm::vec2 RenderableComponent::GetTiling() const
{
    return m_Tiling;
}

void RenderableComponent::OnInitialize()
{
    Component::OnInitialize();

    /*
    * Register itself to owner world's renderable list
    */
    GetOwnerEntity()->GetOwnerWorld()->RegisterRenderable(this);
}
