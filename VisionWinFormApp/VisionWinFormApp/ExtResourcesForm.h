#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace VisionWinFormApp {

	/// <summary>
	/// Summary for ExtResourcesForm
	/// </summary>
	public ref class ExtResourcesForm : public System::Windows::Forms::UserControl
	{
	public:
		ExtResourcesForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ExtResourcesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::PictureBox^  cam_record;
	protected: 
	public: System::Windows::Forms::PictureBox^  cam_norecord;
	public: System::Windows::Forms::FlowLayoutPanel^  camDevAniPanel;

	public: 

	public: 
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: 
	public: System::Windows::Forms::PictureBox^  pictureBox2;
	public: System::Windows::Forms::PictureBox^  pictureBox3;
	public: System::Windows::Forms::PictureBox^  pictureBox4;
	public: System::Windows::Forms::PictureBox^  pictureBox5;
	public: System::Windows::Forms::PictureBox^  pictureBox6;
	public: System::Windows::Forms::PictureBox^  gif_load_01;
	public: System::Windows::Forms::PictureBox^  gif_load_01_stop;
	public: System::Windows::Forms::PictureBox^  pbVideoRecording;
	public: System::Windows::Forms::PictureBox^  pbVideoRecordingStop;
	public: System::Windows::Forms::PictureBox^  pbTarget;
	public: System::Windows::Forms::PictureBox^  pbVideo;
	private: System::Windows::Forms::PictureBox^  pbChartDispVertAxisTitle;
	public: System::Windows::Forms::PictureBox^  pbVideoPlay;
	private: 
	public: System::Windows::Forms::PictureBox^  pbVideoPause;
	public: System::Windows::Forms::PictureBox^  pbChartPrcs;
	public: System::Windows::Forms::PictureBox^  pbChartPrcsStop;
	public: System::Windows::Forms::PictureBox^  pbChartPrcsOpt;
	public: System::Windows::Forms::PictureBox^  pictureBox7;
	public: System::Windows::Forms::PictureBox^  pictureBox8;
	public: System::Windows::Forms::PictureBox^  pictureBox9;
	public: System::Windows::Forms::PictureBox^  pbTargetUnFix;
	public: System::Windows::Forms::PictureBox^  pbTargetFix;



	public: 

	public: 


	protected: 

	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ExtResourcesForm::typeid));
			this->cam_record = (gcnew System::Windows::Forms::PictureBox());
			this->cam_norecord = (gcnew System::Windows::Forms::PictureBox());
			this->camDevAniPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->gif_load_01 = (gcnew System::Windows::Forms::PictureBox());
			this->gif_load_01_stop = (gcnew System::Windows::Forms::PictureBox());
			this->pbVideoRecording = (gcnew System::Windows::Forms::PictureBox());
			this->pbVideoRecordingStop = (gcnew System::Windows::Forms::PictureBox());
			this->pbTarget = (gcnew System::Windows::Forms::PictureBox());
			this->pbVideo = (gcnew System::Windows::Forms::PictureBox());
			this->pbChartDispVertAxisTitle = (gcnew System::Windows::Forms::PictureBox());
			this->pbVideoPlay = (gcnew System::Windows::Forms::PictureBox());
			this->pbVideoPause = (gcnew System::Windows::Forms::PictureBox());
			this->pbChartPrcs = (gcnew System::Windows::Forms::PictureBox());
			this->pbChartPrcsStop = (gcnew System::Windows::Forms::PictureBox());
			this->pbChartPrcsOpt = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->pbTargetUnFix = (gcnew System::Windows::Forms::PictureBox());
			this->pbTargetFix = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cam_record))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cam_norecord))->BeginInit();
			this->camDevAniPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gif_load_01))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gif_load_01_stop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideoRecording))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideoRecordingStop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbTarget))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbChartDispVertAxisTitle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideoPlay))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideoPause))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbChartPrcs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbChartPrcsStop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbChartPrcsOpt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbTargetUnFix))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbTargetFix))->BeginInit();
			this->SuspendLayout();
			// 
			// cam_record
			// 
			this->cam_record->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cam_record.Image")));
			this->cam_record->Location = System::Drawing::Point(20, 15);
			this->cam_record->Name = L"cam_record";
			this->cam_record->Size = System::Drawing::Size(32, 32);
			this->cam_record->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->cam_record->TabIndex = 0;
			this->cam_record->TabStop = false;
			this->cam_record->Click += gcnew System::EventHandler(this, &ExtResourcesForm::cam_record_Click);
			// 
			// cam_norecord
			// 
			this->cam_norecord->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cam_norecord.Image")));
			this->cam_norecord->Location = System::Drawing::Point(68, 15);
			this->cam_norecord->Name = L"cam_norecord";
			this->cam_norecord->Size = System::Drawing::Size(32, 32);
			this->cam_norecord->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->cam_norecord->TabIndex = 1;
			this->cam_norecord->TabStop = false;
			// 
			// camDevAniPanel
			// 
			this->camDevAniPanel->Controls->Add(this->pictureBox1);
			this->camDevAniPanel->Controls->Add(this->pictureBox2);
			this->camDevAniPanel->Controls->Add(this->pictureBox3);
			this->camDevAniPanel->Controls->Add(this->pictureBox4);
			this->camDevAniPanel->Controls->Add(this->pictureBox5);
			this->camDevAniPanel->Controls->Add(this->pictureBox6);
			this->camDevAniPanel->Location = System::Drawing::Point(20, 67);
			this->camDevAniPanel->Name = L"camDevAniPanel";
			this->camDevAniPanel->Size = System::Drawing::Size(270, 56);
			this->camDevAniPanel->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(32, 32);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(41, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(32, 32);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 4;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(79, 3);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(32, 31);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 5;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(117, 3);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(32, 32);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(155, 3);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(32, 32);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(193, 3);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(32, 32);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox6->TabIndex = 8;
			this->pictureBox6->TabStop = false;
			// 
			// gif_load_01
			// 
			this->gif_load_01->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"gif_load_01.Image")));
			this->gif_load_01->Location = System::Drawing::Point(121, 15);
			this->gif_load_01->Name = L"gif_load_01";
			this->gif_load_01->Size = System::Drawing::Size(24, 23);
			this->gif_load_01->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->gif_load_01->TabIndex = 3;
			this->gif_load_01->TabStop = false;
			// 
			// gif_load_01_stop
			// 
			this->gif_load_01_stop->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"gif_load_01_stop.Image")));
			this->gif_load_01_stop->Location = System::Drawing::Point(151, 15);
			this->gif_load_01_stop->Name = L"gif_load_01_stop";
			this->gif_load_01_stop->Size = System::Drawing::Size(24, 23);
			this->gif_load_01_stop->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->gif_load_01_stop->TabIndex = 4;
			this->gif_load_01_stop->TabStop = false;
			// 
			// pbVideoRecording
			// 
			this->pbVideoRecording->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbVideoRecording.Image")));
			this->pbVideoRecording->Location = System::Drawing::Point(210, 15);
			this->pbVideoRecording->Name = L"pbVideoRecording";
			this->pbVideoRecording->Size = System::Drawing::Size(16, 16);
			this->pbVideoRecording->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbVideoRecording->TabIndex = 5;
			this->pbVideoRecording->TabStop = false;
			// 
			// pbVideoRecordingStop
			// 
			this->pbVideoRecordingStop->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbVideoRecordingStop.Image")));
			this->pbVideoRecordingStop->Location = System::Drawing::Point(240, 15);
			this->pbVideoRecordingStop->Name = L"pbVideoRecordingStop";
			this->pbVideoRecordingStop->Size = System::Drawing::Size(16, 16);
			this->pbVideoRecordingStop->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbVideoRecordingStop->TabIndex = 6;
			this->pbVideoRecordingStop->TabStop = false;
			// 
			// pbTarget
			// 
			this->pbTarget->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbTarget->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbTarget->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbTarget.Image")));
			this->pbTarget->Location = System::Drawing::Point(306, 70);
			this->pbTarget->Name = L"pbTarget";
			this->pbTarget->Size = System::Drawing::Size(52, 47);
			this->pbTarget->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pbTarget->TabIndex = 7;
			this->pbTarget->TabStop = false;
			// 
			// pbVideo
			// 
			this->pbVideo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbVideo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbVideo->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbVideo.Image")));
			this->pbVideo->Location = System::Drawing::Point(20, 142);
			this->pbVideo->Name = L"pbVideo";
			this->pbVideo->Size = System::Drawing::Size(34, 34);
			this->pbVideo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbVideo->TabIndex = 8;
			this->pbVideo->TabStop = false;
			// 
			// pbChartDispVertAxisTitle
			// 
			this->pbChartDispVertAxisTitle->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbChartDispVertAxisTitle.Image")));
			this->pbChartDispVertAxisTitle->Location = System::Drawing::Point(394, 70);
			this->pbChartDispVertAxisTitle->Name = L"pbChartDispVertAxisTitle";
			this->pbChartDispVertAxisTitle->Size = System::Drawing::Size(16, 55);
			this->pbChartDispVertAxisTitle->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbChartDispVertAxisTitle->TabIndex = 9;
			this->pbChartDispVertAxisTitle->TabStop = false;
			// 
			// pbVideoPlay
			// 
			this->pbVideoPlay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbVideoPlay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbVideoPlay->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbVideoPlay.Image")));
			this->pbVideoPlay->Location = System::Drawing::Point(68, 142);
			this->pbVideoPlay->Name = L"pbVideoPlay";
			this->pbVideoPlay->Size = System::Drawing::Size(34, 34);
			this->pbVideoPlay->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbVideoPlay->TabIndex = 10;
			this->pbVideoPlay->TabStop = false;
			// 
			// pbVideoPause
			// 
			this->pbVideoPause->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbVideoPause->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbVideoPause->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbVideoPause.Image")));
			this->pbVideoPause->Location = System::Drawing::Point(108, 142);
			this->pbVideoPause->Name = L"pbVideoPause";
			this->pbVideoPause->Size = System::Drawing::Size(28, 28);
			this->pbVideoPause->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbVideoPause->TabIndex = 11;
			this->pbVideoPause->TabStop = false;
			// 
			// pbChartPrcs
			// 
			this->pbChartPrcs->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbChartPrcs.Image")));
			this->pbChartPrcs->Location = System::Drawing::Point(20, 188);
			this->pbChartPrcs->Name = L"pbChartPrcs";
			this->pbChartPrcs->Size = System::Drawing::Size(256, 88);
			this->pbChartPrcs->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbChartPrcs->TabIndex = 12;
			this->pbChartPrcs->TabStop = false;
			// 
			// pbChartPrcsStop
			// 
			this->pbChartPrcsStop->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbChartPrcsStop.Image")));
			this->pbChartPrcsStop->Location = System::Drawing::Point(306, 188);
			this->pbChartPrcsStop->Name = L"pbChartPrcsStop";
			this->pbChartPrcsStop->Size = System::Drawing::Size(256, 88);
			this->pbChartPrcsStop->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbChartPrcsStop->TabIndex = 13;
			this->pbChartPrcsStop->TabStop = false;
			// 
			// pbChartPrcsOpt
			// 
			this->pbChartPrcsOpt->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbChartPrcsOpt.Image")));
			this->pbChartPrcsOpt->Location = System::Drawing::Point(20, 282);
			this->pbChartPrcsOpt->Name = L"pbChartPrcsOpt";
			this->pbChartPrcsOpt->Size = System::Drawing::Size(256, 88);
			this->pbChartPrcsOpt->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbChartPrcsOpt->TabIndex = 14;
			this->pbChartPrcsOpt->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(306, 282);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(256, 88);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox7->TabIndex = 15;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(830, 24);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(24, 23);
			this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox8->TabIndex = 17;
			this->pictureBox8->TabStop = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(800, 24);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(24, 23);
			this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox9->TabIndex = 16;
			this->pictureBox9->TabStop = false;
			// 
			// pbTargetUnFix
			// 
			this->pbTargetUnFix->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbTargetUnFix->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbTargetUnFix->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbTargetUnFix.Image")));
			this->pbTargetUnFix->Location = System::Drawing::Point(482, 97);
			this->pbTargetUnFix->Name = L"pbTargetUnFix";
			this->pbTargetUnFix->Size = System::Drawing::Size(26, 25);
			this->pbTargetUnFix->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbTargetUnFix->TabIndex = 18;
			this->pbTargetUnFix->TabStop = false;
			// 
			// pbTargetFix
			// 
			this->pbTargetFix->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->pbTargetFix->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbTargetFix->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pbTargetFix.Image")));
			this->pbTargetFix->Location = System::Drawing::Point(523, 97);
			this->pbTargetFix->Name = L"pbTargetFix";
			this->pbTargetFix->Size = System::Drawing::Size(26, 24);
			this->pbTargetFix->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbTargetFix->TabIndex = 19;
			this->pbTargetFix->TabStop = false;
			// 
			// ExtResourcesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pbTargetFix);
			this->Controls->Add(this->pbTargetUnFix);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pbChartPrcsOpt);
			this->Controls->Add(this->pbChartPrcsStop);
			this->Controls->Add(this->pbChartPrcs);
			this->Controls->Add(this->pbVideoPause);
			this->Controls->Add(this->pbVideoPlay);
			this->Controls->Add(this->pbChartDispVertAxisTitle);
			this->Controls->Add(this->pbVideo);
			this->Controls->Add(this->pbTarget);
			this->Controls->Add(this->pbVideoRecordingStop);
			this->Controls->Add(this->pbVideoRecording);
			this->Controls->Add(this->gif_load_01_stop);
			this->Controls->Add(this->gif_load_01);
			this->Controls->Add(this->camDevAniPanel);
			this->Controls->Add(this->cam_norecord);
			this->Controls->Add(this->cam_record);
			this->Name = L"ExtResourcesForm";
			this->Size = System::Drawing::Size(1002, 595);
			this->Load += gcnew System::EventHandler(this, &ExtResourcesForm::ExtResourcesForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cam_record))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cam_norecord))->EndInit();
			this->camDevAniPanel->ResumeLayout(false);
			this->camDevAniPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gif_load_01))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gif_load_01_stop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideoRecording))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideoRecordingStop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbTarget))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbChartDispVertAxisTitle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideoPlay))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbVideoPause))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbChartPrcs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbChartPrcsStop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbChartPrcsOpt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbTargetUnFix))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pbTargetFix))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void cam_record_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void ExtResourcesForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	};
}
