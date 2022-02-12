#pragma once
#include <World/Component.h>
#include <Memory/Array.h>

/// <summary>
/// Component class which controls truck movements
/// </summary>
class TruckController : public Component
{
public:
	TruckController(float movementSpeed, float angleSpeed,const Array<Spatial*>& tires);
	~TruckController() = default;

	// Inherited via Component
	virtual bool ShouldTick() const override;
	virtual void OnTick(float deltaTime) override;
private:
	Array<Spatial*> m_Tires;
	float m_MovementSpeed;
	float m_CargoAngleSpeed;
};

