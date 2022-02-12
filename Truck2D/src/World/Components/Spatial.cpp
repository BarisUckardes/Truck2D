#include "Spatial.h"
#include <glm/gtc/matrix_transform.hpp>
Spatial::Spatial()
{
    m_Scale = glm::vec3(1.0f);
    m_Anchor = glm::vec3(0);
}
glm::mat4 Spatial::GetModelMatrix() const
{
    glm::mat4x4 model(1.0f);


    model = glm::translate(model, m_Position);

    model = glm::translate(model, m_Anchor);
    model = glm::rotate(model, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0, 0));
    model = glm::rotate(model, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0));
    model = glm::rotate(model, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0, 1.0f));
    model = glm::scale(model, glm::vec3(m_Scale));
    model = glm::translate(model, -m_Anchor);
   
   

    return model;
}

glm::vec3 Spatial::GetPosition() const
{
    return m_Position;
}

glm::vec3 Spatial::GetRotation() const
{
	return m_Rotation;
}

glm::vec3 Spatial::GetScale() const
{
    return m_Scale;
}

void Spatial::SetAnchor(const glm::vec3& anchor)
{
    m_Anchor = anchor;
}

void Spatial::SetPosition(const glm::vec3& position)
{
    m_Position = position;
}

void Spatial::SetRotation(const glm::vec3& rotation)
{
    m_Rotation = rotation;
}

void Spatial::SetScale(const glm::vec3& scale)
{
    m_Scale = scale;
}
