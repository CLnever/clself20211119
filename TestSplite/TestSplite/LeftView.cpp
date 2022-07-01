// LeftView.cpp : 实现文件
//

#include "stdafx.h"
#include "TestSplite.h"
#include "LeftView.h"


// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CTreeView)

CLeftView::CLeftView()
{

}

CLeftView::~CLeftView()
{
}

BEGIN_MESSAGE_MAP(CLeftView, CTreeView)
END_MESSAGE_MAP()


// CLeftView 诊断

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftView 消息处理程序
