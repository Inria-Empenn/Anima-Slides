#include <tclap/CmdLine.h>
#include <iostream>
#include <string>

#include <itkImage.h>
#include <itkConstImageRegionIterator.h>
#include <itkImageRegionIterator.h>

#include <animaReadWriteFunctions.h>

int main(int argc, char **argv)
{
    TCLAP::CmdLine cmd("INRIA / IRISA - VisAGeS/Empenn Team", ' ', ANIMA_VERSION);

    TCLAP::ValueArg<std::string>   inArg("i",  "input-file",  "Input image",  true, "", "string", cmd);
    TCLAP::ValueArg<std::string>  outArg("o", "output-file", "Output image",  true, "", "string", cmd);
    TCLAP::ValueArg<std::string> maskArg("m",   "mask-file",   "Mask image", false, "", "string", cmd);

    try
    {
        cmd.parse(argc,argv);
    }
    catch (TCLAP::ArgException& e)
    {
        std::cerr << "Error: " << e.error() << "for argument " << e.argId() << std::endl;
        return EXIT_FAILURE;
    }

    using ImageType = itk::Image<double,3>;
    using MaskImageType = itk::Image<unsigned int, 3>;

    ImageType::Pointer inputImage = anima::readImage<ImageType>(inArg.getValue());

    bool useMask = maskArg.getValue() != "";
    MaskImageType::Pointer maskImage;
    if (useMask)
    {
        maskImage = anima::readImage<MaskImageType>(maskArg.getValue());
    }

    ImageType::Pointer outputImage = ImageType::New();
    outputImage->Initialize();
    outputImage->SetRegions(inputImage->GetLargestPossibleRegion());
    outputImage->SetSpacing(inputImage->GetSpacing());
    outputImage->SetOrigin(inputImage->GetOrigin());
    outputImage->SetDirection(inputImage->GetDirection());

    outputImage->Allocate();

    itk::ConstImageRegionIterator<ImageType> inItr(inputImage, outputImage->GetLargestPossibleRegion());
    
    itk::ConstImageRegionIterator<MaskImageType> maskItr;
    if (useMask)
    {
        maskItr = itk::ConstImageRegionIterator<MaskImageType>(maskImage, outputImage->GetLargestPossibleRegion());
    }

    itk::ImageRegionIterator<ImageType> outItr(outputImage, outputImage->GetLargestPossibleRegion());

    while (!outItr.IsAtEnd())
    {
        if (useMask)
        {
            if (maskItr.Get() == 0)
            {
                outItr.Set(0.0);
                ++inItr;
                ++outItr;
                ++maskItr;
                continue;
            }
        }

        double inputValue = inItr.Get();
        double outputValue = std::log(-std::log(inputValue));
        outItr.Set(outputValue);
        ++inItr;
        ++outItr;
        
        if (useMask)
        {
            ++maskItr;
        }
    }

    anima::writeImage<ImageType>(outArg.getValue(), outputImage);

    return EXIT_SUCCESS;
}
