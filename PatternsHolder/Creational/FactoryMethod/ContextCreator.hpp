#pragma once

#include <memory>

namespace RenderTargets
{
class IRenderTarget;
class OpenGlRenderTarget;
class DirectXRenderTarget;
}  // namespace RenderTargets

namespace Creators
{
class IRenderContextCreator
{
   public:
    using Ptr = std::unique_ptr<IRenderContextCreator>;

    [[nodiscard]] virtual std::unique_ptr<RenderTargets::IRenderTarget>
    createRenderContext() = 0;

    virtual ~IRenderContextCreator() = default;
};

class OpenGlCreator : public IRenderContextCreator
{
   public:
    std::unique_ptr<RenderTargets::IRenderTarget>
    createRenderContext() override;

    ~OpenGlCreator() override = default;
};

class DirectXCreator : public IRenderContextCreator
{
   public:
    ~DirectXCreator() override = default;

    std::unique_ptr<RenderTargets::IRenderTarget>
    createRenderContext() override;
};

[[nodiscard]] IRenderContextCreator::Ptr createOpenGlCreator();

[[nodiscard]] IRenderContextCreator::Ptr createDirectXCreator();

};  // namespace Creators
