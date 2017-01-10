#include "Setting.h"
#include <Windows.h>


Setting::Setting()
{
}


Setting::~Setting()
{
}

Setting& Setting::Get()
{
	static Setting m_setting;
	return m_setting;
}


int Setting::LoadConfig(const std::string &  file_path)
{
	return 0;
}



void Setting::SaveConfig(const std::string&  file_path)
{

}