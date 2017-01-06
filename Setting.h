#pragma once

#include <string>

struct ImageConfig {
	std::wstring folder_path;
	int display_type;
	bool is_auto_run;
	int time_span;
};

/*
 * È«¾ÖÅäÖÃÀà

*/
class Setting
{
public:
	Setting();
	Setting& Get();
	~Setting();

	int LoadConfig(const std::string &  file_path);
	void SaveConfig(const std::string&  file_path);

private:
	ImageConfig data;

};

