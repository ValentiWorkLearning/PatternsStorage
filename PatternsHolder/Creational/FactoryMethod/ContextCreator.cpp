#include "ContextCreator.hpp"

#include "RenderContext.hpp"

namespace Creators
{
std::unique_ptr<RenderTargets::IRenderTarget>
OpenGlCreator::createRenderContext()
{
    return std::make_unique<RenderTargets::OpenGlRenderTarget>();
}

std::unique_ptr<RenderTargets::IRenderTarget>
DirectXCreator::createRenderContext()
{
    return std::make_unique<RenderTargets::DirectXRenderTarget>();
}

IRenderContextCreator::Ptr createOpenGlCreator()
{
    return std::make_unique<OpenGlCreator>();
}
IRenderContextCreator::Ptr createDirectXCreator()
{
    return std::make_unique<DirectXCreator>();
}

}  // namespace Creators
