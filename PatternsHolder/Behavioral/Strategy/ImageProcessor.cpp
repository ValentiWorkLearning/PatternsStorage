#include "ImageProcessor.hpp"
#include "ImageProcessor.hpp"
#include "ImageInterpolator.hpp"
#include "Image.hpp"

namespace Behavioral::Strategy
{
void ImageProcessor::setImageInterpolationMode(
    std::unique_ptr<IImageInterpolator>&& _imageProcessor )
{
    m_imageInterpolator = std::move( _imageProcessor );
}

std::unique_ptr<Image>
ImageProcessor::processImage( std::unique_ptr<Image>&& _image )
{
    std::unique_ptr<Image> toProcess{std::move( _image )};
    m_imageInterpolator->interpolate( *toProcess );

    return toProcess;
}
};  // namespace Strategy