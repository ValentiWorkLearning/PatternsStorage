#pragma once

#include <memory>

#include "ImageLoader.hpp"

namespace Behavioral::Strategy
{
class IImageLoaderCreator
{
   public:
    virtual std::unique_ptr<IImageLoader> createLoader() = 0;
};

class FakeImageLoaderCreator : public IImageLoaderCreator
{
   public:
    std::unique_ptr<IImageLoader> createLoader() override
    {
        return std::make_unique<FakeImageLoader>();
    }
};

class FilesystemImageLoaderCreator : public IImageLoaderCreator
{
   public:
    std::unique_ptr<IImageLoader> createLoader() override
    {
        return std::make_unique<FilesystemImageLoader>();
    }
};

std::unique_ptr<IImageLoader>
createImageLoader( std::shared_ptr<IImageLoaderCreator> _loaderCreator )
{
    return _loaderCreator->createLoader();
}

};  // namespace Behavioral::Strategy
