#pragma once
#include "VisionChart.h"  

using namespace System::Windows::Forms::DataVisualization::Charting; 
using namespace System::Collections;

ref class VisionChartFreq : public vision::VisionChart
{
public:
	VisionChartFreq(Chart ^ chart);

private: 
	int fps ; // frames per second
	double xMaxAmpFreq ;
	double yMaxAmpFreq ;

	double preYAxisMax ;  

public: 

public:

	virtual void InitChart() override ;

	virtual int GetFps() ; 

	virtual Aquila::SpectrumType GetFftSpectrum( ArrayList^ samples ) ; 

	virtual double GetXMaxAmpFreq() ;

	virtual double GetYMaxAmpFreq() ; 

	virtual Aquila::SpectrumType GetXSpectrumAll() ;

	virtual Aquila::SpectrumType GetYSpectrumAll() ;

	virtual double ProcessSpectrum(Series^ series, Series^peakSeries, Aquila::SpectrumType * spectrum, VideoInfo * videoInfo, VisionOptionInterface^ vi, const double highPassHz , const double lowPassHz ) ;

	virtual double ProcessDft(Series^ series, Series^ peakSeries, ArrayList^ samples, VideoInfo * videoInfo, VisionOptionInterface^ vi, const double highPassHz, const double lowPassHz );

	virtual double ProcessFft(Series^ series, Series^ peakSeries, ArrayList^ samples, VideoInfo * videoInfo, VisionOptionInterface^ vi, const double highPassHz, const double lowPassHz );

	virtual void ProcessMatchResult( MatchResult * matchResult, VideoInfo * videoInfo, VisionOptionInterface^ vi ) override ; 

};

