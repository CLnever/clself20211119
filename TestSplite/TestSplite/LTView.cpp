// LTView.cpp : 实现文件
//

#include "stdafx.h"
#include "TestSplite.h"
#include "LTView.h"


// CLTView

IMPLEMENT_DYNCREATE(CLTView, CView)

CLTView::CLTView()
{

}

CLTView::~CLTView()
{
}

BEGIN_MESSAGE_MAP(CLTView, CView)
END_MESSAGE_MAP()


// CLTView 绘图

void CLTView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	CRect rect;
	GetClientRect(&rect);
	CBrush br(RGB(0,0,0));
	pDC->FillRect(rect,&br);
	// TODO: 在此添加绘制代码
}


// CLTView 诊断

#ifdef _DEBUG
void CLTView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CLTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLTView 消息处理程序
