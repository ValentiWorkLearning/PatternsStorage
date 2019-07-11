#pragma once

#include <filesystem>
#include <memory>

namespace Strategy
{

class Image;
class IImageInterpolator;

class ImageProcessor
{

public:

	void setImageInterpolationMode(
        std::unique_ptr<IImageInterpolator>&& _imageProcessor );

    std::unique_ptr<Image> processImage();

private:
    std::unique_ptr<IImageInterpolator> m_imageProcessor;
}

};  // namespace Strategy