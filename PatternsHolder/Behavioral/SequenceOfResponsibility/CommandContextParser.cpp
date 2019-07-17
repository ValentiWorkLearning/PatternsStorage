#include "CommandContextParser.hpp"

#include <iostream>

namespace Behavioral::SequenceOfResponsibility
{
void RangeParser::parseContext( ContextType _jsonValueType )
{
    if ( _jsonValueType == ContextType::JsonRange )
        std::cout << "Parsed values range 1-12" << std::endl;
    else
        CompositeContentParser::parseContext( _jsonValueType );
}

void CompositeContentParser::setNext(
    const std::shared_ptr<CompositeContentParser>& _nextHandler )
{
    m_nextParser = _nextHandler;
}

void CompositeContentParser::parseContext( ContextType _jsonValueType )
{
    if ( auto nextParser = m_nextParser.lock() )
        nextParser->parseContext( _jsonValueType );
    else
        std::cout << "NoneValue parser executed!" << std::endl;
}

void ColorParser::parseContext( ContextType _jsonValueType )
{
    if ( _jsonValueType == ContextType::JsonColor )
        std::cout << "Color parser executed" << std::endl;
    else
        CompositeContentParser::parseContext( _jsonValueType );
}
void MarginsParser::parseContext( ContextType _jsonValueType )
{
    if ( _jsonValueType == ContextType::JsonMargins )
        std::cout << "Margins parser executed" << std::endl;
    else
        CompositeContentParser::parseContext( _jsonValueType );
}
}  // namespace SequenceOfResponsibility
