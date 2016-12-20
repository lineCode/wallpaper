#include "stdafx.h"
#include "Wallaper.h"
#include "WallaperDlg.h"
#include <shlobj.h>
#include "common.h"
#include "ConfigDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const UINT WM_TASKBARCREATED = ::RegisterWindowMessage(_T("TaskbarCreated"));
#define MAX_LENGTH 256

GlobalSetting  g_Setting;

CWallpaperDlg::CWallpaperDlg(
	CWnd* pParent/* = NULL*/)
	: CDialog(CWallpaperDlg::IDD, pParent)
	, m_ImageWidth(0)
	, m_ImageHeight(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bTrayIconVisible	=	FALSE;
	m_bLButtonDblClk	=	FALSE;
}

void CWallpaperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LABEL_CURRENT_IMAGEPATH, m_strImagePath);
	DDX_Text(pDX, IDC_LABEL_IMG_WIDTH, m_ImageWidth);
	DDX_Text(pDX, IDC_LABEL_IMG_HEIGHT, m_ImageHeight);
}

BEGIN_MESSAGE_MAP(CWallpaperDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_SAVESETTING, &CWallpaperDlg::OnBnSaveSetting)
	ON_WM_DESTROY()
	ON_MESSAGE(TRAY_ICON_NOTIFY_MESSAGE, OnTrayNotify)
	ON_COMMAND(ID_TRAYICON_SHOWDIALOG, &CWallpaperDlg::OnTrayIconShowDialog)
	ON_COMMAND(ID_TRAYICON_EXIT, &CWallpaperDlg::OnTrayiconExit)
	ON_REGISTERED_MESSAGE(WM_TASKBARCREATED, OnTaskBarCreated)
	ON_BN_CLICKED(IDC_BUTTON_RUN, &CWallpaperDlg::OnBnRun)
	ON_COMMAND(ID_ABOUT_ABOUT, &CWallpaperDlg::OnAbout)
	ON_COMMAND(ID_ABOUT_EXIT, &CWallpaperDlg::OnExit)
	ON_BN_CLICKED(IDC_BTN_HELP, &CWallpaperDlg::OnHelp)
	ON_WM_SHOWWINDOW()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BTN_NEXT, &CWallpaperDlg::OnBnClickedBtnNext)
END_MESSAGE_MAP()

BOOL CWallpaperDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	ShowWindow(SW_MINIMIZE);

	/*
	WPSTYLE_CENTER (0x0)

	0x0. Center the wallpaper image in its original size, filling the remaining area with a solid background color if image is smaller than screen or cropping image if image is larger.

	WPSTYLE_TILE (0x1)

	0x1. Tile the wallpaper image, starting in the upper left corner of the screen. This uses the image in its original size.

	WPSTYLE_STRETCH (0x2)

	0x2. Stretch the image to cover the full screen. This can result in distortion of the image as the image's aspect ratio is not retained.

	WPSTYLE_KEEPASPECT (0x3)

	0x3. Windows 7 and later only. Enlarge or shrink the image to fill the screen, retaining the aspect ratio of the original image. If necessary, the image is padded either on the top and bottom or on the right and left with the background color to fill any screen area not covered by the image.

	WPSTYLE_CROPTOFIT (0x4)

	0x4. Windows 7 and later only. Enlarge or shrink the image to fill the screen, retaining the aspect ratio of the original image. If necessary, the image is cropped either on the top and bottom or on the left and right as necessary to fit the screen.

	WPSTYLE_MAX

	*/

	// ϵͳ����
	TCHAR tchBuffer[MAX_PATH];
	ZeroMemory(tchBuffer, MAX_PATH);
	::GetModuleFileName(NULL, tchBuffer, _countof(tchBuffer));
	tchBuffer[_countof(tchBuffer) - 1] = _T('\0');
	LPTSTR pszFileName = _tcsrchr(tchBuffer, L'\\') + 1;
	*pszFileName = L'\0';
	CString		csCurrentDir = tchBuffer;
	CString		csConfigFile = m_csIniFile;
	m_csIniFile.Format(_T("%s\\%s"), csCurrentDir, csConfigFile);

	// ��������ͼ��
	ZeroMemory(&m_nidIconData, sizeof(NOTIFYICONDATA));
	m_nidIconData.cbSize = NOTIFYICONDATA_V1_SIZE;
	m_nidIconData.hWnd = this->m_hWnd;
	m_nidIconData.uID = IDR_MAINFRAME;
	m_nidIconData.uCallbackMessage = TRAY_ICON_NOTIFY_MESSAGE;
	m_nidIconData.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	CString		csTitle;
	this->GetWindowText(csTitle);
	lstrcpy(m_nidIconData.szTip, (LPCTSTR)csTitle);
	m_nidIconData.uFlags =  NIF_MESSAGE | NIF_ICON | NIF_TIP;
	
	g_Setting.LoadConfig(m_csIniFile);
	UpdateData(FALSE);
	return TRUE;
}

void CWallpaperDlg::Stop()
{
	KillTimer(100);
}

void CWallpaperDlg::Run()
{
	AllImageSearch();

	if (m_arrImageList.GetCount() == 0)  return;
	srand((unsigned)time(NULL));
	SetTimer(100, g_Setting.uiTimerSpan * 1000, NULL);
}

LRESULT CWallpaperDlg::OnTrayNotify(WPARAM wParam, LPARAM lParam)
{
	//UINT uID = (UINT)wParam;
	//if (uID != 1)
	//	return 0;

	CPoint pt;
	UINT uMsg = (UINT)lParam;
	switch (uMsg)
	{ 
	case WM_MOUSEMOVE:
		break;

	case WM_LBUTTONDOWN:
		break;

	case WM_LBUTTONUP:
		break;

	case WM_LBUTTONDBLCLK:
		ShowDialog();
		break;

	case WM_RBUTTONUP:
		{
			LPPOINT lpoint = new tagPOINT;
			::GetCursorPos(lpoint);

			CMenu	tempMenu;
			tempMenu.LoadMenu(IDR_MENUTRAYICON);

			CMenu*	popMenu = tempMenu.GetSubMenu(0);
			ASSERT(popMenu != NULL);
			popMenu->TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this,NULL);
			popMenu->DestroyMenu();
		}
		break;

	case WM_CONTEXTMENU:
		break;

	case WM_RBUTTONDBLCLK:
		break;
	} 
	return 0;
}

void CWallpaperDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if(nID == SC_MINIMIZE)
	{
		MinimizeMyWindows();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CWallpaperDlg::ShowDialog()
{
	// ����ͼ��
	BOOL bSuccess = Shell_NotifyIcon(NIM_DELETE, &m_nidIconData);
	//if (bSuccess)
	{
		//KillTimer(100);
		m_bTrayIconVisible = FALSE;
		ModifyStyleEx(WS_EX_TOOLWINDOW, 0);
		SetForegroundWindow();
		//this->ShowWindow(SW_SHOWDEFAULT);
		//ShowWindow(SW_MINIMIZE);
		//this->ShowWindow(SW_RESTORE);
		this->ShowWindow(SW_SHOW);
	}
}

LRESULT CWallpaperDlg::OnTaskBarCreated(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
	if (m_bTrayIconVisible)
	{
		BOOL bResult = Shell_NotifyIcon(NIM_ADD, &m_nidIconData);
		if (!bResult)
			m_bTrayIconVisible = false;
	}
	return 0;
}

void CWallpaperDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		if (!m_strImagePath.IsEmpty())
		{
			m_ImageInfo.Load(m_strImagePath);
			if (!m_ImageInfo.IsNull())
			{
				RECT  rect;
				GetDlgItem(IDC_CTRL_IMAGE)->GetWindowRect(&rect);
				this->ScreenToClient(&rect);
				m_ImageCtrlRect   =  rect;
				int  areaStartX  =  m_ImageCtrlRect.left;
				int  areaStartY  =  m_ImageCtrlRect.top;
				int  areaWidth  =  m_ImageCtrlRect.Width();
				int  areaHeight  =  m_ImageCtrlRect.Height();
				double  heightFact = m_ImageInfo.GetHeight() / (areaHeight + 0.00);
				double  widthFact  =  m_ImageInfo.GetWidth() / (areaWidth + 0.00);
				double  fact =  (heightFact > widthFact) ? heightFact : widthFact;
				if (fact < 1) fact = 1;
				if (fact != 0)
				{
					int  imgWidth  =  m_ImageInfo.GetWidth() / fact;
					int  imgHeight  =  m_ImageInfo.GetHeight() / fact;
					// �������Ͻ�λ��
					areaStartX += (areaWidth - imgWidth) / 2;
					areaStartY += (areaHeight - imgHeight) / 2;
					dc.SetStretchBltMode(HALFTONE);
					m_ImageInfo.StretchBlt(dc, areaStartX, areaStartY, imgWidth, imgHeight, SRCCOPY);
				}
			}
			if (!m_ImageInfo.IsNull())  m_ImageInfo.Detach();
		}
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CWallpaperDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CWallpaperDlg::SetWallpaper(CString &strPicFile, DWORD dwStyle)
{
	m_strImagePath  =  strPicFile;

	m_ImageInfo.Load(strPicFile);
	m_ImageWidth  =  m_ImageInfo.GetWidth();
	m_ImageHeight  =  m_ImageInfo.GetHeight();
	if (!m_ImageInfo.IsNull())  m_ImageInfo.Detach();
	Invalidate(TRUE);
	UpdateData(FALSE);

	HRESULT hr;
	IActiveDesktop* pIAD;
	//�����ӿڵ�ʵ��
	hr = CoCreateInstance ( CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,       
		IID_IActiveDesktop, (void**) &pIAD );
	if(!SUCCEEDED(hr)) return FALSE;
	//���ļ�����Ϊ���ַ���,����IActiveDesktop::SetWallpaper��Ҫ��
	WCHAR   wszWallpaper [MAX_PATH];
	ZeroMemory(wszWallpaper, MAX_PATH);

	LPTSTR lpStr = strPicFile.GetBuffer(strPicFile.GetLength());
	#ifdef	UNICODE
	wcscpy_s(wszWallpaper, lpStr);
	#else
	MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszWallpaper, MAX_PATH);
	#endif
	strPicFile.ReleaseBuffer();
	//����ǽֽ
	hr = pIAD->SetWallpaper(wszWallpaper, 0);
	if(!SUCCEEDED(hr)) return FALSE;
	//����ǽֽ����ʽ
	WALLPAPEROPT wpo;
	wpo.dwSize = sizeof(wpo);
	wpo.dwStyle = dwStyle;
	hr = pIAD->SetWallpaperOptions(&wpo, 0);
	if(!SUCCEEDED(hr)) 
		return FALSE;
	//Ӧ��ǽֽ������
	hr = pIAD->ApplyChanges(AD_APPLY_ALL);
	if(!SUCCEEDED(hr)) return FALSE;
	//��ȡǽֽ���ļ�������ӡ��debug������
	hr = pIAD->GetWallpaper(wszWallpaper, MAX_PATH, 0);
	//TRACE(strFile); //�������λͼ�Ļ�,�����������벻���ķ���
	//�ͷŽӿڵ�ʵ��
	pIAD->Release();
	return TRUE;
}

void CWallpaperDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 100:
		SetNextBKImage();
		break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CWallpaperDlg::OnBnSaveSetting()
{
	SetRunState(FALSE);
	CConfigDlg  dlg;
	dlg.DoModal();
}

void CWallpaperDlg::AllImageSearch()
{
	m_arrImageList.RemoveAll();
	CString  strPath = g_Setting.strFolderPath;
	int  nPos  =  strPath.Find(';');
	while(nPos >= 0)
	{
		CString  strSubString = strPath.Left(nPos - 1);
		strPath = strPath.Right(strPath.GetLength() - nPos - 1);
		nPos = strPath.Find(';');
		if (!strSubString.IsEmpty())
			FileSearch(strSubString);
	}
	if (!strPath.IsEmpty())  FileSearch(strPath);
}

void CWallpaperDlg::FileSearch(CString root)
{
	root.Trim();
	if (root.IsEmpty())
		return;

	// root ΪĿ¼��
	CFileFind ff;
	CString FilePath;
	if (root.Right(1)!="\\") 
	{
			root+="\\";
	}
	root += _T("*.*");
	BOOL res = ff.FindFile(root);
	while (res)
	{
		res = ff.FindNextFile();
		FilePath = ff.GetFilePath();
		if (ff.IsDirectory() && !ff.IsDots())// �ҵ������ļ���
		{
			FileSearch(FilePath);// �ݹ�
		}
		else if (!ff.IsDirectory() && !ff.IsDots())// �ҵ������ļ�
		{
			// if jpg bmp gif
			int nIndexLastDot = FilePath.ReverseFind('.');
			if (nIndexLastDot > 0)
			{
				CString		csFileType = FilePath.Right(FilePath.GetLength() - nIndexLastDot - 1);
				csFileType.MakeLower();
				if (csFileType.Compare(_T("jpg")) == 0
					|| csFileType.Compare(_T("bmp")) == 0
					|| csFileType.Compare(_T("gif")) == 0
					|| csFileType.Compare(_T("png")) == 0)
				{
					m_arrImageList.Add(FilePath);
				}
			}
		}
	}
}

void CWallpaperDlg::OnDestroy()
{
	g_Setting.SaveConfig(m_csIniFile);

	if (m_bTrayIconVisible)
		VERIFY(Shell_NotifyIcon(NIM_DELETE, &m_nidIconData));
	CDialog::OnDestroy();
}

void CWallpaperDlg::OnTrayIconShowDialog()
{
	ShowDialog();
}

void CWallpaperDlg::OnTrayiconExit()
{
	this->DestroyWindow();
}

void CWallpaperDlg::SetRunState(BOOL isRun)
{
	CWnd*  pWnd  =  GetDlgItem(IDC_BUTTON_RUN);
	if (!(pWnd != NULL  && pWnd->GetSafeHwnd() != NULL))  return;

	if (isRun)
	{
		if (!(g_Setting.strFolderPath.IsEmpty()))
		{
			Run();
			pWnd->SetWindowText(_T("Stop"));
			return;
		}
	}
	else
	{
		Stop();
	}
	pWnd->SetWindowText(_T("Run"));
}

void CWallpaperDlg::OnBnRun()
{
	UpdateData(TRUE);

	CWnd*  pWnd  =  GetDlgItem(IDC_BUTTON_RUN);
	if (pWnd != NULL  && pWnd->GetSafeHwnd() != NULL)
	{
		CString  strText(_T(""));
		pWnd->GetWindowText(strText);
		if (strText.Compare(_T("Run")) == 0)
			SetRunState(TRUE);
		else
			SetRunState(FALSE);
	}
}

void CWallpaperDlg::OnHelp()
{
	ShellExecute(NULL, _T("open"), _T("https://github.com/ITCoolie"), NULL, NULL, SW_SHOWNORMAL);
}

void CWallpaperDlg::OnAbout()
{
}

void CWallpaperDlg::OnExit()
{
	EndDialog(IDOK);
}

BOOL CWallpaperDlg::PreCreateWindow(CREATESTRUCT& cs)
{
	//cs.style  |= WS_MAXIMIZEBOX | WS_CAPTION | WS_MAXIMIZEBOX;
	return CDialog::PreCreateWindow(cs);
}

BOOL CWallpaperDlg::PreTranslateMessage(MSG* pMsg)
{
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CWallpaperDlg::MinimizeMyWindows()
{
	// ��������ͼ��
	BOOL bSuccess = Shell_NotifyIcon(NIM_ADD, &m_nidIconData);
	m_bTrayIconVisible = TRUE;
	ModifyStyleEx(0, WS_EX_TOOLWINDOW);
	this->ShowWindow(SW_HIDE);
	return TRUE;
}

void CWallpaperDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);
	static  BOOL  isFirstShow  =  TRUE;
	if (isFirstShow)
	{
		isFirstShow = FALSE;
	}
}

void CWallpaperDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	try
	{
		if (!m_strImagePath.IsEmpty())
		{
			POINT  pt;
			GetCursorPos(&pt);
			CRect  rect;
			GetDlgItem(IDC_CTRL_IMAGE)->GetClientRect(rect);
			GetDlgItem(IDC_CTRL_IMAGE)->ClientToScreen(rect);
			if (rect.PtInRect(pt))
			{
				ShellExecute(this->m_hWnd, _T("open"), m_strImagePath, NULL, NULL, SW_SHOWNORMAL); 
			}
		}
	}
	catch (CException* e)
	{
	}
	CDialog::OnLButtonDblClk(nFlags, point);
}

void CWallpaperDlg::OnBnClickedBtnNext()
{
	SetNextBKImage();
}

void CWallpaperDlg::SetNextBKImage()
{
	int  index = GetNextImageIndex();
	if (index == -1)  return;

	CString  strImageFile = m_arrImageList[index];
	SetWallpaper(strImageFile, g_Setting.uiStyle);
}

int  CWallpaperDlg::GetNextImageIndex()
{
	if (m_arrImageList.GetCount() == 0)  return -1;

	int  imageIndex = g_Setting.imageIndex;
	if (g_Setting.order == enumOrder::Random)
	{
		imageIndex = rand();
		imageIndex %= m_arrImageList.GetCount();
	}
	else
	{
		imageIndex++;
		if (imageIndex < 0 || imageIndex >= m_arrImageList.GetCount())
		{
			imageIndex = 0;
		}
	}
	return (g_Setting.imageIndex = imageIndex);
}