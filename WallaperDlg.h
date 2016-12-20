#pragma once
#include "afxwin.h"

class CWallpaperDlg : public CDialog
{
// 构造
public:
	CWallpaperDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DESKTOP };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	BOOL SetWallpaper(CString &strPicFile, DWORD dwStyle);
	LRESULT OnTrayNotify(WPARAM wParam, LPARAM lParam);
	BOOL MinimizeMyWindows();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnSaveSetting();
	afx_msg LRESULT OnTaskBarCreated(WPARAM /*wParam*/, LPARAM /*lParam*/);
	void FileSearch(CString root);
	void ShowDialog();
	void SetAutoRun(BOOL bAutoRun);
	void Run();
	void Stop();

	CStringArray		m_arrImageList;
	NOTIFYICONDATA		m_nidIconData;
	BOOL				m_bTrayIconVisible;
	BOOL				m_bLButtonDblClk;

public:
	afx_msg void OnDestroy();
	afx_msg void OnTrayIconShowDialog();
	afx_msg void OnTrayiconExit();
	afx_msg void OnBnRun();
	void SetNextBKImage();
	int  GetNextImageIndex();
	void AllImageSearch();
	void SetRunState(BOOL isRun);

private:
	CImage  m_ImageInfo;

public:
	afx_msg void OnHelp();
	afx_msg void OnAbout();
	afx_msg void OnExit();
	void BnRun();
	int m_ImageWidth;
	int m_ImageHeight;
	CRect  m_ImageCtrlRect;
	CString  m_strImagePath;

protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedBtnNext();
};
