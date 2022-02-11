#include "ImGuiRenderer.h"
#include <IMGUI/imgui_impl_opengl3.h>
#include <IMGUI/imgui.h>



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
	

	ImGui::SetCurrentContext(ImGui::CreateContext());
	ImGui_ImplOpenGL3_Init("#version 410");
}

void ImGuiRenderer::NewFrame()
{
	/*
	* Get imgui io
	*/
	ImGuiIO& io = ImGui::GetIO();

	/*
	* Set display size
	*/
	io.DisplaySize = ImVec2(m_Width, m_Height);
	io.DeltaTime = 1.0f / 60.0f; // fixed fps GUI

	ImGui_ImplOpenGL3_NewFrame();
	ImGui::NewFrame();
}

void ImGuiRenderer::RenderFrame()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
