#pragma once


// CLeftView 视图

class CLeftView : public CTreeView
{
	DECLARE_DYNCREATE(CLeftView)

protected:
	CLeftView();           // 动态创建所使用的受保护的构造函数
	virtual ~CLeftView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


