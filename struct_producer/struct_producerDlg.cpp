
// struct_producerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "struct_producer.h"
#include "struct_producerDlg.h"
#include "afxdialogex.h"
#include <sstream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// StructProducerDlg �Ի���



StructProducerDlg::StructProducerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(StructProducerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void StructProducerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(StructProducerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &StructProducerDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// StructProducerDlg ��Ϣ�������

BOOL StructProducerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void StructProducerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR StructProducerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void StructProducerDlg::OnBnClickedButton1()
{
	CString name;
	GetDlgItemText(IDC_EDIT_NAME, name);
	if(name.GetLength()>1)
	{
		if (name[0] == 'k')
		{
			name.Delete(0,1);
		}

		stringstream  ss;
		ss<< "typedef struct _" <<name <<"\r\n { \r\n \tstatic const Type kType = k" <<name<<";\r\n\r\n}"<<name<<";\r\n\r\n";
		name+="Result";
		ss<< "typedef struct _" <<name  <<"\r\n { \r\n \tstatic const Type kType = k" <<name<<";\r\n\r\n}"<<name<<";\r\n\r\n";

		GetDlgItem(IDC_EDIT_CODE)->SetWindowText(ss.str().c_str());


		if( OpenClipboard() )

		{

			HGLOBAL clipbuffer;

			char * buffer;

			EmptyClipboard();

			clipbuffer = GlobalAlloc(GMEM_DDESHARE, ss.str().length()+1);

			buffer = (char*)GlobalLock(clipbuffer);

			strcpy(buffer, ss.str().c_str());

			GlobalUnlock(clipbuffer);

			SetClipboardData(CF_TEXT,clipbuffer);

			CloseClipboard();

		}
	}
}

