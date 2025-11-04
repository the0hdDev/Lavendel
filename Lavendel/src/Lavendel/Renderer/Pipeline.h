#pragma once 

#include <string>
#include <vector>
#include "../Core.h"
#include "../Log.h"

namespace Lavendel {
	namespace RendererAPI {
		class LAVENDEL_API Pipeline
		{
		public:
			Pipeline(const std::string& vertFilepath, const std::string& fragFilePath);
			~Pipeline();

		private:
			static std::vector<char> readFile(const std::string& filepath);
			void createGraphicsPipeline(const std::string& vertShaderPath, const std::string& fragShaderPath);
		};
	} 
} 