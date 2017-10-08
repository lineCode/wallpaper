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

// º”‘ÿ≈‰÷√
int CSetting::LoadConfig(const std::string &  file_path)
{
	return 0;
}

// ±£¥Ê≈‰÷√
void CSetting::SaveConfig(const std::string&  file_path)
{

}