#include "ForwardRenderer.h"
#include <World/Components/RenderableComponent.h>
#include <World/Components/ObserverComponent.h>
#include <World/Components/Spatial.h>
#include <Graphics/Mesh/Mesh.h>
#include <Graphics/Shader/ShaderProgram.h>
#include <Graphics/Texture/Texture2D.h>
#include <Window/Window.h>
#include <GLAD/glad.h>

GPU_HANDLE _get_uniform_location(const GPU_HANDLE& programHandle,const String& name)
{
	return glGetUniformLocation(programHandle, *name);
}
void ForwardRenderer::Render(Array<RenderableComponent*>& renderables, Array<ObserverComponent*>& observers, const Window* window)
{
	/*
	* Get window properties
	*/
	const unsigned int width = window->GetWidth();
	const unsigned int height = window->GetHeight();

	/*
	* Iterate observers
	*/
	for (unsigned int observerIndex = 0; observerIndex < observers.GetCursor(); observerIndex++)
	{
		/*
		* Get observer
		*/
		const ObserverComponent* observer = observers[observerIndex];

		/*
		* Get observer properties
		*/
		const glm::mat4 viewMatrix = observer->GetViewMatrix();
		const glm::mat4 projectionMatrix = observer->GetProjectionMatrix();
		const glm::vec4 clearColor = observer->GetClearColor();

		/*
		* Get observer handles
		*/
		const GPU_HANDLE observerFramebufferHandle = 0; /// always writing to swapchain framebuffer

		/*
		* Set framebuffer
		*/
		glBindFramebuffer(GL_FRAMEBUFFER, observerFramebufferHandle);

		/*
		* Clear framebuffer
		*/
		glClearColor(clearColor.x, clearColor.y, clearColor.z, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*
		* Set render viewport
		*/
		glViewport(0, 0, width, height);

		/*
		* Iterate renderables
		*/
		for (unsigned int renderableIndex = 0; renderableIndex < renderables.GetCursor(); renderableIndex++)
		{
			/*
			* Get renderable
			*/
			const RenderableComponent* renderable = renderables[renderableIndex];

			/*
			* Get renderable properties
			*/
			const glm::mat4 modelMatrix = renderable->GetSpatial()->GetModelMatrix();
			const glm::mat4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;
			const Mesh* mesh = renderable->GetMesh();
			const ShaderProgram* program = renderable->GetProgram();
			const Texture2D* spriteTexture = renderable->GetTexture();

			/*
			* Get renderable handles
			*/
			const GPU_HANDLE vertexArrayHandle = mesh->GetVertexArrayHandle();
			const GPU_HANDLE vertexBufferHandle = mesh->GetVertexBufferHandle();
			const GPU_HANDLE indexBufferHandle = mesh->GetIndexBufferHandle();
			const unsigned int indexCount = mesh->GetIndexCount();
			const GPU_HANDLE programHandle = program->GetProgramHandle();
			const GPU_HANDLE spriteTextureHandle = spriteTexture->GetTextureHandle();

			/*
			* Set vertex and index buffer handles
			*/
			glBindVertexArray(vertexArrayHandle);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBufferHandle);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferHandle);

			/*
			* Set program handles
			*/
			glUseProgram(programHandle);

			/*
			* Set uniform parameters
			*/
			glUniformMatrix4fv(_get_uniform_location(programHandle, "v_Mvp"), 1, GL_FALSE, &mvpMatrix[0][0]);
			glActiveTexture(GL_TEXTURE0 + 0);
			glBindTexture(GL_TEXTURE_2D, spriteTextureHandle);
			glUniform1i(_get_uniform_location(programHandle, "f_SpriteTexture"), 0);

			/*
			* Issue draw call
			*/
			glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
		}
	}
}
