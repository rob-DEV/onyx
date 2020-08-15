#ifndef _ONYX_GRAPHICS_MESH_H_
#define _ONYX_GRAPHICS_MESH_H_

#include <Onyx/Core/Core.h>
#include <glm/glm.hpp>

#include <string>
#include <vector>

namespace Onyx {

	enum class PrimitiveMeshType {
		Cube = 0,
		Sphere,
		Cone,
		Toroid
	};

	class ONYX_API Mesh {
	public:

		virtual ~Mesh();

		const std::vector<glm::vec3>& GetVertices() const { return *m_Vertices; };
		const std::vector<uint32_t>& GetIndices() const { return *m_Indices; };
		const std::vector<uint32_t>& GetNormals() const { return *m_Indices; };
		const glm::vec4& GetColor() const { return m_Color; };

		void SetColor(const glm::vec4& color) { m_Color = color; };

	public:
		Mesh(const std::vector<glm::vec3>* vertices, const std::vector<uint32_t>* indices);
		Mesh(const std::string& path);

	public:
		static Mesh* Create(const std::string& path);

		//primitive create, default - cube, sphere, cone
		static Mesh* Create(PrimitiveMeshType primitive);

	private:
		const std::vector<glm::vec3>* m_Vertices;
		const std::vector<uint32_t>* m_Indices;

		//color test
		glm::vec4 m_Color;


		//normals
	
		//material




	};


	class PrimitiveMesh : public Mesh {

		//CUBE
		const static std::vector<glm::vec3>* s_CubeVertices;
		const static std::vector<uint32_t>* s_CubeIndices;

		//SPHERE
		const static std::vector<glm::vec3>* s_SphereVertices;
		const static std::vector<uint32_t>* s_SphereIndices;

		//CONE
		const static std::vector<glm::vec3>* s_ConeVertices;
		const static std::vector<uint32_t>* s_ConeIndices;

		//TORIOD

		friend class Mesh;
	};


}


#endif //_ONYX_GRAPHICS_MESH_H_
