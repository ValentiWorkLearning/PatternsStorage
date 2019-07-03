#pragma once

#include <string>

class IFilesystemNode
{
   public:

    virtual size_t getEntrySize() = 0;

    virtual ~IFilesystemNode() = default;
};

class DirectoryNode : public IFilesystemNode
{
    size_t getEntrySize() override;
	
	~DirectoryNode() override = default;
};

class IFileNode : public IFilesystemNode
{

public:

    size_t getEntrySize() override;

    virtual std::string getFileExtension() = 0;

	~IFileNode() override = default();

   private:
    size_t m_fileSize;
};

class CppFileNode : public IFileNode
{
    std::string getFileExtension() override;

	~CppFileNode() override = default;
};
