#pragma once

#include "VisionChart.h" 
#include "ChartInfo.h"

using namespace System::Windows::Forms::DataVisualization::Charting;   
using namespace System::Collections;

ref class VisionChartDisp : public vision::VisionChart
{
public:
	VisionChartDisp(Chart^ chart);

private: 

public:

	virtual void InitChart() override ; 

	virtual void ProcessMatchResult( MatchResult * matchResult, VideoInfo * videoInfo, VisionOptionInterface^ vi ) override ;  

	virtual void ProcessMatchResultSmart( MatchResult * matchResult, VideoInfo * videoInfo, VisionOptionInterface^ vi ) ;  

	virtual void ProcessSeries(ChartInfo * chartInfo, Series^ series , ArrayList^ samples, VideoInfo * videoInfo, VisionOptionInterface^ vi ); 
};

