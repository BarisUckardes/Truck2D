#include "WorldGUIPainter.h"
#include <World/Components/ObserverComponent.h>
#include <World/Components/Spatial.h>
#include <Renderer/IRenderer.h>
#include <GLAD/glad.h>
#include <IMGUI/imgui.h>
#include <glm/trigonometric.hpp>
#include <Core/Log.h>
WorldGUIPainter::WorldGUIPainter(IRenderer* renderer, ObserverComponent* observer, Spatial* cargo)
{
	m_Renderer = renderer;
	m_Observer = observer;
	m_Cargo = cargo;
}
String WorldGUIPainter::GetWindowName() const
{
	return "Performance Metrics";
}
void WorldGUIPainter::OnGUIEnable()
{
}

bool drawMode = true;
void WorldGUIPainter::OnGUIPaint(float deltaTime)
{
	ImGui::Text("Performance");
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::Text("Delta Time: %f", deltaTime);
	ImGui::Text("FPS: %d", (unsigned int)(10.f / deltaTime));

	ImGui::Spacing();
	ImGui::Spacing();
	ImGui::Spacing();

	ImGui::Text("Background");
	ImGui::Separator();
	ImGui::Spacing();
	glm::vec4 color = m_Observer->GetClearColor();
	ImGui::ColorEdit4("", &color.x);
	m_Observer->SetClearColor(color);

	ImGui::Spacing();
	ImGui::Spacing();
	ImGui::Spacing();

	ImGui::Text("Draw Mode");
	ImGui::Separator();
	ImGui::Checkbox("Mode", &drawMode);
	if (drawMode)
	{
		m_Renderer->SetDrawMode(GL_FILL);
	}
	else
	{
		m_Renderer->SetDrawMode(GL_LINE);
	}

	ImGui::Spacing();
	ImGui::Spacing();
	ImGui::Spacing();

	ImGui::Text("Truck");
	ImGui::Separator();
	float angle = abs(m_Cargo->GetSpatial()->GetRotation().z);
	ImGui::Text("Cargo angle:");
	ImGui::SameLine();
	ImGui::SliderFloat("##angleid",&angle, 0, 45);
	m_Cargo->GetSpatial()->SetRotation(glm::vec3(0, 0, -abs(angle)));
}

void WorldGUIPainter::OnGUIFinalize()
{
}
