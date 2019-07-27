#pragma once

#include <memory>
#include <string>

namespace Behavioral::Strategy
{
enum class InterpolationMode
{
    NearestNeighbour,
    Linear,
    Bicubic
};

constexpr const char* ExceptionMessage =
    "Invalid interpolation mode passed to function";

class Image;

class IImageInterpolator
{
   public:
    virtual void interpolate( Image& _toProcess ) = 0;

    virtual ~IImageInterpolator() = default;
};

class NearestNeighbour : public IImageInterpolator
{
   public:
    void interpolate( Image& _toProcess ) override;

    ~NearestNeighbour() override = default;
};

class LinearInterpolation : public IImageInterpolator
{
   public:
    void interpolate( Image& _toProcess ) override;

    ~LinearInterpolation() override = default;
};

class BicubicInterpolation : public IImageInterpolator
{
   public:
    void interpolate( Image& _toProcess ) override;

    ~BicubicInterpolation() override = default;
};

std::unique_ptr<IImageInterpolator>
getInterpolationAlgorithm( InterpolationMode _algorithm );

}  // namespace Behavioral::Strategy
