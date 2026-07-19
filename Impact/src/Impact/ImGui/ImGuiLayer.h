#pragma once

#include "Impact/Layer.h"

#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Impact {

	class IMPACT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnImGuiRender();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void End();
		void Begin();
	private:
		float m_Time = 0.0f;
	};

}