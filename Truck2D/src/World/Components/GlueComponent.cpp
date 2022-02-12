#include "GlueComponent.h"


/// <summary>
/// Helper function which is responsible for calculating the starter strides between glue component position and the target component positions
/// </summary>
/// <param name="components"></param>
/// <param name="center"></param>
/// <returns></returns>
Array<glm::vec3> _compute_strides(const Array<Spatial*>& components, const glm::vec3& center)
{
    Array<glm::vec3> strides;
    for (unsigned int i = 0; i < components.GetCursor(); i++)
    {
        strides.Add(components[i]->GetSpatial()->GetPosition() - center);
    }
    return strides;
}
GlueComponent::GlueComponent(const Array<Spatial*>& targetComponents)
{
    /*
    * Initialize member variables
    */
    m_TargetComponents = targetComponents;

}

void GlueComponent::OnInitialize()
{
    Component::OnInitialize();

    /*
    * Calculate strides
    */
    m_Strides = _compute_strides(m_TargetComponents, GetSpatial()->GetPosition());

    /*
    * Set default state
    */
    GetSpatial()->SetPosition(glm::vec3(0, -1.6f, 0));
}

bool GlueComponent::ShouldTick() const
{
    return true;
}

void GlueComponent::OnTick(float deltaTime)
{
    /*
    * Iterate components and glue them
    */
    for (unsigned int i = 0; i < m_TargetComponents.GetCursor(); i++)
    {
        /*
        * Get component
        */
        Spatial* spatial = m_TargetComponents[i];

        /*
        * Get stride
        */
        const glm::vec3 stride = m_Strides[i];

        /*
        * Glue component
        */
        spatial->SetPosition(GetSpatial()->GetPosition() + stride);
    }
}
