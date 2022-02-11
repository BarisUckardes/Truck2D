#pragma once
#include <World/Component.h>

class Mesh;
class ShaderProgram;
class Texture2D;

/// <summary>
/// Represents a renderable sprite texture component
/// </summary>
class EXPORT RenderableComponent : public Component
{
public:
	RenderableComponent(Mesh* mesh,ShaderProgram* program,Texture2D* texture);
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


	virtual bool ShouldTick() const override { return false; }
	virtual void OnInitialize() override;
	virtual void OnTick(float delta) override {}
private:
	Mesh* m_Mesh;
	ShaderProgram* m_Program;
	Texture2D* m_Texture;
};