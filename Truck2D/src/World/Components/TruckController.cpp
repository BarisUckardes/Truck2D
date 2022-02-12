#include "TruckController.h"
#include <Input/Input.h>
#include <Core/Log.h>
#include <World/Components/Spatial.h>

#define TIRE_ROTATE_SPEED  150.0f

/// <summary>
/// Helper function which is responsible for rotation the tires
/// </summary>
/// <param name="tires"></param>
/// <param name="amount"></param>
void _rotate_tires(Array<Spatial*>& tires, float amount)
{
    /*
    * Rotate tires
    */
    for (unsigned int i = 0; i < tires.GetCursor(); i++)
    {
        /*
        * Get spatial
        */
        Spatial* spatial = tires[i];

        /*
        * Set new rotation
        */
        spatial->SetRotation(spatial->GetRotation() + glm::vec3(0, 0, 1) * amount);
    }
}
TruckController::TruckController(float movementSpeed, float angleSpeed,const Array<Spatial*>& tires)
{
    m_MovementSpeed = movementSpeed;
    m_CargoAngleSpeed = angleSpeed;
    m_Tires = tires;
}

bool TruckController::ShouldTick() const
{
    return true;
}

void TruckController::OnTick(float deltaTime)
{
    /*
    * Manage truck movement
    */
    if (Input::IsKeyDown(KEY_RIGHT))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() - glm::vec3(1, 0, 0) * m_MovementSpeed*deltaTime);
        _rotate_tires(m_Tires, deltaTime * TIRE_ROTATE_SPEED*m_MovementSpeed);
    }
    else if (Input::IsKeyDown(KEY_LEFT))
    {
        GetSpatial()->SetPosition(GetSpatial()->GetPosition() + glm::vec3(1, 0, 0) * m_MovementSpeed*deltaTime);
        _rotate_tires(m_Tires, -deltaTime * TIRE_ROTATE_SPEED* m_MovementSpeed);
    }
}
