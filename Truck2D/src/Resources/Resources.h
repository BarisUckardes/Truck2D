#pragma once
#include <Memory/Array.h>
#include <Graphics/Mesh/MeshVertex.h>

/*
* Empty header for resource globals
*/

const char* g_UnlitAlphaSpriteVertexSource = R"glsl(
#version 450 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTextureCoordinate;

out vec2 f_TextureCoordinate;

uniform mat4 v_Mvp;
void main()
{
	gl_Position = v_Mvp*vec4(aPosition,1.0f);
	f_TextureCoordinate = aTextureCoordinate;
}
)glsl";

const char* g_UnlitAlphaSpriteFragmentSource = R"glsl(
#version 450 core

out vec4 f_ColorOut;
in vec2 f_TextureCoordinate;

uniform sampler2D f_SpriteTexture;
uniform vec2 f_Tiling;
void main()
{
	vec4 texColor = texture(f_SpriteTexture,f_TextureCoordinate*f_Tiling);
	if(texColor.a < 0.95f)
		discard;
	f_ColorOut = texColor;
}
)glsl";

const char* g_UnlitSpriteVertexSource = R"glsl(
#version 450 core
layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec2 aTextureCoordinate;

out vec2 f_TextureCoordinate;

uniform mat4 v_Mvp;
void main()
{
	gl_Position = v_Mvp*vec4(aPosition,1.0f);
	f_TextureCoordinate = aTextureCoordinate;
}
)glsl";

const char* g_UnlitSpriteFragmentSource = R"glsl(
#version 450 core

out vec4 f_ColorOut;
in vec2 f_TextureCoordinate;


uniform sampler2D f_SpriteTexture;
uniform vec2 f_Tiling;
void main()
{
	f_ColorOut =  texture(f_SpriteTexture,f_TextureCoordinate*f_Tiling);
}
)glsl";

Array<MeshVertex> get_quad_vertexes()
{
	Array<MeshVertex> vertexes;
	vertexes.Add(MeshVertex(0.5f, -0.5f, 0, 0, 0));
	vertexes.Add(MeshVertex(-0.5f, -0.5f, 0, 1, 0));
	vertexes.Add(MeshVertex(-0.5f, 0.5f, 0, 1, 1));
	vertexes.Add(MeshVertex(0.5f, 0.5f, 0, 0, 1));

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