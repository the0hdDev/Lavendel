#pragma once
#include "Core.h"

namespace Lumen 
{

	class LUMEN_API Application
	{
		public:
			Application();
			virtual ~Application();
			void Run();
	};

	// MUST BE DEFINED IN CLIENT
	Application* CreateApplication();

}
