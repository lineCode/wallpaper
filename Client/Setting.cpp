#include "Setting.h"
#include <Windows.h>


CSetting::CSetting()
{
}


CSetting::~CSetting()
{
}

CSetting& CSetting::Get()
{
	static CSetting m_setting;
	return m_setting;
}

// ��������
int CSetting::LoadConfig(const std::string &  file_path)
{
	return 0;
}

// ��������
void CSetting::SaveConfig(const std::string&  file_path)
{

}