#ifndef BATDIALOG_H
#define BATDIALOG_H

//(*Headers(BatDialog)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/clrpicker.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
//*)

class BatDialog: public wxDialog
{
	public:

		BatDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~BatDialog();

	private:

		//(*Declarations(BatDialog)
		wxButton* Button_Add;
		wxButton* Button_Cancle;
		wxButton* Button_Empty;
		wxButton* Button_Ok;
		wxCheckBox* CheckBoxNewPNG;
		wxCheckBox* CheckBox_isShd;
		wxColourPickerCtrl* ColourPickerCtrl_BaseColor;
		wxRadioButton* RadioButton_Asf;
		wxRadioButton* RadioButton_Gif;
		wxRadioButton* RadioButton_Mpc;
		wxRadioButton* RadioButton_Png;
		wxRichTextCtrl* RichTextCtrl_List;
		wxSpinCtrl* SpinCtrl_AlphaMask;
		wxSpinCtrl* SpinCtrl_FrameBegin;
		wxSpinCtrl* SpinCtrl_FrameEnd;
		wxSpinCtrl* SpinCtrl_Scale;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		//*)

	protected:

		//(*Identifiers(BatDialog)
		static const long ID_RICHTEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_RADIOBUTTON1;
		static const long ID_RADIOBUTTON2;
		static const long ID_STATICTEXT1;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_COLOURPICKERCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL1;
		static const long ID_SPINCTRL2;
		static const long ID_SPINCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_RADIOBUTTON3;
		static const long ID_RADIOBUTTON4;
		static const long ID_SPINCTRL4;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_CHECKBOXNEWPNG;
		//*)

	public:

		//(*Handlers(BatDialog)
		void OnButton_AddClick(wxCommandEvent& event);
		void OnButton_EmptyClick(wxCommandEvent& event);
		void OnButton_OkClick(wxCommandEvent& event);
		void OnButton_CancleClick(wxCommandEvent& event);
		void OnRadioButton_GifSelect(wxCommandEvent& event);
		void OnRadioButton_PngSelect(wxCommandEvent& event);
		void OnCheckBox_isShdClick(wxCommandEvent& event);
		//*)

    public:
        wxRichTextCtrl *GetListTextCtrl(){return RichTextCtrl_List;}
        wxColour GetBaseColor(){return ColourPickerCtrl_BaseColor->GetColour();}
        unsigned char GetAlphaMask(){return (unsigned char)SpinCtrl_AlphaMask->GetValue();}
        int GetFrameBegin(){return (SpinCtrl_FrameBegin->GetValue() - 1);}
        int GetFrameEnd(){return (SpinCtrl_FrameEnd->GetValue() - 1);}
        bool isGif(){return RadioButton_Gif->GetValue();}
        bool isPng(){return RadioButton_Png->GetValue();}
        bool isMpc(){return RadioButton_Mpc->GetValue();}
        bool isAsf(){return RadioButton_Asf->GetValue();}
        float getScaleRatio(){return (float)SpinCtrl_Scale->GetValue()/(float)100;}
        bool isShd(){return CheckBox_isShd->IsChecked();}
        bool isNewPNG(){return CheckBoxNewPNG->IsChecked();}
		DECLARE_EVENT_TABLE()
};

#endif
