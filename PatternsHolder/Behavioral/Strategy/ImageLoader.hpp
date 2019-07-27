#pragma once

#include <memory>

#include "Image.hpp"

namespace Behavioral::Strategy
{
class IImageLoader
{
   public:
    virtual std::unique_ptr<Image>
    loadImageFromSource( const std::filesystem::path& _path ) = 0;

    virtual ~IImageLoader() = default;
};

class FakeImageLoader : public IImageLoader
{
   public:
    std::unique_ptr<Image>
    loadImageFromSource( const std::filesystem::path& _path ) override;

    ~FakeImageLoader() = default;

   private:
    static inline std::filesystem::path FakePath =
        "FakeDrive/FakeFolder/FakeImage.png";
};

class FilesystemImageLoader : public IImageLoader
{
   public:
    std::unique_ptr<Image>
    loadImageFromSource( const std::filesystem::path& _path ) override;

    ~FilesystemImageLoader() = default;
};

std::unique_ptr<Image>
FakeImageLoader::loadImageFromSource( const std::filesystem::path& _path )
{
    return std::make_unique<Image>( FakePath );
}

std::unique_ptr<Image>
FilesystemImageLoader::loadImageFromSource( const std::filesystem::path& _path )
{
    return std::make_unique<Image>( _path );
}

}  // namespace Behavioral::Strategy
