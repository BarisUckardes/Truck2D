#pragma once
#include <Core/Core.h>
#include <Memory/String.h>
#include <Memory/Array.h>
struct GLFWwindow;

/// <summary>
/// Window which handles input broadcasting,poll window messages and swapbuffers.
/// Uses glfw for native windowing
/// </summary>
class EXPORT Window
{
public:
	Window(const String& title, unsigned int width, unsigned int height);
	~Window();

	/// <summary>
	/// Called when window resized
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	void OnWindowResize(unsigned int width, unsigned int height);

	/// <summary>
	/// Called when mouse moved
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void OnMouseMove(double x, double y);

	/// <summary>
	/// Called when a key is down
	/// </summary>
	/// <param name="key"></param>
	void OnKeyDown(unsigned int key);

	/// <summary>
	/// Called when a key is up
	/// </summary>
	/// <param name="key"></param>
	void OnKeyUp(unsigned int key);

	/// <summary>
	/// Pumps all the buffered window events
	/// </summary>
	void PollWindowMessages();

	/// <summary>
	/// Swaps the swapchain buffers
	/// </summary>
	void Swapbuffers();

	/// <summary>
	/// Returns the current window width
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetWidth() const;

	/// <summary>
	/// Returns the current window height
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetHeight() const;
private:
	String m_Title;
	unsigned int m_Width;
	unsigned int m_Height;
	GLFWwindow* m_NativeWindow;
};