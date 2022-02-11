#pragma once
#include <Memory/Array.h>
#include <Graphics/Mesh/MeshVertex.h>

const char* g_SpriteAlphaFragDiscardVertexShaderSource = "";
const char* g_SpriteAlphaFragDiscardFragmentShaderSource = "";
Array<MeshVertex> get_quad_vertexes()
{
	Array<MeshVertex> vertexes;
	vertexes.Add(MeshVertex( 1, 0, 0, 0, 0));
	vertexes.Add(MeshVertex(-1, 0, 0, 1, 0));
	vertexes.Add(MeshVertex(-1, 1, 0, 1, 1));
	vertexes.Add(MeshVertex( 0, 1, 0, 0, 1));

	return vertexes;
}
Array<int> get_quad_indexes()
{
	Array<int> indexes;
	indexes.Add(0);
	indexes.Add(1);
	indexes.Add(2);
	indexes.Add(0);
	indexes.Add(2);
	indexes.Add(3);
	return indexes;
}