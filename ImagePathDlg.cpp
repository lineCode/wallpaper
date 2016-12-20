#include "stdafx.h"
#include "Wallaper.h"
#include "ImagePathDlg.h"

IMPLEMENT_DYNAMIC(CImagePathDlg, CDialog)
CImagePathDlg::CImagePathDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImagePathDlg::IDD, pParent)
{

}

CImagePathDlg::~CImagePathDlg()
{
}

void CImagePathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_IMAGE_PATH, m_CtrlPath);
}

BEGIN_MESSAGE_MAP(CImagePathDlg, CDialog)
	ON_BN_CLICKED(IDC_BTN_IPCD_DEL, &CImagePathDlg::OnBnDel)
	ON_BN_CLICKED(IDC_BTN_IPCD_CLEAR, &CImagePathDlg::OnBnClear)
	ON_BN_CLICKED(IDC_BTN_IPCD_SAVE, &CImagePathDlg::OnBnSave)
	ON_BN_CLICKED(IDC_BTN_IPCD_CANCEL, &CImagePathDlg::OnBnCancel)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()

void CImagePathDlg::OnBnDel()
{
	CArray<int>  delList;
	POSITION  pos = m_CtrlPath.GetFirstSelectedItemPosition();
	while(pos)
	{
		int  itemIndex = m_CtrlPath.GetNextSelectedItem(pos);
		delList.Add(itemIndex);
	}
	for(int i = delList.GetCount() - 1; i >= 0; i--)
	{
		m_CtrlPath.DeleteItem(delList[i]);
	}
}

void CImagePathDlg::OnBnClear()
{
	m_CtrlPath.DeleteAllItems();
}

void CImagePathDlg::OnBnSave()
{
	CString  strPath;
	// 保存文件夹路径
	BOOL  isFirst = TRUE;
	for(int i = 0; i < m_CtrlPath.GetItemCount(); ++i)
	{
		if (!isFirst)  strPath += _T(";");
		if (isFirst)  isFirst = FALSE;
		strPath += m_CtrlPath.GetItemText(i, 0);
	}
	m_strPath = strPath;
	EndDialog(IDOK);
}

void CImagePathDlg::OnBnCancel()
{
	EndDialog(IDCANCEL);
}

BOOL CImagePathDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_CtrlPath.InsertColumn(0, _T("Path"), LVSCW_AUTOSIZE, 350);
	m_CtrlPath.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CString  strPath = m_strPath;
	if (strPath.IsEmpty())  return TRUE;
	int  nPos  =  strPath.Find(';');
	while(nPos >= 0)
	{
		CString  strSubString = strPath.Left(nPos);
		strPath = strPath.Right(strPath.GetLength() - nPos - 1);
		nPos = strPath.Find(';');
		if (!strSubString.IsEmpty())
			m_CtrlPath.InsertItem(m_CtrlPath.GetItemCount(), strSubString);
	}
	if (!strPath.IsEmpty())  m_CtrlPath.InsertItem(m_CtrlPath.GetItemCount(), strPath);

	return TRUE;
}

void CImagePathDlg::OnDropFiles(HDROP hDropInfo)
{
	CDialog::OnDropFiles(hDropInfo);

	AfxMessageBox(_T("Drap"));
	// 拖拽操作
	TCHAR  szFileName[MAX_PATH + 1]={0};
	UINT  dwFileCount  =  DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);
	CStringArray  m_strList;
	for(UINT i = 0; i < dwFileCount; ++i)
	{
		DragQueryFile(hDropInfo, i, szFileName, MAX_PATH);
		m_strList.Add(szFileName);
	}
	DragFinish(hDropInfo);

	CStringArray  arrFilePath;
	for(int i = 0; i < m_strList.GetCount(); ++i)
	{
		CString  strFileName  =  m_strList.GetAt(i);
		if (strFileName.IsEmpty())  continue;

		try
		{
			DWORD  attributes  =  GetFileAttributes(strFileName);
			if (INVALID_FILE_ATTRIBUTES  == attributes)continue;

			if ((attributes & FILE_ATTRIBUTE_HIDDEN) || (attributes & FILE_ATTRIBUTE_SYSTEM)) continue;
			if (attributes & FILE_ATTRIBUTE_DIRECTORY) 
			{
				BOOL  isExist = FALSE;
				for(int j = 0; j < m_CtrlPath.GetItemCount(); ++j)
				{
					CString  strTempPath = m_CtrlPath.GetItemText(j, 0);
					if (strFileName.Compare(strTempPath) == 0)
					{
						isExist = TRUE;
						break;
					}
				}
				if (!isExist)
					m_CtrlPath.InsertItem(m_CtrlPath.GetItemCount(), strFileName);
			}
		}
		catch (CException* e)
		{
		}
	}
	Invalidate(TRUE);
}
