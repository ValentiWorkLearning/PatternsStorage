#pragma once

namespace Behavioral::Visitor::Filesystem::Messages
{
const char* const BadExtensionCall =
    ".getExtension can be called only on derived from IFileNode";

const char* const InvalidFileExtension =
    "Behavioral::Visitor::Filesystem::Nodes::createFile is called with "
    "incorrect file extension type";
}
