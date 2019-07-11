#pragma once

#include "Image.hpp"

#include <memory>

namespace Straregy
{
class IImageLoader
{
   public:

    virtual std::unique_ptr<Image>
    loadImageFromSource( const std::filesystem::path& ) = 0;
};



class FakeImageLoader
	:	public IImageLoader
{
   public:

	std::unique_ptr<Image>
    loadImageFromSource( const std::filesystem::path& ) override;
};

class FilesystemImageLoader
	:	public IImageLoader
{
   public:

    std::unique_ptr<Image>
    loadImageFromSource( const std::filesystem::path& ) override;

	std::unique_ptr<Image> load
};
}