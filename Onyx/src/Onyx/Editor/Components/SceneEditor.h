#ifndef _ONYX_EDITOR_SCENE_H_
#define _ONYX_EDITOR_SCENE_H_

#include <Onyx/Core/Core.h>

#include <Onyx/Scene/Scene.h>
#include <Onyx/Core/TimeStep.h>

#include <vector>

namespace Onyx {

	class EditorCameraController;
	class Gizmo;
	class Scene;
	class Entity;

	class ONYX_API SceneEditor {
	public:
		SceneEditor();
		~SceneEditor();

		void OnUpdate(Timestep ts);

		SceneData NewScene();
		SceneData OpenScene(const char* filePath);
		bool SaveScene(const char* filePath);

		Scene* GetScene() const { return m_Scene; };
		std::vector<Entity*> GetAllEntitiesTest();

		Entity* GetSelectedEntity();

	private:
		void InvalidateScene();

		//Initialize First
		EditorCameraController* m_EditorCameraController;
		
		Scene* m_Scene;
		Entity* m_SelectedEntity;

		friend class EditorCore;

	};

}


#endif // !_ONYX_EDITOR_SCENE_H_