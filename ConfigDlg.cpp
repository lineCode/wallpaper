#include "stdafx.h"
#include "Wallaper.h"
#include "ConfigDlg.h"
#include "ImagePathDlg.h"

extern GlobalSetting g_Setting;

IMPLEMENT_DYNAMIC(CConfigDlg, CDialog)
CConfigDlg::CConfigDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigDlg::IDD, pParent)
	, m_Style(0)
	, m_order(0)
	, m_strImagePath(_T(""))
{

}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_HOUR, m_cmbHour);
	DDX_Control(pDX, IDC_CMB_MINUTE, m_cmbMinute);
	DDX_Control(pDX, IDC_CMB_SECOND, m_cmbSecond);
	DDX_Text(pDX, IDC_EDIT_IMAGE_PATH, m_strImagePath);
	DDX_Control(pDX, IDC_CMB_STYLE, m_cmbStyle);
	DDX_Control(pDX, IDC_CMD_ORDER, m_cmbOrder);
}

BEGIN_MESSAGE_MAP(CConfigDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CConfigDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CConfigDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTN_IMAGE_PATH, &CConfigDlg::OnBnImagePath)
END_MESSAGE_MAP()

void CConfigDlg::OnBnClickedOk()
{
	UpdateData(FALSE);

	// ÅäÖÃ
	g_Setting.strFolderPath = m_strImagePath;
	int  hour		=	m_cmbHour.GetCurSel();
	int  minute		=	m_cmbMinute.GetCurSel();
	int  second		=	m_cmbSecond.GetCurSel();
	g_Setting.uiTimerSpan = hour * 60 * 60 + minute * 60 + second;
	if (g_Setting.uiTimerSpan == 0)  g_Setting.uiTimerSpan = 2 * 60 * 60;

	g_Setting.uiStyle	=	m_cmbStyle.GetCurSel();
	g_Setting.order		=	(m_cmbOrder.GetCurSel() == 0) ? enumOrder::Random : enumOrder::Sequence;

	CWnd*  pWnd  =  GetDlgItem(IDC_CHECK_AUTOSTART);
	if (pWnd != NULL && pWnd->GetSafeHwnd() != NULL)
	{
		g_Setting.bAutoRun = ((CButton*)pWnd)->GetCheck();
	}
	SetAutoRun(g_Setting.bAutoRun);
	OnOK();
}

void CConfigDlg::OnBnClickedCancel()
{
	OnCancel();
}

BOOL CConfigDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CString  strText;
	for(int i = 0; i < 23; ++i)
	{
		strText.Format(_T("%d"), i);
		m_cmbHour.AddString(strText);
	}
	for(int i = 0; i <= 59; ++i)
	{
		strText.Format(_T("%d"), i);
		m_cmbMinute.AddString(strText);
	}
	for(int i = 0; i <= 59; i++)
	{
		strText.Format(_T("%d"), i);
		m_cmbSecond.AddString(strText);
	}

	//WPSTYLE_CENTER ¾ÓÖÐ 0
	//WPSTYLE_TILE Æ½ÆÌ 1
	//WPSTYLE_STRETCH À­Éì 2
	m_cmbStyle.AddString(_T("Center"));
	m_cmbStyle.AddString(_T("Title"));
	m_cmbStyle.AddString(_T("Stretch"));
	m_cmbStyle.AddString(_T("Max"));
	m_cmbStyle.AddString(_T("Crop To Fit Screen"));

	m_cmbOrder.AddString(_T("Random"));
	m_cmbOrder.AddString(_T("Sequence"));

	// ÅäÖÃ
	m_strImagePath = g_Setting.strFolderPath;
	int  timeSpan = g_Setting.uiTimerSpan;
	int  second = timeSpan % 60;
	timeSpan /= 60;
	int  minute = timeSpan % 60;
	timeSpan /= 60;
	int  hour = timeSpan;
	
	m_cmbHour.SetCurSel(hour);
	m_cmbMinute.SetCurSel(minute);
	m_cmbSecond.SetCurSel(second);

	m_Style = g_Setting.uiStyle;
	m_cmbStyle.SetCurSel(m_Style);

	m_order = g_Setting.order;
	m_cmbOrder.SetCurSel(m_order);

	CWnd*  pWnd  =  GetDlgItem(IDC_CHECK_AUTOSTART);
	if (pWnd != NULL && pWnd->GetSafeHwnd() != NULL)
	{
		((CButton*)pWnd)->SetCheck(g_Setting.bAutoRun);
	}
	UpdateData(FALSE);
	return TRUE;
}

void CConfigDlg::OnBnImagePath()
{

	CImagePathDlg  dlg;
	dlg.m_strPath = m_strImagePath;
	dlg.DoModal();
	m_strImagePath = dlg.m_strPath;
	
	UpdateData(FALSE);
}

void CConfigDlg::SetAutoRun(BOOL bAutoRun)
{
	CRegKey regkey;
	TCHAR modbuffer[MAX_PATH];
	DWORD dwModPathLen = ::GetModuleFileName(NULL, modbuffer, _countof(modbuffer));
	if (dwModPathLen == 0 || dwModPathLen == _countof(modbuffer))
		return;
	CString strCanonFileName = modbuffer;
	strCanonFileName.Replace(_T("%"), _T("%%"));
	CString regbuffer;
	regbuffer.Format(_T("\"%s\""), strCanonFileName);
	CString	csKeyName = _T("");

	HKEY RegKey = NULL;
	HKEY hkeyCR = HKEY_LOCAL_MACHINE;
	if (bAutoRun)
	{
		LONG lResult = RegOpenKey(hkeyCR, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &RegKey);
		if (lResult == ERROR_SUCCESS)
		{
			LPCTSTR lpszValue = regbuffer;
			RegSetValueEx(RegKey, csKeyName, 0, REG_SZ,(const unsigned char*)lpszValue, (_tcslen(lpszValue) + 1) * sizeof(TCHAR));
			RegCloseKey(RegKey);
		}
	}
	else
	{
		LONG lResult = RegOpenKey(hkeyCR, L"Software\\Microsoft\\Windows\\CurrentVersion\\Run", &RegKey);
		if (lResult == ERROR_SUCCESS)
		{
			RegDeleteValue(RegKey, csKeyName);
			RegCloseKey(RegKey);
		}
	}
}