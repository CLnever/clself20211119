
// TestSplite.h : TestSplite Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTestSpliteApp:
// �йش����ʵ�֣������ TestSplite.cpp
//

class CTestSpliteApp : public CWinApp
{
public:
	CTestSpliteApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestSpliteApp theApp;
