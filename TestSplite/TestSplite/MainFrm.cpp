
// MainFrm.cpp : CMainFrame ���ʵ��
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
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// ����һ����ͼ��ռ�ÿ�ܵĹ�����
	//if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	//{
	//	TRACE0("δ�ܴ�����ͼ����\n");
	//	return -1;
	//}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	/*cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		| WS_MINIMIZEBOX | WS_SYSMENU;*/
	cs.lpszName = "RBDcm������������ϵͳ";
	cs.style &= ~FWS_ADDTOTITLE;     //ȥ��������ʾ���ļ�����
	//cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

// CMainFrame ���

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


// CMainFrame ��Ϣ�������

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// ������ǰ�Ƶ���ͼ����
	//m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// ����ͼ��һ�γ��Ը�����
	//if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
	//	return TRUE;

	// ����ִ��Ĭ�ϴ���
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	CRect rct;
	GetClientRect(&rct);								//��ȡ���ڴ�С
	int nRcWidth = rct.Width();
	int nRcHeight = rct.Height();

	//�õ�һ���ָ����ָ��1��2��
	if(m_spliter1.CreateStatic(this, 1, 2)==NULL) return FALSE;
	//�ָ�ĵ�һ�е�һ��ָ����̬��������CLeftView
	//ָ�����ڿ����1/4������,�߶�Ϊ��������߶�
	m_spliter1.CreateView(0,0,RUNTIME_CLASS(CLeftView),CSize(nRcWidth / 4, nRcHeight), pContext);
	
	//��m_spliter1�ָ�ĵڶ���������ʹ��m_spliter2���зָ�ָ��2*2������
	if (m_spliter2.CreateStatic(&m_spliter1, 2, 2, WS_CHILD|WS_VISIBLE, m_spliter1.IdFromRowCol(0, 1)) == NULL) return FALSE;
	//��������ָ࣬����̬�����Ķ���ΪCLTView
	m_spliter2.CreateView(0, 0, RUNTIME_CLASS(CLTView), CSize(nRcWidth / 8 * 3, nRcHeight/2), pContext);
	m_spliter2.CreateView(0, 1, RUNTIME_CLASS(CLTView), CSize(nRcWidth / 8 * 3, nRcHeight/2), pContext);
	m_spliter2.CreateView(1, 0, RUNTIME_CLASS(CLTView), CSize(nRcWidth / 8 * 3, nRcHeight/2), pContext);
	m_spliter2.CreateView(1, 1, RUNTIME_CLASS(CLTView), CSize(nRcWidth / 8 * 3, nRcHeight/2), pContext);

	return CFrameWnd::OnCreateClient(lpcs, pContext);
}
