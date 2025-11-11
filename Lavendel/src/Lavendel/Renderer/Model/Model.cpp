//
// Created by Theo Wimber on 11.11.25.
//

#include "Model.h"


namespace Lavendel
{
    namespace RenderAPI
    {
        Model::Model(GPUDevice &device, std::vector<Vertex> &verticies) : GPUDevice{device}
        {
            createVertexBuffers(verticies);
        }
    }
}