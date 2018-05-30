#include "StdAfx.h"
#include "VisionChart.h" 

namespace vision { 

	VisionChart::VisionChart(Chart^ chart)
	{
		this->chart = chart ;  

		this->xSamples = gcnew System::Collections::ArrayList(); 
		this->ySamples = gcnew System::Collections::ArrayList(); 

		this->chartInfo = new ChartInfo() ; 

		this->InitData();
	} 

	VisionChart::~VisionChart()
	{
		if( NULL != chartInfo ) {
			delete chartInfo ; 
			chartInfo = NULL ; 
		}
	}

	void VisionChart::InitData()
	{ 
		if( this->chart->ChartAreas->Count > 0 ) { 
			this->chartArea = this->chart->ChartAreas[0]; 
		} else {
			this->chartArea = nullptr  ; 
		}

		this->xAxis = chartArea->AxisX;
		this->yAxis = chartArea->AxisY;

		this->xSrs = chart->Series[0];
		this->ySrs = chart->Series[1]; 

		if( this->chart->Series->Count > 2 ) {
			this->xPeakSrs = chart->Series[ 2 ];  
		} else {
			this->xPeakSrs = nullptr ; 
		}

		if( this->chart->Series->Count > 3 ) {
			this->yPeakSrs = chart->Series[ 3 ]; 
		} else {
			this->yPeakSrs = nullptr ; 
		}

		if( this->chart->Series->Count > 4 ) {
			this->filterSrs = chart->Series[ 4 ]; 
		} else {
			this->filterSrs = nullptr ; 
		} 

		tempMaxY = 0 ;
	} 

	void VisionChart::InitChart()
	{
		xSrs->Points->Clear();
		ySrs->Points->Clear();

		if( nullptr != xSamples ) {
			xSamples->Clear();
		}

		if( nullptr != ySamples ) {
			ySamples->Clear();
		}  

		if( nullptr != this->xPeakSrs ) {
			xPeakSrs->Points->Clear() ; 

			this->dpXPeak = gcnew DataPoint( -1, 0 );

			this->xPeakSrs->Points->Add( dpXPeak );
		}

		if( nullptr != this->yPeakSrs ) {
			yPeakSrs->Points->Clear();

			this->dpYPeak = gcnew DataPoint( -1, 0 );

			this->yPeakSrs->Points->Add( dpYPeak );
		}

		if( nullptr != this->filterSrs ) {
			filterSrs->Points->Clear();

			this->dpFilterHighPass = gcnew DataPoint( -1, 0 );
			this->dpFilterLowPass = gcnew DataPoint( -1, 0 );

			this->filterSrs->Points->Add(  dpFilterHighPass );
			this->filterSrs->Points->Add(  dpFilterLowPass );
		} 
	}

	double VisionChart::GetStepValue( double v , double interval )
	{

		int iv = (int) ( v > 0 ? v : - v ) ; 
		int ii = (int) interval ;  

		ii = ii > 0 ? ii : 1 ;

		int max = (iv/ii)*ii;
		while( max < v ) {
			max += ii ; 
		}

		return v > 0 ? max : - max ;
	} 

	ArrayList^ VisionChart::GetXSamples()
	{
		return this->xSamples ; 
	}

	ArrayList^ VisionChart::GetYSamples()
	{
		return this->ySamples ;
	} 

	std::string VisionChart::SetSeriesEnabled( int sidx, bool b )
	{
		if( sidx < chart->Series->Count ) { 
			Series^ srs = chart->Series[sidx];
			srs->Enabled = b;

			if( xSrs == srs && nullptr != xPeakSrs ) {
				xPeakSrs->Enabled = b; 
			}

			if( ySrs == srs && nullptr != yPeakSrs ) {
				yPeakSrs->Enabled = b; 
			}

			return "";
		} else {
			return "invalid idx";
		}
	}

	int VisionChart::GetSampleDataCnt()
	{
		int dataCnt = this->xSamples->Count ;

		if( dataCnt < 1 ) {
			dataCnt = this->ySamples->Count ; 
		}

		return dataCnt ; 
	} 

	void VisionChart::SetXAxisInt( double interval )
	{
		this->xAxis->Interval = interval;  
	} 

	double VisionChart::GetXAxisInt()
	{
		// axis interval
		if( nullptr != this->chartArea ) {
			// interval
			return this->chartArea->AxisX->Interval ; 
		}
		return 0;
	}

	int VisionChart::GetXAxisWidth()
	{
		// axis width
		if( nullptr != this->chartArea ) {
			// width
			int chartSize = this->chart->Width ; 
			float chartAreaPosWidth = this->chartArea->Position->Width ; 

			return (int) ( chartSize*chartAreaPosWidth/100.0 );
		}
		return 0;
	}

	void VisionChart::SetXAxisMin( double min )
	{
		this->xAxis->Minimum = min ; 
	}

	void VisionChart::SetXAxisMax( double maxX )
	{
		this->chartInfo->maxX = maxX ; 

		double currMax = xAxis->Maximum ; 
		double diff = maxX - currMax ;

		currMax += diff/3.0; 

		if( currMax != xAxis->Maximum  ) { 
			this->xAxis->Maximum = currMax ; 
		}
	}

	void VisionChart::SetYAxisMin( double min )
	{
		double interval = yAxis->Interval ; 

		double stepValue = this->GetStepValue( min, interval );

		this->chartInfo->minY = stepValue ; 

		this->yAxis->Minimum = stepValue ; 
	}

	void VisionChart::SetYAxisMax( double maxY )
	{
		if( maxY <= 0 ) {
			maxY = 1; 
		}

		double tMax = maxY;

		int log = (int) log10( maxY );
		int tenPow = (int) pow( 10.0, log );

		int logMax = (int) maxY ;
		logMax = logMax/tenPow*tenPow;

		while( logMax < maxY ) {
			logMax += tenPow;
		}

		int interval = (int)( logMax/5 ) ; 

		int tInt = (interval/5)*5;
		while( tInt < interval ) {
			tInt += 5;
		}

		interval = tInt ;

		if( maxY < 1 ) {
			double tempInt = 0.2 ; 
			yAxis->Interval = tempInt ;
			logMax = 1;
		} else if( maxY < 10 ) {
			interval = 1 ; 
			yAxis->Interval = 2 ;
			logMax = 10 ;
		} else {
			yAxis->Interval = interval ;  
		} 

		interval = interval > 1 ? interval : 1 ; 

		tMax = logMax ;

		if( tMax <= ( maxY  + interval/3 ) ) {
			tMax += interval ; 
		}

		double offSet = interval/100.0;

		tMax += offSet ; 

		this->chartInfo->maxY = tMax ; 

		double currMax = yAxis->Maximum ; 
		double diff = tMax - currMax ;

		currMax += diff/3.0 ; 

		if( currMax != yAxis->Maximum ) {
			this->yAxis->Maximum = currMax ; 
		}
	} 

	double VisionChart::GetYAxisMax()
	{
		return this->yAxis->Maximum ; 
	} 	

	void VisionChart::SetYAxisInt( double interval )
	{
		this->yAxis->Interval = interval; 
	}

}