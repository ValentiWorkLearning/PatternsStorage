#pragma once

#include <memory>

namespace Behavioral::State
{
class TeapotState
{
   public:
    using Ptr = std::shared_ptr<TeapotState>;
};

class Empty : public TeapotState
{
};

class Boiling : public TeapotState
{
};

class Boiled : public TeapotState
{
};

class Firing : public TeapotState
{
};

class Fired : public TeapotState
{
};

};  // namespace Behavioral::State
