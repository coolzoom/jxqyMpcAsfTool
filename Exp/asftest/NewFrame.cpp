#include "wx/filedlg.h"
#include "wx/msgdlg.h"
#include "NewFrame.h"


//(*InternalHeaders(NewFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(NewFrame)
const long NewFrame::ID_STATICBITMAP1 = wxNewId();
const long NewFrame::ID_BUTTON1 = wxNewId();
const long NewFrame::ID_BUTTON2 = wxNewId();
const long NewFrame::ID_BUTTON3 = wxNewId();
const long NewFrame::ID_STATICTEXT1 = wxNewId();
const long NewFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(NewFrame,wxFrame)
    //(*EventTable(NewFrame)
    //*)
END_EVENT_TABLE()

NewFrame::NewFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(NewFrame)
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer3;

    Create(parent, wxID_ANY, _("Choose Asf file.."), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(240,168), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    bitmap_view = new wxStaticBitmap(Panel1, ID_STATICBITMAP1, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    BoxSizer3->Add(bitmap_view, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Button_asffile = new wxButton(Panel1, ID_BUTTON1, _("AsfFile..."), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer4->Add(Button_asffile, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_previous = new wxButton(Panel1, ID_BUTTON2, _("Previous"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(Button_previous, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button_next = new wxButton(Panel1, ID_BUTTON3, _("Next"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer4->Add(Button_next, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText_current_pic = new wxStaticText(Panel1, ID_STATICTEXT1, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer4->Add(StaticText_current_pic, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NewFrame::OnButton_mpcfileClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NewFrame::OnButton_previousClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&NewFrame::OnButton_nextClick);
    //*)
    currentframe = 0;
}

NewFrame::~NewFrame()
{
    //(*Destroy(NewFrame)
    //*)
}


void NewFrame::OnButton_mpcfileClick(wxCommandEvent& event)
{
    try
    {
    wxFileDialog filedlg(this, wxT("Select a ASF File"), wxT(""),
                         wxT(""), wxT("asf file(*.asf)|*.asf"),
                         wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(filedlg.ShowModal() == wxID_OK)
    {
        currentframe = 0;
        if(asfdecode.ReadAsfFile(filedlg.GetPath()))
        {
            bitmap_view->SetBitmap(wxBitmap(asfdecode.GetFrameImage(currentframe)));
            this->SetTitle(asfdecode.GetVersionInfo() +
                           wxT("  Frames:") +
                           wxString::Format(wxT("%ld"), asfdecode.GetFramesCounts()) +
                           wxT("  Colour:") +
                           wxString::Format(wxT("%ld"), asfdecode.GetColourCounts()));
            StaticText_current_pic->SetLabel(wxString::Format(wxT("%d"), currentframe+1));
        }
        else
        {
            wxMessageBox(wxT("Read error!"), wxT("ERROR"), wxOK|wxCENTER|wxICON_ERROR);
        }
    }
    }
    catch(...)
    {
        wxMessageBox(wxT("Exception Occour,Please Retray"));
    }
    this->Refresh();
    this->Update();
}

void NewFrame::OnButton_previousClick(wxCommandEvent& event)
{
    if(!asfdecode.GetFilePath().IsEmpty() && currentframe != 0)
    {
        currentframe--;
        bitmap_view->SetBitmap(wxBitmap(asfdecode.GetFrameImage(currentframe)));
        StaticText_current_pic->SetLabel(wxString::Format(wxT("%d"), currentframe+1));
    }
    this->Refresh();
    this->Update();
}

void NewFrame::OnButton_nextClick(wxCommandEvent& event)
{
    if(!asfdecode.GetFilePath().IsEmpty() && currentframe+1 != asfdecode.GetFramesCounts())
    {
        currentframe++;
        bitmap_view->SetBitmap(wxBitmap(asfdecode.GetFrameImage(currentframe)));
        StaticText_current_pic->SetLabel(wxString::Format(wxT("%d"), currentframe+1));
    }
    this->Refresh();
    this->Update();
}
