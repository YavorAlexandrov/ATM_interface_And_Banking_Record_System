#pragma once

#include"Employee.h"
#include<fstream>
#include<vector>


class Admin: public Person
{
	std::string username;
	std::string password;

	void copyNextWord(char* dest, char* source);
public:

	Admin();
	Admin(const std::string& username, const std::string& password, const std::string& EGN, const Name& fullName, const Date& date, const std::string& phoneNum, const std::string& address);

	void setUsername(const std::string& username);
	void setPassword(const std::string password);

	const std::string& getUsername();
	const std::string& getPassword();

	void createEmployeeAcc(std::string& username, std::string& password, std::string& EGN,
		 Name& fullName, Date& date, std::string& phoneNum, std::string& address, std::vector<Employee*> &employees, bool& isGood);
	void deleteEmployeeAcc(std::string& EGN, std::vector<Employee*>& employees, bool& isGood);


	void printPerson() override;
};

