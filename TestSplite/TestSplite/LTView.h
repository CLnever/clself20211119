#pragma once


// CLTView 视图

class CLTView : public CView
{
	DECLARE_DYNCREATE(CLTView)

protected:
	CLTView();           // 动态创建所使用的受保护的构造函数
	virtual ~CLTView();

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


