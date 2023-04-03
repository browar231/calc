#include "MainApp.h"
#include "MainFrame.h"
IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
	MainFrame* frame = new MainFrame(wxT("Calculator"));
	frame->Show(true);

	return true;
}