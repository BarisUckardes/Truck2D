#include <Window/Window.h>
#include <World/World.h>
#include <Game/Game.h>
#include <GUI/ImGuiRenderer.h>
#include <Core/Event.h>
#include <Events/Delegate.h>
#include <chrono>
#include <Core/Log.h>
#define SCREEN_SIZE 1024
int main(int argumentCount, char** arguments)
{
	/*
	* Create window
	*/
	Window window("Truck2D", SCREEN_SIZE, SCREEN_SIZE);

	
	/*
	* Create gui renderer
	*/
	ImGuiRenderer* renderer = new ImGuiRenderer(SCREEN_SIZE, SCREEN_SIZE);
	renderer->CreateApi();

	/*
	* Create world
	*/
	World world;
	create_default_game_scene(world, renderer);

	/*
	* Create imgui events
	*/
	Delegate<void, unsigned int> guiOnKeyDownDelegate = Delegate<void, unsigned int>(BIND_TARGET_EVENT(renderer, ImGuiRenderer::OnKeyDown));
	Delegate<void, unsigned int> guiOnKeyUpDelegate = Delegate<void, unsigned int>(BIND_TARGET_EVENT(renderer, ImGuiRenderer::OnKeyUp));
	Delegate<void, unsigned int> guiOnButtonDownDelegate = Delegate<void, unsigned int>(BIND_TARGET_EVENT(renderer, ImGuiRenderer::OnButtonDown));
	Delegate<void, unsigned int> guiOnButtonUpDelegate = Delegate<void, unsigned int>(BIND_TARGET_EVENT(renderer, ImGuiRenderer::OnButtonUp));
	Delegate<void, const glm::vec2&> guiOnMouseMovedDelegate = Delegate<void,const glm::vec2&>(BIND_TARGET_EVENT(renderer, ImGuiRenderer::OnMouseMove));
	Delegate<void, const glm::vec2&> guiOnWindowResizeDelegate = Delegate<void, const glm::vec2&>(BIND_TARGET_EVENT(renderer, ImGuiRenderer::OnWindowResized));

	window.RegisterKeyDownCallback(guiOnKeyDownDelegate);
	window.RegisterKeyUpCallback(guiOnKeyUpDelegate);
	window.RegisterButtonDownCallback(guiOnButtonDownDelegate);
	window.RegisterButtonUpCallback(guiOnButtonUpDelegate);
	window.RegisterMouseMoveCallback(guiOnMouseMovedDelegate);
	window.RegisterWindowResizeCallback(guiOnWindowResizeDelegate);

	/*
	* Loop
	*/
	float lastDelta = 0.0f;
	while (!window.HasCloseRequest())
	{
		/*
		* Get time start
		*/
		auto start = std::chrono::high_resolution_clock::now();

		/*
		* Collect buffered window messages
		*/
		window.PollWindowMessages();

		/*
		* Tick world
		*/
		world.TickWorld(&window,lastDelta);

		/*
		* Tick gui renderer
		*/
		renderer->NewFrame(lastDelta);
		renderer->RenderPainters();
		renderer->RenderFrame();

		/*
		* Swap window buffers
		*/
		window.Swapbuffers();

		/*
		* Get time end
		*/
		auto end = std::chrono::high_resolution_clock::now();

		/*
		* Calculate delta
		*/
		const unsigned long long delta = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
		lastDelta = delta / 100000.0f;
	}
}