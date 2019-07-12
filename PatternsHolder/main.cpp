#include <boost/assign.hpp>
#include <boost/range/adaptor/indexed.hpp>
#include <iostream>
#include <iterator>
#include <vector>

#include "Behavioral/SequenceOfResponsibility/CommandContextParser.hpp"

#include "Behavioral/Visitor/Literals.hpp"
#include "Behavioral/Visitor/MenuItemVisitor.hpp"
#include "Behavioral/Visitor/MenuItems.hpp"

#include "Behavioral/Strategy/Image.hpp"
#include "Behavioral/Strategy/ImageInterpolator.hpp"
#include "Behavioral/Strategy/ImageLoader.hpp"
#include "Behavioral/Strategy/ImageProcessor.hpp"
#include "Behavioral/Strategy/ImageLoaderCreator.hpp"

#include "Creational/FactoryMethod/ContextCreator.hpp"
#include "Creational/FactoryMethod/RenderContext.hpp"

int main()
{
    // Creatioal/FactoryMethod
    {

		std::cout << "Creatioal/FactoryMethod" << std::endl;

        auto contextCreator = Creators::createOpenGlCreator();
        auto renderTarget = contextCreator->createRenderContext();

        renderTarget->forceRedraw();

		std::cout << "Creatioal/FactoryMethod" << std::endl;
    }

    // Behavioral/SequenceOfResponsibility
    {
        std::cout << "Behavioral/SequenceOfResponsibility" << std::endl;

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

		std::cout << "Behavioral/SequenceOfResponsibility" << std::endl;
    }

    // Behavioral/Visitor
    {
        std::cout << "Behavioral/Visitor" << std::endl;

        namespace FileNode = Visitor::Filesystem::Nodes;

        auto visitor = Visitor::createPaintNodeVisitor();

        auto rootDir = FileNode::createDirectory();

        auto workDir = FileNode::createDirectory();

        using namespace Visitor::Filesystem::Literals;

        auto pdfFile =
            FileNode::createFile( FileNode::FileExtension::Pdf, 1000_bytes );
        auto batFile =
            FileNode::createFile( FileNode::FileExtension::Bat, 10_kb );
        auto cppSource =
            FileNode::createFile( FileNode::FileExtension::Cpp, 100_mb );

        rootDir->addEntry( pdfFile );
        rootDir->addEntry( workDir );

        workDir->addEntry( batFile );
        workDir->addEntry( cppSource );

        rootDir->accept( *visitor );

		std::cout << "Behavioral/Visitor" << std::endl;
    }

	// Behavioral/Strategy
    {
        std::cout << "Behavioral/Strategy" << std::endl;

        const std::filesystem::path PathFromAbstractParser =
            "FolderWithImage/Image.png";

        auto fakeImageLoader =
            std::make_shared<Strategy::FakeImageLoaderCreator>();

		auto imageLoader = Strategy::createImageLoader( fakeImageLoader );

        auto imageForProcessing = imageLoader->loadImageFromSource( PathFromAbstractParser );
		
		auto imageProcessor = std::make_unique<Strategy::ImageProcessor>();

		auto interpolationMode = Strategy::getInterpolationAlgorithm(
            Strategy::InterpolationMode::Linear );

		imageProcessor->setImageInterpolationMode( std::move( interpolationMode ) );

		std::cout << "Image density before processing: "<<  imageForProcessing->getDensity() << std::endl;

		auto proceededImage = imageProcessor->processImage( std::move( imageForProcessing ) );
		
		std::cout << "Image density after processing: "<< proceededImage->getDensity() << std::endl;

		std::cout << "Behavioral/Strategy" << std::endl;
    }
    return 0;
}
