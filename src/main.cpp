#include "main.h"
#include "Application.h"
MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 400))
{
	// elements
	inputTextBox = new wxTextCtrl(this, -1, "", wxPoint(-1, -1));
	outputTextBox = new wxTextCtrl(this, -1, "Results", wxPoint(-1, -1), wxDefaultSize, wxTE_READONLY);

	wxButton* submitButton = new wxButton(this, ID_SUBMIT_BUTTON, wxT("Submit"));
	wxButton* quitButton = new wxButton(this, wxID_EXIT, wxT("Quit"));

	// sizer
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(inputTextBox, 0, wxEXPAND, 0);
	sizer->Add(outputTextBox, 0, wxEXPAND, 0);
	sizer->Add(submitButton, 0, wxALIGN_LEFT, 0);
	sizer->Add(quitButton, 0, wxALIGN_RIGHT, 0);
	// sizer->SetSizeHints(this);
	SetSizer(sizer);

	// events
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnQuit));
	Connect(ID_SUBMIT_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnSubmit));
	// init
	Centre();
}
void MainFrame::OnSubmit(wxCommandEvent& event)
{
	std::string input = inputTextBox->GetValue().ToStdString();
	wxString answer(Application::parseRequest(input));
	try {
		wxString answer(Application::parseRequest(input));
		outputTextBox->SetValue(answer);
	} catch (std::runtime_error& error) {
		outputTextBox->SetValue("Error");
	}
}
void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close(true);
}
IMPLEMENT_APP(Calculator)

bool Calculator::OnInit()
{
	MainFrame* frame = new MainFrame(wxT("Calculator"));
	frame->Show(true);

	return true;
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