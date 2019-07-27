#include <iostream>

#include "SmartTeapot.hpp"
#include "TeapotState.hpp"

namespace Behavioral::State
{
static void runMinimalExample()
{
    std::cout << "Behavioral/State" << std::endl;

    auto smartTeapot = createTeapot();

    std::cout << "Behavioral/State" << std::endl;
}
}  // namespace Behavioral::State
