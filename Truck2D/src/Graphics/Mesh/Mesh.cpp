#include "Mesh.h"
#include <GLAD/glad.h>
Mesh::Mesh(const Array<MeshVertex>& vertexes, const Array<int>& indexes)
{
    /*
    * Generate handle
    */
    GPU_HANDLE vertexArrayHandle;
    GPU_HANDLE vertexBufferHandle;
    GPU_HANDLE indexBufferHandle;
    glGenVertexArrays(1, &vertexArrayHandle);
    glGenBuffers(1, &vertexBufferHandle);
    glGenBuffers(1, &indexBufferHandle);

    /*
    * Genereate vertex buffer and layout
    */
    glBindVertexArray(vertexArrayHandle);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MeshVertex), (const void*)(sizeof(float)*3));

    glBufferData(GL_ARRAY_BUFFER, sizeof(MeshVertex) * vertexes.GetCursor(), vertexes.GetData(), GL_STATIC_DRAW);
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    /*
    * Generate index buffer
    */
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indexes.GetCursor(), indexes.GetData(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    /*
    * Initialize mesh members
    */
    m_VertexArrayHandle = vertexArrayHandle;
    m_VertexBufferHandle = vertexBufferHandle;
    m_IndexBufferHandle = indexBufferHandle;
    m_IndexCount = indexes.GetCursor();
}

Mesh::~Mesh()
{
}

GPU_HANDLE Mesh::GetVertexArrayHandle() const
{
    return m_VertexArrayHandle;
}

GPU_HANDLE Mesh::GetVertexBufferHandle() const
{
    return m_VertexBufferHandle;
}

GPU_HANDLE Mesh::GetIndexBufferHandle() const
{
    return m_IndexBufferHandle;
}

unsigned int Mesh::GetIndexCount() const
{
    return 0;
}
