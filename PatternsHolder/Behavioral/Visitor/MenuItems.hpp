#pragma once

#include <string>

namespace Visitor::Filesystem::Exceptions
{
	class BadExtensionCall : public std::exception
	{
       public:

		explicit BadExtensionCall( char const* _message )
            : m_warnMessage{ _message }
		{
		}

		explicit BadExtensionCall( const std::string& _message )
            : m_warnMessage{ _message }
		{
		}

		~BadExtensionCall() = default;

        char const* what() override { return m_warnMessage.c_str(); }

		private:
        std::string m_warnMessage;
	};
};

namespace Visitor::Filesystem::Nodes
{
class IFilesystemNode
{
   public:
    virtual size_t getEntrySize() = 0;

    virtual std::string getFileExtension() = 0;

    virtual ~IFilesystemNode() = default;
};

class DirectoryNode : public IFilesystemNode
{
   public:
    size_t getEntrySize() override;

    std::string getFileExtension() override;

    ~DirectoryNode() override = default;

   private:
    std::weak_ptr<IFilesystemNode>
};

class IFileNode : public IFilesystemNode
{
   public:
    size_t getEntrySize() override;

    ~IFileNode() override = default();

   private:
    size_t m_fileSize;
};

class CppFileNode : public IFileNode
{
   public:
    std::string getFileExtension() override;

    ~CppFileNode() override = default;
};

class PdfFileNode : public IFileNode
{
   public:
    std::string getFileExtension() override;

    ~PdfFileNode() override = default;
};

class BatFileNode : public IFileNode
{
   public:
    std::string getFileExtension() override;

    ~BatFileNode() override = default;
};
};  // namespace Visitor::FilesystemNodes