#include "onyxpch.h"
#include "Texture.h"

#include "RendererAPI.h"
#include <Platform/OpenGL/OpenGLTexture.h>

namespace Onyx {

	Texture2D* Texture2D::Create(std::string_view path) {

		if (RendererAPI::GetAPI() == RendererAPI::API::OpenGL) {
			return new OpenGLTexture2D(path);
		}

		return nullptr;
	}


	Texture2D* Texture2D::Create(uint32_t width, uint32_t height)
	{
		if (RendererAPI::GetAPI() == RendererAPI::API::OpenGL) {
			return new OpenGLTexture2D(width, height);
		}

		return nullptr;
	}

	Cubemap* Cubemap::Create(const std::vector<std::string_view>& paths)
	{
		if (RendererAPI::GetAPI() == RendererAPI::API::OpenGL) {
			return new OpenGLCubemap(paths);
		}

		return nullptr;
	}

}