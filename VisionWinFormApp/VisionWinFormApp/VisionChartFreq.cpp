#include "StdAfx.h"
#include "VisionChartFreq.h"

using namespace std ;
using namespace Aquila ;

VisionChartFreq::VisionChartFreq(Chart^ chart):VisionChart( chart )
{
	this->xMaxAmpFreq = 0 ;
	this->yMaxAmpFreq = 0 ; 

	this->fps = 30; 
}

void VisionChartFreq::InitChart()
{
	this->xMaxAmpFreq = 0 ;
	this->yMaxAmpFreq = 0 ; 

	this->preYAxisMax = 0 ;

	this->yAxis->Minimum = 0;
	this->yAxis->Maximum = 10 ;
	this->yAxis->Interval = 2 ; 

	this->xAxis->Minimum = 0 ;
	this->xAxis->Maximum = 15 ; 
	this->xAxis->Interval = 1 ; 

	VisionChart::InitChart(); 
}

int VisionChartFreq::GetFps()
{
	return this->fps ; 
}

double VisionChartFreq::GetXMaxAmpFreq()
{
	if( this->xSrs->Enabled ) { 
		return this->xMaxAmpFreq ; 
	}

	return 0;
}

double VisionChartFreq::GetYMaxAmpFreq()
{
	if( this->ySrs->Enabled ) { 
		return this->yMaxAmpFreq ; 
	}

	return 0;
}


Aquila::SpectrumType VisionChartFreq::GetFftSpectrum( ArrayList^ samples )
{
	// FFT(Fast Fourier Transform) Spectrum

	const int dftSize = samples->Count;

	int fftSize = dftSize ; 

	if( true ) { 
		// calculate the fft sample size as power( 2, int );
		double log2 = log( dftSize + 0.0 )/log(2 + 0.0) ;  

		int n = (int) ceil( log2 );

		fftSize = (int) pow( 2.0, n );

		while( fftSize < dftSize ) {
			n ++ ;
			fftSize = (int) pow( 2.0, n );
		}
	}

	ArrayList^ dftSamples = samples; 
	SampleType * fftSamples  = new SampleType[ fftSize ];  

	// copy the dft samples to the fft samples
	for( int i = 0, iLen = dftSize; i < iLen ; i ++ ) {
		fftSamples[ i ] = (SampleType) ( dftSamples[ i ] );
	}

	for( int i = dftSize, iLen = fftSize; i < iLen ; i ++ ) {
		fftSamples[ i ] = 0 ;
	} 

	OouraFft fft( fftSize ); 

	Aquila::SpectrumType spectrum = fft.fft( fftSamples );

	delete [] fftSamples ;  

	return spectrum;
}

double VisionChartFreq::ProcessSpectrum( Series^ series, Series^peakSeries, Aquila::SpectrumType * spectrum, VideoInfo * videoInfo, VisionOptionInterface^ vi, const double highPassHz, const double lowPassHz )
{
	const bool enabled = series->Enabled;

	//series->Enabled = false; 

	// do not the the data series. use the old data again. 

	this->fps = videoInfo->fps ; 

	const size_t spectrumCnt = spectrum->size(); 

	const int		fps = videoInfo->fps ; 
	const double	maxFreq = fps ; 
	const double	unitFreq = maxFreq/spectrumCnt ;   

	// x frequency offset calibration to prevent overlapping the y-axis .
	const double freqOffSetX = unitFreq/2.0;

	double freq ; // frequency
	double amp ;  // amplitude

	double maxAmp = 0 ; // max amplitude
	double maxAmpFreq = 0 ; // frequency of max amplitude

	DataPoint^ dp ;

	ComplexType t ;
	ComplexType & s = t  ; 

	size_t i = (size_t)( highPassHz/unitFreq + 0.5 ); // high pass filter
	const size_t k = (size_t)( lowPassHz/unitFreq + 0.5 ); // low pass filter
	const size_t iLen = spectrumCnt > 1 ? spectrumCnt/2  - k : spectrumCnt - k ;   

	const int axisWidth = this->GetXAxisWidth() ; 

	bool chartPaintOpt  = spectrumCnt > (2*axisWidth) ; 

	if( chartPaintOpt  ) { 
		// draw chat when the data size is large.
		// if x axisWidth is smaller than the spectrum count

		const int dataCntPerPix = (int)(spectrumCnt/(axisWidth+0.0)) ;

		vi->showChartPaintOpt( dataCntPerPix );

		DataPointCollection^ points = series->Points ;

		int idx = 0 ; 
		double tempMaxAmp ;  
		double tempMaxFreq ; 

		const int pntCnt = points->Count ;  

		int dataCnt = 0 ; 

		for( ; i < iLen ; i ++ ) {
			idx = 0 ;
			tempMaxAmp = 0 ;
			tempMaxFreq = 0 ;

			for( ; ( idx < dataCntPerPix ) && ( i < iLen ) ; idx ++ , i++ ) { 
				freq = unitFreq*i; 

				s = spectrum->at( i );
				amp = sqrt( s.imag()*s.imag() + s.real()*s.real() ) ;  

				if( amp >= maxAmp ) {
					maxAmp = amp ; 
					maxAmpFreq = freq ; 
				}

				if( amp > tempMaxAmp ) {
					tempMaxAmp = amp;
					tempMaxFreq = freq;
				}
			}

			if( dataCnt < pntCnt ) {
				// old chart data resource recycle.
				dp = points[ dataCnt ] ;
				dp->XValue = tempMaxFreq + freqOffSetX ;
				dp->YValues[ 0 ] = tempMaxAmp ; 
			} else {  
				// add new spectrum
				dp = gcnew DataPoint( tempMaxFreq + freqOffSetX, tempMaxAmp ) ;
				points->Add( dp ); 
			}

			dataCnt ++ ;
		}

		// set x-value as zero of empty data points
		// and y-value as zero of empty data points
		for( int i = dataCnt , iLen = pntCnt ; i < iLen ; i ++ ) {
			dp = points[ i ] ; 
			dp->XValue = tempMaxFreq + freqOffSetX + freqOffSetX ; 
			dp->YValues[0] = 0 ; 
		} 

		// end of drawing chart when the data size is large.
	} else {
		// draw chart when data size is small
		// if x axisWidth is larger than the spectrum count double
		DataPointCollection^ points = series->Points ;

		if( true ) {
			// init x values as negative to hide from the chart drawing
			// to use the old data again.
			for( int i = 0 , iLen = points->Count ; i < iLen ; i ++ ) {
				points[ i ]->XValue = -1 ; 
			}
		}

		const int pntCnt = points->Count ; 

		int dataCnt = 0 ; 
		for( ; i < iLen ; i ++ ) {
			freq = unitFreq*i; 

			s = spectrum->at( i );
			amp = sqrt( s.imag()*s.imag() + s.real()*s.real() ) ;  

			if( amp >= maxAmp ) {
				// find maximum amp
				maxAmp = amp ; 
				maxAmpFreq = freq ; 
			}

			if( dataCnt < pntCnt ) {
				// recycle the old chart data resource
				dp = points[ dataCnt ] ; 
				dp->XValue = freq + freqOffSetX;
				dp->YValues[0] = amp;
			} else { 
				// add new spectrum
				dp = gcnew DataPoint( freq + freqOffSetX, amp ) ;
				points->Add( dp ); 
			}

			dataCnt ++ ; 
		}
		// end of chart drawing when the data size is small.
	}

	if( true ) {
		// set y axis maximum value to prevent chart-drawing-flickering

		double yAxisMax = 0 ; 

		if( maxAmp < 0.3 ) {
			yAxisMax = 1;
		} else if( maxAmp < 0.9 ) {
			yAxisMax = 2;
		} else if( maxAmp < 8 ) {
			yAxisMax = 20 ; 
		} else if( maxAmp < 15 ) {
			yAxisMax = 30 ; 
		} else {  
			yAxisMax = maxAmp ;  
		} 

		if( yAxisMax > this->preYAxisMax ) {
			this->preYAxisMax = yAxisMax ; 

			this->SetYAxisMax( yAxisMax ); 
		} 
		
	}

	if( nullptr != peakSeries && maxAmp > 0 ) {
		// add max amplitude frequency

		DataPoint^ dpPeak = ( peakSeries == xPeakSrs ) ? dpXPeak : dpYPeak ; 
		dpPeak->XValue = maxAmpFreq + freqOffSetX ;
		dpPeak->YValues[ 0 ] = maxAmp ; 
		//DataPoint^ dpPeak = gcnew DataPoint( maxAmpFreq + freqOffSetX, maxAmp ) ;
		//peakSeries->Points->Add( dpPeak );
	}

	if( nullptr != filterSrs && ( maxAmp != this->tempMaxY ) && ( spectrumCnt > 30 ) ) {
		// add filter frequency visually  
		 
		this->tempMaxY = this->tempMaxY > maxAmp ? this->tempMaxY : maxAmp ; 

		if( highPassHz > 0 ) { 
			double x = highPassHz*(int)(highPassHz/unitFreq) ;
			size_t i = (size_t)( highPassHz/unitFreq + 0.5 ); // high pass filter
			x = x > unitFreq*i ? unitFreq*i : x ;
			x -= 2*freqOffSetX ; 
			x = x > 0 ? x : 0 ;
			
			this->dpFilterHighPass->XValue = x ; 
			this->dpFilterHighPass->YValues[0] = tempMaxY/2.0;
		}

		if( lowPassHz > 0 ) {  
			// chart x axis data range is half of the maximum spectrum frequency
			
			double x = maxFreq/2.0 - lowPassHz ;

			this->dpFilterLowPass->XValue = x ; 
			this->dpFilterLowPass->YValues[0] = tempMaxY/2.0; 
		} 
	}

	if( true ) { 
		// set x axis max value of frequency chart
		const double showMaxFreq = spectrumCnt > 1 ? maxFreq/2.0 : maxFreq ; 

		int iMaxFreq = (int) ( showMaxFreq + 0.5 ); 

		double offSet = 0.00 ; 

		this->SetXAxisMax( iMaxFreq + offSet ); 	
	}

	//series->Enabled = enabled ;  

	return maxAmpFreq ;
}

double VisionChartFreq::ProcessFft( Series^ series, Series^ peakSeries, ArrayList^ samples, VideoInfo * videoInfo, VisionOptionInterface^ vi, const double highPassHz, const double lowPassHz )
{	
	// FFT 
	Aquila::SpectrumType spectrum = this->GetFftSpectrum( samples ) ;   

	double maxAmpFreq = this->ProcessSpectrum( series, peakSeries, & spectrum, videoInfo, vi, highPassHz, lowPassHz );

	return maxAmpFreq;  
	// end of FFT
}

double VisionChartFreq::ProcessDft( Series^ series, Series^ peakSeries, ArrayList^ samples, VideoInfo * videoInfo, VisionOptionInterface^ vi, const double highPassHz, const double lowPassHz )
{
	// DFT (Discrete Fourier Transform) 
	Dft dft( samples->Count ); 

	Aquila::SpectrumType spectrum = dft.fft( samples ); 

	double maxAmpFreq = this->ProcessSpectrum( series, peakSeries, & spectrum, videoInfo, vi, highPassHz, lowPassHz );
	 
	return maxAmpFreq; 
	// end of DFT
}

void VisionChartFreq::ProcessMatchResult( MatchResult * matchResult, VideoInfo * videoInfo , VisionOptionInterface^ vi )
{
	double dx_mm = 0 ; 
	double dy_mm = 0 ;

	if( NULL != matchResult ) {  
		Disp * disp = matchResult->GetDisp() ;   

		dx_mm = ( disp->GetDxMeter()*1000 ) ;
		dy_mm = ( - disp->GetDyMeter()*1000 ) ;
	}

	const bool isFft = vi->isFft(); 
	const double highPassHz = vi->GetHighPassFilterHz() ;
	const double lowPassHz	= vi->GetLowPassFilterHz() ; 

	if( true ) {
		bool b = ( highPassHz > 0 || lowPassHz > 0 ) && ( xSrs->Enabled || ySrs->Enabled ) ;
		if( nullptr != this->filterSrs ) {
			filterSrs->Enabled = b ;
		}
	}

	this->tempMaxY = 0 ; 

	this->preYAxisMax = 0 ; 

	Series^ series ; 
	Series^ peakSeries ; 
	ArrayList^ samples ;
	double data ;   

	data = dx_mm ; 
	series = xSrs ;
	peakSeries = xPeakSrs ; 
	samples = xSamples ;  
	if( NULL != matchResult ) { 
		samples->Add( data ) ;
	}

	if( this->xSrs->Enabled ) { 
		if( isFft ) {
			this->xMaxAmpFreq = this->ProcessFft( series, peakSeries, samples, videoInfo, vi, highPassHz, lowPassHz ); 
		} else { 
			this->xMaxAmpFreq = this->ProcessDft( series, peakSeries, samples, videoInfo, vi, highPassHz, lowPassHz );
		}
	}  

	data = dy_mm ; 
	series = ySrs;
	peakSeries = yPeakSrs ; 
	samples = ySamples; 
	if( NULL != matchResult ) { 
		samples->Add( data );
	}

	if( this->ySrs->Enabled  ) { 
		if( isFft ) {
			this->yMaxAmpFreq = this->ProcessFft( series, peakSeries, samples, videoInfo, vi, highPassHz, lowPassHz ); 
		} else { 
			this->yMaxAmpFreq = this->ProcessDft( series, peakSeries, samples, videoInfo, vi, highPassHz, lowPassHz );
		}
	} 
}

Aquila::SpectrumType VisionChartFreq::GetXSpectrumAll()
{
	ArrayList^ samples = xSamples ;   
	Aquila::SpectrumType spectrum = this->GetFftSpectrum( samples ) ;

	return spectrum ; 
}

Aquila::SpectrumType VisionChartFreq::GetYSpectrumAll()
{
	ArrayList^ samples = ySamples ; 
	Aquila::SpectrumType spectrum = this->GetFftSpectrum( samples ) ;

	return spectrum ;
}




