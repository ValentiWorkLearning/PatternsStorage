#include "MenuItems.hpp"
#include "MenuItems.hpp"
#include "MenuItems.hpp"
#include "Messages.hpp"
#include "MenuItemVisitor.hpp"

namespace Visitor::Filesystem::Nodes
{

size_t DirectoryNode::getEntrySize() const
{
    size_t directorySize{};

    for ( auto&& node: m_entries )
    {
        if ( auto pNode = node.lock() )
        {
            directorySize += pNode->getEntrySize();
        }
    }
}

std::string DirectoryNode::getFileExtension() const
{
    throw Filesystem::Messages::BadExtensionCall( Visitor::Messages::BadExtensionCall );

    return {};
}

void DirectoryNode::addEntry( const std::shared_ptr<IFilesystemNode>& _node )
{
    m_entries.push_back( _node );
}

void DirectoryNode::accept( Visitor::NodeVisitor& _visitor )
{
    _visitor.visit( *this );

    for ( std::weak_ptr<IFilesystemNode> node : m_entries )
    {
        if ( const auto& pNode = node.lock() )
        {
            _visitor.visit( *pNode );
        }
    }
}

size_t IFileNode::getEntrySize() const
{
    return m_fileSize;
}

std::string CppFileNode::getFileExtension() const
{
    return "cpp";
}

void CppFileNode::accept( Visitor::NodeVisitor& _visitor )
{
    _visitor.visit( *this );
}

std::string PdfFileNode::getFileExtension() const
{
    return "pdf";
}

void PdfFileNode::accept( Visitor::NodeVisitor& _visitor )
{
    _visitor.visit( *this );
}

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

IFilesystemNode::Ptr createFile( FileExtension _fileExtension )
{
    switch ( _fileExtension )
    {
        case FileExtension::Cpp:
            return std::make_shared<CppFileNode>();
        break;
        case FileExtension::Pdf:
            return std::make_shared<PdfFileNode>();
            break;
        case FileExtension::Bat:
            return std::make_shared<BatFileNode>();
            break;
        default:
            break;
    }
}

}  // namespace Visitor::Filesystem::Nodes