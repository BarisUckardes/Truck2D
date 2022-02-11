#include "Texture2D.h"
#include <Core/Assert.h>
#include <STBI/stb_image.h>
#include <GLAD/glad.h>

Texture2D::Texture2D(const String& path)
{
    /*
    * Load stbi data
    */
    int width;
    int height;
    int channels;
    Byte* data = stbi_load(*path, &width, &height, &channels, 0);

    /*
    * Validate texture
    */
    ASSERT(width != 0, "STBI", "Loading texture from disk failed!");

    /*
    * Create texture handles
    */
    GPU_HANDLE textureHandle;
    glGenTextures(1, &textureHandle);

    /*
    * Set texture parameters
    */
    glBindTexture(GL_TEXTURE_2D, textureHandle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    /*
    * Upload texture data
    */
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

    /*
    * Initialize texture members
    */
    m_TextureHandle = textureHandle;

    /*
    * Delete intermediate texture buffer
    */
    delete data;
}

Texture2D::~Texture2D()
{
}

GPU_HANDLE Texture2D::GetTextureHandle() const
{
    return m_TextureHandle;
}
