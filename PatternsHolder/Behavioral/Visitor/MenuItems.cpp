#include "MenuItems.hpp"
#include "Messages.hpp"

namespace Visitor::Filesystem::Nodes
{



size_t DirectoryNode::getEntrySize()
{
    throw Filesystem::Exceptions::BadExtensionCall(
        Messages::BadExtensionCall );
    return {};
}

}  // namespace Visitor::Filesystem::Nodes

char const* Visitor::Filesystem::Exceptions::BadExtensionCall::what()
{
    return nullptr;
}
