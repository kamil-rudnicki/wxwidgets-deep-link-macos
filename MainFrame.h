#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    void HandleDeepLink(const wxString& url);
    void LogMessage(const wxString& message);

private:
    wxStaticText* m_tokenLabel;
    wxTextCtrl* m_logCtrl;
};