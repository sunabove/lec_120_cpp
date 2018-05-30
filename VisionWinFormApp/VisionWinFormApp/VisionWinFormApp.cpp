// VisionWinFormApp.cpp : main project file.

#include "stdafx.h"
#include "VisionWinform.h"

using namespace VisionWinFormApp;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew VisionWinForm());
	return 0;
}
