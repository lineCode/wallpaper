
// MainFrm.h : CMainFrame 类的接口
//

#pragma once
#include "ChildView.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	CChildView    m_wndView;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnConfigSetting();
	afx_msg void OnConfigSearchImage();
	afx_msg void OnConfigExit();
	afx_msg void OnImageprocessOcr();
	afx_msg void OnImageprocessAnalyze();
	afx_msg void OnWallpaperConfig();
	afx_msg void OnWallpaperRun();
	afx_msg void OnHelpHomepage();
	afx_msg void OnHelpHelp();
	afx_msg void OnHelpAbout();
};


