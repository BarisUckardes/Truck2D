#pragma once
#include <Core/Core.h>
#include <Memory/String.h>
#include <Memory/Array.h>
#include <Events/Delegate.h>
#include <glm/vec2.hpp>
#include <Input/Input.h>
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
	/// Returns the current window width
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetWidth() const;

	/// <summary>
	/// Returns the current window height
	/// </summary>
	/// <returns></returns>
	FORCEINLINE unsigned int GetHeight() const;

	/// <summary>
	/// Returns whether this window has a close request or not
	/// </summary>
	/// <returns></returns>
	FORCEINLINE bool HasCloseRequest() const;

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
	/// Called when a mouse button is down
	/// </summary>
	/// <param name="button"></param>
	void OnMouseDown(unsigned int button);

	/// <summary>
	/// called when a mouse button is up
	/// </summary>
	/// <param name="button"></param>
	void OnMouseUp(unsigned int button);

	/// <summary>
	/// Called when close request broadcasted from the native window
	/// </summary>
	void OnWindowClose();

	/// <summary>
	/// Pumps all the buffered window events
	/// </summary>
	void PollWindowMessages();

	/// <summary>
	/// Swaps the swapchain buffers
	/// </summary>
	void Swapbuffers();

	/// <summary>
	/// Registers a key down callback
	/// </summary>
	/// <param name="callback"></param>
	void RegisterKeyDownCallback(Delegate<void, unsigned int>& callback);

	/// <summary>
	/// Registers a key up callback
	/// </summary>
	/// <param name="callback"></param>
	void RegisterKeyUpCallback(Delegate<void, unsigned int>& callback);

	/// <summary>
	/// Registers a button down callback
	/// </summary>
	/// <param name="callback"></param>
	void RegisterButtonDownCallback(Delegate<void, unsigned int>& callback);

	/// <summary>
	/// Regþsters button up callback
	/// </summary>
	/// <param name="callback"></param>
	void RegisterButtonUpCallback(Delegate<void, unsigned int>& callback);

	/// <summary>
	/// Registers mouse move callback
	/// </summary>
	/// <param name="callback"></param>
	void RegisterMouseMoveCallback(Delegate<void, const glm::vec2&>& callback);

	/// <summary>
	/// Registers window resized callback
	/// </summary>
	/// <param name="callback"></param>
	void RegisterWindowResizeCallback(Delegate<void, const glm::vec2&>& callback);
private:
	Array<Delegate<void, unsigned int>> m_OnKeyDownCallbacks;
	Array<Delegate<void, unsigned int>> m_OnKeyUpCallbacks;
	Array<Delegate<void, unsigned int>> m_OnButtonDownCallbacks;
	Array<Delegate<void, unsigned int>> m_OnButtonUpCallbacks;
	Array<Delegate<void, const glm::vec2&>> m_OnMouseMoveCallbacks;
	Array<Delegate<void, const glm::vec2&>> m_OnWindowResizecallback;
	Array<bool> m_Keys;
	GLFWwindow* m_NativeWindow;
	Input* m_Input;
	String m_Title;
	unsigned int m_Width;
	unsigned int m_Height;
	bool m_bHasCloseRequest;
};