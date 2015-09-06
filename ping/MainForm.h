#ifndef _MAINFORM_H
#define _MAINFORM_H


#include <wx/wx.h>
#include <wx/socket.h>
#include <boost/date_time/posix_time/posix_time.hpp>


#define wxID_IPAddress_Ctrl 0x1
#define wxID_Port_Ctrl 0x2
#define wxID_Ping_Ctrl 0x3
#define wxID_Message_Ctrl 0x4
#define wxID_rbGate_Ctrl 0x5
#define wxID_rbData_Ctrl 0x6
#define wxID_rbInteract_Ctrl 0x7
#define wxID_rbWorld_Ctrl 0x8
#define wxID_Clear_Message_Ctrl 0x9
#define wxID_Data_Processer_Ctrl 0xA
#define wxID_Stop_Ctrl 0xB
#define wxID_Socket_Client_1 0xC


class PingClient;

class MainForm: public wxFrame
{
public:
	MainForm(const wxString& Caption, int width, int height);
	virtual ~MainForm();
	//������Ļ����
	void moveto_screen_center();

private:
	wxRadioButton* rbGate;			//����
	wxRadioButton* rbData;
	wxRadioButton* rbInteract;
	wxRadioButton* rbWorld;
	wxTextCtrl* txtIPAddress;
	wxTextCtrl* txtPort;
	wxButton* btnPing;
	wxTextCtrl* txtMessage;			//��Ϣ��ʾ��
	wxButton* btnClearMessage;
	wxTimer* tmPing;				//ping timer
	PingClient* ping_client;		//ping����
	wxButton* btnStop;
	
	boost::posix_time::ptime start_connect_time, start_ping_time;  

	void OnButtonClick(wxCommandEvent& event);
	void OnRadioClick(wxCommandEvent& event);
	void OnTimer(wxTimerEvent& event);
	void OnSocketEvent(wxSocketEvent& event);


	void StartPing();

	int m_ping_executed_count;

	DECLARE_EVENT_TABLE()

};


#endif	//_MAINFORM_H