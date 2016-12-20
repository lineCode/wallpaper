#pragma once
#include "afxcmn.h"

class CImagePathDlg : public CDialog
{
	DECLARE_DYNAMIC(CImagePathDlg)

public:
	CImagePathDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CImagePathDlg();

// �Ի�������
	enum { IDD = IDD_DLG_FOLDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
