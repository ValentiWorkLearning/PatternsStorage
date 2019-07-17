#include <boost/assign.hpp>
#include <boost/range/adaptor/indexed.hpp>

#include "Behavioral/SequenceOfResponsibility/RunMinimalExample.hpp"
#include "Behavioral/Strategy/RunMinimalExample.hpp"
#include "Behavioral/Visitor/RunMinimalExample.hpp"

#include "Creational/FactoryMethod/RunMinimalExample.hpp"

int main()
{

    Creational::Factory::runMinimalExample();

    Behavioral::SequenceOfResponsibility::runMinimalExample();
    Behavioral::Visitor::runMinimalExample();
    Behavioral::Strategy::runMinimalExample();

    return 0;
}
