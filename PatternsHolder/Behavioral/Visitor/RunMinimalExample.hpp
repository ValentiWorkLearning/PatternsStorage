#pragma once

#include "Literals.hpp"
#include "MenuItemVisitor.hpp"
#include "MenuItems.hpp"

#include <iostream>

namespace Behavioral::Visitor
{
static void runMinimalExample()
{
    std::cout << "Behavioral/Visitor" << std::endl;

    namespace FileNode = Behavioral::Visitor::Filesystem::Nodes;

    auto visitor = Visitor::createPaintNodeVisitor();

    auto rootDir = FileNode::createDirectory();

    auto workDir = FileNode::createDirectory();

    using namespace Visitor::Filesystem::Literals;

    auto pdfFile =
        FileNode::createFile( FileNode::FileExtension::Pdf, 1000_bytes );
    auto batFile = FileNode::createFile( FileNode::FileExtension::Bat, 10_kb );
    auto cppSource =
        FileNode::createFile( FileNode::FileExtension::Cpp, 100_mb );

    rootDir->addEntry( pdfFile );
    rootDir->addEntry( workDir );

    workDir->addEntry( batFile );
    workDir->addEntry( cppSource );

    rootDir->accept( *visitor );

    std::cout << "Behavioral/Visitor" << std::endl;
}
};  // namespace Visitor