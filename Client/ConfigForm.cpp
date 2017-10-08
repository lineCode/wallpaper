#include "stdafx.h"
#include "Wallpaper.h"
#include "ConfigForm.h"
#include "afxdialogex.h"
#include "resource.h"
#include "common.h"
#include "Setting.h"

IMPLEMENT_DYNAMIC(CConfigForm, CDialogEx)

CConfigForm::CConfigForm(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONFIGFORM, pParent)
{

}

CConfigForm::~CConfigForm()
{
}

void CConfigForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfigForm, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CConfigForm::OnClickedOK)
END_MESSAGE_MAP()


// CConfigForm message handlers


void CConfigForm::OnClickedOK()
{
	TCHAR szPathName[MAX_PATH] = { 0 };
	BROWSEINFO bInfo = { 0 };
	bInfo.hwndOwner = ::GetForegroundWindow();//父窗口    
	bInfo.lpszTitle = TEXT("浏览文件夹");
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_USENEWUI/*包含一个编辑框 用户可以手动填写路径 对话框可以调整大小之类的..*/ |
		BIF_UAHINT/*带TIPS提示*/ | BIF_NONEWFOLDERBUTTON /*不带新建文件夹按钮*/;
	LPITEMIDLIST lpDlist;
	lpDlist = SHBrowseForFolder(&bInfo);
	if (lpDlist != NULL)
	{
		SHGetPathFromIDList(lpDlist, szPathName);
		xstring sPath = szPathName;
		SetDlgItemText(IDC_IMGFOLDER, sPath.c_str());

		CSetting::Get().m_imageFolder = sPath;
	}
}
