#include "MenuItemVisitor.hpp"
#include "MenuItems.hpp"

#include <iostream>

namespace Visitor
{
void PaintVisitor::visit(
    const Filesystem::Nodes::DirectoryNode& _dirNode )
{
    std::cout << "Paint directory node" << std::endl;
}

void PaintVisitor::visit( const Filesystem::Nodes::CppFileNode& _fileNode )
{
    std::cout << " Paint cpp file node with size:" << _fileNode.getEntrySize()
              << std::endl;
}

void PaintVisitor::visit( const Filesystem::Nodes::PdfFileNode& _fileNode )
{
    std::cout << " Paint preview for pdf file node with size:" << _fileNode.getEntrySize()
              << std::endl;
}

void PaintVisitor::visit( const Filesystem::Nodes::BatFileNode& _fileNode )
{
    std::cout << " Paint bat file node with size:"
              << _fileNode.getEntrySize() << std::endl;
}

}  // namespace Visitor