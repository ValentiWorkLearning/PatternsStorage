#pragam once

namespace Strategy
{
class Image;

class IImageInterpolator
{
   public:
    virtual void interpolate() = 0;

    virtual ~IImageInterpolator() = default;
};

class NearestNeighbour : public IImageInterpolator
{
    void interpolate( Image& _toProcess ) override;
};

class LinearInterpolation : public IImageInterpolator
{
    void interpolate( Image& _toProcess ) override;
};

class BicubicInterpolation : public IImageInterpolator
{
    void interpolate( Image& _toProcess ) override;
};
}  // namespace Strategy