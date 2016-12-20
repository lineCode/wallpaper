#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的资料
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC 核心组件和标准组件
#include <wininet.h> // NOTE: corrects compilation errors w/IActiveDesktop!! 
#include <afxext.h>         // MFC 扩展


#include <afxdisp.h>        // MFC 自动化类

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // 功能区和控件条的 MFC 支持

#define	TRAY_ICON_NOTIFY_MESSAGE		(WM_USER + 0x100 + 1)

#include "common.h"

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

enum enumOrder{
	Random = 0,
	Sequence
};

class  GlobalSetting
{
public:
	CString		strFolderPath;		// 保存图像文件夹路径，用;区分
	UINT		uiTimerSpan;		// 事件间隔，秒
	BOOL		bAutoRun;			// 自动运行
	enumOrder	order;				// 随机、顺序
	int			imageIndex;			// 图片索引
	UINT		uiStyle;			// 样式

	GlobalSetting()
	{
		strFolderPath	=	_T("");
		uiTimerSpan		=	2 * 60 * 60;
		bAutoRun		=	FALSE;
		order			=	Random;
		imageIndex		=	-1;
		uiStyle			=	0;
	}

	int LoadConfig(const  CString&  filePath)
	{
		// check file path
		TCHAR	szImagePath[MAX_PATH];
		ZeroMemory(szImagePath, MAX_PATH * sizeof(TCHAR));
		GetPrivateProfileString(_T("setting"), 
			_T("ImagePath"),
			_T(""), 
			szImagePath,
			MAX_PATH,
			filePath);
		strFolderPath = szImagePath;

		uiTimerSpan	= GetPrivateProfileInt(_T("setting"), _T("TimeSpan"), 2 * 60 * 60, filePath);
		bAutoRun = GetPrivateProfileInt(_T("setting"), _T("AutoRun"), FALSE, filePath);
		order  =  (enumOrder)GetPrivateProfileInt(_T("setting"), _T("Order"), 0, filePath);
		imageIndex  =  GetPrivateProfileInt(_T("setting"), _T("ImageIndex"), -1, filePath);
		uiStyle = GetPrivateProfileInt(_T("setting"), _T("Style"), 0, filePath);
		return 0;
	}

	void SaveConfig(const CString&  filePath)
	{
		WritePrivateProfileString(_T("setting"), _T("ImagePath"), strFolderPath, filePath);

		TCHAR szBuffer[MAX_PATH];
		ZeroMemory(szBuffer, MAX_PATH * sizeof(TCHAR));
		_itot(uiTimerSpan, szBuffer, 10);
		WritePrivateProfileString(_T("setting"), _T("TimeSpan"), szBuffer, filePath);

		ZeroMemory(szBuffer, MAX_PATH * sizeof(TCHAR));
		_itot(bAutoRun, szBuffer, 10);		
		WritePrivateProfileString(_T("setting"), _T("AutoRun"), szBuffer, filePath);

		ZeroMemory(szBuffer, MAX_PATH * sizeof(TCHAR));
		_itot(order, szBuffer, 10);
		WritePrivateProfileString(_T("setting"), _T("Order"), szBuffer, filePath);

		ZeroMemory(szBuffer, MAX_PATH * sizeof(TCHAR));
		_itot(imageIndex, szBuffer, 10);
		WritePrivateProfileString(_T("setting"), _T("ImageIndex"), szBuffer, filePath);

		ZeroMemory(szBuffer, MAX_PATH * sizeof(TCHAR));
		_itot(uiStyle, szBuffer, 10);
		WritePrivateProfileString(_T("setting"), _T("Style"), szBuffer, filePath);
	}
};
