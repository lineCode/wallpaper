#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include "SingleObjectEvent.h"

class  CSingleObjectEvent;
class CWallpaperApp : public CWinAppEx
{
public:
	CWallpaperApp();

// 重写
	public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
	CSingleObjectEvent		m_objEvent;
};

extern CWallpaperApp theApp;