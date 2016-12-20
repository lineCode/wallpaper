#pragma once
#include "afxwin.h"

class CConfigDlg : public CDialog
{
	DECLARE_DYNAMIC(CConfigDlg)

public:
	CConfigDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfigDlg();

// 对话框数据
	enum { IDD = IDD_DLG_CONFIG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cmbHour;
	CComboBox m_cmbMinute;
	CComboBox m_cmbSecond;
	int  m_TimeSpan;
	int m_Style;
	int m_order;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CString m_strImagePath;
	CComboBox m_cmbStyle;
	CComboBox m_cmbOrder;
	afx_msg void OnBnImagePath();
	void SetAutoRun(BOOL bAutoRun);
};
