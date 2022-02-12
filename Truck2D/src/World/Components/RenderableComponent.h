#pragma once
#include <World/Component.h>
#include <glm/vec2.hpp>
class Mesh;
class ShaderProgram;
class Texture2D;

/// <summary>
/// Represents a renderable sprite texture component
/// </summary>
class EXPORT RenderableComponent : public Component
{
public:
	RenderableComponent(Mesh* mesh,ShaderProgram* program,Texture2D* texture,const glm::vec2& tiling = glm::vec2(1.0f,1.0f));
	~RenderableComponent();

	/// <summary>
	/// Returns the mesh
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Mesh* GetMesh() const;

	/// <summary>
	/// Returns the program
	/// </summary>
	/// <returns></returns>
	FORCEINLINE ShaderProgram* GetProgram() const;

	/// <summary>
	/// Returns the texture
	/// </summary>
	/// <returns></returns>
	FORCEINLINE Texture2D* GetTexture() const;

	/// <summary>
	/// Returns the tiling factor of this renderable component
	/// </summary>
	/// <returns></returns>
	FORCEINLINE glm::vec2 GetTiling() const;

	virtual bool ShouldTick() const override { return false; }
	virtual void OnInitialize() override;
	virtual void OnTick(float delta) override {}
private:
	glm::vec2 m_Tiling;
	Mesh* m_Mesh;
	ShaderProgram* m_Program;
	Texture2D* m_Texture;
};