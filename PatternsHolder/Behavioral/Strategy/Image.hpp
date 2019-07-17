#pragma once

#include <filesystem>
#include <random>

namespace Behavioral::Strategy
{
class Image
{
   public:
    Image( const std::filesystem::path& _imageSource );

    void setDensity( size_t _newDensity );

    size_t getDensity() const;

   private:

	size_t getPixelDensityFromSource();

    size_t m_pixelDensity;

    std::filesystem::path m_imageSource;
};

inline Image::Image( const std::filesystem::path& _imageSource )
	:	m_imageSource{ _imageSource }
{

	m_pixelDensity = getPixelDensityFromSource();
}

inline void Image::Image::setDensity( size_t _newDensity )
{
    m_pixelDensity = _newDensity;
}

inline size_t Image::getDensity() const
{
    return m_pixelDensity;
}

inline size_t Image::getPixelDensityFromSource()
{
    static std::random_device randomDevice;
    static std::mt19937_64 generator( randomDevice() );

    std::uniform_int_distribution<size_t> distribution( 0, 400 );

    return distribution( generator );
}

};  // namespace Strategy