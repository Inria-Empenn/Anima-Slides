#include "animaDoubleLogPValueImageFilter.h"

#include <animaReadWriteFunctions.h>

#include <itkImage.h>

#include <tclap/CmdLine.h>

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    TCLAP::CmdLine cmd("INRIA / IRISA - VisAGeS/Empenn Team", ' ', ANIMA_VERSION);

    TCLAP::ValueArg<std::string>          inArg("i",  "input-file",       "Input image",  true, "",       "string", cmd);
    TCLAP::ValueArg<std::string>         outArg("o", "output-file",      "Output image",  true, "",       "string", cmd);
    TCLAP::ValueArg<std::string>        maskArg("m",   "mask-file",        "Mask image", false, "",       "string", cmd);
    TCLAP::ValueArg<unsigned int> numThreadsArg("T", "num-threads", "Number of threads", false,  1, "unsigned int", cmd);

    try
    {
        cmd.parse(argc,argv);
    }
    catch (TCLAP::ArgException& e)
    {
        std::cerr << "Error: " << e.error() << "for argument " << e.argId() << std::endl;
        return EXIT_FAILURE;
    }

    using FilterType = anima::DoubleLogPValueImageFilter<double, 3>;
    using ImageType = FilterType::InputImageType;
    using MaskImageType = FilterType::MaskImageType;

    FilterType::Pointer filter = FilterType::New();

    ImageType::Pointer inputImage = anima::readImage<ImageType>(inArg.getValue());
    filter->SetInput(inputImage);

    bool useMask = maskArg.getValue() != "";
    filter->SetUseMask(useMask);

    MaskImageType::Pointer maskImage;
    if (useMask)
    {
        maskImage = anima::readImage<MaskImageType>(maskArg.getValue());
        filter->SetComputationMask(maskImage);
    }

    filter->SetNumberOfWorkUnits(numThreadsArg.getValue());

    filter->Update();

    anima::writeImage<ImageType>(outArg.getValue(), filter->GetOutput());

    return EXIT_SUCCESS;
}