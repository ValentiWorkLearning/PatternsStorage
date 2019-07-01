#include "RenderContext.hpp"

#include<iostream>

namespace RenderTargets
{

void OpenGlRenderTarget::renderContext()
{
	std::cout << "OpenGL render device" << std::endl;
}

void OpenGlRenderTarget::forceRedraw()
{
	std::cout << "OpenGL force redraw" << std::endl;
}


void DirectXRenderTarget::forceRedraw()
{
	std::cout << "DirectX forceredraw" << std::endl;
}

void DirectXRenderTarget::renderContext()
{
	std::cout << "DirectX render context" << std::endl;
}

}
