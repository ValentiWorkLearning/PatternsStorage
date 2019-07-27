#pragma once
#include <memory>

namespace Creational::Factory::RenderTargets
{
class IRenderTarget
{
   public:
    using Ptr = std::unique_ptr<IRenderTarget>;

    virtual void renderContext() = 0;

    virtual void forceRedraw() = 0;

    virtual ~IRenderTarget() = default;
};

class OpenGlRenderTarget : public IRenderTarget
{
   public:
    void renderContext() override;

    void forceRedraw() override;

    ~OpenGlRenderTarget() override = default;
};

class DirectXRenderTarget : public IRenderTarget
{
   public:
    void renderContext() override;

    void forceRedraw() override;

    ~DirectXRenderTarget() override = default;
};
};  // namespace Creational::Factory::RenderTargets
