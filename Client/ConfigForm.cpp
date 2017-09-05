// ConfigForm.cpp : implementation file
//

#include "stdafx.h"
#include "Wallpaper.h"
#include "ConfigForm.h"
#include "afxdialogex.h"


// CConfigForm dialog

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
END_MESSAGE_MAP()


// CConfigForm message handlers
