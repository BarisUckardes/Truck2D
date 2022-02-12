#pragma once
#include <World/Component.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

/// <summary>
/// A component which holds the spatial information about the entity
/// </summary>
class EXPORT Spatial : public Component
{
public:
	Spatial();
	~Spatial() = default;

	virtual bool ShouldTick() const override { return false; }
	virtual void OnInitialize() override {}
	virtual void OnTick(float delta) override {}


	/// <summary>
	/// Returns the world matrix of this entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::mat4 GetModelMatrix() const;

	/// <summary>
	/// Returns the position of the entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec3 GetPosition() const;

	/// <summary>
	/// Returns the rotation of the entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec3 GetRotation() const;

	/// <summary>
	/// Returns the scale of the entity
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec3 GetScale() const;


	/// <summary>
	/// Sets the anchor position
	/// </summary>
	/// <param name="anchor"></param>
	void SetAnchor(const glm::vec3& anchor);

	/// <summary>
	/// Sets the entity position
	/// </summary>
	/// <param name="position"></param>
	FORCEINLINE void SetPosition(const glm::vec3& position);

	/// <summary>
	/// Sets the entity rotation
	/// </summary>
	/// <param name="rotation"></param>
	FORCEINLINE void SetRotation(const glm::vec3& rotation);

	/// <summary>
	/// Sets the entity scale
	/// </summary>
	/// <param name="scale"></param>
	FORCEINLINE void SetScale(const glm::vec3& scale);
private:
	glm::vec3 m_Position;
	glm::vec3 m_Rotation;
	glm::vec3 m_Scale;
	glm::vec3 m_Anchor;
};

