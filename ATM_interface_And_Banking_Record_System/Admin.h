#pragma once

#include"Employee.h"
#include<fstream>
#include<vector>

class Admin: protected Person
{

	void copyNextWord(char* dest, char* source);
public:

	Admin();
	Admin(const std::string& username, const std::string& password, const std::string& EGN, const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address);

	void createEmployeeAcc(std::string& username, std::string& password, std::string& EGN,
		 Name& fullName, Date& date, std::string& phoneNum, std::string& address, std::vector<Employee*> &employees, bool& isGood);
	void deleteEmployeeAcc(const std::string EGN);

	void printPerson() override;
};

