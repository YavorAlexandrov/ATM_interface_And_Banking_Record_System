#pragma once
#include<string>
#include"Name.h"
class Person
{
	std::string username;
	std::string password;
	std::string EGN;
	Name fullName;
	std::string dateOfBirth;//change to class Date?
	std::string phoneNum;
	std::string address;

public:
	Person();
	Person(const std::string& username, const std::string& password, const std::string& EGN, const Name& fullName, const std::string& dateOfBirth, const std::string& phoneNum, const std::string& address);



};

