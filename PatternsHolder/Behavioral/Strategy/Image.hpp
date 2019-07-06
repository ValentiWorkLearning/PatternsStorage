#pragma once

#include <filesystem>

namespace Strategy
{
class Image
{
   public:
    Image( const std::filesystem::path& _imageSource )
        : m_imageSource{_imageSource}
    {
    }

    void setDensity( size_t _newDensity );

   private:
    size_t m_pixelDensity;

    std::filesystem::path m_imageSource;
};

void Image::Image::setDensity( size_t _newDensity )
{
    m_pixelDensity = _newDensity;
}

};  // namespace Strategy