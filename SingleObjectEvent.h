#pragma once

class  CSingleObjectEvent	:	CObject
{
public:
	CSingleObjectEvent();
	BOOL	Open();			//	�������¼�����
	void 	Close();		//  �ر������¼�����

	virtual ~CSingleObjectEvent();

private:
	CString 	m_strGUID;
	HANDLE      m_hEventHandle;

};


