#pragma once

#include <animaMaskedImageToImageFilter.h>
#include <itkImage.h>

namespace anima
{

template <class TPixelType, unsigned int TImageDimension = 3>
class DoubleLogPValueImageFilter :
    public anima::MaskedImageToImageFilter< itk::Image <TPixelType,TImageDimension>,
                                    itk::Image <TPixelType,TImageDimension> >
{
public:
    /** Standard class typedefs. */
    using Self = DoubleLogPValueImageFilter;
    
    using InputImageType = itk::Image<TPixelType,TImageDimension>;
    using InputPixelType = typename InputImageType::PixelType;
    
    using OutputImageType = itk::Image<TPixelType,TImageDimension>;
    using OutputPixelType = typename OutputImageType::PixelType;
    
    using Superclass = anima::MaskedImageToImageFilter<InputImageType, OutputImageType>;
    
    using Pointer = itk::SmartPointer<Self>;
    using ConstPointer = itk::SmartPointer<const Self>;
    
    /** Method for creation through the object factory. */
    itkNewMacro(Self);
    
    /** Run-time type information (and related methods) */
    itkTypeMacro(DoubleLogPValueImageFilter, MaskedImageToImageFilter);
    
    /** Superclass typedefs. */
    using InputImageRegionType = typename Superclass::InputImageRegionType;
    using OutputImageRegionType = typename Superclass::OutputImageRegionType;
    using MaskImageType = typename Superclass::MaskImageType;
    
    using InputPointerType = typename InputImageType::Pointer;
    using OutputPointerType = typename OutputImageType::Pointer;

    itkSetMacro(UseMask, bool);
    // equivalent to: void SetUseMask(const bool val) { m_UseMask = val; }

protected:
    DoubleLogPValueImageFilter() : Superclass()
    {
        m_UseMask = false;
    }
    
    virtual ~DoubleLogPValueImageFilter() {}

    void DynamicThreadedGenerateData(const OutputImageRegionType& outputRegionForThread) ITK_OVERRIDE;

private:
    ITK_DISALLOW_COPY_AND_ASSIGN(DoubleLogPValueImageFilter);

    bool m_UseMask;
};

} // end of namespace anima

#include "animaDoubleLogPValueImageFilter.hxx"
