#include <boost/assign.hpp>
#include <boost/range/adaptor/indexed.hpp>
#include <iostream>
#include <iterator>
#include <vector>

#include "Behavioral/SequenceOfResponsibility/CommandContextParser.hpp"

#include "Behavioral/Visitor/MenuItemVisitor.hpp"
#include "Behavioral/Visitor/MenuItems.hpp"
#include "Behavioral/Visitor/Literals.hpp"

#include "Creational/FactoryMethod/ContextCreator.hpp"
#include "Creational/FactoryMethod/RenderContext.hpp"


int main()
{
    // Creatioal/FactoryMethod
    {
        auto contextCreator = Creators::createOpenGlCreator();
        auto renderTarget = contextCreator->createRenderContext();

        renderTarget->forceRedraw();
    }

    // Behavioral/SequenceOfResponsibility
    {
        auto colorParser =
            std::make_shared<SequenceOfResponsibility::ColorParser>();
        auto marginsParser =
            std::make_shared<SequenceOfResponsibility::MarginsParser>();
        auto rangeParser =
            std::make_shared<SequenceOfResponsibility::RangeParser>();

        colorParser->setNext( marginsParser );
        marginsParser->setNext( rangeParser );

        std::vector<SequenceOfResponsibility::ContextType> contexts{

            SequenceOfResponsibility::ContextType::JsonRange,
            SequenceOfResponsibility::ContextType::JsonMargins,
            SequenceOfResponsibility::ContextType::JsonColor};

        for ( auto&& context : contexts )
            colorParser->parseContext( context );
    }

    // Behavioral/Visitor
    {
        namespace FileNode = Visitor::Filesystem::Nodes;

        auto visitor = Visitor::createPaintNodeVisitor();

        auto rootDir = FileNode::createDirectory();

        auto workDir = FileNode::createDirectory();

		using namespace Visitor::Filesystem::Literals;

        auto pdfFile = FileNode::createFile( FileNode::FileExtension::Pdf, 1000_bytes );
        auto batFile = FileNode::createFile( FileNode::FileExtension::Bat, 10_kb);
        auto cppSource = FileNode::createFile( FileNode::FileExtension::Cpp, 100_mb );

        rootDir->addEntry( pdfFile );
        rootDir->addEntry( workDir );

        workDir->addEntry( batFile );
        workDir->addEntry( cppSource );

        rootDir->accept( *visitor );
    }
    return 0;
}
