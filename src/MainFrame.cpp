#include "MainFrame.h"
#include "Calculation.h"
MainFrame::MainFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 250))
{
	// elements
	inputTextBox = new wxTextCtrl(this, -1, "", wxPoint(-1, -1));

	wxButton* submitButton = new wxButton(this, ID_SUBMIT_BUTTON, wxT("="));
	wxButton* clearButton = new wxButton(this, ID_CLEAR_BUTTON, wxT("Clear"));
	wxButton* backspaceButton = new wxButton(this, ID_BACKSPACE_BUTTON, wxT("⌫"));
	wxButton* quitButton = new wxButton(this, wxID_EXIT, wxT("Quit"));

	// positioning
	wxBoxSizer* vSizer = new wxBoxSizer(wxVERTICAL);
	vSizer->Add(inputTextBox, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

	wxGridSizer* gs = new wxGridSizer(5, 4, 5, 5);

	gs->Add(new wxStaticText(this, -1, wxT("")), 0, wxEXPAND);
	gs->Add(backspaceButton, 0);
	gs->Add(clearButton, 0);
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("+")));

	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("1")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("2")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("3")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("-")));

	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("4")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("5")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("6")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("*")));

	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("7")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("8")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("9")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("/")));

	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT("0")));
	gs->Add(new wxButton(this, ID_APPEND_BUTTON, wxT(".")));
	gs->Add(submitButton, 0);
	gs->Add(quitButton, 0);

	vSizer->Add(gs, 1, wxEXPAND);
	// sizer->SetSizeHints(this);
	SetSizer(vSizer);
	SetMinSize(wxSize(400, 250));
	SetMaxSize(wxSize(400, 250));

	// events
	Connect(wxID_EXIT, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnQuit));
	Connect(ID_SUBMIT_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnSubmit));
	Connect(ID_CLEAR_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnClear));
	Connect(ID_APPEND_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnAppend));
	Connect(ID_BACKSPACE_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED,
		wxCommandEventHandler(MainFrame::OnBackspace));
	// init
	Centre();
}
void MainFrame::OnSubmit(wxCommandEvent& event)
{
	std::string input = inputTextBox->GetValue().ToStdString();
	wxString outputValue;
	try {
		double answer(Calculation::returnAnswer(input));
		outputValue << answer;
		inputTextBox->SetValue(outputValue);

	} catch (std::runtime_error& error) {
		inputTextBox->SetValue(error.what());
	}
}
void MainFrame::OnClear(wxCommandEvent& event)
{
	inputTextBox->SetValue("");
}
void MainFrame::OnBackspace(wxCommandEvent& event)
{
	wxString currentValue = inputTextBox->GetValue();
	currentValue.RemoveLast();
	inputTextBox->SetValue(currentValue);
}
void MainFrame::OnQuit(wxCommandEvent& event)
{
	Close(true);
}
void MainFrame::OnAppend(wxCommandEvent& event)
{
	wxString currentValue = inputTextBox->GetValue();
	wxButton* pressedButton = wxDynamicCast(event.GetEventObject(), wxButton);
	currentValue << pressedButton->GetLabel();
	inputTextBox->SetValue(currentValue);
}
std::string MainFrame::parseRequest(std::string request)
{
	double answer = Calculation::returnAnswer(request);
	if (answer == floor(answer)) {
		return std::to_string(int(answer));
	}
	return std::to_string(answer);
}