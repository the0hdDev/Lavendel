#include "Pipeline.h"
#include <fstream>
#include <vector>
#include <string>

namespace Lavendel {
	namespace RendererAPI {

		Pipeline::Pipeline(const std::string& vertFilepath, const std::string& fragFilePath)
		{
			createGraphicsPipeline(vertFilepath, fragFilePath);
		}

		Pipeline::~Pipeline() = default;

		std::vector<char> Pipeline::readFile(const std::string& filepath)
		{
			std::ifstream file(filepath, std::ios::ate | std::ios::binary);

			if (!file)
			{
				LV_CORE_ERROR("Failed to open file: {}", filepath);
				throw std::runtime_error("Failed to open file: " + filepath);  
			}

			size_t fileSize = (size_t)file.tellg();
			std::vector<char> buffer(fileSize);

			file.seekg(0);
			file.read(buffer.data(), fileSize);
			file.close();

			return buffer;
		}

		void Pipeline::createGraphicsPipeline(const std::string& vertShaderPath, const std::string& fragShaderPath)
		{
			auto vertCode = readFile(vertShaderPath);
			auto fragCode = readFile(fragShaderPath);

			LV_CORE_INFO("Vertex Shader Code Size: {}", vertCode.size());
			LV_CORE_INFO("Fragment Shader Code Size: {}", fragCode.size());
		}
	}
}