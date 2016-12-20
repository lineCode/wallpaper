#include "stdafx.h"
#include "SingleObjectEvent.h"

CSingleObjectEvent::CSingleObjectEvent()
:	m_strGUID(_T("069F6020-2644-41a6-964A-33D0E4D7D316"))
{
}

CSingleObjectEvent::~CSingleObjectEvent()
{
	if (m_hEventHandle)
	{
		CloseHandle(m_hEventHandle);
		m_hEventHandle = NULL;
	}
}

BOOL  CSingleObjectEvent::Open()
{
	// 创建命名对象事件
	m_hEventHandle	=	CreateEvent(NULL, FALSE, FALSE, m_strGUID);
	if  (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		return  FALSE;
	}

	return  TRUE;
}

void  CSingleObjectEvent::Close()
{
	if (m_hEventHandle)
	{
		CloseHandle(m_hEventHandle);
		m_hEventHandle = NULL;
	}
}

