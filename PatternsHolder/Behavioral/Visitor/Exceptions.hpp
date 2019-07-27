#pragma once

#include <exception>
#include <string>

namespace Behavioral::Visitor::Filesystem::Exceptions
{
class BadExtensionCall : public std::exception
{
   public:
    explicit BadExtensionCall( char const* _message ) : m_warnMessage{_message}
    {
    }

    explicit BadExtensionCall( const std::string& _message )
        : m_warnMessage{_message}
    {
    }

    ~BadExtensionCall() = default;

    char const* what() { return m_warnMessage.c_str(); }

   private:
    std::string m_warnMessage;
};

class InvalidFileExtension : public std::exception
{
   public:
    explicit InvalidFileExtension( char const* _message )
        : m_warnMessage{_message}
    {
    }

    explicit InvalidFileExtension( const std::string& _message )
        : m_warnMessage{_message}
    {
    }

    ~InvalidFileExtension() = default;

    char const* what() { return m_warnMessage.c_str(); }

   private:
    std::string m_warnMessage;
};

};  // namespace Behavioral::Visitor::Filesystem::Exceptions
