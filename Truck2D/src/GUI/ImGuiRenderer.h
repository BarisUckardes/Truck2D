#pragma once
#include <Core/Core.h>

/// <summary>
/// Simple interface for imgui rendering operations
/// </summary>
class ImGuiRenderer
{
public:
	ImGuiRenderer(unsigned int width,unsigned int height);
	~ImGuiRenderer();

	/// <summary>
	/// Creates proper imgui api backend
	/// </summary>
	void CreateApi();

	/// <summary>
	/// Starts imgui api backend frame
	/// </summary>
	void NewFrame();

	/// <summary>
	/// Renders the imgui render data with the created api backend
	/// </summary>
	void RenderFrame();

	void OnKeyEvent();
private:
	unsigned int m_Width;
	unsigned int m_Height;
};

