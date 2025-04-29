#pragma once

#include <itkImageRegionConstIterator.h>
#include <itkImageRegionIterator.h>

namespace anima
{

template <class TPixelType, unsigned int TImageDimension>
void
DoubleLogPValueImageFilter<TPixelType,TImageDimension>
::DynamicThreadedGenerateData(const OutputImageRegionType& outputRegionForThread)
{
    itk::ImageRegionConstIterator<InputImageType> inItr(this->GetInput(), outputRegionForThread);
    itk::ImageRegionConstIterator<MaskImageType> maskItr;
    if (m_UseMask)
        maskItr = itk::ImageRegionConstIterator<MaskImageType>(this->GetComputationMask(), outputRegionForThread);
    itk::ImageRegionIterator<OutputImageType> outItr(this->GetOutput(), outputRegionForThread);
    
    while (!outItr.IsAtEnd())
    {
        if (m_UseMask)
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

        this->IncrementNumberOfProcessedPoints();
        ++inItr;
        ++outItr;
        
        if (m_UseMask)
        {
            ++maskItr;
        }
    }
}

} // end of namespace anima
