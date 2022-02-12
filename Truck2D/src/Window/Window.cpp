#include "Window.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <Core/Assert.h>

Window* _glfw_get_user_window(GLFWwindow* nativeWindow)
{
	return (Window*)glfwGetWindowUserPointer(nativeWindow);
}

Window::Window(const String& title, unsigned int width, unsigned int height)
{
	/*
	* Initialize glfw
	*/
	ASSERT(glfwInit() == GLFW_TRUE, "GLFW", "GLFW intialization failed!");

	/*
	* Create glfw window
	*/
	GLFWwindow* nativeWindow = glfwCreateWindow(width, height,*title, nullptr,nullptr);

	/*
	* Validate glfw window
	*/
	ASSERT(nativeWindow == GLFW_TRUE, "GLFW", "GLFW window create failed!");

	/*
	* Set glfw user pointer
	*/
	glfwSetWindowUserPointer(nativeWindow, this);

	/*
	* Set events
	*/
	glfwSetCursorPosCallback(
		nativeWindow,
		[](GLFWwindow* nativeWindow,double x,double y)
		{
			/*
			* Get window
			*/
			Window* window = _glfw_get_user_window(nativeWindow);

			window->OnMouseMove(x, y);
		});

	glfwSetWindowCloseCallback(nativeWindow,
		[](GLFWwindow* nativeWindow)
		{
			/*
			* Get window
			*/
			Window* window = _glfw_get_user_window(nativeWindow);
			window->OnWindowClose();
		});
	glfwSetWindowSizeCallback(nativeWindow,
		[](GLFWwindow* nativeWindow, int x, int y)
		{
			/*
			* Get window
			*/
			Window* window = _glfw_get_user_window(nativeWindow);

			window->OnWindowResize(x, y);
		});

	glfwSetKeyCallback(nativeWindow,
		[](GLFWwindow* nativeWindow, int key, int scanCode, int action, int mods)
		{
			/*
			* Get window
			*/
			Window* window = _glfw_get_user_window(nativeWindow);

			switch (action)
			{
				case GLFW_PRESS:
				{
					window->OnKeyDown(key);
					break;
				}
				case GLFW_RELEASE:
				{
					window->OnKeyUp(key);
					break;
				}
			}
		});

	glfwSetMouseButtonCallback(nativeWindow,
		[](GLFWwindow* nativeWindow, int button, int action, int mods)
		{
			/*
			* Get window
			*/
			Window* window = _glfw_get_user_window(nativeWindow);

			switch (action)
			{
				case GLFW_PRESS:
				{
					window->OnMouseDown(button);
					break;
				}
				case GLFW_RELEASE:
				{
					window->OnMouseUp(button);
					break;
				}
			}
		});

	/*
	* Make glfw context current
	*/
	glfwMakeContextCurrent(nativeWindow);

	/*
	* Load glad extensions
	*/
	gladLoadGL();

	/*
	* Set GL message callback if its the debug build
	*/
#ifdef _DEBUG
	glDebugMessageCallback(
		[](GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
		{
			if (severity == GL_DEBUG_SEVERITY_HIGH)
				LOG("OpenGL", "%s", message);
		}
	, nullptr);
#endif


	/*
	* Initialize input
	*/
	m_Keys.Reserve(400);
	for (unsigned int i = 0; i < 400; i++)
	{
		m_Keys[i] = false;
	}
	m_Input = new Input(&m_Keys);

	/*
	* Initialize window members
	*/
	m_Title = title;
	m_Width = width;
	m_Height = height;
	m_NativeWindow = nativeWindow;
}

Window::~Window()
{

}

void Window::OnWindowResize(unsigned int width, unsigned int height)
{
	m_Width = width;
	m_Height = height;

	for (unsigned int i = 0; i < m_OnWindowResizecallback.GetCursor(); i++)
	{
		m_OnWindowResizecallback[i].Invoke(glm::vec2(width, height));
	}
}

void Window::OnMouseMove(double x, double y)
{
	for (unsigned int i = 0; i < m_OnMouseMoveCallbacks.GetCursor(); i++)
	{
		m_OnMouseMoveCallbacks[i].Invoke(glm::vec2(x,y));
	}
}

void Window::OnKeyDown(unsigned int key)
{
	m_Keys[key] = true;
	for (unsigned int i = 0; i < m_OnKeyDownCallbacks.GetCursor(); i++)
	{
		m_OnKeyDownCallbacks[i].Invoke(key);
	}
}

void Window::OnKeyUp(unsigned int key)
{
	m_Keys[key] = false;
	for (unsigned int i = 0; i < m_OnKeyUpCallbacks.GetCursor(); i++)
	{
		m_OnKeyUpCallbacks[i].Invoke(key);
	}
}

void Window::OnMouseDown(unsigned int button)
{
	for (unsigned int i = 0; i < m_OnButtonDownCallbacks.GetCursor(); i++)
	{
		m_OnButtonDownCallbacks[i].Invoke(button);
	}
}

void Window::OnMouseUp(unsigned int button)
{
	for (unsigned int i = 0; i < m_OnButtonUpCallbacks.GetCursor(); i++)
	{
		m_OnButtonUpCallbacks[i].Invoke(button);
	}
}

void Window::OnWindowClose()
{
	m_bHasCloseRequest = true;
}

void Window::PollWindowMessages()
{
	/*
	* Poll messages
	*/
	glfwPollEvents();
}

void Window::Swapbuffers()
{
	glfwSwapBuffers(m_NativeWindow);
}

void Window::RegisterKeyDownCallback(Delegate<void, unsigned int>& callback)
{
	m_OnKeyDownCallbacks.Add(callback);
}

void Window::RegisterKeyUpCallback(Delegate<void, unsigned int>& callback)
{
	m_OnKeyUpCallbacks.Add(callback);
}

void Window::RegisterButtonDownCallback(Delegate<void, unsigned int>& callback)
{
	m_OnButtonDownCallbacks.Add(callback);
}

void Window::RegisterButtonUpCallback(Delegate<void, unsigned int>& callback)
{
	m_OnButtonUpCallbacks.Add(callback);
}

void Window::RegisterMouseMoveCallback(Delegate<void, const glm::vec2&>& callback)
{
	m_OnMouseMoveCallbacks.Add(callback);
}

void Window::RegisterWindowResizeCallback(Delegate<void, const glm::vec2&>& callback)
{
	m_OnWindowResizecallback.Add(callback);
}



unsigned int Window::GetWidth() const
{
	return m_Width;
}

unsigned int Window::GetHeight() const
{
	return m_Height;
}

bool Window::HasCloseRequest() const
{
	return m_bHasCloseRequest;
}
