#pragma once

#include <iostream>
#include "CommandContextParser.hpp"

namespace Behavioral::SequenceOfResponsibility
{
static void runMinimalExample()
{
    std::cout << "Behavioral/SequenceOfResponsibility" << std::endl;

    auto colorParser =
        std::make_shared<SequenceOfResponsibility::ColorParser>();
    auto marginsParser =
        std::make_shared<SequenceOfResponsibility::MarginsParser>();
    auto rangeParser =
        std::make_shared<SequenceOfResponsibility::RangeParser>();

    colorParser->setNext( marginsParser );
    marginsParser->setNext( rangeParser );

    std::vector<SequenceOfResponsibility::ContextType> contexts{

        SequenceOfResponsibility::ContextType::JsonRange,
        SequenceOfResponsibility::ContextType::JsonMargins,
        SequenceOfResponsibility::ContextType::JsonColor};

    for ( auto&& context : contexts )
        colorParser->parseContext( context );

    std::cout << "Behavioral/SequenceOfResponsibility" << std::endl;
}

};  // namespace SequenceOfResponsibility