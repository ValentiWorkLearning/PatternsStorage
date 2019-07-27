#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Behavioral::Visitor
{
class NodeVisitor;
}

namespace Behavioral::Visitor::Filesystem::Nodes
{
class NodesVisitor;

class IFilesystemNode
{
   public:
    using Ptr = std::shared_ptr<IFilesystemNode>;

    virtual void accept( Behavioral::Visitor::NodeVisitor& _visitor ) = 0;

    virtual size_t getEntrySize() const = 0;

    virtual std::string getFileExtension() const = 0;

    virtual ~IFilesystemNode() = default;
};

class DirectoryNode : public IFilesystemNode
{
   public:
    using Ptr = std::shared_ptr<DirectoryNode>;

    ~DirectoryNode() override = default;

   public:
    size_t getEntrySize() const override;

    std::string getFileExtension() const override;

    void addEntry( const std::shared_ptr<IFilesystemNode>& _node );

    void accept( Behavioral::Visitor::NodeVisitor& _visitor ) override;

   private:
    std::vector<std::shared_ptr<IFilesystemNode>> m_entries;
};

class IFileNode : public IFilesystemNode
{
   public:
    IFileNode( size_t _fileSize );

    size_t getEntrySize() const override;

    ~IFileNode() override = default;

   private:
    size_t m_fileSize;
};

class CppFileNode : public IFileNode
{
   public:
    CppFileNode( size_t _fileSize );

    std::string getFileExtension() const override;

    void accept( Behavioral::Visitor::NodeVisitor& _visitor ) override;

    ~CppFileNode() override = default;
};

class PdfFileNode : public IFileNode
{
   public:
    PdfFileNode( size_t _fileSize );

    std::string getFileExtension() const override;

    void accept( Behavioral::Visitor::NodeVisitor& _visitor ) override;

    ~PdfFileNode() override = default;
};

class BatFileNode : public IFileNode
{
   public:
    BatFileNode( size_t _fileSize );

    std::string getFileExtension() const override;

    void accept( Behavioral::Visitor::NodeVisitor& _visitor ) override;

    ~BatFileNode() override = default;
};

enum class FileExtension
{
    Cpp,
    Pdf,
    Bat
};

DirectoryNode::Ptr createDirectory();

IFilesystemNode::Ptr
createFile( FileExtension _fileExtension, size_t _fileSize );

};  // namespace Behavioral::Visitor::Filesystem::Nodes
