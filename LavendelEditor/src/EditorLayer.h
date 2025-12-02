#include <Lavendel.h>



class EditorLayer : public Lavendel::Layer
{
public:
	EditorLayer() : Layer("Editor") { LV_PROFILE_FUNCTION(); }


	void OnUpdate() override
	{
		LV_PROFILE_FUNCTION();
		//LV_CORE_INFO("ExampleLayer::Update");
	}
	void OnEvent(Lavendel::Event& event) override
	{
		LV_PROFILE_FUNCTION();
		LV_CORE_INFO("{0}", event.ToString());
	}

	void OnImGuiRender()
	{
		LV_PROFILE_FUNCTION();
		//LV_CORE_INFO("ExampleLayer::OnRender");

		ImGui::Begin("Hello from ExampleLayer");

	}
};