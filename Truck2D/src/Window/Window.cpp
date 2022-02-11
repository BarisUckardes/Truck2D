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
		});

	glfwSetWindowCloseCallback(nativeWindow,
		[](GLFWwindow* nativeWindow)
		{
			/*
			* Get window
			*/
			Window* window = _glfw_get_user_window(nativeWindow);
		});

	glfwSetKeyCallback(nativeWindow,
		[](GLFWwindow* nativeWindow, int key, int scanCode, int action, int mods)
		{
			/*
			* Get window
			*/
			Window* window = _glfw_get_user_window(nativeWindow);
		});

	glfwSetMouseButtonCallback(nativeWindow,
		[](GLFWwindow* nativeWindow, int button, int action, int mods)
		{
			/*
			* Get window
			*/
			Window* window = _glfw_get_user_window(nativeWindow);
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
}

void Window::OnMouseMove(double x, double y)
{

}

void Window::OnKeyDown(unsigned int key)
{

}

void Window::OnKeyUp(unsigned int key)
{

}

void Window::PollWindowMessages()
{
	glfwPollEvents();
}

void Window::Swapbuffers()
{
	glfwSwapBuffers(m_NativeWindow);
}

unsigned int Window::GetWidth() const
{
	return m_Width;
}

unsigned int Window::GetHeight() const
{
	return m_Height;
}
