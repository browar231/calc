#pragma once
#include <wx/wx.h>
enum {
	ID_APPEND_BUTTON,
	ID_SUBMIT_BUTTON,
	ID_CLEAR_BUTTON,
	ID_BACKSPACE_BUTTON
};

class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
	void OnQuit(wxCommandEvent& event);
	void OnSubmit(wxCommandEvent& event);
	void OnClear(wxCommandEvent& event);
	void OnAppend(wxCommandEvent& event);
	void OnBackspace(wxCommandEvent& event);
	std::string parseRequest(std::string request);
	wxTextCtrl* inputTextBox;
};