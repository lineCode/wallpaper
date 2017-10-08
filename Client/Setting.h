#pragma once

#include "common.h"
#include <string>

struct ImageConfig {
	int display_type;			// �����ֽ����
	bool is_auto_run;			// �Ƿ��Զ�����
	int time_span;				// �л���ֽʱ����
};

/*
 * ȫ��������
*/
class CSetting
{
public:
	CSetting();
	static CSetting& Get();
	~CSetting();

	int LoadConfig(const std::string &  file_path);
	void SaveConfig(const std::string&  file_path);

public:
	xstring  m_imageFolder;
	ImageConfig wallpaper;

};

