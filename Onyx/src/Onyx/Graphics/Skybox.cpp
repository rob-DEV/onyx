#include "onyxpch.h"
#include "Skybox.h"
#include "Texture.h"
#include "Shader.h"

#include <Onyx/Graphics/RenderCommand.h>

#include <glad/glad.h>

namespace Onyx {

	std::vector<glm::vec3> SkyboxVertices = {
		// positions          
		{-1.0f,  1.0f, -1.0f},
		{-1.0f, -1.0f, -1.0f},
		{ 1.0f, -1.0f, -1.0f},
		{ 1.0f, -1.0f, -1.0f},
		{ 1.0f,  1.0f, -1.0f},
		{-1.0f,  1.0f, -1.0f},

		{-1.0f, -1.0f,  1.0f},
		{-1.0f, -1.0f, -1.0f},
		{-1.0f,  1.0f, -1.0f},
		{-1.0f,  1.0f, -1.0f},
		{-1.0f,  1.0f,  1.0f},
		{-1.0f, -1.0f,  1.0f},

		{ 1.0f, -1.0f, -1.0f},
		{ 1.0f, -1.0f,  1.0f},
		{ 1.0f,  1.0f,  1.0f},
		{ 1.0f,  1.0f,  1.0f},
		{ 1.0f,  1.0f, -1.0f},
		{ 1.0f, -1.0f, -1.0f},

		{-1.0f, -1.0f,  1.0f},
		{-1.0f,  1.0f,  1.0f},
		{ 1.0f,  1.0f,  1.0f},
		{ 1.0f,  1.0f,  1.0f},
		{ 1.0f, -1.0f,  1.0f},
		{-1.0f, -1.0f,  1.0f},

		{-1.0f,  1.0f, -1.0f},
		{ 1.0f,  1.0f, -1.0f},
		{ 1.0f,  1.0f,  1.0f},
		{ 1.0f,  1.0f,  1.0f},
		{-1.0f,  1.0f,  1.0f},
		{-1.0f,  1.0f, -1.0f},

		{-1.0f, -1.0f, -1.0f},
		{-1.0f, -1.0f,  1.0f},
		{ 1.0f, -1.0f, -1.0f},
		{ 1.0f, -1.0f, -1.0f},
		{-1.0f, -1.0f,  1.0f},
		{ 1.0f, -1.0f,  1.0f}
	};

	Skybox::Skybox(std::vector<std::string_view> paths)
	{
		m_SkyboxTexture = Cubemap::Create(paths);

		m_SkyboxVAO = VertexArray::Create();

		m_SkyboxVBO = VertexBuffer::Create(reinterpret_cast<float*>(SkyboxVertices.data()), SkyboxVertices.size() * sizeof(glm::vec3));
		
		m_SkyboxVBO->SetLayout({
			{ ShaderDataType::Float3, "a_Position" }
		});

		m_SkyboxVAO->AddVertexBuffer(m_SkyboxVBO);

		m_SkyboxVBO->Bind();
		m_SkyboxVAO->Bind();

	}

	Skybox::Skybox() :
		m_SkyboxVAO(nullptr),
		m_SkyboxVBO(nullptr),
		m_SkyboxTexture(nullptr)
	{
	}

	void Skybox::Draw()
	{
		if (m_SkyboxTexture == nullptr)
			return;

		m_SkyboxVBO->Bind();
		m_SkyboxVAO->Bind();
		m_SkyboxTexture->Bind();

		RenderCommand::DrawArrays(36);
	}



}