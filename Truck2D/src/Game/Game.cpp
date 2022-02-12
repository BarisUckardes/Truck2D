#include "Game.h"
#include <World/Entity.h>
#include <World/World.h>
#include <World/Components/ObserverComponent.h>
#include <World/Components/RenderableComponent.h>
#include <World/Components/GlueComponent.h>
#include <Graphics/Mesh/Mesh.h>
#include <Graphics/Shader/ShaderProgram.h>
#include <Graphics/Texture/Texture2D.h>
#include <LogicSolver/Custom/IterativeLogicSolver.h>
#include <Renderer/Custom/ForwardRenderer.h>
#include <Resources/Resources.h>
#include <World/Components/TruckController.h>
#include <GUI/Custom/WorldGUIPainter.h>
#include <GUI/ImGuiRenderer.h>
#include <Windows.h>
#include <shlwapi.h>
#include <Core/Log.h>
#define TRUCK_SPEED 0.5f


/// <summary>
/// Helper function which returns the target string size
/// </summary>
/// <param name="target"></param>
/// <returns></returns>
unsigned int get_char_ptr_length(const char* target)
{
	unsigned int size = 0;
	while (target[size] != '\0')
		size++;
	return size;
}

/// <summary>
/// Helper function which returns the relative path to executable folder
/// </summary>
/// <param name="hInstance"></param>
/// <param name="target"></param>
/// <returns></returns>
const char* get_relative_path(HINSTANCE hInstance, const char* target)
{
	char* Filename = new char[1000]; //this is a char buffer
	GetModuleFileNameA(hInstance, Filename, sizeof(char) * 1000);
	PathRemoveFileSpecA(Filename);

	const unsigned int targetLength = get_char_ptr_length(target);
	const unsigned int pathLength = get_char_ptr_length(Filename);

	for (unsigned int i = 0; i < targetLength; i++)
	{
		Filename[pathLength + i] = target[i];
	}
	Filename[pathLength + targetLength] = '\0';

	return Filename;
}

void create_default_game_scene(World& world,ImGuiRenderer* renderer)
{
	
	/*
	* Load resources
	*/
	Mesh* spriteQuadMesh = new Mesh(get_quad_vertexes(),get_quad_indexes());
	ShaderProgram* alphaSpriteShaderProgram = new ShaderProgram(g_UnlitAlphaSpriteVertexSource, g_UnlitAlphaSpriteFragmentSource);
	ShaderProgram* unlitSpriteShaderProgram = new ShaderProgram(g_UnlitSpriteVertexSource, g_UnlitSpriteFragmentSource);
	Texture2D* truckTexture = new Texture2D(get_relative_path(GetModuleHandle(NULL),"\\TruckTexture.png"));
	Texture2D* groundTexture = new Texture2D(get_relative_path(GetModuleHandle(NULL),"\\GroundTexture.jpg"));
	Texture2D* groundFrontTexture = new Texture2D(get_relative_path(GetModuleHandle(NULL),"\\GroundFrontTexture.jpg"));
	Texture2D* grassTexture = new Texture2D(get_relative_path(GetModuleHandle(NULL),"\\GrassTexture.png"));
	Texture2D* tireTexture = new Texture2D(get_relative_path(GetModuleHandle(NULL),"\\TireTexture.png"));
	Texture2D* cargoTexture = new Texture2D(get_relative_path(GetModuleHandle(NULL),"\\TruckCargo.png"));

	/*
	* Create observer entity
	*/
	Entity* observerEntity = world.CreateEntity();
	observerEntity->SetName("Observer entity");
	ObserverComponent* observerComponent = observerEntity->AddComponent<ObserverComponent>(glm::vec4(0.1f,0.1f,0.1f,1.0f),5.0f);
	observerEntity->GetSpatial()->SetPosition(glm::vec3(0, 0, -5.0f));

	/*
	* Create ground entity
	*/
	Entity* groundEntity = world.CreateEntity();
	groundEntity->AddComponent<RenderableComponent>(spriteQuadMesh, unlitSpriteShaderProgram, groundTexture,glm::vec2(15.0f,15.0f));
	groundEntity->GetSpatial()->SetPosition(glm::vec3(0, -15, 0.0f));
	groundEntity->GetSpatial()->SetScale(glm::vec3(25, 25, 25));

	/*
	* Create front ground entity
	*/
	Entity* groundFrontEntity = world.CreateEntity();
	groundFrontEntity->AddComponent<RenderableComponent>(spriteQuadMesh, unlitSpriteShaderProgram, groundFrontTexture, glm::vec2(40.0f, 1.0f));
	groundFrontEntity->GetSpatial()->SetPosition(glm::vec3(0, -2.5, 0.0f));
	groundFrontEntity->GetSpatial()->SetScale(glm::vec3(25, 0.35f, 1));

	/*
	* Create grass entity
	*/
	Entity* grassEntity = world.CreateEntity();
	grassEntity->AddComponent<RenderableComponent>(spriteQuadMesh, alphaSpriteShaderProgram, grassTexture, glm::vec2(40.0f, 1.0f));
	grassEntity->GetSpatial()->SetPosition(glm::vec3(0, -2.34, 0.0f));
	grassEntity->GetSpatial()->SetScale(glm::vec3(25, 0.22f, 1));

	/*
	* Create truck entity
	*/
	Entity* truckEntity = world.CreateEntity();
	truckEntity->AddComponent<RenderableComponent>(spriteQuadMesh, alphaSpriteShaderProgram, truckTexture);
	truckEntity->GetSpatial()->SetPosition(glm::vec3(-0.5f, 0, 0.0f));
	truckEntity->GetSpatial()->SetScale(glm::vec3(3.023f*1.5f, 1.5f, 1.5f));

	/*
	* Create truck tire0 entity
	*/
	Entity* tire0Entity = world.CreateEntity();
	tire0Entity->AddComponent<RenderableComponent>(spriteQuadMesh, alphaSpriteShaderProgram, tireTexture);
	tire0Entity->GetSpatial()->SetPosition(glm::vec3(-2.1f, -0.45f, 0.0f));
	tire0Entity->GetSpatial()->SetScale(glm::vec3(0.6f, 0.6f, 0.6f));

	/*
	* Create truck tire1 entity
	*/
	Entity* tire1Entity = world.CreateEntity();
	tire1Entity->AddComponent<RenderableComponent>(spriteQuadMesh, alphaSpriteShaderProgram, tireTexture);
	tire1Entity->GetSpatial()->SetPosition(glm::vec3(-1.1f, -0.45f, 0.0f));
	tire1Entity->GetSpatial()->SetScale(glm::vec3(0.6f, 0.6f, 0.6f));

	/*
	* Create truck tire2 entity
	*/
	Entity* tire2Entity = world.CreateEntity();
	tire2Entity->AddComponent<RenderableComponent>(spriteQuadMesh, alphaSpriteShaderProgram, tireTexture);
	tire2Entity->GetSpatial()->SetPosition(glm::vec3(-0.5f, -0.45f, 0.0f));
	tire2Entity->GetSpatial()->SetScale(glm::vec3(0.6f, 0.6f, 0.6f));

	/*
	* Create truck tire3 entity
	*/
	Entity* tire3Entity = world.CreateEntity();
	tire3Entity->AddComponent<RenderableComponent>(spriteQuadMesh, alphaSpriteShaderProgram, tireTexture);
	tire3Entity->GetSpatial()->SetPosition(glm::vec3(0.9f, -0.45f, 0.0f));
	tire3Entity->GetSpatial()->SetScale(glm::vec3(0.6f, 0.6f, 0.6f));
	

	/*
	* Create truck cargo entity
	*/
	Entity* cargoEntity = world.CreateEntity();
	cargoEntity->AddComponent<RenderableComponent>(spriteQuadMesh, alphaSpriteShaderProgram, cargoTexture);
	cargoEntity->GetSpatial()->SetPosition(glm::vec3(1.27f, 0.55f, 0.0f));
	cargoEntity->GetSpatial()->SetScale(glm::vec3(3.4f, 1, 1));
	cargoEntity->GetSpatial()->SetAnchor(glm::vec3(0.5f, -0.5f, 0));

	/*
	* Add Glue component
	*/
	Array<Spatial*> glueComponents = { tire0Entity->GetSpatial() ,tire1Entity->GetSpatial() ,tire2Entity->GetSpatial() ,tire3Entity->GetSpatial(),cargoEntity->GetSpatial()};
	Array<Spatial*> tireComponents = { tire0Entity->GetSpatial() ,tire1Entity->GetSpatial() ,tire2Entity->GetSpatial() ,tire3Entity->GetSpatial() };
	truckEntity->AddComponent<GlueComponent>(glueComponents);
	truckEntity->AddComponent<TruckController>(TRUCK_SPEED, 0, tireComponents);

	/*
	* Set logic solver
	*/
	world.RegisterLogicSolver<IterativeLogicSolver>();

	/*
	* Set renderer
	*/
	ForwardRenderer* forwardRenderer = world.RegisterRenderer<ForwardRenderer>();

	/*
	* Register gui painter
	*/
	renderer->RegisterGUIPainter<WorldGUIPainter>(forwardRenderer,observerComponent,cargoEntity->GetSpatial());


}
