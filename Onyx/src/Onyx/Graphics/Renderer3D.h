#ifndef _ONYX_GRAPHICS_RENDERER3D_H_
#define _ONYX_GRAPHICS_RENDERER3D_H_

#include <Onyx/core/Core.h>
#include <Onyx/Graphics/PerspectiveCamera.h>
#include <Onyx/Graphics/Texture.h>
#include <Onyx/Graphics/Mesh.h>
#include <Onyx/Scene/Scene.h>

namespace Onyx {

	class ONYX_API Renderer3D {
	public:	

		//GLOBAL INITIALIZATION OF RENDERER 2D depending on which RendererAPI is in use
		static void Init();
		inline static void Destroy() { s_Instance->DestroyImplementation(); delete s_Instance; };

		inline static void BeginScene(const PerspectiveCamera& camera) { s_Instance->BeginSceneImplementation(camera); };
		inline static void EndScene() { s_Instance->EndSceneImplementation(); };
		inline static void Flush() { s_Instance->FlushImplementation(); };


		inline static void DrawScene(const Scene* scene);
		inline static void DrawMesh(const Mesh* mesh, const glm::vec3& position, const glm::vec3& size) { s_Instance->DrawMeshImplementation(mesh, position, size); };
		inline static void DrawRotatedMesh(const Mesh* mesh, float angle, const glm::vec3& ax, const glm::vec3& position, const glm::vec3& size) { s_Instance->DrawRotatedMeshImplementation(mesh, angle, ax, position, size); };


	protected:

		virtual void InitImplementation() = 0;
		virtual void DestroyImplementation() = 0;

		virtual void BeginSceneImplementation(const PerspectiveCamera& camera) = 0;
		virtual void EndSceneImplementation() = 0;
		virtual void FlushImplementation() = 0;

		virtual void DrawSceneImplementation(const Scene* scene) = 0;
		virtual void DrawMeshImplementation(const Mesh* mesh, const glm::vec3& position, const glm::vec3& size) = 0;
		virtual void DrawRotatedMeshImplementation(const Mesh* mesh, float angle, const glm::vec3& ax, const glm::vec3& position, const glm::vec3& size) = 0;

	private:
		static Renderer3D* s_Instance;

	};

}

#endif // !_ONYX_GRAPHICS_RENDERER2D_H_