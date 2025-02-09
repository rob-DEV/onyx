#ifndef _ONYX_PLATFORM_OPENGL_TEXTURE_H_
#define _ONYX_PLATFORM_OPENGL_TEXTURE_H_

#include <Onyx/Graphics/Texture.h>
#include <glad/glad.h>

namespace Onyx {

	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(uint32_t width, uint32_t height);
		OpenGLTexture2D(std::string_view path);
		virtual ~OpenGLTexture2D();

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; }

		virtual void SetData(void* data, uint32_t size) override;
		virtual void Bind(uint32_t slot = 0) const override;
		virtual bool operator==(const Texture& other) const override
		{
			return m_RendererID == ((OpenGLTexture2D&)other).m_RendererID;
		}

	private:
		std::string m_Path;
		uint32_t m_Width, m_Height;
		uint32_t m_RendererID;
		GLenum m_InternalFormat, m_DataFormat;
	};

	class OpenGLCubemap : public Cubemap
	{
	public:
		OpenGLCubemap(const std::vector<std::string_view>& paths);
		virtual ~OpenGLCubemap();

		virtual void Bind(uint32_t slot = 0) const override;
		virtual bool operator==(const Texture& other) const override
		{
			return m_RendererID == ((OpenGLCubemap&)other).m_RendererID;
		}

	private:
		std::string_view m_Paths[6];
		uint32_t m_RendererID;
		GLenum m_InternalFormat, m_DataFormat;
	};

}


#endif // !_ONYX_PLATFORM_OPENGL_TEXTURE_H_
