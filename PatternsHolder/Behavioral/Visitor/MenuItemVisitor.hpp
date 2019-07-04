#pragma once

#include <memory>

namespace Visitor::Filesystem::Nodes
{
class DirectoryNode;

class CppFileNode;

class PdfFileNode;

class BatFileNode;

}  // namespace Visitor::Filesystem::Nodes

namespace Visitor
{
class NodeVisitor
{
   public:
    virtual void visit( const Filesystem::Nodes::DirectoryNode& _dirNode ) = 0;

    virtual void visit( const Filesystem::Nodes::CppFileNode& _fileNode ) = 0;

    virtual void visit( const Filesystem::Nodes::PdfFileNode& _fileNode ) = 0;

    virtual void visit( const Filesystem::Nodes::BatFileNode& _fileNode ) = 0;

    virtual ~NodeVisitor() = default;
};

class PaintVisitor : public NodeVisitor
{
   public:
    void visit( const Filesystem::Nodes::DirectoryNode& _dirNode );

    void visit( const Filesystem::Nodes::CppFileNode& _fileNode );

    void visit( const Filesystem::Nodes::PdfFileNode& _fileNode );

    void visit( const Filesystem::Nodes::BatFileNode& _fileNode );

    ~PaintVisitor() override = default;
};

std::unique_ptr<NodeVisitor> createPaintNodeVisitor();

};  // namespace Visitor
