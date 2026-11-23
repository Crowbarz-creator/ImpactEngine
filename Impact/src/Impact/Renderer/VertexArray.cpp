#include "imppch.h"
#include "Impact/Renderer/VertexArray.h"

#include "Impact/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Impact {

    Ref<VertexArray> VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
        case RendererAPI::API::None:
            IMP_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
            return nullptr;

        case RendererAPI::API::OpenGL:
            return CreateRef<OpenGLVertexArray>();
        }

        IMP_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
