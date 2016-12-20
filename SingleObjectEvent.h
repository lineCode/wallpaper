#pragma once

class  CSingleObjectEvent	:	CObject
{
public:
	CSingleObjectEvent();
	BOOL	Open();			//	打开命名事件对象
	void 	Close();		//  关闭命名事件对象

	virtual ~CSingleObjectEvent();

private:
	CString 	m_strGUID;
	HANDLE      m_hEventHandle;

};


