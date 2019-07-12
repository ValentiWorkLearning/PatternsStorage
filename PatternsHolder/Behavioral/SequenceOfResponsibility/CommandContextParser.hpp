#pragma once

#include <memory>
#include <vector>

namespace SequenceOfResponsibility
{
enum class ContextType
{
    JsonColor,
    JsonRange,
    JsonMargins,
    JsonNone
};

class IBaseContextParser
{
   public:
    using Ptr = std::shared_ptr<IBaseContextParser>;

    virtual void parseContext( ContextType ) = 0;

    virtual ~IBaseContextParser() = default;
};

class CompositeContentParser : public IBaseContextParser
{
   public:
    ~CompositeContentParser() override = default;

    void setNext( const std::shared_ptr<CompositeContentParser>& _nextHandler );

    void parseContext( ContextType _jsonValueType ) override;

    std::weak_ptr<CompositeContentParser> m_nextParser;
};

class RangeParser : public CompositeContentParser
{
   public:
    void parseContext( ContextType _jsonValueType ) override;

	~RangeParser() override = default;
};

class ColorParser : public CompositeContentParser
{
   public:
    void parseContext( ContextType _jsonValueType ) override;

	~ColorParser() override = default;
};

class MarginsParser : public CompositeContentParser
{
   public:
    void parseContext( ContextType _jsonValueType ) override;

	~MarginsParser() override = default;
};
};  // namespace SequenceOfResponsibility
