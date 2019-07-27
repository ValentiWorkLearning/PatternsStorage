#pragma once

#include <iostream>

#include "Creational/FactoryMethod/ContextCreator.hpp"
#include "Creational/FactoryMethod/RenderContext.hpp"

namespace Creational::Factory
{
static void runMinimalExample()
{
    std::cout << "Creatioal/FactoryMethod" << std::endl;

    {
        auto openGlcontextCreator = Creators::createOpenGlCreator();
        auto renderTarget = openGlcontextCreator->createRenderContext();

        renderTarget->forceRedraw();
    }
    {
        auto directXContextCreator = Creators::createDirectXCreator();
        auto renderTarget = directXContextCreator->createRenderContext();

        renderTarget->forceRedraw();
    }
    std::cout << "Creatioal/FactoryMethod" << std::endl;
}

};  // namespace Creational::Factory
