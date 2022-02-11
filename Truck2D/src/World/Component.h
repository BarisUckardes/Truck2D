#pragma once
#include <Core/Core.h>

class Spatial;
class Entity;

/// <summary>
/// Single scripting object to be attached to entities
/// </summary>
class EXPORT Component
{
	friend class Entity;
public:
	Component() = default;
	~Component() = default;

	/// <summary>
	/// Returns whether this component should register itself to the logic tick list
	/// </summary>
	/// <returns></returns>
	virtual bool ShouldTick() const = 0;

	/// <summary>
	/// Called upon first time initialized
	/// </summary>
	virtual void OnInitialize();

	/// <summary>
	/// Called when logic tick list is invoked
	/// </summary>
	/// <param name="deltaTime"></param>
	virtual void OnTick(float deltaTime) = 0;

	/// <summary>
	/// Returns the owner entity of this component
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Entity* GetOwnerEntity() const;

	/// <summary>
	/// Returns the entity spatial component
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Spatial* GetSpatial() const;
private:

	/// <summary>
	/// An internal owner entity setter for intialization purposes
	/// </summary>
	/// <param name="ownerEntity"></param>
	void SetOwnerEntityInternal(Entity* ownerEntity);


	Entity* m_OwnerEntity;
};