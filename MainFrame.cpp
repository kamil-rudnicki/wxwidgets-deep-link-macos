#include "MainFrame.h"
#include <wx/url.h>

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    wxStaticText* titleLabel = new wxStaticText(panel, wxID_ANY, "Received Token:");
    vbox->Add(titleLabel, 0, wxALIGN_CENTER | wxTOP, 20);

    m_tokenLabel = new wxStaticText(panel, wxID_ANY, "");
    vbox->Add(m_tokenLabel, 0, wxALIGN_CENTER | wxTOP, 10);

    m_logCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(380, 150), wxTE_MULTILINE | wxTE_READONLY);
    vbox->Add(m_logCtrl, 0, wxALIGN_CENTER | wxTOP, 20);

    panel->SetSizer(vbox);
}

void MainFrame::HandleDeepLink(const wxString& url)
{
    wxMessageBox(url);
    m_tokenLabel->SetLabel(url);
    LogMessage(url);
}

void MainFrame::LogMessage(const wxString& message)
{
    if (m_logCtrl)
    {
        m_logCtrl->AppendText(message + "\n");
    }
}
