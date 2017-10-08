#pragma once

#include "common.h"
#include <string>

struct ImageConfig {
	int display_type;			// 桌面壁纸类型
	bool is_auto_run;			// 是否自动运行
	int time_span;				// 切换壁纸时间间隔
};

/*
 * 全局配置类
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

