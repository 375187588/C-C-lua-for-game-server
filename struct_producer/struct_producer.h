
// struct_producer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// StructProducerApp:
// �йش����ʵ�֣������ struct_producer.cpp
//

class StructProducerApp : public CWinApp
{
public:
	StructProducerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern StructProducerApp theApp;