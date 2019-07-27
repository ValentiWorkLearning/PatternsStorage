#include "SmartTeapot.hpp"

#include <numeric>

namespace Behavioral::State
{
void SmartTeapot::startBoilingWater() {}

bool SmartTeapot::isReady() const
{
    return false;
}

void SmartTeapot::addWater( size_t _volume ) {}

void SmartTeapot::pourWater( size_t _volume ) {}

size_t SmartTeapot::getTeapotVolume() const
{
    return std::numeric_limits<size_t>::max();
}

size_t SmartTeapot::getCurrentWaterVolume() const
{
    return std::numeric_limits<size_t>::max();
}

std::shared_ptr<SmartTeapot> createTeapot()
{
    return std::shared_ptr<SmartTeapot>();
}

};  // namespace Behavioral::State
