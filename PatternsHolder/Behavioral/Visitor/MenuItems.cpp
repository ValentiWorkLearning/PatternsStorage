#include "MenuItems.hpp"

#include "Exceptions.hpp"
#include "MenuItemVisitor.hpp"
#include "MenuItems.hpp"
#include "Messages.hpp"

namespace Behavioral::Visitor::Filesystem::Nodes
{
size_t DirectoryNode::getEntrySize() const
{
    size_t directorySize{};

    for ( auto&& pNode : m_entries )
    {
        directorySize += pNode->getEntrySize();
    }
    return directorySize;
}

std::string DirectoryNode::getFileExtension() const
{
    throw Exceptions::BadExtensionCall( Messages::BadExtensionCall );

    return {};
}

void DirectoryNode::addEntry( const std::shared_ptr<IFilesystemNode>& _node )
{
    m_entries.push_back( _node );
}

void DirectoryNode::accept( Visitor::NodeVisitor& _visitor )
{
    _visitor.visit( *this );

    for ( auto&& pNode : m_entries )
    {
        pNode->accept( _visitor );
    }
}

IFileNode::IFileNode( size_t _fileSize ) : m_fileSize{_fileSize} {}

size_t IFileNode::getEntrySize() const
{
    return m_fileSize;
}

CppFileNode::CppFileNode( size_t _fileSize ) : IFileNode{_fileSize} {}

std::string CppFileNode::getFileExtension() const
{
    return "cpp";
}

void CppFileNode::accept( Visitor::NodeVisitor& _visitor )
{
    _visitor.visit( *this );
}

PdfFileNode::PdfFileNode( size_t _fileSize ) : IFileNode{_fileSize} {}

std::string PdfFileNode::getFileExtension() const
{
    return "pdf";
}

void PdfFileNode::accept( Visitor::NodeVisitor& _visitor )
{
    _visitor.visit( *this );
}

BatFileNode::BatFileNode( size_t _fileSize ) : IFileNode{_fileSize} {}

std::string BatFileNode::getFileExtension() const
{
    return "bat";
}

void BatFileNode::accept( Visitor::NodeVisitor& _visitor )
{
    _visitor.visit( *this );
}

DirectoryNode::Ptr createDirectory()
{
    return std::make_shared<DirectoryNode>();
}

IFilesystemNode::Ptr
createFile( FileExtension _fileExtension, size_t _fileSize )
{
    switch ( _fileExtension )
    {
        case FileExtension::Cpp:
            return std::make_shared<CppFileNode>( _fileSize );
            break;
        case FileExtension::Pdf:
            return std::make_shared<PdfFileNode>( _fileSize );
            break;
        case FileExtension::Bat:
            return std::make_shared<BatFileNode>( _fileSize );
            break;
        default:
            throw Exceptions::InvalidFileExtension(
                Messages::InvalidFileExtension );
            return nullptr;
            break;
    }
}

}  // namespace Behavioral::Visitor::Filesystem::Nodes
