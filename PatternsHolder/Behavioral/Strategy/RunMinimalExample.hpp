#pragma once

#include "Behavioral/Strategy/Image.hpp"
#include "Behavioral/Strategy/ImageInterpolator.hpp"
#include "Behavioral/Strategy/ImageLoader.hpp"
#include "Behavioral/Strategy/ImageProcessor.hpp"
#include "Behavioral/Strategy/ImageLoaderCreator.hpp"

#include <iostream>

namespace Behavioral::Strategy
{

static void runMinimalExample()
{
    std::cout << "Behavioral/Strategy" << std::endl;

    const std::filesystem::path PathFromAbstractParser =
        "FolderWithImage/Image.png";

    auto fakeImageLoader = std::make_shared<Strategy::FakeImageLoaderCreator>();

    auto imageLoader = Strategy::createImageLoader( fakeImageLoader );

    auto imageForProcessing =
        imageLoader->loadImageFromSource( PathFromAbstractParser );

    auto imageProcessor = std::make_unique<Strategy::ImageProcessor>();

    auto interpolationMode = Strategy::getInterpolationAlgorithm(
        Strategy::InterpolationMode::Linear );

    imageProcessor->setImageInterpolationMode( std::move( interpolationMode ) );

    std::cout << "Image density before processing: "
              << imageForProcessing->getDensity() << std::endl;

    auto proceededImage =
        imageProcessor->processImage( std::move( imageForProcessing ) );

    std::cout << "Image density after processing: "
              << proceededImage->getDensity() << std::endl;

    std::cout << "Behavioral/Strategy" << std::endl;
}
};