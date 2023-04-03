#pragma once
#include <wx/wx.h>
const int ID_SUBMIT_BUTTON { 999 };
const int ID_CLEAR_BUTTON { 998 };
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