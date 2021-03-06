#pragma once

#include <filesystem>
#include <memory>

namespace Behavioral::Strategy
{
class Image;
class IImageInterpolator;

class ImageProcessor
{
   public:
    void setImageInterpolationMode(
        std::unique_ptr<IImageInterpolator>&& _imageProcessor );

    std::unique_ptr<Image> processImage( std::unique_ptr<Image>&& _image );

   private:
    std::unique_ptr<IImageInterpolator> m_imageInterpolator;
};

};  // namespace Behavioral::Strategy
