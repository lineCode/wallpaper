#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "SingleObjectEvent.h"

class  CSingleObjectEvent;
class CWallpaperApp : public CWinAppEx
{
public:
	CWallpaperApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	CSingleObjectEvent		m_objEvent;
};

extern CWallpaperApp theApp;