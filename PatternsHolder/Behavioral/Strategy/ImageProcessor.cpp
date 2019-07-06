#include "ImageProcessor.hpp"
#include "ImageInterpolator.hpp"
#include "Image.hpp"

namespace Strategy
{
void ImageProcessor::setImageInterpolationMode(
    std::unique_ptr<IImageInterpolator>&& _imageProcessor )
{
    m_imageProcessor = std::move( _imageProcessor );
}
std::unique_ptr<Image> ImageProcessor::processImage()
{
    return std::unique_ptr<Image>();
}
};  // namespace Strategy