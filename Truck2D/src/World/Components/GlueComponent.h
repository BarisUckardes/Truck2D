#pragma once
#include <World/Component.h>
#include <World/Components/Spatial.h>
#include <Memory/Array.h>
#include <glm/vec3.hpp>

/// <summary>
/// Single responsbility component class.
/// Simply hold together the target components such as tires and truck cargo
/// </summary>
class GlueComponent : public Component
{
public:
	GlueComponent(const Array<Spatial*>& targetComponents);
	~GlueComponent() = default;

	virtual void OnInitialize() override;
	virtual bool ShouldTick() const override;
	virtual void OnTick(float deltaTime) override;

private:
	Array<Spatial*> m_TargetComponents;
	Array<glm::vec3> m_Strides;

	
};

