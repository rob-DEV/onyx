#ifndef _ONYX_GRAPHICS_RENDERER_API_H_
#define _ONYX_GRAPHICS_RENDERER_API_H_

#include <Onyx/core/Core.h>
#include <Onyx/Graphics/VertexArray.h>

#include <glm/vec4.hpp>

namespace Onyx {

	class ONYX_API RendererAPI
	{
	public:
		enum class API	{ None = 0, OpenGL, Vulkan };

		virtual ~RendererAPI() = default;
		virtual void Init() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;
		virtual void DrawArrays(uint32_t count) = 0;
		virtual void DrawIndexed(VertexArray* vertexArray) = 0;
		virtual void DrawIndexed(VertexArray* vertexArray, uint32_t indexCount) = 0;

		inline static API GetAPI() { return s_API; }
		inline static bool VsyncEnabled() { return s_Vsync; };
		static RendererAPI* Create();

	private:
		static API s_API;
		static bool s_Vsync;
	};


}

#endif // !_ONYX_GRAPHICS_RENDERER_API_H_
