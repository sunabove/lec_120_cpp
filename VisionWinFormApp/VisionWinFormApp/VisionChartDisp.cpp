#include "StdAfx.h"
#include "VisionChartDisp.h"


VisionChartDisp::VisionChartDisp(Chart^ chart) : VisionChart( chart )
{
	
}

void VisionChartDisp::InitChart()
{
	VisionChart::InitChart();

	this->xAxis->Minimum = 0 ;
	this->xAxis->Maximum = 15 ; 
	this->xAxis->Interval = 1 ; 

	// add two data points to show chart visually
	DataPoint^ dp ;
	
	dp = gcnew DataPoint( -1, 10 ); 

	this->xSrs->Points->Add( dp );

	dp = gcnew DataPoint( -1, -10 ); 

	this->ySrs->Points->Add( dp );
	// end of adding two virtual data points.

}

void VisionChartDisp::ProcessMatchResult( MatchResult * matchResult, VideoInfo * videoInfo, VisionOptionInterface^ vi )
{
	if( NULL == matchResult ) {
		return ;
	}

	Disp * disp = matchResult->GetDisp(); 

	//const double sampleInterval = 1 / (videoInfo->fps + 0.0);

	double dx_mm = disp->GetDxMeter()*1000 ;
	double dy_mm = - disp->GetDyMeter()*1000 ;

	this->xSamples->Add( dx_mm ) ;
	this->ySamples->Add( dy_mm ) ;  

	DataPoint^ dp;
	double timeSec;
	double disp_mm;

	int i = this->xSamples->Count;

	timeSec = i / (videoInfo->fps + 0.0) ;

	disp_mm = dx_mm;
	dp = gcnew DataPoint(timeSec, disp_mm); 

	xSrs->Points->Add(dp);

	disp_mm = dy_mm;
	dp = gcnew DataPoint(timeSec, disp_mm);

	ySrs->Points->Add(dp); 

	if (true) {
		// set x axis max value 
		int t = (int)(timeSec + 0.5);

		int itv = (int)(this->GetXAxisInt());

		itv = itv < 1 ? 1 : itv;

		t = (t / itv)*itv;

		while (t <= timeSec) {
			t += itv;
		}

		double offSet = 0.001;

		double maxX = t + offSet;

		this->SetXAxisMax(maxX); 
	}

}

void VisionChartDisp::ProcessMatchResultSmart( MatchResult * matchResult, VideoInfo * videoInfo, VisionOptionInterface^ vi )
{
	if( NULL == matchResult ) {
		return ;
	}

	Disp * disp = matchResult->GetDisp(); 

	double dx_mm = disp->GetDxMeter()*1000 ;
	double dy_mm = - disp->GetDyMeter()*1000 ;

	this->xSamples->Add( dx_mm ) ;
	this->ySamples->Add( dy_mm ) ;  

	ChartInfo xChartInfo;

	const bool xEnabled = xSrs->Enabled ; 
	if( xEnabled ) { 
		//xSrs->Enabled = false ; 
		this->ProcessSeries( & xChartInfo, xSrs, xSamples, videoInfo, vi );
		
	}

	ChartInfo yChartInfo;

	const bool yEnabled = ySrs->Enabled ; 
	if( yEnabled ) { 
		//ySrs->Enabled = false ; 
		this->ProcessSeries( & yChartInfo, ySrs, ySamples, videoInfo, vi ); 
	}

	xChartInfo.SetCompData( & yChartInfo );

	ChartInfo * chartInfo = & xChartInfo ;  

	double maxX = chartInfo->maxX ; 
	maxX = maxX > 0 ? maxX : 0.1 ; 
	
	this->SetXAxisMax( maxX );

	//xSrs->Enabled = xEnabled ; 
	//ySrs->Enabled = yEnabled;

}

void VisionChartDisp::ProcessSeries(ChartInfo * chartInfo, Series^ series , ArrayList^ samples, VideoInfo * videoInfo, VisionOptionInterface^ vi )
{
	const double sampleInterval = 1/(videoInfo->fps +0.0) ; 

	DataPoint^ dp ; 
	double timeSec ;
	double disp_mm ; 

	const int pntCnt = series->Points->Count ; 

	const int axisWidth = this->GetXAxisWidth() ; 

	const int sampleCnt = samples->Count ; 
	bool chartPaintOpt  = sampleCnt > (2*axisWidth) ; 

	if( chartPaintOpt  ) { 
		// if x axisWidth is smaller than the spectrum count
		const int dataCntPerPix = (int)(sampleCnt/(axisWidth+0.0)) ;

		vi->showChartPaintOpt( dataCntPerPix );

		DataPointCollection^ points = series->Points ;   

		int idx = 0 ; 
		double tempMaxTimeSec ;  
		double tempMaxDisp_mm ; 

		int dataCnt = 0 ;  

		bool isPos ; // is positive flag.

		for( int i = 0 , iLen = sampleCnt ; i < iLen ; i ++ ) {

			timeSec = sampleInterval*i;
			disp_mm = (double)( samples[ i ] ); 
			
			isPos = disp_mm >= 0 ; 

			tempMaxTimeSec = timeSec ;
			tempMaxDisp_mm = isPos ? disp_mm : - disp_mm ;   

			idx = 1 ; 

			for( ; ( idx < dataCntPerPix )  && ( i < iLen ) ; idx ++ ) {  
				// check data inside one pixel interval.
				timeSec = sampleInterval*i;
				disp_mm = (double)( samples[ i ] ); 

				chartInfo->SetCompVertData( disp_mm );

				if( isPos && disp_mm < 0 ) {
					// if another sign data is encountered, break this loop;  
					idx = dataCntPerPix ; 
					break ;
				} else if( ! isPos && disp_mm >= 0 ) {
					// if another sign data is encountered, break this loop;  
					idx = dataCntPerPix ;
					break ;
				} else {  
					// if the same sign data is encountered, 
					// transform negative value to positive value
					disp_mm = isPos ? disp_mm : - disp_mm ;

					if( disp_mm > tempMaxDisp_mm ) { 
						tempMaxDisp_mm = disp_mm ; 
						tempMaxTimeSec = timeSec ; 
					} 

					i ++ ; 
				}
			} 
			 
			if( ! isPos ) {
				// restore the temp positive data as negative data.
				tempMaxDisp_mm = - tempMaxDisp_mm ; 
			}

			if( i < pntCnt ) {
				dp = points[ dataCnt ] ; 
				dp->XValue = tempMaxTimeSec ;
				dp->YValues[0] = tempMaxDisp_mm ; 
			} else {
				dp = gcnew DataPoint( tempMaxTimeSec, tempMaxDisp_mm ) ;
				points->Add( dp );
			}  

			dataCnt ++ ; 
		}  

		// set x-value as zero of empty data points
		// and y-value as zero of empty data points
		for( int i = dataCnt , iLen = pntCnt ; i < iLen ; i ++ ) {
			dp = points[ i ] ; 
			dp->XValue = tempMaxTimeSec + 0 ; 
			dp->YValues[0] = 0 ; 
		} 

	} else {  
		DataPointCollection^ points = series->Points ;  

		if( true ) {
			// init x values as negative to hide from the chart drawing
			// to use the old data again.
			for( int i = 0 , iLen = points->Count ; i < iLen ; i ++ ) {
				points[ i ]->XValue = -1 ; 
			}
		}

		for( int i = 0 , iLen = samples->Count ; i < iLen ; i ++ ) {
			timeSec = sampleInterval*i;
			disp_mm = (double)( samples[ i ] );

			chartInfo->SetCompVertData( disp_mm ) ; 

			if( i < pntCnt ) {
				dp = points[ i ] ; 
				dp->XValue = timeSec ;
				dp->YValues[0] = disp_mm ; 
			} else {
				dp = gcnew DataPoint( timeSec, disp_mm ) ;
				points->Add( dp );
			}  
		}  
	}

	if( true ) {
		// set x axis max value 
		int t = (int)( timeSec + 0.5); 

		int itv = (int) ( this->GetXAxisInt() ) ;

		itv = itv < 1 ? 1 : itv ; 

		t = (t/itv)*itv;

		while( t <= timeSec ) {
			t += itv ; 
		}

		double offSet = 0.001 ;

		chartInfo->maxX = t + offSet ;
	} 
} 
