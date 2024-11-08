# Documenting anima executables
Currently, there are over 150 executables in anima codebase, most of which
offer little to no documentation when called with the `-h` flag in the
command-line. The objective of this project is to add a minimalistic
description (1-2 sentences) to every executable.

In the meantime, we will also re-organize command-line arguments so that they
appear in this order when the `-h` option is invoked:
- required arguments
- switch arguments
- optional arguments

Here is a list of all the binaries. We will fill in a quick one-sentence documentation for each through the next updates.
<dl>
  <dt>animaAnalyticAssociatedLegendre</dt>
  <dt>animaApplyDistortionCorrection</dt>
  <dt>animaApplyTransformSerie</dt>
  <dt>animaApplyVtkTransform</dt>
  <dt>animaAverageImages</dt>
  <dt>animaAverageLinearTransforms</dt>
  <dt>animaBMDistortionCorrection</dt>
  <dt>animaBackgroundNoiseVarianceEstimator</dt>
  <dt>animaBootstrap4DVolume</dt>
  <dt>animaBuildSamplesFromVolumes</dt>
  <dt>animaCollapseImage</dt>
  <dt>animaCollapseLabelImage</dt>
  <dt>animaCombinedRelaxometryEstimation</dt>
  <dt>animaConcatenateImages</dt>
  <dt>animaConnectedComponents</dt>
  <dt>animaConnectedComponentsMetrics</dt>
  <dt>animaConvertImage</dt>
  <dt>animaConvertShapes</dt>
  <dt>animaCovarianceImages</dt>
  <dt>animaCramersTest</dt>
  <dt>animaCreateImage</dt>
  <dt>animaCropImage</dt>
  <dt>animaDTIEstimator</dt>
  <dt>animaDTINonCentralChiEstimator</dt>
  <dt>animaDTIProbabilisticTractography</dt>
    <dd>This tool implements for DTI our multi-modal particle filtering framework for probabilistic tractography. It relies on the simultaneous propagation of particles and their filtering relative to previous directions and the current model.</dd>
  <dt>animaDTIScalarMaps</dt>
  <dt>animaDTITractography</dt>
    <dd>This tool implements DTI based deterministic tractography.</dd>
  <dt>animaDWISimulationFromMCM</dt>
  <dt>animaDWISimulatorFromDTI</dt>
  <dt>animaDenseMCMSVFBMRegistration</dt>
  <dt>animaDenseSVFBMRegistration</dt>
  <dt>animaDenseTensorSVFBMRegistration</dt>
  <dt>animaDenseTransformArithmetic</dt>
  <dt>animaDetectedComponents</dt>
  <dt>animaDiceMeasure</dt>
  <dt>animaDisplacementFieldJacobian</dt>
  <dt>animaDistanceMap</dt>
  <dt>animaDistortionCorrection</dt>
  <dt>animaEddyCurrentCorrection</dt>
  <dt>animaEnlargeImage</dt>
  <dt>animaExpTensors</dt>
  <dt>animaFDRCorrectPValues</dt>
  <dt>animaFiberPropertyExtractAndRescale</dt>
  <dt>animaFibersAContrario</dt>
  <dt>animaFibersApplyTransformSerie</dt>
    <dd>This tool works as a resampler, but it applies a series of transformations to a set of fibers.</dd>
  <dt>animaFibersCounter</dt>
    <dd>This tool takes as an input a geometry image and uses the input to know how many fibers go through each pixel of that image.</dd>
  <dt>animaFibersDiseaseScores</dt>
  <dt>animaFibersFDRCorrectPValues</dt>
  <dt>animaFibersFilterer</dt>
    <dd>This tool uses a labeled region of interest image to filter a set of fibers. The -t and -f options can be given multiple times and are used to tell which labels a single fiber should go through.</dd>
  <dt>animaFillHoleImage</dt>
  <dt>animaFlipTensors</dt>
  <dt>animaFuzzyDiceMeasure</dt>
  <dt>animaGMMT2RelaxometryEstimation</dt>
  <dt>animaGammaMixtureT2RelaxometryEstimation</dt>
  <dt>animaGcStremMsLesionsSegmentation</dt>
  <dt>animaGeneralizedFA</dt>
  <dt>animaGenerateIsoradiusDDISurface</dt>
  <dt>animaGetScalarMapFromDDI</dt>
  <dt>animaGraphCut</dt>
  <dt>animaGrowLesionSeeds</dt>
  <dt>animaImageArithmetic</dt>
  <dt>animaImageMosaicing</dt>
  <dt>animaImageResolutionChanger</dt>
  <dt>animaImageSmoother</dt>
  <dt>animaInfluenceZones</dt>
  <dt>animaIsosurface</dt>
  <dt>animaKMeansClustering</dt>
  <dt>animaKMeansStandardization</dt>
  <dt>animaLesionEvolutionDetection</dt>
  <dt>animaLinearTransformArithmetic</dt>
  <dt>animaLinearTransformToSVF</dt>
  <dt>animaLocalPatchCovarianceDistance</dt>
  <dt>animaLocalPatchMeanDistance</dt>
  <dt>animaLogTensors</dt>
  <dt>animaLowMemCramersTest</dt>
  <dt>animaLowMemLocalPatchCovarianceDistance</dt>
  <dt>animaLowMemLocalPatchMeanDistance</dt>
  <dt>animaLowMemMCMEstimator</dt>
  <dt>animaLowMemNLMeansPatientToGroupComparison</dt>
  <dt>animaLowMemPatientToGroupComparison</dt>
  <dt>animaLowMemPatientToGroupODFComparison</dt>
  <dt>animaMCMApplyTransformSerie</dt>
  <dt>animaMCMAverageImages</dt>
    <dd>This tool provides a way to average several volumes of MCM into just one, using an averaging and interpolation framework.</dd>
  <dt>animaMCMEstimator</dt>
    <dd>This tool provides a Multi-Compartment Model estimation from DWI data, following a maximum likelihood method.\n\n It allows to estimate models including isotropic compartments, and directional compartments.</dd>
  <dt>animaMCMMergeBlockImages</dt>
  <dt>animaMCMModelAveraging</dt>
    <dd>This tool uses outputs from MCM estimations from 0 to N fiber compartments and their AICc scores (produced by animaMCMEstimator) to compute an average MCM volume with simplification to the optimal number of fibres in each voxel.</dd>
  <dt>animaMCMProbabilisticTractography</dt>
    <dd>This tool implements for MCM our multi-modal particle filtering framework for probabilistic tractography. It relies on the simultaneous propagation of particles and their filtering relative to previous directions and the current model.</dd>
  <dt>animaMCMScalarMaps</dt>
  <dd>This tool provides voxel-wise measures extracted from an MCM image. The currently supported parameters include isotropic and anisotropic water proportions, apparent diffusivities and fractional anisotropy.</dd>
  <dt>animaMCMTractography</dt>
    <dd>This tool computes multi-compartment models based deterministic tractography.</dd>
  <dt>animaMajorityLabelVoting</dt>
  <dt>animaMaskImage</dt>
  <dt>animaMergeBlockImages</dt>
  <dt>animaMorphologicalOperations</dt>
  <dt>animaMultiT2RelaxometryEstimation</dt>
  <dt>animaMultiThreadedSTAPLE</dt>
  <dt>animaN4BiasCorrection</dt>
  <dt>animaNLMeans</dt>
  <dt>animaNLMeansPatientToGroupComparison</dt>
  <dt>animaNLMeansTemporal</dt>
  <dt>animaNoiseGenerator</dt>
  <dt>animaNyulStandardization</dt>
  <dt>animaODFApplyTransformSerie</dt>
  <dt>animaODFEstimator</dt>
  <dt>animaODFProbabilisticTractography</dt>
    <dd>This tool implements for ODF our multi-modal particle filtering framework for probabilistic tractography. It relies on the simultaneous propagation of particles and their filtering relative to previous directions and the current model.</dd>
  <dt>animaOtsuThrImage</dt>
  <dt>animaPatientToGroupComparison</dt>
  <dt>animaPatientToGroupComparisonOnTracks</dt>
  <dt>animaPatientToGroupODFComparison</dt>
  <dt>animaPickLesionSeeds</dt>
  <dt>animaPseudoResidualsNoiseEstimation</dt>
  <dt>animaPyramidImage</dt>
  <dt>animaPyramidalBMRegistration</dt>
  <dt>animaQMRILesionSampleCreator</dt>
  <dt>animaROIIntensitiesStats</dt>
  <dt>animaRemoveTouchingBorder</dt>
  <dt>animaSampleImageFromDistribution</dt>
  <dt>animaSegPerfAnalyzer</dt>
  <dt>animaSimuBlochCoherentGRE</dt>
  <dt>animaSimuBlochGRE</dt>
  <dt>animaSimuBlochIR-GRE</dt>
  <dt>animaSimuBlochIR-SE</dt>
  <dt>animaSimuBlochSE</dt>
  <dt>animaSimuBlochSP-GRE</dt>
  <dt>animaStimulatedSpinEchoSimulator</dt>
  <dt>animaSymmetryConstrainedRegistration</dt>
  <dt>animaSymmetryPlane</dt>
  <dt>animaT1RelaxometryEstimation</dt>
  <dt>animaT1SERelaxometryEstimation</dt>
  <dt>animaT2EPGRelaxometryEstimation</dt>
  <dt>animaT2RelaxometryEstimation</dt>
  <dt>animaTensorApplyTransformSerie</dt>
  <dt>animaThrImage</dt>
  <dt>animaTissuesEMClassification</dt>
  <dt>animaTotalLesionLoad</dt>
  <dt>animaTracksMCMPropertiesExtraction</dt>
    <dd>This tool extracts MCM compartment properties along tracts. Thanks to the multi-compartment nature of MCMs we can extract the compartment closest to the fiber pathway.</dd>
  <dt>animaTransformSerieXmlGenerator</dt>
  <dt>animaVectorizeImages</dt>
</dl>
