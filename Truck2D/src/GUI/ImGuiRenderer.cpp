#include "ImGuiRenderer.h"
#include <GUI/IGUIPainter.h>
#include <Events/Delegate.h>
#include <IMGUI/imgui_impl_opengl3.h>
#include <IMGUI/imgui.h>
#include <Core/Log.h>



ImGuiRenderer::ImGuiRenderer(unsigned int width, unsigned int height)
{
	m_Width = width;
	m_Height = height;
}

ImGuiRenderer::~ImGuiRenderer()
{

}

void ImGuiRenderer::CreateApi()
{
	/*
	* Set current context
	*/
	ImGui::SetCurrentContext(ImGui::CreateContext());

	/*
	* Initialize imgui OpenGL implementation
	*/
	ImGui_ImplOpenGL3_Init("#version 410");
}

void ImGuiRenderer::NewFrame(float deltaTime)
{
	/*
	* Get imgui io
	*/
	ImGuiIO& io = ImGui::GetIO();

	/*
	* Set display size
	*/
	io.DisplaySize = ImVec2(m_Width, m_Height);

	/*
	* Set dleta size
	*/
	io.DeltaTime = deltaTime; // fixed fps GUI
	m_DeltaTime = deltaTime;

	/*
	* Create imgui OpenGL new frame implementation
	*/
	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();
}

void ImGuiRenderer::RenderFrame()
{
	/*
	* Render imgui OpenGL3 render data implementation
	*/
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiRenderer::RenderPainters()
{
	/*
	* Execute gui painter objects
	*/
	for (unsigned int i = 0; i < m_Painters.GetCursor(); i++)
	{
		if (ImGui::Begin(*m_Painters[i]->GetWindowName()))
		{
			m_Painters[i]->OnGUIPaint(m_DeltaTime);
		}
		ImGui::End();
	}
}

void ImGuiRenderer::OnKeyDown(unsigned int key)
{
	ImGuiIO& io = ImGui::GetIO();
	io.KeysDown[key] = true;
}

void ImGuiRenderer::OnKeyUp(unsigned int key)
{
	ImGuiIO& io = ImGui::GetIO();
	io.KeysDown[key] = false;
}

void ImGuiRenderer::OnButtonDown(unsigned int button)
{
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDown[button] = true;
}

void ImGuiRenderer::OnButtonUp(unsigned int button)
{
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDown[button] = false;
}

void ImGuiRenderer::OnMouseMove(const glm::vec2& pos)
{
	ImGuiIO& io = ImGui::GetIO();
	io.MousePos = ImVec2(pos.x,pos.y);
}

void ImGuiRenderer::OnWindowResized(const glm::vec2& size)
{
	ImGuiIO& io = ImGui::GetIO();
	io.DisplaySize = ImVec2(size.x, size.y);
	io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

	m_Width = size.x;
	m_Height = size.y;
}


