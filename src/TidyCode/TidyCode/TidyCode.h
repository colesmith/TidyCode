
// TidyCode.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTidyCodeApp:
// �йش����ʵ�֣������ TidyCode.cpp
//

class CTidyCodeApp : public CWinApp
{
public:
	CTidyCodeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTidyCodeApp theApp;