#include "MenuItemVisitor.hpp"

#include <iostream>

#include "MenuItems.hpp"

namespace Behavioral::Visitor
{
void PaintVisitor::visit( const Filesystem::Nodes::DirectoryNode& _dirNode )
{
    std::cout << "Paint directory node with size:" << _dirNode.getEntrySize()
              << " bytes" << std::endl;
}

void PaintVisitor::visit( const Filesystem::Nodes::CppFileNode& _fileNode )
{
    std::cout << " Paint cpp file node with size:" << _fileNode.getEntrySize()
              << " bytes" << std::endl;
}

void PaintVisitor::visit( const Filesystem::Nodes::PdfFileNode& _fileNode )
{
    std::cout << " Paint preview for pdf file node with size:"
              << _fileNode.getEntrySize() << " bytes" << std::endl;
}

void PaintVisitor::visit( const Filesystem::Nodes::BatFileNode& _fileNode )
{
    std::cout << " Paint bat file node with size:" << _fileNode.getEntrySize()
              << " bytes" << std::endl;
}

std::unique_ptr<NodeVisitor> createPaintNodeVisitor()
{
    return std::make_unique<PaintVisitor>();
}

}  // namespace Behavioral::Visitor
