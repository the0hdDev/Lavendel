#include <Lavendel/Lavendel.h>
#include <ImGui/ImGuiLayer.h>
#include "EditorLayer.h"


class Editor : public  Lavendel::Application
{
public: 
		Editor()
		{
			LV_PROFILE_FUNCTION();
			PushLayer(new EditorLayer());
		}


		~Editor() { LV_PROFILE_FUNCTION(); }
};


Lavendel::Application* Lavendel::CreateApplication()
{
	LV_PROFILE_FUNCTION();
	return new Editor();
}