#pragma once
#include <World/Component.h>
#include <glm/mat4x4.hpp>

/// <summary>
/// Represents a camera in the world
/// Only supports writing to swapchain framebuffer
/// </summary>
class EXPORT ObserverComponent : public Component
{
public:
	ObserverComponent(const glm::vec4& clearColor, float orthoSize);
	~ObserverComponent() = default;

	/// <summary>
	/// Sets the clearcolor
	/// </summary>
	/// <param name="clearColor"></param>
	void SetClearColor(const glm::vec4& clearColor);

	/// <summary>
	/// Returns the view matrix
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::mat4 GetViewMatrix() const;

	/// <summary>
	/// Returns the projection matrix
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::mat4 GetProjectionMatrix() const;

	/// <summary>
	/// Returns the clear color
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec4 GetClearColor() const;

	/// <summary>
	/// Returns the ortho size for ortho projection
	/// </summary>
	/// <returns></returns>
	FORCEINLINE float GetOrthoSize() const;


	virtual bool ShouldTick() const override { return false; }
	virtual void OnInitialize() override;
	virtual void OnTick(float delta) override {}
private:
	glm::vec4 m_ClearColor;
	float m_OrthoSize;
};

