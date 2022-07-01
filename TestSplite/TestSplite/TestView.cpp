
// TestView.cpp : CTestView 类的实现
//

#include "stdafx.h"
#include "TestSplite.h"
#include "TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestView

CTestView::CTestView()
{
}

CTestView::~CTestView()
{
}


BEGIN_MESSAGE_MAP(CTestView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CTestView 消息处理程序

BOOL CTestView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CTestView::OnPaint() 
{
	CPaintDC dc(this); // 用于绘制的设备上下文
	
	// TODO: 在此处添加消息处理程序代码
	
	// 不要为绘制消息而调用 CWnd::OnPaint()
}

