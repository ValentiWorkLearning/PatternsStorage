#include "ImageInterpolator.hpp"
#include "Image.hpp"

#include <iostream>

namespace Behavioral::Strategy
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

std::unique_ptr<IImageInterpolator>
getInterpolationAlgorithm( InterpolationMode _algorithm )
{
    switch ( _algorithm )
    {
        case Strategy::InterpolationMode::NearestNeighbour:
            return std::make_unique<NearestNeighbour>();
            break;
        case Strategy::InterpolationMode::Linear:
            return std::make_unique<LinearInterpolation>();
            break;
        case Strategy::InterpolationMode::Bicubic:
            return std::make_unique<BicubicInterpolation>();
            break;
        default:
            throw std::logic_error( ExceptionMessage );
		break;
    }
}
};  // namespace Strategy