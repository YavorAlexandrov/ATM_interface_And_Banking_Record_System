#pragma once
#include"Person.h"
#include<fstream>

class Admin: protected Person
{

	void breakDownDate(int& day, int& month, int& year, std::string date);
	void copyNextWord(char* dest, char* source);
public:

	Admin();
	Admin(const std::string& username, const std::string& password, const std::string& EGN, const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address);

	void createEmployeeAcc(std::string& username, std::string& password, std::string& EGN,
		 Name& fullName, Date& date, std::string& phoneNum, std::string& address);
	void deleteEmployeeAcc(const std::string EGN);

	void printPerson() override;
};

