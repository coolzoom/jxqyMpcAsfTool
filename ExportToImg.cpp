#include "ExportToImg.h"

#include "wx/msgdlg.h"
//(*InternalHeaders(ExportToImg)



//(*IdInit(ExportToImg)







BEGIN_EVENT_TABLE(ExportToImg,wxDialog)
	//(*EventTable(ExportToImg)
	//*)
END_EVENT_TABLE()

ExportToImg::ExportToImg(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ExportToImg)












}

ExportToImg::~ExportToImg()
{
	//(*Destroy(ExportToImg)
	//*)
}


void ExportToImg::OnButton1Click(wxCommandEvent& event)
{
    nameprefix = TextCtrl_FilePrefix->GetValue();
    EndModal(wxID_OK);
}
void ExportToImg::OnButton2Click(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}