#pragma once
#include "afxcmn.h"

class CImagePathDlg : public CDialog
{
	DECLARE_DYNAMIC(CImagePathDlg)

public:
	CImagePathDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CImagePathDlg();

// 对话框数据
	enum { IDD = IDD_DLG_FOLDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CListCtrl m_CtrlPath;
public:
	afx_msg void OnBnDel();
	afx_msg void OnBnClear();
	afx_msg void OnBnSave();
	afx_msg void OnBnCancel();
	virtual BOOL OnInitDialog();
	CString		m_strPath;
	afx_msg void OnDropFiles(HDROP hDropInfo);
};
