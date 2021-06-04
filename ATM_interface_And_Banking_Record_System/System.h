#pragma once

#include"Database.h"
#include<string>
class System
{
	Database db;

	void loadData();

	bool loginAsAdmin(const std::string& username, const std::string& pass, int& pos);
	bool loginAsEmployee(const std::string& username, const std::string& pass, int& pos);
	bool loginAsClient(const std::string& cardNum, int PIN, int& clientPos, int& BApos);

	void help(int sw);

	void toLowerCase(std::string& str);
public:
	System();
	
	void start();
	

};

