#include "onyxpch.h"
#include "SceneSerializer.h"

#include <tinyxml2.h>

#include <sstream>
#include <string>

#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

namespace Onyx {

	using namespace tinyxml2;

	bool SceneSerializer::Serialize(Scene* scene, const std::string& filePath) {

		tinyxml2::XMLDocument xmlDoc;
		
		XMLNode* pRoot = xmlDoc.NewElement("ONYX-SCENE");
		((XMLElement*)pRoot)->SetAttribute("UniqueIdentifier", scene->m_SceneData.Identifier.c_str());
		((XMLElement*)pRoot)->SetAttribute("Name", scene->m_SceneData.Name.c_str());
		xmlDoc.InsertFirstChild(pRoot);

		//Process each entity in the scene along with it's components
		for (auto e : scene->m_Entities) {

			XMLElement* pEntityElement = xmlDoc.NewElement("ONYX-ENTITY");

			if (e->HasComponent<TagComponent>()) {
				
				TagComponent& t = e->GetComponent<TagComponent>();
				XMLElement* pTagElement = xmlDoc.NewElement("TagComponent");
				pTagElement->SetText(t.Tag.c_str());

				pEntityElement->InsertEndChild(pTagElement);

			}

			if (e->HasComponent<TransformComponent>()) {
				
				TransformComponent& t = e->GetComponent<TransformComponent>();
				XMLElement* pTransformElement = xmlDoc.NewElement("TransformComponent");
				XMLElement* pTransformPositionElement = xmlDoc.NewElement("Position");

				for (uint8_t i = 0; i < 3; ++i)
				{
					char x[2] = { 'X', 0 };
					x[0] = 'X' + i;

					XMLElement* pVec3Element = xmlDoc.NewElement(x);
					pVec3Element->SetText(t.Position[i]);

					pTransformPositionElement->InsertEndChild(pVec3Element);
				}

				pTransformElement->InsertEndChild(pTransformPositionElement);

				pEntityElement->InsertEndChild(pTransformElement);

			}

			if (e->HasComponent<MeshRendererComponent>()) {
				
			}

			pRoot->InsertEndChild(pEntityElement);
		}

		if (xmlDoc.SaveFile(filePath.c_str()) == 0)
			return true;
		
		return false;
	}

	Scene* SceneSerializer::DeSerialize(const std::string& filePath) {
		
		tinyxml2::XMLDocument xmlDoc;

		xmlDoc.LoadFile(filePath.c_str());

		XMLNode* pRoot = xmlDoc.FirstChild();

		if (pRoot == nullptr) {
			ONYX_ERROR("Scene Serializer ERROR: XML is Invalid!");
			return nullptr;
		}

		const char* sceneIdentifer = ((XMLElement*)pRoot)->Attribute("UniqueIdentifier");
		const char* sceneName = ((XMLElement*)pRoot)->Attribute("Name");

		
		if (sceneIdentifer == nullptr || strlen(sceneIdentifer) < 10) {
			ONYX_ERROR("Scene Serializer ERROR: Failed to find a valid Scene!");
			return nullptr;
		}

		//Iterate through serialized entities
		XMLElement* pEntityElement = pRoot->FirstChildElement("ONYX-ENTITY");
		
		Scene* scene = new Scene(SceneData(sceneName, filePath.c_str(), sceneIdentifer));
		
		while (pEntityElement != nullptr) {

			Entity* entity = scene->CreateEntity();

			XMLElement* pEntityComponentElement = pEntityElement->FirstChildElement();

			while (pEntityComponentElement != nullptr) {

				//Determine component type and De-Serialize
				if (_stricmp(pEntityComponentElement->Value(), "TagComponent") == 0) {
					
					TagComponent t = TagComponent(pEntityComponentElement->GetText());
					entity->AddComponent<TagComponent>(t);
					
				}
				else if (_stricmp(pEntityComponentElement->Value(), "TransformComponent") == 0) {

					TransformComponent t = TransformComponent();
					
					//Position
					XMLElement* pTransformPositionElement = pEntityComponentElement->FirstChildElement("Position");
					pTransformPositionElement->FirstChildElement("X")->QueryFloatText(&t.Position.x);
					pTransformPositionElement->FirstChildElement("Y")->QueryFloatText(&t.Position.y);
					pTransformPositionElement->FirstChildElement("Z")->QueryFloatText(&t.Position.z);

					entity->AddComponent<TransformComponent>(t);

				}
				pEntityComponentElement = pEntityComponentElement->NextSiblingElement();
			}

			pEntityElement = pEntityElement->NextSiblingElement("ONYX-ENTITY");
		}

		return scene;
	}

}