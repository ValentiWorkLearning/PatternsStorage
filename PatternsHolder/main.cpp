#include <boost/range/adaptor/indexed.hpp>
#include <boost/assign.hpp>
#include <iterator>
#include <iostream>
#include <vector>

#include "Creational/FactoryMethod/RenderContext.hpp"
#include "Creational/FactoryMethod/ContextCreator.hpp"

int main()
{

    auto contextCreator = Creators::createOpenGlCreator();
    auto renderTarget = contextCreator->createRenderContext();
    renderTarget->forceRedraw();

    // stolen form https://www.boost.org/doc/libs/1_69_0/libs/range/doc/html/range/reference/adaptors/reference/indexed.html
    // just for boost-library test
    using namespace boost::assign;
    using namespace boost::adaptors;

    std::vector<int> input;
    input += 10,20,30,40,50,60,70,80,90;

    for (const auto& element : input | indexed(0))
    {
        std::cout << "Element = " << element.value()
                  << " Index = " << element.index()
                  << std::endl;
    }

    return 0;
}
