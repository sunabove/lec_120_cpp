#pragma once
 
#include "MatchResult.h"
#include "VideoInfo.h"
#include "VisionOptionInterface.h"
#include "ChartInfo.h"

namespace vision { 

	using namespace System::Windows::Forms::DataVisualization::Charting;  
	using namespace System::Collections;

	ref class VisionChart abstract
	{

	public: 

		VisionChart(Chart^ chart );
		~VisionChart();

		virtual void InitData();

	private:
		ChartInfo * chartInfo ; 

	protected :
		ArrayList^ xSamples ;
		ArrayList^ ySamples ;

		Chart^ chart; 
		ChartArea^ chartArea ; 
		
		Axis^ xAxis ;
		Axis^ yAxis ;

		Series^ xSrs;
		Series^ ySrs; 

		Series^ xPeakSrs;
		Series^ yPeakSrs;

		Series^ filterSrs;

		DataPoint^ dpXPeak ;
		DataPoint^ dpYPeak ;
		DataPoint^ dpFilterHighPass ;
		DataPoint^ dpFilterLowPass ; 

		double  tempMaxY ;  

	public: 
		
		virtual double GetStepValue( double d, double interval );

		virtual void ProcessMatchResult( MatchResult * matchResult, VideoInfo * videoInfo , VisionOptionInterface^ vi ) = 0 ;

		virtual void InitChart() ;

		virtual ArrayList^ GetXSamples() ;

		virtual ArrayList^ GetYSamples() ; 

		virtual std::string SetSeriesEnabled( int sidx, bool b ) ;

		virtual int GetSampleDataCnt() ;  

		virtual void SetXAxisInt( double interval );

		virtual double GetXAxisInt() ;

		virtual int GetXAxisWidth() ;

		virtual void SetXAxisMin( double min );

		virtual void SetXAxisMax( double max ) ; 

		virtual double GetYAxisMax() ; 

		virtual void SetYAxisMin( double min ) ;

		virtual void SetYAxisMax( double d ) ;  

		virtual void SetYAxisInt( double interval ) ; 

	};

}

