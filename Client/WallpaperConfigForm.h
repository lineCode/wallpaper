#pragma once

class CWallpaperConfigForm : public CDialogEx
{
	DECLARE_DYNAMIC(CWallpaperConfigForm)

public:
	CWallpaperConfigForm(CWnd* pParent = NULL);   // standard constructor
	virtual ~CWallpaperConfigForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WALLPAPER_CONFIG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedOk();
	afx_msg void OnClickedCancel();
};
