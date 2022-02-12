#pragma once
#include <Core/Core.h>
#include <Memory/Array.h>
#include <glm/vec2.hpp>
class IGUIPainter;

/// <summary>
/// Simple interface for imgui rendering operations
/// </summary>
class EXPORT ImGuiRenderer
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
	void NewFrame(float deltaTime);

	/// <summary>
	/// Renders the imgui render data with the created api backend
	/// </summary>
	void RenderFrame();

	/// <summary>
	/// Runs all the painter behaviours
	/// </summary>
	void RenderPainters();

	/// <summary>
	/// Called when imgui renderer received a key down event
	/// </summary>
	/// <param name="key"></param>
	void OnKeyDown(unsigned int key);

	/// <summary>
	/// Called when imgui renderer received a key up event
	/// </summary>
	/// <param name="key"></param>
	void OnKeyUp(unsigned int key);

	/// <summary>
	/// Called when imgui renderer received a button down event
	/// </summary>
	/// <param name="button"></param>
	void OnButtonDown(unsigned int button);

	/// <summary>
	/// Called when imgui renderer received a button up event
	/// </summary>
	/// <param name="button"></param>
	void OnButtonUp(unsigned int button);

	/// <summary>
	/// Called when imgui renderer received a mouse moved event
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void OnMouseMove(const glm::vec2& pos);

	/// <summary>
	/// Called when imgui renderer received a window resized event
	/// </summary>
	/// <param name="size"></param>
	void OnWindowResized(const glm::vec2& size);

	/// <summary>
	/// Registers anew painter behaviour
	/// </summary>
	/// <typeparam name="TGUIPainter"></typeparam>
	/// <typeparam name="...TParamaeters"></typeparam>
	/// <param name="...parameters"></param>
	template<typename TGUIPainter, typename... TParamaeters>
	void RegisterGUIPainter(TParamaeters... parameters);

private:
	Array<IGUIPainter*> m_Painters;
	unsigned int m_Width;
	unsigned int m_Height;
	float m_DeltaTime;
};

template<typename TGUIPainter, typename ...TParamaeters>
inline void ImGuiRenderer::RegisterGUIPainter(TParamaeters ...parameters)
{
	/*
	* Create painter
	*/
	TGUIPainter* painter = new TGUIPainter(parameters...);

	/*
	* Proc initialize
	*/
	painter->OnGUIEnable();

	/*
	* Register
	*/
	m_Painters.Add(painter);
}
