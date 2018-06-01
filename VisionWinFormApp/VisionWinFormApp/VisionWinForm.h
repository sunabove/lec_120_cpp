#pragma once

#include <Windows.h>
#include <stdio.h> 

#include <iostream>
#include <fstream>

#include "VisionInterface.h"
#include "VisionSystem.h"
#include "VisionOptionInterface.h"

#include "ExtResourcesForm.h"
#include "AboutWinForm.h"

#include "ComObject.h"
#include "CannyOption.h"
#include "VisionChartDisp.h"
#include "VisionChartFreq.h"

#define Excel   Microsoft::Office::Interop::Excel

namespace VisionWinFormApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Configuration;

	using namespace vision;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class VisionWinForm : public System::Windows::Forms::Form , VisionOptionInterface
	{
	public:
		VisionWinForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			initData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~VisionWinForm()
		{
			this->destroyData();

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  videoStatePanel;
	private: System::Windows::Forms::TrackBar^  tbVideoCurrFramePos;


	private: System::Windows::Forms::Label^  lblVideoTotTime;

	private: System::Windows::Forms::Label^  lblVideoCurrTime;
	protected: 





	private: System::Windows::Forms::GroupBox^  gbMathOption;
	private: System::Windows::Forms::GroupBox^  gbPreprocess;
	private: System::Windows::Forms::RadioButton^  rbNcc;


	private: System::Windows::Forms::RadioButton^  rbDic;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  cbCoeffNorm;
	private: System::Windows::Forms::ToolStripSplitButton^  tsVideoCamDev;

	private: System::Windows::Forms::ToolStripButton^  tsVideoRecord;
	private: System::Windows::Forms::ToolStripLabel^  tsVideoCamDevLbl;



	private: System::Windows::Forms::GroupBox^  gbOperOption;
	private: System::Windows::Forms::CheckBox^  cbAutoResize; 
	private: System::Windows::Forms::MenuStrip^  msPlay;

	protected: 

	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  miVideoOpen;


	private: System::Windows::Forms::ToolStripMenuItem^  miSaveConfig;

	private: System::Windows::Forms::ToolStripMenuItem^  miClose;








	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  videoGb;
	private: System::Windows::Forms::GroupBox^  chartGb; 

	private: System::Windows::Forms::GroupBox^  controlGb;
	private: System::Windows::Forms::PictureBox^  pbVideo;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::ToolStrip^  toolStrip;
	private: System::Windows::Forms::ToolStripButton^  tsVideoPlay;


	private: System::Windows::Forms::ToolStripButton^  tsVideoPause;
	private: System::Windows::Forms::ToolStripButton^  tsConfigFileSave;





	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^  tsVideoFileOpen;
	private: System::Windows::Forms::Timer^  videoTimer;



	private: System::Windows::Forms::ToolStripButton^  tsVideoStop;
	private: System::Windows::Forms::ToolStripButton^  tsVideoBackward;

	private: System::Windows::Forms::ToolStripButton^  tsVideoForward;





	private: System::Windows::Forms::RichTextBox^  tbMsg;
	private: System::Windows::Forms::Panel^  videoInfoPanel;
	private: System::Windows::Forms::PictureBox^  pbVideoGetFrameAni;
	private: System::Windows::Forms::PictureBox^  pbImgPrcsAni;
	private: System::Windows::Forms::Label^  lblState;
	private: System::Windows::Forms::Panel^  statePanel;

	private: System::Windows::Forms::PictureBox^  pbVideoRecording;
private: System::Windows::Forms::OpenFileDialog^  videoOpenFileDialog;

private: System::Windows::Forms::CheckBox^  cbShowPrcsInfoOnImage;
private: System::Windows::Forms::CheckBox^  cbPreBinary;
private: System::Windows::Forms::CheckBox^  cbPreHistEqualize;



private: System::Windows::Forms::NumericUpDown^  nUpDnPreBinaryThreshold;

private: System::Windows::Forms::CheckBox^  cbPreAdaptiveThreshold;





private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  lblGrayscale;

private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::CheckBox^  cbPreGaussianBlur;
private: System::Windows::Forms::NumericUpDown^  nUpDnPreGaussianBlurKSize;


private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::NumericUpDown^  nUpDnPreAdaptiveThresholdBSize;

private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label5;

private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::NumericUpDown^  nUpDnPreCannyApSize;

private: System::Windows::Forms::CheckBox^  cbPreCanny;
private: System::Windows::Forms::Label^  label4;

private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::NumericUpDown^  nUpDnPreCannyThresh2;
private: System::Windows::Forms::Label^  label15;

private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::CheckBox^  cbShowMatchMinValue;
private: System::Windows::Forms::Label^  lblShowMatchValue;

private: System::Windows::Forms::CheckBox^  cbShowMatchMaxValue;
private: System::Windows::Forms::Label^  lblFps;
private: System::Windows::Forms::NumericUpDown^  nUpDnFps;
private: System::Windows::Forms::GroupBox^  gbFeatureOption;
private: System::Windows::Forms::Label^  lblMeterUnit;
private: System::Windows::Forms::Label^  lblDistance;
private: System::Windows::Forms::NumericUpDown^  nUpDnFeatureDistance;
private: System::Windows::Forms::Label^  lblDispPixDx;












private: System::Windows::Forms::Label^  lblDispPixDy;





private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartDisp;






private: System::Windows::Forms::PictureBox^  pbTarget;
private: System::Windows::Forms::PictureBox^  pbChartDispVertAxisTitle;


private: System::Windows::Forms::CheckBox^  cbChartDispSeriesY;
private: System::Windows::Forms::CheckBox^  cbChartDispSeriesX;
private: System::Windows::Forms::Button^  btnChartDataSave;
private: System::Windows::Forms::DataVisualization::Charting::Chart^  chartFreq;
private: System::Windows::Forms::CheckBox^  cbChartFreqSeriesY;
private: System::Windows::Forms::CheckBox^  cbChartFreqSeriesX;
private: System::Windows::Forms::PictureBox^  pbChartFreqVertAxisTitle;

private: System::Windows::Forms::Label^  lblChartDispHorAxisTitle;
private: System::Windows::Forms::Label^  lblChartFreqHorAxisTitle;
private: System::Windows::Forms::CheckBox^  cbMatchTargetFix;
private: System::Windows::Forms::SaveFileDialog^  videoSaveFileDialog;
private: System::Windows::Forms::Label^  lblVideoFrameCntFrame;
private: System::Windows::Forms::Label^  lblVideoPlayTimeSec;






private: System::Windows::Forms::Panel^  pnlChartMenu;

private: System::Windows::Forms::Label^  lblChartSampleCntData;
private: System::Windows::Forms::Label^  lblImgProcsTimeSumSec;












private: System::Windows::Forms::RadioButton^  rbChartFft;
private: System::Windows::Forms::RadioButton^  rbChartDft;

private: System::Windows::Forms::Label^  lblVideoSizeX;
private: System::Windows::Forms::Label^  lblImgPsTimeSec;




private: System::Windows::Forms::Label^  lblDpi;
private: System::Windows::Forms::NumericUpDown^  nUpDnDPI;
private: System::Windows::Forms::Label^  lbChartPrcsTimeMs;


private: System::Windows::Forms::Label^  lblDispGeoDx;
private: System::Windows::Forms::Label^  lblDispGeoDy;









private: System::Windows::Forms::Label^  lblDispGeoDyMm;

private: System::Windows::Forms::Label^  lblDispGeoDxMm;





private: System::Windows::Forms::SaveFileDialog^  csvSaveFileDialog;
private: System::Windows::Forms::Label^  lblScaleFactorFormula;

private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::NumericUpDown^  nUpDnFocalLength;

private: System::Windows::Forms::Label^  lblFocalLength;



private: System::Windows::Forms::Label^  lblScaleFactor;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
private: System::Windows::Forms::SaveFileDialog^  configSaveFileDialog;

private: System::Windows::Forms::OpenFileDialog^  configOpenFileDialog;


private: System::Windows::Forms::ToolStripMenuItem^  miOpenConfig;
private: System::Windows::Forms::ToolStripMenuItem^  miVideoSave;
private: System::Windows::Forms::Label^  lblChartYMaxAmpFreqHz;



private: System::Windows::Forms::Label^  lblChartXMaxAmpFreqHz;




private: System::Windows::Forms::Label^  lblFx;
private: System::Windows::Forms::Label^  lblFy;
private: System::Windows::Forms::PictureBox^  pbChartPrcs;
private: System::Windows::Forms::CheckBox^  cbHighPassFilter;

private: System::Windows::Forms::Label^  lblLowFreqFilterHz;
private: System::Windows::Forms::NumericUpDown^  nUpDnHighPassFilterHz;



private: System::Windows::Forms::Label^  tbChartXMaxAmpFreq;
private: System::Windows::Forms::Label^  tbChartYMaxAmpFreq;
private: System::Windows::Forms::Label^  tbDispGeoX;
private: System::Windows::Forms::Label^  tbDispGeoY;
private: System::Windows::Forms::Label^  tbChartPrcsTime;
private: System::Windows::Forms::Label^  tbChartSampleDataCnt;
private: System::Windows::Forms::Label^  tbMatchPrcsTimeSum;
private: System::Windows::Forms::Label^  tbVideoWidth;
private: System::Windows::Forms::Label^  tbVideoHeight;
private: System::Windows::Forms::Label^  tbVideoFrameCnt;
private: System::Windows::Forms::Label^  tbVideoPlayTime;
private: System::Windows::Forms::Label^  tbImgPsTime;
private: System::Windows::Forms::Label^  tbDispPixY;
private: System::Windows::Forms::Label^  tbDispPixX;
private: System::Windows::Forms::NumericUpDown^  nUpDnLowPassFilterHz;

private: System::Windows::Forms::CheckBox^  cbLowPassFilter;
private: System::Windows::Forms::Label^  lblLowPassFilterHz;
private: System::Windows::Forms::Label^  tbScaleFactor;















































	private: System::ComponentModel::IContainer^  components;  

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VisionWinForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series13 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series14 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->msPlay = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miVideoOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miVideoSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miOpenConfig = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miSaveConfig = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miClose = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->videoGb = (gcnew System::Windows::Forms::GroupBox());
			this->videoInfoPanel = (gcnew System::Windows::Forms::Panel());
			this->tbVideoFrameCnt = (gcnew System::Windows::Forms::Label());
			this->tbDispPixY = (gcnew System::Windows::Forms::Label());
			this->tbDispPixX = (gcnew System::Windows::Forms::Label());
			this->tbImgPsTime = (gcnew System::Windows::Forms::Label());
			this->tbVideoPlayTime = (gcnew System::Windows::Forms::Label());
			this->tbVideoHeight = (gcnew System::Windows::Forms::Label());
			this->tbVideoWidth = (gcnew System::Windows::Forms::Label());
			this->lblImgPsTimeSec = (gcnew System::Windows::Forms::Label());
			this->lblVideoSizeX = (gcnew System::Windows::Forms::Label());
			this->lblFps = (gcnew System::Windows::Forms::Label());
			this->lblVideoFrameCntFrame = (gcnew System::Windows::Forms::Label());
			this->nUpDnFps = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblVideoPlayTimeSec = (gcnew System::Windows::Forms::Label());
			this->lblDispPixDx = (gcnew System::Windows::Forms::Label());
			this->lblDispPixDy = (gcnew System::Windows::Forms::Label());
			this->pbVideoRecording = (gcnew System::Windows::Forms::PictureBox());
			this->pbImgPrcsAni = (gcnew System::Windows::Forms::PictureBox());
			this->pbVideoGetFrameAni = (gcnew System::Windows::Forms::PictureBox());
			this->videoStatePanel = (gcnew System::Windows::Forms::Panel());
			this->tbVideoCurrFramePos = (gcnew System::Windows::Forms::TrackBar());
			this->lblVideoTotTime = (gcnew System::Windows::Forms::Label());
			this->lblVideoCurrTime = (gcnew System::Windows::Forms::Label());
			this->pbVideo = (gcnew System::Windows::Forms::PictureBox());
			this->chartGb = (gcnew System::Windows::Forms::GroupBox());
			this->pnlChartMenu = (gcnew System::Windows::Forms::Panel());
			this->pbChartPrcs = (gcnew System::Windows::Forms::PictureBox());
			this->tbChartPrcsTime = (gcnew System::Windows::Forms::Label());
			this->tbChartSampleDataCnt = (gcnew System::Windows::Forms::Label());
			this->tbMatchPrcsTimeSum = (gcnew System::Windows::Forms::Label());
			this->tbDispGeoY = (gcnew System::Windows::Forms::Label());
			this->tbDispGeoX = (gcnew System::Windows::Forms::Label());
			this->tbChartYMaxAmpFreq = (gcnew System::Windows::Forms::Label());
			this->tbChartXMaxAmpFreq = (gcnew System::Windows::Forms::Label());
			this->lblFy = (gcnew System::Windows::Forms::Label());
			this->lblFx = (gcnew System::Windows::Forms::Label());
			this->lblChartXMaxAmpFreqHz = (gcnew System::Windows::Forms::Label());
			this->lblChartYMaxAmpFreqHz = (gcnew System::Windows::Forms::Label());
			this->lblDispGeoDxMm = (gcnew System::Windows::Forms::Label());
			this->lblDispGeoDyMm = (gcnew System::Windows::Forms::Label());
			this->lblDispGeoDx = (gcnew System::Windows::Forms::Label());
			this->lbChartPrcsTimeMs = (gcnew System::Windows::Forms::Label());
			this->lblDispGeoDy = (gcnew System::Windows::Forms::Label());
			this->rbChartFft = (gcnew System::Windows::Forms::RadioButton());
			this->rbChartDft = (gcnew System::Windows::Forms::RadioButton());
			this->lblChartSampleCntData = (gcnew System::Windows::Forms::Label());
			this->lblImgProcsTimeSumSec = (gcnew System::Windows::Forms::Label());
			this->btnChartDataSave = (gcnew System::Windows::Forms::Button());
			this->lblChartFreqHorAxisTitle = (gcnew System::Windows::Forms::Label());
			this->lblChartDispHorAxisTitle = (gcnew System::Windows::Forms::Label());
			this->pbChartFreqVertAxisTitle = (gcnew System::Windows::Forms::PictureBox());
			this->cbChartFreqSeriesY = (gcnew System::Windows::Forms::CheckBox());
			this->cbChartFreqSeriesX = (gcnew System::Windows::Forms::CheckBox());
			this->chartFreq = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->cbChartDispSeriesY = (gcnew System::Windows::Forms::CheckBox());
			this->cbChartDispSeriesX = (gcnew System::Windows::Forms::CheckBox());
			this->pbChartDispVertAxisTitle = (gcnew System::Windows::Forms::PictureBox());
			this->chartDisp = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->controlGb = (gcnew System::Windows::Forms::GroupBox());
			this->gbFeatureOption = (gcnew System::Windows::Forms::GroupBox());
			this->tbScaleFactor = (gcnew System::Windows::Forms::Label());
			this->lblScaleFactorFormula = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->nUpDnFocalLength = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblFocalLength = (gcnew System::Windows::Forms::Label());
			this->lblScaleFactor = (gcnew System::Windows::Forms::Label());
			this->lblDpi = (gcnew System::Windows::Forms::Label());
			this->nUpDnDPI = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbMatchTargetFix = (gcnew System::Windows::Forms::CheckBox());
			this->pbTarget = (gcnew System::Windows::Forms::PictureBox());
			this->lblMeterUnit = (gcnew System::Windows::Forms::Label());
			this->lblDistance = (gcnew System::Windows::Forms::Label());
			this->nUpDnFeatureDistance = (gcnew System::Windows::Forms::NumericUpDown());
			this->gbMathOption = (gcnew System::Windows::Forms::GroupBox());
			this->cbCoeffNorm = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->rbNcc = (gcnew System::Windows::Forms::RadioButton());
			this->rbDic = (gcnew System::Windows::Forms::RadioButton());
			this->gbPreprocess = (gcnew System::Windows::Forms::GroupBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->nUpDnPreCannyThresh2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->nUpDnPreCannyApSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbPreCanny = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->nUpDnPreAdaptiveThresholdBSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->nUpDnPreGaussianBlurKSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->cbPreGaussianBlur = (gcnew System::Windows::Forms::CheckBox());
			this->lblGrayscale = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->cbPreAdaptiveThreshold = (gcnew System::Windows::Forms::CheckBox());
			this->nUpDnPreBinaryThreshold = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbPreHistEqualize = (gcnew System::Windows::Forms::CheckBox());
			this->cbPreBinary = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->tsVideoCamDevLbl = (gcnew System::Windows::Forms::ToolStripLabel());
			this->tsVideoCamDev = (gcnew System::Windows::Forms::ToolStripSplitButton());
			this->tsVideoPlay = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsVideoRecord = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsVideoPause = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsVideoStop = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsVideoBackward = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsVideoForward = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsVideoFileOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->tsConfigFileSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->gbOperOption = (gcnew System::Windows::Forms::GroupBox());
			this->lblLowPassFilterHz = (gcnew System::Windows::Forms::Label());
			this->nUpDnLowPassFilterHz = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbLowPassFilter = (gcnew System::Windows::Forms::CheckBox());
			this->lblLowFreqFilterHz = (gcnew System::Windows::Forms::Label());
			this->cbHighPassFilter = (gcnew System::Windows::Forms::CheckBox());
			this->nUpDnHighPassFilterHz = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblShowMatchValue = (gcnew System::Windows::Forms::Label());
			this->cbShowMatchMaxValue = (gcnew System::Windows::Forms::CheckBox());
			this->cbShowMatchMinValue = (gcnew System::Windows::Forms::CheckBox());
			this->cbShowPrcsInfoOnImage = (gcnew System::Windows::Forms::CheckBox());
			this->cbAutoResize = (gcnew System::Windows::Forms::CheckBox());
			this->tbMsg = (gcnew System::Windows::Forms::RichTextBox());
			this->videoTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblState = (gcnew System::Windows::Forms::Label());
			this->statePanel = (gcnew System::Windows::Forms::Panel());
			this->videoOpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->videoSaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->csvSaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->configSaveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->configOpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->msPlay->SuspendLayout();
			this->videoGb->SuspendLayout();
			this->videoInfoPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnFps))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVideoRecording))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbImgPrcsAni))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVideoGetFrameAni))->BeginInit();
			this->videoStatePanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbVideoCurrFramePos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVideo))->BeginInit();
			this->chartGb->SuspendLayout();
			this->pnlChartMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbChartPrcs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbChartFreqVertAxisTitle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartFreq))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbChartDispVertAxisTitle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDisp))->BeginInit();
			this->controlGb->SuspendLayout();
			this->gbFeatureOption->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnFocalLength))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnDPI))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTarget))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnFeatureDistance))->BeginInit();
			this->gbMathOption->SuspendLayout();
			this->gbPreprocess->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreCannyThresh2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreCannyApSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreAdaptiveThresholdBSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreGaussianBlurKSize))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreBinaryThreshold))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->toolStrip->SuspendLayout();
			this->gbOperOption->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnLowPassFilterHz))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnHighPassFilterHz))->BeginInit();
			this->statePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// msPlay
			// 
			this->msPlay->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->msPlay->Location = System::Drawing::Point(0, 0);
			this->msPlay->Name = L"msPlay";
			this->msPlay->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->msPlay->Size = System::Drawing::Size(1112, 24);
			this->msPlay->TabIndex = 1;
			this->msPlay->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->miVideoOpen,
					this->miVideoSave, this->miOpenConfig, this->miSaveConfig, this->miClose
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// miVideoOpen
			// 
			this->miVideoOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miVideoOpen.Image")));
			this->miVideoOpen->Name = L"miVideoOpen";
			this->miVideoOpen->Size = System::Drawing::Size(142, 22);
			this->miVideoOpen->Text = L"Open Video";
			this->miVideoOpen->Click += gcnew System::EventHandler(this, &VisionWinForm::miVideoOpen_Click);
			// 
			// miVideoSave
			// 
			this->miVideoSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miVideoSave.Image")));
			this->miVideoSave->Name = L"miVideoSave";
			this->miVideoSave->Size = System::Drawing::Size(142, 22);
			this->miVideoSave->Text = L"Save Video";
			this->miVideoSave->Click += gcnew System::EventHandler(this, &VisionWinForm::miVideoSave_Click);
			// 
			// miOpenConfig
			// 
			this->miOpenConfig->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miOpenConfig.Image")));
			this->miOpenConfig->Name = L"miOpenConfig";
			this->miOpenConfig->Size = System::Drawing::Size(142, 22);
			this->miOpenConfig->Text = L"Open Config";
			this->miOpenConfig->Click += gcnew System::EventHandler(this, &VisionWinForm::miOpenConfig_Click);
			// 
			// miSaveConfig
			// 
			this->miSaveConfig->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miSaveConfig.Image")));
			this->miSaveConfig->Name = L"miSaveConfig";
			this->miSaveConfig->Size = System::Drawing::Size(142, 22);
			this->miSaveConfig->Text = L"Save Config";
			this->miSaveConfig->Click += gcnew System::EventHandler(this, &VisionWinForm::ConfigFileSave_Click);
			// 
			// miClose
			// 
			this->miClose->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miClose.Image")));
			this->miClose->Name = L"miClose";
			this->miClose->Size = System::Drawing::Size(142, 22);
			this->miClose->Text = L"Close";
			this->miClose->Click += gcnew System::EventHandler(this, &VisionWinForm::closeToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutToolStripMenuItem.Image")));
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(288, 22);
			this->aboutToolStripMenuItem->Text = L"About Displacement Frequency Analyzer";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &VisionWinForm::aboutToolStripMenuItem_Click);
			// 
			// videoGb
			// 
			this->videoGb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
																					  | System::Windows::Forms::AnchorStyles::Left)
																					  | System::Windows::Forms::AnchorStyles::Right));
			this->videoGb->Controls->Add(this->videoInfoPanel);
			this->videoGb->Controls->Add(this->videoStatePanel);
			this->videoGb->Controls->Add(this->pbVideo);
			this->videoGb->Location = System::Drawing::Point(10, 29);
			this->videoGb->Name = L"videoGb";
			this->videoGb->Size = System::Drawing::Size(777, 607);
			this->videoGb->TabIndex = 2;
			this->videoGb->TabStop = false;
			this->videoGb->Text = L"Video";
			// 
			// videoInfoPanel
			// 
			this->videoInfoPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																							 | System::Windows::Forms::AnchorStyles::Right));
			this->videoInfoPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->videoInfoPanel->Controls->Add(this->tbVideoFrameCnt);
			this->videoInfoPanel->Controls->Add(this->tbDispPixY);
			this->videoInfoPanel->Controls->Add(this->tbDispPixX);
			this->videoInfoPanel->Controls->Add(this->tbImgPsTime);
			this->videoInfoPanel->Controls->Add(this->tbVideoPlayTime);
			this->videoInfoPanel->Controls->Add(this->tbVideoHeight);
			this->videoInfoPanel->Controls->Add(this->tbVideoWidth);
			this->videoInfoPanel->Controls->Add(this->lblImgPsTimeSec);
			this->videoInfoPanel->Controls->Add(this->lblVideoSizeX);
			this->videoInfoPanel->Controls->Add(this->lblFps);
			this->videoInfoPanel->Controls->Add(this->lblVideoFrameCntFrame);
			this->videoInfoPanel->Controls->Add(this->nUpDnFps);
			this->videoInfoPanel->Controls->Add(this->lblVideoPlayTimeSec);
			this->videoInfoPanel->Controls->Add(this->lblDispPixDx);
			this->videoInfoPanel->Controls->Add(this->lblDispPixDy);
			this->videoInfoPanel->Controls->Add(this->pbVideoRecording);
			this->videoInfoPanel->Controls->Add(this->pbImgPrcsAni);
			this->videoInfoPanel->Controls->Add(this->pbVideoGetFrameAni);
			this->videoInfoPanel->Location = System::Drawing::Point(5, 22);
			this->videoInfoPanel->Name = L"videoInfoPanel";
			this->videoInfoPanel->Size = System::Drawing::Size(767, 31);
			this->videoInfoPanel->TabIndex = 3;
			// 
			// tbVideoFrameCnt
			// 
			this->tbVideoFrameCnt->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->tbVideoFrameCnt->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbVideoFrameCnt->Location = System::Drawing::Point(254, 5);
			this->tbVideoFrameCnt->Name = L"tbVideoFrameCnt";
			this->tbVideoFrameCnt->Size = System::Drawing::Size(38, 20);
			this->tbVideoFrameCnt->TabIndex = 41;
			this->tbVideoFrameCnt->Text = L"000000";
			this->tbVideoFrameCnt->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbDispPixY
			// 
			this->tbDispPixY->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbDispPixY->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbDispPixY->Location = System::Drawing::Point(724, 5);
			this->tbDispPixY->Name = L"tbDispPixY";
			this->tbDispPixY->Size = System::Drawing::Size(34, 20);
			this->tbDispPixY->TabIndex = 44;
			this->tbDispPixY->Text = L"+0000";
			this->tbDispPixY->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbDispPixX
			// 
			this->tbDispPixX->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbDispPixX->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbDispPixX->Location = System::Drawing::Point(658, 5);
			this->tbDispPixX->Name = L"tbDispPixX";
			this->tbDispPixX->Size = System::Drawing::Size(34, 20);
			this->tbDispPixX->TabIndex = 41;
			this->tbDispPixX->Text = L"+0000";
			this->tbDispPixX->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbImgPsTime
			// 
			this->tbImgPsTime->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbImgPsTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbImgPsTime->Location = System::Drawing::Point(434, 5);
			this->tbImgPsTime->Name = L"tbImgPsTime";
			this->tbImgPsTime->Size = System::Drawing::Size(27, 20);
			this->tbImgPsTime->TabIndex = 41;
			this->tbImgPsTime->Text = L"100";
			this->tbImgPsTime->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbVideoPlayTime
			// 
			this->tbVideoPlayTime->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->tbVideoPlayTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbVideoPlayTime->Location = System::Drawing::Point(349, 5);
			this->tbVideoPlayTime->Name = L"tbVideoPlayTime";
			this->tbVideoPlayTime->Size = System::Drawing::Size(38, 20);
			this->tbVideoPlayTime->TabIndex = 43;
			this->tbVideoPlayTime->Text = L"000000";
			this->tbVideoPlayTime->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbVideoHeight
			// 
			this->tbVideoHeight->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->tbVideoHeight->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbVideoHeight->Location = System::Drawing::Point(129, 5);
			this->tbVideoHeight->Name = L"tbVideoHeight";
			this->tbVideoHeight->Size = System::Drawing::Size(31, 20);
			this->tbVideoHeight->TabIndex = 42;
			this->tbVideoHeight->Text = L"768";
			this->tbVideoHeight->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbVideoWidth
			// 
			this->tbVideoWidth->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->tbVideoWidth->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbVideoWidth->Location = System::Drawing::Point(83, 5);
			this->tbVideoWidth->Name = L"tbVideoWidth";
			this->tbVideoWidth->Size = System::Drawing::Size(31, 20);
			this->tbVideoWidth->TabIndex = 41;
			this->tbVideoWidth->Text = L"1024";
			this->tbVideoWidth->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblImgPsTimeSec
			// 
			this->lblImgPsTimeSec->AutoSize = true;
			this->lblImgPsTimeSec->Location = System::Drawing::Point(463, 9);
			this->lblImgPsTimeSec->Name = L"lblImgPsTimeSec";
			this->lblImgPsTimeSec->Size = System::Drawing::Size(26, 13);
			this->lblImgPsTimeSec->TabIndex = 17;
			this->lblImgPsTimeSec->Text = L"(ms)";
			// 
			// lblVideoSizeX
			// 
			this->lblVideoSizeX->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->lblVideoSizeX->AutoSize = true;
			this->lblVideoSizeX->Location = System::Drawing::Point(116, 9);
			this->lblVideoSizeX->Name = L"lblVideoSizeX";
			this->lblVideoSizeX->Size = System::Drawing::Size(12, 13);
			this->lblVideoSizeX->TabIndex = 15;
			this->lblVideoSizeX->Text = L"x";
			// 
			// lblFps
			// 
			this->lblFps->AutoSize = true;
			this->lblFps->Location = System::Drawing::Point(213, 9);
			this->lblFps->Name = L"lblFps";
			this->lblFps->Size = System::Drawing::Size(39, 13);
			this->lblFps->TabIndex = 2;
			this->lblFps->Text = L"(fps) = ";
			// 
			// lblVideoFrameCntFrame
			// 
			this->lblVideoFrameCntFrame->AutoSize = true;
			this->lblVideoFrameCntFrame->Location = System::Drawing::Point(295, 9);
			this->lblVideoFrameCntFrame->Name = L"lblVideoFrameCntFrame";
			this->lblVideoFrameCntFrame->Size = System::Drawing::Size(47, 13);
			this->lblVideoFrameCntFrame->TabIndex = 12;
			this->lblVideoFrameCntFrame->Text = L"(frame) /";
			// 
			// nUpDnFps
			// 
			this->nUpDnFps->Enabled = false;
			this->nUpDnFps->Location = System::Drawing::Point(173, 4);
			this->nUpDnFps->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 40, 0, 0, 0 });
			this->nUpDnFps->Name = L"nUpDnFps";
			this->nUpDnFps->Size = System::Drawing::Size(35, 20);
			this->nUpDnFps->TabIndex = 1;
			this->nUpDnFps->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnFps->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			// 
			// lblVideoPlayTimeSec
			// 
			this->lblVideoPlayTimeSec->AutoSize = true;
			this->lblVideoPlayTimeSec->Location = System::Drawing::Point(389, 9);
			this->lblVideoPlayTimeSec->Name = L"lblVideoPlayTimeSec";
			this->lblVideoPlayTimeSec->Size = System::Drawing::Size(30, 13);
			this->lblVideoPlayTimeSec->TabIndex = 10;
			this->lblVideoPlayTimeSec->Text = L"(sec)";
			// 
			// lblDispPixDx
			// 
			this->lblDispPixDx->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblDispPixDx->AutoSize = true;
			this->lblDispPixDx->Location = System::Drawing::Point(633, 9);
			this->lblDispPixDx->Name = L"lblDispPixDx";
			this->lblDispPixDx->Size = System::Drawing::Size(22, 13);
			this->lblDispPixDx->TabIndex = 8;
			this->lblDispPixDx->Text = L"Δx:";
			// 
			// lblDispPixDy
			// 
			this->lblDispPixDy->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblDispPixDy->AutoSize = true;
			this->lblDispPixDy->Location = System::Drawing::Point(699, 9);
			this->lblDispPixDy->Name = L"lblDispPixDy";
			this->lblDispPixDy->Size = System::Drawing::Size(22, 13);
			this->lblDispPixDy->TabIndex = 6;
			this->lblDispPixDy->Text = L"Δy:";
			// 
			// pbVideoRecording
			// 
			this->pbVideoRecording->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbVideoRecording.Image")));
			this->pbVideoRecording->Location = System::Drawing::Point(60, 6);
			this->pbVideoRecording->Name = L"pbVideoRecording";
			this->pbVideoRecording->Size = System::Drawing::Size(17, 17);
			this->pbVideoRecording->TabIndex = 4;
			this->pbVideoRecording->TabStop = false;
			// 
			// pbImgPrcsAni
			// 
			this->pbImgPrcsAni->BackColor = System::Drawing::SystemColors::Control;
			this->pbImgPrcsAni->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbImgPrcsAni.Image")));
			this->pbImgPrcsAni->Location = System::Drawing::Point(31, 2);
			this->pbImgPrcsAni->Name = L"pbImgPrcsAni";
			this->pbImgPrcsAni->Size = System::Drawing::Size(25, 25);
			this->pbImgPrcsAni->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbImgPrcsAni->TabIndex = 1;
			this->pbImgPrcsAni->TabStop = false;
			// 
			// pbVideoGetFrameAni
			// 
			this->pbVideoGetFrameAni->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbVideoGetFrameAni.Image")));
			this->pbVideoGetFrameAni->Location = System::Drawing::Point(3, 2);
			this->pbVideoGetFrameAni->Name = L"pbVideoGetFrameAni";
			this->pbVideoGetFrameAni->Size = System::Drawing::Size(25, 25);
			this->pbVideoGetFrameAni->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbVideoGetFrameAni->TabIndex = 0;
			this->pbVideoGetFrameAni->TabStop = false;
			// 
			// videoStatePanel
			// 
			this->videoStatePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
																							  | System::Windows::Forms::AnchorStyles::Right));
			this->videoStatePanel->Controls->Add(this->tbVideoCurrFramePos);
			this->videoStatePanel->Controls->Add(this->lblVideoTotTime);
			this->videoStatePanel->Controls->Add(this->lblVideoCurrTime);
			this->videoStatePanel->Location = System::Drawing::Point(5, 561);
			this->videoStatePanel->Name = L"videoStatePanel";
			this->videoStatePanel->Size = System::Drawing::Size(767, 39);
			this->videoStatePanel->TabIndex = 2;
			// 
			// tbVideoCurrFramePos
			// 
			this->tbVideoCurrFramePos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->tbVideoCurrFramePos->Enabled = false;
			this->tbVideoCurrFramePos->Location = System::Drawing::Point(46, 8);
			this->tbVideoCurrFramePos->Maximum = 100;
			this->tbVideoCurrFramePos->Name = L"tbVideoCurrFramePos";
			this->tbVideoCurrFramePos->Size = System::Drawing::Size(675, 45);
			this->tbVideoCurrFramePos->TabIndex = 2;
			this->tbVideoCurrFramePos->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::tbVideoCurrFramePos_MouseDown);
			this->tbVideoCurrFramePos->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::tbVideoCurrFramePos_MouseUp);
			// 
			// lblVideoTotTime
			// 
			this->lblVideoTotTime->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblVideoTotTime->AutoSize = true;
			this->lblVideoTotTime->Location = System::Drawing::Point(727, 12);
			this->lblVideoTotTime->Name = L"lblVideoTotTime";
			this->lblVideoTotTime->Size = System::Drawing::Size(49, 13);
			this->lblVideoTotTime->TabIndex = 1;
			this->lblVideoTotTime->Text = L"00:00:00";
			this->lblVideoTotTime->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VisionWinForm::lblPlayTotTime_Paint);
			// 
			// lblVideoCurrTime
			// 
			this->lblVideoCurrTime->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->lblVideoCurrTime->AutoSize = true;
			this->lblVideoCurrTime->Location = System::Drawing::Point(-1, 12);
			this->lblVideoCurrTime->Name = L"lblVideoCurrTime";
			this->lblVideoCurrTime->Size = System::Drawing::Size(49, 13);
			this->lblVideoCurrTime->TabIndex = 0;
			this->lblVideoCurrTime->Text = L"00:00:00";
			// 
			// pbVideo
			// 
			this->pbVideo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
																					  | System::Windows::Forms::AnchorStyles::Left)
																					  | System::Windows::Forms::AnchorStyles::Right));
			this->pbVideo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbVideo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbVideo.Image")));
			this->pbVideo->Location = System::Drawing::Point(5, 60);
			this->pbVideo->Name = L"pbVideo";
			this->pbVideo->Size = System::Drawing::Size(767, 495);
			this->pbVideo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbVideo->TabIndex = 1;
			this->pbVideo->TabStop = false;
			this->pbVideo->Click += gcnew System::EventHandler(this, &VisionWinForm::pbVideo_Click);
			this->pbVideo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VisionWinForm::pbVideo_Paint);
			this->pbVideo->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::pbVideo_MouseClick);
			this->pbVideo->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::pbVideo_MouseDoubleClick);
			this->pbVideo->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::pbVideo_MouseDown);
			this->pbVideo->MouseEnter += gcnew System::EventHandler(this, &VisionWinForm::pbVideo_MouseEnter);
			this->pbVideo->MouseLeave += gcnew System::EventHandler(this, &VisionWinForm::pbVideo_MouseLeave);
			this->pbVideo->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::pbVideo_MouseMove);
			this->pbVideo->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::pbVideo_MouseUp);
			// 
			// chartGb
			// 
			this->chartGb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
																					  | System::Windows::Forms::AnchorStyles::Right));
			this->chartGb->Controls->Add(this->pnlChartMenu);
			this->chartGb->Controls->Add(this->lblChartFreqHorAxisTitle);
			this->chartGb->Controls->Add(this->lblChartDispHorAxisTitle);
			this->chartGb->Controls->Add(this->pbChartFreqVertAxisTitle);
			this->chartGb->Controls->Add(this->cbChartFreqSeriesY);
			this->chartGb->Controls->Add(this->cbChartFreqSeriesX);
			this->chartGb->Controls->Add(this->chartFreq);
			this->chartGb->Controls->Add(this->cbChartDispSeriesY);
			this->chartGb->Controls->Add(this->cbChartDispSeriesX);
			this->chartGb->Controls->Add(this->pbChartDispVertAxisTitle);
			this->chartGb->Controls->Add(this->chartDisp);
			this->chartGb->Location = System::Drawing::Point(10, 642);
			this->chartGb->Name = L"chartGb";
			this->chartGb->Size = System::Drawing::Size(777, 380);
			this->chartGb->TabIndex = 3;
			this->chartGb->TabStop = false;
			this->chartGb->Text = L"Chart";
			// 
			// pnlChartMenu
			// 
			this->pnlChartMenu->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																						   | System::Windows::Forms::AnchorStyles::Right));
			this->pnlChartMenu->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pnlChartMenu->Controls->Add(this->pbChartPrcs);
			this->pnlChartMenu->Controls->Add(this->tbChartPrcsTime);
			this->pnlChartMenu->Controls->Add(this->tbChartSampleDataCnt);
			this->pnlChartMenu->Controls->Add(this->tbMatchPrcsTimeSum);
			this->pnlChartMenu->Controls->Add(this->tbDispGeoY);
			this->pnlChartMenu->Controls->Add(this->tbDispGeoX);
			this->pnlChartMenu->Controls->Add(this->tbChartYMaxAmpFreq);
			this->pnlChartMenu->Controls->Add(this->tbChartXMaxAmpFreq);
			this->pnlChartMenu->Controls->Add(this->lblFy);
			this->pnlChartMenu->Controls->Add(this->lblFx);
			this->pnlChartMenu->Controls->Add(this->lblChartXMaxAmpFreqHz);
			this->pnlChartMenu->Controls->Add(this->lblChartYMaxAmpFreqHz);
			this->pnlChartMenu->Controls->Add(this->lblDispGeoDxMm);
			this->pnlChartMenu->Controls->Add(this->lblDispGeoDyMm);
			this->pnlChartMenu->Controls->Add(this->lblDispGeoDx);
			this->pnlChartMenu->Controls->Add(this->lbChartPrcsTimeMs);
			this->pnlChartMenu->Controls->Add(this->lblDispGeoDy);
			this->pnlChartMenu->Controls->Add(this->rbChartFft);
			this->pnlChartMenu->Controls->Add(this->rbChartDft);
			this->pnlChartMenu->Controls->Add(this->lblChartSampleCntData);
			this->pnlChartMenu->Controls->Add(this->lblImgProcsTimeSumSec);
			this->pnlChartMenu->Controls->Add(this->btnChartDataSave);
			this->pnlChartMenu->Location = System::Drawing::Point(8, 22);
			this->pnlChartMenu->Name = L"pnlChartMenu";
			this->pnlChartMenu->Size = System::Drawing::Size(763, 29);
			this->pnlChartMenu->TabIndex = 13;
			// 
			// pbChartPrcs
			// 
			this->pbChartPrcs->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbChartPrcs.Image")));
			this->pbChartPrcs->Location = System::Drawing::Point(4, 3);
			this->pbChartPrcs->Name = L"pbChartPrcs";
			this->pbChartPrcs->Size = System::Drawing::Size(33, 23);
			this->pbChartPrcs->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbChartPrcs->TabIndex = 34;
			this->pbChartPrcs->TabStop = false;
			this->pbChartPrcs->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &VisionWinForm::pbChartPrcs_Paint);
			// 
			// tbChartPrcsTime
			// 
			this->tbChartPrcsTime->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbChartPrcsTime->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbChartPrcsTime->Location = System::Drawing::Point(295, 4);
			this->tbChartPrcsTime->Name = L"tbChartPrcsTime";
			this->tbChartPrcsTime->Size = System::Drawing::Size(27, 20);
			this->tbChartPrcsTime->TabIndex = 38;
			this->tbChartPrcsTime->Text = L"0000";
			this->tbChartPrcsTime->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbChartSampleDataCnt
			// 
			this->tbChartSampleDataCnt->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbChartSampleDataCnt->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbChartSampleDataCnt->Location = System::Drawing::Point(254, 4);
			this->tbChartSampleDataCnt->Name = L"tbChartSampleDataCnt";
			this->tbChartSampleDataCnt->Size = System::Drawing::Size(38, 20);
			this->tbChartSampleDataCnt->TabIndex = 39;
			this->tbChartSampleDataCnt->Text = L"000000";
			this->tbChartSampleDataCnt->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbMatchPrcsTimeSum
			// 
			this->tbMatchPrcsTimeSum->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbMatchPrcsTimeSum->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbMatchPrcsTimeSum->Location = System::Drawing::Point(148, 4);
			this->tbMatchPrcsTimeSum->Name = L"tbMatchPrcsTimeSum";
			this->tbMatchPrcsTimeSum->Size = System::Drawing::Size(38, 20);
			this->tbMatchPrcsTimeSum->TabIndex = 40;
			this->tbMatchPrcsTimeSum->Text = L"000000";
			this->tbMatchPrcsTimeSum->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbDispGeoY
			// 
			this->tbDispGeoY->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbDispGeoY->BackColor = System::Drawing::Color::Orange;
			this->tbDispGeoY->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbDispGeoY->Location = System::Drawing::Point(660, 4);
			this->tbDispGeoY->Name = L"tbDispGeoY";
			this->tbDispGeoY->Size = System::Drawing::Size(45, 20);
			this->tbDispGeoY->TabIndex = 37;
			this->tbDispGeoY->Text = L"+0000";
			this->tbDispGeoY->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbDispGeoX
			// 
			this->tbDispGeoX->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbDispGeoX->BackColor = System::Drawing::Color::RoyalBlue;
			this->tbDispGeoX->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbDispGeoX->Location = System::Drawing::Point(555, 4);
			this->tbDispGeoX->Name = L"tbDispGeoX";
			this->tbDispGeoX->Size = System::Drawing::Size(45, 20);
			this->tbDispGeoX->TabIndex = 36;
			this->tbDispGeoX->Text = L"+0000";
			this->tbDispGeoX->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbChartYMaxAmpFreq
			// 
			this->tbChartYMaxAmpFreq->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbChartYMaxAmpFreq->BackColor = System::Drawing::Color::Orange;
			this->tbChartYMaxAmpFreq->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbChartYMaxAmpFreq->Location = System::Drawing::Point(468, 4);
			this->tbChartYMaxAmpFreq->Name = L"tbChartYMaxAmpFreq";
			this->tbChartYMaxAmpFreq->Size = System::Drawing::Size(31, 20);
			this->tbChartYMaxAmpFreq->TabIndex = 35;
			this->tbChartYMaxAmpFreq->Text = L"000.0";
			this->tbChartYMaxAmpFreq->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// tbChartXMaxAmpFreq
			// 
			this->tbChartXMaxAmpFreq->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->tbChartXMaxAmpFreq->BackColor = System::Drawing::Color::RoyalBlue;
			this->tbChartXMaxAmpFreq->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbChartXMaxAmpFreq->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tbChartXMaxAmpFreq->Location = System::Drawing::Point(383, 3);
			this->tbChartXMaxAmpFreq->Name = L"tbChartXMaxAmpFreq";
			this->tbChartXMaxAmpFreq->Size = System::Drawing::Size(31, 20);
			this->tbChartXMaxAmpFreq->TabIndex = 4;
			this->tbChartXMaxAmpFreq->Text = L"000.0";
			this->tbChartXMaxAmpFreq->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblFy
			// 
			this->lblFy->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblFy->AutoSize = true;
			this->lblFy->Location = System::Drawing::Point(446, 7);
			this->lblFy->Name = L"lblFy";
			this->lblFy->Size = System::Drawing::Size(21, 13);
			this->lblFy->TabIndex = 33;
			this->lblFy->Text = L"ƒy:";
			// 
			// lblFx
			// 
			this->lblFx->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblFx->AutoSize = true;
			this->lblFx->Location = System::Drawing::Point(361, 7);
			this->lblFx->Name = L"lblFx";
			this->lblFx->Size = System::Drawing::Size(21, 13);
			this->lblFx->TabIndex = 32;
			this->lblFx->Text = L"ƒx:";
			// 
			// lblChartXMaxAmpFreqHz
			// 
			this->lblChartXMaxAmpFreqHz->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblChartXMaxAmpFreqHz->AutoSize = true;
			this->lblChartXMaxAmpFreqHz->Location = System::Drawing::Point(414, 9);
			this->lblChartXMaxAmpFreqHz->Name = L"lblChartXMaxAmpFreqHz";
			this->lblChartXMaxAmpFreqHz->Size = System::Drawing::Size(26, 13);
			this->lblChartXMaxAmpFreqHz->TabIndex = 31;
			this->lblChartXMaxAmpFreqHz->Text = L"(Hz)";
			// 
			// lblChartYMaxAmpFreqHz
			// 
			this->lblChartYMaxAmpFreqHz->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblChartYMaxAmpFreqHz->AutoSize = true;
			this->lblChartYMaxAmpFreqHz->Location = System::Drawing::Point(499, 10);
			this->lblChartYMaxAmpFreqHz->Name = L"lblChartYMaxAmpFreqHz";
			this->lblChartYMaxAmpFreqHz->Size = System::Drawing::Size(26, 13);
			this->lblChartYMaxAmpFreqHz->TabIndex = 29;
			this->lblChartYMaxAmpFreqHz->Text = L"(Hz)";
			// 
			// lblDispGeoDxMm
			// 
			this->lblDispGeoDxMm->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblDispGeoDxMm->AutoSize = true;
			this->lblDispGeoDxMm->Location = System::Drawing::Point(600, 9);
			this->lblDispGeoDxMm->Name = L"lblDispGeoDxMm";
			this->lblDispGeoDxMm->Size = System::Drawing::Size(29, 13);
			this->lblDispGeoDxMm->TabIndex = 27;
			this->lblDispGeoDxMm->Text = L"(mm)";
			// 
			// lblDispGeoDyMm
			// 
			this->lblDispGeoDyMm->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblDispGeoDyMm->AutoSize = true;
			this->lblDispGeoDyMm->Location = System::Drawing::Point(706, 9);
			this->lblDispGeoDyMm->Name = L"lblDispGeoDyMm";
			this->lblDispGeoDyMm->Size = System::Drawing::Size(29, 13);
			this->lblDispGeoDyMm->TabIndex = 26;
			this->lblDispGeoDyMm->Text = L"(mm)";
			// 
			// lblDispGeoDx
			// 
			this->lblDispGeoDx->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblDispGeoDx->AutoSize = true;
			this->lblDispGeoDx->Location = System::Drawing::Point(530, 8);
			this->lblDispGeoDx->Name = L"lblDispGeoDx";
			this->lblDispGeoDx->Size = System::Drawing::Size(24, 13);
			this->lblDispGeoDx->TabIndex = 25;
			this->lblDispGeoDx->Text = L"ΔX:";
			// 
			// lbChartPrcsTimeMs
			// 
			this->lbChartPrcsTimeMs->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lbChartPrcsTimeMs->AutoSize = true;
			this->lbChartPrcsTimeMs->Location = System::Drawing::Point(324, 10);
			this->lbChartPrcsTimeMs->Name = L"lbChartPrcsTimeMs";
			this->lbChartPrcsTimeMs->Size = System::Drawing::Size(26, 13);
			this->lbChartPrcsTimeMs->TabIndex = 22;
			this->lbChartPrcsTimeMs->Text = L"(ms)";
			// 
			// lblDispGeoDy
			// 
			this->lblDispGeoDy->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblDispGeoDy->AutoSize = true;
			this->lblDispGeoDy->Location = System::Drawing::Point(634, 8);
			this->lblDispGeoDy->Name = L"lblDispGeoDy";
			this->lblDispGeoDy->Size = System::Drawing::Size(24, 13);
			this->lblDispGeoDy->TabIndex = 23;
			this->lblDispGeoDy->Text = L"ΔY:";
			// 
			// rbChartFft
			// 
			this->rbChartFft->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->rbChartFft->AutoSize = true;
			this->rbChartFft->Checked = true;
			this->rbChartFft->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rbChartFft->Location = System::Drawing::Point(40, 5);
			this->rbChartFft->Name = L"rbChartFft";
			this->rbChartFft->Size = System::Drawing::Size(48, 17);
			this->rbChartFft->TabIndex = 20;
			this->rbChartFft->TabStop = true;
			this->rbChartFft->Text = L"FFT°";
			this->rbChartFft->UseVisualStyleBackColor = true;
			this->rbChartFft->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::rbChartFft_MouseClick);
			// 
			// rbChartDft
			// 
			this->rbChartDft->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->rbChartDft->AutoSize = true;
			this->rbChartDft->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rbChartDft->Location = System::Drawing::Point(87, 5);
			this->rbChartDft->Name = L"rbChartDft";
			this->rbChartDft->Size = System::Drawing::Size(53, 17);
			this->rbChartDft->TabIndex = 19;
			this->rbChartDft->Text = L"DFT °";
			this->rbChartDft->UseVisualStyleBackColor = true;
			this->rbChartDft->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &VisionWinForm::rbChartDft_MouseClick);
			// 
			// lblChartSampleCntData
			// 
			this->lblChartSampleCntData->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblChartSampleCntData->AutoSize = true;
			this->lblChartSampleCntData->Location = System::Drawing::Point(222, 8);
			this->lblChartSampleCntData->Name = L"lblChartSampleCntData";
			this->lblChartSampleCntData->Size = System::Drawing::Size(31, 13);
			this->lblChartSampleCntData->TabIndex = 18;
			this->lblChartSampleCntData->Text = L"data:";
			// 
			// lblImgProcsTimeSumSec
			// 
			this->lblImgProcsTimeSumSec->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblImgProcsTimeSumSec->AutoSize = true;
			this->lblImgProcsTimeSumSec->Location = System::Drawing::Point(189, 9);
			this->lblImgProcsTimeSumSec->Name = L"lblImgProcsTimeSumSec";
			this->lblImgProcsTimeSumSec->Size = System::Drawing::Size(30, 13);
			this->lblImgProcsTimeSumSec->TabIndex = 16;
			this->lblImgProcsTimeSumSec->Text = L"(sec)";
			// 
			// btnChartDataSave
			// 
			this->btnChartDataSave->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->btnChartDataSave->AutoSize = true;
			this->btnChartDataSave->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnChartDataSave->Enabled = false;
			this->btnChartDataSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnChartDataSave.Image")));
			this->btnChartDataSave->Location = System::Drawing::Point(737, 2);
			this->btnChartDataSave->Name = L"btnChartDataSave";
			this->btnChartDataSave->Size = System::Drawing::Size(22, 24);
			this->btnChartDataSave->TabIndex = 6;
			this->btnChartDataSave->UseVisualStyleBackColor = true;
			this->btnChartDataSave->Click += gcnew System::EventHandler(this, &VisionWinForm::btnChartDataSave_Click);
			// 
			// lblChartFreqHorAxisTitle
			// 
			this->lblChartFreqHorAxisTitle->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblChartFreqHorAxisTitle->AutoSize = true;
			this->lblChartFreqHorAxisTitle->BackColor = System::Drawing::Color::Transparent;
			this->lblChartFreqHorAxisTitle->Location = System::Drawing::Point(693, 350);
			this->lblChartFreqHorAxisTitle->Name = L"lblChartFreqHorAxisTitle";
			this->lblChartFreqHorAxisTitle->Size = System::Drawing::Size(20, 13);
			this->lblChartFreqHorAxisTitle->TabIndex = 12;
			this->lblChartFreqHorAxisTitle->Text = L"Hz";
			// 
			// lblChartDispHorAxisTitle
			// 
			this->lblChartDispHorAxisTitle->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblChartDispHorAxisTitle->AutoSize = true;
			this->lblChartDispHorAxisTitle->BackColor = System::Drawing::Color::Transparent;
			this->lblChartDispHorAxisTitle->Location = System::Drawing::Point(693, 189);
			this->lblChartDispHorAxisTitle->Name = L"lblChartDispHorAxisTitle";
			this->lblChartDispHorAxisTitle->Size = System::Drawing::Size(59, 13);
			this->lblChartDispHorAxisTitle->TabIndex = 11;
			this->lblChartDispHorAxisTitle->Text = L"Time (sec.)";
			// 
			// pbChartFreqVertAxisTitle
			// 
			this->pbChartFreqVertAxisTitle->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbChartFreqVertAxisTitle.Image")));
			this->pbChartFreqVertAxisTitle->Location = System::Drawing::Point(14, 231);
			this->pbChartFreqVertAxisTitle->Name = L"pbChartFreqVertAxisTitle";
			this->pbChartFreqVertAxisTitle->Size = System::Drawing::Size(16, 79);
			this->pbChartFreqVertAxisTitle->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbChartFreqVertAxisTitle->TabIndex = 10;
			this->pbChartFreqVertAxisTitle->TabStop = false;
			// 
			// cbChartFreqSeriesY
			// 
			this->cbChartFreqSeriesY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbChartFreqSeriesY->AutoSize = true;
			this->cbChartFreqSeriesY->Checked = true;
			this->cbChartFreqSeriesY->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbChartFreqSeriesY->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbChartFreqSeriesY->Enabled = false;
			this->cbChartFreqSeriesY->Location = System::Drawing::Point(718, 231);
			this->cbChartFreqSeriesY->Name = L"cbChartFreqSeriesY";
			this->cbChartFreqSeriesY->Size = System::Drawing::Size(31, 17);
			this->cbChartFreqSeriesY->TabIndex = 9;
			this->cbChartFreqSeriesY->Text = L"y";
			this->cbChartFreqSeriesY->UseVisualStyleBackColor = true;
			this->cbChartFreqSeriesY->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbChartFreqSeriesY_CheckedChanged);
			// 
			// cbChartFreqSeriesX
			// 
			this->cbChartFreqSeriesX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbChartFreqSeriesX->AutoSize = true;
			this->cbChartFreqSeriesX->Checked = true;
			this->cbChartFreqSeriesX->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbChartFreqSeriesX->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbChartFreqSeriesX->Enabled = false;
			this->cbChartFreqSeriesX->Location = System::Drawing::Point(691, 231);
			this->cbChartFreqSeriesX->Name = L"cbChartFreqSeriesX";
			this->cbChartFreqSeriesX->Size = System::Drawing::Size(31, 17);
			this->cbChartFreqSeriesX->TabIndex = 8;
			this->cbChartFreqSeriesX->Text = L"x";
			this->cbChartFreqSeriesX->UseVisualStyleBackColor = true;
			this->cbChartFreqSeriesX->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbChartFreqSeriesX_CheckedChanged);
			// 
			// chartFreq
			// 
			this->chartFreq->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																						| System::Windows::Forms::AnchorStyles::Right));
			chartArea3->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea3->AxisX->Interval = 10;
			chartArea3->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea3->AxisX->Minimum = 0;
			chartArea3->AxisX2->Interval = 5;
			chartArea3->AxisX2->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea3->AxisX2->Minimum = 0;
			chartArea3->AxisY->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea3->Name = L"chartFreqArea";
			chartArea3->Position->Auto = false;
			chartArea3->Position->Height = 100;
			chartArea3->Position->Width = 86;
			chartArea3->Position->X = 2;
			chartArea3->ShadowColor = System::Drawing::Color::Gainsboro;
			chartArea3->ShadowOffset = 4;
			this->chartFreq->ChartAreas->Add(chartArea3);
			legend3->Name = L"chartFreqLegend";
			legend3->Position->Auto = false;
			legend3->Position->Height = 50;
			legend3->Position->Width = 7.850929F;
			legend3->Position->X = 90;
			legend3->Position->Y = 34;
			this->chartFreq->Legends->Add(legend3);
			this->chartFreq->Location = System::Drawing::Point(8, 219);
			this->chartFreq->Name = L"chartFreq";
			series8->ChartArea = L"chartFreqArea";
			series8->Color = System::Drawing::Color::RoyalBlue;
			series8->Legend = L"chartFreqLegend";
			series8->Name = L"x";
			series9->ChartArea = L"chartFreqArea";
			series9->Color = System::Drawing::Color::Orange;
			series9->Legend = L"chartFreqLegend";
			series9->Name = L"y";
			series10->BorderColor = System::Drawing::Color::Red;
			series10->BorderWidth = 3;
			series10->ChartArea = L"chartFreqArea";
			series10->Color = System::Drawing::Color::Red;
			series10->Legend = L"chartFreqLegend";
			series10->Name = L"Max x";
			series10->ShadowColor = System::Drawing::Color::Gray;
			series10->ShadowOffset = 2;
			series11->BorderColor = System::Drawing::Color::OrangeRed;
			series11->BorderWidth = 3;
			series11->ChartArea = L"chartFreqArea";
			series11->Color = System::Drawing::Color::OrangeRed;
			series11->Legend = L"chartFreqLegend";
			series11->Name = L"Max y";
			series11->ShadowOffset = 2;
			series12->BorderColor = System::Drawing::Color::DarkRed;
			series12->BorderWidth = 10;
			series12->ChartArea = L"chartFreqArea";
			series12->Color = System::Drawing::Color::DarkRed;
			series12->Legend = L"chartFreqLegend";
			series12->Name = L"filter";
			series12->ShadowColor = System::Drawing::Color::Silver;
			series12->ShadowOffset = 1;
			this->chartFreq->Series->Add(series8);
			this->chartFreq->Series->Add(series9);
			this->chartFreq->Series->Add(series10);
			this->chartFreq->Series->Add(series11);
			this->chartFreq->Series->Add(series12);
			this->chartFreq->Size = System::Drawing::Size(763, 155);
			this->chartFreq->TabIndex = 7;
			this->chartFreq->Text = L"chart1";
			title3->Alignment = System::Drawing::ContentAlignment::MiddleRight;
			title3->Name = L"chartFreqTitle";
			title3->Position->Auto = false;
			title3->Position->Height = 9.785583F;
			title3->Position->Width = 94;
			title3->Position->X = 2;
			title3->Position->Y = 23;
			title3->Text = L"Frequency";
			this->chartFreq->Titles->Add(title3);
			// 
			// cbChartDispSeriesY
			// 
			this->cbChartDispSeriesY->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbChartDispSeriesY->AutoSize = true;
			this->cbChartDispSeriesY->Checked = true;
			this->cbChartDispSeriesY->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbChartDispSeriesY->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbChartDispSeriesY->Enabled = false;
			this->cbChartDispSeriesY->Location = System::Drawing::Point(718, 69);
			this->cbChartDispSeriesY->Name = L"cbChartDispSeriesY";
			this->cbChartDispSeriesY->Size = System::Drawing::Size(31, 17);
			this->cbChartDispSeriesY->TabIndex = 5;
			this->cbChartDispSeriesY->Text = L"y";
			this->cbChartDispSeriesY->UseVisualStyleBackColor = true;
			this->cbChartDispSeriesY->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbChartDispSeriesY_CheckedChanged);
			// 
			// cbChartDispSeriesX
			// 
			this->cbChartDispSeriesX->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->cbChartDispSeriesX->AutoSize = true;
			this->cbChartDispSeriesX->Checked = true;
			this->cbChartDispSeriesX->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbChartDispSeriesX->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbChartDispSeriesX->Enabled = false;
			this->cbChartDispSeriesX->Location = System::Drawing::Point(691, 69);
			this->cbChartDispSeriesX->Name = L"cbChartDispSeriesX";
			this->cbChartDispSeriesX->Size = System::Drawing::Size(31, 17);
			this->cbChartDispSeriesX->TabIndex = 4;
			this->cbChartDispSeriesX->Text = L"x";
			this->cbChartDispSeriesX->UseVisualStyleBackColor = true;
			this->cbChartDispSeriesX->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbChartDispSeriesX_CheckedChanged);
			// 
			// pbChartDispVertAxisTitle
			// 
			this->pbChartDispVertAxisTitle->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbChartDispVertAxisTitle.Image")));
			this->pbChartDispVertAxisTitle->Location = System::Drawing::Point(14, 69);
			this->pbChartDispVertAxisTitle->Name = L"pbChartDispVertAxisTitle";
			this->pbChartDispVertAxisTitle->Size = System::Drawing::Size(17, 89);
			this->pbChartDispVertAxisTitle->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbChartDispVertAxisTitle->TabIndex = 3;
			this->pbChartDispVertAxisTitle->TabStop = false;
			// 
			// chartDisp
			// 
			this->chartDisp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																						| System::Windows::Forms::AnchorStyles::Right));
			chartArea4->AxisX->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea4->AxisX->Interval = 3;
			chartArea4->AxisX->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea4->AxisX->Minimum = 0;
			chartArea4->AxisX2->Interval = 5;
			chartArea4->AxisX2->LineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dot;
			chartArea4->AxisX2->Minimum = 0;
			chartArea4->AxisY->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea4->Name = L"chartDispArea";
			chartArea4->Position->Auto = false;
			chartArea4->Position->Height = 100;
			chartArea4->Position->Width = 86;
			chartArea4->Position->X = 2;
			chartArea4->ShadowColor = System::Drawing::Color::Gainsboro;
			chartArea4->ShadowOffset = 4;
			this->chartDisp->ChartAreas->Add(chartArea4);
			legend4->Name = L"chartDispLegend";
			legend4->Position->Auto = false;
			legend4->Position->Height = 27.73723F;
			legend4->Position->Width = 7.850929F;
			legend4->Position->X = 90;
			legend4->Position->Y = 40;
			this->chartDisp->Legends->Add(legend4);
			this->chartDisp->Location = System::Drawing::Point(8, 57);
			this->chartDisp->Name = L"chartDisp";
			series13->BorderColor = System::Drawing::Color::White;
			series13->BorderWidth = 0;
			series13->ChartArea = L"chartDispArea";
			series13->Color = System::Drawing::Color::RoyalBlue;
			series13->Legend = L"chartDispLegend";
			series13->Name = L"x";
			series14->BorderColor = System::Drawing::Color::White;
			series14->BorderWidth = 0;
			series14->ChartArea = L"chartDispArea";
			series14->Color = System::Drawing::Color::Orange;
			series14->Legend = L"chartDispLegend";
			series14->Name = L"y";
			this->chartDisp->Series->Add(series13);
			this->chartDisp->Series->Add(series14);
			this->chartDisp->Size = System::Drawing::Size(763, 155);
			this->chartDisp->TabIndex = 2;
			this->chartDisp->Text = L"chartDisp";
			title4->Alignment = System::Drawing::ContentAlignment::MiddleRight;
			title4->Name = L"chartDispTitle";
			title4->Position->Auto = false;
			title4->Position->Height = 9.785583F;
			title4->Position->Width = 94;
			title4->Position->X = 4;
			title4->Position->Y = 23;
			title4->Text = L"Displacement";
			this->chartDisp->Titles->Add(title4);
			// 
			// controlGb
			// 
			this->controlGb->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
																						| System::Windows::Forms::AnchorStyles::Right));
			this->controlGb->Controls->Add(this->gbFeatureOption);
			this->controlGb->Controls->Add(this->gbMathOption);
			this->controlGb->Controls->Add(this->gbPreprocess);
			this->controlGb->Controls->Add(this->groupBox1);
			this->controlGb->Controls->Add(this->gbOperOption);
			this->controlGb->Controls->Add(this->tbMsg);
			this->controlGb->Location = System::Drawing::Point(793, 29);
			this->controlGb->Name = L"controlGb";
			this->controlGb->Size = System::Drawing::Size(309, 993);
			this->controlGb->TabIndex = 4;
			this->controlGb->TabStop = false;
			// 
			// gbFeatureOption
			// 
			this->gbFeatureOption->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																							  | System::Windows::Forms::AnchorStyles::Right));
			this->gbFeatureOption->Controls->Add(this->tbScaleFactor);
			this->gbFeatureOption->Controls->Add(this->lblScaleFactorFormula);
			this->gbFeatureOption->Controls->Add(this->label27);
			this->gbFeatureOption->Controls->Add(this->nUpDnFocalLength);
			this->gbFeatureOption->Controls->Add(this->lblFocalLength);
			this->gbFeatureOption->Controls->Add(this->lblScaleFactor);
			this->gbFeatureOption->Controls->Add(this->lblDpi);
			this->gbFeatureOption->Controls->Add(this->nUpDnDPI);
			this->gbFeatureOption->Controls->Add(this->cbMatchTargetFix);
			this->gbFeatureOption->Controls->Add(this->pbTarget);
			this->gbFeatureOption->Controls->Add(this->lblMeterUnit);
			this->gbFeatureOption->Controls->Add(this->lblDistance);
			this->gbFeatureOption->Controls->Add(this->nUpDnFeatureDistance);
			this->gbFeatureOption->Location = System::Drawing::Point(5, 355);
			this->gbFeatureOption->Name = L"gbFeatureOption";
			this->gbFeatureOption->Size = System::Drawing::Size(298, 358);
			this->gbFeatureOption->TabIndex = 5;
			this->gbFeatureOption->TabStop = false;
			this->gbFeatureOption->Text = L"Feature Option";
			// 
			// tbScaleFactor
			// 
			this->tbScaleFactor->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->tbScaleFactor->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->tbScaleFactor->Location = System::Drawing::Point(110, 17);
			this->tbScaleFactor->Name = L"tbScaleFactor";
			this->tbScaleFactor->Size = System::Drawing::Size(81, 22);
			this->tbScaleFactor->TabIndex = 45;
			this->tbScaleFactor->Text = L"000000";
			this->tbScaleFactor->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblScaleFactorFormula
			// 
			this->lblScaleFactorFormula->AutoSize = true;
			this->lblScaleFactorFormula->Location = System::Drawing::Point(195, 22);
			this->lblScaleFactorFormula->Name = L"lblScaleFactorFormula";
			this->lblScaleFactorFormula->Size = System::Drawing::Size(94, 13);
			this->lblScaleFactorFormula->TabIndex = 22;
			this->lblScaleFactorFormula->Text = L"= D(m)/25.4/f(mm)";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(170, 80);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(29, 13);
			this->label27->TabIndex = 21;
			this->label27->Text = L"(mm)";
			// 
			// nUpDnFocalLength
			// 
			this->nUpDnFocalLength->DecimalPlaces = 1;
			this->nUpDnFocalLength->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nUpDnFocalLength->Location = System::Drawing::Point(110, 75);
			this->nUpDnFocalLength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->nUpDnFocalLength->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nUpDnFocalLength->Name = L"nUpDnFocalLength";
			this->nUpDnFocalLength->Size = System::Drawing::Size(55, 20);
			this->nUpDnFocalLength->TabIndex = 20;
			this->nUpDnFocalLength->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnFocalLength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 6, 0, 0, 0 });
			this->nUpDnFocalLength->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnFocalLength_ValueChanged);
			// 
			// lblFocalLength
			// 
			this->lblFocalLength->AutoSize = true;
			this->lblFocalLength->Location = System::Drawing::Point(21, 80);
			this->lblFocalLength->Name = L"lblFocalLength";
			this->lblFocalLength->Size = System::Drawing::Size(83, 13);
			this->lblFocalLength->TabIndex = 19;
			this->lblFocalLength->Text = L"ㅇ Focal Lenth :";
			// 
			// lblScaleFactor
			// 
			this->lblScaleFactor->AutoSize = true;
			this->lblScaleFactor->Location = System::Drawing::Point(9, 23);
			this->lblScaleFactor->Name = L"lblScaleFactor";
			this->lblScaleFactor->Size = System::Drawing::Size(91, 13);
			this->lblScaleFactor->TabIndex = 8;
			this->lblScaleFactor->Text = L"■  Scale Factor  :";
			// 
			// lblDpi
			// 
			this->lblDpi->AutoSize = true;
			this->lblDpi->Location = System::Drawing::Point(201, 51);
			this->lblDpi->Name = L"lblDpi";
			this->lblDpi->Size = System::Drawing::Size(45, 13);
			this->lblDpi->TabIndex = 6;
			this->lblDpi->Text = L"ㅇ DPI :";
			// 
			// nUpDnDPI
			// 
			this->nUpDnDPI->Enabled = false;
			this->nUpDnDPI->Location = System::Drawing::Point(251, 47);
			this->nUpDnDPI->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->nUpDnDPI->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 40, 0, 0, 0 });
			this->nUpDnDPI->Name = L"nUpDnDPI";
			this->nUpDnDPI->Size = System::Drawing::Size(37, 20);
			this->nUpDnDPI->TabIndex = 5;
			this->nUpDnDPI->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnDPI->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 96, 0, 0, 0 });
			this->nUpDnDPI->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnDPI_ValueChanged);
			// 
			// cbMatchTargetFix
			// 
			this->cbMatchTargetFix->BackColor = System::Drawing::Color::Transparent;
			this->cbMatchTargetFix->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbMatchTargetFix->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cbMatchTargetFix.Image")));
			this->cbMatchTargetFix->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->cbMatchTargetFix->Location = System::Drawing::Point(254, 109);
			this->cbMatchTargetFix->Name = L"cbMatchTargetFix";
			this->cbMatchTargetFix->Size = System::Drawing::Size(38, 29);
			this->cbMatchTargetFix->TabIndex = 4;
			this->cbMatchTargetFix->UseVisualStyleBackColor = false;
			this->cbMatchTargetFix->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbMatchTargetFix_CheckedChanged);
			// 
			// pbTarget
			// 
			this->pbTarget->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
																					   | System::Windows::Forms::AnchorStyles::Left)
																					   | System::Windows::Forms::AnchorStyles::Right));
			this->pbTarget->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbTarget->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTarget.Image")));
			this->pbTarget->Location = System::Drawing::Point(5, 107);
			this->pbTarget->Name = L"pbTarget";
			this->pbTarget->Size = System::Drawing::Size(289, 244);
			this->pbTarget->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbTarget->TabIndex = 3;
			this->pbTarget->TabStop = false;
			// 
			// lblMeterUnit
			// 
			this->lblMeterUnit->AutoSize = true;
			this->lblMeterUnit->Location = System::Drawing::Point(170, 51);
			this->lblMeterUnit->Name = L"lblMeterUnit";
			this->lblMeterUnit->Size = System::Drawing::Size(27, 13);
			this->lblMeterUnit->TabIndex = 2;
			this->lblMeterUnit->Text = L"(cm)";
			// 
			// lblDistance
			// 
			this->lblDistance->AutoSize = true;
			this->lblDistance->Location = System::Drawing::Point(21, 51);
			this->lblDistance->Name = L"lblDistance";
			this->lblDistance->Size = System::Drawing::Size(81, 13);
			this->lblDistance->TabIndex = 1;
			this->lblDistance->Text = L"ㅇ Distance     :";
			// 
			// nUpDnFeatureDistance
			// 
			this->nUpDnFeatureDistance->DecimalPlaces = 1;
			this->nUpDnFeatureDistance->Location = System::Drawing::Point(110, 46);
			this->nUpDnFeatureDistance->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->nUpDnFeatureDistance->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nUpDnFeatureDistance->Name = L"nUpDnFeatureDistance";
			this->nUpDnFeatureDistance->Size = System::Drawing::Size(54, 20);
			this->nUpDnFeatureDistance->TabIndex = 0;
			this->nUpDnFeatureDistance->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnFeatureDistance->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 40, 0, 0, 0 });
			this->nUpDnFeatureDistance->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnFeatureDistance_ValueChanged);
			// 
			// gbMathOption
			// 
			this->gbMathOption->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																						   | System::Windows::Forms::AnchorStyles::Right));
			this->gbMathOption->Controls->Add(this->cbCoeffNorm);
			this->gbMathOption->Controls->Add(this->label1);
			this->gbMathOption->Controls->Add(this->rbNcc);
			this->gbMathOption->Controls->Add(this->rbDic);
			this->gbMathOption->Location = System::Drawing::Point(5, 281);
			this->gbMathOption->Name = L"gbMathOption";
			this->gbMathOption->Size = System::Drawing::Size(298, 68);
			this->gbMathOption->TabIndex = 3;
			this->gbMathOption->TabStop = false;
			this->gbMathOption->Text = L"Match Option";
			// 
			// cbCoeffNorm
			// 
			this->cbCoeffNorm->AutoSize = true;
			this->cbCoeffNorm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbCoeffNorm->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->cbCoeffNorm->Location = System::Drawing::Point(11, 40);
			this->cbCoeffNorm->Name = L"cbCoeffNorm";
			this->cbCoeffNorm->Size = System::Drawing::Size(142, 17);
			this->cbCoeffNorm->TabIndex = 4;
			this->cbCoeffNorm->Text = L"Coefficient Normalization";
			this->cbCoeffNorm->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"■  Algorithm :";
			// 
			// rbNcc
			// 
			this->rbNcc->AutoSize = true;
			this->rbNcc->Checked = true;
			this->rbNcc->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rbNcc->Location = System::Drawing::Point(183, 16);
			this->rbNcc->Name = L"rbNcc";
			this->rbNcc->Size = System::Drawing::Size(47, 17);
			this->rbNcc->TabIndex = 1;
			this->rbNcc->TabStop = true;
			this->rbNcc->Text = L"NCC";
			this->rbNcc->UseVisualStyleBackColor = true;
			// 
			// rbDic
			// 
			this->rbDic->AutoSize = true;
			this->rbDic->Cursor = System::Windows::Forms::Cursors::Hand;
			this->rbDic->Location = System::Drawing::Point(116, 16);
			this->rbDic->Name = L"rbDic";
			this->rbDic->Size = System::Drawing::Size(43, 17);
			this->rbDic->TabIndex = 0;
			this->rbDic->Text = L"DIC";
			this->rbDic->UseVisualStyleBackColor = true;
			// 
			// gbPreprocess
			// 
			this->gbPreprocess->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																						   | System::Windows::Forms::AnchorStyles::Right));
			this->gbPreprocess->Controls->Add(this->label12);
			this->gbPreprocess->Controls->Add(this->label4);
			this->gbPreprocess->Controls->Add(this->label15);
			this->gbPreprocess->Controls->Add(this->label18);
			this->gbPreprocess->Controls->Add(this->label17);
			this->gbPreprocess->Controls->Add(this->label16);
			this->gbPreprocess->Controls->Add(this->label14);
			this->gbPreprocess->Controls->Add(this->label13);
			this->gbPreprocess->Controls->Add(this->nUpDnPreCannyThresh2);
			this->gbPreprocess->Controls->Add(this->nUpDnPreCannyApSize);
			this->gbPreprocess->Controls->Add(this->cbPreCanny);
			this->gbPreprocess->Controls->Add(this->label3);
			this->gbPreprocess->Controls->Add(this->label5);
			this->gbPreprocess->Controls->Add(this->label6);
			this->gbPreprocess->Controls->Add(this->nUpDnPreAdaptiveThresholdBSize);
			this->gbPreprocess->Controls->Add(this->nUpDnPreGaussianBlurKSize);
			this->gbPreprocess->Controls->Add(this->label11);
			this->gbPreprocess->Controls->Add(this->label10);
			this->gbPreprocess->Controls->Add(this->label9);
			this->gbPreprocess->Controls->Add(this->cbPreGaussianBlur);
			this->gbPreprocess->Controls->Add(this->lblGrayscale);
			this->gbPreprocess->Controls->Add(this->label8);
			this->gbPreprocess->Controls->Add(this->label7);
			this->gbPreprocess->Controls->Add(this->cbPreAdaptiveThreshold);
			this->gbPreprocess->Controls->Add(this->nUpDnPreBinaryThreshold);
			this->gbPreprocess->Controls->Add(this->cbPreHistEqualize);
			this->gbPreprocess->Controls->Add(this->cbPreBinary);
			this->gbPreprocess->Location = System::Drawing::Point(5, 81);
			this->gbPreprocess->Name = L"gbPreprocess";
			this->gbPreprocess->Size = System::Drawing::Size(298, 193);
			this->gbPreprocess->TabIndex = 2;
			this->gbPreprocess->TabStop = false;
			this->gbPreprocess->Text = L"Preprocess Option";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(5, 99);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(13, 13);
			this->label12->TabIndex = 28;
			this->label12->Text = L"╔";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 98);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 34;
			this->label4->Text = L"╠";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Location = System::Drawing::Point(5, 164);
			this->label15->Margin = System::Windows::Forms::Padding(0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(19, 13);
			this->label15->TabIndex = 40;
			this->label15->Text = L"╚═";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(5, 151);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(13, 13);
			this->label18->TabIndex = 37;
			this->label18->Text = L"║";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(5, 138);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(13, 13);
			this->label17->TabIndex = 36;
			this->label17->Text = L"║";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(5, 125);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(13, 13);
			this->label16->TabIndex = 35;
			this->label16->Text = L"║";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(5, 112);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(13, 13);
			this->label14->TabIndex = 32;
			this->label14->Text = L"║";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(185, 161);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(65, 13);
			this->label13->TabIndex = 31;
			this->label13->Text = L"threshold 2 :";
			// 
			// nUpDnPreCannyThresh2
			// 
			this->nUpDnPreCannyThresh2->AutoSize = true;
			this->nUpDnPreCannyThresh2->Enabled = false;
			this->nUpDnPreCannyThresh2->Location = System::Drawing::Point(255, 156);
			this->nUpDnPreCannyThresh2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 125, 0, 0, 0 });
			this->nUpDnPreCannyThresh2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nUpDnPreCannyThresh2->Name = L"nUpDnPreCannyThresh2";
			this->nUpDnPreCannyThresh2->Size = System::Drawing::Size(41, 20);
			this->nUpDnPreCannyThresh2->TabIndex = 30;
			this->nUpDnPreCannyThresh2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnPreCannyThresh2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			this->nUpDnPreCannyThresh2->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnPreCannyThresh2_ValueChanged);
			// 
			// nUpDnPreCannyApSize
			// 
			this->nUpDnPreCannyApSize->AutoSize = true;
			this->nUpDnPreCannyApSize->Enabled = false;
			this->nUpDnPreCannyApSize->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->nUpDnPreCannyApSize->Location = System::Drawing::Point(142, 156);
			this->nUpDnPreCannyApSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->nUpDnPreCannyApSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->nUpDnPreCannyApSize->Name = L"nUpDnPreCannyApSize";
			this->nUpDnPreCannyApSize->Size = System::Drawing::Size(38, 20);
			this->nUpDnPreCannyApSize->TabIndex = 27;
			this->nUpDnPreCannyApSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnPreCannyApSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->nUpDnPreCannyApSize->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnPreCannyApSize_ValueChanged);
			// 
			// cbPreCanny
			// 
			this->cbPreCanny->AutoSize = true;
			this->cbPreCanny->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbPreCanny->Location = System::Drawing::Point(34, 160);
			this->cbPreCanny->Name = L"cbPreCanny";
			this->cbPreCanny->Size = System::Drawing::Size(104, 17);
			this->cbPreCanny->TabIndex = 26;
			this->cbPreCanny->Text = L"Canny  ap. size :";
			this->cbPreCanny->UseVisualStyleBackColor = true;
			this->cbPreCanny->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbPreCanny_CheckedChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"╚";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 111);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"║";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 85);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 13);
			this->label6->TabIndex = 21;
			this->label6->Text = L"║";
			// 
			// nUpDnPreAdaptiveThresholdBSize
			// 
			this->nUpDnPreAdaptiveThresholdBSize->AutoSize = true;
			this->nUpDnPreAdaptiveThresholdBSize->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->nUpDnPreAdaptiveThresholdBSize->Location = System::Drawing::Point(206, 92);
			this->nUpDnPreAdaptiveThresholdBSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 41, 0, 0, 0 });
			this->nUpDnPreAdaptiveThresholdBSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->nUpDnPreAdaptiveThresholdBSize->Name = L"nUpDnPreAdaptiveThresholdBSize";
			this->nUpDnPreAdaptiveThresholdBSize->Size = System::Drawing::Size(38, 20);
			this->nUpDnPreAdaptiveThresholdBSize->TabIndex = 20;
			this->nUpDnPreAdaptiveThresholdBSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnPreAdaptiveThresholdBSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->nUpDnPreAdaptiveThresholdBSize->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnPreAdaptiveThresholdBSize_ValueChanged);
			// 
			// nUpDnPreGaussianBlurKSize
			// 
			this->nUpDnPreGaussianBlurKSize->AutoSize = true;
			this->nUpDnPreGaussianBlurKSize->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->nUpDnPreGaussianBlurKSize->Location = System::Drawing::Point(206, 42);
			this->nUpDnPreGaussianBlurKSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 121, 0, 0, 0 });
			this->nUpDnPreGaussianBlurKSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nUpDnPreGaussianBlurKSize->Name = L"nUpDnPreGaussianBlurKSize";
			this->nUpDnPreGaussianBlurKSize->Size = System::Drawing::Size(41, 20);
			this->nUpDnPreGaussianBlurKSize->TabIndex = 18;
			this->nUpDnPreGaussianBlurKSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnPreGaussianBlurKSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->nUpDnPreGaussianBlurKSize->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnPreGaussianBlurKSize_ValueChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(17, 35);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"║";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(17, 59);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"║";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(17, 47);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 16;
			this->label9->Text = L"╠";
			// 
			// cbPreGaussianBlur
			// 
			this->cbPreGaussianBlur->AutoSize = true;
			this->cbPreGaussianBlur->Checked = true;
			this->cbPreGaussianBlur->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbPreGaussianBlur->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbPreGaussianBlur->Location = System::Drawing::Point(34, 46);
			this->cbPreGaussianBlur->Name = L"cbPreGaussianBlur";
			this->cbPreGaussianBlur->Size = System::Drawing::Size(159, 17);
			this->cbPreGaussianBlur->TabIndex = 15;
			this->cbPreGaussianBlur->Text = L"Gaussian Blurring      ksize : ";
			this->cbPreGaussianBlur->UseVisualStyleBackColor = true;
			this->cbPreGaussianBlur->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbPreGaussianBlur_CheckedChanged);
			// 
			// lblGrayscale
			// 
			this->lblGrayscale->AutoSize = true;
			this->lblGrayscale->Location = System::Drawing::Point(18, 23);
			this->lblGrayscale->Name = L"lblGrayscale";
			this->lblGrayscale->Size = System::Drawing::Size(66, 13);
			this->lblGrayscale->TabIndex = 13;
			this->lblGrayscale->Text = L"■ Grayscale";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(17, 72);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 12;
			this->label8->Text = L"╠";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(17, 66);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"║";
			// 
			// cbPreAdaptiveThreshold
			// 
			this->cbPreAdaptiveThreshold->AutoSize = true;
			this->cbPreAdaptiveThreshold->Checked = true;
			this->cbPreAdaptiveThreshold->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbPreAdaptiveThreshold->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbPreAdaptiveThreshold->Location = System::Drawing::Point(34, 98);
			this->cbPreAdaptiveThreshold->Name = L"cbPreAdaptiveThreshold";
			this->cbPreAdaptiveThreshold->Size = System::Drawing::Size(160, 17);
			this->cbPreAdaptiveThreshold->TabIndex = 5;
			this->cbPreAdaptiveThreshold->Text = L"Adaptive Threshold    bsize :";
			this->cbPreAdaptiveThreshold->UseVisualStyleBackColor = true;
			this->cbPreAdaptiveThreshold->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbPreAdaptiveThreshold_CheckedChanged);
			// 
			// nUpDnPreBinaryThreshold
			// 
			this->nUpDnPreBinaryThreshold->AutoSize = true;
			this->nUpDnPreBinaryThreshold->Location = System::Drawing::Point(206, 120);
			this->nUpDnPreBinaryThreshold->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->nUpDnPreBinaryThreshold->Name = L"nUpDnPreBinaryThreshold";
			this->nUpDnPreBinaryThreshold->Size = System::Drawing::Size(41, 20);
			this->nUpDnPreBinaryThreshold->TabIndex = 3;
			this->nUpDnPreBinaryThreshold->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnPreBinaryThreshold->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 70, 0, 0, 0 });
			this->nUpDnPreBinaryThreshold->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnPreBinaryThreshold_ValueChanged);
			// 
			// cbPreHistEqualize
			// 
			this->cbPreHistEqualize->AutoSize = true;
			this->cbPreHistEqualize->Checked = true;
			this->cbPreHistEqualize->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbPreHistEqualize->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbPreHistEqualize->Location = System::Drawing::Point(34, 72);
			this->cbPreHistEqualize->Name = L"cbPreHistEqualize";
			this->cbPreHistEqualize->Size = System::Drawing::Size(133, 17);
			this->cbPreHistEqualize->TabIndex = 2;
			this->cbPreHistEqualize->Text = L"Histogram Equalization";
			this->cbPreHistEqualize->UseVisualStyleBackColor = true;
			this->cbPreHistEqualize->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbPreHistEqualize_CheckedChanged);
			// 
			// cbPreBinary
			// 
			this->cbPreBinary->AutoSize = true;
			this->cbPreBinary->Checked = true;
			this->cbPreBinary->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbPreBinary->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbPreBinary->Location = System::Drawing::Point(34, 124);
			this->cbPreBinary->Name = L"cbPreBinary";
			this->cbPreBinary->Size = System::Drawing::Size(156, 17);
			this->cbPreBinary->TabIndex = 1;
			this->cbPreBinary->Text = L"Binarization         threshold :";
			this->cbPreBinary->UseVisualStyleBackColor = true;
			this->cbPreBinary->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbPreBinary_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
																						| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->Controls->Add(this->toolStrip);
			this->groupBox1->Location = System::Drawing::Point(5, 22);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(298, 53);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Play";
			// 
			// toolStrip
			// 
			this->toolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {
				this->tsVideoCamDevLbl,
					this->tsVideoCamDev, this->tsVideoPlay, this->tsVideoRecord, this->tsVideoPause, this->tsVideoStop, this->tsVideoBackward, this->tsVideoForward,
					this->toolStripSeparator1, this->tsVideoFileOpen, this->toolStripSeparator2, this->tsConfigFileSave
			});
			this->toolStrip->Location = System::Drawing::Point(11, 18);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Size = System::Drawing::Size(243, 25);
			this->toolStrip->TabIndex = 0;
			this->toolStrip->Text = L"toolStrip1";
			// 
			// tsVideoCamDevLbl
			// 
			this->tsVideoCamDevLbl->Name = L"tsVideoCamDevLbl";
			this->tsVideoCamDevLbl->Size = System::Drawing::Size(12, 22);
			this->tsVideoCamDevLbl->Text = L"-";
			this->tsVideoCamDevLbl->ToolTipText = L"0";
			// 
			// tsVideoCamDev
			// 
			this->tsVideoCamDev->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsVideoCamDev->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsVideoCamDev.Image")));
			this->tsVideoCamDev->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsVideoCamDev->Name = L"tsVideoCamDev";
			this->tsVideoCamDev->Size = System::Drawing::Size(32, 22);
			this->tsVideoCamDev->Text = L"Camera Device";
			this->tsVideoCamDev->ButtonClick += gcnew System::EventHandler(this, &VisionWinForm::tsVideoCamDev_ButtonClick);
			// 
			// tsVideoPlay
			// 
			this->tsVideoPlay->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsVideoPlay->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsVideoPlay.Image")));
			this->tsVideoPlay->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsVideoPlay->Name = L"tsVideoPlay";
			this->tsVideoPlay->Size = System::Drawing::Size(23, 22);
			this->tsVideoPlay->Text = L"Play";
			this->tsVideoPlay->Click += gcnew System::EventHandler(this, &VisionWinForm::tsVideoPlayBtn_Click);
			// 
			// tsVideoRecord
			// 
			this->tsVideoRecord->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsVideoRecord->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsVideoRecord.Image")));
			this->tsVideoRecord->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsVideoRecord->Name = L"tsVideoRecord";
			this->tsVideoRecord->Size = System::Drawing::Size(23, 22);
			this->tsVideoRecord->Text = L"Record";
			this->tsVideoRecord->Click += gcnew System::EventHandler(this, &VisionWinForm::tsVideoRecord_Click);
			// 
			// tsVideoPause
			// 
			this->tsVideoPause->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsVideoPause->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsVideoPause.Image")));
			this->tsVideoPause->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsVideoPause->Name = L"tsVideoPause";
			this->tsVideoPause->Size = System::Drawing::Size(23, 22);
			this->tsVideoPause->Text = L"Pause";
			this->tsVideoPause->Click += gcnew System::EventHandler(this, &VisionWinForm::tsVideoPause_Click);
			// 
			// tsVideoStop
			// 
			this->tsVideoStop->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsVideoStop->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsVideoStop.Image")));
			this->tsVideoStop->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsVideoStop->Name = L"tsVideoStop";
			this->tsVideoStop->Size = System::Drawing::Size(23, 22);
			this->tsVideoStop->Text = L"toolStripButton1";
			this->tsVideoStop->ToolTipText = L"Stop";
			this->tsVideoStop->Click += gcnew System::EventHandler(this, &VisionWinForm::tsVideoStop_Click);
			// 
			// tsVideoBackward
			// 
			this->tsVideoBackward->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsVideoBackward->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsVideoBackward.Image")));
			this->tsVideoBackward->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsVideoBackward->Name = L"tsVideoBackward";
			this->tsVideoBackward->Size = System::Drawing::Size(23, 22);
			this->tsVideoBackward->Text = L"Backward by 10 seconds";
			this->tsVideoBackward->Click += gcnew System::EventHandler(this, &VisionWinForm::tsVideoBackward_Click);
			// 
			// tsVideoForward
			// 
			this->tsVideoForward->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsVideoForward->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsVideoForward.Image")));
			this->tsVideoForward->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsVideoForward->Name = L"tsVideoForward";
			this->tsVideoForward->Size = System::Drawing::Size(23, 22);
			this->tsVideoForward->Text = L"Forward by 10 seconds";
			this->tsVideoForward->Click += gcnew System::EventHandler(this, &VisionWinForm::tsVideoForward_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
			// 
			// tsVideoFileOpen
			// 
			this->tsVideoFileOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsVideoFileOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsVideoFileOpen.Image")));
			this->tsVideoFileOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsVideoFileOpen->Name = L"tsVideoFileOpen";
			this->tsVideoFileOpen->Size = System::Drawing::Size(23, 22);
			this->tsVideoFileOpen->Text = L"Open Video";
			this->tsVideoFileOpen->Click += gcnew System::EventHandler(this, &VisionWinForm::tsVideoFileOpen_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
			// 
			// tsConfigFileSave
			// 
			this->tsConfigFileSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tsConfigFileSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"tsConfigFileSave.Image")));
			this->tsConfigFileSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tsConfigFileSave->Name = L"tsConfigFileSave";
			this->tsConfigFileSave->Size = System::Drawing::Size(23, 22);
			this->tsConfigFileSave->Text = L"Save Config File";
			this->tsConfigFileSave->Click += gcnew System::EventHandler(this, &VisionWinForm::ConfigFileSave_Click);
			// 
			// gbOperOption
			// 
			this->gbOperOption->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
																						   | System::Windows::Forms::AnchorStyles::Right));
			this->gbOperOption->Controls->Add(this->lblLowPassFilterHz);
			this->gbOperOption->Controls->Add(this->nUpDnLowPassFilterHz);
			this->gbOperOption->Controls->Add(this->cbLowPassFilter);
			this->gbOperOption->Controls->Add(this->lblLowFreqFilterHz);
			this->gbOperOption->Controls->Add(this->cbHighPassFilter);
			this->gbOperOption->Controls->Add(this->nUpDnHighPassFilterHz);
			this->gbOperOption->Controls->Add(this->lblShowMatchValue);
			this->gbOperOption->Controls->Add(this->cbShowMatchMaxValue);
			this->gbOperOption->Controls->Add(this->cbShowMatchMinValue);
			this->gbOperOption->Controls->Add(this->cbShowPrcsInfoOnImage);
			this->gbOperOption->Controls->Add(this->cbAutoResize);
			this->gbOperOption->Location = System::Drawing::Point(5, 737);
			this->gbOperOption->Name = L"gbOperOption";
			this->gbOperOption->Size = System::Drawing::Size(298, 160);
			this->gbOperOption->TabIndex = 4;
			this->gbOperOption->TabStop = false;
			this->gbOperOption->Text = L"Operation Option";
			// 
			// lblLowPassFilterHz
			// 
			this->lblLowPassFilterHz->AutoSize = true;
			this->lblLowPassFilterHz->Location = System::Drawing::Point(249, 133);
			this->lblLowPassFilterHz->Name = L"lblLowPassFilterHz";
			this->lblLowPassFilterHz->Size = System::Drawing::Size(26, 13);
			this->lblLowPassFilterHz->TabIndex = 27;
			this->lblLowPassFilterHz->Text = L"(Hz)";
			// 
			// nUpDnLowPassFilterHz
			// 
			this->nUpDnLowPassFilterHz->DecimalPlaces = 1;
			this->nUpDnLowPassFilterHz->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nUpDnLowPassFilterHz->Location = System::Drawing::Point(189, 129);
			this->nUpDnLowPassFilterHz->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nUpDnLowPassFilterHz->Name = L"nUpDnLowPassFilterHz";
			this->nUpDnLowPassFilterHz->Size = System::Drawing::Size(55, 20);
			this->nUpDnLowPassFilterHz->TabIndex = 26;
			this->nUpDnLowPassFilterHz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnLowPassFilterHz->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			this->nUpDnLowPassFilterHz->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnLowPassFilterHz_ValueChanged);
			// 
			// cbLowPassFilter
			// 
			this->cbLowPassFilter->AutoSize = true;
			this->cbLowPassFilter->Checked = true;
			this->cbLowPassFilter->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbLowPassFilter->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbLowPassFilter->Location = System::Drawing::Point(11, 131);
			this->cbLowPassFilter->Name = L"cbLowPassFilter";
			this->cbLowPassFilter->Size = System::Drawing::Size(105, 17);
			this->cbLowPassFilter->TabIndex = 25;
			this->cbLowPassFilter->Text = L"Low-pass Filter  :";
			this->cbLowPassFilter->UseVisualStyleBackColor = true;
			this->cbLowPassFilter->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbLowPassFilter_CheckedChanged);
			// 
			// lblLowFreqFilterHz
			// 
			this->lblLowFreqFilterHz->AutoSize = true;
			this->lblLowFreqFilterHz->Location = System::Drawing::Point(249, 105);
			this->lblLowFreqFilterHz->Name = L"lblLowFreqFilterHz";
			this->lblLowFreqFilterHz->Size = System::Drawing::Size(26, 13);
			this->lblLowFreqFilterHz->TabIndex = 24;
			this->lblLowFreqFilterHz->Text = L"(Hz)";
			// 
			// cbHighPassFilter
			// 
			this->cbHighPassFilter->AutoSize = true;
			this->cbHighPassFilter->Checked = true;
			this->cbHighPassFilter->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbHighPassFilter->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbHighPassFilter->Location = System::Drawing::Point(11, 103);
			this->cbHighPassFilter->Name = L"cbHighPassFilter";
			this->cbHighPassFilter->Size = System::Drawing::Size(107, 17);
			this->cbHighPassFilter->TabIndex = 7;
			this->cbHighPassFilter->Text = L"High-pass Filter  :";
			this->cbHighPassFilter->UseVisualStyleBackColor = true;
			this->cbHighPassFilter->CheckedChanged += gcnew System::EventHandler(this, &VisionWinForm::cbHighPassFilter_CheckedChanged);
			// 
			// nUpDnHighPassFilterHz
			// 
			this->nUpDnHighPassFilterHz->DecimalPlaces = 1;
			this->nUpDnHighPassFilterHz->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nUpDnHighPassFilterHz->Location = System::Drawing::Point(189, 101);
			this->nUpDnHighPassFilterHz->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nUpDnHighPassFilterHz->Name = L"nUpDnHighPassFilterHz";
			this->nUpDnHighPassFilterHz->Size = System::Drawing::Size(55, 20);
			this->nUpDnHighPassFilterHz->TabIndex = 23;
			this->nUpDnHighPassFilterHz->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->nUpDnHighPassFilterHz->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			this->nUpDnHighPassFilterHz->ValueChanged += gcnew System::EventHandler(this, &VisionWinForm::nUpDnHighPassFilterHz_ValueChanged);
			// 
			// lblShowMatchValue
			// 
			this->lblShowMatchValue->AutoSize = true;
			this->lblShowMatchValue->Location = System::Drawing::Point(9, 23);
			this->lblShowMatchValue->Name = L"lblShowMatchValue";
			this->lblShowMatchValue->Size = System::Drawing::Size(125, 13);
			this->lblShowMatchValue->TabIndex = 6;
			this->lblShowMatchValue->Text = L"■  Show Match Value ° :";
			// 
			// cbShowMatchMaxValue
			// 
			this->cbShowMatchMaxValue->AutoSize = true;
			this->cbShowMatchMaxValue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbShowMatchMaxValue->Location = System::Drawing::Point(147, 21);
			this->cbShowMatchMaxValue->Name = L"cbShowMatchMaxValue";
			this->cbShowMatchMaxValue->Size = System::Drawing::Size(76, 17);
			this->cbShowMatchMaxValue->TabIndex = 5;
			this->cbShowMatchMaxValue->Text = L"Max Value";
			this->cbShowMatchMaxValue->UseVisualStyleBackColor = true;
			// 
			// cbShowMatchMinValue
			// 
			this->cbShowMatchMinValue->AutoSize = true;
			this->cbShowMatchMinValue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbShowMatchMinValue->Location = System::Drawing::Point(225, 21);
			this->cbShowMatchMinValue->Name = L"cbShowMatchMinValue";
			this->cbShowMatchMinValue->Size = System::Drawing::Size(73, 17);
			this->cbShowMatchMinValue->TabIndex = 2;
			this->cbShowMatchMinValue->Text = L"Min Value";
			this->cbShowMatchMinValue->UseVisualStyleBackColor = true;
			// 
			// cbShowPrcsInfoOnImage
			// 
			this->cbShowPrcsInfoOnImage->AutoSize = true;
			this->cbShowPrcsInfoOnImage->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbShowPrcsInfoOnImage->Location = System::Drawing::Point(11, 47);
			this->cbShowPrcsInfoOnImage->Name = L"cbShowPrcsInfoOnImage";
			this->cbShowPrcsInfoOnImage->Size = System::Drawing::Size(184, 17);
			this->cbShowPrcsInfoOnImage->TabIndex = 1;
			this->cbShowPrcsInfoOnImage->Text = L"Show process info on the image °";
			this->cbShowPrcsInfoOnImage->UseVisualStyleBackColor = true;
			// 
			// cbAutoResize
			// 
			this->cbAutoResize->AutoSize = true;
			this->cbAutoResize->Checked = true;
			this->cbAutoResize->CheckState = System::Windows::Forms::CheckState::Checked;
			this->cbAutoResize->Cursor = System::Windows::Forms::Cursors::Hand;
			this->cbAutoResize->Location = System::Drawing::Point(11, 75);
			this->cbAutoResize->Name = L"cbAutoResize";
			this->cbAutoResize->Size = System::Drawing::Size(90, 17);
			this->cbAutoResize->TabIndex = 0;
			this->cbAutoResize->Text = L"Auto Resize °";
			this->cbAutoResize->UseVisualStyleBackColor = true;
			// 
			// tbMsg
			// 
			this->tbMsg->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
																					| System::Windows::Forms::AnchorStyles::Right));
			this->tbMsg->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbMsg->Location = System::Drawing::Point(5, 904);
			this->tbMsg->Name = L"tbMsg";
			this->tbMsg->Size = System::Drawing::Size(299, 83);
			this->tbMsg->TabIndex = 1;
			this->tbMsg->Text = L"";
			// 
			// videoTimer
			// 
			this->videoTimer->Interval = 34;
			this->videoTimer->Tick += gcnew System::EventHandler(this, &VisionWinForm::videoTimer_Tick);
			// 
			// lblState
			// 
			this->lblState->AutoSize = true;
			this->lblState->Location = System::Drawing::Point(6, 3);
			this->lblState->Name = L"lblState";
			this->lblState->Size = System::Drawing::Size(104, 13);
			this->lblState->TabIndex = 5;
			this->lblState->Text = L"변위 및 주파수 측정";
			// 
			// statePanel
			// 
			this->statePanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
																						 | System::Windows::Forms::AnchorStyles::Right));
			this->statePanel->Controls->Add(this->lblState);
			this->statePanel->Location = System::Drawing::Point(10, 1029);
			this->statePanel->Name = L"statePanel";
			this->statePanel->Size = System::Drawing::Size(1091, 20);
			this->statePanel->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1112, 1051);
			this->Controls->Add(this->videoGb);
			this->Controls->Add(this->statePanel);
			this->Controls->Add(this->controlGb);
			this->Controls->Add(this->chartGb);
			this->Controls->Add(this->msPlay);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->msPlay;
			this->Name = L"Form1";
			this->Text = L"Displacement Frequency Analyzer   v 1.0.05";
			this->Load += gcnew System::EventHandler(this, &VisionWinForm::Form1_Load);
			this->msPlay->ResumeLayout(false);
			this->msPlay->PerformLayout();
			this->videoGb->ResumeLayout(false);
			this->videoInfoPanel->ResumeLayout(false);
			this->videoInfoPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnFps))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVideoRecording))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbImgPrcsAni))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVideoGetFrameAni))->EndInit();
			this->videoStatePanel->ResumeLayout(false);
			this->videoStatePanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tbVideoCurrFramePos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVideo))->EndInit();
			this->chartGb->ResumeLayout(false);
			this->chartGb->PerformLayout();
			this->pnlChartMenu->ResumeLayout(false);
			this->pnlChartMenu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbChartPrcs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbChartFreqVertAxisTitle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartFreq))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbChartDispVertAxisTitle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDisp))->EndInit();
			this->controlGb->ResumeLayout(false);
			this->gbFeatureOption->ResumeLayout(false);
			this->gbFeatureOption->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnFocalLength))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnDPI))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTarget))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnFeatureDistance))->EndInit();
			this->gbMathOption->ResumeLayout(false);
			this->gbMathOption->PerformLayout();
			this->gbPreprocess->ResumeLayout(false);
			this->gbPreprocess->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreCannyThresh2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreCannyApSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreAdaptiveThresholdBSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreGaussianBlurKSize))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnPreBinaryThreshold))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			this->gbOperOption->ResumeLayout(false);
			this->gbOperOption->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnLowPassFilterHz))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nUpDnHighPassFilterHz))->EndInit();
			this->statePanel->ResumeLayout(false);
			this->statePanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
	private: 

		ComponentResourceManager^  resources ;
		ExtResourcesForm^ extRscForm ; 

		VisionSystem * visionSystem ; 

		int msgCnt ; 
		int timerCnt ; 
		bool timerOn ;
		long timerThen;
		long timerNow;

		int aniFrameCnt ; 

		bool prePrcsImgRslt ; // previous image processing result  

		System::String^ prevShowMsg ;

		cv::Size * videoPlayerSize ; 

		CannyOption * cannyOption ; 

		bool mouseDown ;
		int  mouseX ;
		int  mouseY ; 

		Mat * targetImg;

		VisionChartDisp^ visionChartDisp;
		VisionChartFreq^ visionChartFreq;

		int preVisionChartDispXAxisInterval ;
		int preVisionChartFreqXAxisInterval ; 

		bool videoCurrentFramePosTrackBarMoving ; 

		bool targetDrawing ;
		bool videoDrawing ; 

		bool videoPause ;
		bool videoStop ; 

		int timerIntervalCalibCnt ;

		void initData() {

			resources = (gcnew System::ComponentModel::ComponentResourceManager(VisionWinForm::typeid));
			extRscForm = gcnew ExtResourcesForm(); 

			videoPause = false;
			videoStop = false ; 

			msgCnt = 0 ;
			timerCnt = 0 ;
			timerOn = false ;
			prePrcsImgRslt = false ; 

			aniFrameCnt = 0 ;

			visionSystem = new VisionSystem(); 
			cannyOption = new CannyOption();

			timerThen = GetTickCount() ;
			timerNow = timerThen ; 

			mouseDown = false;
			mouseX = -1 ;
			mouseY = -1;

			this->targetImg = NULL ; 

			videoPlayerSize = new cv::Size();

			visionChartDisp = gcnew VisionChartDisp( this->chartDisp );
			visionChartFreq = gcnew VisionChartFreq( this->chartFreq );

			preVisionChartDispXAxisInterval = -1 ;
			preVisionChartFreqXAxisInterval = -1 ; 

			videoCurrentFramePosTrackBarMoving = false ; 

			targetDrawing = false; 
			videoDrawing = false;

			timerIntervalCalibCnt = 0 ; 

		}

		void destroyData() {
			if( NULL != visionSystem ) { 
				visionSystem->release() ;

				delete visionSystem ;

				visionSystem = NULL ; 
			}

			if( NULL != cannyOption ) {
				delete cannyOption ;

				cannyOption = NULL ; 
			} 

			if( NULL != videoPlayerSize ) {
				delete videoPlayerSize ;

				videoPlayerSize = NULL ; 
			}
		}

	public:

		void MarshalString ( System::String ^ s, std::string * os ) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			(*os) = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		} 

		virtual void showMsg( std::string * text ) {
			this->showMsg( text->c_str() );
		}

		virtual void showMsg( const char * buff ) {   
			System::String^ text = gcnew System::String( buff ); 

			this->showMsg( text );
		} 

		virtual void showMsg( System::String^ text ) { 

			if( nullptr != text && nullptr != prevShowMsg && prevShowMsg->Equals( text ) ) {
				return ;
			}
			
			msgCnt ++ ; 

			this->prevShowMsg = text ; 

			this->tbMsg->AppendText( "[" + msgCnt + "] " + text + "\n" ); 

			this->tbMsg->SelectionStart = this->tbMsg->TextLength;
			this->tbMsg->SelectionLength = 0 ;
			this->tbMsg->ScrollToCaret();

			this->lblState->Text = text;			
		} 

		virtual void showChartPaintOpt( int optLevel ) {
			if( optLevel > 0 ) { 
				this->pbChartPrcs->Image = this->extRscForm->pbChartPrcsOpt->Image ; 
			} else {
				this->pbChartPrcs->Image = this->extRscForm->pbChartPrcs->Image ; 
			}
		}

		virtual void showException( System::Exception^ e ) {  
			System::Console::WriteLine( e );

			if( e->InnerException ) {
				System::Console::WriteLine( "Inner Exception: {0}", e->InnerException );
			} 
		}

		virtual bool SetTargetPbImage( Vision * vision, RECT * videoRect, Mat * img) {
			if( this->targetDrawing ) {
				return false ; 
			}

			this->targetDrawing = true ; 

			bool b = false ; 
			
			try { 
				b = vision->SetPictureBoxImage( this->pbTarget, videoRect, img ); 
				if( false == b ) { 
					b = vision->DrawImageOnPictureBox( this->pbTarget, videoRect, img );
				}
			} catch( System::Exception^ e) {
				showException( e );
			}

			this->targetDrawing = false ; 
			
			return b;
		}

		virtual int getMatchMethod() {
			// CV_TM_CCORR         ==  DIC 알고리즘 
			// CV_TM_CCORR_NORMED  ==  NCC 알고리즘

			if( this->rbDic->Checked ) { 
				return CV_TM_CCORR ;
			} else {
				return CV_TM_CCORR_NORMED ;
			}
		}

		virtual System::Windows::Forms::PictureBox^ getPbVideo() {
			return this->pbVideo;
		}

		virtual System::Windows::Forms::PictureBox^ getPbTarget() {
			return this->pbTarget;
		} 

		virtual bool isCoeffNorm() {
			return this->cbCoeffNorm->Checked ;
		}

		virtual bool isAutoResize() {
			return this->cbAutoResize->Checked ;
		} 

		virtual cv::Size * GetVideoPlayerSize() {
			return this->videoPlayerSize;
		}

		virtual void setVideoPlayerSize( int width, int height, bool autoResize ) {

			this->videoPlayerSize->width = width ;
			this->videoPlayerSize->height = height ;

			if( autoResize ) {  
				int m = 10 ; // margin

				width += 10 ;
				height += 10 ;

				PictureBox^  pbVideo = this->pbVideo ;

				System::Drawing::Size^ size = pbVideo->Size ; 

				int dw = width - size->Width ; 
				int dh = height - size->Height ;

				if( dw < 1 && dh < 1 ) {
					return;
				}

				dw = dw < 0 ? 0 : dw ;
				dh = dh < 0 ? 0 : dh ;

				size = this->Size ;

				int w = size->Width + dw ;
				int h = size->Height + dh ;

				this->Size = System::Drawing::Size( w, h ); 

				System::String^ msg = "Video player auto size: [" + width + "x" + height + "]" ;			

				showMsg( msg ) ;
			}

		} 

		virtual void showMoviePlayInfo( VideoInfo * videoInfo ) { 
			 
			if( NULL != videoInfo ) {
				const int fps = videoInfo->fps;
				const int frameCnt = videoInfo->GetFrameCnt();
				const double playTimeSec = frameCnt/(fps + 0.0);
				const int playTimeMiliSec = (int)( playTimeSec*1000);

				const int prcsFrameCnt = videoInfo->prcsFrameCnt ;  

				const int buffSize = 20;
				char buff[ buffSize ];

				// image width
				this->tbVideoWidth->Text = ( L"" + videoInfo->imgWidth );

				// image height
				this->tbVideoHeight->Text = ( L"" + videoInfo->imgHeight );

				// frame count
				this->tbVideoFrameCnt->Text = ( L"" + frameCnt );

				// play time
				sprintf_s( buff, "%.3f", playTimeSec ); 
				this->tbVideoPlayTime->Text = gcnew System::String( buff ) ;
				// fps skip

				// image processing time
				this->tbImgPsTime->Text = ( L"" + videoInfo->psTimeMiliSec );

				// set current time
				ComObject::formatHMS( buff, buffSize, playTimeMiliSec ); 
				this->lblVideoCurrTime->Text = gcnew System::String( buff ); 

				// set total time
				System::String^ text = gcnew System::String( videoInfo->totPlayTimeText );
				this->lblVideoTotTime->Text = gcnew System::String( text ); 

				// set video play position ratio
				if( false == this->videoCurrentFramePosTrackBarMoving ) { 
					int posRatioPct = 0;
					int totFrameCnt = videoInfo->totFrameCnt ; 
					if( totFrameCnt > 0 ) {  
						int frameCnt = videoInfo->GetFrameCnt();
						posRatioPct = (int)( frameCnt/( totFrameCnt + 0.0)*100 ) ; 
						if( false ) { 
							System::String^ msg = L"curr/tot = " + frameCnt + "/" + totFrameCnt ;
							showMsg( msg );
						}
					}

					posRatioPct = posRatioPct > 100 ? 100 : posRatioPct;
					posRatioPct = posRatioPct < 0 ? 0 : posRatioPct ;  

					if( posRatioPct != this->tbVideoCurrFramePos->Value ) { 
						this->tbVideoCurrFramePos->Value = posRatioPct ;
					}
				}

			} else {
				this->lblVideoTotTime->Text = L"00:00:00"; 
				this->tbVideoCurrFramePos->Value = 0;
			}

		}

		virtual int GetFps() {
			return (int) this->nUpDnFps->Value ; 
		}

		virtual void SetFps( int fps ) {

			if( fps < 1 ) {
				return;
			}

			int minFps = (int) ( ((double)nUpDnFps->Minimum) + 0.5  );

			fps = fps < minFps ? minFps : fps ;

			if( fps >= ( this->nUpDnFps->Maximum ) ) {
				this->nUpDnFps->Maximum = fps ;
			}

			this->nUpDnFps->Value = fps ;

			double interval = 1000.0/(fps + 0.0);

			this->videoTimer->Interval = (int)( interval ); 
		}

		virtual int GetDpi() {
			return (int) this->nUpDnDPI->Value ; 
		}

		virtual double GetScaleFactor() {
			// M : Meter
			// f : focal length
			// m : meter unit
			// mm : mili meter unit 
			// (inch) = 0.0254 (meter)
			// (m) = 39.3701 (inch)
			// dpi : dots per inch
			// dpi = pixels/inch = 
			// D : Distance to the feature
			// X : geographic coordinate
			// x : image coordinate
			// x(m) = f(m)*X(m)/D(m) 
			// x(inch) = f(m)*X(inch)/D(m)
			// pixels = dpi(pixels/inch)*f(m)*X(inch)/D(m)
			// X(inch) = D(m)/f(m)*pixels
			// X(m)    = D(m)/(0.0254*f(10^3 mm))*pixels
			//         = D(m)/(25.4*f(mm))*pixels
			//         = scaleFactor*pixels

			// ScaleFactor = D(m)/(25.4*f(mm))


			double dist_m = (double) this->nUpDnFeatureDistance->Value/100.0 ; 
			double f_mm = (double) this->nUpDnFocalLength->Value ;
			double dpi = this->GetDpi() ;

			double sf = dist_m/(25.4*f_mm);

			return sf;
		}

		virtual void SetScaleFactor() { 
			double scaleFactor = this->GetScaleFactor();
			char text[ 200 ];
			sprintf_s( text, "%.10f" , scaleFactor );

			this->tbScaleFactor->Text = gcnew System::String( text );
		}

		virtual void PaintVideo() {
			if( this->videoDrawing ) {
				return;
			}

			this->videoDrawing = true; 
			
			try { 
				VisionSystem * vs = this->visionSystem ;   

				vs->ProcessImageToRepaintVideo( this ) ;

				vs->PaintImage( this );
			} catch( System::Exception^ e ) {
				this->showException( e );
			}

			this->videoDrawing = false ;
		}

		virtual System::String^ GetConfigValue(System::Windows::Forms::CheckBox^ cb ) {
			int en = cb->Enabled ? 2 : 0 ;
			int ch = cb->Checked ? 1 : 0 ;

			char text[ 10 ];

			int val = en | ch ; 
			sprintf_s( text, "%d", val );

			System::String^ str = gcnew System::String( text );

			return str;
		}

		virtual System::String^ GetConfigValue(System::Windows::Forms::RadioButton^ rb ) {
			int en = rb->Enabled ? 2 : 0 ;
			int ch = rb->Checked ? 1 : 0 ;

			char text[ 10 ];

			int val = en | ch ; 
			sprintf_s( text, "%d", val );

			System::String^ str = gcnew System::String( text );

			return str;
		} 

		virtual System::String^ GetConfigValue(System::Windows::Forms::NumericUpDown ^nUpDn ) {
			double val = (double) (nUpDn->Value ); 

			char text[ 10 ]; 
			sprintf_s( text, "%f", val );

			System::String^ str = gcnew System::String( text );

			return str;
		}

		virtual void SetConfigValue( System::Windows::Forms::CheckBox^ cb , System::String^ val ) {
			this->SetConfigValue( cb, toInt( val ) );
		}

		virtual void SetConfigValue( System::Windows::Forms::RadioButton^ rb , System::String^ val ) {
			this->SetConfigValue( rb, toInt( val ) );
		}

		virtual void SetConfigValue( System::Windows::Forms::NumericUpDown^ nUpDn , System::String^ val ) {
			nUpDn->Value = toDecimal( val );
		}

		virtual void SetConfigValue( System::Windows::Forms::TextBox^ tb , System::String^ val ) {
			tb->Text = val ; 
		}

		virtual void SetConfigValue( System::Windows::Forms::Label^ lbl , System::String^ val ) {
			lbl->Text = val ; 
		}

		virtual void SetConfigValue( System::Windows::Forms::CheckBox^ cb , int val ) {
			int en = val & 2 ;
			int ch = val & 1 ;

			cb->Enabled = en == 2 ;
			cb->Checked = ch == 1 ;
		}

		virtual void SetConfigValue( System::Windows::Forms::RadioButton^ rb , int val ) {
			int enabled = val & 2 ;
			int checked = val & 1 ;

			rb->Enabled = enabled == 2 ;
			rb->Checked = checked == 1 ;
		}

		virtual int toInt( System::String^ value ) {
			return (int) toDecimal( value );
		}

		virtual Decimal toDecimal( System::String^ value ) {
			int idx = value->LastIndexOf( "," );
			if( idx > -1 ) {
				value = value->Substring( idx + 1 );
			}
			return System::Convert::ToDecimal( value );
		} 

		virtual void ConfigFileOpen(System::String^ fileName) {

			showMsg( L"Loading Config ..." );

			System::Configuration::Configuration^ config = nullptr;

			if( nullptr == fileName || fileName->Length < 1 ) {  
				// save configuration file app.config
				config = ConfigurationManager::OpenExeConfiguration( ConfigurationUserLevel::None);  
			} else if( nullptr != fileName && fileName->Length > 0 ) {
				// save configuration file on the file user selected
				ExeConfigurationFileMap^ fileMap = gcnew ExeConfigurationFileMap();
				fileMap->ExeConfigFilename = fileName ; 
				config = ConfigurationManager::OpenMappedExeConfiguration( fileMap, ConfigurationUserLevel::None); 
			}

			if( nullptr == config ) { 
				return ;
			}

			System::Configuration::AppSettingsSection^ appSet = config->AppSettings;  
			System::Configuration::KeyValueConfigurationCollection^ settings = appSet->Settings ;

			System::String^ key ;
			System::Configuration::KeyValueConfigurationElement^ value; 

			// FPS
			key = L"fps" ; 
			value = settings[ key ];
			if( nullptr != value ) { 
				SetConfigValue( this->nUpDnFps , value->Value );
			}

			// Gaussian blur
			key = L"gaussian_blur" ;
			value = settings[ key ];
			if( nullptr != value ) { 
				this->SetConfigValue( this->cbPreGaussianBlur, value->Value );
			}

			// Gaussian blur ksize
			key = L"ksize" ;
			value = settings[ key ];
			if( nullptr != value ) { 
				SetConfigValue( this->nUpDnPreGaussianBlurKSize , value->Value ); 
			}

			// Histogram equal 
			key = L"hist_equal";
			value = settings[ key ];
			if( nullptr != value ) { 
				this->SetConfigValue( this->cbPreHistEqualize, value->Value );
			} 

			// Adaptive threshold
			key = L"adap_thresh";
			value = settings[ key ];
			if( nullptr != value ) { 
				this->SetConfigValue( this->cbPreAdaptiveThreshold, value->Value );
			}

			key = L"bsize";
			value = settings[ key ];
			if( nullptr != value ) { 
				SetConfigValue( this->nUpDnPreAdaptiveThresholdBSize , value->Value );  
			}

			key = L"binary";
			value = settings[ key ];
			if( nullptr != value ) { 
				this->SetConfigValue( this->cbPreBinary, value->Value );
			}

			key = L"binary_thresh";
			value = settings[ key ];
			if( nullptr != value ) { 
				SetConfigValue( this->nUpDnPreBinaryThreshold , value->Value );  
			}

			key = L"canny";
			value = settings[ key ];
			if( nullptr != value ){ 
				this->SetConfigValue( this->cbPreCanny, value->Value );
			}

			key = L"ap_size";
			value = settings[ key ];
			if( nullptr != value ){ 
				SetConfigValue( this->nUpDnPreCannyApSize , value->Value );  
			}

			key = L"canny_thresh" ;
			value = settings[ key ]; 
			if( nullptr != value ) { 
				SetConfigValue( this->nUpDnPreCannyThresh2 , value->Value );  
			}

			key = L"DIC";
			value = settings[ key ];
			if( nullptr != value ) { 
				this->SetConfigValue( this->rbDic, value->Value );
			}

			key = L"NCC";
			value = settings[ key ];
			if( nullptr != value ){ 
				this->SetConfigValue( this->rbNcc, value->Value ); 
			}  

			key = L"coeff_norm";
			value = settings[ key ];
			if( nullptr != value ){ 
				this->SetConfigValue( this->cbCoeffNorm, value->Value ); 
			} 

			key = L"scale_factor";
			value = settings[ key ];
			if( nullptr != value ){ 
				this->SetConfigValue( this->tbScaleFactor, value->Value );  
			}

			key = L"dist";
			value = settings[ key ];
			if( nullptr != value ){ 
				SetConfigValue( this->nUpDnFeatureDistance , value->Value );  
			}

			key = L"dpi";
			value = settings[ key ];
			if( nullptr != value ){ 
				SetConfigValue( this->nUpDnDPI , value->Value ); 
			}

			key = L"focal_length";
			value = settings[ key ];
			if( nullptr != value ){ 
				SetConfigValue( this->nUpDnFocalLength , value->Value ); 
			}

			key = L"dft";
			value = settings[ key ] ;
			if( nullptr != value ){ 
				this->SetConfigValue( this->rbChartDft, value->Value );
			}

			key = L"fft";
			value = settings[ key ];
			if( nullptr != value ){ 
				this->SetConfigValue( this->rbChartFft, value->Value );
			}

			key = L"high_pass_filter";
			value = settings[ key ];
			if( nullptr != value ){ 
				this->SetConfigValue( this->cbHighPassFilter, value->Value );
			} 

			key = L"high_pass_filter_hz";
			value = settings[ key ];
			if( nullptr != value ){
				this->SetConfigValue( this->nUpDnHighPassFilterHz, value->Value ); 
			}

			key = L"low_pass_filter";
			value = settings[ key ];
			if( nullptr != value ){ 
				this->SetConfigValue( this->cbLowPassFilter, value->Value );
			} 

			key = L"low_pass_filter_hz";
			value = settings[ key ];
			if( nullptr != value ){
				this->SetConfigValue( this->nUpDnLowPassFilterHz, value->Value ); 
			}

			bool debug = false ; 
			if( debug ) {  
				for each(System::String ^ key in settings ){
					value = settings[ key ] ; 
					showMsg( L"key:" + key + "; value: " + value + ";" ) ;
				}
			}  

			ConfigurationManager::RefreshSection( "appSettings" );

			System::String^ title = "Success";
			System::String^ msg = L"Configuration-Loading Success." ; 
			System::Windows::Forms::MessageBox::Show( msg, title, MessageBoxButtons::OK, MessageBoxIcon::Information ) ;

			showMsg( L"Done Loading Config." ); 
		} 

		virtual void ConfigFileSave(System::String^ fileName ) {
			showMsg( L"Save Config ..." + fileName );

			System::Configuration::Configuration^ config = nullptr;
			
			if( nullptr == fileName || fileName->Length < 1 ) {  
				// save configuration file app.config
				config = ConfigurationManager::OpenExeConfiguration( ConfigurationUserLevel::None); 
				ConfigurationManager::RefreshSection( "appSettings" );

				config->Sections->Remove( "appSettings" ); 
			} else if( nullptr != fileName && fileName->Length > 0 ) {
				// save configuration file on the file user selected
				ExeConfigurationFileMap^ fileMap = gcnew ExeConfigurationFileMap();
				fileMap->ExeConfigFilename = fileName ; 
				config = ConfigurationManager::OpenMappedExeConfiguration( fileMap, ConfigurationUserLevel::None);
				config->SectionGroups->Clear();
				ConfigurationManager::RefreshSection( "appSettings" );

				config->Sections->Remove( "appSettings" ); 
			}

			if( nullptr == config ) { 
				return ;
			}

			System::Configuration::AppSettingsSection^ appSet = config->AppSettings; 
			 
			System::Configuration::KeyValueConfigurationCollection^ settings = appSet->Settings ;  
			System::String^ key ;
			System::String^ value;  

			// FPS
			key = L"fps" ;
			value = L"" + this->GetFps(); 
			settings->Add( key, value ); 

			// Gaussian blur
			key = L"gaussian_blur" ;
			value = GetConfigValue( this->cbPreGaussianBlur );
			settings->Add( key, value ); 

			// Gaussian blur ksize
			key = L"ksize" ;
			value = GetConfigValue( this->nUpDnPreGaussianBlurKSize ) ;
			settings->Add( key, value ); 

			// Histogram equal
			key = L"hist_equal";
			value = GetConfigValue( this->cbPreHistEqualize );
			settings->Add( key, value ); 

			// Adaptive threshold
			key = L"adap_thresh";
			value = GetConfigValue( this->cbPreAdaptiveThreshold );
			settings->Add( key, value ); 

			key = L"bsize";
			value = GetConfigValue( this->nUpDnPreAdaptiveThresholdBSize );
			settings->Add( key, value ); 

			key = L"binary";
			value = GetConfigValue( this->cbPreBinary );
			settings->Add( key, value ); 

			key = L"binary_thresh";
			value = GetConfigValue( this->nUpDnPreBinaryThreshold );
			settings->Add( key, value ); 

			key = L"canny";
			value = GetConfigValue( this->cbPreCanny );
			settings->Add( key, value ); 

			key = L"ap_size";
			value = GetConfigValue( this->nUpDnPreCannyApSize ) ;
			settings->Add( key, value ); 

			key = L"canny_thresh" ;
			value = GetConfigValue( this->nUpDnPreCannyThresh2 ); 
			settings->Add( key, value ); 

			key = L"DIC";
			value = GetConfigValue( this->rbDic );
			settings->Add( key, value ); 

			key = L"NCC";
			value = GetConfigValue( this->rbNcc );
			settings->Add( key, value );

			key = L"coeff_norm";
			value = GetConfigValue( this->cbCoeffNorm );
			settings->Add( key, value ); 

			key = L"scale_factor";
			value = this->tbScaleFactor->Text;
			settings->Add( key, value ); 

			key = L"dist";
			value = GetConfigValue( this->nUpDnFeatureDistance );
			settings->Add( key, value ); 

			key = L"dpi";
			value = GetConfigValue( this->nUpDnDPI );
			settings->Add( key, value ); 

			key = L"focal_length";
			value = L"" + this->nUpDnFocalLength->Value;
			settings->Add( key, value );  

			key = L"dft";
			value = GetConfigValue( this->rbChartDft );
			settings->Add( key, value ); 

			key = L"fft";
			value = GetConfigValue( this->rbChartFft );
			settings->Add( key, value ); 

			key = L"high_pass_filter";
			value = GetConfigValue( this->cbHighPassFilter );
			settings->Add( key, value ); 

			key = L"high_pass_filter_hz";
			value = GetConfigValue( this->nUpDnHighPassFilterHz );
			settings->Add( key, value );

			key = L"low_pass_filter";
			value = GetConfigValue( this->cbLowPassFilter );
			settings->Add( key, value ); 

			key = L"low_pass_filter_hz";
			value = GetConfigValue( this->nUpDnLowPassFilterHz );
			settings->Add( key, value );

			config->Save(ConfigurationSaveMode::Modified); 
			//config->Save(ConfigurationSaveMode::Full);

			ConfigurationManager::RefreshSection( "appSettings" );

			System::String^ title = "Success"; 
			System::String^ msg = L"Configuration file has been saved." ; 
			System::Windows::Forms::MessageBox::Show( msg, title, MessageBoxButtons::OK, MessageBoxIcon::Information ) ;

			showMsg( L"Done Saving Config." );
		}

		virtual void showUiStatus() {
			VisionSystem * vs = this->visionSystem;

			const int camCount = vs->camCount;
			const int camDevId = vs->camDevId;

			const bool camEnable = camCount > 0 ; 
			const size_t openFileNameLen = vs->openFileName.length() ;  

			const bool disableMode = ( openFileNameLen == 0 ) && ( ! camEnable ) ; 

			const VisionInterface::PlayMode playMode = disableMode ? VisionInterface::PlayMode::CAM_DISABLED : vs->playMode ;
			const VisionInterface::RecordMode recordMode = disableMode ? VisionInterface::RecordMode::NO_RECORD : vs->recordMode ;  

			const bool isPlayMode = ( VisionInterface::PlayMode::PLAY == playMode );

			const bool isPauseMode = ( VisionInterface::PlayMode::PAUSE == playMode );

			const bool isStopMode = ( VisionInterface::PlayMode::STOP == playMode );

			const bool isRecording = ( VisionInterface::RecordMode::RECORD == recordMode ) ; 
			
			this->tsVideoCamDev->Enabled = ( camEnable && isStopMode ) ;
			this->tsVideoCamDevLbl->Text = ( ( camDevId >= 0 ) ? ( "" + camDevId ) : "x" );

			if( vs->getCameraCount() < 1 ) {
				tsVideoCamDevLbl->ToolTipText = L"Camera device not found" ;
				tsVideoCamDev->ToolTipText = L"Camera device not found" ;
			}

			this->tsVideoPlay->Enabled = ( isStopMode || isPauseMode ) ;
			this->tsVideoStop->Enabled = ( isPlayMode || isPauseMode ) ;
			this->tsVideoRecord->Enabled = isPlayMode ;
			this->tsVideoPause->Enabled = ( isPlayMode || isPauseMode ) ; 

			this->tsVideoPlay->ToolTipText = ( isPauseMode ) ? L"Replay" : L"Play" ;  

			this->tsVideoPause->Image = ( isPauseMode  ) ? this->extRscForm->pbVideoPlay->Image : this->extRscForm->pbVideoPause->Image ; 
			this->tsVideoPause->ToolTipText = ( isPauseMode ) ? L"Replay" : L"Pause" ;  

			if( this->tsVideoRecord->Enabled ) { 
				Image^ image = extRscForm->cam_norecord->Image; 
				System::String^ tooltipText = L"No record" ;
				if( recordMode == VisionInterface::RecordMode::RECORD ) {
					image = extRscForm->cam_record->Image;
					tooltipText = L"Record" ;
				} 
				this->tsVideoRecord->Image = image ;
				this->tsVideoRecord->ToolTipText = tooltipText ;
			} else {
				Image^ image = extRscForm->cam_norecord->Image;   
				System::String^ tooltipText = L"No record" ;
				this->tsVideoRecord->Image = image ;
				this->tsVideoRecord->ToolTipText = tooltipText ;
			}

			this->tsVideoForward->Enabled = ( isPlayMode && (openFileNameLen > 0) );
			this->tsVideoBackward->Enabled = ( isPlayMode && (openFileNameLen > 0)  );

			this->tsVideoFileOpen->Enabled = ( playMode == VisionInterface::PlayMode::CAM_DISABLED || isStopMode );
			this->miVideoOpen->Enabled = this->tsVideoFileOpen->Enabled ;
			this->miVideoSave->Enabled = isPlayMode || isPauseMode  ;

			if( this->tsVideoPlay->Enabled ) {
				this->animateGetFrame( NULL );
				this->animateImgPrcs( NULL );
			} else {
				this->animateImgPrcs( ( vs->isImgPrcs ) ? ( &  vs->videoInfo ) : NULL ) ; 
			}

			if( isStopMode ) {
				this->showMoviePlayInfo( NULL ) ;
				this->pbVideo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbVideo.Image")));
			}

			if( isRecording && isPlayMode ) {
				this->pbVideoRecording->Image = extRscForm->pbVideoRecording->Image;
			} else {
				this->pbVideoRecording->Image = extRscForm->pbVideoRecordingStop->Image;
			}

			if( isStopMode ) {
				this->tbDispPixX->Text = "" ;
				this->tbDispPixY->Text = "" ; 
			} 

			const bool targetFixed = vs->visionMatch.IsTargetFixed() ;
			const bool targetNotFixed = ! targetFixed ; 

			this->cbMatchTargetFix->Enabled = isPlayMode || isPauseMode ; 

			this->cbMatchTargetFix->Checked = targetFixed ;

			this->nUpDnFps->Enabled = ! isPlayMode ; 

			this->nUpDnFeatureDistance->Enabled = targetNotFixed ; 

			this->nUpDnDPI->Enabled = false ; 

			this->nUpDnFocalLength->Enabled = targetNotFixed ;   

			this->btnChartDataSave->Enabled = ( ( targetNotFixed || isPauseMode || isStopMode ) && this->visionChartDisp->GetSampleDataCnt() > 0 ) ;  

			this->tbVideoCurrFramePos->Enabled = openFileNameLen > 0 ; 

			if( isPlayMode && targetFixed ) { 
				this->pbChartPrcs->Image = this->extRscForm->pbChartPrcs->Image ; 
			} else {
				this->pbChartPrcs->Image = this->extRscForm->pbChartPrcsStop->Image ; 
			}

			this->cbMatchTargetFix->Image = targetFixed ? extRscForm->pbTargetFix->Image : extRscForm->pbTargetUnFix->Image ; 
		}

	   virtual void animateGetFrame( VideoInfo * videoInfo ) {

		   Control::ControlCollection^ controls = this->extRscForm->camDevAniPanel->Controls ;  

		   int count = controls->Count ;
		   if( count < 1 ) {
			   return ; 
		   } 

		   int idx = 0 ;

		   if( NULL != videoInfo ) {
			   int frameCnt = this->aniFrameCnt ++ ; 
			   int fps = videoInfo->fps;

			   int diffMiliSec = 1000*frameCnt/fps;

			   idx = ( diffMiliSec/100 ) ;

			   //this->showMsg( L"idx = " + idx );

			   int dir = (idx/count)%2  ;

			   idx = idx%count ; 

			   if( dir == 1 ) {  
				   idx = count - idx - 1;
			   } 			   
		   } else {
			   this->aniFrameCnt = 0 ;
		   }

		   Control^ ctrl = controls[ idx ];

		   PictureBox^ pb = (PictureBox^) ctrl ; 

		   this->pbVideoGetFrameAni->Image = pb->Image; 
	   }

	   virtual void animateImgPrcs( VideoInfo * videoInfo ) {
		   if( NULL != videoInfo ) {
			   Image^ image = this->extRscForm->gif_load_01->Image;
			   this->pbImgPrcsAni->Image = image; 
		   } else {
			   Image^ image = this->extRscForm->gif_load_01_stop->Image;
			   this->pbImgPrcsAni->Image = image; 
		   }		   
	   }

	   virtual bool isShowPrcsInfoOnImage() {
		   return cbShowPrcsInfoOnImage->Checked;
	   }

	   virtual bool isCheckBoxEnabledChecked( System::Windows::Forms::CheckBox^ cb ) {
		   return cb->Enabled && cb->Checked ;
	   } 

	   virtual bool isPreGaussianBlur() {
		   return this->isCheckBoxEnabledChecked( this->cbPreGaussianBlur ) ;
	   }

	   virtual int getPreGuassianBlurKSize() {
		   return (int) this->nUpDnPreGaussianBlurKSize->Value;
	   }

	   virtual bool isPreHistEqualize() {
		   return this->isCheckBoxEnabledChecked( this->cbPreHistEqualize ) ;
	   }

	   virtual bool isPreBinary() {
		   return this->isCheckBoxEnabledChecked( this->cbPreBinary );
	   }

	   virtual bool isPreAdaptiveThreshold() {
		   return this->isCheckBoxEnabledChecked( this->cbPreAdaptiveThreshold );
	   }

	   virtual int getPreAdaptiveThresholdBSize() {
		   return (int) this->nUpDnPreAdaptiveThresholdBSize->Value ;
	   }

	   virtual int getPreBinaryThreshold() {
		   return (int) this->nUpDnPreBinaryThreshold->Value ;
	   }

	   virtual CannyOption * getPreCannyOption() {

		   bool isCanny = this->isCheckBoxEnabledChecked( this->cbPreCanny );

		   cannyOption->isCanny = isCanny ;
		   cannyOption->apertureSize = (int) this->nUpDnPreCannyApSize->Value ;
		   cannyOption->threshold_02 = (int) this->nUpDnPreCannyThresh2->Value ;

		   return cannyOption;
	   }

	   virtual bool showMatchMinValue() {
		   return this->cbShowMatchMinValue->Checked ; 
	   }

	   virtual bool showMatchMaxValue() {
		   return this->cbShowMatchMaxValue->Checked ; 
	   }

	   virtual bool isFft() {
		   return this->rbChartFft->Checked ;
	   }

	   virtual void ProcessMatchResult( MatchResult * matchResult, VideoInfo * videoInfo ) {

		   char text[ 200 ]; 

		   this->showMsg( L"✽ Sampling now ... " ) ;

		   this->pbChartPrcs->Image = this->extRscForm->pbChartPrcs->Image ; 

		   if( nullptr != matchResult ) { 
			   Disp * disp = matchResult->GetDisp();

			   const int dxPixel = (int) disp->GetDxPixel() ;
			   const int dyPixel = (int) disp->GetDyPixel() ;

			   const double dx_mm =   disp->GetDxMeter()*1000;
			   const double dy_mm = - disp->GetDyMeter()*1000;

			   const double currSampleTimeSec = ( this->visionChartDisp->GetSampleDataCnt() + 1)/(videoInfo->fps + 0.0) ;

			   // show curr sample time sec
			   sprintf_s( text, "%.3f", currSampleTimeSec ); 
			   this->tbMatchPrcsTimeSum->Text = gcnew System::String( text ) ;

			   // show displacement in pixel unit on UI
			   sprintf_s( text, "%+03d", dxPixel ) ; 
			   this->tbDispPixX->Text = gcnew System::String( text ) ;
		   
			   sprintf_s( text, "%+03d", dyPixel ) ; 
			   this->tbDispPixY->Text = gcnew System::String( text ) ;

			   // show dx displacement in mm unit on UI
			   sprintf_s( text, "%+.1f", dx_mm ) ; 
			   this->tbDispGeoX->Text = gcnew System::String( text ) ;

			   // show dy displacement in mm unit on UI
			   sprintf_s( text, "%+.1f", dy_mm ); 
			   this->tbDispGeoY->Text = gcnew System::String( text ) ; 

			   if( true ) { 
				   // set x-axis interval according to the time seconds 
				   int dispXAxisCurrTimeSec = (int)( currSampleTimeSec + 0.5 ) ; 

				   double dispXAxisInterval = 3;
				   const int intervalCnt = 20; // scale count
				   if( dispXAxisCurrTimeSec <= 1.0 ) {
					   dispXAxisInterval = 0.4;
				   } else if( dispXAxisCurrTimeSec < 3 ) {
					   dispXAxisInterval = 1 ;
				   } else if( dispXAxisCurrTimeSec < 14 ) {
					   dispXAxisInterval = 1 ;
				   } else if( dispXAxisCurrTimeSec < 37 ) {
					   dispXAxisInterval = 2 ;
				   } else if( dispXAxisCurrTimeSec < 64 ) {
					   dispXAxisInterval = 5 ;
				   } else if( dispXAxisCurrTimeSec < 3604 ) {
					   dispXAxisInterval = 15 ;
				   } else {
					   dispXAxisInterval = 60 ;
				   }

				   if( dispXAxisInterval != this->preVisionChartDispXAxisInterval ) {
					   // reset the axis interval of vision chart displacement only
					   this->preVisionChartDispXAxisInterval = (int) dispXAxisInterval;

					   this->visionChartDisp->SetXAxisInt( dispXAxisInterval );
				   }
			   }

			   if( true ) {
				   // frequency chart x-axis interval calibration 

				   int freqXAxisInterval = 5 ;  
				   const int showMaxFreq = videoInfo->fps/2 ;  

				   if( this->visionChartFreq->GetSampleDataCnt() < 2 ) {
					   freqXAxisInterval = 1 ;
				   } else if( showMaxFreq < 10 ) {
					   freqXAxisInterval = 1 ; 
				   } else if( showMaxFreq < 100 ) {
					   freqXAxisInterval = 1 ; 
				   } else if( showMaxFreq < 1000 ) {
					   freqXAxisInterval = 5 ; 
				   }

				   if( freqXAxisInterval != this->preVisionChartFreqXAxisInterval ) {
					   this->preVisionChartFreqXAxisInterval = freqXAxisInterval ; 
					   this->visionChartFreq->SetXAxisInt( freqXAxisInterval );
				   }
			   }
		   } 

		   // current time in mili seconds
		   const int then = GetTickCount(); 

		   this->visionChartDisp->ProcessMatchResult( matchResult, videoInfo, this ) ;
		   this->visionChartFreq->ProcessMatchResult( matchResult, videoInfo, this ) ;

		   double xMaxAmpFreq = this->visionChartFreq->GetXMaxAmpFreq() ;
		   double yMaxAmpFreq = this->visionChartFreq->GetYMaxAmpFreq() ;

		   sprintf_s( text, "%0.2f", xMaxAmpFreq );
		   this->tbChartXMaxAmpFreq->Text = gcnew System::String( text ) ;

		   sprintf_s( text, "%0.2f", yMaxAmpFreq );
		   this->tbChartYMaxAmpFreq->Text = gcnew System::String( text ) ; 

		   if( this->visionChartDisp->GetSampleDataCnt() != this->visionChartFreq->GetSampleDataCnt() ) {
			   // show error message if the sampling count of displacement chart is different to the one of frequency chart
			   System::String^ title = "Something Wrong"; 
			   System::String^ msg = L"The sampling count of displacement-chart is different to the one of frequency-chart." ; 
			   System::Windows::Forms::MessageBox::Show( msg, title, MessageBoxButtons::OK, MessageBoxIcon::Error ) ;
		   }

		   if( ! this->cbChartDispSeriesX->Enabled ) {
			   bool b = true; 

			   this->cbChartDispSeriesX->Enabled = b;
			   this->cbChartDispSeriesY->Enabled = b;
			   this->cbChartFreqSeriesX->Enabled = b;
			   this->cbChartFreqSeriesY->Enabled = b;
		   }

		   const int samplingCount = this->visionChartFreq->GetSampleDataCnt() ;   

		   bool freqUnitSet = samplingCount < 3 ;  

		   if( freqUnitSet ) {  
			   const int fps = videoInfo->fps ; 
			   const double maxFreq = samplingCount > 1 ? fps/2.0 : fps ;  

			   sprintf_s( text, "Hz [max=%.1f]", maxFreq );

			   this->lblChartFreqHorAxisTitle->Text = gcnew System::String( text );   
		   }

		   this->tbChartSampleDataCnt->Text = ( L"" + this->visionChartDisp->GetSampleDataCnt() );

		   const int now = GetTickCount(); 
		   this->tbChartPrcsTime->Text = ( L"" + ( now - then ) ); 

		   // end of processing match result
	   }

	   virtual void InitChart() {
		   // init chart 
		   this->preVisionChartDispXAxisInterval = -1 ;
		   this->preVisionChartFreqXAxisInterval = -1 ;

		   this->visionChartDisp->InitChart();
		   this->visionChartFreq->InitChart();

		   bool b = false;
		   this->btnChartDataSave->Enabled = b ; 

		   this->cbChartDispSeriesX->Enabled = b;
		   this->cbChartDispSeriesY->Enabled = b;
		   this->cbChartFreqSeriesX->Enabled = b;
		   this->cbChartFreqSeriesY->Enabled = b;

		   this->lblChartFreqHorAxisTitle->Text = L"Hz";

		   // end of init chart
	   }

	   virtual double GetHighPassFilterHz() {
		   if( this->cbHighPassFilter->Checked ) {
			   return (double) ( this->nUpDnHighPassFilterHz->Value ) ; 
		   }
		   return 0 ;
	   }

	   virtual double GetLowPassFilterHz() {
		   if( this->cbLowPassFilter->Checked ) {
			   return (double) ( this->nUpDnLowPassFilterHz->Value ) ;
		   }
		   return 0 ; 
	   }

	   virtual void InitVisionMatchData() {
		   VisionSystem * vs = this->visionSystem ; 

		   bool locInit = true ; // location init 

		   vs->visionMatch.InitRoiData( locInit ); 

		   this->pbTarget->Image = this->extRscForm->pbTarget->Image ;
	   }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

			ToolStripSplitButton^  tsVideoCamDev = this->tsVideoCamDev;
			int camCount = visionSystem->getCameraCount();
			tsVideoCamDev->DropDownItems->Clear(); 

			for( int i = 0 , iLen = camCount ; i < iLen ; i ++ ) {
				ToolStripMenuItem^  tsMenuItemCam = (gcnew System::Windows::Forms::ToolStripMenuItem());
				System::String^ name = L"tsMenuItemCam_" ;
				name += i;
				tsMenuItemCam->Name = name; 
				tsMenuItemCam->Size = System::Drawing::Size(152, 22);

				System::String^ text = L"Camera: " ;
				text += i ;

				tsMenuItemCam->Text = text;

				tsMenuItemCam->Click += gcnew System::EventHandler(this, &VisionWinForm::tsMenuItemCam_Click);

				tsVideoCamDev->DropDownItems->Add( tsMenuItemCam );
			}

			VisionSystem * vs = this->visionSystem;

			vs->camDevId = (camCount> 0 ) ? 0 : -1;
			vs->playMode = (camCount> 0 ) ? VisionInterface::PlayMode::STOP : VisionInterface::PlayMode::CAM_DISABLED  ; // stopped

			if( true ) {
				// DPI check
				HDC hdc = GetDC(NULL); 
				 
				int dpiX = GetDeviceCaps(hdc, LOGPIXELSX);
				int dpiY = GetDeviceCaps(hdc, LOGPIXELSY);
				ReleaseDC(NULL, hdc); 

				int dpi = dpiX;
				if( dpi < this->nUpDnDPI->Minimum ) {
					this->nUpDnDPI->Minimum = dpi;
				}
				if( dpi > this->nUpDnDPI->Maximum ) {
					this->nUpDnDPI->Maximum = dpi;
				}

				this->nUpDnDPI->Value = dpi ;

				if( false ) { 
					System::String^ msg = L"DPIX: " + dpiX + "; DPIY : " + dpiY ;
					this->showMsg( msg ); 
				}
			}

			this->SetScaleFactor();

			bool openConfigOnWindowsLoad = false;
			if( openConfigOnWindowsLoad ) {  
				this->ConfigFileOpen( "" );
			}

			if( camCount == 1 ) {  
				this->showMsg( L"(^‿^)  Ready" );
			} else if( camCount > 0 ) {  
				this->showMsg( L"(^‿^)  Ready: Camera (" + camCount + ") found" );
			} else if( camCount < 1 ) {  
				this->showMsg( L"( •_•)  Not Ready: Camera not found!" );

				System::Windows::Forms::MessageBox::Show( L"Cannot find a camera device available.", L"N0 CAMERA", 
					MessageBoxButtons::OK, MessageBoxIcon::Error ) ;
			}

			this->InitChart();

			this->showUiStatus(); 
		}

	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }

	private: System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }

	private: System::Void tsVideoPlayBtn_Click(System::Object^  sender, System::EventArgs^  e) { 
				 videoPlayBtn_Click();
			 }

	private: System::Void videoPlayBtn_Click() {
				 VisionSystem * vs = this->visionSystem ;

				 this->timerIntervalCalibCnt = 0 ; 

				 if( VisionInterface::PlayMode::STOP == vs->playMode ) { 
					 // init chart when the previous play mode is stop-mode.
					this->InitChart();
				 }

				 VisionInterface::PlayMode playMode = VisionInterface::PlayMode::PLAY ;

				 vs->setPlayMode( playMode );

				 if( true ) { 
					 // sync timer interval to the fps
					 int fps = this->GetFps();

					 double interval = 1000.0/(fps + 0.0);

					 this->videoTimer->Interval = (int)( interval ); 
				 }

				 this->videoTimer->Enabled = true;

				 this->showUiStatus();
			 }

	private: System::Void videoTimer_Tick(System::Object^  sender, System::EventArgs^  e) { 

				 if( timerOn ) {
					 return;
				 }

				 timerOn = true;

				 if( this->videoPause ) { 
					 this->doVideoPauseOnTimer(); 
					 this->videoPause = false ;  
					 timerOn = false ; 

					 videoTimer->Enabled = false ; 
					 return ; 

				 } else if( this->videoStop ) {
					 this->doVideoStopOnTimer(); 
					 this->videoStop = false ;  
					 timerOn = false ;  

					 videoTimer->Enabled = false ; 
					 return ; 
				 }

				 if( false == timerOn ) {
					 return; 
				 }

				 const int now = GetTickCount() ; 

				 const int interval = 1000/this->GetFps() ;

				 const int currInterval = now - timerThen ; 

				 bool debug = true ;

				 if( currInterval < interval ) {

					 timerOn = false ; 

					 // timer interval calibration
					 int diffInterval = interval - currInterval ;

					 diffInterval = diffInterval > 0 ?  diffInterval : 1 ; 

					 this->videoTimer->Interval = diffInterval ; 

					 // end of calibrating timer interval

					 this->timerIntervalCalibCnt ++ ; 

					 if( debug ) {
						 System::String^ msg = L"Timer interval [" + timerIntervalCalibCnt + "] was calibrated to " + ( diffInterval ) ; 
						 showMsg( msg );
					 }

					 return ; 
				 } 

				 if( interval != this->videoTimer->Interval )  {
					 // synchronize video timer interval 
					 this->videoTimer->Interval = interval ; 

					 if( debug ) {
						 System::String^ msg = L"Timer interval [" + timerIntervalCalibCnt + "] was synchronized to " + interval ; 
						 showMsg( msg );
					 }
				 } 

				 timerThen = now;

				 timerCnt ++; 

				 VisionSystem * vs = this->visionSystem ; 

				 if( vs->GetFrame( this ) ) { 

					const bool prcsImgRslt = vs->ProcessImage( this ) ;

					animateGetFrame( & vs->videoInfo );

					vs->PaintImage( this );

					if( prcsImgRslt != prePrcsImgRslt ) {
						if( prcsImgRslt ) {
							this->animateImgPrcs( & vs->videoInfo );
						} else {
							this->animateImgPrcs( NULL );
						}
					}

					this->prePrcsImgRslt = prcsImgRslt ;  

				 } else {
					// if failed to get a video frame
					 if( VisionInterface::VideoSrc::FILE == visionSystem->videoSrc ) {
						 // if failed to get a video frame from file
						 if( vs->videoInfo.isEndPos() ) { 
							 // pause video play
							 videoPause_Click( );

							 this->tbVideoCurrFramePos->Value = this->tbVideoCurrFramePos->Maximum ;

							 showMsg( "End of video file. Video playing stopped." ); 
						 } else {
							 // if not the end of file.
							 // some video file failed to get frame in the middle of file.
							 videoPause_Click( );

							 VideoInfo * videoInfo = & vs->videoInfo ; 
							 int totFrameCnt = videoInfo->totFrameCnt ; 
							 if( totFrameCnt > 0 ) {   
								 this->tbVideoCurrFramePos->Value = this->tbVideoCurrFramePos->Maximum ;

								 int frameCnt = videoInfo->GetFrameCnt(); 

								 System::String^ msg = L"Video Pause: ㅠ..ㅠ Failed to get a video frame at the position: curr/tot = " + frameCnt + "/" + totFrameCnt ;
								 showMsg( msg );
							 } else { 
								 this->tbVideoCurrFramePos->Value = this->tbVideoCurrFramePos->Maximum ;

								 System::String^ msg = L"Video Pause: ㅠ..ㅠ Failed to get a video frame." ;
								 showMsg( msg );
							 }
						 }
					 } else {
						 // if failed to get a video frame from the camera device.
						 // do not pause the video capturing from the camera.
						 // Live camera failed to get a frame sometimes.
						 // videoPause_Click( );

						 showMsg( "ㅠ..ㅠ Failed to get a video frame of the camera." );
					 }
				 }

				 timerOn = false;
			 }

	private: System::Void lblPlayTotTime_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			} 

	private: System::Void pbVideo_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) { 
			 }

	private: System::Void tsVideoCamDev_ButtonClick(System::Object^  sender, System::EventArgs^  e) {

				 VisionSystem * vs = this->visionSystem ; 

				 vs->openFileName = "" ; 

				 this->showMsg( L"플레이 버튼을 클릭하면 카메라 영상을 출력합니다." );
			 }

	private: System::Void tsMenuItemCam_Click(System::Object^  sender, System::EventArgs^  e) {

				 this->tsVideoPlay->Enabled = false ; 

				 ToolStripMenuItem^  mi = (ToolStripMenuItem^) sender; 

				 System::String^ text = mi->Text;

				 int idx = text->LastIndexOf( " " );

				 System::String^ numText = text->Substring( idx + 1 );

				 this->tsVideoCamDevLbl->Text = numText;

				 int camDevId = System::Convert::ToInt32( numText );
				 
				 VisionSystem * vs = this->visionSystem ; 

				 vs->visionMatch.InitRoiData( true );

				 vs->openFileName = "";

				 vs->camDevId = camDevId;

				 // set fps as default value 30 when select a camera device.
				 // this->SetFps( 30 );

				 this->videoPlayBtn_Click();

				 this->tsVideoPlay->Enabled = true ; 

				 System::String^ msg = L"Selected Cam device id: " + camDevId ;

				 this->showMsg( msg );

				 this->showUiStatus();

				

			 }

	private: System::Void tsVideoStop_Click(System::Object^  sender, System::EventArgs^  e) { 
				 this->videoStop = true ; 

				 this->tsVideoStop->Enabled = false ;  

				 VisionSystem * vs = this->visionSystem ; 

				 if( VisionInterface::PlayMode::PAUSE == vs->playMode ) {
					 doVideoStopOnTimer();
				 }
			 }

	private: System::Void doVideoStopOnTimer() {

				 this->showMsg( "Video Stop On Timer." );

				 this->videoStop = false ; 

				 this->videoTimer->Enabled = false;

				 VisionSystem * vs = this->visionSystem ; 

				 this->InitVisionMatchData();

				 VisionInterface::PlayMode playMode = VisionInterface::PlayMode::STOP ;

				 vs->setPlayMode( playMode ) ; 

				 this->tsVideoStop->Enabled = true ; 

				 this->showUiStatus();
			 }

	private: System::Void tsVideoPause_Click(System::Object^  sender, System::EventArgs^  e) {
				  this->tsVideoPause->Enabled = false ;

				 videoPause_Click();
			 }

	private: System::Void videoPause_Click() { 
				 this->tsVideoPause->Enabled = false ;

				 VisionSystem * vs = this->visionSystem ; 

				 if( VisionInterface::PlayMode::PLAY == vs->playMode ) {  
					 // if current mode is play mode
					 this->videoPause = true;
				 } else if( VisionInterface::PlayMode::PAUSE == vs->playMode ) { 
					 // if current mode is pause mode
					 videoPlayBtn_Click();
				 }
			 }

	private: System::Void doVideoPauseOnTimer() {
				 // video pause function
				 this->videoPause = false ; 
				 this->videoTimer->Enabled = false; 

				 VisionInterface::PlayMode playMode = VisionInterface::PlayMode::PAUSE ;

				 VisionSystem * vs = this->visionSystem ; 

				 vs->setPlayMode( playMode ) ;

				 this->showUiStatus();
			 }

	private: System::Void tsVideoRecord_Click(System::Object^  sender, System::EventArgs^  e) {
				 videoFileSave();
			 }

	private: System::Void videoFileSave() {  
				 System::Windows::Forms::SaveFileDialog^ d = this->videoSaveFileDialog;

				 d->Filter = "Video|*.mpg;*.avi;*.mpeg";
				 d->Title = L"Enter file name or select a video file to overwrite!"; 

				 System::String^ fileName = nullptr ; 

				 if ( d->ShowDialog( this ) == System::Windows::Forms::DialogResult::OK ) {
					 fileName = d->FileName ;
					 showMsg( "Video file to save : " + fileName );
				 }

				 if( nullptr == fileName || fileName->Trim()->Length < 1 ) {
					 return;
				 }

				 std::string recordFileName = "";

				 this->MarshalString( fileName, & recordFileName ); 

				 VisionSystem * vs = this->visionSystem ; 

				 vs->recordFileName = recordFileName;

				 VisionInterface::RecordMode recordMode = vs->recordMode ;

				 recordMode = ( recordMode == VisionInterface::RecordMode::RECORD ) ? VisionInterface::RecordMode::NO_RECORD : VisionInterface::RecordMode::RECORD ;

				 vs->setRecordMode( recordMode, this );

				 this->showUiStatus(); 
			 }

	private: System::Void tsVideoFileOpen_Click(System::Object^  sender, System::EventArgs^  e) {
				 videoFileOpen();
			 }

	private: System::Void videoFileOpen() { 

				 System::Windows::Forms::OpenFileDialog^ d = this->videoOpenFileDialog;

				 d->Filter = "Video|*.mpg;*.avi;*.mpeg";
				 d->Title = L"Select a Video File"; 

				 System::String^ fileName = nullptr;

				 if ( d->ShowDialog( this ) == System::Windows::Forms::DialogResult::OK ) {
					 fileName = d->FileName ;
					 showMsg( "Video file selected : " + fileName );
				 }

				 if( nullptr == fileName || fileName->Trim()->Length < 1 ) {
					 return;
				 }

				 this->InitChart();

				 this->InitVisionMatchData();

				 std::string text ;

				 MarshalString( fileName, & text );

				 VisionSystem * vs = this->visionSystem ; 

				 vs->openFileName = text ; 

				 videoPlayBtn_Click();
				  
			 }  

private: System::Void cbPreHistEqualize_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				visionSystem->visionMatch.RebuildTarget() ;
			}

private: System::Void cbPreGaussianBlur_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {

			 bool b = this->cbPreGaussianBlur->Checked ;

			 this->nUpDnPreGaussianBlurKSize->Enabled = b;

			 visionSystem->visionMatch.RebuildTarget() ;
		}

private: System::Void nUpDnPreGaussianBlurKSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			  visionSystem->visionMatch.RebuildTarget()  ;
		}

private: System::Void nUpDnPreBinaryThreshold_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 visionSystem->visionMatch.RebuildTarget() ;
		}

private: System::Void cbPreAdaptiveThreshold_CheckedChanged(System::Object^  sender, System::EventArgs^  e) { 

			 bool b = this->cbPreAdaptiveThreshold->Checked;

			 this->nUpDnPreAdaptiveThresholdBSize->Enabled = b ;

			 visionSystem->visionMatch.RebuildTarget() ;
		}

private: System::Void nUpDnPreAdaptiveThresholdBSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 visionSystem->visionMatch.RebuildTarget() ;
		}

private: System::Void cbPreCanny_CheckedChanged(System::Object^  sender, System::EventArgs^  e) { 

			 bool b = this->cbPreCanny->Checked ;

			 this->nUpDnPreCannyApSize->Enabled = b;
			 this->nUpDnPreCannyThresh2->Enabled = b ;

			 b = ! b ;

			 this->cbPreAdaptiveThreshold->Enabled = b ;
			 this->nUpDnPreAdaptiveThresholdBSize->Enabled = b;

			 this->cbPreBinary->Enabled = b;
			 this->nUpDnPreBinaryThreshold->Enabled = b;

			 visionSystem->visionMatch.RebuildTarget() ;

		 }

private: System::Void nUpDnPreCannyApSize_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 visionSystem->visionMatch.RebuildTarget() ;
		}

private: System::Void nUpDnPreCannyThresh2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 visionSystem->visionMatch.RebuildTarget() ;
		 }

private: System::Void cbPreBinary_CheckedChanged(System::Object^  sender, System::EventArgs^  e) { 
			 bool b = this->cbPreBinary->Checked ; 

			 this->nUpDnPreBinaryThreshold->Enabled = b;

			 visionSystem->visionMatch.RebuildTarget() ;
		 }	 

private: System::Void pbVideo_MouseEnter(System::Object^  sender, System::EventArgs^  e) { 
			 visionSystem->OnMouseEvent( VisionInterface::MouseEvent::ENTER, -1, -1 , this );  
		 }

private: System::Void pbVideo_MouseLeave(System::Object^  sender, System::EventArgs^  e) { 
			 visionSystem->OnMouseEvent( VisionInterface::MouseEvent::LEAVE, -1, -1, this );  
		 }

private: System::Void pbVideo_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { 
			 mouseDown = true;

			 visionSystem->OnMouseEvent( VisionInterface::MouseEvent::DOWN, e->X, e->Y , this );  
		 }

private: System::Void pbVideo_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 if( mouseX != e->X && mouseY != e->Y ) {  
				 if( mouseDown ) { 
					visionSystem->OnMouseEvent( VisionInterface::MouseEvent::DRAG, e->X, e->Y, this );   
				 } else {
					visionSystem->OnMouseEvent( VisionInterface::MouseEvent::MOVE, e->X, e->Y, this );
				 }
				 mouseX = e->X;
				 mouseY = e->Y;
			 } else {
				 
			 }
		 }

private: System::Void pbVideo_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

  			 visionSystem->OnMouseEvent( VisionInterface::MouseEvent::UP, e->X, e->Y, this ); 

			 mouseDown = false ; 
		 } 

private: System::Void pbVideo_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 
			 VisionSystem * vs = this->visionSystem ;

			 vs->OnMouseEvent( VisionInterface::MouseEvent::CLICK, e->X, e->Y, this ); 

			 mouseDown = false ; 
		 }

private: System::Void pbVideo_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { 
			 visionSystem->OnMouseEvent( VisionInterface::MouseEvent::DBL_CLICK, e->X, e->Y, this );  
		 }  

private: System::Void pbVideo_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void cbChartDispSeriesX_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 bool b = this->cbChartDispSeriesX->Checked;
			 this->visionChartDisp->SetSeriesEnabled( 0, b );
		 }
private: System::Void cbChartDispSeriesY_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 bool b = this->cbChartDispSeriesY->Checked;
			 this->visionChartDisp->SetSeriesEnabled( 1, b );
		 }
private: System::Void cbChartFreqSeriesX_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 bool b = this->cbChartFreqSeriesX->Checked;
			 this->visionChartFreq->SetSeriesEnabled( 0, b );
		 }
private: System::Void cbChartFreqSeriesY_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 bool b = this->cbChartFreqSeriesY->Checked;
			 this->visionChartFreq->SetSeriesEnabled( 1, b );
		 }
private: System::Void cbMatchTargetFix_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->cbMatchTargetFix->Enabled = false ; 

			 const bool fixed = this->cbMatchTargetFix->Checked ;

			 VisionSystem * vs = this->visionSystem ; 
			 vs->visionMatch.SetRoiFixed( fixed, this );

			 if( VisionInterface::PlayMode::PAUSE == vs->playMode ) {
				this->PaintVideo();
			 }

			 this->cbMatchTargetFix->Enabled = true ; 

			 this->showUiStatus();	

			 this->showMsg( L"The target is " + ( fixed ? "fixed." : "not fixed." ) );
		 } 
private: System::Void btnChartDataSave_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->btnChartDataSave->Enabled = false ; 

			 this->ChartDataSave();

			 this->btnChartDataSave->Enabled = true ; 
		 }

private: System::Void ChartDataSave() { 

			System::Windows::Forms::SaveFileDialog^ d = this->csvSaveFileDialog ; 

			d->Filter = "CSV|*.csv" ;

			d->Title = L"Enter file name or select a csv file to save the chart data!"; 
			 
			System::String^ fileName = nullptr ; 

			 if ( d->ShowDialog( this ) == System::Windows::Forms::DialogResult::OK) {
				 fileName = d->FileName ;

				 showMsg( "Chart data save on the file : " + fileName );
			 } 

			 if( nullptr == fileName || fileName->Trim()->Length < 1 ) {
				 return;
			 }

			 if( 1 == d->FilterIndex ) { 
				FileSaveCsv( fileName );
			 } 
		 }

private: System::Void FileSaveCsv(System::String^ fileName ) { 
			 // CSV file save
			 
			 StreamWriter^ sw = gcnew StreamWriter( fileName ); 

			 System::DateTime^ now = System::DateTime::Now;

			 ArrayList^ dxList = this->visionChartDisp->GetXSamples();
			 ArrayList^ dyList = this->visionChartDisp->GetYSamples();
			 
			 Aquila::SpectrumType xSpec = this->visionChartFreq->GetXSpectrumAll();
			 Aquila::SpectrumType ySpec = this->visionChartFreq->GetYSpectrumAll();

			 const size_t dxSize = dxList->Count;
			 const size_t fxSize = xSpec.size();

			 const size_t dataCnt = fxSize > dxSize ? fxSize : dxSize ;   

			 const size_t spectrumCnt = xSpec.size() ;
			 const int fps = this->visionChartFreq->GetFps() ;
			 const double maxFreq = fps ;
			 const double unitFreq = maxFreq/spectrumCnt ; 
			 const double sampleTimeSec = fps > 0 ? ( dxSize/(fps + 0.0 ) ) : 1 ; 

			 Aquila::ComplexType t;
			 Aquila::ComplexType & s = t  ;  

			 double timeSec ; 
			 double freq ; // frequency
			 double amp ;  // amplitude  

			 double imag;
			 double real;  

			 System::String^ str;
			 char dispText[ 400 ] ;
			 char fxText[ 400 ];
			 char fyText[ 400 ];

			 char text[ 1000 ];

			 int nowSec = now->Second; 

			 sw->WriteLine( L"Record, Date, Y" + (now->Year%100) + L"-" + now->Month + L"-" + now->Day + ", " + now->Hour + ":" + now->Minute + ":" + nowSec + "" );

			 sw->WriteLine( L"Disp,  Data, count ," + dxSize ) ; 
			 sw->WriteLine( L"Spectrum,  Data, count ," + fxSize ) ;
			 sw->WriteLine( L"movie, fps, " + fps ) ;
			 sw->WriteLine( L"sampling, time(s), " + sampleTimeSec ) ; 
			 sw->WriteLine( L"max, freq(Hz), " + maxFreq ) ; 
			 sw->WriteLine( L"unit, freq(Hz), " + unitFreq ) ;

			 sw->WriteLine( L"no, dx(mm), dy(mm), , time(sec), dx(mm), dy(mm), , fx(Hz), amp_x, real_x, img_x, ,fy(Hz), amp_y, real_y, img_y" ); 

			 int rowNo ; 
			 double dx_mm ;
			 double dy_mm ; 
			 for( size_t i = 0 , iLen = dataCnt ; i < iLen ; i ++ ) { 

				 rowNo = (int) ( i + 1 ) ; 
				 dx_mm = 0;
				 dy_mm = 0 ; 
				 timeSec = i/(fps + 0.0);

				 if( i < dxSize ) {
					 dx_mm = (double) ( dxList[ (int) i ] );
					 dy_mm = (double) ( dyList[ (int) i ] );
				 } 

				 sprintf_s( dispText, "%d, %f, %f, , %f, %f, %f ", rowNo, dx_mm, dy_mm , timeSec, dx_mm, dy_mm);

				 if( i < fxSize ) { 
					 freq = (maxFreq*i)/spectrumCnt ;   

					 s = xSpec.at( i ) ; 
					 imag = s.imag() ;
					 real = s.real() ;
					 amp = sqrt( imag*imag + real*real ) ;   

					 sprintf_s( fxText, "%f, %f, %f, %f" , freq, amp, real, imag );

					 s = ySpec.at( i ) ; 
					 imag = s.imag() ;
					 real = s.real() ;
					 amp = sqrt( imag*imag + real*real ) ;   

					 sprintf_s( fyText, "%f, %f, %f, %f" , freq, amp, real, imag );
				 } else {
					 sprintf_s( fxText, "  ,   ,   ,     " );
					 sprintf_s( fyText, "  ,   ,   ,     " );
				 }

				 sprintf_s( text, "%s, , %s, , %s", dispText, fxText, fyText );

				 str = gcnew System::String( text ) ;

				 sw->WriteLine( str );
			 }

			 sw->Close();

			 System::String^ title = L"Success";
			 System::String^ msg = L"The csv file has been saved.";

			 System::Windows::Forms::MessageBox::Show( msg, title, MessageBoxButtons::OK, MessageBoxIcon::Information ) ;
			 // End of saving as csv file.
		 }

private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 System::Drawing::Point^ loc = this->Location;
			 System::Drawing::Size^ size = this->Size;

			 AboutWinForm^ aboutWinForm = gcnew AboutWinForm(); 

			 int x = loc->X + (size->Width - aboutWinForm->Size.Width)/2;
			 int y = loc->Y + (size->Height - aboutWinForm->Size.Height)/2;

			 aboutWinForm->Location.X = x;
			 aboutWinForm->Location.Y = y;

			 aboutWinForm->Show( this );

			 x = loc->X + (size->Width - aboutWinForm->Size.Width)/2;
			 y = loc->Y + (size->Height - aboutWinForm->Size.Height)/2;

			 aboutWinForm->Location.X = x;
			 aboutWinForm->Location.Y = y;
		 } 

private: System::Void miVideoOpen_Click(System::Object^  sender, System::EventArgs^  e) {
			 videoFileOpen();
		 }

private: System::Void nUpDnFeatureDistance_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->SetScaleFactor();
		 }
private: System::Void nUpDnDPI_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->SetScaleFactor();
		 }
private: System::Void nUpDnFocalLength_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->SetScaleFactor();
		 } 
private: System::Void tsVideoForward_Click(System::Object^  sender, System::EventArgs^  e) {
			 VisionSystem * vs = this->visionSystem ;

			 vs->PlayForward( this );

			 this->showMsg( "Play forward by 10 seconds." );
		 }
private: System::Void tsVideoBackward_Click(System::Object^  sender, System::EventArgs^  e) {
			 VisionSystem * vs = this->visionSystem ;

			 vs->PlayBackward( this );

			 this->showMsg( "Play backward by 10 seconds." );
		 }
private: System::Void tbVideoCurrFramePos_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 this->videoCurrentFramePosTrackBarMoving = true ;
		 }
private: System::Void tbVideoCurrFramePos_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) { 

			 int pos = this->tbVideoCurrFramePos->Value ; 

			 System::String^ msg = L"Video curr frame track bar pos : " + this->tbVideoCurrFramePos->Value;
			 this->showMsg( msg );

			 double posPct = pos/100.0;

			 VisionSystem * vs = this->visionSystem;

			 vs->PlayAtPosPct( posPct );

			 this->videoCurrentFramePosTrackBarMoving = false ; 
		 }

private: System::Void miVideoSave_Click(System::Object^  sender, System::EventArgs^  e) {
			 videoFileSave();
		 }
private: System::Void ConfigFileSave_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Windows::Forms::SaveFileDialog^ d = this->configSaveFileDialog ; 

			 d->Filter = "Config|*.config; *.cfg";
			 d->Title = L"Enter file name or select a config file!";  

			 System::String^ fileName = nullptr ; 

			 if ( d->ShowDialog( this ) == System::Windows::Forms::DialogResult::OK) {
				 fileName = d->FileName ; 
			 }

			 if( nullptr == fileName || fileName->Trim()->Length < 1 ) {
				 return;
			 }

			 if( nullptr != fileName ) {
				 this->ConfigFileSave( fileName );
			 }
		 }
private: System::Void miOpenConfig_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::Windows::Forms::OpenFileDialog^ d = this->configOpenFileDialog ; 

			 d->Filter = "Config|*.config; *.cfg";
			 d->Title = L"Select a config file to open!";  

			 System::String^ fileName = nullptr ; 

			 if ( d->ShowDialog( this ) == System::Windows::Forms::DialogResult::OK) {
				 fileName = d->FileName ; 
			 }

			 if( nullptr == fileName || fileName->Trim()->Length < 1 ) {
				 return;
			 }

			 if( nullptr != fileName ) {  
				 this->ConfigFileOpen( fileName ) ;
			 }
		 } 

private: System::Void DrawChartAgainAtPauseMode( ) {
			 VisionSystem * vs = this->visionSystem ; 
			 bool isPlayMode = ( VisionInterface::PlayMode::PLAY == vs->playMode ) ; 

			 if( false == isPlayMode && this->visionChartFreq->GetSampleDataCnt() > 0 ) {  
				 bool b = false ; 
				 this->rbChartDft->Enabled = b;
				 this->rbChartFft->Enabled = b;  
				 this->nUpDnHighPassFilterHz->Enabled = b ;
				 this->nUpDnLowPassFilterHz->Enabled = b ; 

				 this->cbHighPassFilter->Enabled = b; 
				 this->cbLowPassFilter->Enabled = b; 

				 this->pbChartPrcs->Image = this->extRscForm->pbChartPrcs->Image ;  
			 }
		 }

private: System::Void rbChartFft_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 DrawChartAgainAtPauseMode();
		}
private: System::Void rbChartDft_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 DrawChartAgainAtPauseMode();
		 }
private: System::Void nUpDnHighPassFilterHz_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 DrawChartAgainAtPauseMode();
		 }
private: System::Void nUpDnLowPassFilterHz_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 DrawChartAgainAtPauseMode();
		 }
private: System::Void cbHighPassFilter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 DrawChartAgainAtPauseMode();
		 }
private: System::Void cbLowPassFilter_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 DrawChartAgainAtPauseMode();
		 }
private: System::Void pbChartPrcs_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

			 if( this->rbChartFft->Enabled  || this->rbChartDft->Enabled ) {
				 return ; 
			 }

			 System::String^ msg = L"Chart Repainting ...." ; 
			 showMsg( msg );

			 VisionSystem * vs = this->visionSystem ; 
			 const bool isPlayMode = ( VisionInterface::PlayMode::PLAY == vs->playMode ) ; 

			 if( false == isPlayMode && this->visionChartFreq->GetSampleDataCnt() > 0 ) {  

				 this->ProcessMatchResult( NULL , & vs->videoInfo );

				 bool b = true;
				 this->rbChartDft->Enabled = b;
				 this->rbChartFft->Enabled = b;

				 this->nUpDnHighPassFilterHz->Enabled = this->cbHighPassFilter->Checked ;
				 this->nUpDnLowPassFilterHz->Enabled = this->cbLowPassFilter->Checked ; 

				 this->cbHighPassFilter->Enabled = b; 
				 this->cbLowPassFilter->Enabled = b; 

				 this->pbChartPrcs->Image = this->extRscForm->pbChartPrcsStop->Image ;  
			 }
		 } 


// end of class  

}; 

}

