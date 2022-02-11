#include "Game.h"
#include <World/Entity.h>
#include <World/World.h>
#include <World/Components/ObserverComponent.h>
#include <World/Components/RenderableComponent.h>
#include <Graphics/Mesh/Mesh.h>
#include <Graphics/Shader/ShaderProgram.h>
#include <Graphics/Texture/Texture2D.h>
#include <LogicSolver/Custom/IterativeLogicSolver.h>
#include <Renderer/Custom/ForwardRenderer.h>
#include <Resources/Resources.h>
void create_default_game_scene(World& world)
{
	/*
	* Load resources
	*/
	Mesh* spriteQuadMesh = new Mesh(get_quad_vertexes(),get_quad_indexes());
	ShaderProgram* spriteShaderProgram = new ShaderProgram(g_SpriteAlphaFragDiscardVertexShaderSource, g_SpriteAlphaFragDiscardFragmentShaderSource);
	Texture2D* truckTexture = new Texture2D("");

	/*
	* Create observer
	*/
	Entity* observerEntity = world.CreateEntity();
	observerEntity->SetName("Observer entity");
	observerEntity->AddComponent<ObserverComponent>(glm::vec4(0.1f,0.1f,0.1f,1.0f),5.0f);

	/*
	* Create truck entity
	*/
	Entity* truckEntity = world.CreateEntity();
	//truckEntity->AddComponent<RenderableComponent>(spriteQuadMesh,spriteShaderProgram, truckTexture);

	/*
	* Set logic solver
	*/
	world.RegisterLogicSolver<IterativeLogicSolver>();

	/*
	* Set renderer
	*/
	world.RegisterRenderer<ForwardRenderer>();

}
