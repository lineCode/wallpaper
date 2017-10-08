#include "stdafx.h"
#include "Wallpaper.h"
#include "WallpaperConfigForm.h"
#include "afxdialogex.h"
#include "common.h"
#include "Setting.h"

IMPLEMENT_DYNAMIC(CWallpaperConfigForm, CDialogEx)
CWallpaperConfigForm::CWallpaperConfigForm(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WALLPAPER_CONFIG, pParent)
{

}

CWallpaperConfigForm::~CWallpaperConfigForm()
{
}

void CWallpaperConfigForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CWallpaperConfigForm, CDialogEx)
	ON_BN_CLICKED(IDOK, &CWallpaperConfigForm::OnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CWallpaperConfigForm::OnClickedCancel)
END_MESSAGE_MAP()

BOOL CWallpaperConfigForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	((CComboBox*)GetDlgItem(IDC_DISPLAYTYPE))->AddString(L"填充");
	((CComboBox*)GetDlgItem(IDC_DISPLAYTYPE))->AddString(L"适应");
	((CComboBox*)GetDlgItem(IDC_DISPLAYTYPE))->AddString(L"拉伸");
	((CComboBox*)GetDlgItem(IDC_DISPLAYTYPE))->AddString(L"平铺");
	((CComboBox*)GetDlgItem(IDC_DISPLAYTYPE))->AddString(L"居中");
	((CComboBox*)GetDlgItem(IDC_DISPLAYTYPE))->SetCurSel(3);

	// 添加时间
	for (int i = 0; i < 24; ++i)
	{
		xstring str = int2wxstr(i);
		((CComboBox*)GetDlgItem(IDC_HOUR))->AddString(str.c_str());
	}
	((CComboBox*)GetDlgItem(IDC_HOUR))->SetCurSel(0);

	for (int i = 0; i < 60; ++i)
	{
		xstring str = int2wxstr(i);
		((CComboBox*)GetDlgItem(IDC_MINUTE))->AddString(str.c_str());
	}
	((CComboBox*)GetDlgItem(IDC_MINUTE))->SetCurSel(3);

	for (int i = 0; i < 60; ++i)
	{
		xstring str = int2wxstr(i);
		((CComboBox*)GetDlgItem(IDC_SECOND))->AddString(str.c_str());
	}
	((CComboBox*)GetDlgItem(IDC_SECOND))->SetCurSel(0);

	return TRUE;
}

void CWallpaperConfigForm::OnClickedOk()
{
	int displayType = (int)((CComboBox*)(GetDlgItem(IDC_DISPLAYTYPE)))->GetCurSel();
	CSetting::Get().wallpaper.display_type = displayType;
	
	int hour = ((CComboBox*)GetDlgItem(IDC_HOUR))->GetCurSel();
	int minute = ((CComboBox*)GetDlgItem(IDC_MINUTE))->GetCurSel();
	int second = ((CComboBox*)GetDlgItem(IDC_SECOND))->GetCurSel();
	int span = second + minute * 60 + hour * 60 * 60;
	CSetting::Get().wallpaper.time_span = span;

	bool isAutoRun = ((CButton*)GetDlgItem(IDC_AUTORUN))->GetCheck() != 0;
	CSetting::Get().wallpaper.is_auto_run = isAutoRun;

	CDialogEx::OnOK();
}

void CWallpaperConfigForm::OnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
