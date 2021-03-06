#include "stdafx.h"
#include "Wallpaper.h"
#include "MainFrm.h"
#include "ConfigForm.h"
#include "WallpaperConfigForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_CONFIG_SETTING, &CMainFrame::OnConfigSetting)
	ON_COMMAND(ID_CONFIG_SEARCH_IMAGE, &CMainFrame::OnConfigSearchImage)
	ON_COMMAND(ID_CONFIG_EXIT, &CMainFrame::OnConfigExit)
	ON_COMMAND(ID_IMAGEPROCESS_OCR, &CMainFrame::OnImageprocessOcr)
	ON_COMMAND(ID_IMAGEPROCESS_ANALYZE, &CMainFrame::OnImageprocessAnalyze)
	ON_COMMAND(ID_WALLPAPER_CONFIG, &CMainFrame::OnWallpaperConfig)
	ON_COMMAND(ID_WALLPAPER_RUN, &CMainFrame::OnWallpaperRun)
	ON_COMMAND(ID_HELP_HOMEPAGE, &CMainFrame::OnHelpHomepage)
	ON_COMMAND(ID_HELP_HELP, &CMainFrame::OnHelpHelp)
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
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("未能创建视图窗口\n");
		return -1;
	}

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
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
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// 让视图第一次尝试该命令
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// 否则，执行默认处理
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void CMainFrame::OnConfigSetting()
{
	CConfigForm dlg;
	dlg.DoModal();
}


void CMainFrame::OnConfigSearchImage()
{
	// TODO: Add your command handler code here
}


void CMainFrame::OnConfigExit()
{
	// TODO: Add your command handler code here
}


void CMainFrame::OnImageprocessOcr()
{
	// TODO: Add your command handler code here
}


void CMainFrame::OnImageprocessAnalyze()
{
	// TODO: Add your command handler code here
}


void CMainFrame::OnWallpaperConfig()
{
	CWallpaperConfigForm dlg;
	dlg.DoModal();
}


void CMainFrame::OnWallpaperRun()
{
	// TODO: Add your command handler code here
}


void CMainFrame::OnHelpHomepage()
{
	// TODO: Add your command handler code here
}


void CMainFrame::OnHelpHelp()
{
	// TODO: Add your command handler code here
}