#include "wx/wx.h" 
#include "myframe.h"

class MyApp: public wxApp
{
    virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame(NULL, 1, _("hello"));
    frame->Show(true);
    return true;
}
