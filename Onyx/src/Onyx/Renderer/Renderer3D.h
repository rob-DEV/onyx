#ifndef _ONYX_RENDERER3D_H_
#define _ONYX_RENDERER3D_H_

#include <Onyx/Camera/Camera.h>
#include <Onyx/Graphics/Shader.h>

#include <Onyx/Graphics/Material.h>
#include <Onyx/Graphics/VertexArray.h>
#include <Onyx/Graphics/Framebuffer.h>

namespace Onyx {

	class Scene;
	class Model;

	class Renderer3D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const Camera& camera);
		static void DrawScene(const Scene* scene);
		static void DrawModel(const Model* scene, const glm::mat4& transform);
		static void EndScene();

		static void Flush();

	private:

		static void ResetAndFlush();

		static const uint32_t MAX_TEXTURE_SLOTS = 32;
		static std::array<Texture2D*, MAX_TEXTURE_SLOTS> m_TextureSlots;

		static glm::mat4 m_View;
		static glm::mat4 m_WorldViewProjection;

		static Model* s_TestModel;
		static Material* s_TestMaterial;

		inline static VertexArray* m_MeshVertexArray = nullptr;
		inline static VertexBuffer* m_MeshVertexBuffer = nullptr;
		inline static IndexBuffer* m_MeshIndexBuffer = nullptr;

		inline static void* m_MeshVertexBufferBase = nullptr;
		inline static void* m_MeshVertexBufferWritePtr = nullptr;

		inline static uint32_t* m_MeshIndexBufferBase = nullptr;
		inline static uint32_t* m_MeshIndexBufferWritePtr = nullptr;


		inline static uint32_t m_IndexCount = 0;
		inline static uint32_t m_VertexCount = 0;

	};

}

#endif // !_ONYX_RENDERER3D_H_