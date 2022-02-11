#include <Window/Window.h>
#include <World/World.h>
#include <Game/Game.h>
int main(int argumentCount, char** arguments)
{
	/*
	* Create window
	*/
	Window window("Truck2D", 512, 512);

	/*
	* Create world
	*/
	World world;
	create_default_game_scene(world);

	/*
	* Loop
	*/
	while (true)
	{
		window.PollWindowMessages();
		world.TickWorld(&window,0.01f);
		window.Swapbuffers();
	}
}