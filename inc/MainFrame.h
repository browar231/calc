#pragma once
#include <wx/wx.h>
enum {
	ID_SUBMIT_BUTTON,
	ID_CLEAR_BUTTON
};

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
	void OnQuit(wxCommandEvent& event);
	void OnSubmit(wxCommandEvent& event);
	void OnClear(wxCommandEvent& event);
	std::string parseRequest(std::string request);
	wxTextCtrl* inputTextBox;
	wxTextCtrl* outputTextBox;
};