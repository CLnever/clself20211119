
// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "TestSplite.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// 创建一个视图以占用框架的工作区
	//if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	//{
	//	TRACE0("未能创建视图窗口\n");
	//	return -1;
	//}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	/*cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_MINIMIZEBOX | WS_SYSMENU;*/
	cs.lpszName = "RBDcm计算机辅助诊断系统";
	cs.style &= ~FWS_ADDTOTITLE;     //去掉后面显示的文件名字
	//cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 消息处理程序

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// 将焦点前移到视图窗口
	//m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 让视图第一次尝试该命令
	//if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
	//	return TRUE;

	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	CRect rct;
	GetClientRect(&rct);								//获取窗口大小
	int nRcWidth = rct.Width();
	int nRcHeight = rct.Height();

	//用第一个分隔条分割成1行2列
	if(m_spliter1.CreateStatic(this, 1, 2)==NULL) return FALSE;
	//分割的第一行第一列指定动态创建对象CLeftView
	//指定窗口宽度是1/4界面宽度,高度为整个界面高度
	m_spliter1.CreateView(0,0,RUNTIME_CLASS(CLeftView),CSize(nRcWidth / 4, nRcHeight), pContext);
	
	//对m_spliter1分割的第二个区域再使用m_spliter2进行分割，分割成2*2个区域
	if (m_spliter2.CreateStatic(&m_spliter1, 2, 2, WS_CHILD|WS_VISIBLE, m_spliter1.IdFromRowCol(0, 1)) == NULL) return FALSE;
	//和上述差不多，指定动态创建的对象为CLTView
	m_spliter2.CreateView(0, 0, RUNTIME_CLASS(CLTView), CSize(nRcWidth / 8 * 3, nRcHeight/2), pContext);
	m_spliter2.CreateView(0, 1, RUNTIME_CLASS(CLTView), CSize(nRcWidth / 8 * 3, nRcHeight/2), pContext);
	m_spliter2.CreateView(1, 0, RUNTIME_CLASS(CLTView), CSize(nRcWidth / 8 * 3, nRcHeight/2), pContext);
	m_spliter2.CreateView(1, 1, RUNTIME_CLASS(CLTView), CSize(nRcWidth / 8 * 3, nRcHeight/2), pContext);

	return CFrameWnd::OnCreateClient(lpcs, pContext);
}
