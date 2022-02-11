#pragma once
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

/// <summary>
/// Represents a single vertex data for the entire mesh
/// </summary>
struct MeshVertex
{
	MeshVertex(float posX, float posY, float posZ, float uvS, float uvT) : Position(glm::vec3(posX, posY, posZ)), TextureCoordinate(glm::vec2(uvS, uvT)) {}
	MeshVertex() = default;

	/// <summary>
	/// The position component of the vertex
	/// </summary>
	glm::vec3 Position;

	/// <summary>
	/// The texture coordinate(uv) of the vertex
	/// </summary>
	glm::vec2 TextureCoordinate;
};