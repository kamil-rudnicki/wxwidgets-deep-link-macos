#include <wx/wx.h>
#include "MainFrame.h"

extern "C" void InitializeURLHandler();

class MyApp : public wxApp
{
public:
    virtual bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    InitializeURLHandler();

    MainFrame *frame = new MainFrame("Deep Link Test", wxPoint(50, 50), wxSize(400, 300));
    frame->Show(true);
    
    return true;
}