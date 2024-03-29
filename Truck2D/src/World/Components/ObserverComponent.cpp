#include "ObserverComponent.h"
#include <World/Components/Spatial.h>
#include <World/Entity.h>
#include <World/World.h>
#include <glm/gtc/matrix_transform.hpp>
ObserverComponent::ObserverComponent(const glm::vec4& clearColor, float orthoSize)
{
    m_ClearColor = clearColor;
    m_OrthoSize = orthoSize;
    m_AspectRatio = 1.0f;

}
void ObserverComponent::SetClearColor(const glm::vec4& clearColor)
{
    m_ClearColor = clearColor;
}

void ObserverComponent::SetAspectRatio(float aspectRatio)
{
    m_AspectRatio = aspectRatio;
}

glm::mat4 ObserverComponent::GetViewMatrix() const
{
    const glm::vec3 position = GetOwnerEntity()->GetSpatial()->GetPosition();
    return glm::lookAt(position, position + glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));;
}

glm::mat4 ObserverComponent::GetProjectionMatrix() const
{
    return glm::ortho(-m_OrthoSize*m_AspectRatio, m_OrthoSize* m_AspectRatio, -m_OrthoSize, m_OrthoSize, 0.001f, 1000.0f);
}

glm::vec4 ObserverComponent::GetClearColor() const
{
    return m_ClearColor;
}

float ObserverComponent::GetOrthoSize() const
{
    return m_OrthoSize;
}

void ObserverComponent::OnInitialize()
{
    Component::OnInitialize();

    /*
    * Register itself to owner world's observer list
    */
    GetOwnerEntity()->GetOwnerWorld()->RegisterObserver(this);
}
