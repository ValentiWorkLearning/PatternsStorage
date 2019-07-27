#pragma once

#include <boost/signals2/signal.hpp>
#include <memory>

#include "TeapotState.hpp"

namespace Behavioral::State
{
class SmartTeapot : public std::enable_shared_from_this<SmartTeapot>
{
   public:
    void startBoilingWater();

    bool isReady() const;

    void addWater( size_t _volume );

    void pourWater( size_t _volume );

    size_t getTeapotVolume() const;

    size_t getCurrentWaterVolume() const;

    boost::signals2::signal<void( const std::shared_ptr<TeapotState>& _state )>
        onStateChanged;

    boost::signals2::signal<void()> onBoiled;

    boost::signals2::signal<void( size_t )> onWaterTempChanged;

   private:
    std::shared_ptr<TeapotState> m_teapotState = nullptr;
};

std::shared_ptr<SmartTeapot> createTeapot();

};  // namespace Behavioral::State
