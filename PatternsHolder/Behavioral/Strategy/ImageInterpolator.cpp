#include "ImageInterpolator.hpp"
#include "Image.hpp"

#include <iostream>

namespace Strategy
{
void NearestNeighbour::interpolate( Image& _toProcess)
{
    std::cout << "Image is interpolated via nearest neighbour algorithm " << std::endl;

    _toProcess.setDensity( _toProcess.getDensity() * 1.5 );
}
void LinearInterpolation::interpolate( Image& _toProcess )
{
    std::cout << "Image is interpolated via linerar interpolation algorithm "
              << std::endl;

    _toProcess.setDensity( _toProcess.getDensity() * 2.5 );
}
void BicubicInterpolation::interpolate( Image& _toProcess )
{
    std::cout << "Image is interpolated via bicubic interpolation algorithm "
              << std::endl;
    _toProcess.setDensity( _toProcess.getDensity() * 2 );
}
};  // namespace Strategy