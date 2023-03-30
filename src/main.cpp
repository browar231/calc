
#include <wx/wx.h>

class Main : public wxApp {
public:
	bool OnInit();
};

class Frame : public wxFrame {
public:
	Frame(const wxString& title, const wxPoint& pos, const wxSize& size);

private:
	void OnExit(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();
};
// clang-format off
wxBEGIN_EVENT_TABLE(Frame, wxFrame)
    EVT_MENU(wxID_EXIT, Frame::OnExit)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(Main);
// clang-format on

bool Main::OnInit()
{
	Frame* frame = new Frame("Calculator", wxPoint(50, 50), wxSize(450, 340));
	frame->Show(true);
	return true;
}
Frame::Frame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{

	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");
}

// #include "Application.h"
// #include "Common.h"

// int main()
// {
// 	bool running { true };
// 	std::cout << "Please type your request without spaces, allowed operations: +-*/^"
// 			  << std::endl;
// 	std::cout << "Use dot for fractions ie. 10.32+12" << std::endl;
// 	std::cout << "Type exit to close" << std::endl;
// 	while (running) {
// 		std::string input = Application::getInputFromConsole();
// 		if (input == "exit") {
// 			running = false;
// 			break;
// 		}
// 		try {
// 			std::string answer = Application::parseRequest(input);
// 			std::cout << "Answer: " << answer << std::endl;
// 		} catch (std::runtime_error& error) {
// 			std::cout << error.what() << std::endl;
// 		}
// 	}
// 	return 0;
// }