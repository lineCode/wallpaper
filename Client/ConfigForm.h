#pragma once


// CConfigForm dialog

class CConfigForm : public CDialogEx
{
	DECLARE_DYNAMIC(CConfigForm)

public:
	CConfigForm(CWnd* pParent = NULL);   // standard constructor
	virtual ~CConfigForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONFIGFORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
